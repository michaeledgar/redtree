#include <stdint.h>
#include "ruby/ruby.h"
#include "tree.h"

#define INITIAL_TOKEN_COUNT 128
#define INITIAL_SEQUENCE_COUNT 256

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


#undef INITIAL_TOKEN_COUNT
#undef INITIAL_SEQUENCE_COUNT