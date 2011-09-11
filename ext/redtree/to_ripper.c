#include "to_ripper.h"

static VALUE ripper_dispatch0(VALUE,ID);
static VALUE ripper_dispatch1(VALUE,ID,VALUE);
static VALUE ripper_dispatch2(VALUE,ID,VALUE,VALUE);
static VALUE ripper_dispatch3(VALUE,ID,VALUE,VALUE,VALUE);
static VALUE ripper_dispatch4(VALUE,ID,VALUE,VALUE,VALUE,VALUE);
static VALUE ripper_dispatch5(VALUE,ID,VALUE,VALUE,VALUE,VALUE,VALUE);

VALUE redtree_ripper_walk(VALUE self, struct redtree* tree, uint32_t index);

#define dispatch0(n)            ripper_dispatch0(self, TOKEN_PASTE(ripper_id_, n))
#define dispatch1(n,a)          ripper_dispatch1(self, TOKEN_PASTE(ripper_id_, n), a)
#define dispatch2(n,a,b)        ripper_dispatch2(self, TOKEN_PASTE(ripper_id_, n), a, b)
#define dispatch3(n,a,b,c)      ripper_dispatch3(self, TOKEN_PASTE(ripper_id_, n), a, b, c)
#define dispatch4(n,a,b,c,d)    ripper_dispatch4(self, TOKEN_PASTE(ripper_id_, n), a, b, c, d)
#define dispatch5(n,a,b,c,d,e)  ripper_dispatch5(self, TOKEN_PASTE(ripper_id_, n), a, b, c, d, e)

#define arg_new() dispatch0(args_new)
#define arg_add(l,a) dispatch2(args_add, (l), (a))
#define arg_add_star(l,a) dispatch2(args_add_star, (l), (a))
#define arg_add_block(l,b) dispatch2(args_add_block, (l), (b))
#define arg_add_optblock(l,b) ((b)==Qundef? (l) : dispatch2(args_add_block, (l), (b)))
#define bare_assoc(v) dispatch1(bare_assoc_hash, (v))
#define arg_add_assocs(l,b) arg_add((l), bare_assoc(b))

#define args2mrhs(a) dispatch1(mrhs_new_from_args, (a))
#define mrhs_new() dispatch0(mrhs_new)
#define mrhs_add(l,a) dispatch2(mrhs_add, (l), (a))
#define mrhs_add_star(l,a) dispatch2(mrhs_add_star, (l), (a))

#define mlhs_new() dispatch0(mlhs_new)
#define mlhs_add(l,a) dispatch2(mlhs_add, (l), (a))
#define mlhs_add_star(l,a) dispatch2(mlhs_add_star, (l), (a))

#define params_new(pars, opts, rest, pars2, blk) \
        dispatch5(params, (pars), (opts), (rest), (pars2), (blk))

#define blockvar_new(p,v) dispatch2(block_var, (p), (v))
#define blockvar_add_star(l,a) dispatch2(block_var_add_star, (l), (a))
#define blockvar_add_block(l,a) dispatch2(block_var_add_block, (l), (a))

#define method_optarg(m,a) ((a)==Qundef ? (m) : dispatch2(method_add_arg,(m),(a)))
#define method_arg(m,a) dispatch2(method_add_arg,(m),(a))
#define method_add_block(m,b) dispatch2(method_add_block, (m), (b))

// VALUE rb_cRedtreeRipper;
struct redtree_ripper {
  VALUE tree_val;
  uint32_t sequence_index;
};

static void
redtree_ripper_mark(void *ptr)
{
  struct redtree_ripper* node = (struct redtree_ripper*)ptr;
  rb_gc_mark(node->tree_val);
}

void redtree_ripper_free(void* p) {
	xfree(p);
}

size_t redtree_ripper_memsize(void* p) {
	return sizeof(struct redtree_ripper);
}

static const rb_data_type_t redtree_ripper_data_type =  {"redtree_ripper",
  redtree_ripper_mark, redtree_ripper_free, redtree_ripper_memsize,
};

VALUE redtree_ripper_allocate(VALUE klass) {
	return TypedData_Wrap_Struct(klass, &redtree_ripper_data_type, ALLOC_N(struct redtree_ripper, 1));
}

VALUE redtree_ripper_initialize(VALUE self, VALUE tree) {
  struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  ripper_ptr->tree_val = tree;
  ripper_ptr->sequence_index = 0;
  return Qnil;
}

VALUE redtree_ripper_parse(VALUE self) {
	struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  struct redtree* tree = redtree_unpack_tree(ripper_ptr->tree_val);
  return redtree_ripper_walk(self, tree, tree->sequence_count - 1);  // root node
}

VALUE redtree_ripper_lineno(VALUE self) {
  struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  struct redtree* tree = redtree_unpack_tree(ripper_ptr->tree_val);
  redtree_sequence_entry entry = tree->sequence[ripper_ptr->sequence_index];
  if (entry > 0) {
    // token
    struct token_location location = tree->token_locations[entry];
    return INT2FIX(location.start_line);
  } else {
    // rule
    return Qnil;
  }
}

VALUE redtree_ripper_column(VALUE self) {
  struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  struct redtree* tree = redtree_unpack_tree(ripper_ptr->tree_val);
  redtree_sequence_entry entry = tree->sequence[ripper_ptr->sequence_index];
  if (entry > 0) {
    // token
    struct token_location location = tree->token_locations[entry];
    return INT2FIX(location.start_col);
  } else {
    // rule
    return Qnil;
  }
}

VALUE redtree_ripper_walk(VALUE self, struct redtree* tree, uint32_t index) {
  struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  ripper_ptr->sequence_index = index;

	redtree_sequence_entry entry = tree->sequence[index];
	// production (rule)
	redtree_sequence_entry rule = entry & REDTREE_RULENUM_MASK;
	VALUE kids[MAX_REDTREE_NODE_WIDTH], tmp;
	int idx = 0, max = redtree_node_width_expanded(tree, index);
  unsigned int pat = tree->sequence[index] >> REDTREE_PATTERN_OFFSET;

  while (pat) {
    unsigned int kid_index = index - (idx + 1);
    redtree_sequence_entry kid_entry = tree->sequence[kid_index];
    if ((pat & 0x3) == REDTREE_NODE_FLAG) {
      // reduce next rule
      kids[idx] = redtree_ripper_walk(self, tree, kid_entry);
    } else {
      // scan a token
      // swizzle in new sequence index for lineno/column
      unsigned int old_index = index;
      ripper_ptr->sequence_index = kid_index;

      struct token_location location = tree->token_locations[kid_entry];
      VALUE line = tree->lines[location.start_line - 1];
      VALUE str = rb_enc_str_new(RSTRING_PTR(line) + location.start_col, location.size, tree->enc);
      kids[idx] = ripper_dispatch1(self, redtree_token2eventid(tree->tokens[kid_entry]), str);
      // swizzle out old sequence index
      ripper_ptr->sequence_index = old_index;
    }
    ++idx;
    pat >>= 2;
	}

	switch (rule) {
		case redtree_rulenum_program__top_compstmt:
			// kids[1] becomes kids[0] due to anonymous rule
		  return dispatch1(program, kids[0]);
		case redtree_rulenum_top_compstmt__top_stmts__opt_terms:
		  return kids[0];
		case redtree_rulenum_top_stmts__none:
		  return dispatch2(stmts_add, dispatch0(stmts_new), dispatch0(void_stmt));
		case redtree_rulenum_top_stmt__stmt:
			return kids[0];
		case redtree_rulenum_top_stmts__top_stmt:
		  return dispatch2(stmts_add, dispatch0(stmts_new), kids[0]);
		case redtree_rulenum_top_stmts__top_stmts__terms__top_stmt:
		  return dispatch2(stmts_add, kids[0], kids[2]);
		case redtree_rulenum_top_stmts__error__top_stmt:
		  return kids[1];
		case redtree_rulenum_top_stmt__keyword_BEGIN__LC__top_compstmt__RC:
			// kids[3] becomes kids[2] due to anonymous rule
		  return dispatch1(BEGIN, kids[2]);
		case redtree_rulenum_bodystmt__compstmt__opt_rescue__opt_else__opt_ensure:
		  return dispatch4(bodystmt, kids[0], kids[1], kids[2], kids[3]);
		case redtree_rulenum_compstmt__stmts__opt_terms:
		  return kids[0];
    case redtree_rulenum_stmts__none:
    	return dispatch2(stmts_add, dispatch0(stmts_new), dispatch0(void_stmt));
    case redtree_rulenum_stmts__stmt:
    	return dispatch2(stmts_add, dispatch0(stmts_new), kids[0]);
    case redtree_rulenum_stmts__stmts__terms__stmt:
    	return dispatch2(stmts_add, kids[0], kids[2]);
    case redtree_rulenum_stmts__error__stmt:
    	return kids[1];
    case redtree_rulenum_stmt__keyword_alias__fitem__fitem:
    	// kids[3] becomes kids[2] due to anonymous rule
    	return dispatch2(alias, kids[1], kids[2]);
    case redtree_rulenum_stmt__keyword_alias__tGVAR__tGVAR:
    	return dispatch2(var_alias, kids[1], kids[2]);
    case redtree_rulenum_stmt__keyword_alias__tGVAR__tBACK_REF:
    	return dispatch2(var_alias, kids[1], kids[2]);
    case redtree_rulenum_stmt__keyword_alias__tGVAR__tNTH_REF:
    	return dispatch1(alias_error, dispatch2(var_alias, kids[1], kids[2]));
    case redtree_rulenum_stmt__keyword_undef__undef_list:
    	return dispatch1(undef, kids[1]);
    case redtree_rulenum_stmt__stmt__modifier_if__expr_value:
    	return dispatch2(if_mod, kids[2], kids[0]);
    case redtree_rulenum_stmt__stmt__modifier_unless__expr_value:
    	return dispatch2(unless_mod, kids[2], kids[0]);
    case redtree_rulenum_stmt__stmt__modifier_while__expr_value:
    	return dispatch2(while_mod, kids[2], kids[0]);
    case redtree_rulenum_stmt__stmt__modifier_until__expr_value:
    	return dispatch2(until_mod, kids[2], kids[0]);
    case redtree_rulenum_stmt__stmt__modifier_rescue__stmt:
    	return dispatch2(rescue_mod, kids[0], kids[2]);
    case redtree_rulenum_stmt__keyword_END__LC__compstmt__RC:
    	return dispatch1(END, kids[2]);
    case redtree_rulenum_stmt__command_asgn:
    	return kids[0];
    case redtree_rulenum_stmt__mlhs__EQ__command_call:
    	return dispatch2(massign, kids[0], kids[2]);
    case redtree_rulenum_stmt__var_lhs__tOP_ASGN__command_call:
    	return dispatch3(opassign, kids[0], kids[1], kids[2]);
    case redtree_rulenum_stmt__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__command_call:
		  return dispatch3(opassign, dispatch2(aref_field, kids[0], kids[2]), kids[4], kids[5]);
    case redtree_rulenum_stmt__primary_value__DOT__tIDENTIFIER__tOP_ASGN__command_call:
    case redtree_rulenum_stmt__primary_value__DOT__tCONSTANT__tOP_ASGN__command_call:
		  return dispatch3(opassign, dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]), kids[3], kids[4]);
    case redtree_rulenum_stmt__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__command_call:
    	tmp = dispatch2(const_path_field, kids[0], kids[2]);
		  tmp = dispatch3(opassign, tmp, kids[3], kids[4]);
		  return dispatch1(assign_error, tmp);
    case redtree_rulenum_stmt__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__command_call:
			return dispatch3(opassign, dispatch3(field, kids[0], ripper_intern("::"), kids[2]), kids[3], kids[4]);
    case redtree_rulenum_stmt__backref__tOP_ASGN__command_call:
    	tmp = dispatch2(assign, dispatch1(var_field, kids[0]), kids[2]);
			return dispatch1(assign_error, tmp);
    case redtree_rulenum_stmt__lhs__EQ__mrhs:
    	return dispatch2(assign, kids[0], kids[2]);
    case redtree_rulenum_stmt__mlhs__EQ__arg_value:
    	return dispatch2(massign, kids[0], kids[2]);
    case redtree_rulenum_stmt__mlhs__EQ__mrhs:
    	return dispatch2(massign, kids[0], kids[2]);
    case redtree_rulenum_stmt__expr:
    	return kids[0];
    case redtree_rulenum_command_asgn__lhs__EQ__command_call:
    	return dispatch2(assign, kids[0], kids[2]);
    case redtree_rulenum_command_asgn__lhs__EQ__command_asgn:
    	return dispatch2(assign, kids[0], kids[2]);
    case redtree_rulenum_expr__command_call:
    	return kids[0];
    case redtree_rulenum_expr__expr__keyword_and__expr:
    	return dispatch3(binary, kids[0], ripper_intern("and"), kids[2]);
    case redtree_rulenum_expr__expr__keyword_or__expr:
    	return dispatch3(binary, kids[0], ripper_intern("or"), kids[2]);
    case redtree_rulenum_expr__keyword_not__opt_nl__expr:
    	return dispatch2(unary, ripper_intern("not"), kids[2]);
    case redtree_rulenum_expr__BANG__command_call:
    	return dispatch2(unary, redtree_id2sym('!'), kids[1]);
    case redtree_rulenum_expr__arg:
    	return kids[0];
    case redtree_rulenum_expr_value__expr:
    	return kids[0];
    case redtree_rulenum_command_call__command:
    	return kids[0];
    case redtree_rulenum_command_call__block_command:
    	return kids[0];
    case redtree_rulenum_block_command__block_call:
    	return kids[0];
    case redtree_rulenum_block_command__block_call__DOT__operation2__command_args:
    	return method_arg(dispatch3(call, kids[0], redtree_id2sym('.'), kids[2]), kids[3]);
    case redtree_rulenum_block_command__block_call__tCOLON2__operation2__command_args:
    	return method_arg(dispatch3(call, kids[0], ripper_intern("::"), kids[2]), kids[3]);
    case redtree_rulenum_cmd_brace_block__tLBRACE_ARG__opt_block_param__compstmt__RC:
    	// kids[2] becomes kids[1] due to anonymous rule
    	// kids[3] becomes kids[2] due to anonymous rule
    	return dispatch2(brace_block, kids[1], kids[2]);
    case redtree_rulenum_command__operation__command_args:
    	return dispatch2(command, kids[0], kids[1]);
    case redtree_rulenum_command__operation__command_args__cmd_brace_block:
    	return method_add_block(dispatch2(command, kids[0], kids[1]), kids[2]);
    case redtree_rulenum_command__primary_value__DOT__operation2__command_args:
    	return dispatch4(command_call, kids[0], redtree_id2sym('.'), kids[2], kids[3]);
    case redtree_rulenum_command__primary_value__DOT__operation2__command_args__cmd_brace_block:
    	tmp = dispatch4(command_call, kids[0], redtree_id2sym('.'), kids[2], kids[3]);
			return method_add_block(tmp, kids[4]);
    case redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args:
    	return dispatch4(command_call, kids[0], ripper_intern("::"), kids[2], kids[3]);
    case redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args__cmd_brace_block:
    	tmp = dispatch4(command_call, kids[0], ripper_intern("::"), kids[2], kids[3]);
			return method_add_block(tmp, kids[4]);
    case redtree_rulenum_command__keyword_super__command_args:
    	return dispatch1(super, kids[1]);
    case redtree_rulenum_command__keyword_yield__command_args:
    	return dispatch1(yield, kids[1]);
    case redtree_rulenum_command__keyword_return__call_args:
    	return dispatch1(return, kids[1]);
    case redtree_rulenum_command__keyword_break__call_args:
    	return dispatch1(break, kids[1]);
    case redtree_rulenum_command__keyword_next__call_args:
    	return dispatch1(next, kids[1]);
    case redtree_rulenum_mlhs__mlhs_basic:
    	return kids[0];
    case redtree_rulenum_mlhs__tLPAREN__mlhs_inner__rparen:
    	return dispatch1(mlhs_paren, kids[1]);
    case redtree_rulenum_mlhs_inner__mlhs_basic:
    	return kids[0];
    case redtree_rulenum_mlhs_inner__tLPAREN__mlhs_inner__rparen:
    	return dispatch1(mlhs_paren, kids[1]);
    case redtree_rulenum_mlhs_basic__mlhs_head:
    	return kids[0];
    case redtree_rulenum_mlhs_basic__mlhs_head__mlhs_item:
    	return mlhs_add(kids[0], kids[1]);
    case redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node:
    	return mlhs_add_star(kids[0], kids[2]);
    case redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node__COMMA__mlhs_post:
			return mlhs_add(mlhs_add_star(kids[0], kids[2]), kids[4]);
    case redtree_rulenum_mlhs_basic__mlhs_head__tSTAR:
    	return mlhs_add_star(kids[0], Qnil);
    case redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__COMMA__mlhs_post:
			return mlhs_add(mlhs_add_star(kids[0], Qnil), kids[3]);
    case redtree_rulenum_mlhs_basic__tSTAR__mlhs_node:
    	return mlhs_add_star(mlhs_new(), kids[1]);
    case redtree_rulenum_mlhs_basic__tSTAR__mlhs_node__COMMA__mlhs_post:
			return mlhs_add(mlhs_add_star(mlhs_new(), kids[1]), kids[3]);
    case redtree_rulenum_mlhs_basic__tSTAR:
    	return mlhs_add_star(mlhs_new(), Qnil);
    case redtree_rulenum_mlhs_basic__tSTAR__COMMA__mlhs_post:
			return mlhs_add(mlhs_add_star(mlhs_new(), Qnil), kids[2]);
    case redtree_rulenum_mlhs_item__mlhs_node:
    	return kids[0];
    case redtree_rulenum_mlhs_item__tLPAREN__mlhs_inner__rparen:
    	return dispatch1(mlhs_paren, kids[1]);
    case redtree_rulenum_mlhs_head__mlhs_item__COMMA:
    	return mlhs_add(mlhs_new(), kids[0]);
    case redtree_rulenum_mlhs_head__mlhs_head__mlhs_item__COMMA:
    	return mlhs_add(kids[0], kids[1]);
    case redtree_rulenum_mlhs_post__mlhs_item:
    	return mlhs_add(mlhs_new(), kids[0]);
    case redtree_rulenum_mlhs_post__mlhs_post__COMMA__mlhs_item:
    	return mlhs_add(kids[0], kids[2]);
    case redtree_rulenum_mlhs_node__user_variable:
    	return kids[0];
    case redtree_rulenum_mlhs_node__keyword_variable:
    	return kids[0];
    case redtree_rulenum_mlhs_node__primary_value__LS__opt_call_args__rbracket:
    	return dispatch2(aref_field, kids[0], kids[2]);
    case redtree_rulenum_mlhs_node__primary_value__DOT__tIDENTIFIER:	
    	return dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]);
    case redtree_rulenum_mlhs_node__primary_value__tCOLON2__tIDENTIFIER:
    	return dispatch2(const_path_field, kids[0], kids[2]);
    case redtree_rulenum_mlhs_node__primary_value__DOT__tCONSTANT:
    	return dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]);
    case redtree_rulenum_mlhs_node__primary_value__tCOLON3__tCONSTANT:
    	return dispatch2(const_path_field, kids[0], kids[2]);
    case redtree_rulenum_mlhs_node__tCOLON3__tCONSTANT:
    	return dispatch1(top_const_field, kids[1]);
    case redtree_rulenum_mlhs_node__backref:
    	return dispatch1(assign_error, dispatch1(var_field, kids[0]));
    case redtree_rulenum_lhs__user_variable:
    	return dispatch1(var_field, kids[0]);
    case redtree_rulenum_lhs__keyword_variable:
    	return dispatch1(var_field, kids[0]);
    case redtree_rulenum_lhs__primary_value__LS__opt_call_args__rbracket:
    	return dispatch2(aref_field, kids[0], kids[2]);
    case redtree_rulenum_lhs__primary_value__DOT__tIDENTIFIER:
    	return dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]);
    case redtree_rulenum_lhs__primary_value__tCOLON2__tIDENTIFIER:
    	return dispatch3(field, kids[0], ripper_intern("::"), kids[2]);
    case redtree_rulenum_lhs__primary_value__DOT__tCONSTANT:
    	return dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]);
    case redtree_rulenum_lhs__primary_value__tCOLON3__tCONSTANT:
    	return dispatch2(const_path_field, kids[0], kids[2]);
    case redtree_rulenum_lhs__tCOLON3__tCONSTANT:
    	return dispatch1(top_const_field, kids[1]);
    case redtree_rulenum_lhs__backref:
    	return dispatch1(assign_error, kids[0]);
    case redtree_rulenum_cname__tIDENTIFIER:
    	return dispatch1(class_name_error, kids[0]);
    case redtree_rulenum_cname__tCONSTANT:
    	return kids[0];
    case redtree_rulenum_cpath__tCOLON3__cname:
    	return dispatch1(top_const_ref, kids[1]);
    case redtree_rulenum_cpath__cname:
    	return dispatch1(const_ref, kids[0]);
    case redtree_rulenum_cpath__primary_value__tCOLON2__cname:
    	return dispatch2(const_path_ref, kids[0], kids[2]);
    case redtree_rulenum_fname__tIDENTIFIER:
    case redtree_rulenum_fname__tCONSTANT:
    case redtree_rulenum_fname__tFID:
    case redtree_rulenum_fname__op:
    case redtree_rulenum_fname__reswords:
    	return kids[0];
    case redtree_rulenum_fsym__fname:
    case redtree_rulenum_fsym__symbol:
    	return kids[0];
    case redtree_rulenum_fitem__fsym:
    	return dispatch1(symbol_literal, kids[0]);
    case redtree_rulenum_fitem__dsym:
    	return kids[0];
    case redtree_rulenum_undef_list__fitem:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_undef_list__undef_list__COMMA__fitem:
    	// kids[3] becomes kids[2] due to anonymous rule
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_op__OR:
    case redtree_rulenum_op__CARET:
    case redtree_rulenum_op__AND:
    case redtree_rulenum_op__tCMP:
    case redtree_rulenum_op__tEQ:
    case redtree_rulenum_op__tEQQ:
    case redtree_rulenum_op__tMATCH:
    case redtree_rulenum_op__tNMATCH:
    case redtree_rulenum_op__GT:
    case redtree_rulenum_op__tGEQ:
    case redtree_rulenum_op__LE:
    case redtree_rulenum_op__tLEQ:
    case redtree_rulenum_op__tNEQ:
    case redtree_rulenum_op__tLSHFT:
    case redtree_rulenum_op__tRSHFT:
    case redtree_rulenum_op__PLUS:
    case redtree_rulenum_op__MINUS:
    case redtree_rulenum_op__TIMES:
    case redtree_rulenum_op__tSTAR:
    case redtree_rulenum_op__DIVIDE:
    case redtree_rulenum_op__MOD:
    case redtree_rulenum_op__tPOW:
    case redtree_rulenum_op__BANG:
    case redtree_rulenum_op__TILDE:
    case redtree_rulenum_op__tUPLUS:
    case redtree_rulenum_op__tUMINUS:
    case redtree_rulenum_op__tAREF:
    case redtree_rulenum_op__tASET:
    case redtree_rulenum_op__BACKTICK:
    	return kids[0];
    case redtree_rulenum_reswords__keyword__LINE:
    case redtree_rulenum_reswords__keyword__FILE:
    case redtree_rulenum_reswords__keyword__ENCODING:
    case redtree_rulenum_reswords__keyword_BEGIN:
    case redtree_rulenum_reswords__keyword_END:
    case redtree_rulenum_reswords__keyword_alias:
    case redtree_rulenum_reswords__keyword_and:
    case redtree_rulenum_reswords__keyword_begin:
    case redtree_rulenum_reswords__keyword_break:
    case redtree_rulenum_reswords__keyword_case:
    case redtree_rulenum_reswords__keyword_class:
    case redtree_rulenum_reswords__keyword_def:
    case redtree_rulenum_reswords__keyword_defined:
    case redtree_rulenum_reswords__keyword_do:
    case redtree_rulenum_reswords__keyword_else:
    case redtree_rulenum_reswords__keyword_elsif:
    case redtree_rulenum_reswords__keyword_end:
    case redtree_rulenum_reswords__keyword_ensure:
    case redtree_rulenum_reswords__keyword_false:
    case redtree_rulenum_reswords__keyword_for:
    case redtree_rulenum_reswords__keyword_in:
    case redtree_rulenum_reswords__keyword_module:
    case redtree_rulenum_reswords__keyword_next:
    case redtree_rulenum_reswords__keyword_nil:
    case redtree_rulenum_reswords__keyword_not:
    case redtree_rulenum_reswords__keyword_or:
    case redtree_rulenum_reswords__keyword_redo:
    case redtree_rulenum_reswords__keyword_rescue:
    case redtree_rulenum_reswords__keyword_retry:
    case redtree_rulenum_reswords__keyword_return:
    case redtree_rulenum_reswords__keyword_self:
    case redtree_rulenum_reswords__keyword_super:
    case redtree_rulenum_reswords__keyword_then:
    case redtree_rulenum_reswords__keyword_true:
    case redtree_rulenum_reswords__keyword_undef:
    case redtree_rulenum_reswords__keyword_when:
    case redtree_rulenum_reswords__keyword_yield:
    case redtree_rulenum_reswords__keyword_if:
    case redtree_rulenum_reswords__keyword_unless:
    case redtree_rulenum_reswords__keyword_while:
    case redtree_rulenum_reswords__keyword_until:
    	return kids[0];
    case redtree_rulenum_arg__lhs__EQ__arg:
    	return dispatch2(assign, kids[0], kids[2]);
    case redtree_rulenum_arg__lhs__EQ__arg__modifier_rescue__arg:
    	return dispatch2(assign, kids[0], dispatch2(rescue_mod, kids[2], kids[4]));
    case redtree_rulenum_arg__var_lhs__tOP_ASGN__arg:
    	return dispatch3(opassign, kids[0], kids[1], kids[2]);
    case redtree_rulenum_arg__var_lhs__tOP_ASGN__arg__modifier_rescue__arg:
			return dispatch3(opassign, kids[0], kids[1], dispatch2(rescue_mod, kids[2], kids[4]));
    case redtree_rulenum_arg__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__arg:
			return dispatch3(opassign, dispatch2(aref_field, kids[0], kids[2]), kids[4], kids[5]);
    case redtree_rulenum_arg__primary_value__DOT__tIDENTIFIER__tOP_ASGN__arg:
			return dispatch3(opassign, dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]), kids[3], kids[4]);
    case redtree_rulenum_arg__primary_value__DOT__tCONSTANT__tOP_ASGN__arg:
    	return dispatch3(opassign, dispatch3(field, kids[0], redtree_id2sym('.'), kids[2]), kids[3], kids[4]);
    case redtree_rulenum_arg__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__arg:
			return dispatch3(opassign, dispatch3(field, kids[0], ripper_intern("::"), kids[2]), kids[3], kids[4]);
    case redtree_rulenum_arg__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__arg:
    	tmp = dispatch2(const_path_field, kids[0], kids[2]);
			return dispatch1(assign_error, dispatch3(opassign, tmp, kids[3], kids[4]));
    case redtree_rulenum_arg__tCOLON3__tCONSTANT__tOP_ASGN__arg:
    	tmp = dispatch1(top_const_field, kids[1]);
			return dispatch1(assign_error, dispatch3(opassign, tmp, kids[2], kids[3]));
    case redtree_rulenum_arg__backref__tOP_ASGN__arg:
    	tmp = dispatch1(var_field, kids[1]);
			return dispatch1(assign_error, dispatch3(opassign, tmp, kids[2], kids[3]));
    case redtree_rulenum_arg__arg__tDOT2__arg:
    	return dispatch2(dot2, kids[0], kids[2]);
    case redtree_rulenum_arg__arg__tDOT3__arg:
    	return dispatch2(dot3, kids[0], kids[2]);
    case redtree_rulenum_arg__arg__PLUS__arg:
    	return dispatch3(binary, kids[0], ID2SYM('+'), kids[2]);
    case redtree_rulenum_arg__arg__MINUS__arg:
    	return dispatch3(binary, kids[0], ID2SYM('-'), kids[2]);
    case redtree_rulenum_arg__arg__TIMES__arg:
    	return dispatch3(binary, kids[0], ID2SYM('*'), kids[2]);
    case redtree_rulenum_arg__arg__DIVIDE__arg:
    	return dispatch3(binary, kids[0], ID2SYM('/'), kids[2]);
    case redtree_rulenum_arg__arg__MOD__arg:
    	return dispatch3(binary, kids[0], ID2SYM('%'), kids[2]);
    case redtree_rulenum_arg__arg__tPOW__arg:
    	return dispatch3(binary, kids[0], ripper_intern("**"), kids[2]);
    case redtree_rulenum_arg__tUMINUS_NUM__tINTEGER__tPOW__arg:
    	tmp = dispatch3(binary, kids[1], ripper_intern("**"), kids[3]);
			return dispatch2(unary, ripper_intern("-@"), tmp);
    case redtree_rulenum_arg__tUMINUS_NUM__tFLOAT__tPOW__arg:
    	tmp = dispatch3(binary, kids[1], ripper_intern("**"), kids[3]);
			return dispatch2(unary, ripper_intern("-@"), tmp);
    case redtree_rulenum_arg__tUPLUS__arg:
    	return dispatch2(unary, ripper_intern("+@"), kids[1]);
    case redtree_rulenum_arg__tUMINUS__arg:
    	return dispatch2(unary, ripper_intern("-@"), kids[1]);
    case redtree_rulenum_arg__arg__OR__arg:
    	return dispatch3(binary, kids[0], ID2SYM('|'), kids[2]);
    case redtree_rulenum_arg__arg__CARET__arg:
    	return dispatch3(binary, kids[0], ID2SYM('^'), kids[2]);
    case redtree_rulenum_arg__arg__AND__arg:
    	return dispatch3(binary, kids[0], ID2SYM('&'), kids[2]);
    case redtree_rulenum_arg__arg__tCMP__arg:
    	return dispatch3(binary, kids[0], ripper_intern("<=>"), kids[2]);
    case redtree_rulenum_arg__arg__GT__arg:
    	return dispatch3(binary, kids[0], ID2SYM('>'), kids[2]);
    case redtree_rulenum_arg__arg__tGEQ__arg:
    	return dispatch3(binary, kids[0], ripper_intern(">="), kids[2]);
    case redtree_rulenum_arg__arg__LT__arg:
    	return dispatch3(binary, kids[0], ID2SYM('<'), kids[2]);
    case redtree_rulenum_arg__arg__tLEQ__arg:
    	return dispatch3(binary, kids[0], ripper_intern("<="), kids[2]);
    case redtree_rulenum_arg__arg__tEQ__arg:
    	return dispatch3(binary, kids[0], ripper_intern("=="), kids[2]);
    case redtree_rulenum_arg__arg__tEQQ__arg:
    	return dispatch3(binary, kids[0], ripper_intern("==="), kids[2]);
    case redtree_rulenum_arg__arg__tNEQ__arg:
    	return dispatch3(binary, kids[0], ripper_intern("!="), kids[2]);
    case redtree_rulenum_arg__arg__tMATCH__arg:
    	return dispatch3(binary, kids[0], ripper_intern("=~"), kids[2]);
    case redtree_rulenum_arg__arg__tNMATCH__arg:
    	return dispatch3(binary, kids[0], ripper_intern("!~"), kids[2]);
    case redtree_rulenum_arg__BANG__arg:
    	return dispatch2(unary, ID2SYM('!'), kids[1]);
    case redtree_rulenum_arg__TILDE__arg:
    	return dispatch2(unary, ID2SYM('~'), kids[1]);
    case redtree_rulenum_arg__arg__tLSHFT__arg:
    	return dispatch3(binary, kids[0], ripper_intern("<<"), kids[2]);
    case redtree_rulenum_arg__arg__tRSHFT__arg:
    	return dispatch3(binary, kids[0], ripper_intern(">>"), kids[2]);
    case redtree_rulenum_arg__arg__tANDOP__arg:
    	return dispatch3(binary, kids[0], ripper_intern("&&"), kids[2]);
    case redtree_rulenum_arg__arg__tOROP__arg:
    	return dispatch3(binary, kids[0], ripper_intern("||"), kids[2]);
    case redtree_rulenum_arg__keyword_defined__opt_nl__arg:
    	// kids[3] becomes kids[2] due to anonymous rule
    	return dispatch1(defined, kids[2]);
    case redtree_rulenum_arg__arg__QMARK__arg__opt_nl__COLON__arg:
    	return dispatch3(ifop, kids[0], kids[2], kids[5]);
    case redtree_rulenum_arg__primary:
    	return kids[0];
    case redtree_rulenum_arg_value__arg:
    	return kids[0];
    case redtree_rulenum_aref_args__none:
    case redtree_rulenum_aref_args__args__trailer:
    	return kids[0];
    case redtree_rulenum_aref_args__args__COMMA__assocs__trailer:
    	return arg_add_assocs(kids[0], kids[2]);
    case redtree_rulenum_aref_args__assocs__trailer:
    	return arg_add_assocs(arg_new(), kids[0]);
    case redtree_rulenum_paren_args__LR__opt_call_args__rparen:
    	return dispatch1(arg_paren, kids[1]);
    case redtree_rulenum_opt_paren_args__none:
    case redtree_rulenum_opt_paren_args__paren_args:
    	return kids[0];
    case redtree_rulenum_opt_call_args__none:
    case redtree_rulenum_opt_call_args__call_args:
    case redtree_rulenum_opt_call_args__args__COMMA:
    	return kids[0];
    case redtree_rulenum_opt_call_args__args__COMMA__assocs__COMMA:
    	return arg_add_assocs(kids[0], kids[2]);
    case redtree_rulenum_opt_call_args__assocs__COMMA:
    	return arg_add_assocs(arg_new(), kids[0]);
    case redtree_rulenum_call_args__command:
    	return arg_add(arg_new(), kids[0]);
    case redtree_rulenum_call_args__args__opt_block_arg:
    	return arg_add_optblock(kids[0], kids[1]);
    case redtree_rulenum_call_args__assocs__opt_block_arg:
			return arg_add_optblock(arg_add_assocs(arg_new(), kids[0]), kids[1]);
    case redtree_rulenum_call_args__args__COMMA__assocs__opt_block_arg:
    	return arg_add_optblock(arg_add_assocs(kids[0], kids[2]), kids[3]);
    case redtree_rulenum_call_args__block_arg:
    	return arg_add_block(arg_new(), kids[0]);
    case redtree_rulenum_command_args__call_args:
    	// kids[1] becomes kids[0] due to anonymous rule
    	return kids[0];
    case redtree_rulenum_block_arg__tAMPER__arg_value:
    	return kids[1];
    case redtree_rulenum_opt_block_arg__COMMA__block_arg:
    	return kids[1];
    case redtree_rulenum_opt_block_arg__none:
    	return Qnil;
    case redtree_rulenum_args__arg_value:
    	return arg_add(arg_new(), kids[0]);
    case redtree_rulenum_args__tSTAR__arg_value:
    	return arg_add_star(arg_new(), kids[1]);
    case redtree_rulenum_args__args__COMMA__arg_value:
    	return arg_add(kids[0], kids[2]);
    case redtree_rulenum_args__args__COMMA__tSTAR__arg_value:
      return arg_add_star(kids[0], kids[3]);
    case redtree_rulenum_mrhs__args__COMMA__arg_value:
    	return mrhs_add(args2mrhs(kids[0]), kids[2]);
    case redtree_rulenum_mrhs__args__COMMA__tSTAR__arg_value:
    	return mrhs_add_star(args2mrhs(kids[0]), kids[3]);
    case redtree_rulenum_mrhs__tSTAR__arg_value:
    	return mrhs_add_star(mrhs_new(), kids[1]);
    case redtree_rulenum_primary__literal:
    case redtree_rulenum_primary__strings:
    case redtree_rulenum_primary__xstring:
    case redtree_rulenum_primary__regexp:
    case redtree_rulenum_primary__words:
    case redtree_rulenum_primary__qwords:
    case redtree_rulenum_primary__var_ref:
    case redtree_rulenum_primary__backref:
    	return kids[0];
    case redtree_rulenum_primary__tFID:
    	return method_arg(dispatch1(fcall, kids[0]), arg_new());
    case redtree_rulenum_primary__k_begin__bodystmt__k_end:
    	return dispatch1(begin, kids[2]);
    case redtree_rulenum_primary__tLPAREN_ARG__expr__rparen:
    	// kids[1] becomes kids[0] due to anonymous rule
    	return dispatch1(paren, kids[1]);
    case redtree_rulenum_primary__tLPAREN__compstmt__RR:
    	return dispatch1(paren, kids[1]);
    case redtree_rulenum_primary__primary_value__tCOLON2__tCONSTANT:
    	return dispatch2(const_path_ref, kids[0], kids[2]);
    case redtree_rulenum_primary__tCOLON3__tCONSTANT:
    	return dispatch1(top_const_ref, kids[1]);
    case redtree_rulenum_primary__tLBRACK__aref_args__RS:
    	return dispatch1(array, kids[1]);
    case redtree_rulenum_primary__tLBRACE__assoc_list__RC:
    	return dispatch1(hash, kids[1]);
    case redtree_rulenum_primary__keyword_return:
    	return dispatch0(return0);
    case redtree_rulenum_primary__keyword_yield__LR__call_args__rparen:
    	return dispatch1(yield, dispatch1(paren, kids[2]));
    case redtree_rulenum_primary__keyword_yield__LR__rparen:
    	return dispatch1(yield, dispatch1(paren, arg_new()));
    case redtree_rulenum_primary__keyword_yield:
    	return dispatch0(yield0);
    case redtree_rulenum_primary__keyword_defined__opt_nl__LR__expr__rparen:
    	// kids[4] becomes kids[3] due to anonymous rule
    	return dispatch1(defined, kids[3]);
    case redtree_rulenum_primary__keyword_not__LR__expr__rparen:
    	return dispatch2(unary, ripper_intern("not"), kids[2]);
    case redtree_rulenum_primary__keyword_not__LR__rparen:
    	return dispatch2(unary, ripper_intern("not"), Qnil);
    case redtree_rulenum_primary__operation__brace_block:
    	tmp = method_arg(dispatch1(fcall, kids[0]), arg_new());
			return method_add_block(tmp, kids[1]);
    case redtree_rulenum_primary__method_call:
    	return kids[0];
    case redtree_rulenum_primary__method_call__brace_block:
    	return method_add_block(kids[0], kids[1]);
    case redtree_rulenum_primary__tLAMBDA__lambda:
    	return kids[1];
    case redtree_rulenum_primary__k_if__expr_value__then__compstmt__if_tail__k_end:
    	return dispatch3(if, kids[1], kids[3], kids[4]);
    case redtree_rulenum_primary__k_unless__expr_value__then__compstmt__opt_else__k_end:
    	return dispatch3(unless, kids[1], kids[3], kids[4]);
    case redtree_rulenum_primary__k_while__expr_value__do__compstmt__k_end:
    	// kids[2] becomes kids[1] due to anonymous rule
    	// kids[5] becomes kids[3] due to *two* anonymous rules
    	return dispatch2(while, kids[1], kids[3]);
    case redtree_rulenum_primary__k_until__expr_value__do__compstmt__k_end:
    	// kids[2] becomes kids[1] due to anonymous rule
    	// kids[5] becomes kids[3] due to *two* anonymous rules
    	return dispatch2(until, kids[1], kids[3]);
    case redtree_rulenum_primary__k_case__expr_value__opt_terms__case_body__k_end:
      return dispatch2(case, kids[1], kids[3]);
    case redtree_rulenum_primary__k_case__opt_terms__case_body__k_end:
    	return dispatch2(case, Qnil, kids[2]);
    case redtree_rulenum_primary__k_for__for_var__keyword_in__expr_value__do__compstmt__k_end:
      // kids[4] becomes kids[3] due to anonymous rule
    	// kids[7] becomes kids[5] due to *two* anonymous rules
    	return dispatch3(for, kids[1], kids[3], kids[5]);
    case redtree_rulenum_primary__k_class__cpath__superclass__bodystmt__k_end:
      // kids[4] becomes kids[3] due to anonymous rule
    	return dispatch3(class, kids[1], kids[2], kids[3]);
    case redtree_rulenum_primary__k_class__tLSHFT__expr__term__bodystmt__k_end:
    	// kids[6] becomes kids[4] due to *two* anonymous rules
    	return dispatch2(sclass, kids[2], kids[4]);
    case redtree_rulenum_primary__k_module__cpath__bodystmt__k_end:
    	// kids[3] becomes kids[2] due to anonymous rule
    	return dispatch2(module, kids[1], kids[2]);
    case redtree_rulenum_primary__k_def__fname__f_arglist__bodystmt__k_end:
    	// kids[3] becomes kids[2] due to anonymous rule
    	// kids[4] becomes kids[3] due to anonymous rule
    	return dispatch3(def, kids[1], kids[2], kids[3]);
    case redtree_rulenum_primary__k_def__singleton__dot_or_colon__fname__f_arglist__bodystmt__k_end:
    	// kids[4] becomes kids[3] due to anonymous rule
    	// kids[6] becomes kids[4] due to *two* anonymous rules
    	// kids[7] becomes kids[5] due to *two* anonymous rules
    	return dispatch5(defs, kids[1], kids[2], kids[3], kids[4], kids[5]);
    case redtree_rulenum_primary__keyword_break:
    	return dispatch1(break, arg_new());
    case redtree_rulenum_primary__keyword_next:
    	return dispatch1(next, arg_new());
    case redtree_rulenum_primary__keyword_redo:
    	return dispatch0(redo);
    case redtree_rulenum_primary__keyword_retry:
    	return dispatch0(retry);
    case redtree_rulenum_primary_value__primary:
    	return kids[0];
    case redtree_rulenum_k_begin__keyword_begin:
    case redtree_rulenum_k_if__keyword_if:
    case redtree_rulenum_k_unless__keyword_unless:
    case redtree_rulenum_k_while__keyword_while:
    case redtree_rulenum_k_until__keyword_until:
    case redtree_rulenum_k_case__keyword_case:
    case redtree_rulenum_k_for__keyword_for:
    case redtree_rulenum_k_class__keyword_class:
    case redtree_rulenum_k_module__keyword_module:
    case redtree_rulenum_k_def__keyword_def:
    case redtree_rulenum_k_end__keyword_end:
    	return kids[0];
    case redtree_rulenum_then__term:
    	return Qnil;
    case redtree_rulenum_then__keyword_then:
    	return kids[0];
    case redtree_rulenum_then__term__keyword_then:
    	return kids[1];
    case redtree_rulenum_do__term:
    	return Qnil;
    case redtree_rulenum_do__keyword_do_cond:
    	return kids[0];
    case redtree_rulenum_if_tail__opt_else:
    	return kids[0];
    case redtree_rulenum_if_tail__keyword_elsif__expr_value__then__compstmt__if_tail:
    	return dispatch3(elsif, kids[1], kids[3], kids[4]);
    case redtree_rulenum_opt_else__none:
    	return kids[0];
    case redtree_rulenum_opt_else__keyword_else__compstmt:
    	return dispatch1(else, kids[1]);
    case redtree_rulenum_for_var__lhs:
    case redtree_rulenum_for_var__mlhs:
    	return kids[0];
    case redtree_rulenum_f_marg__f_norm_arg:
    	return dispatch1(mlhs_paren, kids[0]);
    case redtree_rulenum_f_marg__tLPAREN__f_margs__rparen:
    	return dispatch1(mlhs_paren, kids[1]);
    case redtree_rulenum_f_marg_list__f_marg:
    	return mlhs_add(mlhs_new(), kids[0]);
    case redtree_rulenum_f_marg_list__f_marg_list__COMMA__f_marg:
    	return mlhs_add(kids[0], kids[2]);
    case redtree_rulenum_f_margs__f_marg_list:
    	return kids[0];
    case redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg:
    	return mlhs_add_star(kids[0], kids[3]);
    case redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg__COMMA__f_marg_list:
    	return mlhs_add_star(kids[0], kids[3]);
    case redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR:
    	return mlhs_add_star(kids[0], Qnil);
    case redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__COMMA__f_marg_list:
    	return mlhs_add_star(kids[0], kids[4]);
    case redtree_rulenum_f_margs__tSTAR__f_norm_arg:
    	return mlhs_add_star(mlhs_new(), kids[1]);
    case redtree_rulenum_f_margs__tSTAR__f_norm_arg__COMMA__f_marg_list:
    	return mlhs_add_star(kids[1], kids[3]);
    case redtree_rulenum_f_margs__tSTAR:
    	return mlhs_add_star(mlhs_new(), Qnil);
    case redtree_rulenum_f_margs__tSTAR__COMMA__f_marg_list:
    	return mlhs_add_star(mlhs_new(), Qnil);
    case redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], kids[4], Qnil, kids[5]);
    case redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], kids[4], kids[6], kids[7]);
    case redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], Qnil, Qnil, kids[3]);
    case redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], Qnil, kids[4], kids[5]);
    case redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil, kids[2], Qnil, kids[3]);
    case redtree_rulenum_block_param__f_arg__COMMA:
    	return params_new(kids[0], Qnil, Qnil, Qnil, Qnil);
    case redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil, kids[2], kids[4], kids[5]);
    case redtree_rulenum_block_param__f_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil,Qnil, Qnil, kids[1]);
    case redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], kids[2], Qnil, kids[3]);
    case redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], kids[2], kids[4], kids[5]);
    case redtree_rulenum_block_param__f_block_optarg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], Qnil, Qnil, kids[1]);
    case redtree_rulenum_block_param__f_block_optarg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], Qnil, kids[2], kids[3]);
    case redtree_rulenum_block_param__f_rest_arg__opt_f_block_arg:
    	return params_new(Qnil, Qnil, kids[0], Qnil, kids[1]);
    case redtree_rulenum_block_param__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, Qnil, kids[0], kids[2], kids[3]);
    case redtree_rulenum_block_param__f_block_arg:
    	return params_new(Qnil, Qnil, Qnil, Qnil, kids[0]);
    case redtree_rulenum_opt_block_param__none:
    	return kids[0];
    case redtree_rulenum_opt_block_param__block_param_def:
    	return Qnil;
    case redtree_rulenum_block_param_def__OR__opt_bv_decl__OR:
    	return blockvar_new(params_new(Qnil,Qnil,Qnil,Qnil,Qnil), kids[1]);
    case redtree_rulenum_block_param_def__tOROP:
    	return blockvar_new(params_new(Qnil,Qnil,Qnil,Qnil,Qnil), Qnil);
    case redtree_rulenum_block_param_def__OR__block_param__opt_bv_decl__OR:
    	return blockvar_new(kids[1], kids[2]);
    case redtree_rulenum_opt_bv_decl__none:
    	return kids[0];
    case redtree_rulenum_opt_bv_decl__SEMI__bv_decls:
    	return kids[1];
    case redtree_rulenum_bv_decls__bvar:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_bv_decls__bv_decls__COMMA__bvar:
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_bvar__tIDENTIFIER:
    	return kids[0];
    case redtree_rulenum_bvar__f_bad_arg:
    	return Qnil;
    case redtree_rulenum_lambda__f_larglist__lambda_body:
    	// kids[2] becomes kids[0] due to *two* anonymous rules
    	// kids[3] becomes kids[1] due to *two* anonymous rules
    	return dispatch2(lambda, kids[0], kids[1]);
    case redtree_rulenum_f_larglist__LR__f_args__opt_bv_decl__rparen:
    	
    	return dispatch1(paren, kids[1]);
    case redtree_rulenum_f_larglist__f_args:
    	return kids[0];
    case redtree_rulenum_lambda_body__tLAMBEG__compstmt__RC:
    	return kids[1];
    case redtree_rulenum_lambda_body__keyword_do_LAMBDA__compstmt__keyword_end:
    	return kids[1];
    case redtree_rulenum_do_block__keyword_do_block__opt_block_param__compstmt__keyword_end:
    	// kids[2] becomes kids[1] due to anonymous rule
    	// kids[3] becomes kids[2] due to anonymous rule
    	return dispatch2(do_block, kids[1], kids[2]);
    case redtree_rulenum_block_call__command__do_block:
    	return method_add_block(kids[0], kids[1]);
    case redtree_rulenum_block_call__block_call__DOT__operation2__opt_paren_args:
    	return method_optarg(dispatch3(call, kids[0], redtree_id2sym('.'), kids[2]), kids[3]);
    case redtree_rulenum_block_call__block_call__tCOLON2__operation2__opt_paren_args:
    	return method_optarg(dispatch3(call, kids[0], ripper_intern("::"), kids[2]), kids[3]);
    case redtree_rulenum_method_call__operation__paren_args:
    	return method_arg(dispatch1(fcall, kids[0]), kids[1]);
    case redtree_rulenum_method_call__primary_value__DOT__operation2__opt_paren_args:
			return method_optarg(dispatch3(call, kids[0], redtree_id2sym('.'), kids[2]), kids[3]);
    case redtree_rulenum_method_call__primary_value__tCOLON2__operation2__paren_args:
			return method_optarg(dispatch3(call, kids[0], redtree_id2sym('.'), kids[2]), kids[3]);
    case redtree_rulenum_method_call__primary_value__tCOLON2__operation3:
    	return dispatch3(call, kids[0], ripper_intern("::"), kids[2]);
    case redtree_rulenum_method_call__primary_value__DOT__paren_args:
    	tmp = dispatch3(call, kids[0], redtree_id2sym('.'), ripper_intern("call"));
			return method_optarg(tmp, kids[2]);
    case redtree_rulenum_method_call__primary_value__tCOLON2__paren_args:
    	tmp = dispatch3(call, kids[0], ripper_intern("::"), ripper_intern("call"));
			return method_optarg(tmp, kids[2]);
    case redtree_rulenum_method_call__keyword_super__paren_args:
    	return dispatch1(super, kids[1]);
    case redtree_rulenum_method_call__keyword_super:
    	return dispatch0(zsuper);
    case redtree_rulenum_method_call__primary_value__LS__opt_call_args__rbracket:
    	return dispatch2(aref, kids[0], kids[2]);
    case redtree_rulenum_brace_block__LC__opt_block_param__compstmt__RC:
    	// kids[2] becomes kids[1] due to anonymous rules
    	// kids[3] becomes kids[2] due to anonymous rules
    	return dispatch2(brace_block, kids[1], kids[2]);
    case redtree_rulenum_brace_block__keyword_do__opt_block_param__compstmt__keyword_end:
    	// kids[2] becomes kids[1] due to anonymous rules
    	// kids[3] becomes kids[2] due to anonymous rules
    	return dispatch2(do_block, kids[1], kids[2]);
    case redtree_rulenum_case_body__keyword_when__args__then__compstmt__cases:
    	return dispatch3(when, kids[1], kids[3], kids[4]);
    case redtree_rulenum_cases__opt_else:
    case redtree_rulenum_cases__case_body:
    	return kids[0];
    case redtree_rulenum_opt_rescue__keyword_rescue__exc_list__exc_var__then__compstmt__opt_rescue:
    	return dispatch4(rescue, kids[1], kids[2], kids[4], kids[5]);
    case redtree_rulenum_opt_rescue__none:
    	return kids[0];
    case redtree_rulenum_exc_list__arg_value:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_exc_list__mrhs:
    	return kids[0];
    case redtree_rulenum_exc_list__none:
    	return kids[0];
    case redtree_rulenum_exc_var__tASSOC__lhs:
    	return kids[1];
    case redtree_rulenum_exc_var__none:
    	return kids[0];
    case redtree_rulenum_opt_ensure__keyword_ensure__compstmt:
    	return dispatch1(ensure, kids[1]);
    case redtree_rulenum_opt_ensure__none:
    	return kids[0];
    case redtree_rulenum_literal__numeric:
    	return kids[0];
    case redtree_rulenum_literal__symbol:
    	return dispatch1(symbol_literal, kids[0]);
    case redtree_rulenum_literal__dsym:
      return kids[0];
    case redtree_rulenum_strings__string:
    	return kids[0];
    case redtree_rulenum_string__tCHAR:
    case redtree_rulenum_string__string1:
    	return kids[0];
    case redtree_rulenum_string__string__string1:
    	return dispatch2(string_concat, kids[0], kids[1]);
    case redtree_rulenum_string1__tSTRING_BEG__string_contents__tSTRING_END:
    	return dispatch1(string_literal, kids[1]);
    case redtree_rulenum_xstring__tXSTRING_BEG__xstring_contents__tSTRING_END:
    	return dispatch1(xstring_literal, kids[1]);
    case redtree_rulenum_regexp__tREGEXP_BEG__regexp_contents__tREGEXP_END:
    	return dispatch2(regexp_literal, kids[1], kids[2]);
    case redtree_rulenum_words__tWORDS_BEG__SP__tSTRING_END:
    	return dispatch1(array, dispatch0(words_new));
    case redtree_rulenum_words__tWORDS_BEG__word_list__tSTRING_END:
    	return dispatch1(array, kids[1]);
    case redtree_rulenum_word_list__:
    	return dispatch0(words_new);
    case redtree_rulenum_word_list__word_list__word__SP:
    	return dispatch2(words_add, kids[0], kids[1]);
    case redtree_rulenum_word__string_content:
			return dispatch2(word_add, dispatch0(word_new), kids[0]);
    case redtree_rulenum_word__word__string_content:
    	return dispatch2(word_add, kids[0], kids[1]);
    case redtree_rulenum_qwords__tQWORDS_BEG__SP__tSTRING_END:
    	return dispatch1(array, dispatch0(qwords_new));
    case redtree_rulenum_qwords__tQWORDS_BEG__qword_list__tSTRING_END:
    	return dispatch1(array, kids[1]);
    case redtree_rulenum_qword_list__:
    	return dispatch0(qwords_new);
    case redtree_rulenum_qword_list__qword_list__tSTRING_CONTENT__SP:
    	return dispatch2(qwords_add, kids[0], kids[1]);
    case redtree_rulenum_string_contents__:
    	return dispatch0(string_content);
    case redtree_rulenum_string_contents__string_contents__string_content:
    	return dispatch2(string_add, kids[0], kids[1]);
    case redtree_rulenum_xstring_contents__:
    	return dispatch0(xstring_new);
    case redtree_rulenum_xstring_contents__xstring_contents__string_content:
    	return dispatch2(xstring_add, kids[0], kids[1]);
    case redtree_rulenum_regexp_contents__:
    	return dispatch0(regexp_new);
    case redtree_rulenum_regexp_contents__regexp_contents__string_content:
    	return dispatch2(regexp_add, kids[0], kids[1]);
    case redtree_rulenum_string_content__tSTRING_CONTENT:
    	return kids[0];
    case redtree_rulenum_string_content__tSTRING_DVAR__string_dvar:
    	// kids[2] becomes kids[1] due to anonymous rule
    	return dispatch1(string_dvar, kids[1]);
    case redtree_rulenum_string_content__tSTRING_DBEG__compstmt__RC:
    	// kids[3] becomes kids[1] due to *two* anonymous rules
    	return dispatch1(string_embexpr, kids[1]);
    case redtree_rulenum_string_dvar__tGVAR:
    case redtree_rulenum_string_dvar__tIVAR:
    case redtree_rulenum_string_dvar__tCVAR:
    	return dispatch1(var_ref, kids[0]);
    case redtree_rulenum_string_dvar__backref:
    	return kids[0];
    case redtree_rulenum_symbol__tSYMBEG__sym:
    	return dispatch1(symbol, kids[1]);
    case redtree_rulenum_sym__fname:
    case redtree_rulenum_sym__tIVAR:
    case redtree_rulenum_sym__tGVAR:
    case redtree_rulenum_sym__tCVAR:
    	return kids[0];
    case redtree_rulenum_dsym__tSYMBEG__xstring_contents__tSTRING_END:
    	return dispatch1(dyna_symbol, kids[1]);
    case redtree_rulenum_numeric__tINTEGER:
    case redtree_rulenum_numeric__tFLOAT:
    	return kids[0];
    case redtree_rulenum_numeric__tUMINUS_NUM__tINTEGER:
    case redtree_rulenum_numeric__tUMINUS_NUM__tFLOAT:
    	return dispatch2(unary, ripper_intern("-@"), kids[1]);
    case redtree_rulenum_user_variable__tIDENTIFIER:
    case redtree_rulenum_user_variable__tIVAR:
    case redtree_rulenum_user_variable__tGVAR:
    case redtree_rulenum_user_variable__tCONSTANT:
    case redtree_rulenum_user_variable__tCVAR:
    	return kids[0];
    case redtree_rulenum_keyword_variable__keyword_nil:
    case redtree_rulenum_keyword_variable__keyword_self:
    case redtree_rulenum_keyword_variable__keyword_true:
    case redtree_rulenum_keyword_variable__keyword_false:
    case redtree_rulenum_keyword_variable__keyword_FILE:
    case redtree_rulenum_keyword_variable__keyword_LINE:
    case redtree_rulenum_keyword_variable__keyword_ENCODING:
    	return kids[0];
    case redtree_rulenum_var_ref__user_variable:
    	return dispatch1(var_ref, kids[0]);
    case redtree_rulenum_vcall__user_variable:
    	return dispatch1(vcall, kids[0]);
    case redtree_rulenum_var_ref__keyword_variable:
    	return dispatch1(var_ref, kids[0]);
    case redtree_rulenum_var_lhs__user_variable:
    	return dispatch1(var_field, kids[0]);
    case redtree_rulenum_var_field__keyword_variable:
    	return dispatch1(var_field, kids[0]);
    case redtree_rulenum_backref__tNTH_REF:
    case redtree_rulenum_backref__tBACK_REF:
    	return kids[0];
    case redtree_rulenum_superclass__term:
    	return Qnil;
    case redtree_rulenum_superclass__LT__expr_value__term:
    	// kids[2] becomes kids[1] due to anonymous rule
    	return kids[1];
    case redtree_rulenum_superclass__error__term:
    	return Qnil;
    case redtree_rulenum_f_arglist__LR__f_args__rparen:
    	return dispatch1(paren, kids[1]);
    case redtree_rulenum_f_arglist__f_args__term:
    	return kids[0];
    case redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], kids[4], Qnil, kids[5]);
    case redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], kids[4], kids[6], kids[7]);
    case redtree_rulenum_f_args__f_arg__COMMA__f_optarg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], Qnil, Qnil, kids[3]);
    case redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], kids[2], Qnil, kids[4], kids[5]);
    case redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil, kids[2], Qnil, kids[3]);
    case redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil, kids[2], kids[4], kids[5]);
    case redtree_rulenum_f_args__f_arg__opt_f_block_arg:
    	return params_new(kids[0], Qnil, Qnil, Qnil,kids[1]);
    case redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], kids[2], Qnil, kids[3]);
    case redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], kids[2], kids[4], kids[5]);
    case redtree_rulenum_f_args__f_optarg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], Qnil, Qnil,kids[1]);
    case redtree_rulenum_f_args__f_optarg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, kids[0], Qnil, kids[2], kids[3]);
    case redtree_rulenum_f_args__f_rest_arg__opt_f_block_arg:
    	return params_new(Qnil, Qnil, kids[0], Qnil,kids[1]);
    case redtree_rulenum_f_args__f_rest_arg__COMMA__f_arg__opt_f_block_arg:
    	return params_new(Qnil, Qnil, kids[0], kids[2], kids[3]);
    case redtree_rulenum_f_args__f_block_arg:
    	return params_new(Qnil, Qnil, Qnil, Qnil, kids[0]);
    case redtree_rulenum_f_args__:
    	return params_new(Qnil, Qnil, Qnil, Qnil, Qnil);
    case redtree_rulenum_f_bad_arg__tCONSTANT:
    case redtree_rulenum_f_bad_arg__tIVAR:
    case redtree_rulenum_f_bad_arg__tGVAR:
    case redtree_rulenum_f_bad_arg__tCVAR:
    	return dispatch1(param_error, kids[0]);
    case redtree_rulenum_f_norm_arg__f_bad_arg:
    case redtree_rulenum_f_norm_arg__tIDENTIFIER:
    	return kids[0];
    case redtree_rulenum_f_arg_item__f_norm_arg:
    	return kids[0];
    case redtree_rulenum_f_arg_item__tLPAREN__f_margs__rparen:
    	return dispatch1(mlhs_paren, kids[1]);
    case redtree_rulenum_f_arg__f_arg_item:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_f_arg__f_arg__COMMA__f_arg_item:
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_f_opt__tIDENTIFIER__EQ__arg_value:
    	return rb_assoc_new(kids[0], kids[2]);
    case redtree_rulenum_f_block_opt__tIDENTIFIER__EQ__primary_value:
    	return rb_assoc_new(kids[0], kids[2]);
    case redtree_rulenum_f_block_optarg__f_block_opt:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_f_block_optarg__f_block_optarg__COMMA__f_block_opt:
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_f_optarg__f_opt:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_f_optarg__f_optarg__COMMA__f_opt:
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_restarg_mark__TIMES:
    case redtree_rulenum_restarg_mark__tSTAR:
    	return kids[0];
    case redtree_rulenum_f_rest_arg__restarg_mark__tIDENTIFIER:
    	return dispatch1(rest_param, kids[1]);
    case redtree_rulenum_f_rest_arg__restarg_mark:
    	return dispatch1(rest_param, Qnil);
    case redtree_rulenum_blkarg_mark__AND:
    case redtree_rulenum_blkarg_mark__tAMPER:
    	return kids[0];
    case redtree_rulenum_f_block_arg__blkarg_mark__tIDENTIFIER:
    	return dispatch1(blockarg, kids[1]);
    case redtree_rulenum_opt_f_block_arg__COMMA__f_block_arg:
    	return kids[1];
    case redtree_rulenum_opt_f_block_arg__none:
    	return Qnil;
    case redtree_rulenum_singleton__var_ref:
    	return kids[0];
    case redtree_rulenum_singleton__LR__expr__rparen:
    	// kids[2] becomes kids[1] due to anonymous rule
    	return dispatch1(paren, kids[1]);
    case redtree_rulenum_assoc_list__none:
    	return kids[0];
    case redtree_rulenum_assoc_list__assocs__trailer:
    	return dispatch1(assoclist_from_args, kids[0]);
    case redtree_rulenum_assocs__assoc:
    	return rb_ary_new3(1, kids[0]);
    case redtree_rulenum_assocs__assocs__COMMA__assoc:
    	return rb_ary_push(kids[0], kids[2]);
    case redtree_rulenum_assoc__arg_value__tASSOC__arg_value:
    	return dispatch2(assoc_new, kids[0], kids[2]);
    case redtree_rulenum_assoc__tLABEL__arg_value:
    	return dispatch2(assoc_new, kids[0], kids[1]);
    case redtree_rulenum_operation__tIDENTIFIER:
    case redtree_rulenum_operation__tCONSTANT:
    case redtree_rulenum_operation__tFID:
    	return kids[0];
    case redtree_rulenum_operation2__tIDENTIFIER:
    case redtree_rulenum_operation2__tCONSTANT:
    case redtree_rulenum_operation2__tFID:
    case redtree_rulenum_operation2__op:
    	return kids[0];
    case redtree_rulenum_operation3__tIDENTIFIER:
    case redtree_rulenum_operation3__tFID:
    case redtree_rulenum_operation3__op:
    	return kids[0];
    case redtree_rulenum_dot_or_colon__DOT:
    case redtree_rulenum_dot_or_colon__tCOLON2:
    	return kids[0];
    case redtree_rulenum_opt_terms__:
    	return Qnil;
    case redtree_rulenum_opt_terms__terms:
    	return kids[0];
    case redtree_rulenum_opt_nl__:
    	return Qnil;
    case redtree_rulenum_opt_nl__NL:
    	return kids[0];
    case redtree_rulenum_rparen__opt_nl__RR:
    	return kids[0];
    case redtree_rulenum_rbracket__opt_nl__RS:
    	return kids[0];
    case redtree_rulenum_trailer__:
    	return Qnil;
    case redtree_rulenum_trailer__NL:
    	return kids[0];
    case redtree_rulenum_trailer__COMMA:
    	return kids[0];
    case redtree_rulenum_term__SEMI:
    	return kids[0];
    case redtree_rulenum_term__NL:
    	return kids[0];
    case redtree_rulenum_terms__term:
    	return kids[0];
    case redtree_rulenum_terms__terms__SEMI:
    	return kids[0];
    case redtree_rulenum_none__:
    	return Qnil;
    case redtree_rulenum_magic_comment:
		// return kids[0] default production
		default:
		  return kids[0];
	}
}

#undef arg_new()
#undef arg_add(l,a)
#undef arg_add_star(l,a)
#undef arg_add_block(l,b)
#undef arg_add_optblock(l,b)
#undef bare_assoc(v)
#undef arg_add_assocs(l,b)

#undef args2mrhs(a)
#undef mrhs_new()
#undef mrhs_add(l,a)
#undef mrhs_add_star(l,a)

#undef mlhs_new()
#undef mlhs_add(l,a)
#undef mlhs_add_star(l,a)

#undef params_new(pars, opts, rest, pars2, blk)

#undef blockvar_new(p,v)
#undef blockvar_add_star(l,a)
#undef blockvar_add_block(l,a)

#undef method_optarg(m,a)
#undef method_arg(m,a)
#undef method_add_block(m,b)

#undef dispatch0
#undef dispatch1
#undef dispatch2
#undef dispatch3
#undef dispatch4
#undef dispatch4

static VALUE
ripper_dispatch0(VALUE walker, ID mid)
{
    return rb_funcall(walker, mid, 0);
}

static VALUE
ripper_dispatch1(VALUE walker, ID mid, VALUE a)
{
    return rb_funcall(walker, mid, 1, a);
}

static VALUE
ripper_dispatch2(VALUE walker, ID mid, VALUE a, VALUE b)
{
    return rb_funcall(walker, mid, 2, a, b);
}

static VALUE
ripper_dispatch3(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c)
{
    return rb_funcall(walker, mid, 3, a, b, c);
}

static VALUE
ripper_dispatch4(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c, VALUE d)
{
    return rb_funcall(walker, mid, 4, a, b, c, d);
}

static VALUE
ripper_dispatch5(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e)
{
    return rb_funcall(walker, mid, 5, a, b, c, d, e);
}