#include <stdint.h>
#include "ruby/ruby.h"
#include "tree.h"

#define INITIAL_LINE_COUNT 16
#define INITIAL_TOKEN_COUNT 256
#define INITIAL_SEQUENCE_COUNT 256

#define NODE 0x3
#define REDTREE_NODE_FLAG 0x3
#define LEAF 0x2

static VALUE redtree_node_new(VALUE tree_val, uint32_t index);
static VALUE redtree_token_new(VALUE tree_val, uint32_t index);

static void
tree_mark(void *ptr)
{
  struct redtree *p = (struct redtree*)ptr;
  int idx, max = p->line_count;
  for (idx=0; idx < max; ++idx) {
    rb_gc_mark(p->lines[idx]);
  }
}

static void
tree_free(void *ptr)
{
    struct redtree *p = (struct redtree*)ptr;

    xfree(p->tokens);
    xfree(p->token_locations);
    xfree(p->sequence);
    xfree(p->lines);
    xfree(p);
}

static size_t
tree_memsize(const void *ptr)
{
    struct redtree *p = (struct redtree*)ptr;
    size_t size = sizeof(*p);

    size += sizeof(redtree_token) * p->token_size;
    size += sizeof(struct token_location) * p->token_size;
    size += sizeof(redtree_sequence_entry) * p->sequence_size;

    return size;
}

static const rb_data_type_t tree_data_type =  {"redtree",
    tree_mark, tree_free, tree_memsize,
};

struct redtree* redtree_allocate() {
  return ALLOC_N(struct redtree, 1);
}

static struct redtree* redtree_unpack_tree(VALUE self) {
  struct redtree* tree;
  TypedData_Get_Struct(self, struct redtree, &tree_data_type, tree);
  return tree;
}

void redtree_init_struct(struct redtree* tree) {
  tree->tokens = ALLOC_N(redtree_token, INITIAL_TOKEN_COUNT);
  tree->token_locations = ALLOC_N(struct token_location, INITIAL_TOKEN_COUNT);
  tree->token_size = INITIAL_TOKEN_COUNT;
  tree->token_count = 0;
  tree->sequence = ALLOC_N(redtree_sequence_entry, INITIAL_SEQUENCE_COUNT);
  tree->sequence_size = INITIAL_SEQUENCE_COUNT;
  tree->sequence_count = 0;
  tree->lines = ALLOC_N(VALUE, INITIAL_LINE_COUNT);
  tree->line_size = INITIAL_LINE_COUNT;
  tree->line_count = 0;
  tree->enc = 0;
}

void redtree_add_line(struct redtree* tree, VALUE str) {
  tree->lines[tree->line_count] = str;
  ++tree->line_count;
  if (tree->line_count == tree->line_size) {
    tree->line_size *= 2;
    REALLOC_N(tree->lines, VALUE, tree->line_size);
  }
}

uint32_t redtree_lex_token(struct redtree* tree,
                       redtree_token token_type,
                       uint32_t token_start_line,
                       uint16_t token_start_col,
                       uint16_t token_size) {
  tree->tokens[tree->token_count] = token_type;
  tree->token_locations[tree->token_count].start_line = token_start_line;
  tree->token_locations[tree->token_count].start_col = token_start_col;
  tree->token_locations[tree->token_count].size = token_size;
  uint32_t result = tree->token_count++;
  if (tree->token_count == tree->token_size) {
    tree->token_size *= 2;
    REALLOC_N(tree->tokens, redtree_token, tree->token_size);
    REALLOC_N(tree->token_locations, struct token_location, tree->token_size);
  }
  return result;
}

void redtree_shift_token(struct redtree* tree, uint32_t token_index) {
  redtree_sequence_push(tree, token_index);
}

void redtree_reduce_rule(struct redtree* tree, uint32_t rule_index) {
  redtree_sequence_push(tree, -rule_index);
}

void redtree_sequence_push(struct redtree* tree, int32_t entry) {
  tree->sequence[tree->sequence_count] = entry;
  ++tree->sequence_count;
  if (tree->sequence_count == tree->sequence_size) {
    tree->sequence_size *= 2;
    REALLOC_N(tree->sequence, redtree_sequence_entry, tree->sequence_size);
  }
}

VALUE redtree_wrap(VALUE klass, struct redtree* tree) {
  return TypedData_Wrap_Struct(klass, &tree_data_type, tree);
}

VALUE redtree_tokens(VALUE self) {
  struct redtree *tree = redtree_unpack_tree(self);
  uint32_t i;

  VALUE result = rb_ary_new2(tree->token_count);
  for (i=0; i<tree->token_count; ++i) {
    rb_ary_push(result, redtree_token_new(self, i));
  }
  return result;
}

VALUE redtree_sequence(VALUE self) {
  struct redtree *tree = redtree_unpack_tree(self);
  uint32_t i;

  VALUE result = rb_ary_new2(tree->sequence_count);
  for (i=0; i<tree->sequence_count; ++i) {
    rb_ary_push(result, INT2FIX(tree->sequence[i]));
  }
  return result;
}

VALUE redtree_root(VALUE self) {
  struct redtree *tree = redtree_unpack_tree(self);
  return redtree_node_new(self, tree->sequence_count - 1);
}

/****************** NODE METHODS ******************/

static void
node_mark(void *ptr)
{
  struct redtree_node_ref* node = (struct redtree_node_ref*)ptr;
  rb_gc_mark(node->tree_val);
}

static void
node_free(void *ptr)
{
  xfree(ptr);
}

static size_t
node_memsize(void *ptr)
{
  return sizeof(struct redtree_node_ref);
}

static const rb_data_type_t node_data_type =  {"redtree_node",
    node_mark, node_free, node_memsize,
};

static struct redtree_node_ref* redtree_unpack_node(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  return node;
}

static VALUE redtree_node_new(VALUE tree_val, uint32_t index) {
  struct redtree_node_ref* node = ALLOC_N(struct redtree_node_ref, 1);
  node->tree_val = tree_val;
  node->index = index;
  return TypedData_Wrap_Struct(rb_cNode, &node_data_type, node);
}

static int redtree_node_width_expanded(struct redtree* tree, uint32_t index) {
  int32_t pattern = tree->sequence[index-1];
  int width = 0;
  while (pattern != 0) {
    ++width;
    pattern >>= 2;
  }
  return width;
}

static int redtree_node_width(struct redtree_node_ref* node) {
  // TODO(adgar): Assembly version which is O(1)
  return redtree_node_width_expanded(redtree_unpack_tree(node->tree_val), node->index);
}

VALUE redtree_node_index(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_node(self);
  return INT2FIX(node->index);
}

VALUE redtree_node_name(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_node(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  rb_ary_entry(rb_aNames, -tree->sequence[node->index]);
}

VALUE redtree_node_size(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_node(self);
  return INT2FIX(redtree_node_width(node));
}

static inline VALUE node_child_node(struct redtree_node_ref*node, int offset) {
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  return redtree_node_new(node->tree_val, tree->sequence[node->index - (offset + 2)]);
}

static inline VALUE node_child_token(struct redtree_node_ref*node, int offset) {
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  return redtree_token_new(node->tree_val, tree->sequence[node->index - (offset + 2)]);
}

VALUE redtree_node_child(VALUE self, VALUE idx) {
  uint32_t offset = FIX2UINT(idx);
  struct redtree_node_ref* node = redtree_unpack_node(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  int32_t pattern = tree->sequence[node->index-1];
  int byte = (pattern >> (offset * 2)) & 0x3;
  if (byte == NODE) {
    return node_child_node(node, offset);
  } else if (byte == LEAF) {
    return node_child_token(node, offset);
  } else {
    rb_raise(rb_eIndexError, "Index %d too large for node with %d children", offset, redtree_node_width(node));
  }
}

VALUE redtree_node_child_node(VALUE self, VALUE idx) {
  uint32_t offset = FIX2INT(idx);
  struct redtree_node_ref* node = redtree_unpack_node(self);
  return node_child_node(node, offset);
}

VALUE redtree_node_child_token(VALUE self, VALUE idx) {
  uint32_t offset = FIX2INT(idx);
  struct redtree_node_ref* node = redtree_unpack_node(self);
  return node_child_token(node, offset);
}

/********************* TOKEN METHODS *********************/

static const rb_data_type_t token_data_type =  {"redtree_token",
    node_mark, node_free, node_memsize,
};

static VALUE redtree_token_new(VALUE tree_val, uint32_t index) {
  struct redtree_node_ref* node = ALLOC_N(struct redtree_node_ref, 1);
  node->tree_val = tree_val;
  node->index = index;
  return TypedData_Wrap_Struct(rb_cToken, &token_data_type, node);
}

static struct redtree_node_ref* redtree_unpack_token(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  return node;
}

VALUE redtree_token_name(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_token(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  uint16_t type = tree->tokens[node->index];
  rb_ary_entry(rb_aTokenNames, type);
}

VALUE redtree_token_index(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_token(self);
  return INT2FIX(node->index);
}

VALUE redtree_token_line_number(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_token(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  return INT2FIX((tree->token_locations + node->index)->start_line);
}

VALUE redtree_token_column(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_token(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  return INT2FIX((tree->token_locations + node->index)->start_col);
}

VALUE redtree_token_size(VALUE self) {
  struct redtree_node_ref* node = redtree_unpack_token(self);
  struct redtree* tree = redtree_unpack_tree(node->tree_val);
  return INT2FIX((tree->token_locations + node->index)->size);
}

/********************* TREE WALKER METHODS *********************/

struct redtree_walker_ops {
  VALUE ops[redtree_rulenum_MAX_RULES];
};

void ops_mark(void* ops_p) {
  unsigned int i;
  struct redtree_walker_ops* ops = (struct redtree_walker_ops*)ops_p;
  for (i=0; i < redtree_rulenum_MAX_RULES; ++i) {
    VALUE op = ops->ops[i];
    if (op) {
      rb_gc_mark(op);
    }
  }
}

void ops_free(void* ops_p) {
  xfree(ops_p);
}

size_t ops_memsize(void* ops_p) {
  return sizeof(struct redtree_walker_ops);
}

static const rb_data_type_t walker_ops_data_type =  {"redtree_token",
    ops_mark, ops_free, ops_memsize,
};

static struct redtree_walker_ops* ops_for_walker_class(VALUE walker) {
  VALUE table = rb_ivar_get(walker, rb_iWalkerOps);
  struct redtree_walker_ops* table_ptr;
  TypedData_Get_Struct(table, struct redtree_walker_ops, &walker_ops_data_type, table_ptr);
  return table_ptr;
}

VALUE redtree_walker_included(VALUE self, VALUE base) {
  rb_extend_object(base, rb_mWalkerClassMethods);
  // Add ivar only if it doesn't already have it to prevent silliness
  // TODO(adgar): Interplay w/ inheritance?
  if (!rb_ivar_defined(base, rb_iWalkerOps)) {
    struct redtree_walker_ops *ops = ALLOC_N(struct redtree_walker_ops, 1);
    MEMZERO(ops, struct redtree_walker_ops, 1);
    rb_ivar_set(base, rb_iWalkerOps, TypedData_Wrap_Struct(rb_cWalkerOps, &walker_ops_data_type, ops));
  }
  return Qnil;
}

VALUE redtree_walker_s_on(int argc, VALUE *argv, VALUE self) {
  // register proc for all listed node types
  int idx;
  rb_need_block();
  VALUE proc = rb_block_proc();
  struct redtree_walker_ops* ops = ops_for_walker_class(self);
  for (idx=0; idx < argc; ++idx) {
    int op_idx = FIX2INT(argv[idx]);
    ops->ops[op_idx] = proc;
  }
  return Qnil;
}

VALUE redtree_walker_walk(VALUE self, VALUE node) {
  if (rb_obj_is_kind_of(node, rb_cTree)) {
    redtree_walker_visit_node(self, redtree_root(node));
  } else {
    redtree_walker_visit_node(self, node);
  }
}

static VALUE redtree_walker_visit_raw_node(struct redtree_walker_ops* ops, VALUE tree_val, uint32_t index) {
  struct redtree* tree = redtree_unpack_tree(tree_val);
  uint32_t rule = -tree->sequence[index];
  VALUE op = ops->ops[rule];
  if (op) {
    return rb_proc_call(op, rb_ary_new3(1, redtree_node_new(tree_val, index)));
  } else {
    // walk children by default
    uint32_t pattern = tree->sequence[index - 1];
    int offset = 2;
    while (pattern) {
      if (pattern & 0x3 == NODE) {
        redtree_walker_visit_raw_node(ops, tree_val, tree->sequence[index - offset]);
      }
      pattern >>= 2;
      ++offset;
    }
    return Qnil;
  }
}

VALUE redtree_walker_visit_node(VALUE self, VALUE node) {
  struct redtree_walker_ops* ops = ops_for_walker_class(CLASS_OF(self));
  struct redtree_node_ref* node_ptr = redtree_unpack_node(node);
  // issue op
  redtree_walker_visit_raw_node(ops, node_ptr->tree_val, node_ptr->index);
}

#undef NODE
#undef LEAF

#undef INITIAL_TOKEN_COUNT
#undef INITIAL_SEQUENCE_COUNT