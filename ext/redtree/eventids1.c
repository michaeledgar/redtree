enum redtree_ids {
  redtree_rulenum_UNUSED,
  redtree_rulenum_program__top_compstmt,
  redtree_rulenum_top_compstmt__top_stmts__opt_terms,
  redtree_rulenum_top_stmts__none,
  redtree_rulenum_top_stmts__top_stmt,
  redtree_rulenum_top_stmts__top_stmts__terms__top_stmt,
  redtree_rulenum_top_stmts__error__top_stmt,
  redtree_rulenum_top_stmt__stmt,
  redtree_rulenum_top_stmt__keyword_BEGIN__LC__top_compstmt__RC,
  redtree_rulenum_bodystmt__compstmt__opt_rescue__opt_else__opt_ensure,
  redtree_rulenum_compstmt__stmts__opt_terms,
  redtree_rulenum_stmts__none,
  redtree_rulenum_stmts__stmt,
  redtree_rulenum_stmts__stmts__terms__stmt,
  redtree_rulenum_stmts__error__stmt,
  redtree_rulenum_stmt__keyword_alias__fitem__fitem,
  redtree_rulenum_stmt__keyword_alias__tGVAR__tGVAR,
  redtree_rulenum_stmt__keyword_alias__tGVAR__tBACK_REF,
  redtree_rulenum_stmt__keyword_alias__tGVAR__tNTH_REF,
  redtree_rulenum_stmt__keyword_undef__undef_list,
  redtree_rulenum_stmt__stmt__modifier_if__expr_value,
  redtree_rulenum_stmt__stmt__modifier_unless__expr_value,
  redtree_rulenum_stmt__stmt__modifier_while__expr_value,
  redtree_rulenum_stmt__stmt__modifier_until__expr_value,
  redtree_rulenum_stmt__stmt__modifier_rescue__stmt,
  redtree_rulenum_stmt__keyword_END__LC__compstmt__RC,
  redtree_rulenum_stmt__command_asgn,
  redtree_rulenum_stmt__mlhs__EQ__command_call,
  redtree_rulenum_stmt__var_lhs__tOP_ASGN__command_call,
  redtree_rulenum_stmt__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__command_call,
  redtree_rulenum_stmt__primary_value__DOT__tIDENTIFIER__tOP_ASGN__command_call,
  redtree_rulenum_stmt__primary_value__DOT__tCONSTANT__tOP_ASGN__command_call,
  redtree_rulenum_stmt__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__command_call,
  redtree_rulenum_stmt__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__command_call,
  redtree_rulenum_stmt__backref__tOP_ASGN__command_call,
  redtree_rulenum_stmt__lhs__EQ__mrhs,
  redtree_rulenum_stmt__mlhs__EQ__arg_value,
  redtree_rulenum_stmt__mlhs__EQ__mrhs,
  redtree_rulenum_stmt__expr,
  redtree_rulenum_command_asgn__lhs__EQ__command_call,
  redtree_rulenum_command_asgn__lhs__EQ__command_asgn,
  redtree_rulenum_expr__command_call,
  redtree_rulenum_expr__expr__keyword_and__expr,
  redtree_rulenum_expr__expr__keyword_or__expr,
  redtree_rulenum_expr__keyword_not__opt_nl__expr,
  redtree_rulenum_expr__BANG__command_call,
  redtree_rulenum_expr__arg,
  redtree_rulenum_expr_value__expr,
  redtree_rulenum_command_call__command,
  redtree_rulenum_command_call__block_command,
  redtree_rulenum_block_command__block_call,
  redtree_rulenum_block_command__block_call__DOT__operation2__command_args,
  redtree_rulenum_block_command__block_call__tCOLON2__operation2__command_args,
  redtree_rulenum_cmd_brace_block__tLBRACE_ARG__opt_block_param__compstmt__RC,
  redtree_rulenum_command__operation__command_args,
  redtree_rulenum_command__operation__command_args__cmd_brace_block,
  redtree_rulenum_command__primary_value__DOT__operation2__command_args,
  redtree_rulenum_command__primary_value__DOT__operation2__command_args__cmd_brace_block,
  redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args,
  redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args__cmd_brace_block,
  redtree_rulenum_command__keyword_super__command_args,
  redtree_rulenum_command__keyword_yield__command_args,
  redtree_rulenum_command__keyword_return__call_args,
  redtree_rulenum_command__keyword_break__call_args,
  redtree_rulenum_command__keyword_next__call_args,
  redtree_rulenum_mlhs__mlhs_basic,
  redtree_rulenum_mlhs__tLPAREN__mlhs_inner__rparen,
  redtree_rulenum_mlhs_inner__mlhs_basic,
  redtree_rulenum_mlhs_inner__tLPAREN__mlhs_inner__rparen,
  redtree_rulenum_mlhs_basic__mlhs_head,
  redtree_rulenum_mlhs_basic__mlhs_head__mlhs_item,
  redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node,
  redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node__COMMA__mlhs_post,
  redtree_rulenum_mlhs_basic__mlhs_head__tSTAR,
  redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__COMMA__mlhs_post,
  redtree_rulenum_mlhs_basic__tSTAR__mlhs_node,
  redtree_rulenum_mlhs_basic__tSTAR__mlhs_node__COMMA__mlhs_post,
  redtree_rulenum_mlhs_basic__tSTAR,
  redtree_rulenum_mlhs_basic__tSTAR__COMMA__mlhs_post,
  redtree_rulenum_mlhs_item__mlhs_node,
  redtree_rulenum_mlhs_item__tLPAREN__mlhs_inner__rparen,
  redtree_rulenum_mlhs_head__mlhs_item__COMMA,
  redtree_rulenum_mlhs_head__mlhs_head__mlhs_item__COMMA,
  redtree_rulenum_mlhs_post__mlhs_item,
  redtree_rulenum_mlhs_post__mlhs_post__COMMA__mlhs_item,
  redtree_rulenum_mlhs_node__user_variable,
  redtree_rulenum_mlhs_node__keyword_variable,
  redtree_rulenum_mlhs_node__primary_value__LS__opt_call_args__rbracket,
  redtree_rulenum_mlhs_node__primary_value__DOT__tIDENTIFIER,
  redtree_rulenum_mlhs_node__primary_value__tCOLON2__tIDENTIFIER,
  redtree_rulenum_mlhs_node__primary_value__DOT__tCONSTANT,
  redtree_rulenum_mlhs_node__primary_value__tCOLON3__tCONSTANT,
  redtree_rulenum_mlhs_node__tCOLON3__tCONSTANT,
  redtree_rulenum_mlhs_node__backref,
  redtree_rulenum_lhs__user_variable,
  redtree_rulenum_lhs__keyword_variable,
  redtree_rulenum_lhs__primary_value__LS__opt_call_args__rbracket,
  redtree_rulenum_lhs__primary_value__DOT__tIDENTIFIER,
  redtree_rulenum_lhs__primary_value__tCOLON2__tIDENTIFIER,
  redtree_rulenum_lhs__primary_value__DOT__tCONSTANT,
  redtree_rulenum_lhs__primary_value__tCOLON3__tCONSTANT,
  redtree_rulenum_lhs__tCOLON3__tCONSTANT,
  redtree_rulenum_lhs__backref,
  redtree_rulenum_cname__tIDENTIFIER,
  redtree_rulenum_cname__tCONSTANT,
  redtree_rulenum_cpath__tCOLON3__cname,
  redtree_rulenum_cpath__cname,
  redtree_rulenum_cpath__primary_value__tCOLON2__cname,
  redtree_rulenum_fname__tIDENTIFIER,
  redtree_rulenum_fname__tCONSTANT,
  redtree_rulenum_fname__tFID,
  redtree_rulenum_fname__op,
  redtree_rulenum_fname__reswords,
  redtree_rulenum_fsym__fname,
  redtree_rulenum_fsym__symbol,
  redtree_rulenum_fitem__fsym,
  redtree_rulenum_fitem__dsym,
  redtree_rulenum_undef_list__fitem,
  redtree_rulenum_undef_list__COMMA__fitem,
  redtree_rulenum_op__OR,
  redtree_rulenum_op__CARET,
  redtree_rulenum_op__AND,
  redtree_rulenum_op__tCMP,
  redtree_rulenum_op__tEQ,
  redtree_rulenum_op__tEQQ,
  redtree_rulenum_op__tMATCH,
  redtree_rulenum_op__tNMATCH,
  redtree_rulenum_op__GT,
  redtree_rulenum_op__tGEQ,
  redtree_rulenum_op__LE,
  redtree_rulenum_op__tLEQ,
  redtree_rulenum_op__tNEQ,
  redtree_rulenum_op__tLSHFT,
  redtree_rulenum_op__tRSHFT,
  redtree_rulenum_op__PLUS,
  redtree_rulenum_op__MINUS,
  redtree_rulenum_op__TIMES,
  redtree_rulenum_op__tSTAR,
  redtree_rulenum_op__DIVIDE,
  redtree_rulenum_op__MOD,
  redtree_rulenum_op__tPOW,
  redtree_rulenum_op__BANG,
  redtree_rulenum_op__TILDE,
  redtree_rulenum_op__tUPLUS,
  redtree_rulenum_op__tUMINUS,
  redtree_rulenum_op__tAREF,
  redtree_rulenum_op__tASET,
  redtree_rulenum_op__BACKTICK,
  redtree_rulenum_reswords__keyword__LINE__,
  redtree_rulenum_reswords__keyword__FILE__,
  redtree_rulenum_reswords__keyword__ENCODING__,
  redtree_rulenum_reswords__keyword_BEGIN,
  redtree_rulenum_reswords__keyword_END,
  redtree_rulenum_reswords__keyword_alias,
  redtree_rulenum_reswords__keyword_and,
  redtree_rulenum_reswords__keyword_begin,
  redtree_rulenum_reswords__keyword_break,
  redtree_rulenum_reswords__keyword_case,
  redtree_rulenum_reswords__keyword_class,
  redtree_rulenum_reswords__keyword_def,
  redtree_rulenum_reswords__keyword_defined,
  redtree_rulenum_reswords__keyword_do,
  redtree_rulenum_reswords__keyword_else,
  redtree_rulenum_reswords__keyword_elsif,
  redtree_rulenum_reswords__keyword_end,
  redtree_rulenum_reswords__keyword_ensure,
  redtree_rulenum_reswords__keyword_false,
  redtree_rulenum_reswords__keyword_for,
  redtree_rulenum_reswords__keyword_in,
  redtree_rulenum_reswords__keyword_module,
  redtree_rulenum_reswords__keyword_next,
  redtree_rulenum_reswords__keyword_nil,
  redtree_rulenum_reswords__keyword_not,
  redtree_rulenum_reswords__keyword_or,
  redtree_rulenum_reswords__keyword_redo,
  redtree_rulenum_reswords__keyword_rescue,
  redtree_rulenum_reswords__keyword_retry,
  redtree_rulenum_reswords__keyword_return,
  redtree_rulenum_reswords__keyword_self,
  redtree_rulenum_reswords__keyword_super,
  redtree_rulenum_reswords__keyword_then,
  redtree_rulenum_reswords__keyword_true,
  redtree_rulenum_reswords__keyword_undef,
  redtree_rulenum_reswords__keyword_when,
  redtree_rulenum_reswords__keyword_yield,
  redtree_rulenum_reswords__keyword_if,
  redtree_rulenum_reswords__keyword_unless,
  redtree_rulenum_reswords__keyword_while,
  redtree_rulenum_reswords__keyword_until,
  redtree_rulenum_arg__lhs__EQ__arg,
  redtree_rulenum_arg__lhs__EQ__arg__modifier_rescue__arg,
  redtree_rulenum_arg__var_lhs__tOP_ASGN__arg,
  redtree_rulenum_arg__var_lhs__tOP_ASGN__arg__modifier_rescue__arg,
  redtree_rulenum_arg__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__arg,
  redtree_rulenum_arg__primary_value__DOT__tIDENTIFIER__tOP_ASGN__arg,
  redtree_rulenum_arg__primary_value__DOT__tCONSTANT__tOP_ASGN__arg,
  redtree_rulenum_arg__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__arg,
  redtree_rulenum_arg__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__arg,
  redtree_rulenum_arg__tCOLON3__tCONSTANT__tOP_ASGN__arg,
  redtree_rulenum_arg__backref__tOP_ASGN__arg,
  redtree_rulenum_arg__arg__tDOT2__arg,
  redtree_rulenum_arg__arg__tDOT3__arg,
  redtree_rulenum_arg__arg__PLUS__arg,
  redtree_rulenum_arg__arg__MINUS__arg,
  redtree_rulenum_arg__arg__TIMES__arg,
  redtree_rulenum_arg__arg__DIVIDE__arg,
  redtree_rulenum_arg__arg__tPOW__arg,
  redtree_rulenum_arg__tUMINUS_NUM__tINTEGER__tPOW__arg,
  redtree_rulenum_arg__tUMINUS_NUM__tFLOAT__tPOW__arg,
  redtree_rulenum_arg__tUPLUS__arg,
  redtree_rulenum_arg__tUMINUS__arg,
  redtree_rulenum_arg__arg__OR__arg,
  redtree_rulenum_arg__arg__CARET__arg,
  redtree_rulenum_arg__arg__AND__arg,
  redtree_rulenum_arg__arg__tCMP__arg,
  redtree_rulenum_arg__arg__GT__arg,
  redtree_rulenum_arg__arg__tGEQ__arg,
  redtree_rulenum_arg__arg__LT__arg,
  redtree_rulenum_arg__arg__tLEQ__arg,
  redtree_rulenum_arg__arg__tEQ__arg,
  redtree_rulenum_arg__arg__tEQQ__arg,
  redtree_rulenum_arg__arg__tNEQ__arg,
  redtree_rulenum_arg__arg__tMATCH__arg,
  redtree_rulenum_arg__arg__tNMATCH__arg,
  redtree_rulenum_arg__BANG__arg,
  redtree_rulenum_arg__TILDE__arg,
  redtree_rulenum_arg__arg__tLSHFT__arg,
  redtree_rulenum_arg__arg__tRSHFT__arg,
  redtree_rulenum_arg__arg__tANDOP__arg,
  redtree_rulenum_arg__arg__tOROP__arg,
  redtree_rulenum_arg__keyword_defined__opt_nl__arg,
  redtree_rulenum_arg__QMARK__arg__opt_nl__COLON__arg,
  redtree_rulenum_arg__primary,
  redtree_rulenum_arg_value__arg,
  redtree_rulenum_aref_args__none,
  redtree_rulenum_aref_args__args__trailer,
  redtree_rulenum_aref_args__args__COMMA__assocs__trailer,
  redtree_rulenum_aref_args__assocs__trailer,
  redtree_rulenum_paren_args__LR__opt_call_args__rparen,
  redtree_rulenum_opt_paren_args__none,
  redtree_rulenum_opt_paren_args__paren_args,
  redtree_rulenum_opt_call_args__none,
  redtree_rulenum_opt_call_args__call_args,
  redtree_rulenum_opt_call_args__args__COMMA,
  redtree_rulenum_opt_call_args__args__COMMA__assocs__COMMA,
  redtree_rulenum_opt_call_args__assocs__COMMA,
  redtree_rulenum_call_args__command,
  redtree_rulenum_call_args__args__opt_block_arg,
  redtree_rulenum_call_args__assocs__opt_block_arg,
  redtree_rulenum_call_args__args__COMMA__assocs__opt_block_arg,
  redtree_rulenum_call_args__block_arg,
  redtree_rulenum_command_args__call_args,
  redtree_rulenum_block_arg__tAMPER__arg_value,
  redtree_rulenum_opt_block_arg__COMMA__block_arg,
  redtree_rulenum_opt_block_arg__none,
  redtree_rulenum_args__arg_value,
  redtree_rulenum_args__tSTAR__arg_value,
  redtree_rulenum_args__args__COMMA__arg_value,
  redtree_rulenum_args__args__COMMA__tSTAR__arg_value,
  redtree_rulenum_mrhs__args__COMMA__arg_value,
  redtree_rulenum_mrhs__args__COMMA__tSTAR__arg_value,
  redtree_rulenum_mrhs__tSTAR__arg_value,
  redtree_rulenum_primary__literal,
  redtree_rulenum_primary__strings,
  redtree_rulenum_primary__xstring,
  redtree_rulenum_primary__regexp,
  redtree_rulenum_primary__words,
  redtree_rulenum_primary__qwords,
  redtree_rulenum_primary__var_ref,
  redtree_rulenum_primary__backref,
  redtree_rulenum_primary__tFID,
  redtree_rulenum_primary__k_begin,
  redtree_rulenum_primary__tLPAREN_ARG__expr__rparen,
  redtree_rulenum_primary__tLPAREN__compstmt__RR,
  redtree_rulenum_primary__primary_value__tCOLON2__tCONSTANT,
  redtree_rulenum_primary__tCOLON3__tCONSTANT,
  redtree_rulenum_primary__tLBRACK__aref_args__RS,
  redtree_rulenum_primary__tLBRACE__assoc_list__RC,
  redtree_rulenum_primary__keyword_return,
  redtree_rulenum_primary__keyword_yield__LR__call_args__rparen,
  redtree_rulenum_primary__keyword_yield__LR__rparen,
  redtree_rulenum_primary__keyword_yield,
  redtree_rulenum_primary__keyword_defined__opt_nl__LR__expr__rparen,
  redtree_rulenum_primary__keyword_not__LR__expr__rparen,
  redtree_rulenum_primary__keyword_not__LR__rparen,
  redtree_rulenum_primary__operation__brace_block,
  redtree_rulenum_primary__method_call,
  redtree_rulenum_primary__method_call__brace_block,
  redtree_rulenum_primary__tLAMBDA__lambda,
  redtree_rulenum_primary__k_if__expr_value__then__compstmt__if_tail__k_end,
  redtree_rulenum_primary__k_unless__expr_value__then__compstmt__opt_else__k_end,
  redtree_rulenum_primary__k_while__expr_value__do__compstmt__k_end,
  redtree_rulenum_primary__k_until__expr_value__do__compstmt__k_end,
  redtree_rulenum_primary__k_case__expr_value__opt_terms__case_body__k_end,
  redtree_rulenum_primary__k_case__opt_terms__case_body__k_end,
  redtree_rulenum_primary__k_for__for_var__keyword_in__expr_value__do__compstmt__k_end,
  redtree_rulenum_primary__k_class__cpath__superclass__bodystmt__k_end,
  redtree_rulenum_primary__k_class__tLSHFT__expr__term__bodystmt__k_end,
  redtree_rulenum_primary__k_module__cpath__bodystmt__k_end,
  redtree_rulenum_primary__k_def__fname__f_arglist__bodystmt__k_end,
  redtree_rulenum_primary__k_def__singleton__dot_or_colon__fname__f_arglist__bodystmt__k_end,
  redtree_rulenum_primary__keyword_break,
  redtree_rulenum_primary__keyword_next,
  redtree_rulenum_primary__keyword_redo,
  redtree_rulenum_primary__keyword_retry,
  redtree_rulenum_primary_value__primary,
  redtree_rulenum_k_begin__keyword_begin,
  redtree_rulenum_k_if__keyword_if,
  redtree_rulenum_k_unless__keyword_unless,
  redtree_rulenum_k_while__keyword_while,
  redtree_rulenum_k_until__keyword_until,
  redtree_rulenum_k_case__keyword_case,
  redtree_rulenum_k_for__keyword_for,
  redtree_rulenum_k_class__keyword_class,
  redtree_rulenum_k_module__keyword_module,
  redtree_rulenum_k_def__keyword_def,
  redtree_rulenum_k_end__keyword_end,
  redtree_rulenum_then__term,
  redtree_rulenum_then__keyword_then,
  redtree_rulenum_then__term__keyword_then,
  redtree_rulenum_do__term,
  redtree_rulenum_do__keyword_do_cond,
  redtree_rulenum_if_tail__opt_else,
  redtree_rulenum_if_tail__keyword_elsif__expr_value__then__compstmt__if_tail,
  redtree_rulenum_opt_else__none,
  redtree_rulenum_opt_else__keyword_else__compstmt,
  redtree_rulenum_for_var__lhs,
  redtree_rulenum_for_var__mlhs,
  redtree_rulenum_f_marg__f_norm_arg,
  redtree_rulenum_f_marg__tLPAREN__f_margs__rparen,
  redtree_rulenum_f_marg_list__f_marg,
  redtree_rulenum_f_marg_list__f_marg_list__COMMA__f_marg,
  redtree_rulenum_f_margs__f_marg_list,
  redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg,
  redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg__COMMA__f_marg_list,
  redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR,
  redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__COMMA__f_marg_list,
  redtree_rulenum_f_margs__tSTAR__f_norm_arg,
  redtree_rulenum_f_margs__tSTAR__f_norm_arg__COMMA__f_marg_list,
  redtree_rulenum_f_margs__tSTAR,
  redtree_rulenum_f_margs__tSTAR__COMMA__f_marg_list,
  redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__COMMA,
  redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_block_optarg__opt_f_block_arg,
  redtree_rulenum_block_param__f_block_optarg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_block_param__f_block_arg,
  redtree_rulenum_opt_block_param__none,
  redtree_rulenum_opt_block_param__block_param_def,
  redtree_rulenum_block_param_def__OR__opt_bv_decl__OR,
  redtree_rulenum_block_param_def__tOROP,
  redtree_rulenum_block_param_def__OR__block_param__opt_bv_decl__OR,
  redtree_rulenum_opt_bv_decl__none,
  redtree_rulenum_opt_bv_decl__SEMI__bv_decls,
  redtree_rulenum_bv_decls__bvar,
  redtree_rulenum_bv_decls__bv_decls__COMMA__bvar,
  redtree_rulenum_bvar__tIDENTIFIER,
  redtree_rulenum_bvar__f_bad_arg,
  redtree_rulenum_lambda__f_larglist__lambda_body,
  redtree_rulenum_f_larglist__LR__f_args__opt_bv_decl__rparen,
  redtree_rulenum_f_larglist__f_args,
  redtree_rulenum_lambda_body__tLAMBEG__compstmt__RC,
  redtree_rulenum_lambda_body__keyword_do_LAMBDA__compstmt__keyword_end,
  redtree_rulenum_do_block__keyword_do_block__opt_block_param__compstmt__keyword_end,
  redtree_rulenum_block_call__command__do_block,
  redtree_rulenum_block_call__block_call__DOT__operation2__opt_paren_args,
  redtree_rulenum_block_call__block_call__tCOLON2__operation2__opt_paren_args,
  redtree_rulenum_method_call__operation__paren_args,
  redtree_rulenum_method_call__primary_value__DOT__operation2__opt_paren_args,
  redtree_rulenum_method_call__primary_value__tCOLON2__operation2__paren_args,
  redtree_rulenum_method_call__primary_value__tCOLON2__operation3,
  redtree_rulenum_method_call__primary_value__DOT__paren_args,
  redtree_rulenum_method_call__primary_value__tCOLON2__paren_args,
  redtree_rulenum_method_call__keyword_super__paren_args,
  redtree_rulenum_method_call__keyword_super,
  redtree_rulenum_method_call__primary_value__LS__opt_call_args__rbracket,
  redtree_rulenum_brace_block__LC__opt_block_param__compstmt__RC,
  redtree_rulenum_brace_block__keyword_do__opt_block_param__compstmt__keyword_end,
  redtree_rulenum_case_body__keyword_when__args__then__compstmt__cases,
  redtree_rulenum_cases__opt_else,
  redtree_rulenum_cases__case_body,
  redtree_rulenum_opt_rescue__keyword_rescue__exc_list__exc_var__then__compstmt__opt_rescue,
  redtree_rulenum_opt_rescue__none,
  redtree_rulenum_exc_list__arg_value,
  redtree_rulenum_exc_list__mrhs,
  redtree_rulenum_exc_list__none,
  redtree_rulenum_exc_var__tASSOC__lhs,
  redtree_rulenum_exc_var__none,
  redtree_rulenum_opt_ensure__keyword_ensure__compstmt,
  redtree_rulenum_opt_ensure__none,
  redtree_rulenum_literal__numeric,
  redtree_rulenum_literal__symbol,
  redtree_rulenum_literal__dsym,
  redtree_rulenum_strings__string,
  redtree_rulenum_string__tCHAR,
  redtree_rulenum_string__string1,
  redtree_rulenum_string__string__string1,
  redtree_rulenum_string1__tSTRING_BEG__string_contents__tSTRING_END,
  redtree_rulenum_xstring__tXSTRING_BEG__xstring_contents__tSTRING_END,
  redtree_rulenum_regexp__tREGEXP_BEG__regexp_contents__tREGEXP_END,
  redtree_rulenum_words__tWORDS_BEG__SP__tSTRING_END,
  redtree_rulenum_words__tWORDS_BEG__word_list__tSTRING_END,
  redtree_rulenum_word_list__,
  redtree_rulenum_word_list__word_list__word__SP,
  redtree_rulenum_word__string_content,
  redtree_rulenum_word__word__string_content,
  redtree_rulenum_qwords__tQWORDS_BEG__SP__tSTRING_END,
  redtree_rulenum_qwords__tQWORDS_BEG__qword_list__tSTRING_END,
  redtree_rulenum_qword_list__,
  redtree_rulenum_qword_list__qword_list__tSTRING_CONTENT__SP,
  redtree_rulenum_string_contents__,
  redtree_rulenum_string_contents__string_contents__string_content,
  redtree_rulenum_xstring_contents__,
  redtree_rulenum_xstring_contents__xstring_contents__string_content,
  redtree_rulenum_regexp_contents__,
  redtree_rulenum_regexp_contents__regexp_contents__string_content,
  redtree_rulenum_string_content__tSTRING_CONTENT,
  redtree_rulenum_string_content__tSTRING_DVAR__string_dvar,
  redtree_rulenum_string_content__tSTRING_DBEG__compstmt__RC,
  redtree_rulenum_string_dvar__tGVAR,
  redtree_rulenum_string_dvar__tIVAR,
  redtree_rulenum_string_dvar__tCVAR,
  redtree_rulenum_string_dvar__backref,
  redtree_rulenum_symbol__tSYMBEG__sym,
  redtree_rulenum_sym__fname,
  redtree_rulenum_sym__tIVAR,
  redtree_rulenum_sym__tGVAR,
  redtree_rulenum_sym__tCVAR,
  redtree_rulenum_dsym__tSYMBEG__xstring_contents__tSTRING_END,
  redtree_rulenum_numeric__tINTEGER,
  redtree_rulenum_numeric__tFLOAT,
  redtree_rulenum_numeric__tUMINUS_NUM__tINTEGER,
  redtree_rulenum_numeric__tUMINUS_NUM__tFLOAT,
  redtree_rulenum_user_variable__tIDENTIFIER,
  redtree_rulenum_user_variable__tIVAR,
  redtree_rulenum_user_variable__tGVAR,
  redtree_rulenum_user_variable__tCONSTANT,
  redtree_rulenum_user_variable__tCVAR,
  redtree_rulenum_keyword_variable__keyword_nil,
  redtree_rulenum_keyword_variable__keyword_self,
  redtree_rulenum_keyword_variable__keyword_true,
  redtree_rulenum_keyword_variable__keyword_false,
  redtree_rulenum_keyword_variable__keyword_FILE,
  redtree_rulenum_keyword_variable__keyword_LINE,
  redtree_rulenum_keyword_variable__keyword_ENCODING,
  redtree_rulenum_var_ref__user_variable,
  redtree_rulenum_vcall__user_variable,
  redtree_rulenum_var_ref__keyword_variable,
  redtree_rulenum_var_lhs__user_variable,
  redtree_rulenum_var_field__keyword_variable,
  redtree_rulenum_backref__tNTH_REF,
  redtree_rulenum_backref__tBACK_REF,
  redtree_rulenum_superclass__term,
  redtree_rulenum_superclass__LT__expr_value__term,
  redtree_rulenum_superclass__error__term,
  redtree_rulenum_f_arglist__LR__f_args__rparen,
  redtree_rulenum_f_arglist__f_args__term,
  redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__COMMA__f_optarg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_optarg__opt_f_block_arg,
  redtree_rulenum_f_args__f_optarg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_rest_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_rest_arg__COMMA__f_arg__opt_f_block_arg,
  redtree_rulenum_f_args__f_block_arg,
  redtree_rulenum_f_args__,
  redtree_rulenum_f_bad_arg__tCONSTANT,
  redtree_rulenum_f_bad_arg__tIVAR,
  redtree_rulenum_f_bad_arg__tGVAR,
  redtree_rulenum_f_bad_arg__tCVAR,
  redtree_rulenum_f_norm_arg__f_bad_arg,
  redtree_rulenum_f_norm_arg__tIDENTIFIER,
  redtree_rulenum_f_arg_item__f_norm_arg,
  redtree_rulenum_f_arg_item__tLPAREN__f_margs__rparen,
  redtree_rulenum_f_arg__f_arg_item,
  redtree_rulenum_f_arg__f_arg__COMMA__f_arg_item,
  redtree_rulenum_f_opt__tIDENTIFIER__EQ__arg_value,
  redtree_rulenum_f_block_opt__tIDENTIFIER__EQ__primary_value,
  redtree_rulenum_f_block_optarg__f_block_opt,
  redtree_rulenum_f_block_optarg__f_block_optarg__COMMA__f_block_opt,
  redtree_rulenum_f_optarg__f_opt,
  redtree_rulenum_f_optarg__f_optarg__COMMA__f_opt,
  redtree_rulenum_restarg_mark__TIMES,
  redtree_rulenum_restarg_mark__tSTAR,
  redtree_rulenum_f_rest_arg__restarg_mark__tIDENTIFIER,
  redtree_rulenum_f_rest_arg__restarg_mark,
  redtree_rulenum_blkarg_mark__AND,
  redtree_rulenum_blkarg_mark__tAMPER,
  redtree_rulenum_f_block_arg__blkarg_mark__tIDENTIFIER,
  redtree_rulenum_opt_f_block_arg__COMMA__f_block_arg,
  redtree_rulenum_opt_f_block_arg__none,
  redtree_rulenum_singleton__var_ref,
  redtree_rulenum_singleton__LR__expr__rparen,
  redtree_rulenum_assoc_list__none,
  redtree_rulenum_assoc_list__assocs__trailer,
  redtree_rulenum_assocs__assoc,
  redtree_rulenum_assocs__assocs__COMMA__assoc,
  redtree_rulenum_assoc__arg_value__tASSOC__arg_value,
  redtree_rulenum_assoc__tLABEL__arg_value,
  redtree_rulenum_operation__tIDENTIFIER,
  redtree_rulenum_operation__tCONSTANT,
  redtree_rulenum_operation__tFID,
  redtree_rulenum_operation2__tIDENTIFIER,
  redtree_rulenum_operation2__tCONSTANT,
  redtree_rulenum_operation2__tFID,
  redtree_rulenum_operation2__op,
  redtree_rulenum_operation3__tIDENTIFIER,
  redtree_rulenum_operation3__tFID,
  redtree_rulenum_operation3__op,
  redtree_rulenum_dot_or_colon__DOT,
  redtree_rulenum_dot_or_colon__tCOLON2,
  redtree_rulenum_opt_terms__,
  redtree_rulenum_opt_terms__terms,
  redtree_rulenum_opt_nl__,
  redtree_rulenum_opt_nl__NL,
  redtree_rulenum_rparen__opt_nl__RR,
  redtree_rulenum_rbracket__opt_nl__RS,
  redtree_rulenum_trailer__,
  redtree_rulenum_trailer__NL,
  redtree_rulenum_trailer__COMMA,
  redtree_rulenum_term__SEMI,
  redtree_rulenum_term__NL,
  redtree_rulenum_terms__term,
  redtree_rulenum_terms__terms__SEMI,
  redtree_rulenum_none__,
  redtree_rulenum_magic_comment,
  redtree_rulenum_MAX_RULES,
};

static void
redtree_init_eventids1(VALUE self) {
  VALUE arr = rb_ary_new2(redtree_rulenum_MAX_RULES);
  VALUE nodes_module = rb_define_module_under(self, "Nodes");
  rb_define_const(self, "Names", arr);
  rb_define_const(self, "UNUSED", INT2FIX(redtree_rulenum_UNUSED));
  rb_ary_push(arr, rb_str_new("UNUSED", 6));
  rb_define_const(self, "Program_TopCompstmt", INT2FIX(redtree_rulenum_program__top_compstmt));
  rb_ary_push(arr, rb_str_new("Program_TopCompstmt", 19));
  rb_define_const(self, "TopCompstmt_TopStmts_OptTerms", INT2FIX(redtree_rulenum_top_compstmt__top_stmts__opt_terms));
  rb_ary_push(arr, rb_str_new("TopCompstmt_TopStmts_OptTerms", 29));
  rb_define_const(self, "TopStmts_None", INT2FIX(redtree_rulenum_top_stmts__none));
  rb_ary_push(arr, rb_str_new("TopStmts_None", 13));
  rb_define_const(self, "TopStmts_TopStmt", INT2FIX(redtree_rulenum_top_stmts__top_stmt));
  rb_ary_push(arr, rb_str_new("TopStmts_TopStmt", 16));
  rb_define_const(self, "TopStmts_TopStmts_Terms_TopStmt", INT2FIX(redtree_rulenum_top_stmts__top_stmts__terms__top_stmt));
  rb_ary_push(arr, rb_str_new("TopStmts_TopStmts_Terms_TopStmt", 31));
  rb_define_const(self, "TopStmts_Error_TopStmt", INT2FIX(redtree_rulenum_top_stmts__error__top_stmt));
  rb_ary_push(arr, rb_str_new("TopStmts_Error_TopStmt", 22));
  rb_define_const(self, "TopStmt_Stmt", INT2FIX(redtree_rulenum_top_stmt__stmt));
  rb_ary_push(arr, rb_str_new("TopStmt_Stmt", 12));
  rb_define_const(self, "TopStmt_KeywordBEGIN_LC_TopCompstmt_RC", INT2FIX(redtree_rulenum_top_stmt__keyword_BEGIN__LC__top_compstmt__RC));
  rb_ary_push(arr, rb_str_new("TopStmt_KeywordBEGIN_LC_TopCompstmt_RC", 38));
  rb_define_const(self, "Bodystmt_Compstmt_OptRescue_OptElse_OptEnsure", INT2FIX(redtree_rulenum_bodystmt__compstmt__opt_rescue__opt_else__opt_ensure));
  rb_ary_push(arr, rb_str_new("Bodystmt_Compstmt_OptRescue_OptElse_OptEnsure", 45));
  rb_define_const(self, "Compstmt_Stmts_OptTerms", INT2FIX(redtree_rulenum_compstmt__stmts__opt_terms));
  rb_ary_push(arr, rb_str_new("Compstmt_Stmts_OptTerms", 23));
  rb_define_const(self, "Stmts_None", INT2FIX(redtree_rulenum_stmts__none));
  rb_ary_push(arr, rb_str_new("Stmts_None", 10));
  rb_define_const(self, "Stmts_Stmt", INT2FIX(redtree_rulenum_stmts__stmt));
  rb_ary_push(arr, rb_str_new("Stmts_Stmt", 10));
  rb_define_const(self, "Stmts_Stmts_Terms_Stmt", INT2FIX(redtree_rulenum_stmts__stmts__terms__stmt));
  rb_ary_push(arr, rb_str_new("Stmts_Stmts_Terms_Stmt", 22));
  rb_define_const(self, "Stmts_Error_Stmt", INT2FIX(redtree_rulenum_stmts__error__stmt));
  rb_ary_push(arr, rb_str_new("Stmts_Error_Stmt", 16));
  rb_define_const(self, "Stmt_KeywordAlias_Fitem_Fitem", INT2FIX(redtree_rulenum_stmt__keyword_alias__fitem__fitem));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordAlias_Fitem_Fitem", 29));
  rb_define_const(self, "Stmt_KeywordAlias_TGVAR_TGVAR", INT2FIX(redtree_rulenum_stmt__keyword_alias__tGVAR__tGVAR));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordAlias_TGVAR_TGVAR", 29));
  rb_define_const(self, "Stmt_KeywordAlias_TGVAR_TBACKREF", INT2FIX(redtree_rulenum_stmt__keyword_alias__tGVAR__tBACK_REF));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordAlias_TGVAR_TBACKREF", 32));
  rb_define_const(self, "Stmt_KeywordAlias_TGVAR_TNTHREF", INT2FIX(redtree_rulenum_stmt__keyword_alias__tGVAR__tNTH_REF));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordAlias_TGVAR_TNTHREF", 31));
  rb_define_const(self, "Stmt_KeywordUndef_UndefList", INT2FIX(redtree_rulenum_stmt__keyword_undef__undef_list));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordUndef_UndefList", 27));
  rb_define_const(self, "Stmt_Stmt_ModifierIf_ExprValue", INT2FIX(redtree_rulenum_stmt__stmt__modifier_if__expr_value));
  rb_ary_push(arr, rb_str_new("Stmt_Stmt_ModifierIf_ExprValue", 30));
  rb_define_const(self, "Stmt_Stmt_ModifierUnless_ExprValue", INT2FIX(redtree_rulenum_stmt__stmt__modifier_unless__expr_value));
  rb_ary_push(arr, rb_str_new("Stmt_Stmt_ModifierUnless_ExprValue", 34));
  rb_define_const(self, "Stmt_Stmt_ModifierWhile_ExprValue", INT2FIX(redtree_rulenum_stmt__stmt__modifier_while__expr_value));
  rb_ary_push(arr, rb_str_new("Stmt_Stmt_ModifierWhile_ExprValue", 33));
  rb_define_const(self, "Stmt_Stmt_ModifierUntil_ExprValue", INT2FIX(redtree_rulenum_stmt__stmt__modifier_until__expr_value));
  rb_ary_push(arr, rb_str_new("Stmt_Stmt_ModifierUntil_ExprValue", 33));
  rb_define_const(self, "Stmt_Stmt_ModifierRescue_Stmt", INT2FIX(redtree_rulenum_stmt__stmt__modifier_rescue__stmt));
  rb_ary_push(arr, rb_str_new("Stmt_Stmt_ModifierRescue_Stmt", 29));
  rb_define_const(self, "Stmt_KeywordEND_LC_Compstmt_RC", INT2FIX(redtree_rulenum_stmt__keyword_END__LC__compstmt__RC));
  rb_ary_push(arr, rb_str_new("Stmt_KeywordEND_LC_Compstmt_RC", 30));
  rb_define_const(self, "Stmt_CommandAsgn", INT2FIX(redtree_rulenum_stmt__command_asgn));
  rb_ary_push(arr, rb_str_new("Stmt_CommandAsgn", 16));
  rb_define_const(self, "Stmt_Mlhs_EQ_CommandCall", INT2FIX(redtree_rulenum_stmt__mlhs__EQ__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_Mlhs_EQ_CommandCall", 24));
  rb_define_const(self, "Stmt_VarLhs_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__var_lhs__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_VarLhs_TOPASGN_CommandCall", 31));
  rb_define_const(self, "Stmt_PrimaryValue_LS_OptCallArgs_Rbracket_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_PrimaryValue_LS_OptCallArgs_Rbracket_TOPASGN_CommandCall", 61));
  rb_define_const(self, "Stmt_PrimaryValue_DOT_TIDENTIFIER_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__primary_value__DOT__tIDENTIFIER__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_PrimaryValue_DOT_TIDENTIFIER_TOPASGN_CommandCall", 53));
  rb_define_const(self, "Stmt_PrimaryValue_DOT_TCONSTANT_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__primary_value__DOT__tCONSTANT__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_PrimaryValue_DOT_TCONSTANT_TOPASGN_CommandCall", 51));
  rb_define_const(self, "Stmt_PrimaryValue_TCOLON2_TCONSTANT_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_PrimaryValue_TCOLON2_TCONSTANT_TOPASGN_CommandCall", 55));
  rb_define_const(self, "Stmt_PrimaryValue_TCOLON2_TIDENTIFIER_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_PrimaryValue_TCOLON2_TIDENTIFIER_TOPASGN_CommandCall", 57));
  rb_define_const(self, "Stmt_Backref_TOPASGN_CommandCall", INT2FIX(redtree_rulenum_stmt__backref__tOP_ASGN__command_call));
  rb_ary_push(arr, rb_str_new("Stmt_Backref_TOPASGN_CommandCall", 32));
  rb_define_const(self, "Stmt_Lhs_EQ_Mrhs", INT2FIX(redtree_rulenum_stmt__lhs__EQ__mrhs));
  rb_ary_push(arr, rb_str_new("Stmt_Lhs_EQ_Mrhs", 16));
  rb_define_const(self, "Stmt_Mlhs_EQ_ArgValue", INT2FIX(redtree_rulenum_stmt__mlhs__EQ__arg_value));
  rb_ary_push(arr, rb_str_new("Stmt_Mlhs_EQ_ArgValue", 21));
  rb_define_const(self, "Stmt_Mlhs_EQ_Mrhs", INT2FIX(redtree_rulenum_stmt__mlhs__EQ__mrhs));
  rb_ary_push(arr, rb_str_new("Stmt_Mlhs_EQ_Mrhs", 17));
  rb_define_const(self, "Stmt_Expr", INT2FIX(redtree_rulenum_stmt__expr));
  rb_ary_push(arr, rb_str_new("Stmt_Expr", 9));
  rb_define_const(self, "CommandAsgn_Lhs_EQ_CommandCall", INT2FIX(redtree_rulenum_command_asgn__lhs__EQ__command_call));
  rb_ary_push(arr, rb_str_new("CommandAsgn_Lhs_EQ_CommandCall", 30));
  rb_define_const(self, "CommandAsgn_Lhs_EQ_CommandAsgn", INT2FIX(redtree_rulenum_command_asgn__lhs__EQ__command_asgn));
  rb_ary_push(arr, rb_str_new("CommandAsgn_Lhs_EQ_CommandAsgn", 30));
  rb_define_const(self, "Expr_CommandCall", INT2FIX(redtree_rulenum_expr__command_call));
  rb_ary_push(arr, rb_str_new("Expr_CommandCall", 16));
  rb_define_const(self, "Expr_Expr_KeywordAnd_Expr", INT2FIX(redtree_rulenum_expr__expr__keyword_and__expr));
  rb_ary_push(arr, rb_str_new("Expr_Expr_KeywordAnd_Expr", 25));
  rb_define_const(self, "Expr_Expr_KeywordOr_Expr", INT2FIX(redtree_rulenum_expr__expr__keyword_or__expr));
  rb_ary_push(arr, rb_str_new("Expr_Expr_KeywordOr_Expr", 24));
  rb_define_const(self, "Expr_KeywordNot_OptNl_Expr", INT2FIX(redtree_rulenum_expr__keyword_not__opt_nl__expr));
  rb_ary_push(arr, rb_str_new("Expr_KeywordNot_OptNl_Expr", 26));
  rb_define_const(self, "Expr_BANG_CommandCall", INT2FIX(redtree_rulenum_expr__BANG__command_call));
  rb_ary_push(arr, rb_str_new("Expr_BANG_CommandCall", 21));
  rb_define_const(self, "Expr_Arg", INT2FIX(redtree_rulenum_expr__arg));
  rb_ary_push(arr, rb_str_new("Expr_Arg", 8));
  rb_define_const(self, "ExprValue_Expr", INT2FIX(redtree_rulenum_expr_value__expr));
  rb_ary_push(arr, rb_str_new("ExprValue_Expr", 14));
  rb_define_const(self, "CommandCall_Command", INT2FIX(redtree_rulenum_command_call__command));
  rb_ary_push(arr, rb_str_new("CommandCall_Command", 19));
  rb_define_const(self, "CommandCall_BlockCommand", INT2FIX(redtree_rulenum_command_call__block_command));
  rb_ary_push(arr, rb_str_new("CommandCall_BlockCommand", 24));
  rb_define_const(self, "BlockCommand_BlockCall", INT2FIX(redtree_rulenum_block_command__block_call));
  rb_ary_push(arr, rb_str_new("BlockCommand_BlockCall", 22));
  rb_define_const(self, "BlockCommand_BlockCall_DOT_Operation2_CommandArgs", INT2FIX(redtree_rulenum_block_command__block_call__DOT__operation2__command_args));
  rb_ary_push(arr, rb_str_new("BlockCommand_BlockCall_DOT_Operation2_CommandArgs", 49));
  rb_define_const(self, "BlockCommand_BlockCall_TCOLON2_Operation2_CommandArgs", INT2FIX(redtree_rulenum_block_command__block_call__tCOLON2__operation2__command_args));
  rb_ary_push(arr, rb_str_new("BlockCommand_BlockCall_TCOLON2_Operation2_CommandArgs", 53));
  rb_define_const(self, "CmdBraceBlock_TLBRACEARG_OptBlockParam_Compstmt_RC", INT2FIX(redtree_rulenum_cmd_brace_block__tLBRACE_ARG__opt_block_param__compstmt__RC));
  rb_ary_push(arr, rb_str_new("CmdBraceBlock_TLBRACEARG_OptBlockParam_Compstmt_RC", 50));
  rb_define_const(self, "Command_Operation_CommandArgs", INT2FIX(redtree_rulenum_command__operation__command_args));
  rb_ary_push(arr, rb_str_new("Command_Operation_CommandArgs", 29));
  rb_define_const(self, "Command_Operation_CommandArgs_CmdBraceBlock", INT2FIX(redtree_rulenum_command__operation__command_args__cmd_brace_block));
  rb_ary_push(arr, rb_str_new("Command_Operation_CommandArgs_CmdBraceBlock", 43));
  rb_define_const(self, "Command_PrimaryValue_DOT_Operation2_CommandArgs", INT2FIX(redtree_rulenum_command__primary_value__DOT__operation2__command_args));
  rb_ary_push(arr, rb_str_new("Command_PrimaryValue_DOT_Operation2_CommandArgs", 47));
  rb_define_const(self, "Command_PrimaryValue_DOT_Operation2_CommandArgs_CmdBraceBlock", INT2FIX(redtree_rulenum_command__primary_value__DOT__operation2__command_args__cmd_brace_block));
  rb_ary_push(arr, rb_str_new("Command_PrimaryValue_DOT_Operation2_CommandArgs_CmdBraceBlock", 61));
  rb_define_const(self, "Command_PrimaryValue_TCOLON2_Operation2_CommandArgs", INT2FIX(redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args));
  rb_ary_push(arr, rb_str_new("Command_PrimaryValue_TCOLON2_Operation2_CommandArgs", 51));
  rb_define_const(self, "Command_PrimaryValue_TCOLON2_Operation2_CommandArgs_CmdBraceBlock", INT2FIX(redtree_rulenum_command__primary_value__tCOLON2__operation2__command_args__cmd_brace_block));
  rb_ary_push(arr, rb_str_new("Command_PrimaryValue_TCOLON2_Operation2_CommandArgs_CmdBraceBlock", 65));
  rb_define_const(self, "Command_KeywordSuper_CommandArgs", INT2FIX(redtree_rulenum_command__keyword_super__command_args));
  rb_ary_push(arr, rb_str_new("Command_KeywordSuper_CommandArgs", 32));
  rb_define_const(self, "Command_KeywordYield_CommandArgs", INT2FIX(redtree_rulenum_command__keyword_yield__command_args));
  rb_ary_push(arr, rb_str_new("Command_KeywordYield_CommandArgs", 32));
  rb_define_const(self, "Command_KeywordReturn_CallArgs", INT2FIX(redtree_rulenum_command__keyword_return__call_args));
  rb_ary_push(arr, rb_str_new("Command_KeywordReturn_CallArgs", 30));
  rb_define_const(self, "Command_KeywordBreak_CallArgs", INT2FIX(redtree_rulenum_command__keyword_break__call_args));
  rb_ary_push(arr, rb_str_new("Command_KeywordBreak_CallArgs", 29));
  rb_define_const(self, "Command_KeywordNext_CallArgs", INT2FIX(redtree_rulenum_command__keyword_next__call_args));
  rb_ary_push(arr, rb_str_new("Command_KeywordNext_CallArgs", 28));
  rb_define_const(self, "Mlhs_MlhsBasic", INT2FIX(redtree_rulenum_mlhs__mlhs_basic));
  rb_ary_push(arr, rb_str_new("Mlhs_MlhsBasic", 14));
  rb_define_const(self, "Mlhs_TLPAREN_MlhsInner_Rparen", INT2FIX(redtree_rulenum_mlhs__tLPAREN__mlhs_inner__rparen));
  rb_ary_push(arr, rb_str_new("Mlhs_TLPAREN_MlhsInner_Rparen", 29));
  rb_define_const(self, "MlhsInner_MlhsBasic", INT2FIX(redtree_rulenum_mlhs_inner__mlhs_basic));
  rb_ary_push(arr, rb_str_new("MlhsInner_MlhsBasic", 19));
  rb_define_const(self, "MlhsInner_TLPAREN_MlhsInner_Rparen", INT2FIX(redtree_rulenum_mlhs_inner__tLPAREN__mlhs_inner__rparen));
  rb_ary_push(arr, rb_str_new("MlhsInner_TLPAREN_MlhsInner_Rparen", 34));
  rb_define_const(self, "MlhsBasic_MlhsHead", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead", 18));
  rb_define_const(self, "MlhsBasic_MlhsHead_MlhsItem", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head__mlhs_item));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead_MlhsItem", 27));
  rb_define_const(self, "MlhsBasic_MlhsHead_TSTAR_MlhsNode", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead_TSTAR_MlhsNode", 33));
  rb_define_const(self, "MlhsBasic_MlhsHead_TSTAR_MlhsNode_COMMA_MlhsPost", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__mlhs_node__COMMA__mlhs_post));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead_TSTAR_MlhsNode_COMMA_MlhsPost", 48));
  rb_define_const(self, "MlhsBasic_MlhsHead_TSTAR", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head__tSTAR));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead_TSTAR", 24));
  rb_define_const(self, "MlhsBasic_MlhsHead_TSTAR_COMMA_MlhsPost", INT2FIX(redtree_rulenum_mlhs_basic__mlhs_head__tSTAR__COMMA__mlhs_post));
  rb_ary_push(arr, rb_str_new("MlhsBasic_MlhsHead_TSTAR_COMMA_MlhsPost", 39));
  rb_define_const(self, "MlhsBasic_TSTAR_MlhsNode", INT2FIX(redtree_rulenum_mlhs_basic__tSTAR__mlhs_node));
  rb_ary_push(arr, rb_str_new("MlhsBasic_TSTAR_MlhsNode", 24));
  rb_define_const(self, "MlhsBasic_TSTAR_MlhsNode_COMMA_MlhsPost", INT2FIX(redtree_rulenum_mlhs_basic__tSTAR__mlhs_node__COMMA__mlhs_post));
  rb_ary_push(arr, rb_str_new("MlhsBasic_TSTAR_MlhsNode_COMMA_MlhsPost", 39));
  rb_define_const(self, "MlhsBasic_TSTAR", INT2FIX(redtree_rulenum_mlhs_basic__tSTAR));
  rb_ary_push(arr, rb_str_new("MlhsBasic_TSTAR", 15));
  rb_define_const(self, "MlhsBasic_TSTAR_COMMA_MlhsPost", INT2FIX(redtree_rulenum_mlhs_basic__tSTAR__COMMA__mlhs_post));
  rb_ary_push(arr, rb_str_new("MlhsBasic_TSTAR_COMMA_MlhsPost", 30));
  rb_define_const(self, "MlhsItem_MlhsNode", INT2FIX(redtree_rulenum_mlhs_item__mlhs_node));
  rb_ary_push(arr, rb_str_new("MlhsItem_MlhsNode", 17));
  rb_define_const(self, "MlhsItem_TLPAREN_MlhsInner_Rparen", INT2FIX(redtree_rulenum_mlhs_item__tLPAREN__mlhs_inner__rparen));
  rb_ary_push(arr, rb_str_new("MlhsItem_TLPAREN_MlhsInner_Rparen", 33));
  rb_define_const(self, "MlhsHead_MlhsItem_COMMA", INT2FIX(redtree_rulenum_mlhs_head__mlhs_item__COMMA));
  rb_ary_push(arr, rb_str_new("MlhsHead_MlhsItem_COMMA", 23));
  rb_define_const(self, "MlhsHead_MlhsHead_MlhsItem_COMMA", INT2FIX(redtree_rulenum_mlhs_head__mlhs_head__mlhs_item__COMMA));
  rb_ary_push(arr, rb_str_new("MlhsHead_MlhsHead_MlhsItem_COMMA", 32));
  rb_define_const(self, "MlhsPost_MlhsItem", INT2FIX(redtree_rulenum_mlhs_post__mlhs_item));
  rb_ary_push(arr, rb_str_new("MlhsPost_MlhsItem", 17));
  rb_define_const(self, "MlhsPost_MlhsPost_COMMA_MlhsItem", INT2FIX(redtree_rulenum_mlhs_post__mlhs_post__COMMA__mlhs_item));
  rb_ary_push(arr, rb_str_new("MlhsPost_MlhsPost_COMMA_MlhsItem", 32));
  rb_define_const(self, "MlhsNode_UserVariable", INT2FIX(redtree_rulenum_mlhs_node__user_variable));
  rb_ary_push(arr, rb_str_new("MlhsNode_UserVariable", 21));
  rb_define_const(self, "MlhsNode_KeywordVariable", INT2FIX(redtree_rulenum_mlhs_node__keyword_variable));
  rb_ary_push(arr, rb_str_new("MlhsNode_KeywordVariable", 24));
  rb_define_const(self, "MlhsNode_PrimaryValue_LS_OptCallArgs_Rbracket", INT2FIX(redtree_rulenum_mlhs_node__primary_value__LS__opt_call_args__rbracket));
  rb_ary_push(arr, rb_str_new("MlhsNode_PrimaryValue_LS_OptCallArgs_Rbracket", 45));
  rb_define_const(self, "MlhsNode_PrimaryValue_DOT_TIDENTIFIER", INT2FIX(redtree_rulenum_mlhs_node__primary_value__DOT__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("MlhsNode_PrimaryValue_DOT_TIDENTIFIER", 37));
  rb_define_const(self, "MlhsNode_PrimaryValue_TCOLON2_TIDENTIFIER", INT2FIX(redtree_rulenum_mlhs_node__primary_value__tCOLON2__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("MlhsNode_PrimaryValue_TCOLON2_TIDENTIFIER", 41));
  rb_define_const(self, "MlhsNode_PrimaryValue_DOT_TCONSTANT", INT2FIX(redtree_rulenum_mlhs_node__primary_value__DOT__tCONSTANT));
  rb_ary_push(arr, rb_str_new("MlhsNode_PrimaryValue_DOT_TCONSTANT", 35));
  rb_define_const(self, "MlhsNode_PrimaryValue_TCOLON3_TCONSTANT", INT2FIX(redtree_rulenum_mlhs_node__primary_value__tCOLON3__tCONSTANT));
  rb_ary_push(arr, rb_str_new("MlhsNode_PrimaryValue_TCOLON3_TCONSTANT", 39));
  rb_define_const(self, "MlhsNode_TCOLON3_TCONSTANT", INT2FIX(redtree_rulenum_mlhs_node__tCOLON3__tCONSTANT));
  rb_ary_push(arr, rb_str_new("MlhsNode_TCOLON3_TCONSTANT", 26));
  rb_define_const(self, "MlhsNode_Backref", INT2FIX(redtree_rulenum_mlhs_node__backref));
  rb_ary_push(arr, rb_str_new("MlhsNode_Backref", 16));
  rb_define_const(self, "Lhs_UserVariable", INT2FIX(redtree_rulenum_lhs__user_variable));
  rb_ary_push(arr, rb_str_new("Lhs_UserVariable", 16));
  rb_define_const(self, "Lhs_KeywordVariable", INT2FIX(redtree_rulenum_lhs__keyword_variable));
  rb_ary_push(arr, rb_str_new("Lhs_KeywordVariable", 19));
  rb_define_const(self, "Lhs_PrimaryValue_LS_OptCallArgs_Rbracket", INT2FIX(redtree_rulenum_lhs__primary_value__LS__opt_call_args__rbracket));
  rb_ary_push(arr, rb_str_new("Lhs_PrimaryValue_LS_OptCallArgs_Rbracket", 40));
  rb_define_const(self, "Lhs_PrimaryValue_DOT_TIDENTIFIER", INT2FIX(redtree_rulenum_lhs__primary_value__DOT__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Lhs_PrimaryValue_DOT_TIDENTIFIER", 32));
  rb_define_const(self, "Lhs_PrimaryValue_TCOLON2_TIDENTIFIER", INT2FIX(redtree_rulenum_lhs__primary_value__tCOLON2__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Lhs_PrimaryValue_TCOLON2_TIDENTIFIER", 36));
  rb_define_const(self, "Lhs_PrimaryValue_DOT_TCONSTANT", INT2FIX(redtree_rulenum_lhs__primary_value__DOT__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Lhs_PrimaryValue_DOT_TCONSTANT", 30));
  rb_define_const(self, "Lhs_PrimaryValue_TCOLON3_TCONSTANT", INT2FIX(redtree_rulenum_lhs__primary_value__tCOLON3__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Lhs_PrimaryValue_TCOLON3_TCONSTANT", 34));
  rb_define_const(self, "Lhs_TCOLON3_TCONSTANT", INT2FIX(redtree_rulenum_lhs__tCOLON3__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Lhs_TCOLON3_TCONSTANT", 21));
  rb_define_const(self, "Lhs_Backref", INT2FIX(redtree_rulenum_lhs__backref));
  rb_ary_push(arr, rb_str_new("Lhs_Backref", 11));
  rb_define_const(self, "Cname_TIDENTIFIER", INT2FIX(redtree_rulenum_cname__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Cname_TIDENTIFIER", 17));
  rb_define_const(self, "Cname_TCONSTANT", INT2FIX(redtree_rulenum_cname__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Cname_TCONSTANT", 15));
  rb_define_const(self, "Cpath_TCOLON3_Cname", INT2FIX(redtree_rulenum_cpath__tCOLON3__cname));
  rb_ary_push(arr, rb_str_new("Cpath_TCOLON3_Cname", 19));
  rb_define_const(self, "Cpath_Cname", INT2FIX(redtree_rulenum_cpath__cname));
  rb_ary_push(arr, rb_str_new("Cpath_Cname", 11));
  rb_define_const(self, "Cpath_PrimaryValue_TCOLON2_Cname", INT2FIX(redtree_rulenum_cpath__primary_value__tCOLON2__cname));
  rb_ary_push(arr, rb_str_new("Cpath_PrimaryValue_TCOLON2_Cname", 32));
  rb_define_const(self, "Fname_TIDENTIFIER", INT2FIX(redtree_rulenum_fname__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Fname_TIDENTIFIER", 17));
  rb_define_const(self, "Fname_TCONSTANT", INT2FIX(redtree_rulenum_fname__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Fname_TCONSTANT", 15));
  rb_define_const(self, "Fname_TFID", INT2FIX(redtree_rulenum_fname__tFID));
  rb_ary_push(arr, rb_str_new("Fname_TFID", 10));
  rb_define_const(self, "Fname_Op", INT2FIX(redtree_rulenum_fname__op));
  rb_ary_push(arr, rb_str_new("Fname_Op", 8));
  rb_define_const(self, "Fname_Reswords", INT2FIX(redtree_rulenum_fname__reswords));
  rb_ary_push(arr, rb_str_new("Fname_Reswords", 14));
  rb_define_const(self, "Fsym_Fname", INT2FIX(redtree_rulenum_fsym__fname));
  rb_ary_push(arr, rb_str_new("Fsym_Fname", 10));
  rb_define_const(self, "Fsym_Symbol", INT2FIX(redtree_rulenum_fsym__symbol));
  rb_ary_push(arr, rb_str_new("Fsym_Symbol", 11));
  rb_define_const(self, "Fitem_Fsym", INT2FIX(redtree_rulenum_fitem__fsym));
  rb_ary_push(arr, rb_str_new("Fitem_Fsym", 10));
  rb_define_const(self, "Fitem_Dsym", INT2FIX(redtree_rulenum_fitem__dsym));
  rb_ary_push(arr, rb_str_new("Fitem_Dsym", 10));
  rb_define_const(self, "UndefList_Fitem", INT2FIX(redtree_rulenum_undef_list__fitem));
  rb_ary_push(arr, rb_str_new("UndefList_Fitem", 15));
  rb_define_const(self, "UndefList_COMMA_Fitem", INT2FIX(redtree_rulenum_undef_list__COMMA__fitem));
  rb_ary_push(arr, rb_str_new("UndefList_COMMA_Fitem", 21));
  rb_define_const(self, "Op_OR", INT2FIX(redtree_rulenum_op__OR));
  rb_ary_push(arr, rb_str_new("Op_OR", 5));
  rb_define_const(self, "Op_CARET", INT2FIX(redtree_rulenum_op__CARET));
  rb_ary_push(arr, rb_str_new("Op_CARET", 8));
  rb_define_const(self, "Op_AND", INT2FIX(redtree_rulenum_op__AND));
  rb_ary_push(arr, rb_str_new("Op_AND", 6));
  rb_define_const(self, "Op_TCMP", INT2FIX(redtree_rulenum_op__tCMP));
  rb_ary_push(arr, rb_str_new("Op_TCMP", 7));
  rb_define_const(self, "Op_TEQ", INT2FIX(redtree_rulenum_op__tEQ));
  rb_ary_push(arr, rb_str_new("Op_TEQ", 6));
  rb_define_const(self, "Op_TEQQ", INT2FIX(redtree_rulenum_op__tEQQ));
  rb_ary_push(arr, rb_str_new("Op_TEQQ", 7));
  rb_define_const(self, "Op_TMATCH", INT2FIX(redtree_rulenum_op__tMATCH));
  rb_ary_push(arr, rb_str_new("Op_TMATCH", 9));
  rb_define_const(self, "Op_TNMATCH", INT2FIX(redtree_rulenum_op__tNMATCH));
  rb_ary_push(arr, rb_str_new("Op_TNMATCH", 10));
  rb_define_const(self, "Op_GT", INT2FIX(redtree_rulenum_op__GT));
  rb_ary_push(arr, rb_str_new("Op_GT", 5));
  rb_define_const(self, "Op_TGEQ", INT2FIX(redtree_rulenum_op__tGEQ));
  rb_ary_push(arr, rb_str_new("Op_TGEQ", 7));
  rb_define_const(self, "Op_LE", INT2FIX(redtree_rulenum_op__LE));
  rb_ary_push(arr, rb_str_new("Op_LE", 5));
  rb_define_const(self, "Op_TLEQ", INT2FIX(redtree_rulenum_op__tLEQ));
  rb_ary_push(arr, rb_str_new("Op_TLEQ", 7));
  rb_define_const(self, "Op_TNEQ", INT2FIX(redtree_rulenum_op__tNEQ));
  rb_ary_push(arr, rb_str_new("Op_TNEQ", 7));
  rb_define_const(self, "Op_TLSHFT", INT2FIX(redtree_rulenum_op__tLSHFT));
  rb_ary_push(arr, rb_str_new("Op_TLSHFT", 9));
  rb_define_const(self, "Op_TRSHFT", INT2FIX(redtree_rulenum_op__tRSHFT));
  rb_ary_push(arr, rb_str_new("Op_TRSHFT", 9));
  rb_define_const(self, "Op_PLUS", INT2FIX(redtree_rulenum_op__PLUS));
  rb_ary_push(arr, rb_str_new("Op_PLUS", 7));
  rb_define_const(self, "Op_MINUS", INT2FIX(redtree_rulenum_op__MINUS));
  rb_ary_push(arr, rb_str_new("Op_MINUS", 8));
  rb_define_const(self, "Op_TIMES", INT2FIX(redtree_rulenum_op__TIMES));
  rb_ary_push(arr, rb_str_new("Op_TIMES", 8));
  rb_define_const(self, "Op_TSTAR", INT2FIX(redtree_rulenum_op__tSTAR));
  rb_ary_push(arr, rb_str_new("Op_TSTAR", 8));
  rb_define_const(self, "Op_DIVIDE", INT2FIX(redtree_rulenum_op__DIVIDE));
  rb_ary_push(arr, rb_str_new("Op_DIVIDE", 9));
  rb_define_const(self, "Op_MOD", INT2FIX(redtree_rulenum_op__MOD));
  rb_ary_push(arr, rb_str_new("Op_MOD", 6));
  rb_define_const(self, "Op_TPOW", INT2FIX(redtree_rulenum_op__tPOW));
  rb_ary_push(arr, rb_str_new("Op_TPOW", 7));
  rb_define_const(self, "Op_BANG", INT2FIX(redtree_rulenum_op__BANG));
  rb_ary_push(arr, rb_str_new("Op_BANG", 7));
  rb_define_const(self, "Op_TILDE", INT2FIX(redtree_rulenum_op__TILDE));
  rb_ary_push(arr, rb_str_new("Op_TILDE", 8));
  rb_define_const(self, "Op_TUPLUS", INT2FIX(redtree_rulenum_op__tUPLUS));
  rb_ary_push(arr, rb_str_new("Op_TUPLUS", 9));
  rb_define_const(self, "Op_TUMINUS", INT2FIX(redtree_rulenum_op__tUMINUS));
  rb_ary_push(arr, rb_str_new("Op_TUMINUS", 10));
  rb_define_const(self, "Op_TAREF", INT2FIX(redtree_rulenum_op__tAREF));
  rb_ary_push(arr, rb_str_new("Op_TAREF", 8));
  rb_define_const(self, "Op_TASET", INT2FIX(redtree_rulenum_op__tASET));
  rb_ary_push(arr, rb_str_new("Op_TASET", 8));
  rb_define_const(self, "Op_BACKTICK", INT2FIX(redtree_rulenum_op__BACKTICK));
  rb_ary_push(arr, rb_str_new("Op_BACKTICK", 11));
  rb_define_const(self, "Reswords_Keyword_LINE", INT2FIX(redtree_rulenum_reswords__keyword__LINE__));
  rb_ary_push(arr, rb_str_new("Reswords_Keyword_LINE", 21));
  rb_define_const(self, "Reswords_Keyword_FILE", INT2FIX(redtree_rulenum_reswords__keyword__FILE__));
  rb_ary_push(arr, rb_str_new("Reswords_Keyword_FILE", 21));
  rb_define_const(self, "Reswords_Keyword_ENCODING", INT2FIX(redtree_rulenum_reswords__keyword__ENCODING__));
  rb_ary_push(arr, rb_str_new("Reswords_Keyword_ENCODING", 25));
  rb_define_const(self, "Reswords_KeywordBEGIN", INT2FIX(redtree_rulenum_reswords__keyword_BEGIN));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordBEGIN", 21));
  rb_define_const(self, "Reswords_KeywordEND", INT2FIX(redtree_rulenum_reswords__keyword_END));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordEND", 19));
  rb_define_const(self, "Reswords_KeywordAlias", INT2FIX(redtree_rulenum_reswords__keyword_alias));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordAlias", 21));
  rb_define_const(self, "Reswords_KeywordAnd", INT2FIX(redtree_rulenum_reswords__keyword_and));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordAnd", 19));
  rb_define_const(self, "Reswords_KeywordBegin", INT2FIX(redtree_rulenum_reswords__keyword_begin));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordBegin", 21));
  rb_define_const(self, "Reswords_KeywordBreak", INT2FIX(redtree_rulenum_reswords__keyword_break));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordBreak", 21));
  rb_define_const(self, "Reswords_KeywordCase", INT2FIX(redtree_rulenum_reswords__keyword_case));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordCase", 20));
  rb_define_const(self, "Reswords_KeywordClass", INT2FIX(redtree_rulenum_reswords__keyword_class));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordClass", 21));
  rb_define_const(self, "Reswords_KeywordDef", INT2FIX(redtree_rulenum_reswords__keyword_def));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordDef", 19));
  rb_define_const(self, "Reswords_KeywordDefined", INT2FIX(redtree_rulenum_reswords__keyword_defined));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordDefined", 23));
  rb_define_const(self, "Reswords_KeywordDo", INT2FIX(redtree_rulenum_reswords__keyword_do));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordDo", 18));
  rb_define_const(self, "Reswords_KeywordElse", INT2FIX(redtree_rulenum_reswords__keyword_else));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordElse", 20));
  rb_define_const(self, "Reswords_KeywordElsif", INT2FIX(redtree_rulenum_reswords__keyword_elsif));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordElsif", 21));
  rb_define_const(self, "Reswords_KeywordEnd", INT2FIX(redtree_rulenum_reswords__keyword_end));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordEnd", 19));
  rb_define_const(self, "Reswords_KeywordEnsure", INT2FIX(redtree_rulenum_reswords__keyword_ensure));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordEnsure", 22));
  rb_define_const(self, "Reswords_KeywordFalse", INT2FIX(redtree_rulenum_reswords__keyword_false));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordFalse", 21));
  rb_define_const(self, "Reswords_KeywordFor", INT2FIX(redtree_rulenum_reswords__keyword_for));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordFor", 19));
  rb_define_const(self, "Reswords_KeywordIn", INT2FIX(redtree_rulenum_reswords__keyword_in));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordIn", 18));
  rb_define_const(self, "Reswords_KeywordModule", INT2FIX(redtree_rulenum_reswords__keyword_module));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordModule", 22));
  rb_define_const(self, "Reswords_KeywordNext", INT2FIX(redtree_rulenum_reswords__keyword_next));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordNext", 20));
  rb_define_const(self, "Reswords_KeywordNil", INT2FIX(redtree_rulenum_reswords__keyword_nil));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordNil", 19));
  rb_define_const(self, "Reswords_KeywordNot", INT2FIX(redtree_rulenum_reswords__keyword_not));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordNot", 19));
  rb_define_const(self, "Reswords_KeywordOr", INT2FIX(redtree_rulenum_reswords__keyword_or));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordOr", 18));
  rb_define_const(self, "Reswords_KeywordRedo", INT2FIX(redtree_rulenum_reswords__keyword_redo));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordRedo", 20));
  rb_define_const(self, "Reswords_KeywordRescue", INT2FIX(redtree_rulenum_reswords__keyword_rescue));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordRescue", 22));
  rb_define_const(self, "Reswords_KeywordRetry", INT2FIX(redtree_rulenum_reswords__keyword_retry));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordRetry", 21));
  rb_define_const(self, "Reswords_KeywordReturn", INT2FIX(redtree_rulenum_reswords__keyword_return));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordReturn", 22));
  rb_define_const(self, "Reswords_KeywordSelf", INT2FIX(redtree_rulenum_reswords__keyword_self));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordSelf", 20));
  rb_define_const(self, "Reswords_KeywordSuper", INT2FIX(redtree_rulenum_reswords__keyword_super));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordSuper", 21));
  rb_define_const(self, "Reswords_KeywordThen", INT2FIX(redtree_rulenum_reswords__keyword_then));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordThen", 20));
  rb_define_const(self, "Reswords_KeywordTrue", INT2FIX(redtree_rulenum_reswords__keyword_true));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordTrue", 20));
  rb_define_const(self, "Reswords_KeywordUndef", INT2FIX(redtree_rulenum_reswords__keyword_undef));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordUndef", 21));
  rb_define_const(self, "Reswords_KeywordWhen", INT2FIX(redtree_rulenum_reswords__keyword_when));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordWhen", 20));
  rb_define_const(self, "Reswords_KeywordYield", INT2FIX(redtree_rulenum_reswords__keyword_yield));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordYield", 21));
  rb_define_const(self, "Reswords_KeywordIf", INT2FIX(redtree_rulenum_reswords__keyword_if));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordIf", 18));
  rb_define_const(self, "Reswords_KeywordUnless", INT2FIX(redtree_rulenum_reswords__keyword_unless));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordUnless", 22));
  rb_define_const(self, "Reswords_KeywordWhile", INT2FIX(redtree_rulenum_reswords__keyword_while));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordWhile", 21));
  rb_define_const(self, "Reswords_KeywordUntil", INT2FIX(redtree_rulenum_reswords__keyword_until));
  rb_ary_push(arr, rb_str_new("Reswords_KeywordUntil", 21));
  rb_define_const(self, "Arg_Lhs_EQ_Arg", INT2FIX(redtree_rulenum_arg__lhs__EQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Lhs_EQ_Arg", 14));
  rb_define_const(self, "Arg_Lhs_EQ_Arg_ModifierRescue_Arg", INT2FIX(redtree_rulenum_arg__lhs__EQ__arg__modifier_rescue__arg));
  rb_ary_push(arr, rb_str_new("Arg_Lhs_EQ_Arg_ModifierRescue_Arg", 33));
  rb_define_const(self, "Arg_VarLhs_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__var_lhs__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_VarLhs_TOPASGN_Arg", 22));
  rb_define_const(self, "Arg_VarLhs_TOPASGN_Arg_ModifierRescue_Arg", INT2FIX(redtree_rulenum_arg__var_lhs__tOP_ASGN__arg__modifier_rescue__arg));
  rb_ary_push(arr, rb_str_new("Arg_VarLhs_TOPASGN_Arg_ModifierRescue_Arg", 41));
  rb_define_const(self, "Arg_PrimaryValue_LS_OptCallArgs_Rbracket_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_PrimaryValue_LS_OptCallArgs_Rbracket_TOPASGN_Arg", 52));
  rb_define_const(self, "Arg_PrimaryValue_DOT_TIDENTIFIER_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__primary_value__DOT__tIDENTIFIER__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_PrimaryValue_DOT_TIDENTIFIER_TOPASGN_Arg", 44));
  rb_define_const(self, "Arg_PrimaryValue_DOT_TCONSTANT_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__primary_value__DOT__tCONSTANT__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_PrimaryValue_DOT_TCONSTANT_TOPASGN_Arg", 42));
  rb_define_const(self, "Arg_PrimaryValue_TCOLON2_TIDENTIFIER_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_PrimaryValue_TCOLON2_TIDENTIFIER_TOPASGN_Arg", 48));
  rb_define_const(self, "Arg_PrimaryValue_TCOLON2_TCONSTANT_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_PrimaryValue_TCOLON2_TCONSTANT_TOPASGN_Arg", 46));
  rb_define_const(self, "Arg_TCOLON3_TCONSTANT_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__tCOLON3__tCONSTANT__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_TCOLON3_TCONSTANT_TOPASGN_Arg", 33));
  rb_define_const(self, "Arg_Backref_TOPASGN_Arg", INT2FIX(redtree_rulenum_arg__backref__tOP_ASGN__arg));
  rb_ary_push(arr, rb_str_new("Arg_Backref_TOPASGN_Arg", 23));
  rb_define_const(self, "Arg_Arg_TDOT2_Arg", INT2FIX(redtree_rulenum_arg__arg__tDOT2__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TDOT2_Arg", 17));
  rb_define_const(self, "Arg_Arg_TDOT3_Arg", INT2FIX(redtree_rulenum_arg__arg__tDOT3__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TDOT3_Arg", 17));
  rb_define_const(self, "Arg_Arg_PLUS_Arg", INT2FIX(redtree_rulenum_arg__arg__PLUS__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_PLUS_Arg", 16));
  rb_define_const(self, "Arg_Arg_MINUS_Arg", INT2FIX(redtree_rulenum_arg__arg__MINUS__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_MINUS_Arg", 17));
  rb_define_const(self, "Arg_Arg_TIMES_Arg", INT2FIX(redtree_rulenum_arg__arg__TIMES__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TIMES_Arg", 17));
  rb_define_const(self, "Arg_Arg_DIVIDE_Arg", INT2FIX(redtree_rulenum_arg__arg__DIVIDE__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_DIVIDE_Arg", 18));
  rb_define_const(self, "Arg_Arg_TPOW_Arg", INT2FIX(redtree_rulenum_arg__arg__tPOW__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TPOW_Arg", 16));
  rb_define_const(self, "Arg_TUMINUSNUM_TINTEGER_TPOW_Arg", INT2FIX(redtree_rulenum_arg__tUMINUS_NUM__tINTEGER__tPOW__arg));
  rb_ary_push(arr, rb_str_new("Arg_TUMINUSNUM_TINTEGER_TPOW_Arg", 32));
  rb_define_const(self, "Arg_TUMINUSNUM_TFLOAT_TPOW_Arg", INT2FIX(redtree_rulenum_arg__tUMINUS_NUM__tFLOAT__tPOW__arg));
  rb_ary_push(arr, rb_str_new("Arg_TUMINUSNUM_TFLOAT_TPOW_Arg", 30));
  rb_define_const(self, "Arg_TUPLUS_Arg", INT2FIX(redtree_rulenum_arg__tUPLUS__arg));
  rb_ary_push(arr, rb_str_new("Arg_TUPLUS_Arg", 14));
  rb_define_const(self, "Arg_TUMINUS_Arg", INT2FIX(redtree_rulenum_arg__tUMINUS__arg));
  rb_ary_push(arr, rb_str_new("Arg_TUMINUS_Arg", 15));
  rb_define_const(self, "Arg_Arg_OR_Arg", INT2FIX(redtree_rulenum_arg__arg__OR__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_OR_Arg", 14));
  rb_define_const(self, "Arg_Arg_CARET_Arg", INT2FIX(redtree_rulenum_arg__arg__CARET__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_CARET_Arg", 17));
  rb_define_const(self, "Arg_Arg_AND_Arg", INT2FIX(redtree_rulenum_arg__arg__AND__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_AND_Arg", 15));
  rb_define_const(self, "Arg_Arg_TCMP_Arg", INT2FIX(redtree_rulenum_arg__arg__tCMP__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TCMP_Arg", 16));
  rb_define_const(self, "Arg_Arg_GT_Arg", INT2FIX(redtree_rulenum_arg__arg__GT__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_GT_Arg", 14));
  rb_define_const(self, "Arg_Arg_TGEQ_Arg", INT2FIX(redtree_rulenum_arg__arg__tGEQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TGEQ_Arg", 16));
  rb_define_const(self, "Arg_Arg_LT_Arg", INT2FIX(redtree_rulenum_arg__arg__LT__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_LT_Arg", 14));
  rb_define_const(self, "Arg_Arg_TLEQ_Arg", INT2FIX(redtree_rulenum_arg__arg__tLEQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TLEQ_Arg", 16));
  rb_define_const(self, "Arg_Arg_TEQ_Arg", INT2FIX(redtree_rulenum_arg__arg__tEQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TEQ_Arg", 15));
  rb_define_const(self, "Arg_Arg_TEQQ_Arg", INT2FIX(redtree_rulenum_arg__arg__tEQQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TEQQ_Arg", 16));
  rb_define_const(self, "Arg_Arg_TNEQ_Arg", INT2FIX(redtree_rulenum_arg__arg__tNEQ__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TNEQ_Arg", 16));
  rb_define_const(self, "Arg_Arg_TMATCH_Arg", INT2FIX(redtree_rulenum_arg__arg__tMATCH__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TMATCH_Arg", 18));
  rb_define_const(self, "Arg_Arg_TNMATCH_Arg", INT2FIX(redtree_rulenum_arg__arg__tNMATCH__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TNMATCH_Arg", 19));
  rb_define_const(self, "Arg_BANG_Arg", INT2FIX(redtree_rulenum_arg__BANG__arg));
  rb_ary_push(arr, rb_str_new("Arg_BANG_Arg", 12));
  rb_define_const(self, "Arg_TILDE_Arg", INT2FIX(redtree_rulenum_arg__TILDE__arg));
  rb_ary_push(arr, rb_str_new("Arg_TILDE_Arg", 13));
  rb_define_const(self, "Arg_Arg_TLSHFT_Arg", INT2FIX(redtree_rulenum_arg__arg__tLSHFT__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TLSHFT_Arg", 18));
  rb_define_const(self, "Arg_Arg_TRSHFT_Arg", INT2FIX(redtree_rulenum_arg__arg__tRSHFT__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TRSHFT_Arg", 18));
  rb_define_const(self, "Arg_Arg_TANDOP_Arg", INT2FIX(redtree_rulenum_arg__arg__tANDOP__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TANDOP_Arg", 18));
  rb_define_const(self, "Arg_Arg_TOROP_Arg", INT2FIX(redtree_rulenum_arg__arg__tOROP__arg));
  rb_ary_push(arr, rb_str_new("Arg_Arg_TOROP_Arg", 17));
  rb_define_const(self, "Arg_KeywordDefined_OptNl_Arg", INT2FIX(redtree_rulenum_arg__keyword_defined__opt_nl__arg));
  rb_ary_push(arr, rb_str_new("Arg_KeywordDefined_OptNl_Arg", 28));
  rb_define_const(self, "Arg_QMARK_Arg_OptNl_COLON_Arg", INT2FIX(redtree_rulenum_arg__QMARK__arg__opt_nl__COLON__arg));
  rb_ary_push(arr, rb_str_new("Arg_QMARK_Arg_OptNl_COLON_Arg", 29));
  rb_define_const(self, "Arg_Primary", INT2FIX(redtree_rulenum_arg__primary));
  rb_ary_push(arr, rb_str_new("Arg_Primary", 11));
  rb_define_const(self, "ArgValue_Arg", INT2FIX(redtree_rulenum_arg_value__arg));
  rb_ary_push(arr, rb_str_new("ArgValue_Arg", 12));
  rb_define_const(self, "ArefArgs_None", INT2FIX(redtree_rulenum_aref_args__none));
  rb_ary_push(arr, rb_str_new("ArefArgs_None", 13));
  rb_define_const(self, "ArefArgs_Args_Trailer", INT2FIX(redtree_rulenum_aref_args__args__trailer));
  rb_ary_push(arr, rb_str_new("ArefArgs_Args_Trailer", 21));
  rb_define_const(self, "ArefArgs_Args_COMMA_Assocs_Trailer", INT2FIX(redtree_rulenum_aref_args__args__COMMA__assocs__trailer));
  rb_ary_push(arr, rb_str_new("ArefArgs_Args_COMMA_Assocs_Trailer", 34));
  rb_define_const(self, "ArefArgs_Assocs_Trailer", INT2FIX(redtree_rulenum_aref_args__assocs__trailer));
  rb_ary_push(arr, rb_str_new("ArefArgs_Assocs_Trailer", 23));
  rb_define_const(self, "ParenArgs_LR_OptCallArgs_Rparen", INT2FIX(redtree_rulenum_paren_args__LR__opt_call_args__rparen));
  rb_ary_push(arr, rb_str_new("ParenArgs_LR_OptCallArgs_Rparen", 31));
  rb_define_const(self, "OptParenArgs_None", INT2FIX(redtree_rulenum_opt_paren_args__none));
  rb_ary_push(arr, rb_str_new("OptParenArgs_None", 17));
  rb_define_const(self, "OptParenArgs_ParenArgs", INT2FIX(redtree_rulenum_opt_paren_args__paren_args));
  rb_ary_push(arr, rb_str_new("OptParenArgs_ParenArgs", 22));
  rb_define_const(self, "OptCallArgs_None", INT2FIX(redtree_rulenum_opt_call_args__none));
  rb_ary_push(arr, rb_str_new("OptCallArgs_None", 16));
  rb_define_const(self, "OptCallArgs_CallArgs", INT2FIX(redtree_rulenum_opt_call_args__call_args));
  rb_ary_push(arr, rb_str_new("OptCallArgs_CallArgs", 20));
  rb_define_const(self, "OptCallArgs_Args_COMMA", INT2FIX(redtree_rulenum_opt_call_args__args__COMMA));
  rb_ary_push(arr, rb_str_new("OptCallArgs_Args_COMMA", 22));
  rb_define_const(self, "OptCallArgs_Args_COMMA_Assocs_COMMA", INT2FIX(redtree_rulenum_opt_call_args__args__COMMA__assocs__COMMA));
  rb_ary_push(arr, rb_str_new("OptCallArgs_Args_COMMA_Assocs_COMMA", 35));
  rb_define_const(self, "OptCallArgs_Assocs_COMMA", INT2FIX(redtree_rulenum_opt_call_args__assocs__COMMA));
  rb_ary_push(arr, rb_str_new("OptCallArgs_Assocs_COMMA", 24));
  rb_define_const(self, "CallArgs_Command", INT2FIX(redtree_rulenum_call_args__command));
  rb_ary_push(arr, rb_str_new("CallArgs_Command", 16));
  rb_define_const(self, "CallArgs_Args_OptBlockArg", INT2FIX(redtree_rulenum_call_args__args__opt_block_arg));
  rb_ary_push(arr, rb_str_new("CallArgs_Args_OptBlockArg", 25));
  rb_define_const(self, "CallArgs_Assocs_OptBlockArg", INT2FIX(redtree_rulenum_call_args__assocs__opt_block_arg));
  rb_ary_push(arr, rb_str_new("CallArgs_Assocs_OptBlockArg", 27));
  rb_define_const(self, "CallArgs_Args_COMMA_Assocs_OptBlockArg", INT2FIX(redtree_rulenum_call_args__args__COMMA__assocs__opt_block_arg));
  rb_ary_push(arr, rb_str_new("CallArgs_Args_COMMA_Assocs_OptBlockArg", 38));
  rb_define_const(self, "CallArgs_BlockArg", INT2FIX(redtree_rulenum_call_args__block_arg));
  rb_ary_push(arr, rb_str_new("CallArgs_BlockArg", 17));
  rb_define_const(self, "CommandArgs_CallArgs", INT2FIX(redtree_rulenum_command_args__call_args));
  rb_ary_push(arr, rb_str_new("CommandArgs_CallArgs", 20));
  rb_define_const(self, "BlockArg_TAMPER_ArgValue", INT2FIX(redtree_rulenum_block_arg__tAMPER__arg_value));
  rb_ary_push(arr, rb_str_new("BlockArg_TAMPER_ArgValue", 24));
  rb_define_const(self, "OptBlockArg_COMMA_BlockArg", INT2FIX(redtree_rulenum_opt_block_arg__COMMA__block_arg));
  rb_ary_push(arr, rb_str_new("OptBlockArg_COMMA_BlockArg", 26));
  rb_define_const(self, "OptBlockArg_None", INT2FIX(redtree_rulenum_opt_block_arg__none));
  rb_ary_push(arr, rb_str_new("OptBlockArg_None", 16));
  rb_define_const(self, "Args_ArgValue", INT2FIX(redtree_rulenum_args__arg_value));
  rb_ary_push(arr, rb_str_new("Args_ArgValue", 13));
  rb_define_const(self, "Args_TSTAR_ArgValue", INT2FIX(redtree_rulenum_args__tSTAR__arg_value));
  rb_ary_push(arr, rb_str_new("Args_TSTAR_ArgValue", 19));
  rb_define_const(self, "Args_Args_COMMA_ArgValue", INT2FIX(redtree_rulenum_args__args__COMMA__arg_value));
  rb_ary_push(arr, rb_str_new("Args_Args_COMMA_ArgValue", 24));
  rb_define_const(self, "Args_Args_COMMA_TSTAR_ArgValue", INT2FIX(redtree_rulenum_args__args__COMMA__tSTAR__arg_value));
  rb_ary_push(arr, rb_str_new("Args_Args_COMMA_TSTAR_ArgValue", 30));
  rb_define_const(self, "Mrhs_Args_COMMA_ArgValue", INT2FIX(redtree_rulenum_mrhs__args__COMMA__arg_value));
  rb_ary_push(arr, rb_str_new("Mrhs_Args_COMMA_ArgValue", 24));
  rb_define_const(self, "Mrhs_Args_COMMA_TSTAR_ArgValue", INT2FIX(redtree_rulenum_mrhs__args__COMMA__tSTAR__arg_value));
  rb_ary_push(arr, rb_str_new("Mrhs_Args_COMMA_TSTAR_ArgValue", 30));
  rb_define_const(self, "Mrhs_TSTAR_ArgValue", INT2FIX(redtree_rulenum_mrhs__tSTAR__arg_value));
  rb_ary_push(arr, rb_str_new("Mrhs_TSTAR_ArgValue", 19));
  rb_define_const(self, "Primary_Literal", INT2FIX(redtree_rulenum_primary__literal));
  rb_ary_push(arr, rb_str_new("Primary_Literal", 15));
  rb_define_const(self, "Primary_Strings", INT2FIX(redtree_rulenum_primary__strings));
  rb_ary_push(arr, rb_str_new("Primary_Strings", 15));
  rb_define_const(self, "Primary_Xstring", INT2FIX(redtree_rulenum_primary__xstring));
  rb_ary_push(arr, rb_str_new("Primary_Xstring", 15));
  rb_define_const(self, "Primary_Regexp", INT2FIX(redtree_rulenum_primary__regexp));
  rb_ary_push(arr, rb_str_new("Primary_Regexp", 14));
  rb_define_const(self, "Primary_Words", INT2FIX(redtree_rulenum_primary__words));
  rb_ary_push(arr, rb_str_new("Primary_Words", 13));
  rb_define_const(self, "Primary_Qwords", INT2FIX(redtree_rulenum_primary__qwords));
  rb_ary_push(arr, rb_str_new("Primary_Qwords", 14));
  rb_define_const(self, "Primary_VarRef", INT2FIX(redtree_rulenum_primary__var_ref));
  rb_ary_push(arr, rb_str_new("Primary_VarRef", 14));
  rb_define_const(self, "Primary_Backref", INT2FIX(redtree_rulenum_primary__backref));
  rb_ary_push(arr, rb_str_new("Primary_Backref", 15));
  rb_define_const(self, "Primary_TFID", INT2FIX(redtree_rulenum_primary__tFID));
  rb_ary_push(arr, rb_str_new("Primary_TFID", 12));
  rb_define_const(self, "Primary_KBegin", INT2FIX(redtree_rulenum_primary__k_begin));
  rb_ary_push(arr, rb_str_new("Primary_KBegin", 14));
  rb_define_const(self, "Primary_TLPARENARG_Expr_Rparen", INT2FIX(redtree_rulenum_primary__tLPAREN_ARG__expr__rparen));
  rb_ary_push(arr, rb_str_new("Primary_TLPARENARG_Expr_Rparen", 30));
  rb_define_const(self, "Primary_TLPAREN_Compstmt_RR", INT2FIX(redtree_rulenum_primary__tLPAREN__compstmt__RR));
  rb_ary_push(arr, rb_str_new("Primary_TLPAREN_Compstmt_RR", 27));
  rb_define_const(self, "Primary_PrimaryValue_TCOLON2_TCONSTANT", INT2FIX(redtree_rulenum_primary__primary_value__tCOLON2__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Primary_PrimaryValue_TCOLON2_TCONSTANT", 38));
  rb_define_const(self, "Primary_TCOLON3_TCONSTANT", INT2FIX(redtree_rulenum_primary__tCOLON3__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Primary_TCOLON3_TCONSTANT", 25));
  rb_define_const(self, "Primary_TLBRACK_ArefArgs_RS", INT2FIX(redtree_rulenum_primary__tLBRACK__aref_args__RS));
  rb_ary_push(arr, rb_str_new("Primary_TLBRACK_ArefArgs_RS", 27));
  rb_define_const(self, "Primary_TLBRACE_AssocList_RC", INT2FIX(redtree_rulenum_primary__tLBRACE__assoc_list__RC));
  rb_ary_push(arr, rb_str_new("Primary_TLBRACE_AssocList_RC", 28));
  rb_define_const(self, "Primary_KeywordReturn", INT2FIX(redtree_rulenum_primary__keyword_return));
  rb_ary_push(arr, rb_str_new("Primary_KeywordReturn", 21));
  rb_define_const(self, "Primary_KeywordYield_LR_CallArgs_Rparen", INT2FIX(redtree_rulenum_primary__keyword_yield__LR__call_args__rparen));
  rb_ary_push(arr, rb_str_new("Primary_KeywordYield_LR_CallArgs_Rparen", 39));
  rb_define_const(self, "Primary_KeywordYield_LR_Rparen", INT2FIX(redtree_rulenum_primary__keyword_yield__LR__rparen));
  rb_ary_push(arr, rb_str_new("Primary_KeywordYield_LR_Rparen", 30));
  rb_define_const(self, "Primary_KeywordYield", INT2FIX(redtree_rulenum_primary__keyword_yield));
  rb_ary_push(arr, rb_str_new("Primary_KeywordYield", 20));
  rb_define_const(self, "Primary_KeywordDefined_OptNl_LR_Expr_Rparen", INT2FIX(redtree_rulenum_primary__keyword_defined__opt_nl__LR__expr__rparen));
  rb_ary_push(arr, rb_str_new("Primary_KeywordDefined_OptNl_LR_Expr_Rparen", 43));
  rb_define_const(self, "Primary_KeywordNot_LR_Expr_Rparen", INT2FIX(redtree_rulenum_primary__keyword_not__LR__expr__rparen));
  rb_ary_push(arr, rb_str_new("Primary_KeywordNot_LR_Expr_Rparen", 33));
  rb_define_const(self, "Primary_KeywordNot_LR_Rparen", INT2FIX(redtree_rulenum_primary__keyword_not__LR__rparen));
  rb_ary_push(arr, rb_str_new("Primary_KeywordNot_LR_Rparen", 28));
  rb_define_const(self, "Primary_Operation_BraceBlock", INT2FIX(redtree_rulenum_primary__operation__brace_block));
  rb_ary_push(arr, rb_str_new("Primary_Operation_BraceBlock", 28));
  rb_define_const(self, "Primary_MethodCall", INT2FIX(redtree_rulenum_primary__method_call));
  rb_ary_push(arr, rb_str_new("Primary_MethodCall", 18));
  rb_define_const(self, "Primary_MethodCall_BraceBlock", INT2FIX(redtree_rulenum_primary__method_call__brace_block));
  rb_ary_push(arr, rb_str_new("Primary_MethodCall_BraceBlock", 29));
  rb_define_const(self, "Primary_TLAMBDA_Lambda", INT2FIX(redtree_rulenum_primary__tLAMBDA__lambda));
  rb_ary_push(arr, rb_str_new("Primary_TLAMBDA_Lambda", 22));
  rb_define_const(self, "Primary_KIf_ExprValue_Then_Compstmt_IfTail_KEnd", INT2FIX(redtree_rulenum_primary__k_if__expr_value__then__compstmt__if_tail__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KIf_ExprValue_Then_Compstmt_IfTail_KEnd", 47));
  rb_define_const(self, "Primary_KUnless_ExprValue_Then_Compstmt_OptElse_KEnd", INT2FIX(redtree_rulenum_primary__k_unless__expr_value__then__compstmt__opt_else__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KUnless_ExprValue_Then_Compstmt_OptElse_KEnd", 52));
  rb_define_const(self, "Primary_KWhile_ExprValue_Do_Compstmt_KEnd", INT2FIX(redtree_rulenum_primary__k_while__expr_value__do__compstmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KWhile_ExprValue_Do_Compstmt_KEnd", 41));
  rb_define_const(self, "Primary_KUntil_ExprValue_Do_Compstmt_KEnd", INT2FIX(redtree_rulenum_primary__k_until__expr_value__do__compstmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KUntil_ExprValue_Do_Compstmt_KEnd", 41));
  rb_define_const(self, "Primary_KCase_ExprValue_OptTerms_CaseBody_KEnd", INT2FIX(redtree_rulenum_primary__k_case__expr_value__opt_terms__case_body__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KCase_ExprValue_OptTerms_CaseBody_KEnd", 46));
  rb_define_const(self, "Primary_KCase_OptTerms_CaseBody_KEnd", INT2FIX(redtree_rulenum_primary__k_case__opt_terms__case_body__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KCase_OptTerms_CaseBody_KEnd", 36));
  rb_define_const(self, "Primary_KFor_ForVar_KeywordIn_ExprValue_Do_Compstmt_KEnd", INT2FIX(redtree_rulenum_primary__k_for__for_var__keyword_in__expr_value__do__compstmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KFor_ForVar_KeywordIn_ExprValue_Do_Compstmt_KEnd", 56));
  rb_define_const(self, "Primary_KClass_Cpath_Superclass_Bodystmt_KEnd", INT2FIX(redtree_rulenum_primary__k_class__cpath__superclass__bodystmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KClass_Cpath_Superclass_Bodystmt_KEnd", 45));
  rb_define_const(self, "Primary_KClass_TLSHFT_Expr_Term_Bodystmt_KEnd", INT2FIX(redtree_rulenum_primary__k_class__tLSHFT__expr__term__bodystmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KClass_TLSHFT_Expr_Term_Bodystmt_KEnd", 45));
  rb_define_const(self, "Primary_KModule_Cpath_Bodystmt_KEnd", INT2FIX(redtree_rulenum_primary__k_module__cpath__bodystmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KModule_Cpath_Bodystmt_KEnd", 35));
  rb_define_const(self, "Primary_KDef_Fname_FArglist_Bodystmt_KEnd", INT2FIX(redtree_rulenum_primary__k_def__fname__f_arglist__bodystmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KDef_Fname_FArglist_Bodystmt_KEnd", 41));
  rb_define_const(self, "Primary_KDef_Singleton_DotOrColon_Fname_FArglist_Bodystmt_KEnd", INT2FIX(redtree_rulenum_primary__k_def__singleton__dot_or_colon__fname__f_arglist__bodystmt__k_end));
  rb_ary_push(arr, rb_str_new("Primary_KDef_Singleton_DotOrColon_Fname_FArglist_Bodystmt_KEnd", 62));
  rb_define_const(self, "Primary_KeywordBreak", INT2FIX(redtree_rulenum_primary__keyword_break));
  rb_ary_push(arr, rb_str_new("Primary_KeywordBreak", 20));
  rb_define_const(self, "Primary_KeywordNext", INT2FIX(redtree_rulenum_primary__keyword_next));
  rb_ary_push(arr, rb_str_new("Primary_KeywordNext", 19));
  rb_define_const(self, "Primary_KeywordRedo", INT2FIX(redtree_rulenum_primary__keyword_redo));
  rb_ary_push(arr, rb_str_new("Primary_KeywordRedo", 19));
  rb_define_const(self, "Primary_KeywordRetry", INT2FIX(redtree_rulenum_primary__keyword_retry));
  rb_ary_push(arr, rb_str_new("Primary_KeywordRetry", 20));
  rb_define_const(self, "PrimaryValue_Primary", INT2FIX(redtree_rulenum_primary_value__primary));
  rb_ary_push(arr, rb_str_new("PrimaryValue_Primary", 20));
  rb_define_const(self, "KBegin_KeywordBegin", INT2FIX(redtree_rulenum_k_begin__keyword_begin));
  rb_ary_push(arr, rb_str_new("KBegin_KeywordBegin", 19));
  rb_define_const(self, "KIf_KeywordIf", INT2FIX(redtree_rulenum_k_if__keyword_if));
  rb_ary_push(arr, rb_str_new("KIf_KeywordIf", 13));
  rb_define_const(self, "KUnless_KeywordUnless", INT2FIX(redtree_rulenum_k_unless__keyword_unless));
  rb_ary_push(arr, rb_str_new("KUnless_KeywordUnless", 21));
  rb_define_const(self, "KWhile_KeywordWhile", INT2FIX(redtree_rulenum_k_while__keyword_while));
  rb_ary_push(arr, rb_str_new("KWhile_KeywordWhile", 19));
  rb_define_const(self, "KUntil_KeywordUntil", INT2FIX(redtree_rulenum_k_until__keyword_until));
  rb_ary_push(arr, rb_str_new("KUntil_KeywordUntil", 19));
  rb_define_const(self, "KCase_KeywordCase", INT2FIX(redtree_rulenum_k_case__keyword_case));
  rb_ary_push(arr, rb_str_new("KCase_KeywordCase", 17));
  rb_define_const(self, "KFor_KeywordFor", INT2FIX(redtree_rulenum_k_for__keyword_for));
  rb_ary_push(arr, rb_str_new("KFor_KeywordFor", 15));
  rb_define_const(self, "KClass_KeywordClass", INT2FIX(redtree_rulenum_k_class__keyword_class));
  rb_ary_push(arr, rb_str_new("KClass_KeywordClass", 19));
  rb_define_const(self, "KModule_KeywordModule", INT2FIX(redtree_rulenum_k_module__keyword_module));
  rb_ary_push(arr, rb_str_new("KModule_KeywordModule", 21));
  rb_define_const(self, "KDef_KeywordDef", INT2FIX(redtree_rulenum_k_def__keyword_def));
  rb_ary_push(arr, rb_str_new("KDef_KeywordDef", 15));
  rb_define_const(self, "KEnd_KeywordEnd", INT2FIX(redtree_rulenum_k_end__keyword_end));
  rb_ary_push(arr, rb_str_new("KEnd_KeywordEnd", 15));
  rb_define_const(self, "Then_Term", INT2FIX(redtree_rulenum_then__term));
  rb_ary_push(arr, rb_str_new("Then_Term", 9));
  rb_define_const(self, "Then_KeywordThen", INT2FIX(redtree_rulenum_then__keyword_then));
  rb_ary_push(arr, rb_str_new("Then_KeywordThen", 16));
  rb_define_const(self, "Then_Term_KeywordThen", INT2FIX(redtree_rulenum_then__term__keyword_then));
  rb_ary_push(arr, rb_str_new("Then_Term_KeywordThen", 21));
  rb_define_const(self, "Do_Term", INT2FIX(redtree_rulenum_do__term));
  rb_ary_push(arr, rb_str_new("Do_Term", 7));
  rb_define_const(self, "Do_KeywordDoCond", INT2FIX(redtree_rulenum_do__keyword_do_cond));
  rb_ary_push(arr, rb_str_new("Do_KeywordDoCond", 16));
  rb_define_const(self, "IfTail_OptElse", INT2FIX(redtree_rulenum_if_tail__opt_else));
  rb_ary_push(arr, rb_str_new("IfTail_OptElse", 14));
  rb_define_const(self, "IfTail_KeywordElsif_ExprValue_Then_Compstmt_IfTail", INT2FIX(redtree_rulenum_if_tail__keyword_elsif__expr_value__then__compstmt__if_tail));
  rb_ary_push(arr, rb_str_new("IfTail_KeywordElsif_ExprValue_Then_Compstmt_IfTail", 50));
  rb_define_const(self, "OptElse_None", INT2FIX(redtree_rulenum_opt_else__none));
  rb_ary_push(arr, rb_str_new("OptElse_None", 12));
  rb_define_const(self, "OptElse_KeywordElse_Compstmt", INT2FIX(redtree_rulenum_opt_else__keyword_else__compstmt));
  rb_ary_push(arr, rb_str_new("OptElse_KeywordElse_Compstmt", 28));
  rb_define_const(self, "ForVar_Lhs", INT2FIX(redtree_rulenum_for_var__lhs));
  rb_ary_push(arr, rb_str_new("ForVar_Lhs", 10));
  rb_define_const(self, "ForVar_Mlhs", INT2FIX(redtree_rulenum_for_var__mlhs));
  rb_ary_push(arr, rb_str_new("ForVar_Mlhs", 11));
  rb_define_const(self, "FMarg_FNormArg", INT2FIX(redtree_rulenum_f_marg__f_norm_arg));
  rb_ary_push(arr, rb_str_new("FMarg_FNormArg", 14));
  rb_define_const(self, "FMarg_TLPAREN_FMargs_Rparen", INT2FIX(redtree_rulenum_f_marg__tLPAREN__f_margs__rparen));
  rb_ary_push(arr, rb_str_new("FMarg_TLPAREN_FMargs_Rparen", 27));
  rb_define_const(self, "FMargList_FMarg", INT2FIX(redtree_rulenum_f_marg_list__f_marg));
  rb_ary_push(arr, rb_str_new("FMargList_FMarg", 15));
  rb_define_const(self, "FMargList_FMargList_COMMA_FMarg", INT2FIX(redtree_rulenum_f_marg_list__f_marg_list__COMMA__f_marg));
  rb_ary_push(arr, rb_str_new("FMargList_FMargList_COMMA_FMarg", 31));
  rb_define_const(self, "FMargs_FMargList", INT2FIX(redtree_rulenum_f_margs__f_marg_list));
  rb_ary_push(arr, rb_str_new("FMargs_FMargList", 16));
  rb_define_const(self, "FMargs_FMargList_COMMA_TSTAR_FNormArg", INT2FIX(redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg));
  rb_ary_push(arr, rb_str_new("FMargs_FMargList_COMMA_TSTAR_FNormArg", 37));
  rb_define_const(self, "FMargs_FMargList_COMMA_TSTAR_FNormArg_COMMA_FMargList", INT2FIX(redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg__COMMA__f_marg_list));
  rb_ary_push(arr, rb_str_new("FMargs_FMargList_COMMA_TSTAR_FNormArg_COMMA_FMargList", 53));
  rb_define_const(self, "FMargs_FMargList_COMMA_TSTAR", INT2FIX(redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR));
  rb_ary_push(arr, rb_str_new("FMargs_FMargList_COMMA_TSTAR", 28));
  rb_define_const(self, "FMargs_FMargList_COMMA_TSTAR_COMMA_FMargList", INT2FIX(redtree_rulenum_f_margs__f_marg_list__COMMA__tSTAR__COMMA__f_marg_list));
  rb_ary_push(arr, rb_str_new("FMargs_FMargList_COMMA_TSTAR_COMMA_FMargList", 44));
  rb_define_const(self, "FMargs_TSTAR_FNormArg", INT2FIX(redtree_rulenum_f_margs__tSTAR__f_norm_arg));
  rb_ary_push(arr, rb_str_new("FMargs_TSTAR_FNormArg", 21));
  rb_define_const(self, "FMargs_TSTAR_FNormArg_COMMA_FMargList", INT2FIX(redtree_rulenum_f_margs__tSTAR__f_norm_arg__COMMA__f_marg_list));
  rb_ary_push(arr, rb_str_new("FMargs_TSTAR_FNormArg_COMMA_FMargList", 37));
  rb_define_const(self, "FMargs_TSTAR", INT2FIX(redtree_rulenum_f_margs__tSTAR));
  rb_ary_push(arr, rb_str_new("FMargs_TSTAR", 12));
  rb_define_const(self, "FMargs_TSTAR_COMMA_FMargList", INT2FIX(redtree_rulenum_f_margs__tSTAR__COMMA__f_marg_list));
  rb_ary_push(arr, rb_str_new("FMargs_TSTAR_COMMA_FMargList", 28));
  rb_define_const(self, "BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FRestArg_OptFBlockArg", 62));
  rb_define_const(self, "BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 73));
  rb_define_const(self, "BlockParam_FArg_COMMA_FBlockOptarg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FBlockOptarg_OptFBlockArg", 47));
  rb_define_const(self, "BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_block_optarg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FBlockOptarg_COMMA_FArg_OptFBlockArg", 58));
  rb_define_const(self, "BlockParam_FArg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FRestArg_OptFBlockArg", 43));
  rb_define_const(self, "BlockParam_FArg_COMMA", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA", 21));
  rb_define_const(self, "BlockParam_FArg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 54));
  rb_define_const(self, "BlockParam_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FArg_OptFBlockArg", 28));
  rb_define_const(self, "BlockParam_FBlockOptarg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FBlockOptarg_COMMA_FRestArg_OptFBlockArg", 51));
  rb_define_const(self, "BlockParam_FBlockOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FBlockOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 62));
  rb_define_const(self, "BlockParam_FBlockOptarg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_block_optarg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FBlockOptarg_OptFBlockArg", 36));
  rb_define_const(self, "BlockParam_FBlockOptarg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_block_optarg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FBlockOptarg_COMMA_FArg_OptFBlockArg", 47));
  rb_define_const(self, "BlockParam_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FRestArg_OptFBlockArg", 32));
  rb_define_const(self, "BlockParam_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_block_param__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FRestArg_COMMA_FArg_OptFBlockArg", 43));
  rb_define_const(self, "BlockParam_FBlockArg", INT2FIX(redtree_rulenum_block_param__f_block_arg));
  rb_ary_push(arr, rb_str_new("BlockParam_FBlockArg", 20));
  rb_define_const(self, "OptBlockParam_None", INT2FIX(redtree_rulenum_opt_block_param__none));
  rb_ary_push(arr, rb_str_new("OptBlockParam_None", 18));
  rb_define_const(self, "OptBlockParam_BlockParamDef", INT2FIX(redtree_rulenum_opt_block_param__block_param_def));
  rb_ary_push(arr, rb_str_new("OptBlockParam_BlockParamDef", 27));
  rb_define_const(self, "BlockParamDef_OR_OptBvDecl_OR", INT2FIX(redtree_rulenum_block_param_def__OR__opt_bv_decl__OR));
  rb_ary_push(arr, rb_str_new("BlockParamDef_OR_OptBvDecl_OR", 29));
  rb_define_const(self, "BlockParamDef_TOROP", INT2FIX(redtree_rulenum_block_param_def__tOROP));
  rb_ary_push(arr, rb_str_new("BlockParamDef_TOROP", 19));
  rb_define_const(self, "BlockParamDef_OR_BlockParam_OptBvDecl_OR", INT2FIX(redtree_rulenum_block_param_def__OR__block_param__opt_bv_decl__OR));
  rb_ary_push(arr, rb_str_new("BlockParamDef_OR_BlockParam_OptBvDecl_OR", 40));
  rb_define_const(self, "OptBvDecl_None", INT2FIX(redtree_rulenum_opt_bv_decl__none));
  rb_ary_push(arr, rb_str_new("OptBvDecl_None", 14));
  rb_define_const(self, "OptBvDecl_SEMI_BvDecls", INT2FIX(redtree_rulenum_opt_bv_decl__SEMI__bv_decls));
  rb_ary_push(arr, rb_str_new("OptBvDecl_SEMI_BvDecls", 22));
  rb_define_const(self, "BvDecls_Bvar", INT2FIX(redtree_rulenum_bv_decls__bvar));
  rb_ary_push(arr, rb_str_new("BvDecls_Bvar", 12));
  rb_define_const(self, "BvDecls_BvDecls_COMMA_Bvar", INT2FIX(redtree_rulenum_bv_decls__bv_decls__COMMA__bvar));
  rb_ary_push(arr, rb_str_new("BvDecls_BvDecls_COMMA_Bvar", 26));
  rb_define_const(self, "Bvar_TIDENTIFIER", INT2FIX(redtree_rulenum_bvar__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Bvar_TIDENTIFIER", 16));
  rb_define_const(self, "Bvar_FBadArg", INT2FIX(redtree_rulenum_bvar__f_bad_arg));
  rb_ary_push(arr, rb_str_new("Bvar_FBadArg", 12));
  rb_define_const(self, "Lambda_FLarglist_LambdaBody", INT2FIX(redtree_rulenum_lambda__f_larglist__lambda_body));
  rb_ary_push(arr, rb_str_new("Lambda_FLarglist_LambdaBody", 27));
  rb_define_const(self, "FLarglist_LR_FArgs_OptBvDecl_Rparen", INT2FIX(redtree_rulenum_f_larglist__LR__f_args__opt_bv_decl__rparen));
  rb_ary_push(arr, rb_str_new("FLarglist_LR_FArgs_OptBvDecl_Rparen", 35));
  rb_define_const(self, "FLarglist_FArgs", INT2FIX(redtree_rulenum_f_larglist__f_args));
  rb_ary_push(arr, rb_str_new("FLarglist_FArgs", 15));
  rb_define_const(self, "LambdaBody_TLAMBEG_Compstmt_RC", INT2FIX(redtree_rulenum_lambda_body__tLAMBEG__compstmt__RC));
  rb_ary_push(arr, rb_str_new("LambdaBody_TLAMBEG_Compstmt_RC", 30));
  rb_define_const(self, "LambdaBody_KeywordDoLAMBDA_Compstmt_KeywordEnd", INT2FIX(redtree_rulenum_lambda_body__keyword_do_LAMBDA__compstmt__keyword_end));
  rb_ary_push(arr, rb_str_new("LambdaBody_KeywordDoLAMBDA_Compstmt_KeywordEnd", 46));
  rb_define_const(self, "DoBlock_KeywordDoBlock_OptBlockParam_Compstmt_KeywordEnd", INT2FIX(redtree_rulenum_do_block__keyword_do_block__opt_block_param__compstmt__keyword_end));
  rb_ary_push(arr, rb_str_new("DoBlock_KeywordDoBlock_OptBlockParam_Compstmt_KeywordEnd", 56));
  rb_define_const(self, "BlockCall_Command_DoBlock", INT2FIX(redtree_rulenum_block_call__command__do_block));
  rb_ary_push(arr, rb_str_new("BlockCall_Command_DoBlock", 25));
  rb_define_const(self, "BlockCall_BlockCall_DOT_Operation2_OptParenArgs", INT2FIX(redtree_rulenum_block_call__block_call__DOT__operation2__opt_paren_args));
  rb_ary_push(arr, rb_str_new("BlockCall_BlockCall_DOT_Operation2_OptParenArgs", 47));
  rb_define_const(self, "BlockCall_BlockCall_TCOLON2_Operation2_OptParenArgs", INT2FIX(redtree_rulenum_block_call__block_call__tCOLON2__operation2__opt_paren_args));
  rb_ary_push(arr, rb_str_new("BlockCall_BlockCall_TCOLON2_Operation2_OptParenArgs", 51));
  rb_define_const(self, "MethodCall_Operation_ParenArgs", INT2FIX(redtree_rulenum_method_call__operation__paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_Operation_ParenArgs", 30));
  rb_define_const(self, "MethodCall_PrimaryValue_DOT_Operation2_OptParenArgs", INT2FIX(redtree_rulenum_method_call__primary_value__DOT__operation2__opt_paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_DOT_Operation2_OptParenArgs", 51));
  rb_define_const(self, "MethodCall_PrimaryValue_TCOLON2_Operation2_ParenArgs", INT2FIX(redtree_rulenum_method_call__primary_value__tCOLON2__operation2__paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_TCOLON2_Operation2_ParenArgs", 52));
  rb_define_const(self, "MethodCall_PrimaryValue_TCOLON2_Operation3", INT2FIX(redtree_rulenum_method_call__primary_value__tCOLON2__operation3));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_TCOLON2_Operation3", 42));
  rb_define_const(self, "MethodCall_PrimaryValue_DOT_ParenArgs", INT2FIX(redtree_rulenum_method_call__primary_value__DOT__paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_DOT_ParenArgs", 37));
  rb_define_const(self, "MethodCall_PrimaryValue_TCOLON2_ParenArgs", INT2FIX(redtree_rulenum_method_call__primary_value__tCOLON2__paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_TCOLON2_ParenArgs", 41));
  rb_define_const(self, "MethodCall_KeywordSuper_ParenArgs", INT2FIX(redtree_rulenum_method_call__keyword_super__paren_args));
  rb_ary_push(arr, rb_str_new("MethodCall_KeywordSuper_ParenArgs", 33));
  rb_define_const(self, "MethodCall_KeywordSuper", INT2FIX(redtree_rulenum_method_call__keyword_super));
  rb_ary_push(arr, rb_str_new("MethodCall_KeywordSuper", 23));
  rb_define_const(self, "MethodCall_PrimaryValue_LS_OptCallArgs_Rbracket", INT2FIX(redtree_rulenum_method_call__primary_value__LS__opt_call_args__rbracket));
  rb_ary_push(arr, rb_str_new("MethodCall_PrimaryValue_LS_OptCallArgs_Rbracket", 47));
  rb_define_const(self, "BraceBlock_LC_OptBlockParam_Compstmt_RC", INT2FIX(redtree_rulenum_brace_block__LC__opt_block_param__compstmt__RC));
  rb_ary_push(arr, rb_str_new("BraceBlock_LC_OptBlockParam_Compstmt_RC", 39));
  rb_define_const(self, "BraceBlock_KeywordDo_OptBlockParam_Compstmt_KeywordEnd", INT2FIX(redtree_rulenum_brace_block__keyword_do__opt_block_param__compstmt__keyword_end));
  rb_ary_push(arr, rb_str_new("BraceBlock_KeywordDo_OptBlockParam_Compstmt_KeywordEnd", 54));
  rb_define_const(self, "CaseBody_KeywordWhen_Args_Then_Compstmt_Cases", INT2FIX(redtree_rulenum_case_body__keyword_when__args__then__compstmt__cases));
  rb_ary_push(arr, rb_str_new("CaseBody_KeywordWhen_Args_Then_Compstmt_Cases", 45));
  rb_define_const(self, "Cases_OptElse", INT2FIX(redtree_rulenum_cases__opt_else));
  rb_ary_push(arr, rb_str_new("Cases_OptElse", 13));
  rb_define_const(self, "Cases_CaseBody", INT2FIX(redtree_rulenum_cases__case_body));
  rb_ary_push(arr, rb_str_new("Cases_CaseBody", 14));
  rb_define_const(self, "OptRescue_KeywordRescue_ExcList_ExcVar_Then_Compstmt_OptRescue", INT2FIX(redtree_rulenum_opt_rescue__keyword_rescue__exc_list__exc_var__then__compstmt__opt_rescue));
  rb_ary_push(arr, rb_str_new("OptRescue_KeywordRescue_ExcList_ExcVar_Then_Compstmt_OptRescue", 62));
  rb_define_const(self, "OptRescue_None", INT2FIX(redtree_rulenum_opt_rescue__none));
  rb_ary_push(arr, rb_str_new("OptRescue_None", 14));
  rb_define_const(self, "ExcList_ArgValue", INT2FIX(redtree_rulenum_exc_list__arg_value));
  rb_ary_push(arr, rb_str_new("ExcList_ArgValue", 16));
  rb_define_const(self, "ExcList_Mrhs", INT2FIX(redtree_rulenum_exc_list__mrhs));
  rb_ary_push(arr, rb_str_new("ExcList_Mrhs", 12));
  rb_define_const(self, "ExcList_None", INT2FIX(redtree_rulenum_exc_list__none));
  rb_ary_push(arr, rb_str_new("ExcList_None", 12));
  rb_define_const(self, "ExcVar_TASSOC_Lhs", INT2FIX(redtree_rulenum_exc_var__tASSOC__lhs));
  rb_ary_push(arr, rb_str_new("ExcVar_TASSOC_Lhs", 17));
  rb_define_const(self, "ExcVar_None", INT2FIX(redtree_rulenum_exc_var__none));
  rb_ary_push(arr, rb_str_new("ExcVar_None", 11));
  rb_define_const(self, "OptEnsure_KeywordEnsure_Compstmt", INT2FIX(redtree_rulenum_opt_ensure__keyword_ensure__compstmt));
  rb_ary_push(arr, rb_str_new("OptEnsure_KeywordEnsure_Compstmt", 32));
  rb_define_const(self, "OptEnsure_None", INT2FIX(redtree_rulenum_opt_ensure__none));
  rb_ary_push(arr, rb_str_new("OptEnsure_None", 14));
  rb_define_const(self, "Literal_Numeric", INT2FIX(redtree_rulenum_literal__numeric));
  rb_ary_push(arr, rb_str_new("Literal_Numeric", 15));
  rb_define_const(self, "Literal_Symbol", INT2FIX(redtree_rulenum_literal__symbol));
  rb_ary_push(arr, rb_str_new("Literal_Symbol", 14));
  rb_define_const(self, "Literal_Dsym", INT2FIX(redtree_rulenum_literal__dsym));
  rb_ary_push(arr, rb_str_new("Literal_Dsym", 12));
  rb_define_const(self, "Strings_String", INT2FIX(redtree_rulenum_strings__string));
  rb_ary_push(arr, rb_str_new("Strings_String", 14));
  rb_define_const(self, "String_TCHAR", INT2FIX(redtree_rulenum_string__tCHAR));
  rb_ary_push(arr, rb_str_new("String_TCHAR", 12));
  rb_define_const(self, "String_String1", INT2FIX(redtree_rulenum_string__string1));
  rb_ary_push(arr, rb_str_new("String_String1", 14));
  rb_define_const(self, "String_String_String1", INT2FIX(redtree_rulenum_string__string__string1));
  rb_ary_push(arr, rb_str_new("String_String_String1", 21));
  rb_define_const(self, "String1_TSTRINGBEG_StringContents_TSTRINGEND", INT2FIX(redtree_rulenum_string1__tSTRING_BEG__string_contents__tSTRING_END));
  rb_ary_push(arr, rb_str_new("String1_TSTRINGBEG_StringContents_TSTRINGEND", 44));
  rb_define_const(self, "Xstring_TXSTRINGBEG_XstringContents_TSTRINGEND", INT2FIX(redtree_rulenum_xstring__tXSTRING_BEG__xstring_contents__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Xstring_TXSTRINGBEG_XstringContents_TSTRINGEND", 46));
  rb_define_const(self, "Regexp_TREGEXPBEG_RegexpContents_TREGEXPEND", INT2FIX(redtree_rulenum_regexp__tREGEXP_BEG__regexp_contents__tREGEXP_END));
  rb_ary_push(arr, rb_str_new("Regexp_TREGEXPBEG_RegexpContents_TREGEXPEND", 43));
  rb_define_const(self, "Words_TWORDSBEG_SP_TSTRINGEND", INT2FIX(redtree_rulenum_words__tWORDS_BEG__SP__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Words_TWORDSBEG_SP_TSTRINGEND", 29));
  rb_define_const(self, "Words_TWORDSBEG_WordList_TSTRINGEND", INT2FIX(redtree_rulenum_words__tWORDS_BEG__word_list__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Words_TWORDSBEG_WordList_TSTRINGEND", 35));
  rb_define_const(self, "WordList", INT2FIX(redtree_rulenum_word_list__));
  rb_ary_push(arr, rb_str_new("WordList", 8));
  rb_define_const(self, "WordList_WordList_Word_SP", INT2FIX(redtree_rulenum_word_list__word_list__word__SP));
  rb_ary_push(arr, rb_str_new("WordList_WordList_Word_SP", 25));
  rb_define_const(self, "Word_StringContent", INT2FIX(redtree_rulenum_word__string_content));
  rb_ary_push(arr, rb_str_new("Word_StringContent", 18));
  rb_define_const(self, "Word_Word_StringContent", INT2FIX(redtree_rulenum_word__word__string_content));
  rb_ary_push(arr, rb_str_new("Word_Word_StringContent", 23));
  rb_define_const(self, "Qwords_TQWORDSBEG_SP_TSTRINGEND", INT2FIX(redtree_rulenum_qwords__tQWORDS_BEG__SP__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Qwords_TQWORDSBEG_SP_TSTRINGEND", 31));
  rb_define_const(self, "Qwords_TQWORDSBEG_QwordList_TSTRINGEND", INT2FIX(redtree_rulenum_qwords__tQWORDS_BEG__qword_list__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Qwords_TQWORDSBEG_QwordList_TSTRINGEND", 38));
  rb_define_const(self, "QwordList", INT2FIX(redtree_rulenum_qword_list__));
  rb_ary_push(arr, rb_str_new("QwordList", 9));
  rb_define_const(self, "QwordList_QwordList_TSTRINGCONTENT_SP", INT2FIX(redtree_rulenum_qword_list__qword_list__tSTRING_CONTENT__SP));
  rb_ary_push(arr, rb_str_new("QwordList_QwordList_TSTRINGCONTENT_SP", 37));
  rb_define_const(self, "StringContents", INT2FIX(redtree_rulenum_string_contents__));
  rb_ary_push(arr, rb_str_new("StringContents", 14));
  rb_define_const(self, "StringContents_StringContents_StringContent", INT2FIX(redtree_rulenum_string_contents__string_contents__string_content));
  rb_ary_push(arr, rb_str_new("StringContents_StringContents_StringContent", 43));
  rb_define_const(self, "XstringContents", INT2FIX(redtree_rulenum_xstring_contents__));
  rb_ary_push(arr, rb_str_new("XstringContents", 15));
  rb_define_const(self, "XstringContents_XstringContents_StringContent", INT2FIX(redtree_rulenum_xstring_contents__xstring_contents__string_content));
  rb_ary_push(arr, rb_str_new("XstringContents_XstringContents_StringContent", 45));
  rb_define_const(self, "RegexpContents", INT2FIX(redtree_rulenum_regexp_contents__));
  rb_ary_push(arr, rb_str_new("RegexpContents", 14));
  rb_define_const(self, "RegexpContents_RegexpContents_StringContent", INT2FIX(redtree_rulenum_regexp_contents__regexp_contents__string_content));
  rb_ary_push(arr, rb_str_new("RegexpContents_RegexpContents_StringContent", 43));
  rb_define_const(self, "StringContent_TSTRINGCONTENT", INT2FIX(redtree_rulenum_string_content__tSTRING_CONTENT));
  rb_ary_push(arr, rb_str_new("StringContent_TSTRINGCONTENT", 28));
  rb_define_const(self, "StringContent_TSTRINGDVAR_StringDvar", INT2FIX(redtree_rulenum_string_content__tSTRING_DVAR__string_dvar));
  rb_ary_push(arr, rb_str_new("StringContent_TSTRINGDVAR_StringDvar", 36));
  rb_define_const(self, "StringContent_TSTRINGDBEG_Compstmt_RC", INT2FIX(redtree_rulenum_string_content__tSTRING_DBEG__compstmt__RC));
  rb_ary_push(arr, rb_str_new("StringContent_TSTRINGDBEG_Compstmt_RC", 37));
  rb_define_const(self, "StringDvar_TGVAR", INT2FIX(redtree_rulenum_string_dvar__tGVAR));
  rb_ary_push(arr, rb_str_new("StringDvar_TGVAR", 16));
  rb_define_const(self, "StringDvar_TIVAR", INT2FIX(redtree_rulenum_string_dvar__tIVAR));
  rb_ary_push(arr, rb_str_new("StringDvar_TIVAR", 16));
  rb_define_const(self, "StringDvar_TCVAR", INT2FIX(redtree_rulenum_string_dvar__tCVAR));
  rb_ary_push(arr, rb_str_new("StringDvar_TCVAR", 16));
  rb_define_const(self, "StringDvar_Backref", INT2FIX(redtree_rulenum_string_dvar__backref));
  rb_ary_push(arr, rb_str_new("StringDvar_Backref", 18));
  rb_define_const(self, "Symbol_TSYMBEG_Sym", INT2FIX(redtree_rulenum_symbol__tSYMBEG__sym));
  rb_ary_push(arr, rb_str_new("Symbol_TSYMBEG_Sym", 18));
  rb_define_const(self, "Sym_Fname", INT2FIX(redtree_rulenum_sym__fname));
  rb_ary_push(arr, rb_str_new("Sym_Fname", 9));
  rb_define_const(self, "Sym_TIVAR", INT2FIX(redtree_rulenum_sym__tIVAR));
  rb_ary_push(arr, rb_str_new("Sym_TIVAR", 9));
  rb_define_const(self, "Sym_TGVAR", INT2FIX(redtree_rulenum_sym__tGVAR));
  rb_ary_push(arr, rb_str_new("Sym_TGVAR", 9));
  rb_define_const(self, "Sym_TCVAR", INT2FIX(redtree_rulenum_sym__tCVAR));
  rb_ary_push(arr, rb_str_new("Sym_TCVAR", 9));
  rb_define_const(self, "Dsym_TSYMBEG_XstringContents_TSTRINGEND", INT2FIX(redtree_rulenum_dsym__tSYMBEG__xstring_contents__tSTRING_END));
  rb_ary_push(arr, rb_str_new("Dsym_TSYMBEG_XstringContents_TSTRINGEND", 39));
  rb_define_const(self, "Numeric_TINTEGER", INT2FIX(redtree_rulenum_numeric__tINTEGER));
  rb_ary_push(arr, rb_str_new("Numeric_TINTEGER", 16));
  rb_define_const(self, "Numeric_TFLOAT", INT2FIX(redtree_rulenum_numeric__tFLOAT));
  rb_ary_push(arr, rb_str_new("Numeric_TFLOAT", 14));
  rb_define_const(self, "Numeric_TUMINUSNUM_TINTEGER", INT2FIX(redtree_rulenum_numeric__tUMINUS_NUM__tINTEGER));
  rb_ary_push(arr, rb_str_new("Numeric_TUMINUSNUM_TINTEGER", 27));
  rb_define_const(self, "Numeric_TUMINUSNUM_TFLOAT", INT2FIX(redtree_rulenum_numeric__tUMINUS_NUM__tFLOAT));
  rb_ary_push(arr, rb_str_new("Numeric_TUMINUSNUM_TFLOAT", 25));
  rb_define_const(self, "UserVariable_TIDENTIFIER", INT2FIX(redtree_rulenum_user_variable__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("UserVariable_TIDENTIFIER", 24));
  rb_define_const(self, "UserVariable_TIVAR", INT2FIX(redtree_rulenum_user_variable__tIVAR));
  rb_ary_push(arr, rb_str_new("UserVariable_TIVAR", 18));
  rb_define_const(self, "UserVariable_TGVAR", INT2FIX(redtree_rulenum_user_variable__tGVAR));
  rb_ary_push(arr, rb_str_new("UserVariable_TGVAR", 18));
  rb_define_const(self, "UserVariable_TCONSTANT", INT2FIX(redtree_rulenum_user_variable__tCONSTANT));
  rb_ary_push(arr, rb_str_new("UserVariable_TCONSTANT", 22));
  rb_define_const(self, "UserVariable_TCVAR", INT2FIX(redtree_rulenum_user_variable__tCVAR));
  rb_ary_push(arr, rb_str_new("UserVariable_TCVAR", 18));
  rb_define_const(self, "KeywordVariable_KeywordNil", INT2FIX(redtree_rulenum_keyword_variable__keyword_nil));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordNil", 26));
  rb_define_const(self, "KeywordVariable_KeywordSelf", INT2FIX(redtree_rulenum_keyword_variable__keyword_self));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordSelf", 27));
  rb_define_const(self, "KeywordVariable_KeywordTrue", INT2FIX(redtree_rulenum_keyword_variable__keyword_true));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordTrue", 27));
  rb_define_const(self, "KeywordVariable_KeywordFalse", INT2FIX(redtree_rulenum_keyword_variable__keyword_false));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordFalse", 28));
  rb_define_const(self, "KeywordVariable_KeywordFILE", INT2FIX(redtree_rulenum_keyword_variable__keyword_FILE));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordFILE", 27));
  rb_define_const(self, "KeywordVariable_KeywordLINE", INT2FIX(redtree_rulenum_keyword_variable__keyword_LINE));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordLINE", 27));
  rb_define_const(self, "KeywordVariable_KeywordENCODING", INT2FIX(redtree_rulenum_keyword_variable__keyword_ENCODING));
  rb_ary_push(arr, rb_str_new("KeywordVariable_KeywordENCODING", 31));
  rb_define_const(self, "VarRef_UserVariable", INT2FIX(redtree_rulenum_var_ref__user_variable));
  rb_ary_push(arr, rb_str_new("VarRef_UserVariable", 19));
  rb_define_const(self, "Vcall_UserVariable", INT2FIX(redtree_rulenum_vcall__user_variable));
  rb_ary_push(arr, rb_str_new("Vcall_UserVariable", 18));
  rb_define_const(self, "VarRef_KeywordVariable", INT2FIX(redtree_rulenum_var_ref__keyword_variable));
  rb_ary_push(arr, rb_str_new("VarRef_KeywordVariable", 22));
  rb_define_const(self, "VarLhs_UserVariable", INT2FIX(redtree_rulenum_var_lhs__user_variable));
  rb_ary_push(arr, rb_str_new("VarLhs_UserVariable", 19));
  rb_define_const(self, "VarField_KeywordVariable", INT2FIX(redtree_rulenum_var_field__keyword_variable));
  rb_ary_push(arr, rb_str_new("VarField_KeywordVariable", 24));
  rb_define_const(self, "Backref_TNTHREF", INT2FIX(redtree_rulenum_backref__tNTH_REF));
  rb_ary_push(arr, rb_str_new("Backref_TNTHREF", 15));
  rb_define_const(self, "Backref_TBACKREF", INT2FIX(redtree_rulenum_backref__tBACK_REF));
  rb_ary_push(arr, rb_str_new("Backref_TBACKREF", 16));
  rb_define_const(self, "Superclass_Term", INT2FIX(redtree_rulenum_superclass__term));
  rb_ary_push(arr, rb_str_new("Superclass_Term", 15));
  rb_define_const(self, "Superclass_LT_ExprValue_Term", INT2FIX(redtree_rulenum_superclass__LT__expr_value__term));
  rb_ary_push(arr, rb_str_new("Superclass_LT_ExprValue_Term", 28));
  rb_define_const(self, "Superclass_Error_Term", INT2FIX(redtree_rulenum_superclass__error__term));
  rb_ary_push(arr, rb_str_new("Superclass_Error_Term", 21));
  rb_define_const(self, "FArglist_LR_FArgs_Rparen", INT2FIX(redtree_rulenum_f_arglist__LR__f_args__rparen));
  rb_ary_push(arr, rb_str_new("FArglist_LR_FArgs_Rparen", 24));
  rb_define_const(self, "FArglist_FArgs_Term", INT2FIX(redtree_rulenum_f_arglist__f_args__term));
  rb_ary_push(arr, rb_str_new("FArglist_FArgs_Term", 19));
  rb_define_const(self, "FArgs_FArg_COMMA_FOptarg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FOptarg_COMMA_FRestArg_OptFBlockArg", 52));
  rb_define_const(self, "FArgs_FArg_COMMA_FOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 63));
  rb_define_const(self, "FArgs_FArg_COMMA_FOptarg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_optarg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FOptarg_OptFBlockArg", 37));
  rb_define_const(self, "FArgs_FArg_COMMA_FOptarg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_optarg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FOptarg_COMMA_FArg_OptFBlockArg", 48));
  rb_define_const(self, "FArgs_FArg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FRestArg_OptFBlockArg", 38));
  rb_define_const(self, "FArgs_FArg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 49));
  rb_define_const(self, "FArgs_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FArg_OptFBlockArg", 23));
  rb_define_const(self, "FArgs_FOptarg_COMMA_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FOptarg_COMMA_FRestArg_OptFBlockArg", 41));
  rb_define_const(self, "FArgs_FOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FOptarg_COMMA_FRestArg_COMMA_FArg_OptFBlockArg", 52));
  rb_define_const(self, "FArgs_FOptarg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_optarg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FOptarg_OptFBlockArg", 26));
  rb_define_const(self, "FArgs_FOptarg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_optarg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FOptarg_COMMA_FArg_OptFBlockArg", 37));
  rb_define_const(self, "FArgs_FRestArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_rest_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FRestArg_OptFBlockArg", 27));
  rb_define_const(self, "FArgs_FRestArg_COMMA_FArg_OptFBlockArg", INT2FIX(redtree_rulenum_f_args__f_rest_arg__COMMA__f_arg__opt_f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FRestArg_COMMA_FArg_OptFBlockArg", 38));
  rb_define_const(self, "FArgs_FBlockArg", INT2FIX(redtree_rulenum_f_args__f_block_arg));
  rb_ary_push(arr, rb_str_new("FArgs_FBlockArg", 15));
  rb_define_const(self, "FArgs", INT2FIX(redtree_rulenum_f_args__));
  rb_ary_push(arr, rb_str_new("FArgs", 5));
  rb_define_const(self, "FBadArg_TCONSTANT", INT2FIX(redtree_rulenum_f_bad_arg__tCONSTANT));
  rb_ary_push(arr, rb_str_new("FBadArg_TCONSTANT", 17));
  rb_define_const(self, "FBadArg_TIVAR", INT2FIX(redtree_rulenum_f_bad_arg__tIVAR));
  rb_ary_push(arr, rb_str_new("FBadArg_TIVAR", 13));
  rb_define_const(self, "FBadArg_TGVAR", INT2FIX(redtree_rulenum_f_bad_arg__tGVAR));
  rb_ary_push(arr, rb_str_new("FBadArg_TGVAR", 13));
  rb_define_const(self, "FBadArg_TCVAR", INT2FIX(redtree_rulenum_f_bad_arg__tCVAR));
  rb_ary_push(arr, rb_str_new("FBadArg_TCVAR", 13));
  rb_define_const(self, "FNormArg_FBadArg", INT2FIX(redtree_rulenum_f_norm_arg__f_bad_arg));
  rb_ary_push(arr, rb_str_new("FNormArg_FBadArg", 16));
  rb_define_const(self, "FNormArg_TIDENTIFIER", INT2FIX(redtree_rulenum_f_norm_arg__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("FNormArg_TIDENTIFIER", 20));
  rb_define_const(self, "FArgItem_FNormArg", INT2FIX(redtree_rulenum_f_arg_item__f_norm_arg));
  rb_ary_push(arr, rb_str_new("FArgItem_FNormArg", 17));
  rb_define_const(self, "FArgItem_TLPAREN_FMargs_Rparen", INT2FIX(redtree_rulenum_f_arg_item__tLPAREN__f_margs__rparen));
  rb_ary_push(arr, rb_str_new("FArgItem_TLPAREN_FMargs_Rparen", 30));
  rb_define_const(self, "FArg_FArgItem", INT2FIX(redtree_rulenum_f_arg__f_arg_item));
  rb_ary_push(arr, rb_str_new("FArg_FArgItem", 13));
  rb_define_const(self, "FArg_FArg_COMMA_FArgItem", INT2FIX(redtree_rulenum_f_arg__f_arg__COMMA__f_arg_item));
  rb_ary_push(arr, rb_str_new("FArg_FArg_COMMA_FArgItem", 24));
  rb_define_const(self, "FOpt_TIDENTIFIER_EQ_ArgValue", INT2FIX(redtree_rulenum_f_opt__tIDENTIFIER__EQ__arg_value));
  rb_ary_push(arr, rb_str_new("FOpt_TIDENTIFIER_EQ_ArgValue", 28));
  rb_define_const(self, "FBlockOpt_TIDENTIFIER_EQ_PrimaryValue", INT2FIX(redtree_rulenum_f_block_opt__tIDENTIFIER__EQ__primary_value));
  rb_ary_push(arr, rb_str_new("FBlockOpt_TIDENTIFIER_EQ_PrimaryValue", 37));
  rb_define_const(self, "FBlockOptarg_FBlockOpt", INT2FIX(redtree_rulenum_f_block_optarg__f_block_opt));
  rb_ary_push(arr, rb_str_new("FBlockOptarg_FBlockOpt", 22));
  rb_define_const(self, "FBlockOptarg_FBlockOptarg_COMMA_FBlockOpt", INT2FIX(redtree_rulenum_f_block_optarg__f_block_optarg__COMMA__f_block_opt));
  rb_ary_push(arr, rb_str_new("FBlockOptarg_FBlockOptarg_COMMA_FBlockOpt", 41));
  rb_define_const(self, "FOptarg_FOpt", INT2FIX(redtree_rulenum_f_optarg__f_opt));
  rb_ary_push(arr, rb_str_new("FOptarg_FOpt", 12));
  rb_define_const(self, "FOptarg_FOptarg_COMMA_FOpt", INT2FIX(redtree_rulenum_f_optarg__f_optarg__COMMA__f_opt));
  rb_ary_push(arr, rb_str_new("FOptarg_FOptarg_COMMA_FOpt", 26));
  rb_define_const(self, "RestargMark_TIMES", INT2FIX(redtree_rulenum_restarg_mark__TIMES));
  rb_ary_push(arr, rb_str_new("RestargMark_TIMES", 17));
  rb_define_const(self, "RestargMark_TSTAR", INT2FIX(redtree_rulenum_restarg_mark__tSTAR));
  rb_ary_push(arr, rb_str_new("RestargMark_TSTAR", 17));
  rb_define_const(self, "FRestArg_RestargMark_TIDENTIFIER", INT2FIX(redtree_rulenum_f_rest_arg__restarg_mark__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("FRestArg_RestargMark_TIDENTIFIER", 32));
  rb_define_const(self, "FRestArg_RestargMark", INT2FIX(redtree_rulenum_f_rest_arg__restarg_mark));
  rb_ary_push(arr, rb_str_new("FRestArg_RestargMark", 20));
  rb_define_const(self, "BlkargMark_AND", INT2FIX(redtree_rulenum_blkarg_mark__AND));
  rb_ary_push(arr, rb_str_new("BlkargMark_AND", 14));
  rb_define_const(self, "BlkargMark_TAMPER", INT2FIX(redtree_rulenum_blkarg_mark__tAMPER));
  rb_ary_push(arr, rb_str_new("BlkargMark_TAMPER", 17));
  rb_define_const(self, "FBlockArg_BlkargMark_TIDENTIFIER", INT2FIX(redtree_rulenum_f_block_arg__blkarg_mark__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("FBlockArg_BlkargMark_TIDENTIFIER", 32));
  rb_define_const(self, "OptFBlockArg_COMMA_FBlockArg", INT2FIX(redtree_rulenum_opt_f_block_arg__COMMA__f_block_arg));
  rb_ary_push(arr, rb_str_new("OptFBlockArg_COMMA_FBlockArg", 28));
  rb_define_const(self, "OptFBlockArg_None", INT2FIX(redtree_rulenum_opt_f_block_arg__none));
  rb_ary_push(arr, rb_str_new("OptFBlockArg_None", 17));
  rb_define_const(self, "Singleton_VarRef", INT2FIX(redtree_rulenum_singleton__var_ref));
  rb_ary_push(arr, rb_str_new("Singleton_VarRef", 16));
  rb_define_const(self, "Singleton_LR_Expr_Rparen", INT2FIX(redtree_rulenum_singleton__LR__expr__rparen));
  rb_ary_push(arr, rb_str_new("Singleton_LR_Expr_Rparen", 24));
  rb_define_const(self, "AssocList_None", INT2FIX(redtree_rulenum_assoc_list__none));
  rb_ary_push(arr, rb_str_new("AssocList_None", 14));
  rb_define_const(self, "AssocList_Assocs_Trailer", INT2FIX(redtree_rulenum_assoc_list__assocs__trailer));
  rb_ary_push(arr, rb_str_new("AssocList_Assocs_Trailer", 24));
  rb_define_const(self, "Assocs_Assoc", INT2FIX(redtree_rulenum_assocs__assoc));
  rb_ary_push(arr, rb_str_new("Assocs_Assoc", 12));
  rb_define_const(self, "Assocs_Assocs_COMMA_Assoc", INT2FIX(redtree_rulenum_assocs__assocs__COMMA__assoc));
  rb_ary_push(arr, rb_str_new("Assocs_Assocs_COMMA_Assoc", 25));
  rb_define_const(self, "Assoc_ArgValue_TASSOC_ArgValue", INT2FIX(redtree_rulenum_assoc__arg_value__tASSOC__arg_value));
  rb_ary_push(arr, rb_str_new("Assoc_ArgValue_TASSOC_ArgValue", 30));
  rb_define_const(self, "Assoc_TLABEL_ArgValue", INT2FIX(redtree_rulenum_assoc__tLABEL__arg_value));
  rb_ary_push(arr, rb_str_new("Assoc_TLABEL_ArgValue", 21));
  rb_define_const(self, "Operation_TIDENTIFIER", INT2FIX(redtree_rulenum_operation__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Operation_TIDENTIFIER", 21));
  rb_define_const(self, "Operation_TCONSTANT", INT2FIX(redtree_rulenum_operation__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Operation_TCONSTANT", 19));
  rb_define_const(self, "Operation_TFID", INT2FIX(redtree_rulenum_operation__tFID));
  rb_ary_push(arr, rb_str_new("Operation_TFID", 14));
  rb_define_const(self, "Operation2_TIDENTIFIER", INT2FIX(redtree_rulenum_operation2__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Operation2_TIDENTIFIER", 22));
  rb_define_const(self, "Operation2_TCONSTANT", INT2FIX(redtree_rulenum_operation2__tCONSTANT));
  rb_ary_push(arr, rb_str_new("Operation2_TCONSTANT", 20));
  rb_define_const(self, "Operation2_TFID", INT2FIX(redtree_rulenum_operation2__tFID));
  rb_ary_push(arr, rb_str_new("Operation2_TFID", 15));
  rb_define_const(self, "Operation2_Op", INT2FIX(redtree_rulenum_operation2__op));
  rb_ary_push(arr, rb_str_new("Operation2_Op", 13));
  rb_define_const(self, "Operation3_TIDENTIFIER", INT2FIX(redtree_rulenum_operation3__tIDENTIFIER));
  rb_ary_push(arr, rb_str_new("Operation3_TIDENTIFIER", 22));
  rb_define_const(self, "Operation3_TFID", INT2FIX(redtree_rulenum_operation3__tFID));
  rb_ary_push(arr, rb_str_new("Operation3_TFID", 15));
  rb_define_const(self, "Operation3_Op", INT2FIX(redtree_rulenum_operation3__op));
  rb_ary_push(arr, rb_str_new("Operation3_Op", 13));
  rb_define_const(self, "DotOrColon_DOT", INT2FIX(redtree_rulenum_dot_or_colon__DOT));
  rb_ary_push(arr, rb_str_new("DotOrColon_DOT", 14));
  rb_define_const(self, "DotOrColon_TCOLON2", INT2FIX(redtree_rulenum_dot_or_colon__tCOLON2));
  rb_ary_push(arr, rb_str_new("DotOrColon_TCOLON2", 18));
  rb_define_const(self, "OptTerms", INT2FIX(redtree_rulenum_opt_terms__));
  rb_ary_push(arr, rb_str_new("OptTerms", 8));
  rb_define_const(self, "OptTerms_Terms", INT2FIX(redtree_rulenum_opt_terms__terms));
  rb_ary_push(arr, rb_str_new("OptTerms_Terms", 14));
  rb_define_const(self, "OptNl", INT2FIX(redtree_rulenum_opt_nl__));
  rb_ary_push(arr, rb_str_new("OptNl", 5));
  rb_define_const(self, "OptNl_NL", INT2FIX(redtree_rulenum_opt_nl__NL));
  rb_ary_push(arr, rb_str_new("OptNl_NL", 8));
  rb_define_const(self, "Rparen_OptNl_RR", INT2FIX(redtree_rulenum_rparen__opt_nl__RR));
  rb_ary_push(arr, rb_str_new("Rparen_OptNl_RR", 15));
  rb_define_const(self, "Rbracket_OptNl_RS", INT2FIX(redtree_rulenum_rbracket__opt_nl__RS));
  rb_ary_push(arr, rb_str_new("Rbracket_OptNl_RS", 17));
  rb_define_const(self, "Trailer", INT2FIX(redtree_rulenum_trailer__));
  rb_ary_push(arr, rb_str_new("Trailer", 7));
  rb_define_const(self, "Trailer_NL", INT2FIX(redtree_rulenum_trailer__NL));
  rb_ary_push(arr, rb_str_new("Trailer_NL", 10));
  rb_define_const(self, "Trailer_COMMA", INT2FIX(redtree_rulenum_trailer__COMMA));
  rb_ary_push(arr, rb_str_new("Trailer_COMMA", 13));
  rb_define_const(self, "Term_SEMI", INT2FIX(redtree_rulenum_term__SEMI));
  rb_ary_push(arr, rb_str_new("Term_SEMI", 9));
  rb_define_const(self, "Term_NL", INT2FIX(redtree_rulenum_term__NL));
  rb_ary_push(arr, rb_str_new("Term_NL", 7));
  rb_define_const(self, "Terms_Term", INT2FIX(redtree_rulenum_terms__term));
  rb_ary_push(arr, rb_str_new("Terms_Term", 10));
  rb_define_const(self, "Terms_Terms_SEMI", INT2FIX(redtree_rulenum_terms__terms__SEMI));
  rb_ary_push(arr, rb_str_new("Terms_Terms_SEMI", 16));
  rb_define_const(self, "None", INT2FIX(redtree_rulenum_none__));
  rb_ary_push(arr, rb_str_new("None", 4));
  rb_define_const(self, "MagicComment", INT2FIX(redtree_rulenum_magic_comment));
  rb_ary_push(arr, rb_str_new("MagicComment", 12));
  rb_define_const(self, "MAXRULES", INT2FIX(redtree_rulenum_MAX_RULES));
  rb_ary_push(arr, rb_str_new("MAXRULES", 8));
}
