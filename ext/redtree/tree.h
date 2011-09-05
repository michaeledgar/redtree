#ifndef CARBONICA_REDTREE_TREE_H_
#define CARBONICA_REDTREE_TREE_H_

typedef uint16_t redtree_token;
typedef int32_t redtree_sequence_entry;

struct redtree {
  VALUE source;
  redtree_token *tokens;
  struct token_location {
    uint32_t start_line;
    uint32_t end_line;
    uint16_t start_col;
    uint16_t end_col;
  } *token_locations;
  redtree_sequence_entry *sequence;
  uint32_t token_count;
  uint32_t sequence_count;
  uint32_t token_size;
  uint32_t sequence_size;
};

struct redtree* redtree_allocate();
void redtree_init_struct(struct redtree* tree, VALUE source);
uint32_t redtree_lex_token(struct redtree* tree,
                       redtree_token token_type,
                       uint32_t token_start_line,
                       uint32_t token_end_line,
                       uint16_t token_start_col,
                       uint16_t token_end_col);
void redtree_shift_token(struct redtree* tree, uint32_t token_index);
void redtree_reduce_rule(struct redtree* tree, uint32_t rule_index);
void redtree_sequence_push(struct redtree* tree, int32_t entry);

VALUE redtree_wrap(VALUE klass, struct redtree* tree);
VALUE redtree_tokens(VALUE self);
VALUE redtree_sequence(VALUE self);
VALUE redtree_root(VALUE self);

struct redtree_node_ref {
  struct redtree* tree;
  uint32_t index;
};

VALUE redtree_node_name(VALUE self);
VALUE redtree_node_index(VALUE self);
VALUE redtree_node_size(VALUE self);
VALUE redtree_node_child(VALUE self, VALUE idx);
VALUE redtree_node_child_node(VALUE self, VALUE idx);
VALUE redtree_node_child_token(VALUE self, VALUE idx);

VALUE redtree_token_name(VALUE self);
VALUE redtree_token_index(VALUE self);

#endif