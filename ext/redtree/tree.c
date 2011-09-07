#include <stdint.h>
#include "ruby/ruby.h"
#include "tree.h"

#define INITIAL_TOKEN_COUNT 256
#define INITIAL_SEQUENCE_COUNT 256

#define NODE 0x3
#define LEAF 0x2

static VALUE redtree_node_new(struct redtree* tree, uint32_t index);
static VALUE redtree_token_new(struct redtree* tree, uint32_t index);

struct redtree* redtree_allocate() {
  return ALLOC_N(struct redtree, 1);
}

void redtree_init_struct(struct redtree* tree, VALUE source) {
  tree->source = source;
  tree->tokens = ALLOC_N(redtree_token, INITIAL_TOKEN_COUNT);
  tree->token_locations = ALLOC_N(struct token_location, INITIAL_TOKEN_COUNT);
  tree->token_size = INITIAL_TOKEN_COUNT;
  tree->token_count = 0;
  tree->sequence = ALLOC_N(redtree_sequence_entry, INITIAL_SEQUENCE_COUNT);
  tree->sequence_size = INITIAL_SEQUENCE_COUNT;
  tree->sequence_count = 0;
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

static void
tree_mark(void *ptr)
{
    struct redtree *tree = (struct redtree*)ptr;
    rb_gc_mark(tree->source);
}

static void
tree_free(void *ptr)
{
    struct redtree *p = (struct redtree*)ptr;

    xfree(p->tokens);
    xfree(p->token_locations);
    xfree(p->sequence);
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


VALUE redtree_wrap(VALUE klass, struct redtree* tree) {
  return TypedData_Wrap_Struct(klass, &tree_data_type, tree);
}

VALUE redtree_tokens(VALUE self) {
  struct redtree *tree;
  uint32_t i;
  TypedData_Get_Struct(self, struct redtree, &tree_data_type, tree);

  VALUE result = rb_ary_new2(tree->token_count);
  for (i=0; i<tree->token_count; ++i) {
    rb_ary_push(result, redtree_token_new(tree, i));
  }
  return result;
}

VALUE redtree_sequence(VALUE self) {
  struct redtree *tree;
  uint32_t i;
  TypedData_Get_Struct(self, struct redtree, &tree_data_type, tree);

  VALUE result = rb_ary_new2(tree->sequence_count);
  for (i=0; i<tree->sequence_count; ++i) {
    rb_ary_push(result, INT2FIX(tree->sequence[i]));
  }
  return result;
}

VALUE redtree_root(VALUE self) {
  struct redtree *tree;
  TypedData_Get_Struct(self, struct redtree, &tree_data_type, tree);
  return redtree_node_new(tree, tree->sequence_count - 1);
}

/****************** NODE METHODS ******************/

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
    0, node_free, node_memsize,
};


static VALUE redtree_node_new(struct redtree* tree, uint32_t index) {
  struct redtree_node_ref* node = ALLOC_N(struct redtree_node_ref, 1);
  node->tree = tree;
  node->index = index;
  return TypedData_Wrap_Struct(rb_cNode, &node_data_type, node);
}

static int redtree_node_width(struct redtree_node_ref* node) {
  // TODO(adgar): Assembly version which is O(1)
  int32_t pattern = node->tree->sequence[node->index-1];
  int width = 0;
  while (pattern != 0) {
    ++width;
    pattern >>= 2;
  }
  return width;
}

VALUE redtree_node_index(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  return INT2FIX(node->index);
}

VALUE redtree_node_name(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  rb_ary_entry(rb_aNames, -node->tree->sequence[node->index]);
}

VALUE redtree_node_size(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  return INT2FIX(redtree_node_width(node));
}

static inline VALUE node_child_node(struct redtree_node_ref*node, int offset) {
  return redtree_node_new(node->tree, node->tree->sequence[node->index - (offset + 2)]);
}

static inline VALUE node_child_token(struct redtree_node_ref*node, int offset) {
  return redtree_token_new(node->tree, node->tree->sequence[node->index - (offset + 2)]);
}

VALUE redtree_node_child(VALUE self, VALUE idx) {
  uint32_t offset = FIX2UINT(idx);
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  int32_t pattern = node->tree->sequence[node->index-1];
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
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  return node_child_node(node, offset);
}

VALUE redtree_node_child_token(VALUE self, VALUE idx) {
  uint32_t offset = FIX2INT(idx);
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  return node_child_token(node, offset);
}

/********************* TOKEN METHODS *********************/

static const rb_data_type_t token_data_type =  {"redtree_token",
    0, node_free, node_memsize,
};

static VALUE redtree_token_new(struct redtree* tree, uint32_t index) {
  struct redtree_node_ref* node = ALLOC_N(struct redtree_node_ref, 1);
  node->tree = tree;
  node->index = index;
  return TypedData_Wrap_Struct(rb_cToken, &token_data_type, node);
}

VALUE redtree_token_name(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  uint16_t type = node->tree->tokens[node->index];
  rb_ary_entry(rb_aTokenNames, type);
}

VALUE redtree_token_index(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  return INT2FIX(node->index);
}

VALUE redtree_token_line_number(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  return INT2FIX((node->tree->token_locations + node->index)->start_line);
}

VALUE redtree_token_column(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  return INT2FIX((node->tree->token_locations + node->index)->start_col);
}

VALUE redtree_token_size(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &token_data_type, node);
  return INT2FIX((node->tree->token_locations + node->index)->size);
}

#undef NODE
#undef LEAF

#undef INITIAL_TOKEN_COUNT
#undef INITIAL_SEQUENCE_COUNT