/**********************************************************************

  parse.y -

  $Author: nobu $
  created at: Fri May 28 18:02:42 JST 1993

  Copyright (C) 1993-2007 Yukihiro Matsumoto

**********************************************************************/

%{

#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYSTACK_USE_ALLOCA 0

#include "ruby/ruby.h"
#include "ruby/st.h"
#include "ruby/encoding.h"
#include "internal.h"
#include "node.h"
#include "parse.h"
#include "id.h"
#include "regenc.h"
#include <stdio.h>
#include <errno.h>
#include <ctype.h>

#define numberof(array) (int)(sizeof(array) / sizeof((array)[0]))

#define YYMALLOC(size)    rb_parser_malloc(parser, (size))
#define YYREALLOC(ptr, size)  rb_parser_realloc(parser, (ptr), (size))
#define YYCALLOC(nelem, size) rb_parser_calloc(parser, (nelem), (size))
#define YYFREE(ptr)   rb_parser_free(parser, (ptr))
#define malloc  YYMALLOC
#define realloc YYREALLOC
#define calloc  YYCALLOC
#define free  YYFREE

#define is_notop_id(id) ((id)>tLAST_TOKEN)
#define is_local_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_LOCAL)
#define is_global_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_GLOBAL)
#define is_instance_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_INSTANCE)
#define is_attrset_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_ATTRSET)
#define is_const_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CONST)
#define is_class_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_CLASS)
#define is_junk_id(id) (is_notop_id(id)&&((id)&ID_SCOPE_MASK)==ID_JUNK)

#define is_asgn_or_id(id) ((is_notop_id(id)) && \
  (((id)&ID_SCOPE_MASK) == ID_GLOBAL || \
   ((id)&ID_SCOPE_MASK) == ID_INSTANCE || \
   ((id)&ID_SCOPE_MASK) == ID_CLASS))

enum lex_state_e {
    EXPR_BEG,     /* ignore newline, +/- is a sign. */
    EXPR_END,     /* newline significant, +/- is an operator. */
    EXPR_ENDARG,    /* ditto, and unbound braces. */
    EXPR_ENDFN,     /* ditto, and unbound braces. */
    EXPR_ARG,     /* newline significant, +/- is an operator. */
    EXPR_CMDARG,    /* newline significant, +/- is an operator. */
    EXPR_MID,     /* newline significant, +/- is an operator. */
    EXPR_FNAME,     /* ignore newline, no reserved words. */
    EXPR_DOT,     /* right after `.' or `::', no reserved words. */
    EXPR_CLASS,     /* immediate after `class', no here document. */
    EXPR_VALUE,     /* alike EXPR_BEG but label is disallowed. */
    EXPR_MAX_STATE
};

typedef VALUE stack_type;

# define BITSTACK_PUSH(stack, n)  ((stack) = ((stack)<<1)|((n)&1))
# define BITSTACK_POP(stack)  ((stack) = (stack) >> 1)
# define BITSTACK_LEXPOP(stack) ((stack) = ((stack) >> 1) | ((stack) & 1))
# define BITSTACK_SET_P(stack)  ((stack)&1)

#define COND_PUSH(n)  BITSTACK_PUSH(cond_stack, (n))
#define COND_POP()  BITSTACK_POP(cond_stack)
#define COND_LEXPOP() BITSTACK_LEXPOP(cond_stack)
#define COND_P()  BITSTACK_SET_P(cond_stack)

#define CMDARG_PUSH(n)  BITSTACK_PUSH(cmdarg_stack, (n))
#define CMDARG_POP()  BITSTACK_POP(cmdarg_stack)
#define CMDARG_LEXPOP() BITSTACK_LEXPOP(cmdarg_stack)
#define CMDARG_P()  BITSTACK_SET_P(cmdarg_stack)

struct vtable {
    ID *tbl;
    int pos;
    int capa;
    struct vtable *prev;
};

struct local_vars {
    struct vtable *args;
    struct vtable *vars;
    struct vtable *used;
    struct local_vars *prev;
};

#define DVARS_INHERIT ((void*)1)
#define DVARS_TOPSCOPE NULL
#define DVARS_SPECIAL_P(tbl) (!POINTER_P(tbl))
#define POINTER_P(val) ((VALUE)(val) & ~(VALUE)3)

static int
vtable_size(const struct vtable *tbl)
{
    if (POINTER_P(tbl)) {
        return tbl->pos;
    }
    else {
        return 0;
    }
}

#define VTBL_DEBUG 0

static struct vtable *
vtable_alloc(struct vtable *prev)
{
    struct vtable *tbl = ALLOC(struct vtable);
    tbl->pos = 0;
    tbl->capa = 8;
    tbl->tbl = ALLOC_N(ID, tbl->capa);
    tbl->prev = prev;
    if (VTBL_DEBUG) printf("vtable_alloc: %p\n", (void *)tbl);
    return tbl;
}

static void
vtable_free(struct vtable *tbl)
{
    if (VTBL_DEBUG)printf("vtable_free: %p\n", (void *)tbl);
    if (POINTER_P(tbl)) {
        if (tbl->tbl) {
            xfree(tbl->tbl);
        }
        xfree(tbl);
    }
}

static void
vtable_add(struct vtable *tbl, ID id)
{
    if (!POINTER_P(tbl)) {
        rb_bug("vtable_add: vtable is not allocated (%p)", (void *)tbl);
    }
    if (VTBL_DEBUG) printf("vtable_add: %p, %s\n", (void *)tbl, rb_id2name(id));

    if (tbl->pos == tbl->capa) {
        tbl->capa = tbl->capa * 2;
        REALLOC_N(tbl->tbl, ID, tbl->capa);
    }
    tbl->tbl[tbl->pos++] = id;
}

static int
vtable_included(const struct vtable * tbl, ID id)
{
    int i;

    if (POINTER_P(tbl)) {
        for (i = 0; i < tbl->pos; i++) {
            if (tbl->tbl[i] == id) {
                return i+1;
            }
        }
    }
    return 0;
}


/*
    Structure of Lexer Buffer:

 lex_pbeg      tokp         lex_p        lex_pend
    |           |              |            |
    |-----------+--------------+------------|
                |<------------>|
                     token
*/
struct parser_params {
    int is_redtree;
    NODE *heap;

    YYSTYPE *parser_yylval;
    VALUE eofp;

    NODE *parser_lex_strterm;
    enum lex_state_e parser_lex_state;
    stack_type parser_cond_stack;
    stack_type parser_cmdarg_stack;
    int parser_class_nest;
    int parser_paren_nest;
    int parser_lpar_beg;
    int parser_in_single;
    int parser_in_def;
    int parser_compile_for_eval;
    VALUE parser_cur_mid;
    int parser_in_defined;
    char *parser_tokenbuf;
    int parser_tokidx;
    int parser_toksiz;
    VALUE parser_lex_input;
    VALUE parser_lex_lastline;
    VALUE parser_lex_nextline;
    const char *parser_lex_pbeg;
    const char *parser_lex_p;
    const char *parser_lex_pend;
    int parser_heredoc_end;
    int parser_command_start;
    NODE *parser_deferred_nodes;
    long parser_lex_gets_ptr;
    VALUE (*parser_lex_gets)(struct parser_params*,VALUE);
    struct local_vars *parser_lvtbl;
    int parser_ruby__end__seen;
    int line_count;
    int has_shebang;
    char *parser_ruby_sourcefile; /* current source file */
    int parser_ruby_sourceline; /* current line no. */
    rb_encoding *enc;
    rb_encoding *utf8;

    int parser_yydebug;

    /* Redtree only */
    VALUE parser_ruby_sourcefile_string;
    const char *tokp;
    VALUE delayed;
    int delayed_line;
    int delayed_col;

    VALUE value;
    VALUE result;
    VALUE parsing_thread;
    int toplevel_p;
};

#define UTF8_ENC() (parser->utf8 ? parser->utf8 : \
        (parser->utf8 = rb_utf8_encoding()))
#define STR_NEW(p,n) rb_enc_str_new((p),(n),parser->enc)
#define STR_NEW0() rb_enc_str_new(0,0,parser->enc)
#define STR_NEW2(p) rb_enc_str_new((p),strlen(p),parser->enc)
#define STR_NEW3(p,n,e,func) parser_str_new((p),(n),(e),(func),parser->enc)
#define ENC_SINGLE(cr) ((cr)==ENC_CODERANGE_7BIT)
#define TOK_INTERN(mb) rb_intern3(tok(), toklen(), parser->enc)

static int parser_yyerror(struct parser_params*, const char*);
#define yyerror(msg) parser_yyerror(parser, (msg))

#define YYLEX_PARAM parser

#define lex_strterm   (parser->parser_lex_strterm)
#define lex_state   (parser->parser_lex_state)
#define cond_stack    (parser->parser_cond_stack)
#define cmdarg_stack    (parser->parser_cmdarg_stack)
#define class_nest    (parser->parser_class_nest)
#define paren_nest    (parser->parser_paren_nest)
#define lpar_beg    (parser->parser_lpar_beg)
#define in_single   (parser->parser_in_single)
#define in_def      (parser->parser_in_def)
#define compile_for_eval  (parser->parser_compile_for_eval)
#define cur_mid     (parser->parser_cur_mid)
#define in_defined    (parser->parser_in_defined)
#define tokenbuf    (parser->parser_tokenbuf)
#define tokidx      (parser->parser_tokidx)
#define toksiz      (parser->parser_toksiz)
#define lex_input   (parser->parser_lex_input)
#define lex_lastline    (parser->parser_lex_lastline)
#define lex_nextline    (parser->parser_lex_nextline)
#define lex_pbeg    (parser->parser_lex_pbeg)
#define lex_p     (parser->parser_lex_p)
#define lex_pend    (parser->parser_lex_pend)
#define heredoc_end   (parser->parser_heredoc_end)
#define command_start   (parser->parser_command_start)
#define deferred_nodes    (parser->parser_deferred_nodes)
#define lex_gets_ptr    (parser->parser_lex_gets_ptr)
#define lex_gets    (parser->parser_lex_gets)
#define lvtbl     (parser->parser_lvtbl)
#define ruby__end__seen   (parser->parser_ruby__end__seen)
#define ruby_sourceline   (parser->parser_ruby_sourceline)
#define ruby_sourcefile   (parser->parser_ruby_sourcefile)
#define current_enc   (parser->enc)
#define yydebug     (parser->parser_yydebug)

static int yylex(void*, void*);



#define remove_begin(node) (node)
#define rb_dvar_defined(id) 0
#define rb_local_defined(id) 0
static ID redtree_get_id(VALUE);
#define get_id(id) redtree_get_id(id)
static VALUE redtree_get_value(VALUE);
#define get_value(val) redtree_get_value(val)
static VALUE assignable_gen(struct parser_params*,VALUE);
#define assignable(lhs,node) assignable_gen(parser, (lhs))
static int id_is_var_gen(struct parser_params *parser, ID id);
#define id_is_var(id) id_is_var_gen(parser, (id))

static ID formal_argument_gen(struct parser_params*, ID);
#define formal_argument(id) formal_argument_gen(parser, (id))
static ID shadowing_lvar_gen(struct parser_params*,ID);
#define shadowing_lvar(name) shadowing_lvar_gen(parser, (name))
static void new_bv_gen(struct parser_params*,ID);
#define new_bv(id) new_bv_gen(parser, (id))

static void local_push_gen(struct parser_params*,int);
#define local_push(top) local_push_gen(parser,(top))
static void local_pop_gen(struct parser_params*);
#define local_pop() local_pop_gen(parser)
static int local_var_gen(struct parser_params*, ID);
#define local_var(id) local_var_gen(parser, (id));
static int arg_var_gen(struct parser_params*, ID);
#define arg_var(id) arg_var_gen(parser, (id))
static int  local_id_gen(struct parser_params*, ID);
#define local_id(id) local_id_gen(parser, (id))
static ID   internal_id_gen(struct parser_params*);
#define internal_id() internal_id_gen(parser)

static const struct vtable *dyna_push_gen(struct parser_params *);
#define dyna_push() dyna_push_gen(parser)
static void dyna_pop_gen(struct parser_params*, const struct vtable *);
#define dyna_pop(node) dyna_pop_gen(parser, (node))
static int dyna_in_block_gen(struct parser_params*);
#define dyna_in_block() dyna_in_block_gen(parser)
#define dyna_var(id) local_var(id)
static int dvar_defined_gen(struct parser_params*,ID,int);
#define dvar_defined(id) dvar_defined_gen(parser, (id), 0)
#define dvar_defined_get(id) dvar_defined_gen(parser, (id), 1)
static int dvar_curr_gen(struct parser_params*,ID);
#define dvar_curr(id) dvar_curr_gen(parser, (id))

static int lvar_defined_gen(struct parser_params*, ID);
#define lvar_defined(id) lvar_defined_gen(parser, (id))

#define RE_OPTION_ONCE (1<<16)
#define RE_OPTION_ENCODING_SHIFT 8
#define RE_OPTION_ENCODING(e) (((e)&0xff)<<RE_OPTION_ENCODING_SHIFT)
#define RE_OPTION_ENCODING_IDX(o) (((o)>>RE_OPTION_ENCODING_SHIFT)&0xff)
#define RE_OPTION_ENCODING_NONE(o) ((o)&RE_OPTION_ARG_ENCODING_NONE)
#define RE_OPTION_MASK  0xff
#define RE_OPTION_ARG_ENCODING_NONE 32

#define NODE_STRTERM NODE_ZARRAY  /* nothing to gc */
#define NODE_HEREDOC NODE_ARRAY   /* 1, 3 to gc */
#define SIGN_EXTEND(x,n) (((1<<(n)-1)^((x)&~(~0<<(n))))-(1<<(n)-1))
#define nd_func u1.id
#if SIZEOF_SHORT == 2
#define nd_term(node) ((signed short)(node)->u2.id)
#else
#define nd_term(node) SIGN_EXTEND((node)->u2.id, CHAR_BIT*2)
#endif
#define nd_paren(node) (char)((node)->u2.id >> CHAR_BIT*2)
#define nd_nest u3.cnt

/****** Redtree *******/

#define Redtree_VERSION "0.1.0"

#include "eventids1.c"
#include "eventids2.c"
static ID redtree_id_gets;

static VALUE redtree_dispatch0(struct parser_params*,ID);
static VALUE redtree_dispatch1(struct parser_params*,ID,VALUE);
static VALUE redtree_dispatch2(struct parser_params*,ID,VALUE,VALUE);
static VALUE redtree_dispatch3(struct parser_params*,ID,VALUE,VALUE,VALUE);
static VALUE redtree_dispatch4(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE);
static VALUE redtree_dispatch5(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE,VALUE);

#define dispatch0(n)            redtree_dispatch0(parser, TOKEN_PASTE(redtree_id_, n))
#define dispatch1(n,a)          redtree_dispatch1(parser, TOKEN_PASTE(redtree_id_, n), (a))
#define dispatch2(n,a,b)        redtree_dispatch2(parser, TOKEN_PASTE(redtree_id_, n), (a), (b))
#define dispatch3(n,a,b,c)      redtree_dispatch3(parser, TOKEN_PASTE(redtree_id_, n), (a), (b), (c))
#define dispatch4(n,a,b,c,d)    redtree_dispatch4(parser, TOKEN_PASTE(redtree_id_, n), (a), (b), (c), (d))
#define dispatch5(n,a,b,c,d,e)  redtree_dispatch5(parser, TOKEN_PASTE(redtree_id_, n), (a), (b), (c), (d), (e))

#define yyparse redtree_yyparse

#define redtree_intern(s) ID2SYM(rb_intern(s))
static VALUE redtree_id2sym(ID);
#ifdef __GNUC__
#define redtree_id2sym(id) ((id) < 256 && rb_ispunct(id) ? \
         ID2SYM(id) : redtree_id2sym(id))
#endif

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

#define escape_Qundef(x) ((x)==Qundef ? Qnil : (x))

#define FIXME 0

# define rb_warn0(fmt)    redtree_warn0(parser, (fmt))
# define rb_warnI(fmt,a)  redtree_warnI(parser, (fmt), (a))
# define rb_warnS(fmt,a)  redtree_warnS(parser, (fmt), (a))
# define rb_warning0(fmt) redtree_warning0(parser, (fmt))
# define rb_warningS(fmt,a) redtree_warningS(parser, (fmt), (a))
static void redtree_warn0(struct parser_params*, const char*);
static void redtree_warnI(struct parser_params*, const char*, int);
static void redtree_warning0(struct parser_params*, const char*);
static void redtree_warningS(struct parser_params*, const char*, const char*);

static void redtree_compile_error(struct parser_params*, const char *fmt, ...);
# define rb_compile_error redtree_compile_error
# define compile_error redtree_compile_error
# define PARSER_ARG parser,

/* Older versions of Yacc set YYMAXDEPTH to a very low value by default (150,
   for instance).  This is too low for Ruby to parse some files, such as
   date/format.rb, therefore bump the value up to at least Bison's default. */
#ifdef OLD_YACC
#ifndef YYMAXDEPTH
#define YYMAXDEPTH 10000
#endif
#endif

#define token_info_push(token) /* nothing */
#define token_info_pop(token) /* nothing */
%}

%pure_parser
%parse-param {struct parser_params *parser}

%union {
    VALUE val;
    NODE *node;
    ID id;
    int num;
    const struct vtable *vars;
}

/*
%token
*/
%token <val>

  keyword_class
  keyword_module
  keyword_def
  keyword_undef
  keyword_begin
  keyword_rescue
  keyword_ensure
  keyword_end
  keyword_if
  keyword_unless
  keyword_then
  keyword_elsif
  keyword_else
  keyword_case
  keyword_when
  keyword_while
  keyword_until
  keyword_for
  keyword_break
  keyword_next
  keyword_redo
  keyword_retry
  keyword_in
  keyword_do
  keyword_do_cond
  keyword_do_block
  keyword_do_LAMBDA
  keyword_return
  keyword_yield
  keyword_super
  keyword_self
  keyword_nil
  keyword_true
  keyword_false
  keyword_and
  keyword_or
  keyword_not
  modifier_if
  modifier_unless
  modifier_while
  modifier_until
  modifier_rescue
  keyword_alias
  keyword_defined
  keyword_BEGIN
  keyword_END
  keyword__LINE__
  keyword__FILE__
  keyword__ENCODING__

%token <val>   tIDENTIFIER tFID tGVAR tIVAR tCONSTANT tCVAR tLABEL
%token <val> tINTEGER tFLOAT tSTRING_CONTENT tCHAR
%token <val> tNTH_REF tBACK_REF
%token <val>  tREGEXP_END

%type <val> singleton strings string string1 xstring regexp
%type <val> string_contents xstring_contents regexp_contents string_content
%type <val> words qwords word_list qword_list word
%type <val> literal numeric dsym cpath
%type <val> top_compstmt top_stmts top_stmt
%type <val> bodystmt compstmt stmts stmt expr arg primary command command_call method_call
%type <val> expr_value arg_value primary_value
%type <val> if_tail opt_else case_body cases opt_rescue exc_list exc_var opt_ensure
%type <val> args call_args opt_call_args
%type <val> paren_args opt_paren_args
%type <val> command_args aref_args opt_block_arg block_arg var_ref var_lhs
%type <val> command_asgn mrhs superclass block_call block_command
%type <val> f_block_optarg f_block_opt
%type <val> f_arglist f_args f_arg f_arg_item f_optarg f_marg f_marg_list f_margs
%type <val> assoc_list assocs assoc undef_list backref string_dvar for_var
%type <val> block_param opt_block_param block_param_def f_opt
%type <val> bv_decls opt_bv_decl bvar
%type <val> lambda f_larglist lambda_body
%type <val> brace_block cmd_brace_block do_block lhs none fitem
%type <val> mlhs mlhs_head mlhs_basic mlhs_item mlhs_node mlhs_post mlhs_inner
%type <val>   fsym keyword_variable user_variable sym symbol operation operation2 operation3
%type <val>   cname fname op f_rest_arg f_block_arg opt_f_block_arg f_norm_arg f_bad_arg
/*
*/
%type <val> program reswords then do dot_or_colon

%token tUPLUS   /* unary+ */
%token tUMINUS    /* unary- */
%token tPOW   /* ** */
%token tCMP   /* <=> */
%token tEQ    /* == */
%token tEQQ   /* === */
%token tNEQ   /* != */
%token tGEQ   /* >= */
%token tLEQ   /* <= */
%token tANDOP tOROP /* && and || */
%token tMATCH tNMATCH /* =~ and !~ */
%token tDOT2 tDOT3  /* .. and ... */
%token tAREF tASET  /* [] and []= */
%token tLSHFT tRSHFT  /* << and >> */
%token tCOLON2    /* :: */
%token tCOLON3    /* :: at EXPR_BEG */
%token <val> tOP_ASGN /* +=, -=  etc. */
%token tASSOC   /* => */
%token tLPAREN    /* ( */
%token tLPAREN_ARG  /* ( */
%token tRPAREN    /* ) */
%token tLBRACK    /* [ */
%token tLBRACE    /* { */
%token tLBRACE_ARG  /* { */
%token tSTAR    /* * */
%token tAMPER   /* & */
%token tLAMBDA    /* -> */
%token tSYMBEG tSTRING_BEG tXSTRING_BEG tREGEXP_BEG tWORDS_BEG tQWORDS_BEG
%token tSTRING_DBEG tSTRING_DVAR tSTRING_END tLAMBEG

/*
 *  precedence table
 */

%nonassoc tLOWEST
%nonassoc tLBRACE_ARG

%nonassoc  modifier_if modifier_unless modifier_while modifier_until
%left  keyword_or keyword_and
%right keyword_not
%nonassoc keyword_defined
%right '=' tOP_ASGN
%left modifier_rescue
%right '?' ':'
%nonassoc tDOT2 tDOT3
%left  tOROP
%left  tANDOP
%nonassoc  tCMP tEQ tEQQ tNEQ tMATCH tNMATCH
%left  '>' tGEQ '<' tLEQ
%left  '|' '^'
%left  '&'
%left  tLSHFT tRSHFT
%left  '+' '-'
%left  '*' '/' '%'
%right tUMINUS_NUM tUMINUS
%right tPOW
%right '!' '~' tUPLUS

%nonassoc idNULL
%nonassoc idRespond_to
%nonassoc idIFUNC
%nonassoc idCFUNC
%nonassoc id_core_set_method_alias
%nonassoc id_core_set_variable_alias
%nonassoc id_core_undef_method
%nonassoc id_core_define_method
%nonassoc id_core_define_singleton_method
%nonassoc id_core_set_postexe

%token tLAST_TOKEN

%%
program   :  {
      lex_state = EXPR_BEG;
      local_push(0);
        }
      top_compstmt
        {
      $$ = $2;
      parser->result = dispatch1(program, $$);

      local_pop();
        }
    ;

top_compstmt  : top_stmts opt_terms
        {

      $$ = $1;
        }
    ;

top_stmts : none
                    {
      $$ = dispatch2(stmts_add, dispatch0(stmts_new),
              dispatch0(void_stmt));
        }
    | top_stmt
        {
      $$ = dispatch2(stmts_add, dispatch0(stmts_new), $1);
        }
    | top_stmts terms top_stmt
        {
      $$ = dispatch2(stmts_add, $1, $3);
        }
    | error top_stmt
        {
      $$ = remove_begin($2);
        }
    ;

top_stmt  : stmt
    | keyword_BEGIN
        {
      if (in_def || in_single) {
          yyerror("BEGIN in method");
      }
        }
      '{' top_compstmt '}'
        {
      $$ = dispatch1(BEGIN, $4);
        }
    ;

bodystmt  : compstmt
      opt_rescue
      opt_else
      opt_ensure
        {
      $$ = dispatch4(bodystmt,
               escape_Qundef($1),
               escape_Qundef($2),
               escape_Qundef($3),
               escape_Qundef($4));
        }
    ;

compstmt  : stmts opt_terms
        {

      $$ = $1;
        }
    ;

stmts   : none
                    {
      $$ = dispatch2(stmts_add, dispatch0(stmts_new),
              dispatch0(void_stmt));
        }
    | stmt
        {
      $$ = dispatch2(stmts_add, dispatch0(stmts_new), $1);
        }
    | stmts terms stmt
        {
      $$ = dispatch2(stmts_add, $1, $3);
        }
    | error stmt
        {
      $$ = remove_begin($2);
        }
    ;

stmt    : keyword_alias fitem {lex_state = EXPR_FNAME;} fitem
        {
      $$ = dispatch2(alias, $2, $4);
        }
    | keyword_alias tGVAR tGVAR
        {
      $$ = dispatch2(var_alias, $2, $3);
        }
    | keyword_alias tGVAR tBACK_REF
        {
      $$ = dispatch2(var_alias, $2, $3);
        }
    | keyword_alias tGVAR tNTH_REF
        {
      $$ = dispatch2(var_alias, $2, $3);
      $$ = dispatch1(alias_error, $$);
        }
    | keyword_undef undef_list
        {
      $$ = dispatch1(undef, $2);
        }
    | stmt modifier_if expr_value
        {
      $$ = dispatch2(if_mod, $3, $1);
        }
    | stmt modifier_unless expr_value
        {
      $$ = dispatch2(unless_mod, $3, $1);
        }
    | stmt modifier_while expr_value
        {
      $$ = dispatch2(while_mod, $3, $1);
        }
    | stmt modifier_until expr_value
        {
      $$ = dispatch2(until_mod, $3, $1);
        }
    | stmt modifier_rescue stmt
        {
      $$ = dispatch2(rescue_mod, $1, $3);
        }
    | keyword_END '{' compstmt '}'
        {
      if (in_def || in_single) {
          rb_warn0("END in method; use at_exit");
      }
      $$ = dispatch1(END, $3);
        }
    | command_asgn
    | mlhs '=' command_call
        {
      $$ = dispatch2(massign, $1, $3);
        }
    | var_lhs tOP_ASGN command_call
        {
      $$ = dispatch3(opassign, $1, $2, $3);
        }
    | primary_value '[' opt_call_args rbracket tOP_ASGN command_call
        {
      $$ = dispatch2(aref_field, $1, escape_Qundef($3));
      $$ = dispatch3(opassign, $$, $5, $6);
        }
    | primary_value '.' tIDENTIFIER tOP_ASGN command_call
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
      $$ = dispatch3(opassign, $$, $4, $5);
        }
    | primary_value '.' tCONSTANT tOP_ASGN command_call
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
      $$ = dispatch3(opassign, $$, $4, $5);
        }
    | primary_value tCOLON2 tCONSTANT tOP_ASGN command_call
        {
      $$ = dispatch2(const_path_field, $1, $3);
      $$ = dispatch3(opassign, $$, $4, $5);
      $$ = dispatch1(assign_error, $$);
        }
    | primary_value tCOLON2 tIDENTIFIER tOP_ASGN command_call
        {
      $$ = dispatch3(field, $1, redtree_intern("::"), $3);
      $$ = dispatch3(opassign, $$, $4, $5);
        }
    | backref tOP_ASGN command_call
        {
      $$ = dispatch2(assign, dispatch1(var_field, $1), $3);
      $$ = dispatch1(assign_error, $$);
        }
    | lhs '=' mrhs
        {
      $$ = dispatch2(assign, $1, $3);
        }
    | mlhs '=' arg_value
        {
      $$ = dispatch2(massign, $1, $3);
        }
    | mlhs '=' mrhs
        {
      $$ = dispatch2(massign, $1, $3);
        }
    | expr
    ;

command_asgn  : lhs '=' command_call
        {
      $$ = dispatch2(assign, $1, $3);
        }
    | lhs '=' command_asgn
        {
      $$ = dispatch2(assign, $1, $3);
        }
    ;


expr    : command_call
    | expr keyword_and expr
        {
      $$ = dispatch3(binary, $1, redtree_intern("and"), $3);
        }
    | expr keyword_or expr
        {
      $$ = dispatch3(binary, $1, redtree_intern("or"), $3);
        }
    | keyword_not opt_nl expr
        {
      $$ = dispatch2(unary, redtree_intern("not"), $3);
        }
    | '!' command_call
        {
      $$ = dispatch2(unary, redtree_id2sym('!'), $2);
        }
    | arg
    ;

expr_value  : expr
        {
      $$ = $1;
        }
    ;

command_call  : command
    | block_command
    ;

block_command : block_call
    | block_call '.' operation2 command_args
        {
      $$ = dispatch3(call, $1, redtree_id2sym('.'), $3);
      $$ = method_arg($$, $4);
        }
    | block_call tCOLON2 operation2 command_args
        {
      $$ = dispatch3(call, $1, redtree_intern("::"), $3);
      $$ = method_arg($$, $4);
        }
    ;

cmd_brace_block : tLBRACE_ARG
        {
      $<vars>1 = dyna_push();
        }
      opt_block_param
      compstmt
      '}'
        {
      $$ = dispatch2(brace_block, escape_Qundef($3), $4);

      dyna_pop($<vars>1);
        }
    ;

command   : operation command_args       %prec tLOWEST
        {
      $$ = dispatch2(command, $1, $2);
        }
    | operation command_args cmd_brace_block
        {
      $$ = dispatch2(command, $1, $2);
      $$ = method_add_block($$, $3);
        }
    | primary_value '.' operation2 command_args %prec tLOWEST
        {
      $$ = dispatch4(command_call, $1, redtree_id2sym('.'), $3, $4);
        }
    | primary_value '.' operation2 command_args cmd_brace_block
        {
      $$ = dispatch4(command_call, $1, redtree_id2sym('.'), $3, $4);
      $$ = method_add_block($$, $5);
       }
    | primary_value tCOLON2 operation2 command_args %prec tLOWEST
        {
      $$ = dispatch4(command_call, $1, redtree_intern("::"), $3, $4);
        }
    | primary_value tCOLON2 operation2 command_args cmd_brace_block
        {
      $$ = dispatch4(command_call, $1, redtree_intern("::"), $3, $4);
      $$ = method_add_block($$, $5);
       }
    | keyword_super command_args
        {
      $$ = dispatch1(super, $2);
        }
    | keyword_yield command_args
        {
      $$ = dispatch1(yield, $2);
        }
    | keyword_return call_args
        {
      $$ = dispatch1(return, $2);
        }
    | keyword_break call_args
        {
      $$ = dispatch1(break, $2);
        }
    | keyword_next call_args
        {
      $$ = dispatch1(next, $2);
        }
    ;

mlhs    : mlhs_basic
    | tLPAREN mlhs_inner rparen
        {
      $$ = dispatch1(mlhs_paren, $2);
        }
    ;

mlhs_inner  : mlhs_basic
    | tLPAREN mlhs_inner rparen
        {
      $$ = dispatch1(mlhs_paren, $2);
        }
    ;

mlhs_basic  : mlhs_head
        {
      $$ = $1;
        }
    | mlhs_head mlhs_item
        {
      $$ = mlhs_add($1, $2);
        }
    | mlhs_head tSTAR mlhs_node
        {
      $$ = mlhs_add_star($1, $3);
        }
    | mlhs_head tSTAR mlhs_node ',' mlhs_post
        {
      $1 = mlhs_add_star($1, $3);
      $$ = mlhs_add($1, $5);
        }
    | mlhs_head tSTAR
        {
      $$ = mlhs_add_star($1, Qnil);
        }
    | mlhs_head tSTAR ',' mlhs_post
        {
      $1 = mlhs_add_star($1, Qnil);
      $$ = mlhs_add($1, $4);
        }
    | tSTAR mlhs_node
        {
      $$ = mlhs_add_star(mlhs_new(), $2);
        }
    | tSTAR mlhs_node ',' mlhs_post
        {
      $2 = mlhs_add_star(mlhs_new(), $2);
      $$ = mlhs_add($2, $4);
        }
    | tSTAR
        {
      $$ = mlhs_add_star(mlhs_new(), Qnil);
        }
    | tSTAR ',' mlhs_post
        {
      $$ = mlhs_add_star(mlhs_new(), Qnil);
      $$ = mlhs_add($$, $3);
        }
    ;

mlhs_item : mlhs_node
    | tLPAREN mlhs_inner rparen
        {
      $$ = dispatch1(mlhs_paren, $2);
        }
    ;

mlhs_head : mlhs_item ','
        {
      $$ = mlhs_add(mlhs_new(), $1);
        }
    | mlhs_head mlhs_item ','
        {
      $$ = mlhs_add($1, $2);
        }
    ;

mlhs_post : mlhs_item
        {
      $$ = mlhs_add(mlhs_new(), $1);
        }
    | mlhs_post ',' mlhs_item
        {
      $$ = mlhs_add($1, $3);
        }
    ;

mlhs_node : user_variable
        {
      $$ = assignable($1, 0);
        }
    | keyword_variable
        {
            $$ = assignable($1, 0);
        }
    | primary_value '[' opt_call_args rbracket
        {
      $$ = dispatch2(aref_field, $1, escape_Qundef($3));
        }
    | primary_value '.' tIDENTIFIER
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
        }
    | primary_value tCOLON2 tIDENTIFIER
        {
      $$ = dispatch2(const_path_field, $1, $3);
        }
    | primary_value '.' tCONSTANT
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
        }
    | primary_value tCOLON2 tCONSTANT
        {
      if (in_def || in_single)
          yyerror("dynamic constant assignment");
      $$ = dispatch2(const_path_field, $1, $3);
        }
    | tCOLON3 tCONSTANT
        {
      $$ = dispatch1(top_const_field, $2);
        }
    | backref
        {
      $$ = dispatch1(var_field, $1);
      $$ = dispatch1(assign_error, $$);
        }
    ;

lhs   : user_variable
        {
      $$ = assignable($1, 0);
      $$ = dispatch1(var_field, $$);
        }
    | keyword_variable
        {
            $$ = assignable($1, 0);
            $$ = dispatch1(var_field, $$);
        }
    | primary_value '[' opt_call_args rbracket
        {
      $$ = dispatch2(aref_field, $1, escape_Qundef($3));
        }
    | primary_value '.' tIDENTIFIER
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
        }
    | primary_value tCOLON2 tIDENTIFIER
        {
      $$ = dispatch3(field, $1, redtree_intern("::"), $3);
        }
    | primary_value '.' tCONSTANT
        {
      $$ = dispatch3(field, $1, redtree_id2sym('.'), $3);
        }
    | primary_value tCOLON2 tCONSTANT
        {
      $$ = dispatch2(const_path_field, $1, $3);
      if (in_def || in_single) {
          $$ = dispatch1(assign_error, $$);
      }
        }
    | tCOLON3 tCONSTANT
        {
      $$ = dispatch1(top_const_field, $2);
      if (in_def || in_single) {
          $$ = dispatch1(assign_error, $$);
      }
        }
    | backref
        {
      $$ = dispatch1(assign_error, $1);
        }
    ;

cname   : tIDENTIFIER
        {
      $$ = dispatch1(class_name_error, $1);
        }
    | tCONSTANT
    ;

cpath   : tCOLON3 cname
        {
      $$ = dispatch1(top_const_ref, $2);
        }
    | cname
        {
      $$ = dispatch1(const_ref, $1);
        }
    | primary_value tCOLON2 cname
        {
      $$ = dispatch2(const_path_ref, $1, $3);
        }
    ;

fname   : tIDENTIFIER
    | tCONSTANT
    | tFID
    | op
        {
      lex_state = EXPR_ENDFN;
      $$ = $1;
        }
    | reswords
        {
      lex_state = EXPR_ENDFN;
      $$ = $1;
        }
    ;

fsym    : fname
    | symbol
    ;

fitem   : fsym
        {
      $$ = dispatch1(symbol_literal, $1);
        }
    | dsym
    ;

undef_list  : fitem
        {
      $$ = rb_ary_new3(1, $1);
        }
    | undef_list ',' {lex_state = EXPR_FNAME;} fitem
        {
      rb_ary_push($1, $4);
        }
    ;

op    : '|'   
    | '^'     
    | '&'     
    | tCMP    
    | tEQ     
    | tEQQ    
    | tMATCH  
    | tNMATCH 
    | '>'     
    | tGEQ    
    | '<'     
    | tLEQ    
    | tNEQ    
    | tLSHFT  
    | tRSHFT  
    | '+'     
    | '-'     
    | '*'     
    | tSTAR   
    | '/'     
    | '%'     
    | tPOW    
    | '!'     
    | '~'     
    | tUPLUS  
    | tUMINUS 
    | tAREF   
    | tASET   
    | '`'     
    ;

reswords  : keyword__LINE__ | keyword__FILE__ | keyword__ENCODING__
    | keyword_BEGIN | keyword_END
    | keyword_alias | keyword_and | keyword_begin
    | keyword_break | keyword_case | keyword_class | keyword_def
    | keyword_defined | keyword_do | keyword_else | keyword_elsif
    | keyword_end | keyword_ensure | keyword_false
    | keyword_for | keyword_in | keyword_module | keyword_next
    | keyword_nil | keyword_not | keyword_or | keyword_redo
    | keyword_rescue | keyword_retry | keyword_return | keyword_self
    | keyword_super | keyword_then | keyword_true | keyword_undef
    | keyword_when | keyword_yield | keyword_if | keyword_unless
    | keyword_while | keyword_until
    ;

arg   : lhs '=' arg
        {
      $$ = dispatch2(assign, $1, $3);
        }
    | lhs '=' arg modifier_rescue arg
        {
      $$ = dispatch2(assign, $1, dispatch2(rescue_mod, $3, $5));
        }
    | var_lhs tOP_ASGN arg
        {
      $$ = dispatch3(opassign, $1, $2, $3);
        }
    | var_lhs tOP_ASGN arg modifier_rescue arg
        {
      $3 = dispatch2(rescue_mod, $3, $5);
      $$ = dispatch3(opassign, $1, $2, $3);
        }
    | primary_value '[' opt_call_args rbracket tOP_ASGN arg
        {
      $1 = dispatch2(aref_field, $1, escape_Qundef($3));
      $$ = dispatch3(opassign, $1, $5, $6);
        }
    | primary_value '.' tIDENTIFIER tOP_ASGN arg
        {
      $1 = dispatch3(field, $1, redtree_id2sym('.'), $3);
      $$ = dispatch3(opassign, $1, $4, $5);
        }
    | primary_value '.' tCONSTANT tOP_ASGN arg
        {
      $1 = dispatch3(field, $1, redtree_id2sym('.'), $3);
      $$ = dispatch3(opassign, $1, $4, $5);
        }
    | primary_value tCOLON2 tIDENTIFIER tOP_ASGN arg
        {
      $1 = dispatch3(field, $1, redtree_intern("::"), $3);
      $$ = dispatch3(opassign, $1, $4, $5);
        }
    | primary_value tCOLON2 tCONSTANT tOP_ASGN arg
        {
      $$ = dispatch2(const_path_field, $1, $3);
      $$ = dispatch3(opassign, $$, $4, $5);
      $$ = dispatch1(assign_error, $$);
        }
    | tCOLON3 tCONSTANT tOP_ASGN arg
        {
      $$ = dispatch1(top_const_field, $2);
      $$ = dispatch3(opassign, $$, $3, $4);
      $$ = dispatch1(assign_error, $$);
        }
    | backref tOP_ASGN arg
        {
      $$ = dispatch1(var_field, $1);
      $$ = dispatch3(opassign, $$, $2, $3);
      $$ = dispatch1(assign_error, $$);
        }
    | arg tDOT2 arg
        {
      $$ = dispatch2(dot2, $1, $3);
        }
    | arg tDOT3 arg
        {
      $$ = dispatch2(dot3, $1, $3);
        }
    | arg '+' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('+'), $3);
        }
    | arg '-' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('-'), $3);
        }
    | arg '*' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('*'), $3);
        }
    | arg '/' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('/'), $3);
        }
    | arg '%' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('%'), $3);
        }
    | arg tPOW arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("**"), $3);
        }
    | tUMINUS_NUM tINTEGER tPOW arg
        {
      $$ = dispatch3(binary, $2, redtree_intern("**"), $4);
      $$ = dispatch2(unary, redtree_intern("-@"), $$);
        }
    | tUMINUS_NUM tFLOAT tPOW arg
        {
      $$ = dispatch3(binary, $2, redtree_intern("**"), $4);
      $$ = dispatch2(unary, redtree_intern("-@"), $$);
        }
    | tUPLUS arg
        {
      $$ = dispatch2(unary, redtree_intern("+@"), $2);
        }
    | tUMINUS arg
        {
      $$ = dispatch2(unary, redtree_intern("-@"), $2);
        }
    | arg '|' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('|'), $3);
        }
    | arg '^' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('^'), $3);
        }
    | arg '&' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('&'), $3);
        }
    | arg tCMP arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("<=>"), $3);
        }
    | arg '>' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('>'), $3);
        }
    | arg tGEQ arg
        {
      $$ = dispatch3(binary, $1, redtree_intern(">="), $3);
        }
    | arg '<' arg
        {
      $$ = dispatch3(binary, $1, ID2SYM('<'), $3);
        }
    | arg tLEQ arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("<="), $3);
        }
    | arg tEQ arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("=="), $3);
        }
    | arg tEQQ arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("==="), $3);
        }
    | arg tNEQ arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("!="), $3);
        }
    | arg tMATCH arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("=~"), $3);
        }
    | arg tNMATCH arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("!~"), $3);
        }
    | '!' arg
        {
      $$ = dispatch2(unary, ID2SYM('!'), $2);
        }
    | '~' arg
        {
      $$ = dispatch2(unary, ID2SYM('~'), $2);
        }
    | arg tLSHFT arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("<<"), $3);
        }
    | arg tRSHFT arg
        {
      $$ = dispatch3(binary, $1, redtree_intern(">>"), $3);
        }
    | arg tANDOP arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("&&"), $3);
        }
    | arg tOROP arg
        {
      $$ = dispatch3(binary, $1, redtree_intern("||"), $3);
        }
    | keyword_defined opt_nl {in_defined = 1;} arg
        {
      in_defined = 0;
      $$ = dispatch1(defined, $4);
        }
    | arg '?' arg opt_nl ':' arg
        {
      $$ = dispatch3(ifop, $1, $3, $6);
        }
    | primary
        {
      $$ = $1;
        }
    ;

arg_value : arg
        {
      $$ = $1;
        }
    ;

aref_args : none
    | args trailer
        {
      $$ = $1;
        }
    | args ',' assocs trailer
        {
      $$ = arg_add_assocs($1, $3);
        }
    | assocs trailer
        {
      $$ = arg_add_assocs(arg_new(), $1);
        }
    ;

paren_args  : '(' opt_call_args rparen
        {
      $$ = dispatch1(arg_paren, escape_Qundef($2));
        }
    ;

opt_paren_args  : none
    | paren_args
    ;

opt_call_args : none
    | call_args
    | args ','
        {
          $$ = $1;
        }
    | args ',' assocs ','
        {
      $$ = arg_add_assocs($1, $3);
        }
    | assocs ','
        {
      $$ = arg_add_assocs(arg_new(), $1);
        }
    ;

call_args : command
        {
      $$ = arg_add(arg_new(), $1);
        }
    | args opt_block_arg
        {
      $$ = arg_add_optblock($1, $2);
        }
    | assocs opt_block_arg
        {
      $$ = arg_add_assocs(arg_new(), $1);
      $$ = arg_add_optblock($$, $2);
        }
    | args ',' assocs opt_block_arg
        {
      $$ = arg_add_optblock(arg_add_assocs($1, $3), $4);
        }
    | block_arg
/*
*/
        {
      $$ = arg_add_block(arg_new(), $1);
        }

    ;

command_args  :  {
      $<val>$ = cmdarg_stack;
      CMDARG_PUSH(1);
        }
      call_args
        {
      /* CMDARG_POP() */
      cmdarg_stack = $<val>1;
      $$ = $2;
        }
    ;

block_arg : tAMPER arg_value
        {
      $$ = $2;
        }
    ;

opt_block_arg : ',' block_arg
        {
      $$ = $2;
        }
    | none
        {
      $$ = 0;
        }
    ;

args    : arg_value
        {
      $$ = arg_add(arg_new(), $1);
        }
    | tSTAR arg_value
        {
      $$ = arg_add_star(arg_new(), $2);
        }
    | args ',' arg_value
        {
      $$ = arg_add($1, $3);
        }
    | args ',' tSTAR arg_value
        {
      $$ = arg_add_star($1, $4);
        }
    ;

mrhs    : args ',' arg_value
        {
      $$ = mrhs_add(args2mrhs($1), $3);
        }
    | args ',' tSTAR arg_value
        {
      $$ = mrhs_add_star(args2mrhs($1), $4);
        }
    | tSTAR arg_value
        {
      $$ = mrhs_add_star(mrhs_new(), $2);
        }
    ;

primary   : literal
    | strings
    | xstring
    | regexp
    | words
    | qwords
    | var_ref
    | backref
    | tFID
        {
      $$ = method_arg(dispatch1(fcall, $1), arg_new());
        }
    | k_begin
        {
        }
      bodystmt
      k_end
        {
      $$ = dispatch1(begin, $3);
        }
    | tLPAREN_ARG expr {lex_state = EXPR_ENDARG;} rparen
        {
      rb_warning0("(...) interpreted as grouped expression");
      $$ = dispatch1(paren, $2);
        }
    | tLPAREN compstmt ')'
        {
      $$ = dispatch1(paren, $2);
        }
    | primary_value tCOLON2 tCONSTANT
        {
      $$ = dispatch2(const_path_ref, $1, $3);
        }
    | tCOLON3 tCONSTANT
        {
      $$ = dispatch1(top_const_ref, $2);
        }
    | tLBRACK aref_args ']'
        {
      $$ = dispatch1(array, escape_Qundef($2));
        }
    | tLBRACE assoc_list '}'
        {
      $$ = dispatch1(hash, escape_Qundef($2));
        }
    | keyword_return
        {
      $$ = dispatch0(return0);
        }
    | keyword_yield '(' call_args rparen
        {
      $$ = dispatch1(yield, dispatch1(paren, $3));
        }
    | keyword_yield '(' rparen
        {
      $$ = dispatch1(yield, dispatch1(paren, arg_new()));
        }
    | keyword_yield
        {
      $$ = dispatch0(yield0);
        }
    | keyword_defined opt_nl '(' {in_defined = 1;} expr rparen
        {
      in_defined = 0;
      $$ = dispatch1(defined, $5);
        }
    | keyword_not '(' expr rparen
        {
      $$ = dispatch2(unary, redtree_intern("not"), $3);
        }
    | keyword_not '(' rparen
        {
      $$ = dispatch2(unary, redtree_intern("not"), Qnil);
        }
    | operation brace_block
        {
      $$ = method_arg(dispatch1(fcall, $1), arg_new());
      $$ = method_add_block($$, $2);
        }
    | method_call
    | method_call brace_block
        {
      $$ = method_add_block($1, $2);
        }
    | tLAMBDA lambda
        {
      $$ = $2;
        }
    | k_if expr_value then
      compstmt
      if_tail
      k_end
        {
      $$ = dispatch3(if, $2, $4, escape_Qundef($5));
        }
    | k_unless expr_value then
      compstmt
      opt_else
      k_end
        {
      $$ = dispatch3(unless, $2, $4, escape_Qundef($5));
        }
    | k_while {COND_PUSH(1);} expr_value do {COND_POP();}
      compstmt
      k_end
        {
      $$ = dispatch2(while, $3, $6);
        }
    | k_until {COND_PUSH(1);} expr_value do {COND_POP();}
      compstmt
      k_end
        {
      $$ = dispatch2(until, $3, $6);
        }
    | k_case expr_value opt_terms
      case_body
      k_end
        {
      $$ = dispatch2(case, $2, $4);
        }
    | k_case opt_terms case_body k_end
        {
      $$ = dispatch2(case, Qnil, $3);
        }
    | k_for for_var keyword_in
      {COND_PUSH(1);}
      expr_value do
      {COND_POP();}
      compstmt
      k_end
        {
      $$ = dispatch3(for, $2, $5, $8);
        }
    | k_class cpath superclass
        {
      if (in_def || in_single)
          yyerror("class definition in method body");
      local_push(0);
        }
      bodystmt
      k_end
        {
      $$ = dispatch3(class, $2, $3, $5);

      local_pop();
        }
    | k_class tLSHFT expr
        {
      $<num>$ = in_def;
      in_def = 0;
        }
      term
        {
      $<num>$ = in_single;
      in_single = 0;
      local_push(0);
        }
      bodystmt
      k_end
        {
      $$ = dispatch2(sclass, $3, $7);

      local_pop();
      in_def = $<num>4;
      in_single = $<num>6;
        }
    | k_module cpath
        {
      if (in_def || in_single)
          yyerror("module definition in method body");
      local_push(0);
        }
      bodystmt
      k_end
        {
      $$ = dispatch2(module, $2, $4);

      local_pop();
        }
    | k_def fname
        {
      $<id>$ = cur_mid;
      cur_mid = $2;
      in_def++;
      local_push(0);
        }
      f_arglist
      bodystmt
      k_end
        {
      $$ = dispatch3(def, $2, $4, $5);

      local_pop();
      in_def--;
      cur_mid = $<id>3;
        }
    | k_def singleton dot_or_colon {lex_state = EXPR_FNAME;} fname
        {
      in_single++;
      lex_state = EXPR_ENDFN; /* force for args */
      local_push(0);
        }
      f_arglist
      bodystmt
      k_end
        {
      $$ = dispatch5(defs, $2, $3, $5, $7, $8);

      local_pop();
      in_single--;
        }
    | keyword_break
        {
      $$ = dispatch1(break, arg_new());
        }
    | keyword_next
        {
      $$ = dispatch1(next, arg_new());
        }
    | keyword_redo
        {
      $$ = dispatch0(redo);
        }
    | keyword_retry
        {
      $$ = dispatch0(retry);
        }
    ;

primary_value : primary
        {
      $$ = $1;
        }
    ;

k_begin   : keyword_begin
        {
      token_info_push("begin");
        }
    ;

k_if    : keyword_if
        {
      token_info_push("if");
        }
    ;

k_unless  : keyword_unless
        {
      token_info_push("unless");
        }
    ;

k_while   : keyword_while
        {
      token_info_push("while");
        }
    ;

k_until   : keyword_until
        {
      token_info_push("until");
        }
    ;

k_case    : keyword_case
        {
      token_info_push("case");
        }
    ;

k_for   : keyword_for
        {
      token_info_push("for");
        }
    ;

k_class   : keyword_class
        {
      token_info_push("class");
        }
    ;

k_module  : keyword_module
        {
      token_info_push("module");
        }
    ;

k_def   : keyword_def
        {
      token_info_push("def");
        }
    ;

k_end   : keyword_end
        {
      token_info_pop("end");
        }
    ;

then    : term
/*
*/
        { $$ = Qnil; }

    | keyword_then
    | term keyword_then
/*
*/
        { $$ = $2; }

    ;

do    : term
/*
*/
        { $$ = Qnil; }

    | keyword_do_cond
    ;

if_tail   : opt_else
    | keyword_elsif expr_value then
      compstmt
      if_tail
        {
      $$ = dispatch3(elsif, $2, $4, escape_Qundef($5));
        }
    ;

opt_else  : none
    | keyword_else compstmt
        {
      $$ = dispatch1(else, $2);
        }
    ;

for_var   : lhs
    | mlhs
    ;

f_marg    : f_norm_arg
        {
      $$ = assignable($1, 0);
      $$ = dispatch1(mlhs_paren, $$);
        }
    | tLPAREN f_margs rparen
        {
      $$ = dispatch1(mlhs_paren, $2);
        }
    ;

f_marg_list : f_marg
        {
      $$ = mlhs_add(mlhs_new(), $1);
        }
    | f_marg_list ',' f_marg
        {
      $$ = mlhs_add($1, $3);
        }
    ;

f_margs   : f_marg_list
        {
      $$ = $1;
        }
    | f_marg_list ',' tSTAR f_norm_arg
        {
      $$ = assignable($4, 0);
      $$ = mlhs_add_star($1, $$);
        }
    | f_marg_list ',' tSTAR f_norm_arg ',' f_marg_list
        {
      $$ = assignable($4, 0);
      $$ = mlhs_add_star($1, $$);
        }
    | f_marg_list ',' tSTAR
        {
      $$ = mlhs_add_star($1, Qnil);
        }
    | f_marg_list ',' tSTAR ',' f_marg_list
        {
      $$ = mlhs_add_star($1, $5);
        }
    | tSTAR f_norm_arg
        {
      $$ = assignable($2, 0);
      $$ = mlhs_add_star(mlhs_new(), $$);
        }
    | tSTAR f_norm_arg ',' f_marg_list
        {
      $$ = assignable($2, 0);
                $$ = mlhs_add_star($$, $4);
        }
    | tSTAR
        {
      $$ = mlhs_add_star(mlhs_new(), Qnil);
        }
    | tSTAR ',' f_marg_list
        {
      $$ = mlhs_add_star(mlhs_new(), Qnil);
        }
    ;

block_param : f_arg ',' f_block_optarg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, $5, Qnil, escape_Qundef($6));
        }
    | f_arg ',' f_block_optarg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, $5, $7, escape_Qundef($8));
        }
    | f_arg ',' f_block_optarg opt_f_block_arg
        {
      $$ = params_new($1, $3, Qnil, Qnil, escape_Qundef($4));
        }
    | f_arg ',' f_block_optarg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, Qnil, $5, escape_Qundef($6));
        }
    | f_arg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil, $3, Qnil, escape_Qundef($4));
        }
    | f_arg ','
        {
      $$ = params_new($1, Qnil, Qnil, Qnil, Qnil);
                        dispatch1(excessed_comma, $$);
        }
    | f_arg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil, $3, $5, escape_Qundef($6));
        }
    | f_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil,Qnil, Qnil, escape_Qundef($2));
        }
    | f_block_optarg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, $3, Qnil, escape_Qundef($4));
        }
    | f_block_optarg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, $3, $5, escape_Qundef($6));
        }
    | f_block_optarg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, Qnil, Qnil,escape_Qundef($2));
        }
    | f_block_optarg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, Qnil, $3, escape_Qundef($4));
        }
    | f_rest_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, Qnil, $1, Qnil, escape_Qundef($2));
        }
    | f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, Qnil, $1, $3, escape_Qundef($4));
        }
    | f_block_arg
        {
      $$ = params_new(Qnil, Qnil, Qnil, Qnil, $1);
        }
    ;

opt_block_param : none
    | block_param_def
        {
      command_start = TRUE;
        }
    ;

block_param_def : '|' opt_bv_decl '|'
        {
      $$ = blockvar_new(params_new(Qnil,Qnil,Qnil,Qnil,Qnil),
                                          escape_Qundef($2));
        }
    | tOROP
        {
      $$ = blockvar_new(params_new(Qnil,Qnil,Qnil,Qnil,Qnil),
                                          Qnil);
        }
    | '|' block_param opt_bv_decl '|'
        {
      $$ = blockvar_new(escape_Qundef($2), escape_Qundef($3));
        }
    ;


opt_bv_decl : none
    | ';' bv_decls
        {
      $$ = $2;
        }
    ;

bv_decls  : bvar
/*
*/
        {
      $$ = rb_ary_new3(1, $1);
        }

    | bv_decls ',' bvar
/*
*/
        {
      rb_ary_push($$, $3);
        }

    ;

bvar    : tIDENTIFIER
        {
      new_bv(get_id($1));
      $$ = get_value($1);
        }
    | f_bad_arg
        {
      $$ = 0;
        }
    ;

lambda    :   {
      $<vars>$ = dyna_push();
        }
        {
      $<num>$ = lpar_beg;
      lpar_beg = ++paren_nest;
        }
      f_larglist
      lambda_body
        {
      lpar_beg = $<num>2;
      $$ = dispatch2(lambda, $3, $4);

      dyna_pop($<vars>1);
        }
    ;

f_larglist  : '(' f_args opt_bv_decl rparen
        {
      $$ = dispatch1(paren, $2);
        }
    | f_args
        {
      $$ = $1;
        }
    ;

lambda_body : tLAMBEG compstmt '}'
        {
      $$ = $2;
        }
    | keyword_do_LAMBDA compstmt keyword_end
        {
      $$ = $2;
        }
    ;

do_block  : keyword_do_block
        {
      $<vars>1 = dyna_push();
        }
      opt_block_param
      compstmt
      keyword_end
        {
      $$ = dispatch2(do_block, escape_Qundef($3), $4);

      dyna_pop($<vars>1);
        }
    ;

block_call  : command do_block
        {
      $$ = method_add_block($1, $2);
        }
    | block_call '.' operation2 opt_paren_args
        {
      $$ = dispatch3(call, $1, redtree_id2sym('.'), $3);
      $$ = method_optarg($$, $4);
        }
    | block_call tCOLON2 operation2 opt_paren_args
        {
      $$ = dispatch3(call, $1, redtree_intern("::"), $3);
      $$ = method_optarg($$, $4);
        }
    ;

method_call : operation paren_args
        {
      $$ = method_arg(dispatch1(fcall, $1), $2);
        }
    | primary_value '.' operation2 opt_paren_args
        {
      $$ = dispatch3(call, $1, redtree_id2sym('.'), $3);
      $$ = method_optarg($$, $4);
        }
    | primary_value tCOLON2 operation2 paren_args
        {
      $$ = dispatch3(call, $1, redtree_id2sym('.'), $3);
      $$ = method_optarg($$, $4);
        }
    | primary_value tCOLON2 operation3
        {
      $$ = dispatch3(call, $1, redtree_intern("::"), $3);
        }
    | primary_value '.' paren_args
        {
      $$ = dispatch3(call, $1, redtree_id2sym('.'),
               redtree_intern("call"));
      $$ = method_optarg($$, $3);
        }
    | primary_value tCOLON2 paren_args
        {
      $$ = dispatch3(call, $1, redtree_intern("::"),
               redtree_intern("call"));
      $$ = method_optarg($$, $3);
        }
    | keyword_super paren_args
        {
      $$ = dispatch1(super, $2);
        }
    | keyword_super
        {
      $$ = dispatch0(zsuper);
        }
    | primary_value '[' opt_call_args rbracket
        {
      $$ = dispatch2(aref, $1, escape_Qundef($3));
        }
    ;

brace_block : '{'
        {
      $<vars>1 = dyna_push();
        }
      opt_block_param
      compstmt '}'
        {
      $$ = dispatch2(brace_block, escape_Qundef($3), $4);

      dyna_pop($<vars>1);
        }
    | keyword_do
        {
      $<vars>1 = dyna_push();
        }
      opt_block_param
      compstmt keyword_end
        {
      $$ = dispatch2(do_block, escape_Qundef($3), $4);

      dyna_pop($<vars>1);
        }
    ;

case_body : keyword_when args then
      compstmt
      cases
        {
      $$ = dispatch3(when, $2, $4, escape_Qundef($5));
        }
    ;

cases   : opt_else
    | case_body
    ;

opt_rescue  : keyword_rescue exc_list exc_var then
      compstmt
      opt_rescue
        {
      $$ = dispatch4(rescue,
               escape_Qundef($2),
               escape_Qundef($3),
               escape_Qundef($5),
               escape_Qundef($6));
        }
    | none
    ;

exc_list  : arg_value
        {
      $$ = rb_ary_new3(1, $1);
        }
    | mrhs
        {
      $$ = $1;
        }
    | none
    ;

exc_var   : tASSOC lhs
        {
      $$ = $2;
        }
    | none
    ;

opt_ensure  : keyword_ensure compstmt
        {
      $$ = dispatch1(ensure, $2);
        }
    | none
    ;

literal   : numeric
    | symbol
        {
      $$ = dispatch1(symbol_literal, $1);
        }
    | dsym
    ;

strings   : string
        {
      $$ = $1;
        }
    ;

string    : tCHAR
    | string1
    | string string1
        {
      $$ = dispatch2(string_concat, $1, $2);
        }
    ;

string1   : tSTRING_BEG string_contents tSTRING_END
        {
      $$ = dispatch1(string_literal, $2);
        }
    ;

xstring   : tXSTRING_BEG xstring_contents tSTRING_END
        {
      $$ = dispatch1(xstring_literal, $2);
        }
    ;

regexp    : tREGEXP_BEG regexp_contents tREGEXP_END
        {
      $$ = dispatch2(regexp_literal, $2, $3);
        }
    ;

words   : tWORDS_BEG ' ' tSTRING_END
        {
      $$ = dispatch0(words_new);
      $$ = dispatch1(array, $$);
        }
    | tWORDS_BEG word_list tSTRING_END
        {
      $$ = dispatch1(array, $2);
        }
    ;

word_list : /* none */
        {
      $$ = dispatch0(words_new);
        }
    | word_list word ' '
        {
      $$ = dispatch2(words_add, $1, $2);
        }
    ;

word    : string_content
/*
*/
        {
      $$ = dispatch0(word_new);
      $$ = dispatch2(word_add, $$, $1);
        }

    | word string_content
        {
      $$ = dispatch2(word_add, $1, $2);
        }
    ;

qwords    : tQWORDS_BEG ' ' tSTRING_END
        {
      $$ = dispatch0(qwords_new);
      $$ = dispatch1(array, $$);
        }
    | tQWORDS_BEG qword_list tSTRING_END
        {
      $$ = dispatch1(array, $2);
        }
    ;

qword_list  : /* none */
        {
      $$ = dispatch0(qwords_new);
        }
    | qword_list tSTRING_CONTENT ' '
        {
      $$ = dispatch2(qwords_add, $1, $2);
        }
    ;

string_contents : /* none */
        {
      $$ = dispatch0(string_content);
        }
    | string_contents string_content
        {
      $$ = dispatch2(string_add, $1, $2);
        }
    ;

xstring_contents: /* none */
        {
      $$ = dispatch0(xstring_new);
        }
    | xstring_contents string_content
        {
      $$ = dispatch2(xstring_add, $1, $2);
        }
    ;

regexp_contents: /* none */
        {
      $$ = dispatch0(regexp_new);
        }
    | regexp_contents string_content
        {
      $$ = dispatch2(regexp_add, $1, $2);
        }
    ;

string_content  : tSTRING_CONTENT
    | tSTRING_DVAR
        {
      $<node>$ = lex_strterm;
      lex_strterm = 0;
      lex_state = EXPR_BEG;
        }
      string_dvar
        {
      lex_strterm = $<node>2;
      $$ = dispatch1(string_dvar, $3);
        }
    | tSTRING_DBEG
        {
      $<val>1 = cond_stack;
      $<val>$ = cmdarg_stack;
      cond_stack = 0;
      cmdarg_stack = 0;
        }
        {
      $<node>$ = lex_strterm;
      lex_strterm = 0;
      lex_state = EXPR_BEG;
        }
      compstmt '}'
        {
      cond_stack = $<val>1;
      cmdarg_stack = $<val>2;
      lex_strterm = $<node>3;
      $$ = dispatch1(string_embexpr, $4);
        }
    ;

string_dvar : tGVAR
        {
      $$ = dispatch1(var_ref, $1);
        }
    | tIVAR
        {
      $$ = dispatch1(var_ref, $1);
        }
    | tCVAR
        {
      $$ = dispatch1(var_ref, $1);
        }
    | backref
    ;

symbol    : tSYMBEG sym
        {
      lex_state = EXPR_END;
      $$ = dispatch1(symbol, $2);
        }
    ;

sym   : fname
    | tIVAR
    | tGVAR
    | tCVAR
    ;

dsym    : tSYMBEG xstring_contents tSTRING_END
        {
      lex_state = EXPR_END;
      $$ = dispatch1(dyna_symbol, $2);
        }
    ;

numeric   : tINTEGER
    | tFLOAT
    | tUMINUS_NUM tINTEGER         %prec tLOWEST
        {
      $$ = dispatch2(unary, redtree_intern("-@"), $2);
        }
    | tUMINUS_NUM tFLOAT         %prec tLOWEST
        {
      $$ = dispatch2(unary, redtree_intern("-@"), $2);
        }
    ;

user_variable : tIDENTIFIER
    | tIVAR
    | tGVAR
    | tCONSTANT
    | tCVAR
    ;

keyword_variable: keyword_nil
    | keyword_self
    | keyword_true
    | keyword_false
    | keyword__FILE__
    | keyword__LINE__
    | keyword__ENCODING__
    ;

var_ref   : user_variable
        {
      if (id_is_var(get_id($1))) {
          $$ = dispatch1(var_ref, $1);
      }
      else {
          $$ = dispatch1(vcall, $1);
      }
        }
    | keyword_variable
        {
      $$ = dispatch1(var_ref, $1);
        }
    ;

var_lhs   : user_variable
        {
      $$ = assignable($1, 0);
      $$ = dispatch1(var_field, $$);
        }
    | keyword_variable
        {
            $$ = assignable($1, 0);
      $$ = dispatch1(var_field, $$);
        }
    ;

backref   : tNTH_REF
    | tBACK_REF
    ;

superclass  : term
        {
      $$ = Qnil;
        }
    | '<'
        {
      lex_state = EXPR_BEG;
        }
      expr_value term
        {
      $$ = $3;
        }
    | error term
        {
      yyerrok;
      $$ = Qnil;
        }
    ;

f_arglist : '(' f_args rparen
        {
      $$ = dispatch1(paren, $2);

      lex_state = EXPR_BEG;
      command_start = TRUE;
        }
    | f_args term
        {
      $$ = $1;
        }
    ;

f_args    : f_arg ',' f_optarg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, $5, Qnil, escape_Qundef($6));
        }
    | f_arg ',' f_optarg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, $5, $7, escape_Qundef($8));
        }
    | f_arg ',' f_optarg opt_f_block_arg
        {
      $$ = params_new($1, $3, Qnil, Qnil, escape_Qundef($4));
        }
    | f_arg ',' f_optarg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, $3, Qnil, $5, escape_Qundef($6));
        }
    | f_arg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil, $3, Qnil, escape_Qundef($4));
        }
    | f_arg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil, $3, $5, escape_Qundef($6));
        }
    | f_arg opt_f_block_arg
        {
      $$ = params_new($1, Qnil, Qnil, Qnil,escape_Qundef($2));
        }
    | f_optarg ',' f_rest_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, $3, Qnil, escape_Qundef($4));
        }
    | f_optarg ',' f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, $3, $5, escape_Qundef($6));
        }
    | f_optarg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, Qnil, Qnil,escape_Qundef($2));
        }
    | f_optarg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, $1, Qnil, $3, escape_Qundef($4));
        }
    | f_rest_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, Qnil, $1, Qnil,escape_Qundef($2));
        }
    | f_rest_arg ',' f_arg opt_f_block_arg
        {
      $$ = params_new(Qnil, Qnil, $1, $3, escape_Qundef($4));
        }
    | f_block_arg
        {
      $$ = params_new(Qnil, Qnil, Qnil, Qnil, $1);
        }
    | /* none */
        {
      $$ = params_new(Qnil, Qnil, Qnil, Qnil, Qnil);
        }
    ;

f_bad_arg : tCONSTANT
        {
      $$ = dispatch1(param_error, $1);
        }
    | tIVAR
        {
      $$ = dispatch1(param_error, $1);
        }
    | tGVAR
        {
      $$ = dispatch1(param_error, $1);
        }
    | tCVAR
        {
      $$ = dispatch1(param_error, $1);
        }
    ;

f_norm_arg  : f_bad_arg
    | tIDENTIFIER
        {
      formal_argument(get_id($1));
      $$ = $1;
        }
    ;

f_arg_item  : f_norm_arg
        {
      arg_var(get_id($1));
      $$ = get_value($1);
        }
    | tLPAREN f_margs rparen
        {
      ID tid = internal_id();
      arg_var(tid);

      $$ = dispatch1(mlhs_paren, $2);
        }
    ;

f_arg   : f_arg_item
/*
*/
        {
      $$ = rb_ary_new3(1, $1);
        }

    | f_arg ',' f_arg_item
        {
      $$ = rb_ary_push($1, $3);
        }
    ;

f_opt   : tIDENTIFIER '=' arg_value
        {
      arg_var(formal_argument(get_id($1)));
      $$ = assignable($1, $3);
      $$ = rb_assoc_new($$, $3);
        }
    ;

f_block_opt : tIDENTIFIER '=' primary_value
        {
      arg_var(formal_argument(get_id($1)));
      $$ = assignable($1, $3);
      $$ = rb_assoc_new($$, $3);
        }
    ;

f_block_optarg  : f_block_opt
        {
      $$ = rb_ary_new3(1, $1);
        }
    | f_block_optarg ',' f_block_opt
        {
      $$ = rb_ary_push($1, $3);
        }
    ;

f_optarg  : f_opt
        {
      $$ = rb_ary_new3(1, $1);
        }
    | f_optarg ',' f_opt
        {
      $$ = rb_ary_push($1, $3);
        }
    ;

restarg_mark  : '*'
    | tSTAR
    ;

f_rest_arg  : restarg_mark tIDENTIFIER
        {
      arg_var(shadowing_lvar(get_id($2)));
      $$ = dispatch1(rest_param, $2);
        }
    | restarg_mark
        {
      $$ = dispatch1(rest_param, Qnil);
        }
    ;

blkarg_mark : '&'
    | tAMPER
    ;

f_block_arg : blkarg_mark tIDENTIFIER
        {
      arg_var(shadowing_lvar(get_id($2)));
      $$ = dispatch1(blockarg, $2);
        }
    ;

opt_f_block_arg : ',' f_block_arg
        {
      $$ = $2;
        }
    | none
        {
      $$ = Qundef;
        }
    ;

singleton : var_ref
        {
      $$ = $1;
        }
    | '(' {lex_state = EXPR_BEG;} expr rparen
        {
      $$ = dispatch1(paren, $3);
        }
    ;

assoc_list  : none
    | assocs trailer
        {
      $$ = dispatch1(assoclist_from_args, $1);
        }
    ;

assocs    : assoc
/*
*/
        {
      $$ = rb_ary_new3(1, $1);
        }

    | assocs ',' assoc
        {
      $$ = rb_ary_push($1, $3);
        }
    ;

assoc   : arg_value tASSOC arg_value
        {
      $$ = dispatch2(assoc_new, $1, $3);
        }
    | tLABEL arg_value
        {
      $$ = dispatch2(assoc_new, $1, $2);
        }
    ;

operation : tIDENTIFIER
    | tCONSTANT
    | tFID
    ;

operation2  : tIDENTIFIER
    | tCONSTANT
    | tFID
    | op
    ;

operation3  : tIDENTIFIER
    | tFID
    | op
    ;

dot_or_colon  : '.'
/*
*/
        { $$ = $<val>1; }

    | tCOLON2
/*
*/
        { $$ = $<val>1; }

    ;

opt_terms : /* none */
    | terms
    ;

opt_nl    : /* none */
    | '\n'
    ;

rparen    : opt_nl ')'
    ;

rbracket  : opt_nl ']'
    ;

trailer   : /* none */
    | '\n'
    | ','
    ;

term    : ';' {yyerrok;}
    | '\n'
    ;

terms   : term
    | terms ';' {yyerrok;}
    ;

none    : /* none */
        {
      $$ = Qundef;
        }
    ;
%%
# undef parser
# undef yylex
# undef yylval
# define yylval  (*((YYSTYPE*)(parser->parser_yylval)))

static int parser_regx_options(struct parser_params*);
static int parser_tokadd_string(struct parser_params*,int,int,int,long*,rb_encoding**);
static void parser_tokaddmbc(struct parser_params *parser, int c, rb_encoding *enc);
static int parser_parse_string(struct parser_params*,NODE*);
static int parser_here_document(struct parser_params*,NODE*);


# define nextc()                   parser_nextc(parser)
# define pushback(c)               parser_pushback(parser, (c))
# define newtok()                  parser_newtok(parser)
# define tokspace(n)               parser_tokspace(parser, (n))
# define tokadd(c)                 parser_tokadd(parser, (c))
# define tok_hex(numlen)           parser_tok_hex(parser, (numlen))
# define read_escape(flags,e)      parser_read_escape(parser, (flags), (e))
# define tokadd_escape(e)          parser_tokadd_escape(parser, (e))
# define regx_options()            parser_regx_options(parser)
# define tokadd_string(f,t,p,n,e)  parser_tokadd_string(parser,(f),(t),(p),(n),(e))
# define parse_string(n)           parser_parse_string(parser,(n))
# define tokaddmbc(c, enc)         parser_tokaddmbc(parser, (c), (enc))
# define here_document(n)          parser_here_document(parser,(n))
# define heredoc_identifier()      parser_heredoc_identifier(parser)
# define heredoc_restore(n)        parser_heredoc_restore(parser,(n))
# define whole_match_p(e,l,i)      parser_whole_match_p(parser,(e),(l),(i))

static inline VALUE
redtree_yylval_id(ID x)
{
    return (VALUE)NEW_LASGN(x, ID2SYM(x));
}
# define set_yylval_str(x) (void)(x)
# define set_yylval_num(x) (void)(x)
# define set_yylval_id(x)  (void)(x)
# define set_yylval_name(x) (void)(yylval.val = redtree_yylval_id(x))
# define set_yylval_literal(x) (void)(x)
# define set_yylval_node(x) (void)(x)
# define yylval_id() yylval.id

#define redtree_flush(p) ((p)->tokp = (p)->parser_lex_p)

#define yylval_rval (*(RB_TYPE_P(yylval.val, T_NODE) ? &yylval.node->nd_rval : &yylval.val))

static int
redtree_has_scan_event(struct parser_params *parser)
{

    if (lex_p < parser->tokp) rb_raise(rb_eRuntimeError, "lex_p < tokp");
    return lex_p > parser->tokp;
}

static VALUE
redtree_scan_event_val(struct parser_params *parser, int t)
{
    VALUE str = STR_NEW(parser->tokp, lex_p - parser->tokp);
    VALUE rval = redtree_dispatch1(parser, redtree_token2eventid(t), str);
    redtree_flush(parser);
    return rval;
}

static void
redtree_dispatch_scan_event(struct parser_params *parser, int t)
{
    if (!redtree_has_scan_event(parser)) return;
    yylval_rval = redtree_scan_event_val(parser, t);
}

static void
redtree_dispatch_ignored_scan_event(struct parser_params *parser, int t)
{
    if (!redtree_has_scan_event(parser)) return;
    (void)redtree_scan_event_val(parser, t);
}

static void
redtree_dispatch_delayed_token(struct parser_params *parser, int t)
{
    int saved_line = ruby_sourceline;
    const char *saved_tokp = parser->tokp;

    ruby_sourceline = parser->delayed_line;
    parser->tokp = lex_pbeg + parser->delayed_col;
    yylval_rval = redtree_dispatch1(parser, redtree_token2eventid(t), parser->delayed);
    parser->delayed = Qnil;
    ruby_sourceline = saved_line;
    parser->tokp = saved_tokp;
}

#include "ruby/regex.h"
#include "ruby/util.h"

/* We remove any previous definition of `SIGN_EXTEND_CHAR',
   since ours (we hope) works properly with all combinations of
   machines, compilers, `char' and `unsigned char' argument types.
   (Per Bothner suggested the basic approach.)  */
#undef SIGN_EXTEND_CHAR
#if __STDC__
# define SIGN_EXTEND_CHAR(c) ((signed char)(c))
#else  /* not __STDC__ */
/* As in Harbison and Steele.  */
# define SIGN_EXTEND_CHAR(c) ((((unsigned char)(c)) ^ 128) - 128)
#endif

#define parser_encoding_name()  (parser->enc->name)
#define parser_mbclen()  mbclen((lex_p-1),lex_pend,parser->enc)
#define parser_precise_mbclen()  rb_enc_precise_mbclen((lex_p-1),lex_pend,parser->enc)
#define is_identchar(p,e,enc) (rb_enc_isalnum(*(p),(enc)) || (*(p)) == '_' || !ISASCII(*(p)))
#define parser_is_identchar() (!parser->eofp && is_identchar((lex_p-1),lex_pend,parser->enc))

#define parser_isascii() ISASCII(*(lex_p-1))


static int
parser_yyerror(struct parser_params *parser, const char *msg)
{
    dispatch1(parse_error, STR_NEW2(msg));
    return 0;
}

static void parser_prepare(struct parser_params *parser);

static rb_encoding *
must_be_ascii_compatible(VALUE s)
{
    rb_encoding *enc = rb_enc_get(s);
    if (!rb_enc_asciicompat(enc)) {
  rb_raise(rb_eArgError, "invalid source encoding");
    }
    return enc;
}

static VALUE
lex_get_str(struct parser_params *parser, VALUE s)
{
    char *beg, *end, *pend;
    rb_encoding *enc = must_be_ascii_compatible(s);

    beg = RSTRING_PTR(s);
    if (lex_gets_ptr) {
  if (RSTRING_LEN(s) == lex_gets_ptr) return Qnil;
  beg += lex_gets_ptr;
    }
    pend = RSTRING_PTR(s) + RSTRING_LEN(s);
    end = beg;
    while (end < pend) {
  if (*end++ == '\n') break;
    }
    lex_gets_ptr = end - RSTRING_PTR(s);
    return rb_enc_str_new(beg, end - beg, enc);
}

static VALUE
lex_getline(struct parser_params *parser)
{
    VALUE line = (*parser->parser_lex_gets)(parser, parser->parser_lex_input);
    if (NIL_P(line)) return line;
    must_be_ascii_compatible(line);
    return line;
}

static const rb_data_type_t parser_data_type;


#define STR_FUNC_ESCAPE 0x01
#define STR_FUNC_EXPAND 0x02
#define STR_FUNC_REGEXP 0x04
#define STR_FUNC_QWORDS 0x08
#define STR_FUNC_SYMBOL 0x10
#define STR_FUNC_INDENT 0x20

enum string_type {
    str_squote = (0),
    str_dquote = (STR_FUNC_EXPAND),
    str_xquote = (STR_FUNC_EXPAND),
    str_regexp = (STR_FUNC_REGEXP|STR_FUNC_ESCAPE|STR_FUNC_EXPAND),
    str_sword  = (STR_FUNC_QWORDS),
    str_dword  = (STR_FUNC_QWORDS|STR_FUNC_EXPAND),
    str_ssym   = (STR_FUNC_SYMBOL),
    str_dsym   = (STR_FUNC_SYMBOL|STR_FUNC_EXPAND)
};

static VALUE
parser_str_new(const char *p, long n, rb_encoding *enc, int func, rb_encoding *enc0)
{
    VALUE str;

    str = rb_enc_str_new(p, n, enc);
    if (!(func & STR_FUNC_REGEXP) && rb_enc_asciicompat(enc)) {
  if (rb_enc_str_coderange(str) == ENC_CODERANGE_7BIT) {
  }
  else if (enc0 == rb_usascii_encoding() && enc != rb_utf8_encoding()) {
      rb_enc_associate(str, rb_ascii8bit_encoding());
  }
    }

    return str;
}

#define lex_goto_eol(parser) ((parser)->parser_lex_p = (parser)->parser_lex_pend)
#define peek(c) peek_n((c), 0)
#define peek_n(c,n) (lex_p+(n) < lex_pend && (c) == (unsigned char)lex_p[n])

static inline int
parser_nextc(struct parser_params *parser)
{
    int c;

    if (lex_p == lex_pend) {
  VALUE v = lex_nextline;
  lex_nextline = 0;
  if (!v) {
      if (parser->eofp)
    return -1;

      if (!lex_input || NIL_P(v = lex_getline(parser))) {
    parser->eofp = Qtrue;
    lex_goto_eol(parser);
    return -1;
      }
  }
  {
      if (parser->tokp < lex_pend) {
    if (NIL_P(parser->delayed)) {
        parser->delayed = rb_str_buf_new(1024);
        rb_str_buf_cat(parser->delayed,
           parser->tokp, lex_pend - parser->tokp);
        parser->delayed_line = ruby_sourceline;
        parser->delayed_col = (int)(parser->tokp - lex_pbeg);
    }
    else {
        rb_str_buf_cat(parser->delayed,
           parser->tokp, lex_pend - parser->tokp);
    }
      }
      if (heredoc_end > 0) {
    ruby_sourceline = heredoc_end;
    heredoc_end = 0;
      }
      ruby_sourceline++;
      parser->line_count++;
      lex_pbeg = lex_p = RSTRING_PTR(v);
      lex_pend = lex_p + RSTRING_LEN(v);
      redtree_flush(parser);
      lex_lastline = v;
  }
    }
    c = (unsigned char)*lex_p++;
    if (c == '\r' && peek('\n')) {
  lex_p++;
  c = '\n';
    }

    return c;
}

static void
parser_pushback(struct parser_params *parser, int c)
{
    if (c == -1) return;
    lex_p--;
    if (lex_p > lex_pbeg && lex_p[0] == '\n' && lex_p[-1] == '\r') {
  lex_p--;
    }
}

#define was_bol() (lex_p == lex_pbeg + 1)

#define tokfix() (tokenbuf[tokidx]='\0')
#define tok() tokenbuf
#define toklen() tokidx
#define toklast() (tokidx>0?tokenbuf[tokidx-1]:0)

static char*
parser_newtok(struct parser_params *parser)
{
    tokidx = 0;
    if (!tokenbuf) {
  toksiz = 60;
  tokenbuf = ALLOC_N(char, 60);
    }
    if (toksiz > 4096) {
  toksiz = 60;
  REALLOC_N(tokenbuf, char, 60);
    }
    return tokenbuf;
}

static char *
parser_tokspace(struct parser_params *parser, int n)
{
    tokidx += n;

    if (tokidx >= toksiz) {
  do {toksiz *= 2;} while (toksiz < tokidx);
  REALLOC_N(tokenbuf, char, toksiz);
    }
    return &tokenbuf[tokidx-n];
}

static void
parser_tokadd(struct parser_params *parser, int c)
{
    tokenbuf[tokidx++] = (char)c;
    if (tokidx >= toksiz) {
  toksiz *= 2;
  REALLOC_N(tokenbuf, char, toksiz);
    }
}

static int
parser_tok_hex(struct parser_params *parser, size_t *numlen)
{
    int c;

    c = scan_hex(lex_p, 2, numlen);
    if (!*numlen) {
  yyerror("invalid hex escape");
  return 0;
    }
    lex_p += *numlen;
    return c;
}

#define tokcopy(n) memcpy(tokspace(n), lex_p - (n), (n))

static int
parser_tokadd_utf8(struct parser_params *parser, rb_encoding **encp,
                   int string_literal, int symbol_literal, int regexp_literal)
{
    /*
     * If string_literal is true, then we allow multiple codepoints
     * in \u{}, and add the codepoints to the current token.
     * Otherwise we're parsing a character literal and return a single
     * codepoint without adding it
     */

    int codepoint;
    size_t numlen;

    if (regexp_literal) { tokadd('\\'); tokadd('u'); }

    if (peek('{')) {  /* handle \u{...} form */
  do {
            if (regexp_literal) { tokadd(*lex_p); }
      nextc();
      codepoint = scan_hex(lex_p, 6, &numlen);
      if (numlen == 0)  {
    yyerror("invalid Unicode escape");
    return 0;
      }
      if (codepoint > 0x10ffff) {
    yyerror("invalid Unicode codepoint (too large)");
    return 0;
      }
      lex_p += numlen;
            if (regexp_literal) {
                tokcopy((int)numlen);
            }
            else if (codepoint >= 0x80) {
    *encp = UTF8_ENC();
    if (string_literal) tokaddmbc(codepoint, *encp);
      }
      else if (string_literal) {
    tokadd(codepoint);
      }
  } while (string_literal && (peek(' ') || peek('\t')));

  if (!peek('}')) {
      yyerror("unterminated Unicode escape");
      return 0;
  }

        if (regexp_literal) { tokadd('}'); }
  nextc();
    }
    else {      /* handle \uxxxx form */
  codepoint = scan_hex(lex_p, 4, &numlen);
  if (numlen < 4) {
      yyerror("invalid Unicode escape");
      return 0;
  }
  lex_p += 4;
        if (regexp_literal) {
            tokcopy(4);
        }
  else if (codepoint >= 0x80) {
      *encp = UTF8_ENC();
      if (string_literal) tokaddmbc(codepoint, *encp);
  }
  else if (string_literal) {
      tokadd(codepoint);
  }
    }

    return codepoint;
}

#define ESCAPE_CONTROL 1
#define ESCAPE_META    2

static int
parser_read_escape(struct parser_params *parser, int flags,
       rb_encoding **encp)
{
    int c;
    size_t numlen;

    switch (c = nextc()) {
      case '\\':  /* Backslash */
  return c;

      case 'n': /* newline */
  return '\n';

      case 't': /* horizontal tab */
  return '\t';

      case 'r': /* carriage-return */
  return '\r';

      case 'f': /* form-feed */
  return '\f';

      case 'v': /* vertical tab */
  return '\13';

      case 'a': /* alarm(bell) */
  return '\007';

      case 'e': /* escape */
  return 033;

      case '0': case '1': case '2': case '3': /* octal constant */
      case '4': case '5': case '6': case '7':
  pushback(c);
  c = scan_oct(lex_p, 3, &numlen);
  lex_p += numlen;
  return c;

      case 'x': /* hex constant */
  c = tok_hex(&numlen);
  if (numlen == 0) return 0;
  return c;

      case 'b': /* backspace */
  return '\010';

      case 's': /* space */
  return ' ';

      case 'M':
  if (flags & ESCAPE_META) goto eof;
  if ((c = nextc()) != '-') {
      pushback(c);
      goto eof;
  }
  if ((c = nextc()) == '\\') {
      if (peek('u')) goto eof;
      return read_escape(flags|ESCAPE_META, encp) | 0x80;
  }
  else if (c == -1 || !ISASCII(c)) goto eof;
  else {
      return ((c & 0xff) | 0x80);
  }

      case 'C':
  if ((c = nextc()) != '-') {
      pushback(c);
      goto eof;
  }
      case 'c':
  if (flags & ESCAPE_CONTROL) goto eof;
  if ((c = nextc())== '\\') {
      if (peek('u')) goto eof;
      c = read_escape(flags|ESCAPE_CONTROL, encp);
  }
  else if (c == '?')
      return 0177;
  else if (c == -1 || !ISASCII(c)) goto eof;
  return c & 0x9f;

      eof:
      case -1:
        yyerror("Invalid escape character syntax");
  return '\0';

      default:
  return c;
    }
}

static void
parser_tokaddmbc(struct parser_params *parser, int c, rb_encoding *enc)
{
    int len = rb_enc_codelen(c, enc);
    rb_enc_mbcput(c, tokspace(len), enc);
}

static int
parser_tokadd_escape(struct parser_params *parser, rb_encoding **encp)
{
    int c;
    int flags = 0;
    size_t numlen;

  first:
    switch (c = nextc()) {
      case '\n':
  return 0;   /* just ignore */

      case '0': case '1': case '2': case '3': /* octal constant */
      case '4': case '5': case '6': case '7':
  {
      ruby_scan_oct(--lex_p, 3, &numlen);
      if (numlen == 0) goto eof;
      lex_p += numlen;
      tokcopy((int)numlen + 1);
  }
  return 0;

      case 'x': /* hex constant */
  {
      tok_hex(&numlen);
      if (numlen == 0) return -1;
      tokcopy((int)numlen + 2);
  }
  return 0;

      case 'M':
  if (flags & ESCAPE_META) goto eof;
  if ((c = nextc()) != '-') {
      pushback(c);
      goto eof;
  }
  tokcopy(3);
  flags |= ESCAPE_META;
  goto escaped;

      case 'C':
  if (flags & ESCAPE_CONTROL) goto eof;
  if ((c = nextc()) != '-') {
      pushback(c);
      goto eof;
  }
  tokcopy(3);
  goto escaped;

      case 'c':
  if (flags & ESCAPE_CONTROL) goto eof;
  tokcopy(2);
  flags |= ESCAPE_CONTROL;
      escaped:
  if ((c = nextc()) == '\\') {
      goto first;
  }
  else if (c == -1) goto eof;
  tokadd(c);
  return 0;

      eof:
      case -1:
        yyerror("Invalid escape character syntax");
  return -1;

      default:
        tokadd('\\');
  tokadd(c);
    }
    return 0;
}

static int
parser_regx_options(struct parser_params *parser)
{
    int kcode = 0;
    int kopt = 0;
    int options = 0;
    int c, opt, kc;

    newtok();
    while (c = nextc(), ISALPHA(c)) {
        if (c == 'o') {
            options |= RE_OPTION_ONCE;
        }
        else if (rb_char_to_option_kcode(c, &opt, &kc)) {
      if (kc >= 0) {
    if (kc != rb_ascii8bit_encindex()) kcode = c;
    kopt = opt;
      }
      else {
    options |= opt;
      }
        }
        else {
      tokadd(c);
        }
    }
    options |= kopt;
    pushback(c);
    if (toklen()) {
  tokfix();
  compile_error(PARSER_ARG "unknown regexp option%s - %s",
          toklen() > 1 ? "s" : "", tok());
    }
    return options | RE_OPTION_ENCODING(kcode);
}

static void
dispose_string(VALUE str)
{
    /* TODO: should use another API? */
    if (RBASIC(str)->flags & RSTRING_NOEMBED)
  xfree(RSTRING_PTR(str));
    rb_gc_force_recycle(str);
}

static int
parser_tokadd_mbchar(struct parser_params *parser, int c)
{
    int len = parser_precise_mbclen();
    if (!MBCLEN_CHARFOUND_P(len)) {
  compile_error(PARSER_ARG "invalid multibyte char (%s)", parser_encoding_name());
  return -1;
    }
    tokadd(c);
    lex_p += --len;
    if (len > 0) tokcopy(len);
    return c;
}

#define tokadd_mbchar(c) parser_tokadd_mbchar(parser, (c))

static int
parser_tokadd_string(struct parser_params *parser,
         int func, int term, int paren, long *nest,
         rb_encoding **encp)
{
    int c;
    int has_nonascii = 0;
    rb_encoding *enc = *encp;
    char *errbuf = 0;
    static const char mixed_msg[] = "%s mixed within %s source";

#define mixed_error(enc1, enc2) if (!errbuf) {  \
  size_t len = sizeof(mixed_msg) - 4; \
  len += strlen(rb_enc_name(enc1)); \
  len += strlen(rb_enc_name(enc2)); \
  errbuf = ALLOCA_N(char, len);   \
  snprintf(errbuf, len, mixed_msg,  \
     rb_enc_name(enc1),   \
     rb_enc_name(enc2));    \
  yyerror(errbuf);      \
    }
#define mixed_escape(beg, enc1, enc2) do {  \
  const char *pos = lex_p;    \
  lex_p = (beg);        \
  mixed_error((enc1), (enc2));    \
  lex_p = pos;        \
    } while (0)

    while ((c = nextc()) != -1) {
  if (paren && c == paren) {
      ++*nest;
  }
  else if (c == term) {
      if (!nest || !*nest) {
    pushback(c);
    break;
      }
      --*nest;
  }
  else if ((func & STR_FUNC_EXPAND) && c == '#' && lex_p < lex_pend) {
      int c2 = *lex_p;
      if (c2 == '$' || c2 == '@' || c2 == '{') {
    pushback(c);
    break;
      }
  }
  else if (c == '\\') {
      const char *beg = lex_p - 1;
      c = nextc();
      switch (c) {
        case '\n':
    if (func & STR_FUNC_QWORDS) break;
    if (func & STR_FUNC_EXPAND) continue;
    tokadd('\\');
    break;

        case '\\':
    if (func & STR_FUNC_ESCAPE) tokadd(c);
    break;

        case 'u':
    if ((func & STR_FUNC_EXPAND) == 0) {
        tokadd('\\');
        break;
    }
    parser_tokadd_utf8(parser, &enc, 1,
           func & STR_FUNC_SYMBOL,
                                   func & STR_FUNC_REGEXP);
    if (has_nonascii && enc != *encp) {
        mixed_escape(beg, enc, *encp);
    }
    continue;

        default:
    if (func & STR_FUNC_REGEXP) {
        pushback(c);
        if ((c = tokadd_escape(&enc)) < 0)
      return -1;
        if (has_nonascii && enc != *encp) {
      mixed_escape(beg, enc, *encp);
        }
        continue;
    }
    else if (func & STR_FUNC_EXPAND) {
        pushback(c);
        if (func & STR_FUNC_ESCAPE) tokadd('\\');
        c = read_escape(0, &enc);
    }
    else if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
        /* ignore backslashed spaces in %w */
    }
    else if (c != term && !(paren && c == paren)) {
        tokadd('\\');
        pushback(c);
        continue;
    }
      }
  }
  else if (!parser_isascii()) {
      has_nonascii = 1;
      if (enc != *encp) {
    mixed_error(enc, *encp);
    continue;
      }
      if (tokadd_mbchar(c) == -1) return -1;
      continue;
  }
  else if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
      pushback(c);
      break;
  }
        if (c & 0x80) {
            has_nonascii = 1;
      if (enc != *encp) {
    mixed_error(enc, *encp);
    continue;
      }
        }
  tokadd(c);
    }
    *encp = enc;
    return c;
}

#define NEW_STRTERM(func, term, paren) \
  rb_node_newnode(NODE_STRTERM, (func), (term) | ((paren) << (CHAR_BIT * 2)), 0)

static int
parser_parse_string(struct parser_params *parser, NODE *quote)
{
    int func = (int)quote->nd_func;
    int term = nd_term(quote);
    int paren = nd_paren(quote);
    int c, space = 0;
    rb_encoding *enc = parser->enc;

    if (func == -1) return tSTRING_END;
    c = nextc();
    if ((func & STR_FUNC_QWORDS) && ISSPACE(c)) {
  do {c = nextc();} while (ISSPACE(c));
  space = 1;
    }
    if (c == term && !quote->nd_nest) {
  if (func & STR_FUNC_QWORDS) {
      quote->nd_func = -1;
      return ' ';
  }
  if (!(func & STR_FUNC_REGEXP)) return tSTRING_END;
        set_yylval_num(regx_options());
  return tREGEXP_END;
    }
    if (space) {
  pushback(c);
  return ' ';
    }
    newtok();
    if ((func & STR_FUNC_EXPAND) && c == '#') {
  switch (c = nextc()) {
    case '$':
    case '@':
      pushback(c);
      return tSTRING_DVAR;
    case '{':
      return tSTRING_DBEG;
  }
  tokadd('#');
    }
    pushback(c);
    if (tokadd_string(func, term, paren, &quote->nd_nest,
          &enc) == -1) {
  ruby_sourceline = nd_line(quote);
  if (func & STR_FUNC_REGEXP) {
      if (parser->eofp)
    compile_error(PARSER_ARG "unterminated regexp meets end of file");
      return tREGEXP_END;
  }
  else {
      if (parser->eofp)
    compile_error(PARSER_ARG "unterminated string meets end of file");
      return tSTRING_END;
  }
    }

    tokfix();
    set_yylval_str(STR_NEW3(tok(), toklen(), enc, func));

    if (!NIL_P(parser->delayed)) {
  ptrdiff_t len = lex_p - parser->tokp;
  if (len > 0) {
      rb_enc_str_buf_cat(parser->delayed, parser->tokp, len, enc);
  }
  redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
  parser->tokp = lex_p;
    }

    return tSTRING_CONTENT;
}

static int
parser_heredoc_identifier(struct parser_params *parser)
{
    int c = nextc(), term, func = 0;
    long len;

    if (c == '-') {
  c = nextc();
  func = STR_FUNC_INDENT;
    }
    switch (c) {
      case '\'':
  func |= str_squote; goto quoted;
      case '"':
  func |= str_dquote; goto quoted;
      case '`':
  func |= str_xquote;
      quoted:
  newtok();
  tokadd(func);
  term = c;
  while ((c = nextc()) != -1 && c != term) {
      if (tokadd_mbchar(c) == -1) return 0;
  }
  if (c == -1) {
      compile_error(PARSER_ARG "unterminated here document identifier");
      return 0;
  }
  break;

      default:
  if (!parser_is_identchar()) {
      pushback(c);
      if (func & STR_FUNC_INDENT) {
    pushback('-');
      }
      return 0;
  }
  newtok();
  term = '"';
  tokadd(func |= str_dquote);
  do {
      if (tokadd_mbchar(c) == -1) return 0;
  } while ((c = nextc()) != -1 && parser_is_identchar());
  pushback(c);
  break;
    }

    tokfix();
    redtree_dispatch_scan_event(parser, tHEREDOC_BEG);
    len = lex_p - lex_pbeg;
    lex_goto_eol(parser);
    lex_strterm = rb_node_newnode(NODE_HEREDOC,
          STR_NEW(tok(), toklen()), /* nd_lit */
          len,        /* nd_nth */
          lex_lastline);    /* nd_orig */
    nd_set_line(lex_strterm, ruby_sourceline);
    redtree_flush(parser);
    return term == '`' ? tXSTRING_BEG : tSTRING_BEG;
}

static void
parser_heredoc_restore(struct parser_params *parser, NODE *here)
{
    VALUE line;

    line = here->nd_orig;
    lex_lastline = line;
    lex_pbeg = RSTRING_PTR(line);
    lex_pend = lex_pbeg + RSTRING_LEN(line);
    lex_p = lex_pbeg + here->nd_nth;
    heredoc_end = ruby_sourceline;
    ruby_sourceline = nd_line(here);
    dispose_string(here->nd_lit);
    rb_gc_force_recycle((VALUE)here);
    redtree_flush(parser);
}

static int
parser_whole_match_p(struct parser_params *parser,
    const char *eos, long len, int indent)
{
    const char *p = lex_pbeg;
    long n;

    if (indent) {
  while (*p && ISSPACE(*p)) p++;
    }
    n = lex_pend - (p + len);
    if (n < 0 || (n > 0 && p[len] != '\n' && p[len] != '\r')) return FALSE;
    return strncmp(eos, p, len) == 0;
}

static void
redtree_dispatch_heredoc_end(struct parser_params *parser)
{
    if (!NIL_P(parser->delayed))
  redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
    lex_goto_eol(parser);
    redtree_dispatch_ignored_scan_event(parser, tHEREDOC_END);
}

#define dispatch_heredoc_end() redtree_dispatch_heredoc_end(parser)

static int
parser_here_document(struct parser_params *parser, NODE *here)
{
    int c, func, indent = 0;
    const char *eos, *p, *pend;
    long len;
    VALUE str = 0;
    rb_encoding *enc = parser->enc;

    eos = RSTRING_PTR(here->nd_lit);
    len = RSTRING_LEN(here->nd_lit) - 1;
    indent = (func = *eos++) & STR_FUNC_INDENT;

    if ((c = nextc()) == -1) {
      error:
  compile_error(PARSER_ARG "can't find string \"%s\" anywhere before EOF", eos);
  if (NIL_P(parser->delayed)) {
      redtree_dispatch_scan_event(parser, tSTRING_CONTENT);
  }
  else {
      if (str ||
    ((len = lex_p - parser->tokp) > 0 &&
     (str = STR_NEW3(parser->tokp, len, enc, func), 1))) {
    rb_str_append(parser->delayed, str);
      }
      redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
  }
  lex_goto_eol(parser);
      restore:
  heredoc_restore(lex_strterm);
  lex_strterm = 0;
  return 0;
    }
    if (was_bol() && whole_match_p(eos, len, indent)) {
  dispatch_heredoc_end();
  heredoc_restore(lex_strterm);
  return tSTRING_END;
    }

    if (!(func & STR_FUNC_EXPAND)) {
  do {
      p = RSTRING_PTR(lex_lastline);
      pend = lex_pend;
      if (pend > p) {
    switch (pend[-1]) {
      case '\n':
        if (--pend == p || pend[-1] != '\r') {
      pend++;
      break;
        }
      case '\r':
        --pend;
    }
      }
      if (str)
    rb_str_cat(str, p, pend - p);
      else
    str = STR_NEW(p, pend - p);
      if (pend < lex_pend) rb_str_cat(str, "\n", 1);
      lex_goto_eol(parser);
      if (nextc() == -1) {
    if (str) dispose_string(str);
    goto error;
      }
  } while (!whole_match_p(eos, len, indent));
    }
    else {
  /*  int mb = ENC_CODERANGE_7BIT, *mbp = &mb;*/
  newtok();
  if (c == '#') {
      switch (c = nextc()) {
        case '$':
        case '@':
    pushback(c);
    return tSTRING_DVAR;
        case '{':
    return tSTRING_DBEG;
      }
      tokadd('#');
  }
  do {
      pushback(c);
      if ((c = tokadd_string(func, '\n', 0, NULL, &enc)) == -1) {
    if (parser->eofp) goto error;
    goto restore;
      }
      if (c != '\n') {
    set_yylval_str(STR_NEW3(tok(), toklen(), enc, func));
    return tSTRING_CONTENT;
      }
      tokadd(nextc());
      /*      if (mbp && mb == ENC_CODERANGE_UNKNOWN) mbp = 0;*/
      if ((c = nextc()) == -1) goto error;
  } while (!whole_match_p(eos, len, indent));
  str = STR_NEW3(tok(), toklen(), enc, func);
    }
    dispatch_heredoc_end();
    heredoc_restore(lex_strterm);
    lex_strterm = NEW_STRTERM(-1, 0, 0);
    set_yylval_str(str);
    return tSTRING_CONTENT;
}

#include "lex.c"

static void
arg_ambiguous_gen(struct parser_params *parser)
{
    dispatch0(arg_ambiguous);
}
#define arg_ambiguous() (arg_ambiguous_gen(parser), 1)

static ID
formal_argument_gen(struct parser_params *parser, ID lhs)
{
    shadowing_lvar(lhs);
    return lhs;
}

static int
lvar_defined_gen(struct parser_params *parser, ID id)
{
    return (dyna_in_block() && dvar_defined_get(id)) || local_id(id);
}

/* emacsen -*- hack */
static long
parser_encode_length(struct parser_params *parser, const char *name, long len)
{
    long nlen;

    if (len > 5 && name[nlen = len - 5] == '-') {
  if (rb_memcicmp(name + nlen + 1, "unix", 4) == 0)
      return nlen;
    }
    if (len > 4 && name[nlen = len - 4] == '-') {
  if (rb_memcicmp(name + nlen + 1, "dos", 3) == 0)
      return nlen;
  if (rb_memcicmp(name + nlen + 1, "mac", 3) == 0 &&
      !(len == 8 && rb_memcicmp(name, "utf8-mac", len) == 0))
      /* exclude UTF8-MAC because the encoding named "UTF8" doesn't exist in Ruby */
      return nlen;
    }
    return len;
}

static void
parser_set_encode(struct parser_params *parser, const char *name)
{
    int idx = rb_enc_find_index(name);
    rb_encoding *enc;
    VALUE excargs[3];

    if (idx < 0) {
  excargs[1] = rb_sprintf("unknown encoding name: %s", name);
      error:
  excargs[0] = rb_eArgError;
  excargs[2] = rb_make_backtrace();
  rb_ary_unshift(excargs[2], rb_sprintf("%s:%d", ruby_sourcefile, ruby_sourceline));
  rb_exc_raise(rb_make_exception(3, excargs));
    }
    enc = rb_enc_from_index(idx);
    if (!rb_enc_asciicompat(enc)) {
  excargs[1] = rb_sprintf("%s is not ASCII compatible", rb_enc_name(enc));
  goto error;
    }
    parser->enc = enc;
}

static int
comment_at_top(struct parser_params *parser)
{
    const char *p = lex_pbeg, *pend = lex_p - 1;
    if (parser->line_count != (parser->has_shebang ? 2 : 1)) return 0;
    while (p < pend) {
  if (!ISSPACE(*p)) return 0;
  p++;
    }
    return 1;
}

static const char *
magic_comment_marker(const char *str, long len)
{
    long i = 2;

    while (i < len) {
  switch (str[i]) {
    case '-':
      if (str[i-1] == '*' && str[i-2] == '-') {
    return str + i + 1;
      }
      i += 2;
      break;
    case '*':
      if (i + 1 >= len) return 0;
      if (str[i+1] != '-') {
    i += 4;
      }
      else if (str[i-1] != '-') {
    i += 2;
      }
      else {
    return str + i + 2;
      }
      break;
    default:
      i += 3;
      break;
  }
    }
    return 0;
}

static int
parser_magic_comment(struct parser_params *parser, const char *str, long len)
{
    VALUE name = 0, val = 0;
    const char *beg, *end, *vbeg, *vend;
#define str_copy(_s, _p, _n) ((_s) \
  ? (void)(rb_str_resize((_s), (_n)), \
     MEMCPY(RSTRING_PTR(_s), (_p), char, (_n)), (_s)) \
  : (void)((_s) = STR_NEW((_p), (_n))))

    if (len <= 7) return FALSE;
    if (!(beg = magic_comment_marker(str, len))) return FALSE;
    if (!(end = magic_comment_marker(beg, str + len - beg))) return FALSE;
    str = beg;
    len = end - beg - 3;

    /* %r"([^\\s\'\":;]+)\\s*:\\s*(\"(?:\\\\.|[^\"])*\"|[^\"\\s;]+)[\\s;]*" */
    while (len > 0) {
  char *s;
  int i;
  long n = 0;

  for (; len > 0 && *str; str++, --len) {
      switch (*str) {
        case '\'': case '"': case ':': case ';':
    continue;
      }
      if (!ISSPACE(*str)) break;
  }
  for (beg = str; len > 0; str++, --len) {
      switch (*str) {
        case '\'': case '"': case ':': case ';':
    break;
        default:
    if (ISSPACE(*str)) break;
    continue;
      }
      break;
  }
  for (end = str; len > 0 && ISSPACE(*str); str++, --len);
  if (!len) break;
  if (*str != ':') continue;

  do str++; while (--len > 0 && ISSPACE(*str));
  if (!len) break;
  if (*str == '"') {
      for (vbeg = ++str; --len > 0 && *str != '"'; str++) {
    if (*str == '\\') {
        --len;
        ++str;
    }
      }
      vend = str;
      if (len) {
    --len;
    ++str;
      }
  }
  else {
      for (vbeg = str; len > 0 && *str != '"' && *str != ';' && !ISSPACE(*str); --len, str++);
      vend = str;
  }
  while (len > 0 && (*str == ';' || ISSPACE(*str))) --len, str++;

  n = end - beg;
  str_copy(name, beg, n);
  s = RSTRING_PTR(name);
  for (i = 0; i < n; ++i) {
      if (s[i] == '-') s[i] = '_';
  }
  dispatch2(magic_comment, name, val);
    }

    return TRUE;
}

static void
set_file_encoding(struct parser_params *parser, const char *str, const char *send)
{
    int sep = 0;
    const char *beg = str;
    VALUE s;

    for (;;) {
  if (send - str <= 6) return;
  switch (str[6]) {
    case 'C': case 'c': str += 6; continue;
    case 'O': case 'o': str += 5; continue;
    case 'D': case 'd': str += 4; continue;
    case 'I': case 'i': str += 3; continue;
    case 'N': case 'n': str += 2; continue;
    case 'G': case 'g': str += 1; continue;
    case '=': case ':':
      sep = 1;
      str += 6;
      break;
    default:
      str += 6;
      if (ISSPACE(*str)) break;
      continue;
  }
  if (STRNCASECMP(str-6, "coding", 6) == 0) break;
    }
    for (;;) {
  do {
      if (++str >= send) return;
  } while (ISSPACE(*str));
  if (sep) break;
  if (*str != '=' && *str != ':') return;
  sep = 1;
  str++;
    }
    beg = str;
    while ((*str == '-' || *str == '_' || ISALNUM(*str)) && ++str < send);
    s = rb_str_new(beg, parser_encode_length(parser, beg, str - beg));
    parser_set_encode(parser, RSTRING_PTR(s));
    rb_str_resize(s, 0);
}

static void
parser_prepare(struct parser_params *parser)
{
    int c = nextc();
    switch (c) {
      case '#':
  if (peek('!')) parser->has_shebang = 1;
  break;
      case 0xef:    /* UTF-8 BOM marker */
  if (lex_pend - lex_p >= 2 &&
      (unsigned char)lex_p[0] == 0xbb &&
      (unsigned char)lex_p[1] == 0xbf) {
      parser->enc = rb_utf8_encoding();
      lex_p += 2;
      lex_pbeg = lex_p;
      return;
  }
  break;
      case EOF:
  return;
    }
    pushback(c);
    parser->enc = rb_enc_get(lex_lastline);
}

#define IS_ARG() (lex_state == EXPR_ARG || lex_state == EXPR_CMDARG)
#define IS_END() (lex_state == EXPR_END || lex_state == EXPR_ENDARG || lex_state == EXPR_ENDFN)
#define IS_BEG() (lex_state == EXPR_BEG || lex_state == EXPR_MID || lex_state == EXPR_VALUE || lex_state == EXPR_CLASS)
#define IS_SPCARG(c) (IS_ARG() && space_seen && !ISSPACE(c))
#define IS_LABEL_POSSIBLE() ((lex_state == EXPR_BEG && !cmd_state) || IS_ARG())
#define IS_LABEL_SUFFIX(n) (peek_n(':',(n)) && !peek_n(':', (n)+1))

#define ambiguous_operator(op, syn) dispatch2(operator_ambiguous, redtree_intern(op), rb_str_new_cstr(syn))

#define warn_balanced(op, syn) ((void) \
    (last_state != EXPR_CLASS && last_state != EXPR_DOT && \
     last_state != EXPR_FNAME && last_state != EXPR_ENDFN && \
     last_state != EXPR_ENDARG && \
     space_seen && !ISSPACE(c) && \
     (ambiguous_operator(op, syn), 0)))

static int
parser_yylex(struct parser_params *parser)
{
    register int c;
    int space_seen = 0;
    int cmd_state;
    enum lex_state_e last_state;
    rb_encoding *enc;
    int mb;
    int fallthru = FALSE;

    if (lex_strterm) {
  int token;
  if (nd_type(lex_strterm) == NODE_HEREDOC) {
      token = here_document(lex_strterm);
      if (token == tSTRING_END) {
    lex_strterm = 0;
    lex_state = EXPR_END;
      }
  }
  else {
      token = parse_string(lex_strterm);
      if (token == tSTRING_END || token == tREGEXP_END) {
    rb_gc_force_recycle((VALUE)lex_strterm);
    lex_strterm = 0;
    lex_state = EXPR_END;
      }
  }
  return token;
    }
    cmd_state = command_start;
    command_start = FALSE;
  retry:
    last_state = lex_state;
    switch (c = nextc()) {
      case '\0':    /* NUL */
      case '\004':    /* ^D */
      case '\032':    /* ^Z */
      case -1:      /* end of script. */
  return 0;

  /* white spaces */
      case ' ': case '\t': case '\f': case '\r':
      case '\13': /* '\v' */
  space_seen = 1;
  while ((c = nextc())) {
      switch (c) {
        case ' ': case '\t': case '\f': case '\r':
        case '\13': /* '\v' */
    break;
        default:
    goto outofloop;
      }
  }
      outofloop:
  pushback(c);
  redtree_dispatch_scan_event(parser, tSP);
  goto retry;

      case '#':   /* it's a comment */
  /* no magic_comment in shebang line */
  if (!parser_magic_comment(parser, lex_p, lex_pend - lex_p)) {
      if (comment_at_top(parser)) {
    set_file_encoding(parser, lex_p, lex_pend);
      }
  }
  lex_p = lex_pend;
        redtree_dispatch_scan_event(parser, tCOMMENT);
        fallthru = TRUE;
  /* fall through */
      case '\n':
  switch (lex_state) {
    case EXPR_BEG:
    case EXPR_FNAME:
    case EXPR_DOT:
    case EXPR_CLASS:
    case EXPR_VALUE:
            if (!fallthru) {
                redtree_dispatch_scan_event(parser, tIGNORED_NL);
            }
            fallthru = FALSE;
      goto retry;
    default:
      break;
  }
  while ((c = nextc())) {
      switch (c) {
        case ' ': case '\t': case '\f': case '\r':
        case '\13': /* '\v' */
    space_seen = 1;
    break;
        case '.': {
      if ((c = nextc()) != '.') {
          pushback(c);
          pushback('.');
          goto retry;
      }
        }
        default:
    --ruby_sourceline;
    lex_nextline = lex_lastline;
        case -1:    /* EOF no decrement*/
    lex_goto_eol(parser);
    if (c != -1) {
        parser->tokp = lex_p;
    }
    goto normal_newline;
      }
  }
      normal_newline:
  command_start = TRUE;
  lex_state = EXPR_BEG;
  return '\n';

      case '*':
  if ((c = nextc()) == '*') {
      if ((c = nextc()) == '=') {
                set_yylval_id(tPOW);
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      c = tPOW;
  }
  else {
      if (c == '=') {
                set_yylval_id('*');
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      if (IS_SPCARG(c)) {
    rb_warning0("`*' interpreted as argument prefix");
    c = tSTAR;
      }
      else if (IS_BEG()) {
    c = tSTAR;
      }
      else {
    warn_balanced("*", "argument prefix");
    c = '*';
      }
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  return c;

      case '!':
  c = nextc();
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      lex_state = EXPR_ARG;
      if (c == '@') {
    return '!';
      }
  }
  else {
      lex_state = EXPR_BEG;
  }
  if (c == '=') {
      return tNEQ;
  }
  if (c == '~') {
      return tNMATCH;
  }
  pushback(c);
  return '!';

      case '=':
  if (was_bol()) {
      /* skip embedded rd document */
      if (strncmp(lex_p, "begin", 5) == 0 && ISSPACE(lex_p[5])) {
                int first_p = TRUE;

                lex_goto_eol(parser);
                redtree_dispatch_scan_event(parser, tEMBDOC_BEG);
    for (;;) {
        lex_goto_eol(parser);
                    if (!first_p) {
                        redtree_dispatch_scan_event(parser, tEMBDOC);
                    }
                    first_p = FALSE;
        c = nextc();
        if (c == -1) {
      compile_error(PARSER_ARG "embedded document meets end of file");
      return 0;
        }
        if (c != '=') continue;
        if (strncmp(lex_p, "end", 3) == 0 &&
      (lex_p + 3 == lex_pend || ISSPACE(lex_p[3]))) {
      break;
        }
    }
    lex_goto_eol(parser);
                redtree_dispatch_scan_event(parser, tEMBDOC_END);
    goto retry;
      }
  }

  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  if ((c = nextc()) == '=') {
      if ((c = nextc()) == '=') {
    return tEQQ;
      }
      pushback(c);
      return tEQ;
  }
  if (c == '~') {
      return tMATCH;
  }
  else if (c == '>') {
      return tASSOC;
  }
  pushback(c);
  return '=';

      case '<':
  last_state = lex_state;
  c = nextc();
  if (c == '<' &&
      lex_state != EXPR_DOT &&
      lex_state != EXPR_CLASS &&
      !IS_END() &&
      (!IS_ARG() || space_seen)) {
      int token = heredoc_identifier();
      if (token) return token;
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  if (c == '=') {
      if ((c = nextc()) == '>') {
    return tCMP;
      }
      pushback(c);
      return tLEQ;
  }
  if (c == '<') {
      if ((c = nextc()) == '=') {
                set_yylval_id(tLSHFT);
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      warn_balanced("<<", "here document");
      return tLSHFT;
  }
  pushback(c);
  return '<';

      case '>':
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  if ((c = nextc()) == '=') {
      return tGEQ;
  }
  if (c == '>') {
      if ((c = nextc()) == '=') {
                set_yylval_id(tRSHFT);
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      return tRSHFT;
  }
  pushback(c);
  return '>';

      case '"':
  lex_strterm = NEW_STRTERM(str_dquote, '"', 0);
  return tSTRING_BEG;

      case '`':
  if (lex_state == EXPR_FNAME) {
      lex_state = EXPR_ENDFN;
      return c;
  }
  if (lex_state == EXPR_DOT) {
      if (cmd_state)
    lex_state = EXPR_CMDARG;
      else
    lex_state = EXPR_ARG;
      return c;
  }
  lex_strterm = NEW_STRTERM(str_xquote, '`', 0);
  return tXSTRING_BEG;

      case '\'':
  lex_strterm = NEW_STRTERM(str_squote, '\'', 0);
  return tSTRING_BEG;

      case '?':
  if (IS_END()) {
      lex_state = EXPR_VALUE;
      return '?';
  }
  c = nextc();
  if (c == -1) {
      compile_error(PARSER_ARG "incomplete character syntax");
      return 0;
  }
  if (rb_enc_isspace(c, parser->enc)) {
      if (!IS_ARG()) {
    int c2 = 0;
    switch (c) {
      case ' ':
        c2 = 's';
        break;
      case '\n':
        c2 = 'n';
        break;
      case '\t':
        c2 = 't';
        break;
      case '\v':
        c2 = 'v';
        break;
      case '\r':
        c2 = 'r';
        break;
      case '\f':
        c2 = 'f';
        break;
    }
    if (c2) {
        rb_warnI("invalid character syntax; use ?\\%c", c2);
    }
      }
    ternary:
      pushback(c);
      lex_state = EXPR_VALUE;
      return '?';
  }
  newtok();
  enc = parser->enc;
  if (!parser_isascii()) {
      if (tokadd_mbchar(c) == -1) return 0;
  }
  else if ((rb_enc_isalnum(c, parser->enc) || c == '_') &&
     lex_p < lex_pend && is_identchar(lex_p, lex_pend, parser->enc)) {
      goto ternary;
  }
        else if (c == '\\') {
            if (peek('u')) {
                nextc();
                c = parser_tokadd_utf8(parser, &enc, 0, 0, 0);
                if (0x80 <= c) {
                    tokaddmbc(c, enc);
                }
                else {
                    tokadd(c);
                }
            }
            else {
                c = read_escape(0, &enc);
                tokadd(c);
            }
        }
        else {
      tokadd(c);
        }
  tokfix();
  set_yylval_str(STR_NEW3(tok(), toklen(), enc, 0));
  lex_state = EXPR_END;
  return tCHAR;

      case '&':
  if ((c = nextc()) == '&') {
      lex_state = EXPR_BEG;
      if ((c = nextc()) == '=') {
                set_yylval_id(tANDOP);
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      return tANDOP;
  }
  else if (c == '=') {
            set_yylval_id('&');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  pushback(c);
  if (IS_SPCARG(c)) {
      rb_warning0("`&' interpreted as argument prefix");
      c = tAMPER;
  }
  else if (IS_BEG()) {
      c = tAMPER;
  }
  else {
      warn_balanced("&", "argument prefix");
      c = '&';
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG;
  }
  return c;

      case '|':
  if ((c = nextc()) == '|') {
      lex_state = EXPR_BEG;
      if ((c = nextc()) == '=') {
                set_yylval_id(tOROP);
    lex_state = EXPR_BEG;
    return tOP_ASGN;
      }
      pushback(c);
      return tOROP;
  }
  if (c == '=') {
            set_yylval_id('|');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      lex_state = EXPR_ARG;
  }
  else {
      lex_state = EXPR_BEG;
  }
  pushback(c);
  return '|';

      case '+':
  c = nextc();
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      lex_state = EXPR_ARG;
      if (c == '@') {
    return tUPLUS;
      }
      pushback(c);
      return '+';
  }
  if (c == '=') {
            set_yylval_id('+');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous())) {
      lex_state = EXPR_BEG;
      pushback(c);
      if (c != -1 && ISDIGIT(c)) {
    c = '+';
    goto start_num;
      }
      return tUPLUS;
  }
  lex_state = EXPR_BEG;
  pushback(c);
  warn_balanced("+", "unary operator");
  return '+';

      case '-':
  c = nextc();
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      lex_state = EXPR_ARG;
      if (c == '@') {
    return tUMINUS;
      }
      pushback(c);
      return '-';
  }
  if (c == '=') {
            set_yylval_id('-');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  if (c == '>') {
      lex_state = EXPR_ARG;
      return tLAMBDA;
  }
  if (IS_BEG() || (IS_SPCARG(c) && arg_ambiguous())) {
      lex_state = EXPR_BEG;
      pushback(c);
      if (c != -1 && ISDIGIT(c)) {
    return tUMINUS_NUM;
      }
      return tUMINUS;
  }
  lex_state = EXPR_BEG;
  pushback(c);
  warn_balanced("-", "unary operator");
  return '-';

      case '.':
  lex_state = EXPR_BEG;
  if ((c = nextc()) == '.') {
      if ((c = nextc()) == '.') {
    return tDOT3;
      }
      pushback(c);
      return tDOT2;
  }
  pushback(c);
  if (c != -1 && ISDIGIT(c)) {
      yyerror("no .<digit> floating literal anymore; put 0 before dot");
  }
  lex_state = EXPR_DOT;
  return '.';

      start_num:
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
  {
      int is_float, seen_point, seen_e, nondigit;

      is_float = seen_point = seen_e = nondigit = 0;
      lex_state = EXPR_END;
      newtok();
      if (c == '-' || c == '+') {
    tokadd(c);
    c = nextc();
      }
      if (c == '0') {
#define no_digits() do {yyerror("numeric literal without digits"); return 0;} while (0)
    int start = toklen();
    c = nextc();
    if (c == 'x' || c == 'X') {
        /* hexadecimal */
        c = nextc();
        if (c != -1 && ISXDIGIT(c)) {
      do {
          if (c == '_') {
        if (nondigit) break;
        nondigit = c;
        continue;
          }
          if (!ISXDIGIT(c)) break;
          nondigit = 0;
          tokadd(c);
      } while ((c = nextc()) != -1);
        }
        pushback(c);
        tokfix();
        if (toklen() == start) {
      no_digits();
        }
        else if (nondigit) goto trailing_uc;
        set_yylval_literal(rb_cstr_to_inum(tok(), 16, FALSE));
        return tINTEGER;
    }
    if (c == 'b' || c == 'B') {
        /* binary */
        c = nextc();
        if (c == '0' || c == '1') {
      do {
          if (c == '_') {
        if (nondigit) break;
        nondigit = c;
        continue;
          }
          if (c != '0' && c != '1') break;
          nondigit = 0;
          tokadd(c);
      } while ((c = nextc()) != -1);
        }
        pushback(c);
        tokfix();
        if (toklen() == start) {
      no_digits();
        }
        else if (nondigit) goto trailing_uc;
        set_yylval_literal(rb_cstr_to_inum(tok(), 2, FALSE));
        return tINTEGER;
    }
    if (c == 'd' || c == 'D') {
        /* decimal */
        c = nextc();
        if (c != -1 && ISDIGIT(c)) {
      do {
          if (c == '_') {
        if (nondigit) break;
        nondigit = c;
        continue;
          }
          if (!ISDIGIT(c)) break;
          nondigit = 0;
          tokadd(c);
      } while ((c = nextc()) != -1);
        }
        pushback(c);
        tokfix();
        if (toklen() == start) {
      no_digits();
        }
        else if (nondigit) goto trailing_uc;
        set_yylval_literal(rb_cstr_to_inum(tok(), 10, FALSE));
        return tINTEGER;
    }
    if (c == '_') {
        /* 0_0 */
        goto octal_number;
    }
    if (c == 'o' || c == 'O') {
        /* prefixed octal */
        c = nextc();
        if (c == -1 || c == '_' || !ISDIGIT(c)) {
      no_digits();
        }
    }
    if (c >= '0' && c <= '7') {
        /* octal */
      octal_number:
              do {
      if (c == '_') {
          if (nondigit) break;
          nondigit = c;
          continue;
      }
      if (c < '0' || c > '9') break;
      if (c > '7') goto invalid_octal;
      nondigit = 0;
      tokadd(c);
        } while ((c = nextc()) != -1);
        if (toklen() > start) {
      pushback(c);
      tokfix();
      if (nondigit) goto trailing_uc;
      set_yylval_literal(rb_cstr_to_inum(tok(), 8, FALSE));
      return tINTEGER;
        }
        if (nondigit) {
      pushback(c);
      goto trailing_uc;
        }
    }
    if (c > '7' && c <= '9') {
      invalid_octal:
        yyerror("Invalid octal digit");
    }
    else if (c == '.' || c == 'e' || c == 'E') {
        tokadd('0');
    }
    else {
        pushback(c);
                    set_yylval_literal(INT2FIX(0));
        return tINTEGER;
    }
      }

      for (;;) {
    switch (c) {
      case '0': case '1': case '2': case '3': case '4':
      case '5': case '6': case '7': case '8': case '9':
        nondigit = 0;
        tokadd(c);
        break;

      case '.':
        if (nondigit) goto trailing_uc;
        if (seen_point || seen_e) {
      goto decode_num;
        }
        else {
      int c0 = nextc();
      if (c0 == -1 || !ISDIGIT(c0)) {
          pushback(c0);
          goto decode_num;
      }
      c = c0;
        }
        tokadd('.');
        tokadd(c);
        is_float++;
        seen_point++;
        nondigit = 0;
        break;

      case 'e':
      case 'E':
        if (nondigit) {
      pushback(c);
      c = nondigit;
      goto decode_num;
        }
        if (seen_e) {
      goto decode_num;
        }
        tokadd(c);
        seen_e++;
        is_float++;
        nondigit = c;
        c = nextc();
        if (c != '-' && c != '+') continue;
        tokadd(c);
        nondigit = c;
        break;

      case '_': /* `_' in number just ignored */
        if (nondigit) goto decode_num;
        nondigit = c;
        break;

      default:
        goto decode_num;
    }
    c = nextc();
      }

    decode_num:
      pushback(c);
      if (nondigit) {
    char tmp[30];
        trailing_uc:
    snprintf(tmp, sizeof(tmp), "trailing `%c' in number", nondigit);
    yyerror(tmp);
      }
      tokfix();
      if (is_float) {
    double d = strtod(tok(), 0);
    if (errno == ERANGE) {
        rb_warningS("Float %s out of range", tok());
        errno = 0;
    }
                set_yylval_literal(DBL2NUM(d));
    return tFLOAT;
      }
      set_yylval_literal(rb_cstr_to_inum(tok(), 10, FALSE));
      return tINTEGER;
  }

      case ')':
      case ']':
  paren_nest--;
      case '}':
  COND_LEXPOP();
  CMDARG_LEXPOP();
  if (c == ')')
      lex_state = EXPR_ENDFN;
  else
      lex_state = EXPR_ENDARG;
  return c;

      case ':':
  c = nextc();
  if (c == ':') {
      if (IS_BEG() || lex_state == EXPR_CLASS || IS_SPCARG(-1)) {
    lex_state = EXPR_BEG;
    return tCOLON3;
      }
      lex_state = EXPR_DOT;
      return tCOLON2;
  }
  if (IS_END() || ISSPACE(c)) {
      pushback(c);
      warn_balanced(":", "symbol literal");
      lex_state = EXPR_BEG;
      return ':';
  }
  switch (c) {
    case '\'':
      lex_strterm = NEW_STRTERM(str_ssym, c, 0);
      break;
    case '"':
      lex_strterm = NEW_STRTERM(str_dsym, c, 0);
      break;
    default:
      pushback(c);
      break;
  }
  lex_state = EXPR_FNAME;
  return tSYMBEG;

      case '/':
  if (IS_BEG()) {
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
  }
  if ((c = nextc()) == '=') {
            set_yylval_id('/');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  pushback(c);
  if (IS_SPCARG(c)) {
      (void)arg_ambiguous();
      lex_strterm = NEW_STRTERM(str_regexp, '/', 0);
      return tREGEXP_BEG;
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  warn_balanced("/", "regexp literal");
  return '/';

      case '^':
  if ((c = nextc()) == '=') {
            set_yylval_id('^');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  pushback(c);
  return '^';

      case ';':
  lex_state = EXPR_BEG;
  command_start = TRUE;
  return ';';

      case ',':
  lex_state = EXPR_BEG;
  return ',';

      case '~':
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      if ((c = nextc()) != '@') {
    pushback(c);
      }
      lex_state = EXPR_ARG;
  }
  else {
      lex_state = EXPR_BEG;
  }
  return '~';

      case '(':
  if (IS_BEG()) {
      c = tLPAREN;
  }
  else if (IS_SPCARG(-1)) {
      c = tLPAREN_ARG;
  }
  paren_nest++;
  COND_PUSH(0);
  CMDARG_PUSH(0);
  lex_state = EXPR_BEG;
  return c;

      case '[':
  paren_nest++;
  if (lex_state == EXPR_FNAME || lex_state == EXPR_DOT) {
      lex_state = EXPR_ARG;
      if ((c = nextc()) == ']') {
    if ((c = nextc()) == '=') {
        return tASET;
    }
    pushback(c);
    return tAREF;
      }
      pushback(c);
      return '[';
  }
  else if (IS_BEG()) {
      c = tLBRACK;
  }
  else if (IS_ARG() && space_seen) {
      c = tLBRACK;
  }
  lex_state = EXPR_BEG;
  COND_PUSH(0);
  CMDARG_PUSH(0);
  return c;

      case '{':
  if (lpar_beg && lpar_beg == paren_nest) {
      lex_state = EXPR_BEG;
      lpar_beg = 0;
      --paren_nest;
      COND_PUSH(0);
      CMDARG_PUSH(0);
      return tLAMBEG;
  }
  if (IS_ARG() || lex_state == EXPR_END || lex_state == EXPR_ENDFN)
      c = '{';          /* block (primary) */
  else if (lex_state == EXPR_ENDARG)
      c = tLBRACE_ARG;  /* block (expr) */
  else
      c = tLBRACE;      /* hash */
  COND_PUSH(0);
  CMDARG_PUSH(0);
  lex_state = EXPR_BEG;
  if (c != tLBRACE) command_start = TRUE;
  return c;

      case '\\':
  c = nextc();
  if (c == '\n') {
      space_seen = 1;
      redtree_dispatch_scan_event(parser, tSP);
      goto retry; /* skip \\n */
  }
  pushback(c);
  return '\\';

      case '%':
  if (IS_BEG()) {
      int term;
      int paren;

      c = nextc();
    quotation:
      if (c == -1 || !ISALNUM(c)) {
    term = c;
    c = 'Q';
      }
      else {
    term = nextc();
    if (rb_enc_isalnum(term, parser->enc) || !parser_isascii()) {
        yyerror("unknown type of %string");
        return 0;
    }
      }
      if (c == -1 || term == -1) {
    compile_error(PARSER_ARG "unterminated quoted string meets end of file");
    return 0;
      }
      paren = term;
      if (term == '(') term = ')';
      else if (term == '[') term = ']';
      else if (term == '{') term = '}';
      else if (term == '<') term = '>';
      else paren = 0;

      switch (c) {
        case 'Q':
    lex_strterm = NEW_STRTERM(str_dquote, term, paren);
    return tSTRING_BEG;

        case 'q':
    lex_strterm = NEW_STRTERM(str_squote, term, paren);
    return tSTRING_BEG;

        case 'W':
    lex_strterm = NEW_STRTERM(str_dword, term, paren);
    do {c = nextc();} while (ISSPACE(c));
    pushback(c);
    return tWORDS_BEG;

        case 'w':
    lex_strterm = NEW_STRTERM(str_sword, term, paren);
    do {c = nextc();} while (ISSPACE(c));
    pushback(c);
    return tQWORDS_BEG;

        case 'x':
    lex_strterm = NEW_STRTERM(str_xquote, term, paren);
    return tXSTRING_BEG;

        case 'r':
    lex_strterm = NEW_STRTERM(str_regexp, term, paren);
    return tREGEXP_BEG;

        case 's':
    lex_strterm = NEW_STRTERM(str_ssym, term, paren);
    lex_state = EXPR_FNAME;
    return tSYMBEG;

        default:
    yyerror("unknown type of %string");
    return 0;
      }
  }
  if ((c = nextc()) == '=') {
            set_yylval_id('%');
      lex_state = EXPR_BEG;
      return tOP_ASGN;
  }
  if (IS_SPCARG(c)) {
      goto quotation;
  }
  switch (lex_state) {
    case EXPR_FNAME: case EXPR_DOT:
      lex_state = EXPR_ARG; break;
    default:
      lex_state = EXPR_BEG; break;
  }
  pushback(c);
  warn_balanced("%%", "string literal");
  return '%';

      case '$':
  lex_state = EXPR_END;
  newtok();
  c = nextc();
  switch (c) {
    case '_':   /* $_: last read line string */
      c = nextc();
      if (parser_is_identchar()) {
    tokadd('$');
    tokadd('_');
    break;
      }
      pushback(c);
      c = '_';
      /* fall through */
    case '~':   /* $~: match-data */
    case '*':   /* $*: argv */
    case '$':   /* $$: pid */
    case '?':   /* $?: last status */
    case '!':   /* $!: error string */
    case '@':   /* $@: error position */
    case '/':   /* $/: input record separator */
    case '\\':    /* $\: output record separator */
    case ';':   /* $;: field separator */
    case ',':   /* $,: output field separator */
    case '.':   /* $.: last read line number */
    case '=':   /* $=: ignorecase */
    case ':':   /* $:: load path */
    case '<':   /* $<: reading filename */
    case '>':   /* $>: default output handle */
    case '\"':    /* $": already loaded files */
      tokadd('$');
      tokadd(c);
      tokfix();
      set_yylval_name(rb_intern(tok()));
      return tGVAR;

    case '-':
      tokadd('$');
      tokadd(c);
      c = nextc();
      if (parser_is_identchar()) {
    if (tokadd_mbchar(c) == -1) return 0;
      }
      else {
    pushback(c);
      }
    gvar:
      tokfix();
      set_yylval_name(rb_intern(tok()));
      return tGVAR;

    case '&':   /* $&: last match */
    case '`':   /* $`: string before last match */
    case '\'':    /* $': string after last match */
    case '+':   /* $+: string matches last paren. */
      if (last_state == EXPR_FNAME) {
    tokadd('$');
    tokadd(c);
    goto gvar;
      }
      set_yylval_node(NEW_BACK_REF(c));
      return tBACK_REF;

    case '1': case '2': case '3':
    case '4': case '5': case '6':
    case '7': case '8': case '9':
      tokadd('$');
      do {
    tokadd(c);
    c = nextc();
      } while (c != -1 && ISDIGIT(c));
      pushback(c);
      if (last_state == EXPR_FNAME) goto gvar;
      tokfix();
      set_yylval_node(NEW_NTH_REF(atoi(tok()+1)));
      return tNTH_REF;

    default:
      if (!parser_is_identchar()) {
    pushback(c);
    return '$';
      }
    case '0':
      tokadd('$');
  }
  break;

      case '@':
  c = nextc();
  newtok();
  tokadd('@');
  if (c == '@') {
      tokadd('@');
      c = nextc();
  }
  if (c != -1 && ISDIGIT(c)) {
      if (tokidx == 1) {
    compile_error(PARSER_ARG "`@%c' is not allowed as an instance variable name", c);
      }
      else {
    compile_error(PARSER_ARG "`@@%c' is not allowed as a class variable name", c);
      }
      return 0;
  }
  if (!parser_is_identchar()) {
      pushback(c);
      return '@';
  }
  break;

      case '_':
  if (was_bol() && whole_match_p("__END__", 7, 0)) {
      ruby__end__seen = 1;
      parser->eofp = Qtrue;
            lex_goto_eol(parser);
            redtree_dispatch_scan_event(parser, k__END__);
            return 0;
  }
  newtok();
  break;

      default:
  if (!parser_is_identchar()) {
      rb_compile_error(PARSER_ARG  "Invalid char `\\x%02X' in expression", c);
      goto retry;
  }

  newtok();
  break;
    }

    mb = ENC_CODERANGE_7BIT;
    do {
  if (!ISASCII(c)) mb = ENC_CODERANGE_UNKNOWN;
  if (tokadd_mbchar(c) == -1) return 0;
  c = nextc();
    } while (parser_is_identchar());
    switch (tok()[0]) {
      case '@': case '$':
  pushback(c);
  break;
      default:
  if ((c == '!' || c == '?') && !peek('=')) {
      tokadd(c);
  }
  else {
      pushback(c);
  }
    }
    tokfix();

    {
  int result = 0;

  last_state = lex_state;
  switch (tok()[0]) {
    case '$':
      lex_state = EXPR_END;
      result = tGVAR;
      break;
    case '@':
      lex_state = EXPR_END;
      if (tok()[1] == '@')
    result = tCVAR;
      else
    result = tIVAR;
      break;

    default:
      if (toklast() == '!' || toklast() == '?') {
    result = tFID;
      }
      else {
    if (lex_state == EXPR_FNAME) {
        if ((c = nextc()) == '=' && !peek('~') && !peek('>') &&
      (!peek('=') || (peek_n('>', 1)))) {
      result = tIDENTIFIER;
      tokadd(c);
      tokfix();
        }
        else {
      pushback(c);
        }
    }
    if (result == 0 && ISUPPER(tok()[0])) {
        result = tCONSTANT;
    }
    else {
        result = tIDENTIFIER;
    }
      }

      if (IS_LABEL_POSSIBLE()) {
    if (IS_LABEL_SUFFIX(0)) {
        lex_state = EXPR_BEG;
        nextc();
        set_yylval_name(TOK_INTERN(!ENC_SINGLE(mb)));
        return tLABEL;
    }
      }
      if (mb == ENC_CODERANGE_7BIT && lex_state != EXPR_DOT) {
    const struct kwtable *kw;

    /* See if it is a reserved word.  */
    kw = rb_reserved_word(tok(), toklen());
    if (kw) {
        enum lex_state_e state = lex_state;
        lex_state = kw->state;
        if (state == EXPR_FNAME) {
      set_yylval_name(rb_intern(kw->name));
      return kw->id[0];
        }
        if (kw->id[0] == keyword_do) {
      command_start = TRUE;
      if (lpar_beg && lpar_beg == paren_nest) {
          lpar_beg = 0;
          --paren_nest;
          return keyword_do_LAMBDA;
      }
      if (COND_P()) return keyword_do_cond;
      if (CMDARG_P() && state != EXPR_CMDARG)
          return keyword_do_block;
      if (state == EXPR_ENDARG || state == EXPR_BEG)
          return keyword_do_block;
      return keyword_do;
        }
        if (state == EXPR_BEG || state == EXPR_VALUE)
      return kw->id[0];
        else {
      if (kw->id[0] != kw->id[1])
          lex_state = EXPR_BEG;
      return kw->id[1];
        }
    }
      }

      if (IS_BEG() ||
    lex_state == EXPR_DOT ||
    IS_ARG()) {
    if (cmd_state) {
        lex_state = EXPR_CMDARG;
    }
    else {
        lex_state = EXPR_ARG;
    }
      }
      else if (lex_state == EXPR_FNAME) {
    lex_state = EXPR_ENDFN;
      }
      else {
    lex_state = EXPR_END;
      }
  }
        {
            ID ident = TOK_INTERN(!ENC_SINGLE(mb));

            set_yylval_name(ident);
            if (last_state != EXPR_DOT && is_local_id(ident) && lvar_defined(ident)) {
                lex_state = EXPR_END;
            }
        }
  return result;
    }
}

#if YYPURE
static int
yylex(void *lval, void *p)
#else
yylex(void *p)
#endif
{
    struct parser_params *parser = (struct parser_params*)p;
    int t;

#if YYPURE
    parser->parser_yylval = lval;
    parser->parser_yylval->val = Qundef;
#endif
    t = parser_yylex(parser);
    if (!NIL_P(parser->delayed)) {
  redtree_dispatch_delayed_token(parser, t);
  return t;
    }
    if (t != 0)
  redtree_dispatch_scan_event(parser, t);

    return t;
}

static int
id_is_var_gen(struct parser_params *parser, ID id)
{
    if (is_notop_id(id)) {
  switch (id & ID_SCOPE_MASK) {
    case ID_GLOBAL: case ID_INSTANCE: case ID_CONST: case ID_CLASS:
      return 1;
    case ID_LOCAL:
      if (dyna_in_block() && dvar_defined(id)) return 1;
      if (local_id(id)) return 1;
      /* method call without arguments */
      return 0;
  }
    }
    compile_error(PARSER_ARG "identifier %s is not valid to get", rb_id2name(id));
    return 0;
}

static VALUE
assignable_gen(struct parser_params *parser, VALUE lhs)
{
    ID id = get_id(lhs);
# define assignable_result(x) get_value(lhs)
# define parser_yyerror(parser, x) dispatch1(assign_error, lhs)
    if (!id) return assignable_result(0);
    if (id == keyword_self) {
  yyerror("Can't change the value of self");
    }
    else if (id == keyword_nil) {
  yyerror("Can't assign to nil");
    }
    else if (id == keyword_true) {
  yyerror("Can't assign to true");
    }
    else if (id == keyword_false) {
  yyerror("Can't assign to false");
    }
    else if (id == keyword__FILE__) {
  yyerror("Can't assign to __FILE__");
    }
    else if (id == keyword__LINE__) {
  yyerror("Can't assign to __LINE__");
    }
    else if (id == keyword__ENCODING__) {
  yyerror("Can't assign to __ENCODING__");
    }
    else if (is_local_id(id)) {
  if (dyna_in_block()) {
      if (dvar_curr(id)) {
    return assignable_result(NEW_DASGN_CURR(id, val));
      }
      else if (dvar_defined(id)) {
    return assignable_result(NEW_DASGN(id, val));
      }
      else if (local_id(id)) {
    return assignable_result(NEW_LASGN(id, val));
      }
      else {
    dyna_var(id);
    return assignable_result(NEW_DASGN_CURR(id, val));
      }
  }
  else {
      if (!local_id(id)) {
    local_var(id);
      }
      return assignable_result(NEW_LASGN(id, val));
  }
    }
    else if (is_global_id(id)) {
  return assignable_result(NEW_GASGN(id, val));
    }
    else if (is_instance_id(id)) {
  return assignable_result(NEW_IASGN(id, val));
    }
    else if (is_const_id(id)) {
  if (!in_def && !in_single)
      return assignable_result(NEW_CDECL(id, val, 0));
  yyerror("dynamic constant assignment");
    }
    else if (is_class_id(id)) {
  return assignable_result(NEW_CVASGN(id, val));
    }
    else {
  compile_error(PARSER_ARG "identifier %s is not valid to set", rb_id2name(id));
    }
    return assignable_result(0);
#undef assignable_result
#undef parser_yyerror
}

#define LVAR_USED ((int)1 << (sizeof(int) * CHAR_BIT - 1))

static ID
shadowing_lvar_gen(struct parser_params *parser, ID name)
{
    if (idUScore == name) return name;
    if (dyna_in_block()) {
  if (dvar_curr(name)) {
      yyerror("duplicated argument name");
  }
  else if (dvar_defined_get(name) || local_id(name)) {
      rb_warningS("shadowing outer local variable - %s", rb_id2name(name));
      vtable_add(lvtbl->vars, name);
      if (lvtbl->used) {
    vtable_add(lvtbl->used, (ID)ruby_sourceline | LVAR_USED);
      }
  }
    }
    else {
  if (local_id(name)) {
      yyerror("duplicated argument name");
  }
    }
    return name;
}

static void
new_bv_gen(struct parser_params *parser, ID name)
{
    if (!name) return;
    if (!is_local_id(name)) {
  compile_error(PARSER_ARG "invalid local variable - %s",
          rb_id2name(name));
  return;
    }
    shadowing_lvar(name);
    dyna_var(name);
}

static void
warn_unused_var(struct parser_params *parser, struct local_vars *local)
{
    int i, cnt;
    ID *v, *u;

    if (!local->used) return;
    v = local->vars->tbl;
    u = local->used->tbl;
    cnt = local->used->pos;
    if (cnt != local->vars->pos) {
  rb_bug("local->used->pos != local->vars->pos");
    }
    for (i = 0; i < cnt; ++i) {
  if (!v[i] || (u[i] & LVAR_USED)) continue;
  if (idUScore == v[i]) continue;
  rb_compile_warn(ruby_sourcefile, (int)u[i], "assigned but unused variable - %s", rb_id2name(v[i]));
    }
}

static void
local_push_gen(struct parser_params *parser, int inherit_dvars)
{
    struct local_vars *local;

    local = ALLOC(struct local_vars);
    local->prev = lvtbl;
    local->args = vtable_alloc(0);
    local->vars = vtable_alloc(inherit_dvars ? DVARS_INHERIT : DVARS_TOPSCOPE);
    local->used = !inherit_dvars && RTEST(ruby_verbose) ? vtable_alloc(0) : 0;
    lvtbl = local;
}

static void
local_pop_gen(struct parser_params *parser)
{
    struct local_vars *local = lvtbl->prev;
    if (lvtbl->used) {
  warn_unused_var(parser, lvtbl);
  vtable_free(lvtbl->used);
    }
    vtable_free(lvtbl->args);
    vtable_free(lvtbl->vars);
    xfree(lvtbl);
    lvtbl = local;
}

static int
arg_var_gen(struct parser_params *parser, ID id)
{
    vtable_add(lvtbl->args, id);
    return vtable_size(lvtbl->args) - 1;
}

static int
local_var_gen(struct parser_params *parser, ID id)
{
    vtable_add(lvtbl->vars, id);
    if (lvtbl->used) {
  vtable_add(lvtbl->used, (ID)ruby_sourceline);
    }
    return vtable_size(lvtbl->vars) - 1;
}

static int
local_id_gen(struct parser_params *parser, ID id)
{
    struct vtable *vars, *args, *used;

    vars = lvtbl->vars;
    args = lvtbl->args;
    used = lvtbl->used;

    while (vars && POINTER_P(vars->prev)) {
  vars = vars->prev;
  args = args->prev;
  if (used) used = used->prev;
    }

    if (vars && vars->prev == DVARS_INHERIT) {
  return rb_local_defined(id);
    }
    else if (vtable_included(args, id)) {
  return 1;
    }
    else {
  int i = vtable_included(vars, id);
  if (i && used) used->tbl[i-1] |= LVAR_USED;
  return i != 0;
    }
}

static const struct vtable *
dyna_push_gen(struct parser_params *parser)
{
    lvtbl->args = vtable_alloc(lvtbl->args);
    lvtbl->vars = vtable_alloc(lvtbl->vars);
    if (lvtbl->used) {
  lvtbl->used = vtable_alloc(lvtbl->used);
    }
    return lvtbl->args;
}

static void
dyna_pop_1(struct parser_params *parser)
{
    struct vtable *tmp;

    if ((tmp = lvtbl->used) != 0) {
  warn_unused_var(parser, lvtbl);
  lvtbl->used = lvtbl->used->prev;
  vtable_free(tmp);
    }
    tmp = lvtbl->args;
    lvtbl->args = lvtbl->args->prev;
    vtable_free(tmp);
    tmp = lvtbl->vars;
    lvtbl->vars = lvtbl->vars->prev;
    vtable_free(tmp);
}

static void
dyna_pop_gen(struct parser_params *parser, const struct vtable *lvargs)
{
    while (lvtbl->args != lvargs) {
  dyna_pop_1(parser);
  if (!lvtbl->args) {
      struct local_vars *local = lvtbl->prev;
      xfree(lvtbl);
      lvtbl = local;
  }
    }
    dyna_pop_1(parser);
}

static int
dyna_in_block_gen(struct parser_params *parser)
{
    return POINTER_P(lvtbl->vars) && lvtbl->vars->prev != DVARS_TOPSCOPE;
}

static int
dvar_defined_gen(struct parser_params *parser, ID id, int get)
{
    struct vtable *vars, *args, *used;
    int i;

    args = lvtbl->args;
    vars = lvtbl->vars;
    used = lvtbl->used;

    while (POINTER_P(vars)) {
  if (vtable_included(args, id)) {
      return 1;
  }
  if ((i = vtable_included(vars, id)) != 0) {
      if (used) used->tbl[i-1] |= LVAR_USED;
      return 1;
  }
  args = args->prev;
  vars = vars->prev;
  if (get) used = 0;
  if (used) used = used->prev;
    }

    if (vars == DVARS_INHERIT) {
        return rb_dvar_defined(id);
    }

    return 0;
}

static int
dvar_curr_gen(struct parser_params *parser, ID id)
{
    return (vtable_included(lvtbl->args, id) ||
      vtable_included(lvtbl->vars, id));
}

static ID
internal_id_gen(struct parser_params *parser)
{
    ID id = (ID)vtable_size(lvtbl->args) + (ID)vtable_size(lvtbl->vars);
    id += ((tLAST_TOKEN - ID_INTERNAL) >> ID_SCOPE_SHIFT) + 1;
    return ID_INTERNAL | (id << ID_SCOPE_SHIFT);
}

static void
parser_initialize(struct parser_params *parser)
{
    parser->eofp = Qfalse;

    parser->parser_lex_strterm = 0;
    parser->parser_cond_stack = 0;
    parser->parser_cmdarg_stack = 0;
    parser->parser_class_nest = 0;
    parser->parser_paren_nest = 0;
    parser->parser_lpar_beg = 0;
    parser->parser_in_single = 0;
    parser->parser_in_def = 0;
    parser->parser_in_defined = 0;
    parser->parser_compile_for_eval = 0;
    parser->parser_cur_mid = 0;
    parser->parser_tokenbuf = NULL;
    parser->parser_tokidx = 0;
    parser->parser_toksiz = 0;
    parser->parser_heredoc_end = 0;
    parser->parser_command_start = TRUE;
    parser->parser_deferred_nodes = 0;
    parser->parser_lex_pbeg = 0;
    parser->parser_lex_p = 0;
    parser->parser_lex_pend = 0;
    parser->parser_lvtbl = 0;
    parser->parser_ruby__end__seen = 0;
    parser->parser_ruby_sourcefile = 0;

    parser->is_redtree = 1;
    parser->parser_ruby_sourcefile_string = Qnil;
    parser->delayed = Qnil;

    parser->result = Qnil;
    parser->parsing_thread = Qnil;
    parser->toplevel_p = TRUE;
#ifdef YYMALLOC
    parser->heap = NULL;
#endif
    parser->enc = rb_usascii_encoding();
}

#define parser_mark redtree_parser_mark
#define parser_free redtree_parser_free

static void
parser_mark(void *ptr)
{
    struct parser_params *p = (struct parser_params*)ptr;

    rb_gc_mark((VALUE)p->parser_lex_strterm);
    rb_gc_mark((VALUE)p->parser_deferred_nodes);
    rb_gc_mark(p->parser_lex_input);
    rb_gc_mark(p->parser_lex_lastline);
    rb_gc_mark(p->parser_lex_nextline);
    rb_gc_mark(p->parser_ruby_sourcefile_string);
    rb_gc_mark(p->delayed);
    rb_gc_mark(p->value);
    rb_gc_mark(p->result);
    rb_gc_mark(p->parsing_thread);
#ifdef YYMALLOC
    rb_gc_mark((VALUE)p->heap);
#endif
}

static void
parser_free(void *ptr)
{
    struct parser_params *p = (struct parser_params*)ptr;
    struct local_vars *local, *prev;

    if (p->parser_tokenbuf) {
        xfree(p->parser_tokenbuf);
    }
    for (local = p->parser_lvtbl; local; local = prev) {
  if (local->vars) xfree(local->vars);
  prev = local->prev;
  xfree(local);
    }
    xfree(p);
}

static size_t
parser_memsize(const void *ptr)
{
    struct parser_params *p = (struct parser_params*)ptr;
    struct local_vars *local;
    size_t size = sizeof(*p);

    if (!ptr) return 0;
    size += p->parser_toksiz;
    for (local = p->parser_lvtbl; local; local = local->prev) {
  size += sizeof(*local);
  if (local->vars) size += local->vars->capa * sizeof(ID);
    }
    return size;
}

static const rb_data_type_t parser_data_type = {
    "parser",
    {
  parser_mark,
  parser_free,
  parser_memsize,
    },
};

#define validate(x) ((x) = get_value(x))

static VALUE
redtree_dispatch0(struct parser_params *parser, ID mid)
{
    return rb_funcall(parser->value, mid, 0);
}

static VALUE
redtree_dispatch1(struct parser_params *parser, ID mid, VALUE a)
{
    validate(a);
    return rb_funcall(parser->value, mid, 1, a);
}

static VALUE
redtree_dispatch2(struct parser_params *parser, ID mid, VALUE a, VALUE b)
{
    validate(a);
    validate(b);
    return rb_funcall(parser->value, mid, 2, a, b);
}

static VALUE
redtree_dispatch3(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c)
{
    validate(a);
    validate(b);
    validate(c);
    return rb_funcall(parser->value, mid, 3, a, b, c);
}

static VALUE
redtree_dispatch4(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c, VALUE d)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    return rb_funcall(parser->value, mid, 4, a, b, c, d);
}

static VALUE
redtree_dispatch5(struct parser_params *parser, ID mid, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    validate(e);
    return rb_funcall(parser->value, mid, 5, a, b, c, d, e);
}

static const struct kw_assoc {
    ID id;
    const char *name;
} keyword_to_name[] = {
    {keyword_class, "class"},
    {keyword_module,  "module"},
    {keyword_def, "def"},
    {keyword_undef, "undef"},
    {keyword_begin, "begin"},
    {keyword_rescue,  "rescue"},
    {keyword_ensure,  "ensure"},
    {keyword_end, "end"},
    {keyword_if,  "if"},
    {keyword_unless,  "unless"},
    {keyword_then,  "then"},
    {keyword_elsif, "elsif"},
    {keyword_else,  "else"},
    {keyword_case,  "case"},
    {keyword_when,  "when"},
    {keyword_while, "while"},
    {keyword_until, "until"},
    {keyword_for, "for"},
    {keyword_break, "break"},
    {keyword_next,  "next"},
    {keyword_redo,  "redo"},
    {keyword_retry, "retry"},
    {keyword_in,  "in"},
    {keyword_do,  "do"},
    {keyword_do_cond, "do"},
    {keyword_do_block,  "do"},
    {keyword_return,  "return"},
    {keyword_yield, "yield"},
    {keyword_super, "super"},
    {keyword_self,  "self"},
    {keyword_nil, "nil"},
    {keyword_true,  "true"},
    {keyword_false, "false"},
    {keyword_and, "and"},
    {keyword_or,  "or"},
    {keyword_not, "not"},
    {modifier_if, "if"},
    {modifier_unless, "unless"},
    {modifier_while,  "while"},
    {modifier_until,  "until"},
    {modifier_rescue, "rescue"},
    {keyword_alias, "alias"},
    {keyword_defined, "defined?"},
    {keyword_BEGIN, "BEGIN"},
    {keyword_END, "END"},
    {keyword__LINE__, "__LINE__"},
    {keyword__FILE__, "__FILE__"},
    {keyword__ENCODING__, "__ENCODING__"},
    {0, NULL}
};

static const char*
keyword_id_to_str(ID id)
{
    const struct kw_assoc *a;

    for (a = keyword_to_name; a->id; a++) {
        if (a->id == id)
            return a->name;
    }
    return NULL;
}

#undef redtree_id2sym
static VALUE
redtree_id2sym(ID id)
{
    const char *name;
    char buf[8];

    if (id <= 256) {
        buf[0] = (char)id;
        buf[1] = '\0';
        return ID2SYM(rb_intern2(buf, 1));
    }
    if ((name = keyword_id_to_str(id))) {
        return ID2SYM(rb_intern(name));
    }
    switch (id) {
      case tOROP:
        name = "||";
        break;
      case tANDOP:
        name = "&&";
        break;
      default:
        name = rb_id2name(id);
        if (!name) {
            rb_bug("cannot convert ID to string: %ld", (unsigned long)id);
        }
        return ID2SYM(id);
    }
    return ID2SYM(rb_intern(name));
}

static ID
redtree_get_id(VALUE v)
{
    NODE *nd;
    if (!RB_TYPE_P(v, T_NODE)) return 0;
    nd = (NODE *)v;
    if (nd_type(nd) != NODE_LASGN) return 0;
    return nd->nd_vid;
}

static VALUE
redtree_get_value(VALUE v)
{
    NODE *nd;
    if (v == Qundef) return Qnil;
    if (!RB_TYPE_P(v, T_NODE)) return v;
    nd = (NODE *)v;
    if (nd_type(nd) != NODE_LASGN) return Qnil;
    return nd->nd_rval;
}

static void
redtree_compile_error(struct parser_params *parser, const char *fmt, ...)
{
    VALUE str;
    va_list args;

    va_start(args, fmt);
    str = rb_vsprintf(fmt, args);
    va_end(args);
    rb_funcall(parser->value, rb_intern("compile_error"), 1, str);
}

static void
redtree_warn0(struct parser_params *parser, const char *fmt)
{
    rb_funcall(parser->value, rb_intern("warn"), 1, STR_NEW2(fmt));
}

static void
redtree_warnI(struct parser_params *parser, const char *fmt, int a)
{
    rb_funcall(parser->value, rb_intern("warn"), 2,
               STR_NEW2(fmt), INT2NUM(a));
}

static void
redtree_warning0(struct parser_params *parser, const char *fmt)
{
    rb_funcall(parser->value, rb_intern("warning"), 1, STR_NEW2(fmt));
}

static void
redtree_warningS(struct parser_params *parser, const char *fmt, const char *str)
{
    rb_funcall(parser->value, rb_intern("warning"), 2,
               STR_NEW2(fmt), STR_NEW2(str));
}

static VALUE
redtree_lex_get_generic(struct parser_params *parser, VALUE src)
{
    return rb_funcall(src, redtree_id_gets, 0);
}

static VALUE
redtree_s_allocate(VALUE klass)
{
    struct parser_params *p;
    VALUE self;

    p = ALLOC_N(struct parser_params, 1);
    MEMZERO(p, struct parser_params, 1);
    self = TypedData_Wrap_Struct(klass, &parser_data_type, p);
    p->value = self;
    return self;
}

#define redtree_initialized_p(r) ((r)->parser_lex_input != 0)

/*
 *  call-seq:
 *    Redtree.new(src, filename="(redtree)", lineno=1) -> redtree
 *
 *  Create a new Redtree object.
 *  _src_ must be a String, an IO, or an Object which has #gets method.
 *
 *  This method does not starts parsing.
 *  See also Redtree#parse and Redtree.parse.
 */
static VALUE
redtree_initialize(int argc, VALUE *argv, VALUE self)
{
    struct parser_params *parser;
    VALUE src, fname, lineno;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    rb_scan_args(argc, argv, "12", &src, &fname, &lineno);
    if (rb_obj_respond_to(src, redtree_id_gets, 0)) {
        parser->parser_lex_gets = redtree_lex_get_generic;
    }
    else {
        StringValue(src);
        parser->parser_lex_gets = lex_get_str;
    }
    parser->parser_lex_input = src;
    parser->eofp = Qfalse;
    if (NIL_P(fname)) {
        fname = STR_NEW2("(redtree)");
    }
    else {
        StringValue(fname);
    }
    parser_initialize(parser);

    parser->parser_ruby_sourcefile_string = fname;
    parser->parser_ruby_sourcefile = RSTRING_PTR(fname);
    parser->parser_ruby_sourceline = NIL_P(lineno) ? 0 : NUM2INT(lineno) - 1;

    return Qnil;
}

struct redtree_args {
    struct parser_params *parser;
    int argc;
    VALUE *argv;
};

static VALUE
redtree_parse0(VALUE parser_v)
{
    struct parser_params *parser;

    TypedData_Get_Struct(parser_v, struct parser_params, &parser_data_type, parser);
    parser_prepare(parser);
    redtree_yyparse((void*)parser);
    return parser->result;
}

static VALUE
redtree_ensure(VALUE parser_v)
{
    struct parser_params *parser;

    TypedData_Get_Struct(parser_v, struct parser_params, &parser_data_type, parser);
    parser->parsing_thread = Qnil;
    return Qnil;
}

/*
 *  call-seq:
 *    redtree#parse
 *
 *  Start parsing and returns the value of the root action.
 */
static VALUE
redtree_parse(VALUE self)
{
    struct parser_params *parser;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    if (!redtree_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (!NIL_P(parser->parsing_thread)) {
        if (parser->parsing_thread == rb_thread_current())
            rb_raise(rb_eArgError, "Redtree#parse is not reentrant");
        else
            rb_raise(rb_eArgError, "Redtree#parse is not multithread-safe");
    }
    parser->parsing_thread = rb_thread_current();
    rb_ensure(redtree_parse0, self, redtree_ensure, self);

    return parser->result;
}

/*
 *  call-seq:
 *    redtree#column   -> Integer
 *
 *  Return column number of current parsing line.
 *  This number starts from 0.
 */
static VALUE
redtree_column(VALUE self)
{
    struct parser_params *parser;
    long col;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    if (!redtree_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (NIL_P(parser->parsing_thread)) return Qnil;
    col = parser->tokp - parser->parser_lex_pbeg;
    return LONG2NUM(col);
}

/*
 *  call-seq:
 *    redtree#filename   -> String
 *
 *  Return current parsing filename.
 */
static VALUE
redtree_filename(VALUE self)
{
    struct parser_params *parser;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    if (!redtree_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    return parser->parser_ruby_sourcefile_string;
}

/*
 *  call-seq:
 *    redtree#lineno   -> Integer
 *
 *  Return line number of current parsing line.
 *  This number starts from 1.
 */
static VALUE
redtree_lineno(VALUE self)
{
    struct parser_params *parser;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    if (!redtree_initialized_p(parser)) {
        rb_raise(rb_eArgError, "method called for uninitialized object");
    }
    if (NIL_P(parser->parsing_thread)) return Qnil;
    return INT2NUM(parser->parser_ruby_sourceline);
}

void
Init_redtree(void)
{
    VALUE Redtree;

    Redtree = rb_define_class("Redtree", rb_cObject);
    rb_define_const(Redtree, "Version", rb_usascii_str_new2(Redtree_VERSION));
    rb_define_alloc_func(Redtree, redtree_s_allocate);
    rb_define_method(Redtree, "initialize", redtree_initialize, -1);
    rb_define_method(Redtree, "parse", redtree_parse, 0);
    rb_define_method(Redtree, "column", redtree_column, 0);
    rb_define_method(Redtree, "filename", redtree_filename, 0);
    rb_define_method(Redtree, "lineno", redtree_lineno, 0);
    rb_define_method(Redtree, "end_seen?", rb_parser_end_seen_p, 0);
    rb_define_method(Redtree, "encoding", rb_parser_encoding, 0);
    rb_define_method(Redtree, "yydebug", rb_parser_get_yydebug, 0);
    rb_define_method(Redtree, "yydebug=", rb_parser_set_yydebug, 1);

    redtree_id_gets = rb_intern("gets");
    redtree_init_eventids1(Redtree);
    redtree_init_eventids2(Redtree);
    /* ensure existing in symbol table */
    (void)rb_intern("||");
    (void)rb_intern("&&");
}
