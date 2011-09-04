#include <stdint.h>
#include "ruby/ruby.h"
#include "tree.h"

#define INITIAL_TOKEN_COUNT 128
#define INITIAL_SEQUENCE_COUNT 256

static VALUE redtree_node_new(struct redtree* tree, uint32_t index);

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

void redtree_lex_token(struct redtree* tree,
                       redtree_token token_type,
                       uint32_t token_start_line,
                       uint32_t token_end_line,
                       uint16_t token_start_col,
                       uint16_t token_end_col) {
  tree->tokens[tree->token_count] = token_type;
  tree->token_locations[tree->token_count].start_line = token_start_line;
  tree->token_locations[tree->token_count].end_line = token_end_line;
  tree->token_locations[tree->token_count].start_col = token_start_col;
  tree->token_locations[tree->token_count].end_col = token_end_col;
  ++tree->token_count;
  if (tree->token_count == tree->token_size) {
    tree->token_size *= 2;
    tree->tokens = REALLOC_N(tree->tokens, redtree_token, tree->token_size);
    tree->token_locations = REALLOC_N(
    tree->token_locations, struct token_location, tree->token_size);
  }
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
    tree->sequence = REALLOC_N(
        tree->sequence, redtree_sequence_entry, tree->sequence_size);
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

VALUE redtree_sequence(VALUE self) {
  struct redtree *tree;
  uint32_t i;
  VALUE result = rb_ary_new();
  TypedData_Get_Struct(self, struct redtree, &tree_data_type, tree);

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

VALUE redtree_node_name(VALUE self) {
  struct redtree_node_ref* node;
  TypedData_Get_Struct(self, struct redtree_node_ref, &node_data_type, node);
  rb_ary_entry(rb_aNames, -node->tree->sequence[node->index]);
}

#undef INITIAL_TOKEN_COUNT
#undef INITIAL_SEQUENCE_COUNT