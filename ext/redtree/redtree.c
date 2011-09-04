/* A Bison parser, made by GNU Bison 2.3.  */

/* Skeleton implementation for Bison's Yacc-like parsers in C

   Copyright (C) 1984, 1989, 1990, 2000, 2001, 2002, 2003, 2004, 2005, 2006
   Free Software Foundation, Inc.

   This program is free software; you can redistribute it and/or modify
   it under the terms of the GNU General Public License as published by
   the Free Software Foundation; either version 2, or (at your option)
   any later version.

   This program is distributed in the hope that it will be useful,
   but WITHOUT ANY WARRANTY; without even the implied warranty of
   MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
   GNU General Public License for more details.

   You should have received a copy of the GNU General Public License
   along with this program; if not, write to the Free Software
   Foundation, Inc., 51 Franklin Street, Fifth Floor,
   Boston, MA 02110-1301, USA.  */

/* As a special exception, you may create a larger work that contains
   part or all of the Bison parser skeleton and distribute that work
   under terms of your choice, so long as that work isn't itself a
   parser generator using the skeleton or a modified version thereof
   as a parser skeleton.  Alternatively, if you modify or redistribute
   the parser skeleton itself, you may (at your option) remove this
   special exception, which will cause the skeleton and the resulting
   Bison output files to be licensed under the GNU General Public
   License without this special exception.

   This special exception was added by the Free Software Foundation in
   version 2.2 of Bison.  */

/* C LALR(1) parser skeleton written by Richard Stallman, by
   simplifying the original so-called "semantic" parser.  */

/* All symbols defined below should begin with yy or YY, to avoid
   infringing on user name space.  This should be done even for local
   variables, as they might otherwise be expanded by user macros.
   There are some unavoidable exceptions within include files to
   define necessary library symbols; they are noted "INFRINGES ON
   USER NAME SPACE" below.  */

/* Identify Bison output.  */
#define YYBISON 1

/* Bison version.  */
#define YYBISON_VERSION "2.3"

/* Skeleton name.  */
#define YYSKELETON_NAME "yacc.c"

/* Pure parsers.  */
#define YYPURE 1

/* Using locations.  */
#define YYLSP_NEEDED 0



/* Tokens.  */
#ifndef YYTOKENTYPE
# define YYTOKENTYPE
   /* Put the tokens into the symbol table, so that GDB and other debuggers
      know about them.  */
   enum yytokentype {
     keyword_class = 258,
     keyword_module = 259,
     keyword_def = 260,
     keyword_undef = 261,
     keyword_begin = 262,
     keyword_rescue = 263,
     keyword_ensure = 264,
     keyword_end = 265,
     keyword_if = 266,
     keyword_unless = 267,
     keyword_then = 268,
     keyword_elsif = 269,
     keyword_else = 270,
     keyword_case = 271,
     keyword_when = 272,
     keyword_while = 273,
     keyword_until = 274,
     keyword_for = 275,
     keyword_break = 276,
     keyword_next = 277,
     keyword_redo = 278,
     keyword_retry = 279,
     keyword_in = 280,
     keyword_do = 281,
     keyword_do_cond = 282,
     keyword_do_block = 283,
     keyword_do_LAMBDA = 284,
     keyword_return = 285,
     keyword_yield = 286,
     keyword_super = 287,
     keyword_self = 288,
     keyword_nil = 289,
     keyword_true = 290,
     keyword_false = 291,
     keyword_and = 292,
     keyword_or = 293,
     keyword_not = 294,
     modifier_if = 295,
     modifier_unless = 296,
     modifier_while = 297,
     modifier_until = 298,
     modifier_rescue = 299,
     keyword_alias = 300,
     keyword_defined = 301,
     keyword_BEGIN = 302,
     keyword_END = 303,
     keyword__LINE__ = 304,
     keyword__FILE__ = 305,
     keyword__ENCODING__ = 306,
     tIDENTIFIER = 307,
     tFID = 308,
     tGVAR = 309,
     tIVAR = 310,
     tCONSTANT = 311,
     tCVAR = 312,
     tLABEL = 313,
     tINTEGER = 314,
     tFLOAT = 315,
     tSTRING_CONTENT = 316,
     tCHAR = 317,
     tNTH_REF = 318,
     tBACK_REF = 319,
     tREGEXP_END = 320,
     tUPLUS = 321,
     tUMINUS = 322,
     tPOW = 323,
     tCMP = 324,
     tEQ = 325,
     tEQQ = 326,
     tNEQ = 327,
     tGEQ = 328,
     tLEQ = 329,
     tANDOP = 330,
     tOROP = 331,
     tMATCH = 332,
     tNMATCH = 333,
     tDOT2 = 334,
     tDOT3 = 335,
     tAREF = 336,
     tASET = 337,
     tLSHFT = 338,
     tRSHFT = 339,
     tCOLON2 = 340,
     tCOLON3 = 341,
     tOP_ASGN = 342,
     tASSOC = 343,
     tLPAREN = 344,
     tLPAREN_ARG = 345,
     tRPAREN = 346,
     tLBRACK = 347,
     tLBRACE = 348,
     tLBRACE_ARG = 349,
     tSTAR = 350,
     tAMPER = 351,
     tLAMBDA = 352,
     tSYMBEG = 353,
     tSTRING_BEG = 354,
     tXSTRING_BEG = 355,
     tREGEXP_BEG = 356,
     tWORDS_BEG = 357,
     tQWORDS_BEG = 358,
     tSTRING_DBEG = 359,
     tSTRING_DVAR = 360,
     tSTRING_END = 361,
     tLAMBEG = 362,
     tLOWEST = 363,
     tUMINUS_NUM = 364,
     idNULL = 365,
     idRespond_to = 366,
     idIFUNC = 367,
     idCFUNC = 368,
     id_core_set_method_alias = 369,
     id_core_set_variable_alias = 370,
     id_core_undef_method = 371,
     id_core_define_method = 372,
     id_core_define_singleton_method = 373,
     id_core_set_postexe = 374,
     tLAST_TOKEN = 375
   };
#endif
/* Tokens.  */
#define keyword_class 258
#define keyword_module 259
#define keyword_def 260
#define keyword_undef 261
#define keyword_begin 262
#define keyword_rescue 263
#define keyword_ensure 264
#define keyword_end 265
#define keyword_if 266
#define keyword_unless 267
#define keyword_then 268
#define keyword_elsif 269
#define keyword_else 270
#define keyword_case 271
#define keyword_when 272
#define keyword_while 273
#define keyword_until 274
#define keyword_for 275
#define keyword_break 276
#define keyword_next 277
#define keyword_redo 278
#define keyword_retry 279
#define keyword_in 280
#define keyword_do 281
#define keyword_do_cond 282
#define keyword_do_block 283
#define keyword_do_LAMBDA 284
#define keyword_return 285
#define keyword_yield 286
#define keyword_super 287
#define keyword_self 288
#define keyword_nil 289
#define keyword_true 290
#define keyword_false 291
#define keyword_and 292
#define keyword_or 293
#define keyword_not 294
#define modifier_if 295
#define modifier_unless 296
#define modifier_while 297
#define modifier_until 298
#define modifier_rescue 299
#define keyword_alias 300
#define keyword_defined 301
#define keyword_BEGIN 302
#define keyword_END 303
#define keyword__LINE__ 304
#define keyword__FILE__ 305
#define keyword__ENCODING__ 306
#define tIDENTIFIER 307
#define tFID 308
#define tGVAR 309
#define tIVAR 310
#define tCONSTANT 311
#define tCVAR 312
#define tLABEL 313
#define tINTEGER 314
#define tFLOAT 315
#define tSTRING_CONTENT 316
#define tCHAR 317
#define tNTH_REF 318
#define tBACK_REF 319
#define tREGEXP_END 320
#define tUPLUS 321
#define tUMINUS 322
#define tPOW 323
#define tCMP 324
#define tEQ 325
#define tEQQ 326
#define tNEQ 327
#define tGEQ 328
#define tLEQ 329
#define tANDOP 330
#define tOROP 331
#define tMATCH 332
#define tNMATCH 333
#define tDOT2 334
#define tDOT3 335
#define tAREF 336
#define tASET 337
#define tLSHFT 338
#define tRSHFT 339
#define tCOLON2 340
#define tCOLON3 341
#define tOP_ASGN 342
#define tASSOC 343
#define tLPAREN 344
#define tLPAREN_ARG 345
#define tRPAREN 346
#define tLBRACK 347
#define tLBRACE 348
#define tLBRACE_ARG 349
#define tSTAR 350
#define tAMPER 351
#define tLAMBDA 352
#define tSYMBEG 353
#define tSTRING_BEG 354
#define tXSTRING_BEG 355
#define tREGEXP_BEG 356
#define tWORDS_BEG 357
#define tQWORDS_BEG 358
#define tSTRING_DBEG 359
#define tSTRING_DVAR 360
#define tSTRING_END 361
#define tLAMBEG 362
#define tLOWEST 363
#define tUMINUS_NUM 364
#define idNULL 365
#define idRespond_to 366
#define idIFUNC 367
#define idCFUNC 368
#define id_core_set_method_alias 369
#define id_core_set_variable_alias 370
#define id_core_undef_method 371
#define id_core_define_method 372
#define id_core_define_singleton_method 373
#define id_core_set_postexe 374
#define tLAST_TOKEN 375




/* Copy the first part of user declarations.  */
#line 12 "redtree.y"


#define YYDEBUG 1
#define YYERROR_VERBOSE 1
#define YYSTACK_USE_ALLOCA 0

#include "ruby/ruby.h"
#include "ruby/st.h"
#include "ruby/encoding.h"
#include "internal.h"
#include "node.h"
#include "redtree.h"
#include "id.h"
#include "regenc.h"
#include <stdint.h>
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

struct parse_stack {
    int32_t *stack;
    uint32_t pos;
    uint32_t capa;
};
struct parse_stack *new_redtree_stack();
int32_t* redtree_stack_pop_n_volatile(struct parser_params* parser,
                                      unsigned int n);
int32_t* redtree_stack_pop_n(struct parser_params* parser, unsigned int n);
void redtree_stack_push(struct parser_params* parser, int32_t val);

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
  int32_t *sequence;
  uint32_t token_count;
  uint32_t sequence_count;
  uint32_t token_size;
  uint32_t sequence_size;
};

struct redtree* redtree_allocate();
void redtree_init_struct(struct redtree* tree, VALUE source);
void redtree_lex_token(struct redtree* tree,
                       redtree_token token_type,
                       uint32_t token_start_line,
                       uint32_t token_end_line,
                       uint16_t token_start_col,
                       uint16_t token_end_col);
void redtree_shift_token(struct redtree* tree, uint32_t token_index);
void redtree_reduce_rule(struct redtree* tree, uint32_t rule_index);
void redtree_sequence_push(struct redtree* tree, int32_t entry);

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
    struct redtree *parse_tree;
    struct parse_stack *redtree_stack;
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

#define DEFAULT_PARSE_STACK_SIZE 32
struct parse_stack *new_redtree_stack() {
    struct parse_stack* result = ALLOC_N(struct parse_stack, 1);
    result->stack = ALLOC_N(int32_t, DEFAULT_PARSE_STACK_SIZE);
    result->pos = 0;
    result->capa = DEFAULT_PARSE_STACK_SIZE;
    return result;
}
#undef DEFAULT_PARSE_STACK_SIZE

int32_t* redtree_stack_pop_n_volatile(struct parser_params* parser,
                                      unsigned int n) {
    struct parse_stack* stack = parser->redtree_stack;
    stack->pos -= n;
    if (yydebug) {
      fprintf(stderr, "Redtree: Popped %d from stack.. Stack size %d. \n", n, stack->pos);
    }
    return stack->stack + stack->pos;
}

int32_t* redtree_stack_pop_n(struct parser_params* parser, unsigned int n) {
  int32_t* result = ALLOC_N(int32_t, n);
  memcpy(result, redtree_stack_pop_n_volatile(parser, n), sizeof(int32_t) * n);
  return result;
}

void redtree_stack_push(struct parser_params* parser, int32_t val) {
    struct parse_stack* stack = parser->redtree_stack;
    *(stack->stack + stack->pos) = val;
    ++stack->pos;
    if (yydebug) {
      fprintf(stderr, "Redtree: Pushed token %d. Stack size %d. \n", val, stack->pos);
    }
    if (stack->pos == stack->capa) {
      stack->capa *= 2;
      stack->stack = REALLOC_N(stack->stack, int32_t, stack->capa);
    }
}

#define Redtree_VERSION "0.1.0"

#include "eventids1.c"
static ID redtree_id_gets;

static void redtree_reduce(struct parser_params *parser, int redtree_rule_num, int rhs_size);
static VALUE redtree_dispatch0(struct parser_params*,ID);
static VALUE redtree_dispatch1(struct parser_params*,ID,VALUE);
static VALUE redtree_dispatch2(struct parser_params*,ID,VALUE,VALUE);
static VALUE redtree_dispatch3(struct parser_params*,ID,VALUE,VALUE,VALUE);
static VALUE redtree_dispatch4(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE);
static VALUE redtree_dispatch5(struct parser_params*,ID,VALUE,VALUE,VALUE,VALUE,VALUE);

#define reduce_rule(name, size) redtree_reduce(parser, TOKEN_PASTE(redtree_rulenum_, name), size)

#define yyparse redtree_yyparse

#define redtree_intern(s) ID2SYM(rb_intern(s))
static VALUE redtree_id2sym(ID);
#ifdef __GNUC__
#define redtree_id2sym(id) ((id) < 256 && rb_ispunct(id) ? \
         ID2SYM(id) : redtree_id2sym(id))
#endif

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


/* Enabling traces.  */
#ifndef YYDEBUG
# define YYDEBUG 1
#endif

/* Enabling verbose error messages.  */
#ifdef YYERROR_VERBOSE
# undef YYERROR_VERBOSE
# define YYERROR_VERBOSE 1
#else
# define YYERROR_VERBOSE 0
#endif

/* Enabling the token table.  */
#ifndef YYTOKEN_TABLE
# define YYTOKEN_TABLE 0
#endif

#if ! defined YYSTYPE && ! defined YYSTYPE_IS_DECLARED
typedef union YYSTYPE
#line 564 "redtree.y"
{
    int num;
    NODE *node;
    ID id;
    const struct vtable *vars;
}
/* Line 193 of yacc.c.  */
#line 892 "ripper.c"
	YYSTYPE;
# define yystype YYSTYPE /* obsolescent; will be withdrawn */
# define YYSTYPE_IS_DECLARED 1
# define YYSTYPE_IS_TRIVIAL 1
#endif



/* Copy the second part of user declarations.  */


/* Line 216 of yacc.c.  */
#line 905 "ripper.c"

#ifdef short
# undef short
#endif

#ifdef YYTYPE_UINT8
typedef YYTYPE_UINT8 yytype_uint8;
#else
typedef unsigned char yytype_uint8;
#endif

#ifdef YYTYPE_INT8
typedef YYTYPE_INT8 yytype_int8;
#elif (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
typedef signed char yytype_int8;
#else
typedef short int yytype_int8;
#endif

#ifdef YYTYPE_UINT16
typedef YYTYPE_UINT16 yytype_uint16;
#else
typedef unsigned short int yytype_uint16;
#endif

#ifdef YYTYPE_INT16
typedef YYTYPE_INT16 yytype_int16;
#else
typedef short int yytype_int16;
#endif

#ifndef YYSIZE_T
# ifdef __SIZE_TYPE__
#  define YYSIZE_T __SIZE_TYPE__
# elif defined size_t
#  define YYSIZE_T size_t
# elif ! defined YYSIZE_T && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#  include <stddef.h> /* INFRINGES ON USER NAME SPACE */
#  define YYSIZE_T size_t
# else
#  define YYSIZE_T unsigned int
# endif
#endif

#define YYSIZE_MAXIMUM ((YYSIZE_T) -1)

#ifndef YY_
# if defined YYENABLE_NLS && YYENABLE_NLS
#  if ENABLE_NLS
#   include <libintl.h> /* INFRINGES ON USER NAME SPACE */
#   define YY_(msgid) dgettext ("bison-runtime", msgid)
#  endif
# endif
# ifndef YY_
#  define YY_(msgid) msgid
# endif
#endif

/* Suppress unused-variable warnings by "using" E.  */
#if ! defined lint || defined __GNUC__
# define YYUSE(e) ((void) (e))
#else
# define YYUSE(e) /* empty */
#endif

/* Identity function, used to suppress warnings about constant conditions.  */
#ifndef lint
# define YYID(n) (n)
#else
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static int
YYID (int i)
#else
static int
YYID (i)
    int i;
#endif
{
  return i;
}
#endif

#if ! defined yyoverflow || YYERROR_VERBOSE

/* The parser invokes alloca or malloc; define the necessary symbols.  */

# ifdef YYSTACK_USE_ALLOCA
#  if YYSTACK_USE_ALLOCA
#   ifdef __GNUC__
#    define YYSTACK_ALLOC __builtin_alloca
#   elif defined __BUILTIN_VA_ARG_INCR
#    include <alloca.h> /* INFRINGES ON USER NAME SPACE */
#   elif defined _AIX
#    define YYSTACK_ALLOC __alloca
#   elif defined _MSC_VER
#    include <malloc.h> /* INFRINGES ON USER NAME SPACE */
#    define alloca _alloca
#   else
#    define YYSTACK_ALLOC alloca
#    if ! defined _ALLOCA_H && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
#     include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#     ifndef _STDLIB_H
#      define _STDLIB_H 1
#     endif
#    endif
#   endif
#  endif
# endif

# ifdef YYSTACK_ALLOC
   /* Pacify GCC's `empty if-body' warning.  */
#  define YYSTACK_FREE(Ptr) do { /* empty */; } while (YYID (0))
#  ifndef YYSTACK_ALLOC_MAXIMUM
    /* The OS might guarantee only one guard page at the bottom of the stack,
       and a page size can be as small as 4096 bytes.  So we cannot safely
       invoke alloca (N) if N exceeds 4096.  Use a slightly smaller number
       to allow for a few compiler-allocated temporary stack slots.  */
#   define YYSTACK_ALLOC_MAXIMUM 4032 /* reasonable circa 2006 */
#  endif
# else
#  define YYSTACK_ALLOC YYMALLOC
#  define YYSTACK_FREE YYFREE
#  ifndef YYSTACK_ALLOC_MAXIMUM
#   define YYSTACK_ALLOC_MAXIMUM YYSIZE_MAXIMUM
#  endif
#  if (defined __cplusplus && ! defined _STDLIB_H \
       && ! ((defined YYMALLOC || defined malloc) \
	     && (defined YYFREE || defined free)))
#   include <stdlib.h> /* INFRINGES ON USER NAME SPACE */
#   ifndef _STDLIB_H
#    define _STDLIB_H 1
#   endif
#  endif
#  ifndef YYMALLOC
#   define YYMALLOC malloc
#   if ! defined malloc && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void *malloc (YYSIZE_T); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
#  ifndef YYFREE
#   define YYFREE free
#   if ! defined free && ! defined _STDLIB_H && (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
void free (void *); /* INFRINGES ON USER NAME SPACE */
#   endif
#  endif
# endif
#endif /* ! defined yyoverflow || YYERROR_VERBOSE */


#if (! defined yyoverflow \
     && (! defined __cplusplus \
	 || (defined YYSTYPE_IS_TRIVIAL && YYSTYPE_IS_TRIVIAL)))

/* A type that is properly aligned for any stack member.  */
union yyalloc
{
  yytype_int16 yyss;
  YYSTYPE yyvs;
  };

/* The size of the maximum gap between one aligned stack and the next.  */
# define YYSTACK_GAP_MAXIMUM (sizeof (union yyalloc) - 1)

/* The size of an array large to enough to hold all stacks, each with
   N elements.  */
# define YYSTACK_BYTES(N) \
     ((N) * (sizeof (yytype_int16) + sizeof (YYSTYPE)) \
      + YYSTACK_GAP_MAXIMUM)

/* Copy COUNT objects from FROM to TO.  The source and destination do
   not overlap.  */
# ifndef YYCOPY
#  if defined __GNUC__ && 1 < __GNUC__
#   define YYCOPY(To, From, Count) \
      __builtin_memcpy (To, From, (Count) * sizeof (*(From)))
#  else
#   define YYCOPY(To, From, Count)		\
      do					\
	{					\
	  YYSIZE_T yyi;				\
	  for (yyi = 0; yyi < (Count); yyi++)	\
	    (To)[yyi] = (From)[yyi];		\
	}					\
      while (YYID (0))
#  endif
# endif

/* Relocate STACK from its old location to the new one.  The
   local variables YYSIZE and YYSTACKSIZE give the old and new number of
   elements in the stack, and YYPTR gives the new location of the
   stack.  Advance YYPTR to a properly aligned location for the next
   stack.  */
# define YYSTACK_RELOCATE(Stack)					\
    do									\
      {									\
	YYSIZE_T yynewbytes;						\
	YYCOPY (&yyptr->Stack, Stack, yysize);				\
	Stack = &yyptr->Stack;						\
	yynewbytes = yystacksize * sizeof (*Stack) + YYSTACK_GAP_MAXIMUM; \
	yyptr += yynewbytes / sizeof (*yyptr);				\
      }									\
    while (YYID (0))

#endif

/* YYFINAL -- State number of the termination state.  */
#define YYFINAL  3
/* YYLAST -- Last index in YYTABLE.  */
#define YYLAST   10633

/* YYNTOKENS -- Number of terminals.  */
#define YYNTOKENS  148
/* YYNNTS -- Number of nonterminals.  */
#define YYNNTS  173
/* YYNRULES -- Number of rules.  */
#define YYNRULES  572
/* YYNRULES -- Number of states.  */
#define YYNSTATES  988

/* YYTRANSLATE(YYLEX) -- Bison symbol number corresponding to YYLEX.  */
#define YYUNDEFTOK  2
#define YYMAXUTOK   375

#define YYTRANSLATE(YYX)						\
  ((unsigned int) (YYX) <= YYMAXUTOK ? yytranslate[YYX] : YYUNDEFTOK)

/* YYTRANSLATE[YYLEX] -- Bison symbol number corresponding to YYLEX.  */
static const yytype_uint8 yytranslate[] =
{
       0,     2,     2,     2,     2,     2,     2,     2,     2,     2,
     147,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,   146,   111,     2,     2,     2,   124,   119,     2,
     142,   143,   122,   120,   141,   121,   140,   123,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,   116,   145,
     110,   114,   109,   115,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,   139,     2,   144,   118,     2,   108,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,   137,   117,   138,   112,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     2,     2,     2,     2,
       2,     2,     2,     2,     2,     2,     1,     2,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    27,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,    41,    42,    43,    44,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    61,    62,    63,    64,
      65,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    81,    82,    83,    84,
      85,    86,    87,    88,    89,    90,    91,    92,    93,    94,
      95,    96,    97,    98,    99,   100,   101,   102,   103,   104,
     105,   106,   107,   113,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136
};

#if YYDEBUG
/* YYPRHS[YYN] -- Index of the first RHS symbol of rule number YYN in
   YYRHS.  */
static const yytype_uint16 yyprhs[] =
{
       0,     0,     3,     4,     7,    10,    12,    14,    18,    21,
      23,    24,    30,    35,    38,    40,    42,    46,    49,    50,
      55,    59,    63,    67,    70,    74,    78,    82,    86,    90,
      95,    97,   101,   105,   112,   118,   124,   130,   136,   140,
     144,   148,   152,   154,   158,   162,   164,   168,   172,   176,
     179,   181,   183,   185,   187,   189,   194,   199,   200,   206,
     209,   213,   218,   224,   229,   235,   238,   241,   244,   247,
     250,   252,   256,   258,   262,   264,   267,   271,   277,   280,
     285,   288,   293,   295,   299,   301,   305,   308,   312,   314,
     318,   320,   322,   327,   331,   335,   339,   343,   346,   348,
     350,   352,   357,   361,   365,   369,   373,   376,   378,   380,
     382,   385,   387,   391,   393,   395,   397,   399,   401,   403,
     405,   407,   409,   411,   412,   417,   419,   421,   423,   425,
     427,   429,   431,   433,   435,   437,   439,   441,   443,   445,
     447,   449,   451,   453,   455,   457,   459,   461,   463,   465,
     467,   469,   471,   473,   475,   477,   479,   481,   483,   485,
     487,   489,   491,   493,   495,   497,   499,   501,   503,   505,
     507,   509,   511,   513,   515,   517,   519,   521,   523,   525,
     527,   529,   531,   533,   535,   537,   539,   541,   543,   545,
     547,   549,   551,   553,   555,   557,   561,   567,   571,   577,
     584,   590,   596,   602,   608,   613,   617,   621,   625,   629,
     633,   637,   641,   645,   649,   654,   659,   662,   665,   669,
     673,   677,   681,   685,   689,   693,   697,   701,   705,   709,
     713,   717,   720,   723,   727,   731,   735,   739,   740,   745,
     752,   754,   756,   758,   761,   766,   769,   773,   775,   777,
     779,   781,   784,   789,   792,   794,   797,   800,   805,   807,
     808,   811,   814,   817,   819,   821,   824,   828,   833,   837,
     842,   845,   847,   849,   851,   853,   855,   857,   859,   861,
     863,   865,   866,   871,   875,   879,   882,   886,   890,   892,
     897,   901,   903,   904,   911,   916,   920,   923,   925,   928,
     931,   938,   945,   946,   947,   955,   956,   957,   965,   971,
     976,   977,   978,   988,   989,   996,   997,   998,  1007,  1008,
    1014,  1015,  1022,  1023,  1024,  1034,  1036,  1038,  1040,  1042,
    1044,  1046,  1048,  1050,  1052,  1054,  1056,  1058,  1060,  1062,
    1064,  1066,  1068,  1070,  1073,  1075,  1077,  1079,  1085,  1087,
    1090,  1092,  1094,  1096,  1100,  1102,  1106,  1108,  1113,  1120,
    1124,  1130,  1133,  1138,  1140,  1144,  1151,  1160,  1165,  1172,
    1177,  1180,  1187,  1190,  1195,  1202,  1205,  1210,  1213,  1218,
    1220,  1222,  1224,  1228,  1230,  1235,  1237,  1240,  1242,  1246,
    1248,  1250,  1251,  1252,  1257,  1262,  1264,  1268,  1272,  1273,
    1279,  1282,  1287,  1292,  1295,  1300,  1305,  1309,  1313,  1317,
    1320,  1322,  1327,  1328,  1334,  1335,  1341,  1347,  1349,  1351,
    1358,  1360,  1362,  1364,  1366,  1369,  1371,  1374,  1376,  1378,
    1380,  1382,  1384,  1386,  1388,  1391,  1395,  1399,  1403,  1407,
    1411,  1412,  1416,  1418,  1421,  1425,  1429,  1430,  1434,  1435,
    1438,  1439,  1442,  1443,  1446,  1448,  1449,  1453,  1454,  1455,
    1461,  1463,  1465,  1467,  1469,  1472,  1474,  1476,  1478,  1480,
    1484,  1486,  1488,  1491,  1494,  1496,  1498,  1500,  1502,  1504,
    1506,  1508,  1510,  1512,  1514,  1516,  1518,  1520,  1522,  1524,
    1526,  1528,  1530,  1532,  1533,  1538,  1541,  1545,  1548,  1555,
    1564,  1569,  1576,  1581,  1588,  1591,  1596,  1603,  1606,  1611,
    1614,  1619,  1621,  1622,  1624,  1626,  1628,  1630,  1632,  1634,
    1636,  1640,  1642,  1646,  1650,  1654,  1656,  1660,  1662,  1666,
    1668,  1670,  1673,  1675,  1677,  1679,  1682,  1685,  1687,  1689,
    1690,  1695,  1697,  1700,  1702,  1706,  1710,  1713,  1715,  1717,
    1719,  1721,  1723,  1725,  1727,  1729,  1731,  1733,  1735,  1737,
    1738,  1740,  1741,  1743,  1746,  1749,  1750,  1752,  1754,  1756,
    1758,  1760,  1763
};

/* YYRHS -- A `-1'-separated list of the rules' RHS.  */
static const yytype_int16 yyrhs[] =
{
     149,     0,    -1,    -1,   150,   151,    -1,   152,   313,    -1,
     320,    -1,   153,    -1,   152,   319,   153,    -1,     1,   153,
      -1,   158,    -1,    -1,    47,   154,   137,   151,   138,    -1,
     156,   255,   230,   258,    -1,   157,   313,    -1,   320,    -1,
     158,    -1,   157,   319,   158,    -1,     1,   158,    -1,    -1,
      45,   180,   159,   180,    -1,    45,    54,    54,    -1,    45,
      54,    64,    -1,    45,    54,    63,    -1,     6,   181,    -1,
     158,    40,   162,    -1,   158,    41,   162,    -1,   158,    42,
     162,    -1,   158,    43,   162,    -1,   158,    44,   158,    -1,
      48,   137,   156,   138,    -1,   160,    -1,   168,   114,   163,
      -1,   285,    87,   163,    -1,   215,   139,   191,   316,    87,
     163,    -1,   215,   140,    52,    87,   163,    -1,   215,   140,
      56,    87,   163,    -1,   215,    85,    56,    87,   163,    -1,
     215,    85,    52,    87,   163,    -1,   286,    87,   163,    -1,
     175,   114,   198,    -1,   168,   114,   187,    -1,   168,   114,
     198,    -1,   161,    -1,   175,   114,   163,    -1,   175,   114,
     160,    -1,   163,    -1,   161,    37,   161,    -1,   161,    38,
     161,    -1,    39,   314,   161,    -1,   111,   163,    -1,   185,
      -1,   161,    -1,   167,    -1,   164,    -1,   248,    -1,   248,
     140,   310,   193,    -1,   248,    85,   310,   193,    -1,    -1,
      94,   166,   236,   156,   138,    -1,   309,   193,    -1,   309,
     193,   165,    -1,   215,   140,   310,   193,    -1,   215,   140,
     310,   193,   165,    -1,   215,    85,   310,   193,    -1,   215,
      85,   310,   193,   165,    -1,    32,   193,    -1,    31,   193,
      -1,    30,   192,    -1,    21,   192,    -1,    22,   192,    -1,
     170,    -1,    89,   169,   315,    -1,   170,    -1,    89,   169,
     315,    -1,   172,    -1,   172,   171,    -1,   172,    95,   174,
      -1,   172,    95,   174,   141,   173,    -1,   172,    95,    -1,
     172,    95,   141,   173,    -1,    95,   174,    -1,    95,   174,
     141,   173,    -1,    95,    -1,    95,   141,   173,    -1,   174,
      -1,    89,   169,   315,    -1,   171,   141,    -1,   172,   171,
     141,    -1,   171,    -1,   173,   141,   171,    -1,   282,    -1,
     283,    -1,   215,   139,   191,   316,    -1,   215,   140,    52,
      -1,   215,    85,    52,    -1,   215,   140,    56,    -1,   215,
      85,    56,    -1,    86,    56,    -1,   286,    -1,   282,    -1,
     283,    -1,   215,   139,   191,   316,    -1,   215,   140,    52,
      -1,   215,    85,    52,    -1,   215,   140,    56,    -1,   215,
      85,    56,    -1,    86,    56,    -1,   286,    -1,    52,    -1,
      56,    -1,    86,   176,    -1,   176,    -1,   215,    85,   176,
      -1,    52,    -1,    56,    -1,    53,    -1,   183,    -1,   184,
      -1,   178,    -1,   278,    -1,   179,    -1,   280,    -1,   180,
      -1,    -1,   181,   141,   182,   180,    -1,   117,    -1,   118,
      -1,   119,    -1,    69,    -1,    70,    -1,    71,    -1,    77,
      -1,    78,    -1,   109,    -1,    73,    -1,   110,    -1,    74,
      -1,    72,    -1,    83,    -1,    84,    -1,   120,    -1,   121,
      -1,   122,    -1,    95,    -1,   123,    -1,   124,    -1,    68,
      -1,   111,    -1,   112,    -1,    66,    -1,    67,    -1,    81,
      -1,    82,    -1,   108,    -1,    49,    -1,    50,    -1,    51,
      -1,    47,    -1,    48,    -1,    45,    -1,    37,    -1,     7,
      -1,    21,    -1,    16,    -1,     3,    -1,     5,    -1,    46,
      -1,    26,    -1,    15,    -1,    14,    -1,    10,    -1,     9,
      -1,    36,    -1,    20,    -1,    25,    -1,     4,    -1,    22,
      -1,    34,    -1,    39,    -1,    38,    -1,    23,    -1,     8,
      -1,    24,    -1,    30,    -1,    33,    -1,    32,    -1,    13,
      -1,    35,    -1,     6,    -1,    17,    -1,    31,    -1,    11,
      -1,    12,    -1,    18,    -1,    19,    -1,   175,   114,   185,
      -1,   175,   114,   185,    44,   185,    -1,   285,    87,   185,
      -1,   285,    87,   185,    44,   185,    -1,   215,   139,   191,
     316,    87,   185,    -1,   215,   140,    52,    87,   185,    -1,
     215,   140,    56,    87,   185,    -1,   215,    85,    52,    87,
     185,    -1,   215,    85,    56,    87,   185,    -1,    86,    56,
      87,   185,    -1,   286,    87,   185,    -1,   185,    79,   185,
      -1,   185,    80,   185,    -1,   185,   120,   185,    -1,   185,
     121,   185,    -1,   185,   122,   185,    -1,   185,   123,   185,
      -1,   185,   124,   185,    -1,   185,    68,   185,    -1,   125,
      59,    68,   185,    -1,   125,    60,    68,   185,    -1,    66,
     185,    -1,    67,   185,    -1,   185,   117,   185,    -1,   185,
     118,   185,    -1,   185,   119,   185,    -1,   185,    69,   185,
      -1,   185,   109,   185,    -1,   185,    73,   185,    -1,   185,
     110,   185,    -1,   185,    74,   185,    -1,   185,    70,   185,
      -1,   185,    71,   185,    -1,   185,    72,   185,    -1,   185,
      77,   185,    -1,   185,    78,   185,    -1,   111,   185,    -1,
     112,   185,    -1,   185,    83,   185,    -1,   185,    84,   185,
      -1,   185,    75,   185,    -1,   185,    76,   185,    -1,    -1,
      46,   314,   186,   185,    -1,   185,   115,   185,   314,   116,
     185,    -1,   199,    -1,   185,    -1,   320,    -1,   197,   317,
      -1,   197,   141,   307,   317,    -1,   307,   317,    -1,   142,
     191,   315,    -1,   320,    -1,   189,    -1,   320,    -1,   192,
      -1,   197,   141,    -1,   197,   141,   307,   141,    -1,   307,
     141,    -1,   167,    -1,   197,   196,    -1,   307,   196,    -1,
     197,   141,   307,   196,    -1,   195,    -1,    -1,   194,   192,
      -1,    96,   187,    -1,   141,   195,    -1,   320,    -1,   187,
      -1,    95,   187,    -1,   197,   141,   187,    -1,   197,   141,
      95,   187,    -1,   197,   141,   187,    -1,   197,   141,    95,
     187,    -1,    95,   187,    -1,   259,    -1,   260,    -1,   263,
      -1,   264,    -1,   265,    -1,   268,    -1,   284,    -1,   286,
      -1,    53,    -1,   216,    -1,    -1,    90,   161,   200,   315,
      -1,    89,   156,   143,    -1,   215,    85,    56,    -1,    86,
      56,    -1,    92,   188,   144,    -1,    93,   306,   138,    -1,
      30,    -1,    31,   142,   192,   315,    -1,    31,   142,   315,
      -1,    31,    -1,    -1,    46,   314,   142,   201,   161,   315,
      -1,    39,   142,   161,   315,    -1,    39,   142,   315,    -1,
     309,   250,    -1,   249,    -1,   249,   250,    -1,    97,   241,
      -1,   217,   162,   227,   156,   229,   226,    -1,   218,   162,
     227,   156,   230,   226,    -1,    -1,    -1,   219,   202,   162,
     228,   203,   156,   226,    -1,    -1,    -1,   220,   204,   162,
     228,   205,   156,   226,    -1,   221,   162,   313,   253,   226,
      -1,   221,   313,   253,   226,    -1,    -1,    -1,   222,   231,
      25,   206,   162,   228,   207,   156,   226,    -1,    -1,   223,
     177,   287,   208,   155,   226,    -1,    -1,    -1,   223,    83,
     161,   209,   318,   210,   155,   226,    -1,    -1,   224,   177,
     211,   155,   226,    -1,    -1,   225,   178,   212,   289,   155,
     226,    -1,    -1,    -1,   225,   304,   312,   213,   178,   214,
     289,   155,   226,    -1,    21,    -1,    22,    -1,    23,    -1,
      24,    -1,   199,    -1,     7,    -1,    11,    -1,    12,    -1,
      18,    -1,    19,    -1,    16,    -1,    20,    -1,     3,    -1,
       4,    -1,     5,    -1,    10,    -1,   318,    -1,    13,    -1,
     318,    13,    -1,   318,    -1,    27,    -1,   230,    -1,    14,
     162,   227,   156,   229,    -1,   320,    -1,    15,   156,    -1,
     175,    -1,   168,    -1,   292,    -1,    89,   234,   315,    -1,
     232,    -1,   233,   141,   232,    -1,   233,    -1,   233,   141,
      95,   292,    -1,   233,   141,    95,   292,   141,   233,    -1,
     233,   141,    95,    -1,   233,   141,    95,   141,   233,    -1,
      95,   292,    -1,    95,   292,   141,   233,    -1,    95,    -1,
      95,   141,   233,    -1,   294,   141,   297,   141,   300,   303,
      -1,   294,   141,   297,   141,   300,   141,   294,   303,    -1,
     294,   141,   297,   303,    -1,   294,   141,   297,   141,   294,
     303,    -1,   294,   141,   300,   303,    -1,   294,   141,    -1,
     294,   141,   300,   141,   294,   303,    -1,   294,   303,    -1,
     297,   141,   300,   303,    -1,   297,   141,   300,   141,   294,
     303,    -1,   297,   303,    -1,   297,   141,   294,   303,    -1,
     300,   303,    -1,   300,   141,   294,   303,    -1,   302,    -1,
     320,    -1,   237,    -1,   117,   238,   117,    -1,    76,    -1,
     117,   235,   238,   117,    -1,   320,    -1,   145,   239,    -1,
     240,    -1,   239,   141,   240,    -1,    52,    -1,   291,    -1,
      -1,    -1,   242,   243,   244,   245,    -1,   142,   290,   238,
     315,    -1,   290,    -1,   107,   156,   138,    -1,    29,   156,
      10,    -1,    -1,    28,   247,   236,   156,    10,    -1,   167,
     246,    -1,   248,   140,   310,   190,    -1,   248,    85,   310,
     190,    -1,   309,   189,    -1,   215,   140,   310,   190,    -1,
     215,    85,   310,   189,    -1,   215,    85,   311,    -1,   215,
     140,   189,    -1,   215,    85,   189,    -1,    32,   189,    -1,
      32,    -1,   215,   139,   191,   316,    -1,    -1,   137,   251,
     236,   156,   138,    -1,    -1,    26,   252,   236,   156,    10,
      -1,    17,   197,   227,   156,   254,    -1,   230,    -1,   253,
      -1,     8,   256,   257,   227,   156,   255,    -1,   320,    -1,
     187,    -1,   198,    -1,   320,    -1,    88,   175,    -1,   320,
      -1,     9,   156,    -1,   320,    -1,   281,    -1,   278,    -1,
     280,    -1,   261,    -1,    62,    -1,   262,    -1,   261,   262,
      -1,    99,   270,   106,    -1,   100,   271,   106,    -1,   101,
     272,    65,    -1,   102,   146,   106,    -1,   102,   266,   106,
      -1,    -1,   266,   267,   146,    -1,   273,    -1,   267,   273,
      -1,   103,   146,   106,    -1,   103,   269,   106,    -1,    -1,
     269,    61,   146,    -1,    -1,   270,   273,    -1,    -1,   271,
     273,    -1,    -1,   272,   273,    -1,    61,    -1,    -1,   105,
     274,   277,    -1,    -1,    -1,   104,   275,   276,   156,   138,
      -1,    54,    -1,    55,    -1,    57,    -1,   286,    -1,    98,
     279,    -1,   178,    -1,    55,    -1,    54,    -1,    57,    -1,
      98,   271,   106,    -1,    59,    -1,    60,    -1,   125,    59,
      -1,   125,    60,    -1,    52,    -1,    55,    -1,    54,    -1,
      56,    -1,    57,    -1,    34,    -1,    33,    -1,    35,    -1,
      36,    -1,    50,    -1,    49,    -1,    51,    -1,   282,    -1,
     283,    -1,   282,    -1,   283,    -1,    63,    -1,    64,    -1,
     318,    -1,    -1,   110,   288,   162,   318,    -1,     1,   318,
      -1,   142,   290,   315,    -1,   290,   318,    -1,   294,   141,
     298,   141,   300,   303,    -1,   294,   141,   298,   141,   300,
     141,   294,   303,    -1,   294,   141,   298,   303,    -1,   294,
     141,   298,   141,   294,   303,    -1,   294,   141,   300,   303,
      -1,   294,   141,   300,   141,   294,   303,    -1,   294,   303,
      -1,   298,   141,   300,   303,    -1,   298,   141,   300,   141,
     294,   303,    -1,   298,   303,    -1,   298,   141,   294,   303,
      -1,   300,   303,    -1,   300,   141,   294,   303,    -1,   302,
      -1,    -1,    56,    -1,    55,    -1,    54,    -1,    57,    -1,
     291,    -1,    52,    -1,   292,    -1,    89,   234,   315,    -1,
     293,    -1,   294,   141,   293,    -1,    52,   114,   187,    -1,
      52,   114,   215,    -1,   296,    -1,   297,   141,   296,    -1,
     295,    -1,   298,   141,   295,    -1,   122,    -1,    95,    -1,
     299,    52,    -1,   299,    -1,   119,    -1,    96,    -1,   301,
      52,    -1,   141,   302,    -1,   320,    -1,   284,    -1,    -1,
     142,   305,   161,   315,    -1,   320,    -1,   307,   317,    -1,
     308,    -1,   307,   141,   308,    -1,   187,    88,   187,    -1,
      58,   187,    -1,    52,    -1,    56,    -1,    53,    -1,    52,
      -1,    56,    -1,    53,    -1,   183,    -1,    52,    -1,    53,
      -1,   183,    -1,   140,    -1,    85,    -1,    -1,   319,    -1,
      -1,   147,    -1,   314,   143,    -1,   314,   144,    -1,    -1,
     147,    -1,   141,    -1,   145,    -1,   147,    -1,   318,    -1,
     319,   145,    -1,    -1
};

/* YYRLINE[YYN] -- source line where rule number YYN was defined.  */
static const yytype_uint16 yyrline[] =
{
       0,   736,   736,   736,   747,   754,   758,   762,   766,   772,
     777,   776,   788,   797,   803,   807,   811,   815,   821,   821,
     825,   829,   833,   837,   841,   845,   849,   853,   857,   861,
     868,   872,   876,   880,   884,   888,   892,   896,   900,   904,
     908,   912,   916,   922,   926,   933,   937,   941,   945,   949,
     953,   959,   965,   969,   975,   979,   983,   990,   989,  1001,
    1005,  1009,  1013,  1017,  1021,  1025,  1029,  1033,  1037,  1041,
    1047,  1051,  1057,  1061,  1067,  1071,  1075,  1079,  1083,  1087,
    1091,  1095,  1099,  1103,  1109,  1113,  1119,  1123,  1129,  1133,
    1139,  1144,  1149,  1153,  1157,  1161,  1165,  1171,  1175,  1181,
    1186,  1191,  1195,  1199,  1203,  1207,  1213,  1217,  1223,  1227,
    1233,  1237,  1241,  1247,  1251,  1255,  1259,  1264,  1271,  1275,
    1281,  1285,  1291,  1295,  1295,  1301,  1302,  1303,  1304,  1305,
    1306,  1307,  1308,  1309,  1310,  1311,  1312,  1313,  1314,  1315,
    1316,  1317,  1318,  1319,  1320,  1321,  1322,  1323,  1324,  1325,
    1326,  1327,  1328,  1329,  1332,  1333,  1334,  1335,  1336,  1337,
    1338,  1339,  1340,  1341,  1342,  1343,  1344,  1345,  1346,  1347,
    1348,  1349,  1350,  1351,  1352,  1353,  1354,  1355,  1356,  1357,
    1358,  1359,  1360,  1361,  1362,  1363,  1364,  1365,  1366,  1367,
    1368,  1369,  1370,  1371,  1372,  1375,  1379,  1383,  1387,  1391,
    1395,  1399,  1403,  1407,  1411,  1415,  1419,  1423,  1427,  1431,
    1435,  1439,  1443,  1447,  1451,  1455,  1459,  1463,  1467,  1471,
    1475,  1479,  1483,  1487,  1491,  1495,  1499,  1503,  1507,  1511,
    1515,  1519,  1523,  1527,  1531,  1535,  1539,  1543,  1543,  1548,
    1552,  1558,  1565,  1569,  1573,  1577,  1583,  1589,  1593,  1599,
    1603,  1607,  1611,  1615,  1621,  1625,  1629,  1633,  1637,  1644,
    1644,  1656,  1662,  1666,  1672,  1676,  1680,  1684,  1690,  1694,
    1698,  1704,  1708,  1712,  1716,  1720,  1724,  1728,  1732,  1736,
    1740,  1744,  1744,  1749,  1753,  1757,  1761,  1765,  1769,  1773,
    1777,  1781,  1785,  1785,  1790,  1794,  1798,  1802,  1806,  1810,
    1814,  1818,  1822,  1822,  1822,  1826,  1826,  1826,  1830,  1834,
    1839,  1841,  1838,  1848,  1847,  1861,  1866,  1860,  1881,  1880,
    1894,  1893,  1910,  1911,  1910,  1925,  1929,  1933,  1937,  1943,
    1949,  1956,  1963,  1969,  1975,  1981,  1987,  1993,  1999,  2005,
    2011,  2017,  2021,  2025,  2031,  2035,  2041,  2045,  2051,  2055,
    2061,  2065,  2071,  2076,  2082,  2086,  2092,  2096,  2101,  2106,
    2110,  2114,  2119,  2124,  2128,  2134,  2138,  2142,  2146,  2150,
    2154,  2158,  2162,  2166,  2170,  2174,  2178,  2182,  2186,  2190,
    2196,  2200,  2207,  2211,  2215,  2222,  2226,  2232,  2236,  2243,
    2249,  2255,  2258,  2255,  2272,  2276,  2282,  2286,  2293,  2292,
    2306,  2310,  2314,  2320,  2324,  2328,  2332,  2336,  2340,  2344,
    2348,  2352,  2359,  2358,  2370,  2369,  2382,  2388,  2392,  2398,
    2402,  2408,  2412,  2416,  2422,  2426,  2432,  2436,  2442,  2446,
    2450,  2456,  2462,  2466,  2470,  2476,  2482,  2488,  2494,  2498,
    2505,  2508,  2514,  2518,  2524,  2528,  2535,  2538,  2545,  2548,
    2555,  2558,  2565,  2568,  2574,  2579,  2578,  2590,  2596,  2589,
    2610,  2614,  2618,  2622,  2628,  2635,  2639,  2643,  2647,  2653,
    2660,  2664,  2668,  2672,  2678,  2683,  2688,  2693,  2698,  2705,
    2710,  2715,  2720,  2725,  2730,  2735,  2742,  2751,  2757,  2762,
    2769,  2773,  2779,  2784,  2783,  2791,  2798,  2805,  2811,  2815,
    2819,  2823,  2827,  2831,  2835,  2839,  2843,  2847,  2851,  2855,
    2859,  2863,  2868,  2873,  2877,  2881,  2885,  2891,  2895,  2903,
    2909,  2918,  2922,  2928,  2936,  2944,  2948,  2954,  2958,  2964,
    2968,  2974,  2979,  2985,  2989,  2995,  3002,  3006,  3012,  3016,
    3016,  3022,  3026,  3032,  3036,  3042,  3046,  3052,  3056,  3060,
    3066,  3070,  3074,  3078,  3084,  3088,  3092,  3098,  3102,  3109,
    3112,  3119,  3122,  3128,  3134,  3141,  3144,  3148,  3154,  3158,
    3164,  3168,  3176
};
#endif

#if YYDEBUG || YYERROR_VERBOSE || YYTOKEN_TABLE
/* YYTNAME[SYMBOL-NUM] -- String name of the symbol SYMBOL-NUM.
   First, the terminals, then, starting at YYNTOKENS, nonterminals.  */
static const char *const yytname[] =
{
  "$end", "error", "$undefined", "keyword_class", "keyword_module",
  "keyword_def", "keyword_undef", "keyword_begin", "keyword_rescue",
  "keyword_ensure", "keyword_end", "keyword_if", "keyword_unless",
  "keyword_then", "keyword_elsif", "keyword_else", "keyword_case",
  "keyword_when", "keyword_while", "keyword_until", "keyword_for",
  "keyword_break", "keyword_next", "keyword_redo", "keyword_retry",
  "keyword_in", "keyword_do", "keyword_do_cond", "keyword_do_block",
  "keyword_do_LAMBDA", "keyword_return", "keyword_yield", "keyword_super",
  "keyword_self", "keyword_nil", "keyword_true", "keyword_false",
  "keyword_and", "keyword_or", "keyword_not", "modifier_if",
  "modifier_unless", "modifier_while", "modifier_until", "modifier_rescue",
  "keyword_alias", "keyword_defined", "keyword_BEGIN", "keyword_END",
  "keyword__LINE__", "keyword__FILE__", "keyword__ENCODING__",
  "tIDENTIFIER", "tFID", "tGVAR", "tIVAR", "tCONSTANT", "tCVAR", "tLABEL",
  "tINTEGER", "tFLOAT", "tSTRING_CONTENT", "tCHAR", "tNTH_REF",
  "tBACK_REF", "tREGEXP_END", "tUPLUS", "tUMINUS", "tPOW", "tCMP", "tEQ",
  "tEQQ", "tNEQ", "tGEQ", "tLEQ", "tANDOP", "tOROP", "tMATCH", "tNMATCH",
  "tDOT2", "tDOT3", "tAREF", "tASET", "tLSHFT", "tRSHFT", "tCOLON2",
  "tCOLON3", "tOP_ASGN", "tASSOC", "tLPAREN", "tLPAREN_ARG", "tRPAREN",
  "tLBRACK", "tLBRACE", "tLBRACE_ARG", "tSTAR", "tAMPER", "tLAMBDA",
  "tSYMBEG", "tSTRING_BEG", "tXSTRING_BEG", "tREGEXP_BEG", "tWORDS_BEG",
  "tQWORDS_BEG", "tSTRING_DBEG", "tSTRING_DVAR", "tSTRING_END", "tLAMBEG",
  "'`'", "'>'", "'<'", "'!'", "'~'", "tLOWEST", "'='", "'?'", "':'", "'|'",
  "'^'", "'&'", "'+'", "'-'", "'*'", "'/'", "'%'", "tUMINUS_NUM", "idNULL",
  "idRespond_to", "idIFUNC", "idCFUNC", "id_core_set_method_alias",
  "id_core_set_variable_alias", "id_core_undef_method",
  "id_core_define_method", "id_core_define_singleton_method",
  "id_core_set_postexe", "tLAST_TOKEN", "'{'", "'}'", "'['", "'.'", "','",
  "'('", "')'", "']'", "';'", "' '", "'\\n'", "$accept", "program", "@1",
  "top_compstmt", "top_stmts", "top_stmt", "@2", "bodystmt", "compstmt",
  "stmts", "stmt", "@3", "command_asgn", "expr", "expr_value",
  "command_call", "block_command", "cmd_brace_block", "@4", "command",
  "mlhs", "mlhs_inner", "mlhs_basic", "mlhs_item", "mlhs_head",
  "mlhs_post", "mlhs_node", "lhs", "cname", "cpath", "fname", "fsym",
  "fitem", "undef_list", "@5", "op", "reswords", "arg", "@6", "arg_value",
  "aref_args", "paren_args", "opt_paren_args", "opt_call_args",
  "call_args", "command_args", "@7", "block_arg", "opt_block_arg", "args",
  "mrhs", "primary", "@8", "@9", "@10", "@11", "@12", "@13", "@14", "@15",
  "@16", "@17", "@18", "@19", "@20", "@21", "@22", "primary_value",
  "k_begin", "k_if", "k_unless", "k_while", "k_until", "k_case", "k_for",
  "k_class", "k_module", "k_def", "k_end", "then", "do", "if_tail",
  "opt_else", "for_var", "f_marg", "f_marg_list", "f_margs", "block_param",
  "opt_block_param", "block_param_def", "opt_bv_decl", "bv_decls", "bvar",
  "lambda", "@23", "@24", "f_larglist", "lambda_body", "do_block", "@25",
  "block_call", "method_call", "brace_block", "@26", "@27", "case_body",
  "cases", "opt_rescue", "exc_list", "exc_var", "opt_ensure", "literal",
  "strings", "string", "string1", "xstring", "regexp", "words",
  "word_list", "word", "qwords", "qword_list", "string_contents",
  "xstring_contents", "regexp_contents", "string_content", "@28", "@29",
  "@30", "string_dvar", "symbol", "sym", "dsym", "numeric",
  "user_variable", "keyword_variable", "var_ref", "var_lhs", "backref",
  "superclass", "@31", "f_arglist", "f_args", "f_bad_arg", "f_norm_arg",
  "f_arg_item", "f_arg", "f_opt", "f_block_opt", "f_block_optarg",
  "f_optarg", "restarg_mark", "f_rest_arg", "blkarg_mark", "f_block_arg",
  "opt_f_block_arg", "singleton", "@32", "assoc_list", "assocs", "assoc",
  "operation", "operation2", "operation3", "dot_or_colon", "opt_terms",
  "opt_nl", "rparen", "rbracket", "trailer", "term", "terms", "none", 0
};
#endif

# ifdef YYPRINT
/* YYTOKNUM[YYLEX-NUM] -- Internal token number corresponding to
   token YYLEX-NUM.  */
static const yytype_uint16 yytoknum[] =
{
       0,   256,   257,   258,   259,   260,   261,   262,   263,   264,
     265,   266,   267,   268,   269,   270,   271,   272,   273,   274,
     275,   276,   277,   278,   279,   280,   281,   282,   283,   284,
     285,   286,   287,   288,   289,   290,   291,   292,   293,   294,
     295,   296,   297,   298,   299,   300,   301,   302,   303,   304,
     305,   306,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,   334,
     335,   336,   337,   338,   339,   340,   341,   342,   343,   344,
     345,   346,   347,   348,   349,   350,   351,   352,   353,   354,
     355,   356,   357,   358,   359,   360,   361,   362,    96,    62,
      60,    33,   126,   363,    61,    63,    58,   124,    94,    38,
      43,    45,    42,    47,    37,   364,   365,   366,   367,   368,
     369,   370,   371,   372,   373,   374,   375,   123,   125,    91,
      46,    44,    40,    41,    93,    59,    32,    10
};
# endif

/* YYR1[YYN] -- Symbol number of symbol that rule YYN derives.  */
static const yytype_uint16 yyr1[] =
{
       0,   148,   150,   149,   151,   152,   152,   152,   152,   153,
     154,   153,   155,   156,   157,   157,   157,   157,   159,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   158,   158,   158,   158,   158,   158,   158,
     158,   158,   158,   160,   160,   161,   161,   161,   161,   161,
     161,   162,   163,   163,   164,   164,   164,   166,   165,   167,
     167,   167,   167,   167,   167,   167,   167,   167,   167,   167,
     168,   168,   169,   169,   170,   170,   170,   170,   170,   170,
     170,   170,   170,   170,   171,   171,   172,   172,   173,   173,
     174,   174,   174,   174,   174,   174,   174,   174,   174,   175,
     175,   175,   175,   175,   175,   175,   175,   175,   176,   176,
     177,   177,   177,   178,   178,   178,   178,   178,   179,   179,
     180,   180,   181,   182,   181,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   183,   183,   183,   183,   183,   183,
     183,   183,   183,   183,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   184,   184,   184,   184,   184,
     184,   184,   184,   184,   184,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   186,   185,   185,
     185,   187,   188,   188,   188,   188,   189,   190,   190,   191,
     191,   191,   191,   191,   192,   192,   192,   192,   192,   194,
     193,   195,   196,   196,   197,   197,   197,   197,   198,   198,
     198,   199,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   200,   199,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   201,   199,   199,   199,   199,   199,   199,   199,
     199,   199,   202,   203,   199,   204,   205,   199,   199,   199,
     206,   207,   199,   208,   199,   209,   210,   199,   211,   199,
     212,   199,   213,   214,   199,   199,   199,   199,   199,   215,
     216,   217,   218,   219,   220,   221,   222,   223,   224,   225,
     226,   227,   227,   227,   228,   228,   229,   229,   230,   230,
     231,   231,   232,   232,   233,   233,   234,   234,   234,   234,
     234,   234,   234,   234,   234,   235,   235,   235,   235,   235,
     235,   235,   235,   235,   235,   235,   235,   235,   235,   235,
     236,   236,   237,   237,   237,   238,   238,   239,   239,   240,
     240,   242,   243,   241,   244,   244,   245,   245,   247,   246,
     248,   248,   248,   249,   249,   249,   249,   249,   249,   249,
     249,   249,   251,   250,   252,   250,   253,   254,   254,   255,
     255,   256,   256,   256,   257,   257,   258,   258,   259,   259,
     259,   260,   261,   261,   261,   262,   263,   264,   265,   265,
     266,   266,   267,   267,   268,   268,   269,   269,   270,   270,
     271,   271,   272,   272,   273,   274,   273,   275,   276,   273,
     277,   277,   277,   277,   278,   279,   279,   279,   279,   280,
     281,   281,   281,   281,   282,   282,   282,   282,   282,   283,
     283,   283,   283,   283,   283,   283,   284,   284,   285,   285,
     286,   286,   287,   288,   287,   287,   289,   289,   290,   290,
     290,   290,   290,   290,   290,   290,   290,   290,   290,   290,
     290,   290,   290,   291,   291,   291,   291,   292,   292,   293,
     293,   294,   294,   295,   296,   297,   297,   298,   298,   299,
     299,   300,   300,   301,   301,   302,   303,   303,   304,   305,
     304,   306,   306,   307,   307,   308,   308,   309,   309,   309,
     310,   310,   310,   310,   311,   311,   311,   312,   312,   313,
     313,   314,   314,   315,   316,   317,   317,   317,   318,   318,
     319,   319,   320
};

/* YYR2[YYN] -- Number of symbols composing right hand side of rule YYN.  */
static const yytype_uint8 yyr2[] =
{
       0,     2,     0,     2,     2,     1,     1,     3,     2,     1,
       0,     5,     4,     2,     1,     1,     3,     2,     0,     4,
       3,     3,     3,     2,     3,     3,     3,     3,     3,     4,
       1,     3,     3,     6,     5,     5,     5,     5,     3,     3,
       3,     3,     1,     3,     3,     1,     3,     3,     3,     2,
       1,     1,     1,     1,     1,     4,     4,     0,     5,     2,
       3,     4,     5,     4,     5,     2,     2,     2,     2,     2,
       1,     3,     1,     3,     1,     2,     3,     5,     2,     4,
       2,     4,     1,     3,     1,     3,     2,     3,     1,     3,
       1,     1,     4,     3,     3,     3,     3,     2,     1,     1,
       1,     4,     3,     3,     3,     3,     2,     1,     1,     1,
       2,     1,     3,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     3,     5,     3,     5,     6,
       5,     5,     5,     5,     4,     3,     3,     3,     3,     3,
       3,     3,     3,     3,     4,     4,     2,     2,     3,     3,
       3,     3,     3,     3,     3,     3,     3,     3,     3,     3,
       3,     2,     2,     3,     3,     3,     3,     0,     4,     6,
       1,     1,     1,     2,     4,     2,     3,     1,     1,     1,
       1,     2,     4,     2,     1,     2,     2,     4,     1,     0,
       2,     2,     2,     1,     1,     2,     3,     4,     3,     4,
       2,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     0,     4,     3,     3,     2,     3,     3,     1,     4,
       3,     1,     0,     6,     4,     3,     2,     1,     2,     2,
       6,     6,     0,     0,     7,     0,     0,     7,     5,     4,
       0,     0,     9,     0,     6,     0,     0,     8,     0,     5,
       0,     6,     0,     0,     9,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     2,     1,     1,     1,     5,     1,     2,
       1,     1,     1,     3,     1,     3,     1,     4,     6,     3,
       5,     2,     4,     1,     3,     6,     8,     4,     6,     4,
       2,     6,     2,     4,     6,     2,     4,     2,     4,     1,
       1,     1,     3,     1,     4,     1,     2,     1,     3,     1,
       1,     0,     0,     4,     4,     1,     3,     3,     0,     5,
       2,     4,     4,     2,     4,     4,     3,     3,     3,     2,
       1,     4,     0,     5,     0,     5,     5,     1,     1,     6,
       1,     1,     1,     1,     2,     1,     2,     1,     1,     1,
       1,     1,     1,     1,     2,     3,     3,     3,     3,     3,
       0,     3,     1,     2,     3,     3,     0,     3,     0,     2,
       0,     2,     0,     2,     1,     0,     3,     0,     0,     5,
       1,     1,     1,     1,     2,     1,     1,     1,     1,     3,
       1,     1,     2,     2,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     1,
       1,     1,     1,     0,     4,     2,     3,     2,     6,     8,
       4,     6,     4,     6,     2,     4,     6,     2,     4,     2,
       4,     1,     0,     1,     1,     1,     1,     1,     1,     1,
       3,     1,     3,     3,     3,     1,     3,     1,     3,     1,
       1,     2,     1,     1,     1,     2,     2,     1,     1,     0,
       4,     1,     2,     1,     3,     3,     2,     1,     1,     1,
       1,     1,     1,     1,     1,     1,     1,     1,     1,     0,
       1,     0,     1,     2,     2,     0,     1,     1,     1,     1,
       1,     2,     0
};

/* YYDEFACT[STATE-NAME] -- Default rule to reduce with in state
   STATE-NUM when YYTABLE doesn't specify something else to do.  Zero
   means the default is an error.  */
static const yytype_uint16 yydefact[] =
{
       2,     0,     0,     1,     0,   337,   338,   339,     0,   330,
     331,   332,   335,   333,   334,   336,   325,   326,   327,   328,
     288,   259,   259,   480,   479,   481,   482,   561,     0,   561,
      10,     0,   484,   483,   485,   474,   549,   476,   475,   477,
     478,   470,   471,   432,   490,   491,     0,     0,     0,     0,
       0,   572,   572,    82,   391,   450,   448,   450,   452,   440,
     446,     0,     0,     0,     3,   559,     6,     9,    30,    42,
      45,    53,    52,     0,    70,     0,    74,    84,     0,    50,
     240,     0,   280,     0,     0,   302,   305,   559,     0,     0,
       0,     0,    54,   297,   271,   272,   431,   433,   273,   274,
     275,   276,   429,   430,   428,   486,   487,   277,     0,   278,
     259,     5,     8,   164,   175,   165,   188,   161,   181,   171,
     170,   191,   192,   186,   169,   168,   163,   189,   193,   194,
     173,   162,   176,   180,   182,   174,   167,   183,   190,   185,
     184,   177,   187,   172,   160,   179,   178,   159,   166,   157,
     158,   154,   155,   156,   113,   115,   114,   149,   150,   146,
     128,   129,   130,   137,   134,   136,   131,   132,   151,   152,
     138,   139,   143,   153,   133,   135,   147,   148,   125,   126,
     127,   140,   141,   142,   144,   145,   118,   120,   122,    23,
     116,   117,   119,   121,     0,     0,     0,     0,     0,     0,
       0,   254,     0,   241,   264,    68,   258,   572,     0,   486,
     487,     0,   278,   572,   543,    69,    67,   561,    66,     0,
     572,   409,    65,   561,   562,     0,     0,    18,   237,     0,
       0,   325,   326,   288,   291,   410,   216,     0,     0,   217,
     285,     0,     0,     0,   559,    15,   561,    72,    14,   281,
       0,   565,   565,   242,     0,     0,   565,   541,   561,     0,
       0,     0,    80,   329,     0,    90,    91,    98,   299,   392,
     467,   466,   468,   465,     0,   464,     0,     0,     0,     0,
       0,     0,     0,    49,   231,   232,   472,   473,   568,   569,
       4,   570,   560,     0,     0,     0,     0,     0,     0,     0,
     398,   400,     0,    86,     0,    78,    75,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   572,     0,    51,     0,     0,
       0,     0,   559,     0,   560,     0,   351,   350,     0,     0,
     486,   487,   278,   108,   109,     0,     0,   111,     0,     0,
     486,   487,   278,   318,   184,   177,   187,   172,   154,   155,
     156,   113,   114,   539,   320,   538,     0,     0,     0,   414,
     412,   298,   434,     0,     0,   403,    59,   296,   123,   546,
     285,   265,   261,     0,     0,     0,   255,   263,     0,   572,
       0,     0,     0,     0,   256,   561,     0,   290,   260,   561,
     250,   572,   572,   249,   561,   295,    48,    20,    22,    21,
       0,   292,     0,     0,     0,     0,     0,     0,    17,   561,
     283,    13,   560,    71,   561,   286,   567,   566,   243,   567,
     245,   287,   542,     0,    97,   472,   473,    88,    83,     0,
       0,   572,     0,   512,   454,   457,   455,   469,   451,   435,
     449,   436,   437,   453,   438,   439,     0,   442,   444,     0,
     445,     0,     0,   571,     7,    24,    25,    26,    27,    28,
      46,    47,   572,     0,    31,    40,     0,    41,   561,     0,
      76,    87,    44,    43,     0,   195,   264,    39,   213,   221,
     226,   227,   228,   223,   225,   235,   236,   229,   230,   206,
     207,   233,   234,   222,   224,   561,   218,   219,   220,   208,
     209,   210,   211,   212,   550,   555,   551,   556,   408,   259,
     406,   561,   550,   552,   551,   553,   407,   259,   342,     0,
     341,     0,     0,     0,     0,     0,     0,   285,     0,   572,
       0,   310,   315,   108,   109,   110,     0,   493,   313,   492,
       0,   572,     0,     0,     0,   512,   558,   557,   322,   550,
     551,   259,   259,   572,   572,    32,   197,    38,   205,    57,
      60,     0,   195,   545,     0,   266,   262,   572,   554,   551,
     561,   550,   551,   544,   289,   563,   246,   251,   253,   294,
      19,     0,   238,     0,    29,     0,   572,   204,    73,    16,
     282,   565,     0,    81,    94,    96,   561,   550,   551,   518,
     515,   514,   513,   516,     0,   530,   534,   533,   529,   512,
       0,   395,   517,   519,   521,   572,   527,   572,   532,   572,
       0,   511,   458,     0,   441,   443,   447,   214,   215,   383,
     572,     0,   381,   380,   270,     0,    85,    79,     0,     0,
       0,     0,     0,     0,   405,    63,     0,   411,     0,     0,
     248,   404,    61,   247,   572,   343,   572,   345,   303,   344,
     306,     0,     0,   340,   309,   554,   284,   561,   550,   551,
       0,     0,   495,     0,     0,   108,   109,   112,   561,     0,
     572,   561,   512,     0,     0,     0,   402,    56,   401,    55,
       0,     0,     0,   572,   124,   267,   257,     0,     0,   411,
       0,     0,   572,   561,    11,   244,    89,    92,     0,   518,
       0,   363,   354,   356,   561,   352,   572,     0,     0,   393,
       0,   504,   537,     0,   507,   531,     0,   509,   535,     0,
     460,   461,   462,   456,   463,   518,     0,   572,     0,   572,
     525,   572,   572,   379,   385,     0,     0,   268,    77,   196,
       0,    37,   202,    36,   203,    64,   564,     0,    34,   200,
      35,   201,    62,     0,     0,     0,   346,   348,     0,     0,
       0,   308,     0,     0,   411,     0,   316,     0,     0,   411,
     319,   572,   572,   420,   540,   561,     0,   497,   323,     0,
       0,   198,     0,     0,   252,   293,   523,   561,     0,   361,
       0,   520,   561,     0,     0,   522,   572,   572,   536,   572,
     528,   572,   572,     0,     0,   389,   386,   387,   390,     0,
     382,   370,   372,     0,   375,     0,   377,   399,   269,   239,
      33,   199,     0,   349,   300,   301,     0,     0,   266,   572,
     311,     0,   494,   314,   421,   422,   572,   423,   572,   496,
     321,   512,   415,   413,     0,   353,   364,     0,   359,   355,
     394,   397,   396,     0,   500,     0,   502,     0,   508,     0,
     505,   510,   459,     0,   524,     0,   384,   572,   572,   572,
     526,   572,   572,     0,   304,   307,   417,   418,   416,     0,
       0,     0,     0,   425,     0,    12,   427,     0,    58,     0,
     362,     0,   357,   572,   572,   572,   572,   285,     0,   388,
       0,   367,     0,   369,   376,     0,   373,   378,   572,     0,
     317,     0,   424,     0,    99,   100,   107,     0,   426,     0,
     360,     0,   501,     0,   498,   503,   506,   554,   284,   572,
     572,   572,   572,   347,   312,   106,     0,   572,     0,   572,
     324,   358,   572,   368,     0,   365,   371,   374,   554,   105,
     561,   550,   551,   419,   499,   572,   411,   366
};

/* YYDEFGOTO[NTERM-NUM].  */
static const yytype_int16 yydefgoto[] =
{
      -1,     1,     2,    64,    65,    66,   229,   699,   700,   244,
     245,   420,    68,    69,   338,    70,    71,   580,   713,    72,
      73,   246,    74,    75,    76,   448,    77,   202,   357,   358,
     186,   187,   188,   189,   581,   535,   191,    79,   422,   204,
     250,   528,   671,   409,   410,   218,   219,   206,   396,   411,
     487,    80,   434,   601,   340,   789,   341,   790,   690,   909,
     694,   691,   861,   563,   565,   705,   871,   237,    82,    83,
      84,    85,    86,    87,    88,    89,    90,    91,   684,   539,
     678,   785,   786,   349,   732,   733,   734,   757,   651,   652,
     758,   836,   837,   268,   269,   453,   630,   739,   301,   482,
      92,    93,   387,   574,   573,   546,   908,   802,   866,   912,
     915,    94,    95,    96,    97,    98,    99,   100,   280,   466,
     101,   282,   276,   274,   278,   458,   643,   642,   749,   753,
     102,   275,   103,   104,   209,   210,   107,   211,   212,   558,
     693,   703,   704,   632,   633,   634,   635,   636,   760,   761,
     637,   638,   639,   640,   828,   741,   376,   564,   255,   412,
     214,   238,   605,   530,   568,   290,   406,   407,   667,   438,
     540,   344,   248
};

/* YYPACT[STATE-NUM] -- Index in YYTABLE of the portion describing
   STATE-NUM.  */
#define YYPACT_NINF -749
static const yytype_int16 yypact[] =
{
    -749,   153,  2646,  -749,  6538,  -749,  -749,  -749,  9313,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  6758,  6758,  -749,  -749,
    6758,  3335,  2901,  -749,  -749,  -749,  -749,   -24,  9191,    62,
    -749,    29,  -749,  -749,  -749,  5715,  3047,  -749,  -749,  5842,
    -749,  -749,  -749,  -749,  -749,  -749,  7968,  7968,   218,  4483,
    8078,  6978,  7308,  6314,  -749,  9069,  -749,  -749,  -749,    88,
     157,  8188,  7968,    74,  -749,   234,  -749,   791,  -749,   163,
    -749,  -749,   287,   232,  -749,   224,  8298,  -749,   262,  2495,
      37,   303,  -749,  8078,  8078,  -749,  -749,  5102,  8406,  8514,
    8622,  5590,    15,    76,  -749,  -749,   313,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,   248,   565,  -749,   311,   613,
      89,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,   285,
    -749,  -749,  -749,  -749,   298,  7968,   394,  4613,  7968,  7968,
    7968,  -749,   338,  2495,   367,  -749,  -749,   316,   353,    61,
      69,   379,   273,   332,  -749,  -749,  -749,  4992,  -749,  6758,
    6758,  -749,  -749,  5221,  -749,  8078,   592,  -749,   336,   360,
    4743,  -749,  -749,  -749,   371,   389,  -749,   413,    89,   460,
     639,  6648,  4483,   352,   234,   791,    62,   422,  -749,   163,
     398,    18,   233,  -749,   367,   407,   233,  -749,    62,   500,
     474,  8730,   421,  -749,   454,   489,   492,   528,  -749,  -749,
    -749,  -749,  -749,  -749,    46,  -749,   420,   581,   342,   469,
     641,   482,    79,  -749,  -749,  -749,   512,   527,  -749,  -749,
    -749,  -749,  5331,  8078,  8078,  8078,  8078,  6648,  8078,  8078,
    -749,  -749,  7418,  -749,  4483,  6426,   461,  7418,  7968,  7968,
    7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,
    7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,  7968,
    7968,  7968,  7968,  7968,  9508,  6758,  9585,   163,    95,    95,
    8078,  8078,   234,   588,   502,   563,  -749,  -749,   541,   602,
      57,   121,   124,   319,   380,  8078,   299,  -749,   110,   549,
    -749,  -749,  -749,  -749,    32,    34,    54,    56,   168,   231,
     238,   265,   282,  -749,  -749,  -749,   284, 10509, 10509,  -749,
    -749,  -749,  -749,  8188,  8188,  -749,   564,  -749,  -749,  -749,
     388,  -749,  -749,  7968,  7968,  6868,  -749,  -749,  9662,  6758,
    9739,  7968,  7968,  7088,  -749,    62,   516,  -749,  -749,    62,
    -749,   521,   543,  -749,    94,  -749,  -749,  -749,  -749,  -749,
    9313,  -749,  7968,  4078,   544,  9662,  9739,  7968,   791,    62,
    -749,  -749,  5447,   552,    62,  -749,  7198,  -749,  -749,  7308,
    -749,  -749,  -749,   336,   569,  -749,  -749,  -749,   556,  8730,
    9816,  6758,  9893,   795,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,   268,  -749,  -749,   571,
    -749,  7968,  7968,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,    27,  7968,  -749,   574,   577,  -749,    62,  8730,
     578,  -749,  -749,  -749,   596,  2044,  -749,  -749,   460,  2881,
    2881,  2881,  2881,  1075,  1075,  3027,  1484,  2881,  2881,  2739,
    2739,   386,   386,  1075,  1075,   925,   809,   809,   990,   392,
     392,   460,   460,   460,  3425,  6084,  3513,  6199,  -749,   389,
    -749,    62,   649,  -749,   662,  -749,  -749,  3189,  -749,  3803,
     708,  4223,    45,    45,   588,  7528,   725,   129,  9970,  6758,
   10047,  -749,   163,  -749,   569,  -749,   234,  -749,  -749,  -749,
   10124,  6758, 10201,  3658,  8078,   935,  -749,  -749,  -749,  -749,
    -749,  1852,  1852,    27,    27,  -749,  2240,  -749,  2495,  -749,
    -749,  9313,  2373,  -749,  7968,   367,  -749,   332,  5969,  2759,
      62,   416,   436,  -749,  -749,  -749,  -749,  6868,  7088,  -749,
    -749,  8078,  2495,   604,  -749,   389,   389,  2495,   252,   791,
    -749,   233,  8730,   556,   459,   344,    62,   327,   358,   629,
    -749,  -749,  -749,  -749,  1067,  -749,  -749,  -749,  -749,  1013,
      77,  -749,  -749,  -749,  -749,   603,  -749,   609,   700,   617,
     710,  -749,  -749,   824,  -749,  -749,  -749,   460,   460,  -749,
     554,  4873,  -749,  -749,   623,  7638,  -749,   556,  8730,  8188,
    7968,   650,  8188,  8188,  -749,   564,   633,   674,  8188,  8188,
    -749,  -749,   564,  -749,   625,  -749,   752,  -749,  -749,  -749,
    -749,   725,   193,  -749,  -749,   170,   178,    62,   137,   144,
    8078,   234,  -749,  8078,  3658,   459,   344,  -749,    62,   725,
     770,    94,  1013,  3658,   234,  9435,  -749,  -749,  -749,  -749,
    4873,  4743,  7968,    27,  -749,  -749,  -749,  7968,  7968,   450,
    7968,  7968,   640,    94,  -749,  -749,  -749,   279,  7968,  -749,
    1067,   566,  -749,   642,    62,  -749,   651,  4873,  4743,  -749,
    1013,  -749,  -749,  1013,  -749,  -749,    72,  -749,  -749,  4743,
    -749,  -749,  -749,  -749,  -749,   670,   898,   651,   677,   646,
    -749,   656,   660,  -749,  -749,   792,  7968,   665,   556,  2495,
    7968,  -749,  2495,  -749,  2495,  -749,  -749,  8188,  -749,  2495,
    -749,  2495,  -749,  8078,  4353,   725,  -749,  -749,   725,  4873,
    4873,  -749,  7748,  3948,   148,    45,  -749,   234,   725,  -749,
    -749,  7858,   752,  -749,  -749,    62,   725,  -749,  -749,   800,
     673,  2495,  4743,  7968,  7088,  -749,  -749,    62,   819,   675,
    1074,  -749,    62,   807,   681,  -749,   679,   682,  -749,   687,
    -749,   697,   687,   684,  8838,  -749,   703,  -749,  -749,   728,
    -749,  1038,  -749,  1038,  -749,    72,  -749,  -749,   705,  2495,
    -749,  2495,    95,  -749,  -749,  -749,   725,   725,  -749,   418,
    -749,  3658,  -749,  -749,   574,  -749,   760,  -749,   844,  -749,
    -749,   935,  -749,  -749,   716,  -749,   715,   819,   785,  -749,
    -749,  -749,  -749,  1013,  -749,    72,  -749,    72,  -749,    72,
    -749,  -749,  -749,   802,   590,   898,  -749,   719,   720,   687,
    -749,   726,   687,  3803,  -749,  -749,  -749,  -749,  -749,  4873,
     725,  8946,    95,  -749,  4873,  -749,  -749,  3658,  -749,   819,
     715,   819,   727,   687,   729,   687,   687,  -749, 10278,  -749,
    1038,  -749,    72,  -749,  -749,    72,  -749,  -749,   625,   725,
    -749,   806,  -749,   593,   489,   492,   528,  3658,  -749,   725,
     715,   819,  -749,    72,  -749,  -749,  -749,   738,   740,   687,
     745,   687,   687,  -749,  -749,   569, 10355,  6758, 10432,   770,
    -749,   715,   687,  -749,    72,  -749,  -749,  -749,   130,   344,
      62,   194,   211,  -749,  -749,   687,   237,  -749
};

/* YYPGOTO[NTERM-NUM].  */
static const yytype_int16 yypgoto[] =
{
    -749,  -749,  -749,   446,  -749,    36,  -749,  -590,   427,  -749,
      39,  -749,  -296,  1100,   -27,   106,  -749,  -530,  -749,    -3,
     810,  -141,    22,   -74,  -749,  -428,   -29,  1643,  -327,   811,
     -54,  -749,   -21,  -749,  -749,    19,  -749,  1035,  -749,    93,
    -749,    11,    73,  -326,    67,    20,  -749,  -369,  -210,    42,
    -297,   -22,  -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,     2,  -749,  -749,
    -749,  -749,  -749,  -749,  -749,  -749,  -749,  -749,   -84,  -334,
    -513,   -36,  -623,  -749,  -739,  -713,   173,  -749,  -476,  -749,
    -600,  -749,     9,  -749,  -749,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,   813,  -749,  -749,  -529,  -749,   -60,  -749,  -749,
    -749,  -749,  -749,  -749,   814,  -749,  -749,  -749,  -749,  -749,
    -749,  -749,  -749,   855,  -749,  -164,  -749,  -749,  -749,  -749,
       0,  -749,     8,  -749,  1223,  1487,   829,  1674,  1728,  -749,
    -749,    44,  -378,  -691,  -560,  -694,  -453,  -673,  -748,    84,
     187,  -749,  -562,  -749,  -377,   690,  -749,  -749,  -749,    28,
    -383,   721,  -240,  -749,  -749,   -55,    -4,   384,  -578,  -217,
      12,     4,    -2
};

/* YYTABLE[YYPACT[STATE-NUM]].  What to do in state STATE-NUM.  If
   positive, shift that token.  If negative, reduce the rule which
   number is the opposite.  If zero, do what YYDEFACT says.
   If YYTABLE_NINF, syntax error.  */
#define YYTABLE_NINF -573
static const yytype_int16 yytable[] =
{
     111,   273,   306,   404,    81,   541,    81,   227,   192,   531,
     497,   492,   719,   201,   201,   681,   193,   201,   208,   208,
     593,   613,   208,   225,   262,   228,   586,   190,   192,   555,
     680,   263,   343,   221,   586,   440,   193,   374,   727,   442,
     112,    67,   222,    67,   213,   213,   825,   190,   213,   253,
     257,    81,   208,   788,   263,   264,   593,   339,   207,   207,
     342,   657,   207,   208,   735,   838,   263,   263,   263,   292,
     830,   247,   677,   590,   190,   631,   641,   291,   264,   252,
     256,   879,   -99,   205,   215,   208,   208,   216,   762,   208,
     348,   359,   359,   251,   529,   900,   537,   710,   711,   291,
     377,   429,   379,   649,   798,   876,   737,   454,   538,   794,
     190,   556,   460,   806,   463,   379,   467,  -480,   223,  -479,
     799,   385,  -329,   224,   729,   616,   620,   621,   622,   623,
     386,   298,   299,   286,   287,   775,   822,   571,   572,  -481,
     469,  -482,   782,  -103,   650,   254,  -100,   825,  -488,  -107,
     455,   456,   457,     3,  -106,   378,  -489,   839,   529,   436,
     537,   624,  -102,   488,   920,   437,   230,   283,   626,  -104,
     735,   819,  -480,  -101,  -479,   -99,  -329,  -329,   827,   868,
     879,   831,   900,  -100,   738,   470,   606,   447,   641,   431,
     288,   627,   289,   825,  -481,  -103,  -482,   759,   -90,    81,
     298,   299,   404,  -105,   838,   397,   538,  -102,   950,   224,
     830,   397,   606,   380,   201,   593,   201,   201,   413,   208,
     557,   208,   208,   687,  -104,   208,   380,   208,   586,   586,
     768,   220,    81,   697,   279,   698,   906,   812,   971,   263,
     288,   224,   289,    81,    81,   213,   221,   213,   432,   385,
    -101,   736,   641,  -484,   443,   288,   291,   289,   735,   207,
     735,   207,   -91,   264,   247,   -98,   475,   476,   477,   478,
     -97,   910,  -550,   763,   240,  -103,   490,  -103,   -93,   898,
     428,   901,   860,   263,   405,   -95,   408,   544,   389,   -92,
     829,   391,   392,   832,    81,   208,   208,   208,   208,    81,
     208,   208,   645,   281,   208,  -411,    81,   264,  -484,   208,
     606,   -94,  -550,   542,   543,   300,  -483,   735,   922,   -96,
    -551,   924,   606,  -485,   805,   641,   247,   949,   474,   454,
     907,    67,   201,   413,   792,  -488,   479,   208,   288,  -102,
     289,  -102,   208,   208,   486,  -547,   302,   536,   793,   486,
    -474,   553,   -93,   527,   291,   554,  -104,   208,  -104,   735,
     402,   735,   -99,   492,  -411,   303,   -71,  -477,   960,   566,
     559,  -483,   455,   456,   439,   447,   307,   716,  -485,   288,
     437,   289,  -101,   -95,  -101,   208,   208,  -107,   334,   -90,
     899,   735,   902,   -85,   725,   485,   201,   413,   383,   600,
     496,   208,   986,   454,  -474,  -474,  -548,   462,   484,   397,
     397,   536,    56,   493,   644,   447,  -411,   527,  -411,  -411,
     192,   111,  -477,   587,   567,    81,   388,   263,   193,  -284,
     923,   593,   925,   784,    81,   545,   926,   536,   398,   190,
     223,   -93,   335,   336,   527,   586,   455,   456,   201,   413,
     390,   264,   393,   208,   308,   394,  -547,   395,  -474,  -474,
     308,  -547,    67,   536,   611,  -477,   401,   263,   -93,   527,
     -93,   609,   -95,   403,   -93,   427,   243,   959,   421,   961,
     653,   454,   962,  -284,  -284,  -554,  -551,   583,   585,   575,
     577,   264,   399,   400,   641,   430,   254,   423,   425,   -95,
     972,   -95,  -106,   720,   865,   -95,   329,   330,   331,   332,
     333,   661,   716,   217,   331,   332,   333,  -548,   903,  -477,
    -477,   985,  -548,   721,   455,   456,   459,   666,   308,   585,
    -102,   220,   254,   445,   446,   673,   -70,   813,   726,   450,
     664,    81,   435,    81,  -554,   441,   201,   413,   670,   665,
    -104,   208,   399,   426,   679,   679,   444,   672,   201,   413,
     714,   536,   449,   208,  -101,    81,   208,   527,   692,   673,
     673,   653,   653,   536,  -486,   464,   654,  -487,   947,   527,
     471,   192,   670,   670,   447,   397,   666,   682,   468,   193,
     263,   707,   709,   451,   452,   472,  -554,   791,  -554,  -554,
     190,  -550,   491,   208,   673,   545,   755,   415,   620,   621,
     622,   623,   666,  -278,   264,   800,   664,   670,   729,   547,
     620,   621,   622,   623,   243,   722,   548,   551,  -486,  -486,
     433,  -487,  -487,   742,   560,   742,   263,   742,   496,   783,
     784,   980,   454,   624,   706,   708,   417,   473,   764,   625,
     626,   808,  -489,    81,  -285,   418,   419,   424,   579,   595,
     264,   208,   597,   795,   208,   208,   797,  -278,  -278,   243,
     208,   208,   787,   627,   787,   928,   628,   715,   966,  -100,
     549,   550,   604,   666,   598,   455,   456,   461,   561,   562,
     585,   254,   208,   -85,   666,   208,    81,   612,   803,   756,
     384,   854,   454,   796,   855,    81,   -91,   818,  -285,  -285,
     659,   653,    81,    81,   863,  -264,   807,   646,   655,   658,
     397,   675,   870,   110,   190,   110,   427,  -107,   606,   561,
     562,   243,   967,   968,   764,   683,   668,   110,   110,    81,
      81,   110,   724,   728,   740,   455,   456,   465,   767,   669,
     743,    81,   745,  -106,   -98,   764,   852,   742,   746,   742,
     742,   777,   748,  -102,  -265,   493,   770,   784,   771,   773,
     110,   110,   904,   905,   778,   780,  -104,   776,   801,   208,
     -97,   814,   110,   820,   834,   208,    81,   841,  -101,   594,
     -93,    81,    81,   596,   840,    81,   756,   843,   599,   867,
     787,   845,   847,   -95,   110,   110,  -266,   679,   110,   862,
     872,   873,   263,   608,    81,   -92,   877,   881,   610,   882,
     883,   816,   892,   885,   742,   742,   940,   742,   887,   742,
     742,   293,   294,   295,   296,   297,   894,   729,   889,   620,
     621,   622,   623,   486,   895,   896,  -267,   619,   911,   620,
     621,   622,   623,   914,   918,   964,   919,   787,   927,   848,
     930,   932,   965,    81,   913,   970,   916,   935,   951,   603,
     953,   729,   656,   620,   621,   622,   623,   308,   750,   751,
    -550,   752,  -551,   850,   624,   858,   974,    44,    45,   263,
     625,   626,   321,   322,   864,   742,   742,   742,   346,   742,
     742,   363,   963,   817,   929,    81,   381,   254,   730,   983,
     382,    81,   277,   943,   627,   917,    81,   628,   110,    81,
     375,   742,   742,   742,   742,   897,   921,   826,   328,   329,
     330,   331,   332,   333,     0,     0,   787,   629,   110,     0,
     110,   110,     0,     0,   110,     0,   110,   527,     0,    81,
     835,   110,   620,   621,   622,   623,     0,   742,   742,   742,
     742,     0,   110,   110,   201,   413,   674,   803,   676,   208,
     742,     0,     0,     0,     0,     0,   666,     0,     0,   536,
       0,     0,     0,   742,     0,   527,     0,   619,     0,   620,
     621,   622,   623,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,     0,     0,   321,   322,
       0,     0,     0,   110,   110,   110,   110,   110,   110,   110,
     110,     0,     0,   110,   624,   110,     0,     0,   110,     0,
     625,   626,     0,     0,   323,   324,     0,     0,     0,     0,
     325,     0,   326,   327,   328,   329,   330,   331,   332,   333,
       0,   203,   203,     0,   627,   203,   110,   628,   308,     0,
       0,   110,   110,     0,     0,   619,     0,   620,   621,   622,
     623,     0,   224,   321,   322,     0,   110,   702,   765,     0,
       0,   236,   239,     0,     0,   804,   203,   203,     0,     0,
     755,     0,   620,   621,   622,   623,   284,   285,     0,     0,
       0,     0,   624,     0,   110,   110,     0,   815,   625,   626,
     329,   330,   331,   332,   333,     0,     0,     0,   821,   729,
     110,   620,   621,   622,   623,     0,   729,   624,   620,   621,
     622,   623,   627,   625,   626,   628,     0,   809,   810,     0,
       0,     0,     0,   308,   110,     0,     0,     0,     0,     0,
     249,     0,     0,   110,     0,     0,   730,   627,   321,   322,
     628,     0,   731,   730,   823,   824,     0,     0,     0,   878,
       0,     0,   110,     0,     0,     0,   833,     0,     0,     0,
       0,     0,     0,   337,   337,     0,     0,   337,     0,   869,
       0,     0,   326,   327,   328,   329,   330,   331,   332,   333,
       0,   875,     0,     0,     0,     0,   880,     0,     0,     0,
       0,   853,     0,     0,     0,     0,   856,   857,     0,     0,
     859,     0,     0,     0,     0,   105,     0,   105,     0,     0,
     203,     0,     0,   203,   203,   284,     0,     0,     0,   874,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   203,     0,   203,   203,     0,     0,     0,     0,
     110,     0,   110,     0,     0,     0,     0,     0,     0,     0,
     110,     0,   105,     0,     0,     0,   265,     0,     0,     0,
       0,     0,   110,     0,   110,   110,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   265,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   350,   360,   360,   360,     0,     0,     0,     0,     0,
       0,     0,   110,   414,     0,   416,     0,   744,     0,   747,
     938,     0,     0,     0,     0,     0,   939,   203,     0,     0,
       0,   948,   495,   498,   499,   500,   501,   502,   503,   504,
     505,   506,   507,   508,   509,   510,   511,   512,   513,   514,
     515,   516,   517,   518,   519,   520,   521,   522,   523,     0,
     203,     0,   110,     0,   969,     0,     0,     0,     0,     0,
     110,     0,     0,   110,   110,     0,     0,     0,     0,   110,
     110,     0,     0,   337,   337,   337,   337,     0,   480,   481,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   110,     0,     0,   110,   110,     0,     0,   576,   578,
     105,     0,     0,     0,   110,     0,     0,     0,   582,   203,
     203,   110,   110,     0,   203,     0,   576,   578,   203,     0,
     337,   337,     0,     0,     0,     0,     0,     0,     0,   842,
       0,   844,   846,   105,     0,   552,     0,   602,   110,   110,
       0,     0,   607,     0,   105,   105,     0,     0,     0,     0,
     110,   203,     0,     0,   203,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   265,     0,   203,     0,     0,   106,
       0,   106,     0,     0,     0,     0,     0,     0,   110,     0,
       0,     0,     0,     0,   110,   110,   647,   648,     0,     0,
     110,   110,     0,     0,   110,   105,   884,   886,   203,   888,
     105,   890,   891,     0,     0,     0,     0,   105,   265,     0,
       0,     0,     0,   110,     0,     0,   106,     0,     0,     0,
     266,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   308,   309,   310,   311,   312,   313,   314,   315,
       0,   317,   318,   266,     0,     0,     0,   321,   322,     0,
       0,     0,     0,     0,     0,   351,   361,   361,   361,     0,
     203,     0,   110,     0,   203,     0,     0,   931,   933,   934,
       0,   936,   937,   323,   324,     0,   203,     0,     0,     0,
       0,   326,   327,   328,   329,   330,   331,   332,   333,     0,
       0,     0,     0,   952,   954,   955,   956,     0,     0,   203,
       0,     0,     0,     0,   110,     0,     0,     0,     0,     0,
     110,     0,   203,   203,     0,   110,     0,     0,   110,     0,
       0,     0,     0,     0,     0,    78,   105,    78,     0,   973,
     975,   976,   977,     0,     0,   105,     0,     0,     0,     0,
       0,     0,   984,     0,   701,     0,     0,     0,   110,     0,
       0,     0,   265,     0,     0,   987,   108,     0,   108,     0,
       0,     0,     0,     0,   106,     0,     0,     0,   110,     0,
     203,     0,    78,     0,   582,   769,     0,   772,   774,     0,
       0,   723,     0,   779,   781,     0,     0,     0,     0,     0,
       0,     0,   265,     0,     0,     0,     0,   106,     0,     0,
       0,     0,     0,   108,     0,     0,     0,     0,   106,   106,
     109,   347,   109,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   811,   266,     0,
       0,     0,   772,   774,     0,   779,   781,     0,     0,     0,
       0,     0,   105,   203,   105,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,   106,
       0,   267,     0,     0,   106,     0,   105,     0,     0,     0,
     337,   106,   266,   337,     0,     0,     0,     0,     0,     0,
       0,   203,     0,     0,   267,   849,     0,     0,     0,     0,
       0,     0,   851,     0,     0,     0,   352,   362,   362,     0,
       0,     0,     0,     0,     0,     0,     0,   203,     0,     0,
       0,     0,     0,     0,     0,   265,   203,     0,     0,     0,
      78,     0,     0,     0,     0,     0,     0,     0,   851,   203,
       0,     0,  -572,     0,     0,     0,     0,     0,     0,     0,
    -572,  -572,  -572,     0,     0,  -572,  -572,  -572,     0,  -572,
       0,   108,     0,    78,   105,     0,     0,     0,     0,  -572,
       0,   265,     0,   337,    78,    78,     0,     0,     0,  -572,
    -572,     0,  -572,  -572,  -572,  -572,  -572,     0,     0,     0,
       0,     0,     0,     0,   108,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,   108,   108,   105,     0,   106,
       0,     0,     0,     0,     0,   109,   105,     0,     0,     0,
       0,     0,     0,   105,   105,    78,   266,  -572,     0,     0,
      78,     0,     0,     0,     0,     0,     0,    78,     0,     0,
     494,     0,     0,     0,     0,     0,     0,     0,   109,     0,
     105,   105,     0,     0,     0,     0,   108,     0,     0,   109,
     109,   108,   105,     0,     0,     0,   266,     0,   108,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   267,
    -572,     0,  -572,     0,   220,  -572,     0,  -572,     0,  -572,
       0,     0,   203,     0,     0,     0,     0,   105,     0,     0,
       0,     0,   105,   105,     0,     0,   105,     0,     0,     0,
     109,     0,     0,     0,     0,   109,   106,     0,   106,     0,
       0,     0,   109,   267,     0,   105,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   360,     0,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,     0,     0,    78,     0,     0,     0,     0,
       0,     0,     0,     0,   105,     0,     0,     0,   660,     0,
       0,     0,     0,     0,     0,     0,     0,   108,     0,   266,
       0,     0,     0,     0,     0,     0,   108,     0,     0,     0,
       0,     0,   308,   309,   310,   311,   312,   313,   314,   315,
     316,   317,   318,   319,   320,     0,   105,   321,   322,     0,
       0,     0,   105,     0,   944,     0,     0,   105,   106,     0,
     105,     0,     0,     0,     0,   266,     0,     0,     0,     0,
       0,   109,     0,   323,   324,     0,     0,     0,     0,   325,
     109,   326,   327,   328,   329,   330,   331,   332,   333,     0,
     105,     0,     0,     0,     0,     0,     0,   267,     0,     0,
       0,   106,    78,     0,    78,  -241,     0,     0,     0,     0,
     106,     0,     0,     0,     0,     0,     0,   106,   106,     0,
       0,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,     0,   108,     0,   108,     0,   267,     0,     0,
       0,     0,     0,     0,   106,   106,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   106,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,   109,
       0,   106,     0,     0,     0,     0,   106,   106,     0,     0,
     106,     0,     0,     0,   712,     0,     0,     0,     0,     0,
       0,   109,     0,     0,    78,     0,     0,     0,     0,   106,
       0,     0,   494,     0,     0,     0,     0,     0,   308,   309,
     310,   311,   312,   313,   314,   315,   316,   317,   318,   319,
     320,   361,     0,   321,   322,   108,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    78,     0,     0,
     267,     0,     0,     0,     0,     0,    78,     0,   106,   323,
     324,     0,     0,    78,    78,   325,     0,   326,   327,   328,
     329,   330,   331,   332,   333,     0,     0,     0,   108,     0,
       0,   754,     0,     0,     0,     0,     0,   108,     0,   109,
      78,    78,     0,     0,   108,   108,   267,     0,     0,     0,
     106,     0,    78,     0,     0,     0,   106,     0,   945,     0,
       0,   106,     0,     0,   106,     0,     0,     0,     0,     0,
       0,   108,   108,     0,     0,     0,     0,   660,     0,     0,
       0,     0,   109,   108,     0,     0,     0,    78,     0,     0,
       0,   109,    78,    78,   106,     0,    78,     0,   109,   109,
       0,   308,   309,   310,   311,   312,   313,   314,   315,   316,
     317,   318,   319,   320,     0,    78,   321,   322,   108,     0,
       0,     0,     0,   108,   108,   109,   109,   108,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   109,     0,     0,
       0,     0,   323,   324,     0,     0,   108,     0,   325,     0,
     326,   327,   328,   329,   330,   331,   332,   333,     0,     0,
       0,     0,     0,     0,    78,     0,     0,     0,     0,     0,
       0,     0,   109,     0,     0,     0,     0,   109,   109,     0,
       0,   109,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   108,     0,     0,     0,     0,
     109,     0,     0,     0,     0,     0,    78,     0,     0,     0,
       0,     0,    78,     0,   942,     0,     0,    78,     0,     0,
      78,     0,   362,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,     0,   108,   321,   322,
       0,     0,     0,   108,     0,     0,     0,     0,   108,   109,
      78,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   323,   324,     0,     0,     0,     0,
     325,     0,   326,   327,   328,   329,   330,   331,   332,   333,
       0,   108,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   109,     0,     0,     0,     0,     0,   109,     0,   946,
       0,     0,   109,     0,     0,   109,  -572,     4,     0,     5,
       6,     7,     8,     9,     0,     0,     0,    10,    11,     0,
       0,     0,    12,     0,    13,    14,    15,    16,    17,    18,
      19,     0,     0,     0,     0,   109,    20,    21,    22,    23,
      24,    25,    26,     0,     0,    27,     0,     0,     0,     0,
       0,    28,    29,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,    43,    44,
      45,     0,    46,    47,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    48,     0,     0,    49,    50,     0,    51,    52,
       0,    53,     0,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,    61,    62,  -284,
       0,     0,     0,     0,     0,     0,     0,  -284,  -284,  -284,
       0,    63,  -284,  -284,  -284,     0,  -284,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -284,  -284,  -284,     0,
       0,  -572,     0,  -572,     0,     0,  -284,  -284,     0,  -284,
    -284,  -284,  -284,  -284,     0,     0,     0,   308,   309,   310,
     311,   312,   313,   314,   315,   316,   317,   318,  -573,  -573,
       0,     0,   321,   322,     0,     0,     0,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
       0,     0,  -284,  -284,  -284,     0,   718,  -284,   323,   324,
       0,     0,     0,  -284,     0,     0,   326,   327,   328,   329,
     330,   331,   332,   333,     0,     0,  -284,     0,  -284,  -284,
       0,     0,     0,  -105,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -284,  -284,  -284,
    -284,  -410,  -284,  -284,  -284,     0,  -284,     0,     0,  -410,
    -410,  -410,     0,     0,  -410,  -410,  -410,     0,  -410,     0,
       0,     0,     0,     0,     0,     0,     0,  -410,  -410,  -410,
       0,     0,     0,     0,     0,     0,     0,     0,  -410,  -410,
       0,  -410,  -410,  -410,  -410,  -410,     0,     0,     0,   308,
    -573,  -573,  -573,  -573,   313,   314,     0,     0,  -573,  -573,
       0,     0,     0,     0,   321,   322,     0,     0,     0,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,  -410,
    -410,  -410,     0,     0,  -410,  -410,  -410,     0,     0,  -410,
     323,   324,     0,     0,     0,  -410,     0,     0,   326,   327,
     328,   329,   330,   331,   332,   333,     0,     0,     0,     0,
    -410,  -410,     0,     0,     0,     0,  -410,     0,  -410,  -410,
    -410,  -410,  -410,  -410,  -410,  -410,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -410,  -410,
    -410,  -410,  -410,   220,  -410,  -410,  -410,  -279,  -410,     0,
       0,     0,     0,     0,     0,  -279,  -279,  -279,     0,     0,
    -279,  -279,  -279,     0,  -279,     0,     0,     0,     0,     0,
       0,     0,     0,     0,  -279,  -279,  -279,     0,     0,     0,
       0,     0,     0,     0,  -279,  -279,     0,  -279,  -279,  -279,
    -279,  -279,     0,     0,     0,   308,   309,   310,   311,   312,
     313,   314,     0,     0,   317,   318,     0,     0,     0,     0,
     321,   322,     0,     0,     0,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,     0,     0,
    -279,  -279,  -279,     0,     0,  -279,   323,   324,     0,     0,
       0,  -279,     0,     0,   326,   327,   328,   329,   330,   331,
     332,   333,     0,     0,  -279,     0,  -279,  -279,     0,     0,
       0,     0,  -279,  -279,  -279,  -279,  -279,  -279,  -279,  -279,
    -279,  -279,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -279,  -279,  -279,  -279,  -572,
    -279,  -279,  -279,     0,  -279,     0,     0,  -572,  -572,  -572,
       0,     0,  -572,  -572,  -572,     0,  -572,     0,     0,     0,
       0,     0,     0,     0,     0,  -572,  -572,  -572,     0,     0,
       0,     0,     0,     0,     0,     0,  -572,  -572,     0,  -572,
    -572,  -572,  -572,  -572,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -572,  -572,  -572,
    -572,  -572,  -572,  -572,  -572,  -572,  -572,  -572,  -572,  -572,
       0,     0,  -572,  -572,  -572,     0,     0,  -572,     0,     0,
       0,     0,     0,  -572,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -572,  -572,
       0,     0,     0,     0,  -572,     0,  -572,  -572,  -572,  -572,
    -572,  -572,  -572,  -572,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -572,  -572,  -572,  -572,
    -572,   220,  -572,  -572,  -572,  -291,  -572,     0,     0,     0,
       0,     0,     0,  -291,  -291,  -291,     0,     0,  -291,  -291,
    -291,     0,  -291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -291,  -291,     0,     0,     0,     0,     0,     0,
       0,     0,  -291,  -291,     0,  -291,  -291,  -291,  -291,  -291,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
    -291,  -291,  -291,  -291,  -291,  -291,     0,     0,  -291,  -291,
    -291,     0,     0,  -291,     0,  -554,     0,     0,     0,  -291,
       0,     0,     0,  -554,  -554,  -554,     0,     0,     0,  -554,
    -554,     0,  -554,     0,  -291,  -291,     0,     0,     0,     0,
    -291,  -554,  -291,  -291,  -291,  -291,  -291,  -291,  -291,  -291,
       0,     0,  -554,  -554,     0,  -554,  -554,  -554,  -554,  -554,
       0,     0,     0,  -291,  -291,  -291,  -291,   217,  -291,  -291,
    -291,     0,  -291,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -554,  -554,  -554,  -554,  -554,  -554,     0,     0,  -554,  -554,
    -554,     0,   662,  -284,     0,     0,     0,     0,     0,     0,
       0,  -284,  -284,  -284,     0,     0,     0,  -284,  -284,     0,
    -284,     0,     0,     0,  -554,  -554,     0,     0,     0,  -103,
    -554,     0,  -554,  -554,  -554,  -554,  -554,  -554,  -554,  -554,
    -284,  -284,     0,  -284,  -284,  -284,  -284,  -284,     0,     0,
       0,     0,  -554,  -554,  -554,  -554,   -94,     0,  -554,     0,
    -554,     0,  -554,     0,     0,     0,     0,     0,     0,     0,
       0,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,
    -284,  -284,  -284,  -284,     0,     0,  -284,  -284,  -284,     0,
     663,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,  -284,  -284,     0,     0,     0,  -105,  -284,     0,
    -284,  -284,  -284,  -284,  -284,  -284,  -284,  -284,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -284,  -284,  -284,   -96,     0,  -284,     0,  -284,   241,
    -284,     5,     6,     7,     8,     9,  -572,  -572,  -572,    10,
      11,     0,     0,  -572,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,  -572,   241,  -572,     5,     6,     7,     8,
       9,     0,     0,  -572,    10,    11,     0,  -572,  -572,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -572,   241,
    -572,     5,     6,     7,     8,     9,     0,     0,  -572,    10,
      11,     0,     0,  -572,    12,  -572,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     4,
       0,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,     0,     0,  -572,    12,  -572,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    63,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,  -572,     0,     0,     0,
       0,     0,     0,  -572,   241,  -572,     5,     6,     7,     8,
       9,     0,     0,  -572,    10,    11,     0,     0,  -572,    12,
       0,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   241,     0,     5,     6,     7,     8,
       9,     0,  -572,  -572,    10,    11,     0,     0,  -572,    12,
    -572,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   241,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,     0,     0,  -572,    12,
    -572,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,   242,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   241,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,  -572,     0,  -572,    12,
    -572,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   241,     0,     5,     6,     7,     8,
       9,     0,     0,     0,    10,    11,  -572,     0,  -572,    12,
    -572,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,    63,     0,
       0,     0,     0,     0,   241,     0,     5,     6,     7,     8,
       9,  -572,     0,  -572,    10,    11,     0,     0,  -572,    12,
    -572,    13,    14,    15,    16,    17,    18,    19,     0,     0,
       0,     0,     0,    20,    21,    22,    23,    24,    25,    26,
       0,     0,    27,     0,     0,     0,     0,     0,    28,    29,
       0,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      40,     0,    41,    42,     0,    43,    44,    45,     0,    46,
      47,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,    48,
       0,     0,    49,    50,     0,    51,    52,     0,    53,     0,
      54,    55,    56,    57,    58,    59,    60,     0,     0,     0,
       0,     0,     0,     0,    61,    62,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,    63,     9,
       0,     0,     0,    10,    11,     0,     0,     0,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,  -572,     0,
    -572,     0,    20,    21,    22,    23,    24,    25,    26,     0,
       0,   194,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
     195,    41,    42,     0,    43,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,   197,    50,     0,    51,    52,     0,   198,   199,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,   200,    62,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,     0,     0,    63,    12,     0,
      13,    14,    15,    16,    17,    18,    19,     0,     0,     0,
       0,     0,    20,    21,    22,    23,    24,    25,    26,   224,
       0,    27,     0,     0,     0,     0,     0,     0,    29,     0,
       0,    32,    33,    34,    35,    36,    37,    38,    39,    40,
       0,    41,    42,     0,    43,    44,    45,     0,    46,    47,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   196,     0,
       0,   197,    50,     0,    51,    52,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,    61,    62,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     5,     6,     7,    63,     9,     0,
       0,     0,    10,    11,     0,     0,     0,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,   288,     0,   289,
       0,    20,    21,    22,    23,    24,    25,    26,     0,     0,
      27,     0,     0,     0,     0,     0,     0,    29,     0,     0,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,     0,    43,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   196,     0,     0,
     197,    50,     0,    51,    52,     0,     0,     0,    54,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,     5,     6,     7,     8,     9,     0,
       0,     0,    10,    11,     0,     0,    63,    12,     0,    13,
      14,    15,    16,    17,    18,    19,     0,     0,     0,     0,
       0,    20,    21,    22,    23,    24,    25,    26,   224,     0,
      27,     0,     0,     0,     0,     0,    28,    29,    30,    31,
      32,    33,    34,    35,    36,    37,    38,    39,    40,     0,
      41,    42,     0,    43,    44,    45,     0,    46,    47,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,    48,     0,     0,
      49,    50,     0,    51,    52,     0,    53,     0,    54,    55,
      56,    57,    58,    59,    60,     0,     0,     0,     0,     0,
       0,     0,    61,    62,     0,     0,     0,     0,     0,     0,
       5,     6,     7,     8,     9,     0,    63,     0,    10,    11,
       0,     0,     0,    12,     0,    13,    14,    15,    16,    17,
      18,    19,     0,     0,     0,     0,   473,    20,    21,    22,
      23,    24,    25,    26,     0,     0,    27,     0,     0,     0,
       0,     0,    28,    29,     0,    31,    32,    33,    34,    35,
      36,    37,    38,    39,    40,     0,    41,    42,     0,    43,
      44,    45,     0,    46,    47,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,    48,     0,     0,    49,    50,     0,    51,
      52,     0,    53,     0,    54,    55,    56,    57,    58,    59,
      60,     0,     0,     0,     0,     0,     0,     0,    61,    62,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,    63,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   473,   113,   114,   115,   116,   117,   118,   119,
     120,   121,   122,   123,   124,   125,   126,   127,   128,   129,
     130,   131,   132,   133,   134,   135,   136,     0,     0,     0,
     137,   138,   139,   364,   365,   366,   367,   144,   145,   146,
       0,     0,     0,     0,     0,   147,   148,   149,   150,   368,
     369,   370,   371,   155,    37,    38,   372,    40,     0,     0,
       0,     0,     0,     0,     0,     0,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,     0,   166,   167,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,   177,     0,     0,     0,     0,   178,   179,   180,
     181,   182,   183,   184,   185,     0,     0,     0,  -547,  -547,
    -547,     0,  -547,     0,     0,     0,  -547,  -547,     0,     0,
       0,  -547,   373,  -547,  -547,  -547,  -547,  -547,  -547,  -547,
       0,  -547,     0,     0,     0,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,     0,     0,  -547,     0,     0,     0,     0,     0,
       0,  -547,     0,     0,  -547,  -547,  -547,  -547,  -547,  -547,
    -547,  -547,  -547,  -547,  -547,  -547,     0,  -547,  -547,  -547,
       0,  -547,  -547,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,  -547,     0,     0,  -547,  -547,     0,  -547,  -547,     0,
    -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,  -547,     0,
       0,     0,     0,     0,     0,     0,  -547,  -547,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -547,     0,     0,     0,     0,  -548,  -548,  -548,     0,  -548,
       0,     0,  -547,  -548,  -548,     0,     0,  -547,  -548,     0,
    -548,  -548,  -548,  -548,  -548,  -548,  -548,     0,  -548,     0,
       0,     0,  -548,  -548,  -548,  -548,  -548,  -548,  -548,     0,
       0,  -548,     0,     0,     0,     0,     0,     0,  -548,     0,
       0,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,  -548,
    -548,  -548,  -548,     0,  -548,  -548,  -548,     0,  -548,  -548,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,  -548,     0,
       0,  -548,  -548,     0,  -548,  -548,     0,  -548,  -548,  -548,
    -548,  -548,  -548,  -548,  -548,  -548,     0,     0,     0,     0,
       0,     0,     0,  -548,  -548,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,  -548,     0,     0,
       0,     0,  -550,  -550,  -550,     0,  -550,     0,     0,  -548,
    -550,  -550,     0,     0,  -548,  -550,     0,  -550,  -550,  -550,
    -550,  -550,  -550,  -550,     0,     0,     0,     0,     0,  -550,
    -550,  -550,  -550,  -550,  -550,  -550,     0,     0,  -550,     0,
       0,     0,     0,     0,     0,  -550,     0,     0,  -550,  -550,
    -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,  -550,
       0,  -550,  -550,  -550,     0,  -550,  -550,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -550,   717,     0,  -550,  -550,
       0,  -550,  -550,     0,  -550,  -550,  -550,  -550,  -550,  -550,
    -550,  -550,  -550,     0,     0,     0,     0,     0,     0,     0,
    -550,  -550,     0,  -103,     0,     0,     0,  -552,  -552,  -552,
       0,  -552,     0,     0,  -550,  -552,  -552,     0,     0,     0,
    -552,     0,  -552,  -552,  -552,  -552,  -552,  -552,  -552,     0,
       0,  -550,     0,     0,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,     0,     0,  -552,     0,     0,     0,     0,     0,     0,
    -552,     0,     0,  -552,  -552,  -552,  -552,  -552,  -552,  -552,
    -552,  -552,  -552,  -552,  -552,     0,  -552,  -552,  -552,     0,
    -552,  -552,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
    -552,     0,     0,  -552,  -552,     0,  -552,  -552,     0,  -552,
    -552,  -552,  -552,  -552,  -552,  -552,  -552,  -552,     0,     0,
       0,     0,     0,     0,     0,  -552,  -552,     0,     0,     0,
       0,     0,  -553,  -553,  -553,     0,  -553,     0,     0,  -552,
    -553,  -553,     0,     0,     0,  -553,     0,  -553,  -553,  -553,
    -553,  -553,  -553,  -553,     0,     0,  -552,     0,     0,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,     0,     0,  -553,     0,
       0,     0,     0,     0,     0,  -553,     0,     0,  -553,  -553,
    -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,  -553,
       0,  -553,  -553,  -553,     0,  -553,  -553,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,  -553,     0,     0,  -553,  -553,
       0,  -553,  -553,     0,  -553,  -553,  -553,  -553,  -553,  -553,
    -553,  -553,  -553,     0,     0,     0,     0,     0,     0,     0,
    -553,  -553,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,  -553,    10,    11,     0,     0,     0,
      12,     0,    13,    14,    15,   231,   232,    18,    19,     0,
       0,  -553,     0,     0,   233,   234,   235,    23,    24,    25,
      26,     0,     0,   194,     0,     0,     0,     0,     0,     0,
     258,     0,     0,    32,    33,    34,    35,    36,    37,    38,
      39,    40,     0,    41,    42,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     259,     0,     0,   197,    50,     0,    51,    52,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,   260,
       0,     0,    12,     0,    13,    14,    15,   231,   232,    18,
      19,     0,     0,     0,     0,   261,   233,   234,   235,    23,
      24,    25,    26,     0,     0,   194,     0,     0,     0,     0,
       0,     0,   258,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,    43,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   259,     0,     0,   197,    50,     0,    51,    52,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,   260,     0,     0,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,   489,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     5,     6,     7,     8,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,    28,    29,     0,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,    48,     0,     0,    49,    50,     0,
      51,    52,     0,    53,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   198,   199,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   584,   199,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   198,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,     0,   199,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   584,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,   195,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   483,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   198,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   766,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   584,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,   483,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,    27,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,    61,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,    16,
      17,    18,    19,     0,     0,     0,     0,     0,    20,    21,
      22,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,    29,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,    46,    47,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   196,     0,     0,   197,    50,     0,
      51,    52,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,   200,
      62,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,    63,    12,     0,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,   258,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   259,     0,     0,   304,    50,     0,
      51,    52,     0,   305,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,     0,
       0,     0,    12,   260,    13,    14,    15,   231,   232,    18,
      19,     0,     0,     0,     0,     0,   233,   234,   235,    23,
      24,    25,    26,     0,     0,   194,     0,     0,     0,     0,
       0,     0,   258,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,    43,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   345,     0,     0,    49,    50,     0,    51,    52,
       0,    53,     0,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     5,     6,     7,
       0,     9,     0,     0,     0,    10,    11,     0,     0,     0,
      12,   260,    13,    14,    15,   231,   232,    18,    19,     0,
       0,     0,     0,     0,   233,   234,   235,    23,    24,    25,
      26,     0,     0,   194,     0,     0,     0,     0,     0,     0,
     258,     0,     0,    32,    33,    34,   353,    36,    37,    38,
     354,    40,     0,    41,    42,     0,    43,    44,    45,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   355,     0,     0,
     356,     0,     0,   197,    50,     0,    51,    52,     0,     0,
       0,    54,    55,    56,    57,    58,    59,    60,     0,     0,
       0,     0,     0,     0,     0,     5,     6,     7,     0,     9,
       0,     0,     0,    10,    11,     0,     0,     0,    12,   260,
      13,    14,    15,   231,   232,    18,    19,     0,     0,     0,
       0,     0,   233,   234,   235,    23,    24,    25,    26,     0,
       0,   194,     0,     0,     0,     0,     0,     0,   258,     0,
       0,    32,    33,    34,   353,    36,    37,    38,   354,    40,
       0,    41,    42,     0,    43,    44,    45,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   356,     0,
       0,   197,    50,     0,    51,    52,     0,     0,     0,    54,
      55,    56,    57,    58,    59,    60,     0,     0,     0,     0,
       0,     0,     0,     5,     6,     7,     0,     9,     0,     0,
       0,    10,    11,     0,     0,     0,    12,   260,    13,    14,
      15,   231,   232,    18,    19,     0,     0,     0,     0,     0,
     233,   234,   235,    23,    24,    25,    26,     0,     0,   194,
       0,     0,     0,     0,     0,     0,   258,     0,     0,    32,
      33,    34,    35,    36,    37,    38,    39,    40,     0,    41,
      42,     0,    43,    44,    45,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   259,     0,     0,   304,
      50,     0,    51,    52,     0,     0,     0,    54,    55,    56,
      57,    58,    59,    60,     0,     0,     0,     0,     0,     0,
       0,     5,     6,     7,     0,     9,     0,     0,     0,    10,
      11,     0,     0,     0,    12,   260,    13,    14,    15,   231,
     232,    18,    19,     0,     0,     0,     0,     0,   233,   234,
     235,    23,    24,    25,    26,     0,     0,   194,     0,     0,
       0,     0,     0,     0,   258,     0,     0,    32,    33,    34,
      35,    36,    37,    38,    39,    40,     0,    41,    42,     0,
      43,    44,    45,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   893,     0,     0,   197,    50,     0,
      51,    52,     0,     0,     0,    54,    55,    56,    57,    58,
      59,    60,     0,     0,     0,     0,     0,     0,     0,     5,
       6,     7,     0,     9,     0,     0,     0,    10,    11,     0,
       0,     0,    12,   260,    13,    14,    15,   231,   232,    18,
      19,     0,     0,     0,     0,     0,   233,   234,   235,    23,
      24,    25,    26,     0,     0,   194,     0,     0,     0,     0,
       0,     0,   258,     0,     0,    32,    33,    34,    35,    36,
      37,    38,    39,    40,     0,    41,    42,     0,    43,    44,
      45,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   941,     0,     0,   197,    50,     0,    51,    52,
       0,     0,     0,    54,    55,    56,    57,    58,    59,    60,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   260,   113,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,   125,   126,   127,   128,   129,   130,
     131,   132,   133,   134,   135,   136,     0,     0,     0,   137,
     138,   139,   140,   141,   142,   143,   144,   145,   146,     0,
       0,     0,     0,     0,   147,   148,   149,   150,   151,   152,
     153,   154,   155,   270,   271,   156,   272,     0,     0,     0,
       0,     0,     0,     0,     0,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,   166,   167,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,     0,     0,     0,     0,   178,   179,   180,   181,
     182,   183,   184,   185,   113,   114,   115,   116,   117,   118,
     119,   120,   121,   122,   123,   124,   125,   126,   127,   128,
     129,   130,   131,   132,   133,   134,   135,   136,     0,     0,
       0,   137,   138,   139,   140,   141,   142,   143,   144,   145,
     146,     0,     0,     0,     0,     0,   147,   148,   149,   150,
     151,   152,   153,   154,   155,   226,     0,   156,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,     0,   166,   167,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,    55,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,     0,   178,   179,
     180,   181,   182,   183,   184,   185,   113,   114,   115,   116,
     117,   118,   119,   120,   121,   122,   123,   124,   125,   126,
     127,   128,   129,   130,   131,   132,   133,   134,   135,   136,
       0,     0,     0,   137,   138,   139,   140,   141,   142,   143,
     144,   145,   146,     0,     0,     0,     0,     0,   147,   148,
     149,   150,   151,   152,   153,   154,   155,     0,     0,   156,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,     0,
     166,   167,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,    55,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,   179,   180,   181,   182,   183,   184,   185,   113,   114,
     115,   116,   117,   118,   119,   120,   121,   122,   123,   124,
     125,   126,   127,   128,   129,   130,   131,   132,   133,   134,
     135,   136,     0,     0,     0,   137,   138,   139,   140,   141,
     142,   143,   144,   145,   146,     0,     0,     0,     0,     0,
     147,   148,   149,   150,   151,   152,   153,   154,   155,     0,
       0,   156,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,     0,   166,   167,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,   177,     0,     0,
       0,     0,   178,   179,   180,   181,   182,   183,   184,   185,
     524,   525,     0,     0,   526,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,     0,   166,   167,     0,     0,   168,
     169,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,     0,     0,     0,     0,   178,   179,   180,   181,   182,
     183,   184,   185,     0,     0,     0,     0,   532,   533,     0,
       0,   534,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,     0,   166,   167,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,   177,     0,     0,
       0,     0,   178,   179,   180,   181,   182,   183,   184,   185,
       0,     0,     0,     0,   588,   525,     0,     0,   589,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,     0,   166,
     167,     0,     0,   168,   169,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,   177,     0,     0,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,     0,     0,     0,
       0,   591,   533,     0,     0,   592,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,   166,   167,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,     0,     0,     0,     0,   178,   179,   180,   181,
     182,   183,   184,   185,     0,     0,     0,     0,   614,   525,
       0,     0,   615,     0,     0,     0,     0,     0,     0,     0,
       0,   220,   157,   158,   159,   160,   161,   162,   163,   164,
     165,     0,     0,   166,   167,     0,     0,   168,   169,   170,
     171,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   172,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   173,   174,   175,   176,   177,     0,
       0,     0,     0,   178,   179,   180,   181,   182,   183,   184,
     185,     0,     0,     0,     0,   617,   533,     0,     0,   618,
       0,     0,     0,     0,     0,     0,     0,     0,   220,   157,
     158,   159,   160,   161,   162,   163,   164,   165,     0,     0,
     166,   167,     0,     0,   168,   169,   170,   171,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   172,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,   173,   174,   175,   176,   177,     0,     0,     0,     0,
     178,   179,   180,   181,   182,   183,   184,   185,     0,     0,
       0,     0,   685,   525,     0,     0,   686,     0,     0,     0,
       0,     0,     0,     0,     0,   220,   157,   158,   159,   160,
     161,   162,   163,   164,   165,     0,     0,   166,   167,     0,
       0,   168,   169,   170,   171,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   172,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,   173,   174,
     175,   176,   177,     0,     0,     0,     0,   178,   179,   180,
     181,   182,   183,   184,   185,     0,     0,     0,     0,   688,
     533,     0,     0,   689,     0,     0,     0,     0,     0,     0,
       0,     0,   220,   157,   158,   159,   160,   161,   162,   163,
     164,   165,     0,     0,   166,   167,     0,     0,   168,   169,
     170,   171,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   172,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,   173,   174,   175,   176,   177,
       0,     0,     0,     0,   178,   179,   180,   181,   182,   183,
     184,   185,     0,     0,     0,     0,   695,   525,     0,     0,
     696,     0,     0,     0,     0,     0,     0,     0,     0,   220,
     157,   158,   159,   160,   161,   162,   163,   164,   165,     0,
       0,   166,   167,     0,     0,   168,   169,   170,   171,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   172,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,   173,   174,   175,   176,   177,     0,     0,     0,
       0,   178,   179,   180,   181,   182,   183,   184,   185,     0,
       0,     0,     0,   569,   533,     0,     0,   570,     0,     0,
       0,     0,     0,     0,     0,     0,   220,   157,   158,   159,
     160,   161,   162,   163,   164,   165,     0,     0,   166,   167,
       0,     0,   168,   169,   170,   171,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   172,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,   173,
     174,   175,   176,   177,     0,     0,     0,     0,   178,   179,
     180,   181,   182,   183,   184,   185,     0,     0,     0,     0,
     957,   525,     0,     0,   958,     0,     0,     0,     0,     0,
       0,     0,     0,   220,   157,   158,   159,   160,   161,   162,
     163,   164,   165,     0,     0,   166,   167,     0,     0,   168,
     169,   170,   171,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   172,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,   173,   174,   175,   176,
     177,     0,     0,     0,     0,   178,   179,   180,   181,   182,
     183,   184,   185,     0,     0,     0,     0,   978,   525,     0,
       0,   979,     0,     0,     0,     0,     0,     0,     0,     0,
     220,   157,   158,   159,   160,   161,   162,   163,   164,   165,
       0,     0,   166,   167,     0,     0,   168,   169,   170,   171,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     172,     0,     0,     0,     0,     0,     0,     0,     0,     0,
       0,     0,     0,   173,   174,   175,   176,   177,     0,     0,
       0,     0,   178,   179,   180,   181,   182,   183,   184,   185,
       0,     0,     0,     0,   981,   533,     0,     0,   982,     0,
       0,     0,     0,     0,     0,     0,     0,   220,   157,   158,
     159,   160,   161,   162,   163,   164,   165,     0,     0,   166,
     167,     0,     0,   168,   169,   170,   171,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   172,     0,     0,
       0,     0,     0,     0,     0,     0,     0,     0,     0,     0,
     173,   174,   175,   176,   177,     0,     0,     0,     0,   178,
     179,   180,   181,   182,   183,   184,   185,     0,     0,     0,
       0,   569,   533,     0,     0,   570,     0,     0,     0,     0,
       0,     0,     0,     0,   220,   157,   158,   159,   160,   161,
     162,   163,   164,   165,     0,     0,   166,   167,     0,     0,
     168,   169,   170,   171,     0,     0,     0,     0,     0,     0,
       0,     0,     0,     0,   172,     0,     0,     0,     0,     0,
       0,     0,     0,     0,     0,     0,     0,   173,   174,   175,
     176,   177,     0,     0,     0,     0,   178,   179,   180,   181,
     182,   183,   184,   185
};

static const yytype_int16 yycheck[] =
{
       2,    55,    76,   213,     2,   339,     4,    28,     8,   335,
     307,   307,   590,    16,    17,   544,     8,    20,    16,    17,
     403,   449,    20,    27,    53,    29,   395,     8,    28,   356,
     543,    53,    87,    22,   403,   252,    28,    91,   616,   256,
       4,     2,    22,     4,    16,    17,   740,    28,    20,    51,
      52,    49,    50,   676,    76,    53,   439,    84,    16,    17,
      87,   489,    20,    61,   624,   756,    88,    89,    90,    65,
     743,    49,    27,   399,    55,   453,   453,    65,    76,    51,
      52,   820,    25,    16,    17,    83,    84,    20,   650,    87,
      88,    89,    90,    51,   334,   843,   336,   573,   574,    87,
      85,   242,    26,    76,   694,   818,    29,    61,    13,   687,
      91,     1,   276,   703,   278,    26,   280,    85,   142,    85,
     698,   110,    85,   147,    52,   451,    54,    55,    56,    57,
     110,    37,    38,    59,    60,   665,   736,   377,   378,    85,
      61,    85,   672,    13,   117,    52,    25,   841,    87,    25,
     104,   105,   106,     0,    25,   140,    87,   757,   398,   141,
     400,    89,    25,   304,   877,   147,   137,    61,    96,    25,
     730,   731,   140,    25,   140,   114,   139,   140,   740,   802,
     919,   743,   930,   114,   107,   106,   426,   261,   565,   244,
     145,   119,   147,   887,   140,    25,   140,   650,   141,   197,
      37,    38,   412,    25,   895,   207,    13,    13,   921,   147,
     883,   213,   452,   137,   217,   598,   219,   220,   220,   217,
     110,   219,   220,   549,    13,   223,   137,   225,   597,   598,
     658,   142,   230,   560,   146,   561,   859,   713,   951,   261,
     145,   147,   147,   241,   242,   217,   235,   219,   244,   238,
      13,   629,   629,    85,   258,   145,   244,   147,   818,   217,
     820,   219,   141,   261,   242,   141,   293,   294,   295,   296,
     141,   861,   142,   650,    56,   145,   305,   147,   141,   841,
     241,   843,   795,   305,   217,   141,   219,   342,   195,   141,
     743,   198,   199,   746,   292,   293,   294,   295,   296,   297,
     298,   299,   466,   146,   302,    26,   304,   305,   140,   307,
     550,   141,   142,   340,   341,    28,    85,   877,   878,   141,
     142,   883,   562,    85,   702,   702,   304,   917,   292,    61,
     859,   292,   335,   335,   141,    87,   297,   335,   145,   145,
     147,   147,   340,   341,   302,    26,   114,   336,   682,   307,
      85,    52,    25,   334,   342,    56,   145,   355,   147,   919,
      87,   921,   114,   659,    85,   141,   114,    85,   930,    85,
     358,   140,   104,   105,   141,   449,   114,   587,   140,   145,
     147,   147,   145,    25,   147,   383,   384,   114,    85,   141,
     843,   951,   845,   141,   611,   302,   399,   399,    87,   420,
     307,   399,   980,    61,    85,   140,    26,    65,   302,   411,
     412,   400,    99,   307,   146,   489,   137,   398,   139,   140,
     420,   423,   140,   395,   140,   423,   141,   449,   420,    85,
     883,   814,   885,    15,   432,    17,   889,   426,    85,   420,
     142,   114,   139,   140,   425,   814,   104,   105,   451,   451,
      56,   449,   114,   451,    68,    88,   137,   141,   139,   140,
      68,   142,   423,   452,   436,    85,    87,   489,   141,   450,
     143,   432,   114,   141,   147,    87,    49,   930,   142,   932,
     482,    61,   935,   139,   140,    26,   142,   394,   395,   383,
     384,   489,   139,   140,   871,   143,   403,   137,    85,   141,
     953,   143,   114,    87,   801,   147,   120,   121,   122,   123,
     124,   515,   722,   142,   122,   123,   124,   137,   852,   139,
     140,   974,   142,    87,   104,   105,   106,   531,    68,   436,
     114,   142,   439,    59,    60,   537,   114,    87,   612,    85,
     529,   539,   144,   541,    85,   138,   549,   549,   537,   529,
     114,   549,   139,   140,   542,   543,    56,   537,   561,   561,
     581,   550,   141,   561,   114,   563,   564,   548,   556,   571,
     572,   573,   574,   562,    85,   106,   483,    85,   912,   560,
      68,   581,   571,   572,   658,   587,   590,   545,   106,   581,
     612,   571,   572,   139,   140,    68,   137,   681,   139,   140,
     581,   142,   141,   601,   606,    17,    52,   223,    54,    55,
      56,    57,   616,    85,   612,   699,   605,   606,    52,    56,
      54,    55,    56,    57,   197,   597,    85,    25,   139,   140,
     246,   139,   140,   635,    85,   637,   658,   639,   545,    14,
      15,   967,    61,    89,   571,   572,    54,   145,   650,    95,
      96,   705,    87,   651,    85,    63,    64,   230,    94,   143,
     658,   659,   141,   690,   662,   663,   693,   139,   140,   242,
     668,   669,   674,   119,   676,    85,   122,   584,    85,   114,
     139,   140,   138,   687,   141,   104,   105,   106,   139,   140,
     597,   598,   690,   141,   698,   693,   694,   141,   700,   145,
      87,   785,    61,   691,   788,   703,   141,   141,   139,   140,
     114,   713,   710,   711,   798,   141,   704,   146,   141,   141,
     722,    13,   806,     2,   705,     4,    87,   114,   968,   139,
     140,   304,   139,   140,   736,    10,    87,    16,    17,   737,
     738,    20,   138,   114,   141,   104,   105,   106,   655,    87,
     141,   749,    52,   114,   141,   757,   783,   759,   141,   761,
     762,    87,    52,   114,   141,   659,   116,    15,   662,   663,
      49,    50,   856,   857,   668,   669,   114,   144,     8,   777,
     141,   141,    61,   141,   114,   783,   784,   141,   114,   405,
     141,   789,   790,   409,   117,   793,   145,   141,   414,   801,
     802,   141,    10,   141,    83,    84,   141,   795,    87,   797,
      10,   138,   834,   429,   812,   141,   141,    10,   434,   138,
     141,   728,   138,   141,   826,   827,   910,   829,   141,   831,
     832,    40,    41,    42,    43,    44,   834,    52,   141,    54,
      55,    56,    57,   801,   141,   117,   141,    52,    88,    54,
      55,    56,    57,     9,   138,   939,   141,   859,    56,   766,
     141,   141,    56,   861,   866,   949,   868,   141,   141,   423,
     141,    52,   488,    54,    55,    56,    57,    68,    54,    55,
     142,    57,   142,   777,    89,   792,   141,    63,    64,   911,
      95,    96,    83,    84,   801,   897,   898,   899,    88,   901,
     902,    90,   938,   730,   895,   903,    93,   814,    89,   969,
      96,   909,    57,   911,   119,   871,   914,   122,   197,   917,
      91,   923,   924,   925,   926,   841,   141,   740,   119,   120,
     121,   122,   123,   124,    -1,    -1,   938,   142,   217,    -1,
     219,   220,    -1,    -1,   223,    -1,   225,   928,    -1,   947,
      52,   230,    54,    55,    56,    57,    -1,   959,   960,   961,
     962,    -1,   241,   242,   967,   967,   539,   969,   541,   967,
     972,    -1,    -1,    -1,    -1,    -1,   980,    -1,    -1,   968,
      -1,    -1,    -1,   985,    -1,   966,    -1,    52,    -1,    54,
      55,    56,    57,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    84,
      -1,    -1,    -1,   292,   293,   294,   295,   296,   297,   298,
     299,    -1,    -1,   302,    89,   304,    -1,    -1,   307,    -1,
      95,    96,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    16,    17,    -1,   119,    20,   335,   122,    68,    -1,
      -1,   340,   341,    -1,    -1,    52,    -1,    54,    55,    56,
      57,    -1,   147,    83,    84,    -1,   355,   142,   651,    -1,
      -1,    46,    47,    -1,    -1,   701,    51,    52,    -1,    -1,
      52,    -1,    54,    55,    56,    57,    61,    62,    -1,    -1,
      -1,    -1,    89,    -1,   383,   384,    -1,   723,    95,    96,
     120,   121,   122,   123,   124,    -1,    -1,    -1,   734,    52,
     399,    54,    55,    56,    57,    -1,    52,    89,    54,    55,
      56,    57,   119,    95,    96,   122,    -1,   710,   711,    -1,
      -1,    -1,    -1,    68,   423,    -1,    -1,    -1,    -1,    -1,
      50,    -1,    -1,   432,    -1,    -1,    89,   119,    83,    84,
     122,    -1,    95,    89,   737,   738,    -1,    -1,    -1,    95,
      -1,    -1,   451,    -1,    -1,    -1,   749,    -1,    -1,    -1,
      -1,    -1,    -1,    83,    84,    -1,    -1,    87,    -1,   805,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   817,    -1,    -1,    -1,    -1,   822,    -1,    -1,    -1,
      -1,   784,    -1,    -1,    -1,    -1,   789,   790,    -1,    -1,
     793,    -1,    -1,    -1,    -1,     2,    -1,     4,    -1,    -1,
     195,    -1,    -1,   198,   199,   200,    -1,    -1,    -1,   812,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   217,    -1,   219,   220,    -1,    -1,    -1,    -1,
     539,    -1,   541,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     549,    -1,    49,    -1,    -1,    -1,    53,    -1,    -1,    -1,
      -1,    -1,   561,    -1,   563,   564,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    76,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    88,    89,    90,    91,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   601,   223,    -1,   225,    -1,   637,    -1,   639,
     903,    -1,    -1,    -1,    -1,    -1,   909,   302,    -1,    -1,
      -1,   914,   307,   308,   309,   310,   311,   312,   313,   314,
     315,   316,   317,   318,   319,   320,   321,   322,   323,   324,
     325,   326,   327,   328,   329,   330,   331,   332,   333,    -1,
     335,    -1,   651,    -1,   947,    -1,    -1,    -1,    -1,    -1,
     659,    -1,    -1,   662,   663,    -1,    -1,    -1,    -1,   668,
     669,    -1,    -1,   293,   294,   295,   296,    -1,   298,   299,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   690,    -1,    -1,   693,   694,    -1,    -1,   383,   384,
     197,    -1,    -1,    -1,   703,    -1,    -1,    -1,   393,   394,
     395,   710,   711,    -1,   399,    -1,   401,   402,   403,    -1,
     340,   341,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   759,
      -1,   761,   762,   230,    -1,   355,    -1,   422,   737,   738,
      -1,    -1,   427,    -1,   241,   242,    -1,    -1,    -1,    -1,
     749,   436,    -1,    -1,   439,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   261,    -1,   451,    -1,    -1,     2,
      -1,     4,    -1,    -1,    -1,    -1,    -1,    -1,   777,    -1,
      -1,    -1,    -1,    -1,   783,   784,   471,   472,    -1,    -1,
     789,   790,    -1,    -1,   793,   292,   826,   827,   483,   829,
     297,   831,   832,    -1,    -1,    -1,    -1,   304,   305,    -1,
      -1,    -1,    -1,   812,    -1,    -1,    49,    -1,    -1,    -1,
      53,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      -1,    77,    78,    76,    -1,    -1,    -1,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    88,    89,    90,    91,    -1,
     545,    -1,   861,    -1,   549,    -1,    -1,   897,   898,   899,
      -1,   901,   902,   109,   110,    -1,   561,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,   923,   924,   925,   926,    -1,    -1,   584,
      -1,    -1,    -1,    -1,   903,    -1,    -1,    -1,    -1,    -1,
     909,    -1,   597,   598,    -1,   914,    -1,    -1,   917,    -1,
      -1,    -1,    -1,    -1,    -1,     2,   423,     4,    -1,   959,
     960,   961,   962,    -1,    -1,   432,    -1,    -1,    -1,    -1,
      -1,    -1,   972,    -1,   564,    -1,    -1,    -1,   947,    -1,
      -1,    -1,   449,    -1,    -1,   985,     2,    -1,     4,    -1,
      -1,    -1,    -1,    -1,   197,    -1,    -1,    -1,   967,    -1,
     655,    -1,    49,    -1,   659,   660,    -1,   662,   663,    -1,
      -1,   601,    -1,   668,   669,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   489,    -1,    -1,    -1,    -1,   230,    -1,    -1,
      -1,    -1,    -1,    49,    -1,    -1,    -1,    -1,   241,   242,
       2,    88,     4,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   712,   261,    -1,
      -1,    -1,   717,   718,    -1,   720,   721,    -1,    -1,    -1,
      -1,    -1,   539,   728,   541,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    49,    -1,   292,
      -1,    53,    -1,    -1,   297,    -1,   563,    -1,    -1,    -1,
     690,   304,   305,   693,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   766,    -1,    -1,    76,   770,    -1,    -1,    -1,    -1,
      -1,    -1,   777,    -1,    -1,    -1,    88,    89,    90,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   792,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   612,   801,    -1,    -1,    -1,
     197,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   813,   814,
      -1,    -1,     0,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
       8,     9,    10,    -1,    -1,    13,    14,    15,    -1,    17,
      -1,   197,    -1,   230,   651,    -1,    -1,    -1,    -1,    27,
      -1,   658,    -1,   783,   241,   242,    -1,    -1,    -1,    37,
      38,    -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   230,    -1,    -1,    -1,    -1,    -1,
     423,    -1,    -1,    -1,    -1,   241,   242,   694,    -1,   432,
      -1,    -1,    -1,    -1,    -1,   197,   703,    -1,    -1,    -1,
      -1,    -1,    -1,   710,   711,   292,   449,    85,    -1,    -1,
     297,    -1,    -1,    -1,    -1,    -1,    -1,   304,    -1,    -1,
     307,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   230,    -1,
     737,   738,    -1,    -1,    -1,    -1,   292,    -1,    -1,   241,
     242,   297,   749,    -1,    -1,    -1,   489,    -1,   304,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   261,
     138,    -1,   140,    -1,   142,   143,    -1,   145,    -1,   147,
      -1,    -1,   967,    -1,    -1,    -1,    -1,   784,    -1,    -1,
      -1,    -1,   789,   790,    -1,    -1,   793,    -1,    -1,    -1,
     292,    -1,    -1,    -1,    -1,   297,   539,    -1,   541,    -1,
      -1,    -1,   304,   305,    -1,   812,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     563,    -1,    -1,    -1,    -1,    -1,    -1,   834,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   861,    -1,    -1,    -1,    44,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   423,    -1,   612,
      -1,    -1,    -1,    -1,    -1,    -1,   432,    -1,    -1,    -1,
      -1,    -1,    68,    69,    70,    71,    72,    73,    74,    75,
      76,    77,    78,    79,    80,    -1,   903,    83,    84,    -1,
      -1,    -1,   909,    -1,   911,    -1,    -1,   914,   651,    -1,
     917,    -1,    -1,    -1,    -1,   658,    -1,    -1,    -1,    -1,
      -1,   423,    -1,   109,   110,    -1,    -1,    -1,    -1,   115,
     432,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
     947,    -1,    -1,    -1,    -1,    -1,    -1,   449,    -1,    -1,
      -1,   694,   539,    -1,   541,   141,    -1,    -1,    -1,    -1,
     703,    -1,    -1,    -1,    -1,    -1,    -1,   710,   711,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   563,    -1,    -1,    -1,
      -1,    -1,    -1,   539,    -1,   541,    -1,   489,    -1,    -1,
      -1,    -1,    -1,    -1,   737,   738,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   749,   563,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   539,    -1,   541,
      -1,   784,    -1,    -1,    -1,    -1,   789,   790,    -1,    -1,
     793,    -1,    -1,    -1,    44,    -1,    -1,    -1,    -1,    -1,
      -1,   563,    -1,    -1,   651,    -1,    -1,    -1,    -1,   812,
      -1,    -1,   659,    -1,    -1,    -1,    -1,    -1,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,   834,    -1,    83,    84,   651,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   694,    -1,    -1,
     612,    -1,    -1,    -1,    -1,    -1,   703,    -1,   861,   109,
     110,    -1,    -1,   710,   711,   115,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,   694,    -1,
      -1,   643,    -1,    -1,    -1,    -1,    -1,   703,    -1,   651,
     737,   738,    -1,    -1,   710,   711,   658,    -1,    -1,    -1,
     903,    -1,   749,    -1,    -1,    -1,   909,    -1,   911,    -1,
      -1,   914,    -1,    -1,   917,    -1,    -1,    -1,    -1,    -1,
      -1,   737,   738,    -1,    -1,    -1,    -1,    44,    -1,    -1,
      -1,    -1,   694,   749,    -1,    -1,    -1,   784,    -1,    -1,
      -1,   703,   789,   790,   947,    -1,   793,    -1,   710,   711,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,   812,    83,    84,   784,    -1,
      -1,    -1,    -1,   789,   790,   737,   738,   793,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   749,    -1,    -1,
      -1,    -1,   109,   110,    -1,    -1,   812,    -1,   115,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,   861,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   784,    -1,    -1,    -1,    -1,   789,   790,    -1,
      -1,   793,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   861,    -1,    -1,    -1,    -1,
     812,    -1,    -1,    -1,    -1,    -1,   903,    -1,    -1,    -1,
      -1,    -1,   909,    -1,   911,    -1,    -1,   914,    -1,    -1,
     917,    -1,   834,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,   903,    83,    84,
      -1,    -1,    -1,   909,    -1,    -1,    -1,    -1,   914,   861,
     947,   917,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,   947,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   903,    -1,    -1,    -1,    -1,    -1,   909,    -1,   911,
      -1,    -1,   914,    -1,    -1,   917,     0,     1,    -1,     3,
       4,     5,     6,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,   947,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    45,    46,    47,    48,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,     0,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     8,     9,    10,
      -1,   125,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    27,    28,    29,    -1,
      -1,   145,    -1,   147,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    84,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    84,    85,    -1,    87,    88,   109,   110,
      -1,    -1,    -1,    94,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,   107,    -1,   109,   110,
      -1,    -1,    -1,   114,   115,   116,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   138,   139,   140,
     141,     0,   143,   144,   145,    -1,   147,    -1,    -1,     8,
       9,    10,    -1,    -1,    13,    14,    15,    -1,    17,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    26,    27,    28,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    37,    38,
      -1,    40,    41,    42,    43,    44,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      -1,    -1,    -1,    -1,    83,    84,    -1,    -1,    -1,    68,
      69,    70,    71,    72,    73,    74,    75,    76,    77,    78,
      79,    80,    -1,    -1,    83,    84,    85,    -1,    -1,    88,
     109,   110,    -1,    -1,    -1,    94,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
     109,   110,    -1,    -1,    -1,    -1,   115,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   137,   138,
     139,   140,   141,   142,   143,   144,   145,     0,   147,    -1,
      -1,    -1,    -1,    -1,    -1,     8,     9,    10,    -1,    -1,
      13,    14,    15,    -1,    17,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    27,    28,    29,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    37,    38,    -1,    40,    41,    42,
      43,    44,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    -1,    -1,    -1,    -1,
      83,    84,    -1,    -1,    -1,    68,    69,    70,    71,    72,
      73,    74,    75,    76,    77,    78,    79,    80,    -1,    -1,
      83,    84,    85,    -1,    -1,    88,   109,   110,    -1,    -1,
      -1,    94,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,   107,    -1,   109,   110,    -1,    -1,
      -1,    -1,   115,   116,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   138,   139,   140,   141,     0,
     143,   144,   145,    -1,   147,    -1,    -1,     8,     9,    10,
      -1,    -1,    13,    14,    15,    -1,    17,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    26,    27,    28,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    37,    38,    -1,    40,
      41,    42,    43,    44,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    68,    69,    70,
      71,    72,    73,    74,    75,    76,    77,    78,    79,    80,
      -1,    -1,    83,    84,    85,    -1,    -1,    88,    -1,    -1,
      -1,    -1,    -1,    94,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   109,   110,
      -1,    -1,    -1,    -1,   115,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   137,   138,   139,   140,
     141,   142,   143,   144,   145,     0,   147,    -1,    -1,    -1,
      -1,    -1,    -1,     8,     9,    10,    -1,    -1,    13,    14,
      15,    -1,    17,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    27,    28,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    84,
      85,    -1,    -1,    88,    -1,     0,    -1,    -1,    -1,    94,
      -1,    -1,    -1,     8,     9,    10,    -1,    -1,    -1,    14,
      15,    -1,    17,    -1,   109,   110,    -1,    -1,    -1,    -1,
     115,    26,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    37,    38,    -1,    40,    41,    42,    43,    44,
      -1,    -1,    -1,   138,   139,   140,   141,   142,   143,   144,
     145,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    68,    69,    70,    71,    72,    73,    74,
      75,    76,    77,    78,    79,    80,    -1,    -1,    83,    84,
      85,    -1,    87,     0,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     8,     9,    10,    -1,    -1,    -1,    14,    15,    -1,
      17,    -1,    -1,    -1,   109,   110,    -1,    -1,    -1,   114,
     115,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      37,    38,    -1,    40,    41,    42,    43,    44,    -1,    -1,
      -1,    -1,   137,   138,   139,   140,   141,    -1,   143,    -1,
     145,    -1,   147,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    68,    69,    70,    71,    72,    73,    74,    75,    76,
      77,    78,    79,    80,    -1,    -1,    83,    84,    85,    -1,
      87,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   109,   110,    -1,    -1,    -1,   114,   115,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   138,   139,   140,   141,    -1,   143,    -1,   145,     1,
     147,     3,     4,     5,     6,     7,     8,     9,    10,    11,
      12,    -1,    -1,    15,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   145,     1,   147,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    14,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   145,     1,
     147,     3,     4,     5,     6,     7,    -1,    -1,    10,    11,
      12,    -1,    -1,    15,    16,    17,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,     1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   145,    16,   147,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   138,    -1,    -1,    -1,
      -1,    -1,    -1,   145,     1,   147,     3,     4,     5,     6,
       7,    -1,    -1,    10,    11,    12,    -1,    -1,    15,    16,
      -1,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,     9,    10,    11,    12,    -1,    -1,   145,    16,
     147,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,    -1,    -1,   145,    16,
     147,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   143,    -1,   145,    16,
     147,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,    -1,    -1,    -1,    11,    12,   143,    -1,   145,    16,
     147,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,
      -1,    -1,    -1,    -1,     1,    -1,     3,     4,     5,     6,
       7,   138,    -1,    10,    11,    12,    -1,    -1,   145,    16,
     147,    18,    19,    20,    21,    22,    23,    24,    -1,    -1,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      -1,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    -1,    59,    60,    -1,    62,    63,    64,    -1,    66,
      67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,
      -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,    -1,
      97,    98,    99,   100,   101,   102,   103,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,   125,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,   145,    -1,
     147,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,    92,    93,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,   125,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,   147,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,    92,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,     3,     4,     5,   125,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,    -1,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,   145,    -1,   147,
      -1,    30,    31,    32,    33,    34,    35,    36,    -1,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    90,    -1,    92,    93,    -1,    -1,    -1,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,     3,     4,     5,     6,     7,    -1,
      -1,    -1,    11,    12,    -1,    -1,   125,    16,    -1,    18,
      19,    20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,   147,    -1,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    55,    56,    57,    -1,
      59,    60,    -1,    62,    63,    64,    -1,    66,    67,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,
      89,    90,    -1,    92,    93,    -1,    95,    -1,    97,    98,
      99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,    -1,
       3,     4,     5,     6,     7,    -1,   125,    -1,    11,    12,
      -1,    -1,    -1,    16,    -1,    18,    19,    20,    21,    22,
      23,    24,    -1,    -1,    -1,    -1,   145,    30,    31,    32,
      33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,
      -1,    -1,    45,    46,    -1,    48,    49,    50,    51,    52,
      53,    54,    55,    56,    57,    -1,    59,    60,    -1,    62,
      63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,    92,
      93,    -1,    95,    -1,    97,    98,    99,   100,   101,   102,
     103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,   112,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   125,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   145,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    37,    38,    39,
      -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    -1,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,     3,     4,
       5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,
      -1,    16,   142,    18,    19,    20,    21,    22,    23,    24,
      -1,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,
      -1,    46,    -1,    -1,    49,    50,    51,    52,    53,    54,
      55,    56,    57,    58,    59,    60,    -1,    62,    63,    64,
      -1,    66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    86,    -1,    -1,    89,    90,    -1,    92,    93,    -1,
      95,    96,    97,    98,    99,   100,   101,   102,   103,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     125,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,   137,    11,    12,    -1,    -1,   142,    16,    -1,
      18,    19,    20,    21,    22,    23,    24,    -1,    26,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      58,    59,    60,    -1,    62,    63,    64,    -1,    66,    67,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,    92,    93,    -1,    95,    96,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   111,   112,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   125,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,   137,
      11,    12,    -1,    -1,   142,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    87,    -1,    89,    90,
      -1,    92,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,    -1,   114,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,   125,    11,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,   142,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    58,    59,    60,    -1,    62,    63,    64,    -1,
      66,    67,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    -1,    92,    93,    -1,    95,
      96,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   111,   112,    -1,    -1,    -1,
      -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,   125,
      11,    12,    -1,    -1,    -1,    16,    -1,    18,    19,    20,
      21,    22,    23,    24,    -1,    -1,   142,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    -1,    -1,    39,    -1,
      -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    58,    59,    60,
      -1,    62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,
      -1,    92,    93,    -1,    95,    96,    97,    98,    99,   100,
     101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     111,   112,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,   125,    11,    12,    -1,    -1,    -1,
      16,    -1,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,   142,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      86,    -1,    -1,    89,    90,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,   125,
      -1,    -1,    16,    -1,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,   141,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    92,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,   125,    -1,    -1,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,   141,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    47,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,     6,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    45,    46,    -1,    48,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    96,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    58,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    66,    67,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   111,
     112,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,   125,    16,    -1,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    95,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,   125,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    92,    93,
      -1,    95,    -1,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,     4,     5,
      -1,     7,    -1,    -1,    -1,    11,    12,    -1,    -1,    -1,
      16,   125,    18,    19,    20,    21,    22,    23,    24,    -1,
      -1,    -1,    -1,    -1,    30,    31,    32,    33,    34,    35,
      36,    -1,    -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,
      46,    -1,    -1,    49,    50,    51,    52,    53,    54,    55,
      56,    57,    -1,    59,    60,    -1,    62,    63,    64,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    83,    -1,    -1,
      86,    -1,    -1,    89,    90,    -1,    92,    93,    -1,    -1,
      -1,    97,    98,    99,   100,   101,   102,   103,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,     3,     4,     5,    -1,     7,
      -1,    -1,    -1,    11,    12,    -1,    -1,    -1,    16,   125,
      18,    19,    20,    21,    22,    23,    24,    -1,    -1,    -1,
      -1,    -1,    30,    31,    32,    33,    34,    35,    36,    -1,
      -1,    39,    -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,
      -1,    49,    50,    51,    52,    53,    54,    55,    56,    57,
      -1,    59,    60,    -1,    62,    63,    64,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,
      -1,    89,    90,    -1,    92,    93,    -1,    -1,    -1,    97,
      98,    99,   100,   101,   102,   103,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,     3,     4,     5,    -1,     7,    -1,    -1,
      -1,    11,    12,    -1,    -1,    -1,    16,   125,    18,    19,
      20,    21,    22,    23,    24,    -1,    -1,    -1,    -1,    -1,
      30,    31,    32,    33,    34,    35,    36,    -1,    -1,    39,
      -1,    -1,    -1,    -1,    -1,    -1,    46,    -1,    -1,    49,
      50,    51,    52,    53,    54,    55,    56,    57,    -1,    59,
      60,    -1,    62,    63,    64,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    86,    -1,    -1,    89,
      90,    -1,    92,    93,    -1,    -1,    -1,    97,    98,    99,
     100,   101,   102,   103,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,     3,     4,     5,    -1,     7,    -1,    -1,    -1,    11,
      12,    -1,    -1,    -1,    16,   125,    18,    19,    20,    21,
      22,    23,    24,    -1,    -1,    -1,    -1,    -1,    30,    31,
      32,    33,    34,    35,    36,    -1,    -1,    39,    -1,    -1,
      -1,    -1,    -1,    -1,    46,    -1,    -1,    49,    50,    51,
      52,    53,    54,    55,    56,    57,    -1,    59,    60,    -1,
      62,    63,    64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    86,    -1,    -1,    89,    90,    -1,
      92,    93,    -1,    -1,    -1,    97,    98,    99,   100,   101,
     102,   103,    -1,    -1,    -1,    -1,    -1,    -1,    -1,     3,
       4,     5,    -1,     7,    -1,    -1,    -1,    11,    12,    -1,
      -1,    -1,    16,   125,    18,    19,    20,    21,    22,    23,
      24,    -1,    -1,    -1,    -1,    -1,    30,    31,    32,    33,
      34,    35,    36,    -1,    -1,    39,    -1,    -1,    -1,    -1,
      -1,    -1,    46,    -1,    -1,    49,    50,    51,    52,    53,
      54,    55,    56,    57,    -1,    59,    60,    -1,    62,    63,
      64,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    86,    -1,    -1,    89,    90,    -1,    92,    93,
      -1,    -1,    -1,    97,    98,    99,   100,   101,   102,   103,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   125,     3,     4,     5,     6,     7,     8,     9,    10,
      11,    12,    13,    14,    15,    16,    17,    18,    19,    20,
      21,    22,    23,    24,    25,    26,    -1,    -1,    -1,    30,
      31,    32,    33,    34,    35,    36,    37,    38,    39,    -1,
      -1,    -1,    -1,    -1,    45,    46,    47,    48,    49,    50,
      51,    52,    53,    54,    55,    56,    57,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,     3,     4,     5,     6,     7,     8,
       9,    10,    11,    12,    13,    14,    15,    16,    17,    18,
      19,    20,    21,    22,    23,    24,    25,    26,    -1,    -1,
      -1,    30,    31,    32,    33,    34,    35,    36,    37,    38,
      39,    -1,    -1,    -1,    -1,    -1,    45,    46,    47,    48,
      49,    50,    51,    52,    53,    54,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    98,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,     3,     4,     5,     6,
       7,     8,     9,    10,    11,    12,    13,    14,    15,    16,
      17,    18,    19,    20,    21,    22,    23,    24,    25,    26,
      -1,    -1,    -1,    30,    31,    32,    33,    34,    35,    36,
      37,    38,    39,    -1,    -1,    -1,    -1,    -1,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    98,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,     3,     4,
       5,     6,     7,     8,     9,    10,    11,    12,    13,    14,
      15,    16,    17,    18,    19,    20,    21,    22,    23,    24,
      25,    26,    -1,    -1,    -1,    30,    31,    32,    33,    34,
      35,    36,    37,    38,    39,    -1,    -1,    -1,    -1,    -1,
      45,    46,    47,    48,    49,    50,    51,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124,    -1,    -1,    -1,    -1,    52,    53,
      -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   142,    66,    67,    68,    69,    70,    71,    72,    73,
      74,    -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,
      84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,
      -1,    -1,    -1,   117,   118,   119,   120,   121,   122,   123,
     124,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    56,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    66,
      67,    68,    69,    70,    71,    72,    73,    74,    -1,    -1,
      77,    78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,
     117,   118,   119,   120,   121,   122,   123,   124,    -1,    -1,
      -1,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   142,    66,    67,    68,    69,
      70,    71,    72,    73,    74,    -1,    -1,    77,    78,    -1,
      -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,
     110,   111,   112,    -1,    -1,    -1,    -1,   117,   118,   119,
     120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,    52,
      53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   142,    66,    67,    68,    69,    70,    71,    72,
      73,    74,    -1,    -1,    77,    78,    -1,    -1,    81,    82,
      83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,   112,
      -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,   122,
     123,   124,    -1,    -1,    -1,    -1,    52,    53,    -1,    -1,
      56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,
      66,    67,    68,    69,    70,    71,    72,    73,    74,    -1,
      -1,    77,    78,    -1,    -1,    81,    82,    83,    84,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,   108,   109,   110,   111,   112,    -1,    -1,    -1,
      -1,   117,   118,   119,   120,   121,   122,   123,   124,    -1,
      -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   142,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    -1,    -1,    77,    78,
      -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,
     109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,   118,
     119,   120,   121,   122,   123,   124,    -1,    -1,    -1,    -1,
      52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   142,    66,    67,    68,    69,    70,    71,
      72,    73,    74,    -1,    -1,    77,    78,    -1,    -1,    81,
      82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,   111,
     112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,   121,
     122,   123,   124,    -1,    -1,    -1,    -1,    52,    53,    -1,
      -1,    56,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     142,    66,    67,    68,    69,    70,    71,    72,    73,    74,
      -1,    -1,    77,    78,    -1,    -1,    81,    82,    83,    84,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      95,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,   108,   109,   110,   111,   112,    -1,    -1,
      -1,    -1,   117,   118,   119,   120,   121,   122,   123,   124,
      -1,    -1,    -1,    -1,    52,    53,    -1,    -1,    56,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   142,    66,    67,
      68,    69,    70,    71,    72,    73,    74,    -1,    -1,    77,
      78,    -1,    -1,    81,    82,    83,    84,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    95,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,    -1,
     108,   109,   110,   111,   112,    -1,    -1,    -1,    -1,   117,
     118,   119,   120,   121,   122,   123,   124,    -1,    -1,    -1,
      -1,    52,    53,    -1,    -1,    56,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,   142,    66,    67,    68,    69,    70,
      71,    72,    73,    74,    -1,    -1,    77,    78,    -1,    -1,
      81,    82,    83,    84,    -1,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    95,    -1,    -1,    -1,    -1,    -1,
      -1,    -1,    -1,    -1,    -1,    -1,    -1,   108,   109,   110,
     111,   112,    -1,    -1,    -1,    -1,   117,   118,   119,   120,
     121,   122,   123,   124
};

/* YYSTOS[STATE-NUM] -- The (internal number of the) accessing
   symbol of state STATE-NUM.  */
static const yytype_uint16 yystos[] =
{
       0,   149,   150,     0,     1,     3,     4,     5,     6,     7,
      11,    12,    16,    18,    19,    20,    21,    22,    23,    24,
      30,    31,    32,    33,    34,    35,    36,    39,    45,    46,
      47,    48,    49,    50,    51,    52,    53,    54,    55,    56,
      57,    59,    60,    62,    63,    64,    66,    67,    86,    89,
      90,    92,    93,    95,    97,    98,    99,   100,   101,   102,
     103,   111,   112,   125,   151,   152,   153,   158,   160,   161,
     163,   164,   167,   168,   170,   171,   172,   174,   175,   185,
     199,   215,   216,   217,   218,   219,   220,   221,   222,   223,
     224,   225,   248,   249,   259,   260,   261,   262,   263,   264,
     265,   268,   278,   280,   281,   282,   283,   284,   285,   286,
     309,   320,   153,     3,     4,     5,     6,     7,     8,     9,
      10,    11,    12,    13,    14,    15,    16,    17,    18,    19,
      20,    21,    22,    23,    24,    25,    26,    30,    31,    32,
      33,    34,    35,    36,    37,    38,    39,    45,    46,    47,
      48,    49,    50,    51,    52,    53,    56,    66,    67,    68,
      69,    70,    71,    72,    73,    74,    77,    78,    81,    82,
      83,    84,    95,   108,   109,   110,   111,   112,   117,   118,
     119,   120,   121,   122,   123,   124,   178,   179,   180,   181,
     183,   184,   278,   280,    39,    58,    86,    89,    95,    96,
     111,   167,   175,   185,   187,   192,   195,   197,   215,   282,
     283,   285,   286,   307,   308,   192,   192,   142,   193,   194,
     142,   189,   193,   142,   147,   314,    54,   180,   314,   154,
     137,    21,    22,    30,    31,    32,   185,   215,   309,   185,
      56,     1,    89,   156,   157,   158,   169,   170,   320,   161,
     188,   197,   307,   320,   187,   306,   307,   320,    46,    86,
     125,   141,   174,   199,   215,   282,   283,   286,   241,   242,
      54,    55,    57,   178,   271,   279,   270,   271,   272,   146,
     266,   146,   269,   163,   185,   185,    59,    60,   145,   147,
     313,   318,   319,    40,    41,    42,    43,    44,    37,    38,
      28,   246,   114,   141,    89,    95,   171,   114,    68,    69,
      70,    71,    72,    73,    74,    75,    76,    77,    78,    79,
      80,    83,    84,   109,   110,   115,   117,   118,   119,   120,
     121,   122,   123,   124,    85,   139,   140,   161,   162,   162,
     202,   204,   162,   313,   319,    86,   168,   175,   215,   231,
     282,   283,   286,    52,    56,    83,    86,   176,   177,   215,
     282,   283,   286,   177,    33,    34,    35,    36,    49,    50,
      51,    52,    56,   142,   178,   284,   304,    85,   140,    26,
     137,   250,   262,    87,    87,   189,   193,   250,   141,   187,
      56,   187,   187,   114,    88,   141,   196,   320,    85,   139,
     140,    87,    87,   141,   196,   192,   314,   315,   192,   191,
     192,   197,   307,   320,   161,   315,   161,    54,    63,    64,
     159,   142,   186,   137,   156,    85,   140,    87,   158,   169,
     143,   313,   319,   315,   200,   144,   141,   147,   317,   141,
     317,   138,   317,   314,    56,    59,    60,   171,   173,   141,
      85,   139,   140,   243,    61,   104,   105,   106,   273,   106,
     273,   106,    65,   273,   106,   106,   267,   273,   106,    61,
     106,    68,    68,   145,   153,   162,   162,   162,   162,   158,
     161,   161,   247,    95,   163,   187,   197,   198,   169,   141,
     174,   141,   160,   163,   175,   185,   187,   198,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,   185,   185,   185,   185,   185,   185,
     185,   185,   185,   185,    52,    53,    56,   183,   189,   310,
     311,   191,    52,    53,    56,   183,   189,   310,    13,   227,
     318,   227,   162,   162,   313,    17,   253,    56,    85,   139,
     140,    25,   161,    52,    56,   176,     1,   110,   287,   318,
      85,   139,   140,   211,   305,   212,    85,   140,   312,    52,
      56,   310,   310,   252,   251,   163,   185,   163,   185,    94,
     165,   182,   185,   187,    95,   187,   195,   307,    52,    56,
     191,    52,    56,   308,   315,   143,   315,   141,   141,   315,
     180,   201,   185,   151,   138,   310,   310,   185,   315,   158,
     315,   307,   141,   173,    52,    56,   191,    52,    56,    52,
      54,    55,    56,    57,    89,    95,    96,   119,   122,   142,
     244,   290,   291,   292,   293,   294,   295,   298,   299,   300,
     301,   302,   275,   274,   146,   273,   146,   185,   185,    76,
     117,   236,   237,   320,   187,   141,   315,   173,   141,   114,
      44,   314,    87,    87,   189,   193,   314,   316,    87,    87,
     189,   190,   193,   320,   156,    13,   156,    27,   228,   318,
     228,   253,   197,    10,   226,    52,    56,   191,    52,    56,
     206,   209,   318,   288,   208,    52,    56,   176,   191,   155,
     156,   161,   142,   289,   290,   213,   190,   193,   190,   193,
     236,   236,    44,   166,   180,   187,   196,    87,    87,   316,
      87,    87,   307,   161,   138,   317,   171,   316,   114,    52,
      89,    95,   232,   233,   234,   292,   290,    29,   107,   245,
     141,   303,   320,   141,   303,    52,   141,   303,    52,   276,
      54,    55,    57,   277,   286,    52,   145,   235,   238,   294,
     296,   297,   300,   302,   320,   156,    95,   187,   173,   185,
     116,   163,   185,   163,   185,   165,   144,    87,   163,   185,
     163,   185,   165,    14,    15,   229,   230,   320,   230,   203,
     205,   226,   141,   227,   316,   162,   318,   162,   155,   316,
     226,     8,   255,   320,   315,   290,   155,   318,   178,   156,
     156,   185,   236,    87,   141,   315,   187,   234,   141,   292,
     141,   315,   238,   156,   156,   293,   298,   300,   302,   294,
     295,   300,   294,   156,   114,    52,   239,   240,   291,   238,
     117,   141,   303,   141,   303,   141,   303,    10,   187,   185,
     163,   185,   162,   156,   226,   226,   156,   156,   187,   156,
     228,   210,   318,   226,   187,   198,   256,   320,   230,   315,
     226,   214,    10,   138,   156,   315,   233,   141,    95,   232,
     315,    10,   138,   141,   303,   141,   303,   141,   303,   141,
     303,   303,   138,    86,   215,   141,   117,   297,   300,   294,
     296,   300,   294,   227,   226,   226,   230,   253,   254,   207,
     155,    88,   257,   320,     9,   258,   320,   289,   138,   141,
     233,   141,   292,   294,   300,   294,   294,    56,    85,   240,
     141,   303,   141,   303,   303,   141,   303,   303,   156,   156,
     226,    86,   175,   215,   282,   283,   286,   227,   156,   155,
     233,   141,   303,   141,   303,   303,   303,    52,    56,   294,
     300,   294,   294,   229,   226,    56,    85,   139,   140,   156,
     226,   233,   294,   303,   141,   303,   303,   303,    52,    56,
     191,    52,    56,   255,   303,   294,   316,   303
};

#define yyerrok		(yyerrstatus = 0)
#define yyclearin	(yychar = YYEMPTY)
#define YYEMPTY		(-2)
#define YYEOF		0

#define YYACCEPT	goto yyacceptlab
#define YYABORT		goto yyabortlab
#define YYERROR		goto yyerrorlab


/* Like YYERROR except do call yyerror.  This remains here temporarily
   to ease the transition to the new meaning of YYERROR, for GCC.
   Once GCC version 2 has supplanted version 1, this can go.  */

#define YYFAIL		goto yyerrlab

#define YYRECOVERING()  (!!yyerrstatus)

#define YYBACKUP(Token, Value)					\
do								\
  if (yychar == YYEMPTY && yylen == 1)				\
    {								\
      yychar = (Token);						\
      yylval = (Value);						\
      yytoken = YYTRANSLATE (yychar);				\
      YYPOPSTACK (1);						\
      goto yybackup;						\
    }								\
  else								\
    {								\
      parser_yyerror (parser, YY_("syntax error: cannot back up")); \
      YYERROR;							\
    }								\
while (YYID (0))


#define YYTERROR	1
#define YYERRCODE	256


/* YYLLOC_DEFAULT -- Set CURRENT to span from RHS[1] to RHS[N].
   If N is 0, then set CURRENT to the empty location which ends
   the previous symbol: RHS[0] (always defined).  */

#define YYRHSLOC(Rhs, K) ((Rhs)[K])
#ifndef YYLLOC_DEFAULT
# define YYLLOC_DEFAULT(Current, Rhs, N)				\
    do									\
      if (YYID (N))                                                    \
	{								\
	  (Current).first_line   = YYRHSLOC (Rhs, 1).first_line;	\
	  (Current).first_column = YYRHSLOC (Rhs, 1).first_column;	\
	  (Current).last_line    = YYRHSLOC (Rhs, N).last_line;		\
	  (Current).last_column  = YYRHSLOC (Rhs, N).last_column;	\
	}								\
      else								\
	{								\
	  (Current).first_line   = (Current).last_line   =		\
	    YYRHSLOC (Rhs, 0).last_line;				\
	  (Current).first_column = (Current).last_column =		\
	    YYRHSLOC (Rhs, 0).last_column;				\
	}								\
    while (YYID (0))
#endif


/* YY_LOCATION_PRINT -- Print the location on the stream.
   This macro was not mandated originally: define only if we know
   we won't break user code: when these are the locations we know.  */

#ifndef YY_LOCATION_PRINT
# if defined YYLTYPE_IS_TRIVIAL && YYLTYPE_IS_TRIVIAL
#  define YY_LOCATION_PRINT(File, Loc)			\
     fprintf (File, "%d.%d-%d.%d",			\
	      (Loc).first_line, (Loc).first_column,	\
	      (Loc).last_line,  (Loc).last_column)
# else
#  define YY_LOCATION_PRINT(File, Loc) ((void) 0)
# endif
#endif


/* YYLEX -- calling `yylex' with the right arguments.  */

#ifdef YYLEX_PARAM
# define YYLEX yylex (&yylval, YYLEX_PARAM)
#else
# define YYLEX yylex (&yylval)
#endif

/* Enable debugging if requested.  */
#if YYDEBUG

# ifndef YYFPRINTF
#  include <stdio.h> /* INFRINGES ON USER NAME SPACE */
#  define YYFPRINTF fprintf
# endif

# define YYDPRINTF(Args)			\
do {						\
  if (yydebug)					\
    YYFPRINTF Args;				\
} while (YYID (0))

# define YY_SYMBOL_PRINT(Title, Type, Value, Location)			  \
do {									  \
  if (yydebug)								  \
    {									  \
      YYFPRINTF (stderr, "%s ", Title);					  \
      yy_symbol_print (stderr,						  \
		  Type, Value, parser); \
      YYFPRINTF (stderr, "\n");						  \
    }									  \
} while (YYID (0))


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_value_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct parser_params *parser)
#else
static void
yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct parser_params *parser;
#endif
{
  if (!yyvaluep)
    return;
  YYUSE (parser);
# ifdef YYPRINT
  if (yytype < YYNTOKENS)
    YYPRINT (yyoutput, yytoknum[yytype], *yyvaluep);
# else
  YYUSE (yyoutput);
# endif
  switch (yytype)
    {
      default:
	break;
    }
}


/*--------------------------------.
| Print this symbol on YYOUTPUT.  |
`--------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_symbol_print (FILE *yyoutput, int yytype, YYSTYPE const * const yyvaluep, struct parser_params *parser)
#else
static void
yy_symbol_print (yyoutput, yytype, yyvaluep, parser)
    FILE *yyoutput;
    int yytype;
    YYSTYPE const * const yyvaluep;
    struct parser_params *parser;
#endif
{
  if (yytype < YYNTOKENS)
    YYFPRINTF (yyoutput, "token %s (", yytname[yytype]);
  else
    YYFPRINTF (yyoutput, "nterm %s (", yytname[yytype]);

  yy_symbol_value_print (yyoutput, yytype, yyvaluep, parser);
  YYFPRINTF (yyoutput, ")");
}

/*------------------------------------------------------------------.
| yy_stack_print -- Print the state stack from its BOTTOM up to its |
| TOP (included).                                                   |
`------------------------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_stack_print (yytype_int16 *bottom, yytype_int16 *top)
#else
static void
yy_stack_print (bottom, top)
    yytype_int16 *bottom;
    yytype_int16 *top;
#endif
{
  YYFPRINTF (stderr, "Stack now");
  for (; bottom <= top; ++bottom)
    YYFPRINTF (stderr, " %d", *bottom);
  YYFPRINTF (stderr, "\n");
}

# define YY_STACK_PRINT(Bottom, Top)				\
do {								\
  if (yydebug)							\
    yy_stack_print ((Bottom), (Top));				\
} while (YYID (0))


/*------------------------------------------------.
| Report that the YYRULE is going to be reduced.  |
`------------------------------------------------*/

#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yy_reduce_print (YYSTYPE *yyvsp, int yyrule, struct parser_params *parser)
#else
static void
yy_reduce_print (yyvsp, yyrule, parser)
    YYSTYPE *yyvsp;
    int yyrule;
    struct parser_params *parser;
#endif
{
  int yynrhs = yyr2[yyrule];
  int yyi;
  unsigned long int yylno = yyrline[yyrule];
  YYFPRINTF (stderr, "Reducing stack by rule %d (line %lu):\n",
	     yyrule - 1, yylno);
  /* The symbols being reduced.  */
  for (yyi = 0; yyi < yynrhs; yyi++)
    {
      fprintf (stderr, "   $%d = ", yyi + 1);
      yy_symbol_print (stderr, yyrhs[yyprhs[yyrule] + yyi],
		       &(yyvsp[(yyi + 1) - (yynrhs)])
		       		       , parser);
      fprintf (stderr, "\n");
    }
}

# define YY_REDUCE_PRINT(Rule)		\
do {					\
  if (yydebug)				\
    yy_reduce_print (yyvsp, Rule, parser); \
} while (YYID (0))

/* Nonzero means print parse trace.  It is left uninitialized so that
   multiple parsers can coexist.  */
#ifndef yydebug
int yydebug;
#endif
#else /* !YYDEBUG */
# define YYDPRINTF(Args)
# define YY_SYMBOL_PRINT(Title, Type, Value, Location)
# define YY_STACK_PRINT(Bottom, Top)
# define YY_REDUCE_PRINT(Rule)
#endif /* !YYDEBUG */


/* YYINITDEPTH -- initial size of the parser's stacks.  */
#ifndef	YYINITDEPTH
# define YYINITDEPTH 200
#endif

/* YYMAXDEPTH -- maximum size the stacks can grow to (effective only
   if the built-in stack extension method is used).

   Do not make this value too large; the results are undefined if
   YYSTACK_ALLOC_MAXIMUM < YYSTACK_BYTES (YYMAXDEPTH)
   evaluated with infinite-precision integer arithmetic.  */

#ifndef YYMAXDEPTH
# define YYMAXDEPTH 10000
#endif



#if YYERROR_VERBOSE

# ifndef yystrlen
#  if defined __GLIBC__ && defined _STRING_H
#   define yystrlen strlen
#  else
/* Return the length of YYSTR.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static YYSIZE_T
yystrlen (const char *yystr)
#else
static YYSIZE_T
yystrlen (yystr)
    const char *yystr;
#endif
{
  YYSIZE_T yylen;
  for (yylen = 0; yystr[yylen]; yylen++)
    continue;
  return yylen;
}
#  endif
# endif

# ifndef yystpcpy
#  if defined __GLIBC__ && defined _STRING_H && defined _GNU_SOURCE
#   define yystpcpy stpcpy
#  else
/* Copy YYSRC to YYDEST, returning the address of the terminating '\0' in
   YYDEST.  */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static char *
yystpcpy (char *yydest, const char *yysrc)
#else
static char *
yystpcpy (yydest, yysrc)
    char *yydest;
    const char *yysrc;
#endif
{
  char *yyd = yydest;
  const char *yys = yysrc;

  while ((*yyd++ = *yys++) != '\0')
    continue;

  return yyd - 1;
}
#  endif
# endif

# ifndef yytnamerr
/* Copy to YYRES the contents of YYSTR after stripping away unnecessary
   quotes and backslashes, so that it's suitable for yyerror.  The
   heuristic is that double-quoting is unnecessary unless the string
   contains an apostrophe, a comma, or backslash (other than
   backslash-backslash).  YYSTR is taken from yytname.  If YYRES is
   null, do not copy; instead, return the length of what the result
   would have been.  */
static YYSIZE_T
yytnamerr (char *yyres, const char *yystr)
{
  if (*yystr == '"')
    {
      YYSIZE_T yyn = 0;
      char const *yyp = yystr;

      for (;;)
	switch (*++yyp)
	  {
	  case '\'':
	  case ',':
	    goto do_not_strip_quotes;

	  case '\\':
	    if (*++yyp != '\\')
	      goto do_not_strip_quotes;
	    /* Fall through.  */
	  default:
	    if (yyres)
	      yyres[yyn] = *yyp;
	    yyn++;
	    break;

	  case '"':
	    if (yyres)
	      yyres[yyn] = '\0';
	    return yyn;
	  }
    do_not_strip_quotes: ;
    }

  if (! yyres)
    return yystrlen (yystr);

  return yystpcpy (yyres, yystr) - yyres;
}
# endif

/* Copy into YYRESULT an error message about the unexpected token
   YYCHAR while in state YYSTATE.  Return the number of bytes copied,
   including the terminating null byte.  If YYRESULT is null, do not
   copy anything; just return the number of bytes that would be
   copied.  As a special case, return 0 if an ordinary "syntax error"
   message will do.  Return YYSIZE_MAXIMUM if overflow occurs during
   size calculation.  */
static YYSIZE_T
yysyntax_error (char *yyresult, int yystate, int yychar)
{
  int yyn = yypact[yystate];

  if (! (YYPACT_NINF < yyn && yyn <= YYLAST))
    return 0;
  else
    {
      int yytype = YYTRANSLATE (yychar);
      YYSIZE_T yysize0 = yytnamerr (0, yytname[yytype]);
      YYSIZE_T yysize = yysize0;
      YYSIZE_T yysize1;
      int yysize_overflow = 0;
      enum { YYERROR_VERBOSE_ARGS_MAXIMUM = 5 };
      char const *yyarg[YYERROR_VERBOSE_ARGS_MAXIMUM];
      int yyx;

# if 0
      /* This is so xgettext sees the translatable formats that are
	 constructed on the fly.  */
      YY_("syntax error, unexpected %s");
      YY_("syntax error, unexpected %s, expecting %s");
      YY_("syntax error, unexpected %s, expecting %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s");
      YY_("syntax error, unexpected %s, expecting %s or %s or %s or %s");
# endif
      char *yyfmt;
      char const *yyf;
      static char const yyunexpected[] = "syntax error, unexpected %s";
      static char const yyexpecting[] = ", expecting %s";
      static char const yyor[] = " or %s";
      char yyformat[sizeof yyunexpected
		    + sizeof yyexpecting - 1
		    + ((YYERROR_VERBOSE_ARGS_MAXIMUM - 2)
		       * (sizeof yyor - 1))];
      char const *yyprefix = yyexpecting;

      /* Start YYX at -YYN if negative to avoid negative indexes in
	 YYCHECK.  */
      int yyxbegin = yyn < 0 ? -yyn : 0;

      /* Stay within bounds of both yycheck and yytname.  */
      int yychecklim = YYLAST - yyn + 1;
      int yyxend = yychecklim < YYNTOKENS ? yychecklim : YYNTOKENS;
      int yycount = 1;

      yyarg[0] = yytname[yytype];
      yyfmt = yystpcpy (yyformat, yyunexpected);

      for (yyx = yyxbegin; yyx < yyxend; ++yyx)
	if (yycheck[yyx + yyn] == yyx && yyx != YYTERROR)
	  {
	    if (yycount == YYERROR_VERBOSE_ARGS_MAXIMUM)
	      {
		yycount = 1;
		yysize = yysize0;
		yyformat[sizeof yyunexpected - 1] = '\0';
		break;
	      }
	    yyarg[yycount++] = yytname[yyx];
	    yysize1 = yysize + yytnamerr (0, yytname[yyx]);
	    yysize_overflow |= (yysize1 < yysize);
	    yysize = yysize1;
	    yyfmt = yystpcpy (yyfmt, yyprefix);
	    yyprefix = yyor;
	  }

      yyf = YY_(yyformat);
      yysize1 = yysize + yystrlen (yyf);
      yysize_overflow |= (yysize1 < yysize);
      yysize = yysize1;

      if (yysize_overflow)
	return YYSIZE_MAXIMUM;

      if (yyresult)
	{
	  /* Avoid sprintf, as that infringes on the user's name space.
	     Don't have undefined behavior even if the translation
	     produced a string with the wrong number of "%s"s.  */
	  char *yyp = yyresult;
	  int yyi = 0;
	  while ((*yyp = *yyf) != '\0')
	    {
	      if (*yyp == '%' && yyf[1] == 's' && yyi < yycount)
		{
		  yyp += yytnamerr (yyp, yyarg[yyi++]);
		  yyf += 2;
		}
	      else
		{
		  yyp++;
		  yyf++;
		}
	    }
	}
      return yysize;
    }
}
#endif /* YYERROR_VERBOSE */


/*-----------------------------------------------.
| Release the memory associated to this symbol.  |
`-----------------------------------------------*/

/*ARGSUSED*/
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
static void
yydestruct (const char *yymsg, int yytype, YYSTYPE *yyvaluep, struct parser_params *parser)
#else
static void
yydestruct (yymsg, yytype, yyvaluep, parser)
    const char *yymsg;
    int yytype;
    YYSTYPE *yyvaluep;
    struct parser_params *parser;
#endif
{
  YYUSE (yyvaluep);
  YYUSE (parser);

  if (!yymsg)
    yymsg = "Deleting";
  YY_SYMBOL_PRINT (yymsg, yytype, yyvaluep, yylocationp);

  switch (yytype)
    {

      default:
	break;
    }
}


/* Prevent warnings from -Wmissing-prototypes.  */

#ifdef YYPARSE_PARAM
#if defined __STDC__ || defined __cplusplus
int yyparse (void *YYPARSE_PARAM);
#else
int yyparse ();
#endif
#else /* ! YYPARSE_PARAM */
#if defined __STDC__ || defined __cplusplus
int yyparse (struct parser_params *parser);
#else
int yyparse ();
#endif
#endif /* ! YYPARSE_PARAM */






/*----------.
| yyparse.  |
`----------*/

#ifdef YYPARSE_PARAM
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (void *YYPARSE_PARAM)
#else
int
yyparse (YYPARSE_PARAM)
    void *YYPARSE_PARAM;
#endif
#else /* ! YYPARSE_PARAM */
#if (defined __STDC__ || defined __C99__FUNC__ \
     || defined __cplusplus || defined _MSC_VER)
int
yyparse (struct parser_params *parser)
#else
int
yyparse (parser)
    struct parser_params *parser;
#endif
#endif
{
  /* The look-ahead symbol.  */
int yychar;

/* The semantic value of the look-ahead symbol.  */
YYSTYPE yylval;

/* Number of syntax errors so far.  */
int yynerrs;

  int yystate;
  int yyn;
  int yyresult;
  /* Number of tokens to shift before error messages enabled.  */
  int yyerrstatus;
  /* Look-ahead token as an internal (translated) token number.  */
  int yytoken = 0;
#if YYERROR_VERBOSE
  /* Buffer for error messages, and its allocated size.  */
  char yymsgbuf[128];
  char *yymsg = yymsgbuf;
  YYSIZE_T yymsg_alloc = sizeof yymsgbuf;
#endif

  /* Three stacks and their tools:
     `yyss': related to states,
     `yyvs': related to semantic values,
     `yyls': related to locations.

     Refer to the stacks thru separate pointers, to allow yyoverflow
     to reallocate them elsewhere.  */

  /* The state stack.  */
  yytype_int16 yyssa[YYINITDEPTH];
  yytype_int16 *yyss = yyssa;
  yytype_int16 *yyssp;

  /* The semantic value stack.  */
  YYSTYPE yyvsa[YYINITDEPTH];
  YYSTYPE *yyvs = yyvsa;
  YYSTYPE *yyvsp;



#define YYPOPSTACK(N)   (yyvsp -= (N), yyssp -= (N))

  YYSIZE_T yystacksize = YYINITDEPTH;

  /* The variables used to return semantic value and location from the
     action routines.  */
  YYSTYPE yyval;


  /* The number of symbols on the RHS of the reduced rule.
     Keep to zero when no symbol should be popped.  */
  int yylen = 0;

  YYDPRINTF ((stderr, "Starting parse\n"));

  yystate = 0;
  yyerrstatus = 0;
  yynerrs = 0;
  yychar = YYEMPTY;		/* Cause a token to be read.  */

  /* Initialize stack pointers.
     Waste one element of value and location stack
     so that they stay on the same level as the state stack.
     The wasted elements are never initialized.  */

  yyssp = yyss;
  yyvsp = yyvs;

  goto yysetstate;

/*------------------------------------------------------------.
| yynewstate -- Push a new state, which is found in yystate.  |
`------------------------------------------------------------*/
 yynewstate:
  /* In all cases, when you get here, the value and location stacks
     have just been pushed.  So pushing a state here evens the stacks.  */
  yyssp++;

 yysetstate:
  *yyssp = yystate;

  if (yyss + yystacksize - 1 <= yyssp)
    {
      /* Get the current used size of the three stacks, in elements.  */
      YYSIZE_T yysize = yyssp - yyss + 1;

#ifdef yyoverflow
      {
	/* Give user a chance to reallocate the stack.  Use copies of
	   these so that the &'s don't force the real ones into
	   memory.  */
	YYSTYPE *yyvs1 = yyvs;
	yytype_int16 *yyss1 = yyss;


	/* Each stack pointer address is followed by the size of the
	   data in use in that stack, in bytes.  This used to be a
	   conditional around just the two extra args, but that might
	   be undefined if yyoverflow is a macro.  */
	yyoverflow (YY_("memory exhausted"),
		    &yyss1, yysize * sizeof (*yyssp),
		    &yyvs1, yysize * sizeof (*yyvsp),

		    &yystacksize);

	yyss = yyss1;
	yyvs = yyvs1;
      }
#else /* no yyoverflow */
# ifndef YYSTACK_RELOCATE
      goto yyexhaustedlab;
# else
      /* Extend the stack our own way.  */
      if (YYMAXDEPTH <= yystacksize)
	goto yyexhaustedlab;
      yystacksize *= 2;
      if (YYMAXDEPTH < yystacksize)
	yystacksize = YYMAXDEPTH;

      {
	yytype_int16 *yyss1 = yyss;
	union yyalloc *yyptr =
	  (union yyalloc *) YYSTACK_ALLOC (YYSTACK_BYTES (yystacksize));
	if (! yyptr)
	  goto yyexhaustedlab;
	YYSTACK_RELOCATE (yyss);
	YYSTACK_RELOCATE (yyvs);

#  undef YYSTACK_RELOCATE
	if (yyss1 != yyssa)
	  YYSTACK_FREE (yyss1);
      }
# endif
#endif /* no yyoverflow */

      yyssp = yyss + yysize - 1;
      yyvsp = yyvs + yysize - 1;


      YYDPRINTF ((stderr, "Stack size increased to %lu\n",
		  (unsigned long int) yystacksize));

      if (yyss + yystacksize - 1 <= yyssp)
	YYABORT;
    }

  YYDPRINTF ((stderr, "Entering state %d\n", yystate));

  goto yybackup;

/*-----------.
| yybackup.  |
`-----------*/
yybackup:

  /* Do appropriate processing given the current state.  Read a
     look-ahead token if we need one and don't already have one.  */

  /* First try to decide what to do without reference to look-ahead token.  */
  yyn = yypact[yystate];
  if (yyn == YYPACT_NINF)
    goto yydefault;

  /* Not known => get a look-ahead token if don't already have one.  */

  /* YYCHAR is either YYEMPTY or YYEOF or a valid look-ahead symbol.  */
  if (yychar == YYEMPTY)
    {
      YYDPRINTF ((stderr, "Reading a token: "));
      yychar = YYLEX;
    }

  if (yychar <= YYEOF)
    {
      yychar = yytoken = YYEOF;
      YYDPRINTF ((stderr, "Now at end of input.\n"));
    }
  else
    {
      yytoken = YYTRANSLATE (yychar);
      YY_SYMBOL_PRINT ("Next token is", yytoken, &yylval, &yylloc);
    }

  /* If the proper action on seeing token YYTOKEN is to reduce or to
     detect an error, take that action.  */
  yyn += yytoken;
  if (yyn < 0 || YYLAST < yyn || yycheck[yyn] != yytoken)
    goto yydefault;
  yyn = yytable[yyn];
  if (yyn <= 0)
    {
      if (yyn == 0 || yyn == YYTABLE_NINF)
	goto yyerrlab;
      yyn = -yyn;
      goto yyreduce;
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  /* Count tokens shifted since error; after three, turn off error
     status.  */
  if (yyerrstatus)
    yyerrstatus--;

  /* Shift the look-ahead token.  */
redtree_stack_push(parser, yytoken);
  YY_SYMBOL_PRINT ("Shifting", yytoken, &yylval, &yylloc);

  /* Discard the shifted token unless it is eof.  */
  if (yychar != YYEOF)
    yychar = YYEMPTY;

  yystate = yyn;
  *++yyvsp = yylval;

  goto yynewstate;


/*-----------------------------------------------------------.
| yydefault -- do the default action for the current state.  |
`-----------------------------------------------------------*/
yydefault:
  yyn = yydefact[yystate];
  if (yyn == 0)
    goto yyerrlab;
  goto yyreduce;


/*-----------------------------.
| yyreduce -- Do a reduction.  |
`-----------------------------*/
yyreduce:
  /* yyn is the number of a rule to reduce with.  */
  yylen = yyr2[yyn];

  /* If YYLEN is nonzero, implement the default value of the action:
     `$$ = $1'.

     Otherwise, the following line sets YYVAL to garbage.
     This behavior is undocumented and Bison
     users should not rely upon it.  Assigning to YYVAL
     unconditionally makes the parser a bit smaller, and it avoids a
     GCC warning that YYVAL may be used uninitialized.  */
  yyval = yyvsp[1-yylen];


  YY_REDUCE_PRINT (yyn);
  switch (yyn)
    {
        case 2:
#line 736 "redtree.y"
    {
          lex_state = EXPR_BEG;
          local_push(0);
        ;}
    break;

  case 3:
#line 741 "redtree.y"
    {
          reduce_rule(program__top_compstmt, 1);
          local_pop();
        ;}
    break;

  case 4:
#line 748 "redtree.y"
    {

          reduce_rule(top_compstmt__top_stmts__opt_terms, 2);
        ;}
    break;

  case 5:
#line 755 "redtree.y"
    {
          reduce_rule(top_stmts__none, 1);
        ;}
    break;

  case 6:
#line 759 "redtree.y"
    {
          reduce_rule(top_stmts__top_stmt, 1);
        ;}
    break;

  case 7:
#line 763 "redtree.y"
    {
          reduce_rule(top_stmts__top_stmts__terms__top_stmt, 3);
        ;}
    break;

  case 8:
#line 767 "redtree.y"
    {
          reduce_rule(top_stmts__error__top_stmt, 2);
        ;}
    break;

  case 9:
#line 773 "redtree.y"
    {
          reduce_rule(top_stmt__stmt, 1);
        ;}
    break;

  case 10:
#line 777 "redtree.y"
    {
          if (in_def || in_single) {
            yyerror("BEGIN in method");
          }
        ;}
    break;

  case 11:
#line 783 "redtree.y"
    {
          reduce_rule(top_stmt__keyword_BEGIN__LC__top_compstmt__RC, 4);
        ;}
    break;

  case 12:
#line 792 "redtree.y"
    {
          reduce_rule(bodystmt__compstmt__opt_rescue__opt_else__opt_ensure, 4);
        ;}
    break;

  case 13:
#line 798 "redtree.y"
    {
          reduce_rule(compstmt__stmts__opt_terms, 2);
        ;}
    break;

  case 14:
#line 804 "redtree.y"
    {
          reduce_rule(stmts__none, 1);
        ;}
    break;

  case 15:
#line 808 "redtree.y"
    {
          reduce_rule(stmts__stmt, 1);
        ;}
    break;

  case 16:
#line 812 "redtree.y"
    {
          reduce_rule(stmts__stmts__terms__stmt, 3);
        ;}
    break;

  case 17:
#line 816 "redtree.y"
    {
          reduce_rule(stmts__error__stmt, 2);
        ;}
    break;

  case 18:
#line 821 "redtree.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 19:
#line 822 "redtree.y"
    {
          reduce_rule(stmt__keyword_alias__fitem__fitem, 3);
        ;}
    break;

  case 20:
#line 826 "redtree.y"
    {
          reduce_rule(stmt__keyword_alias__tGVAR__tGVAR, 3);
        ;}
    break;

  case 21:
#line 830 "redtree.y"
    {
          reduce_rule(stmt__keyword_alias__tGVAR__tBACK_REF, 3);
        ;}
    break;

  case 22:
#line 834 "redtree.y"
    {
          reduce_rule(stmt__keyword_alias__tGVAR__tNTH_REF, 3);
        ;}
    break;

  case 23:
#line 838 "redtree.y"
    {
          reduce_rule(stmt__keyword_undef__undef_list, 2);
        ;}
    break;

  case 24:
#line 842 "redtree.y"
    {
          reduce_rule(stmt__stmt__modifier_if__expr_value, 3);
        ;}
    break;

  case 25:
#line 846 "redtree.y"
    {
          reduce_rule(stmt__stmt__modifier_unless__expr_value, 3);
        ;}
    break;

  case 26:
#line 850 "redtree.y"
    {
          reduce_rule(stmt__stmt__modifier_while__expr_value, 3);
        ;}
    break;

  case 27:
#line 854 "redtree.y"
    {
          reduce_rule(stmt__stmt__modifier_until__expr_value, 3);
        ;}
    break;

  case 28:
#line 858 "redtree.y"
    {
          reduce_rule(stmt__stmt__modifier_rescue__stmt, 3);
        ;}
    break;

  case 29:
#line 862 "redtree.y"
    {
          if (in_def || in_single) {
          rb_warn0("END in method; use at_exit");
          }
          reduce_rule(stmt__keyword_END__LC__compstmt__RC, 4);
        ;}
    break;

  case 30:
#line 869 "redtree.y"
    {
            reduce_rule(stmt__command_asgn, 1);
        ;}
    break;

  case 31:
#line 873 "redtree.y"
    {
          reduce_rule(stmt__mlhs__EQ__command_call, 3);
        ;}
    break;

  case 32:
#line 877 "redtree.y"
    {
          reduce_rule(stmt__var_lhs__tOP_ASGN__command_call, 3);
        ;}
    break;

  case 33:
#line 881 "redtree.y"
    {
          reduce_rule(stmt__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__command_call, 6);
        ;}
    break;

  case 34:
#line 885 "redtree.y"
    {
          reduce_rule(stmt__primary_value__DOT__tIDENTIFIER__tOP_ASGN__command_call, 5);
        ;}
    break;

  case 35:
#line 889 "redtree.y"
    {
          reduce_rule(stmt__primary_value__DOT__tCONSTANT__tOP_ASGN__command_call, 5);
        ;}
    break;

  case 36:
#line 893 "redtree.y"
    {
          reduce_rule(stmt__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__command_call, 5);
        ;}
    break;

  case 37:
#line 897 "redtree.y"
    {
          reduce_rule(stmt__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__command_call, 5);
        ;}
    break;

  case 38:
#line 901 "redtree.y"
    {
          reduce_rule(stmt__backref__tOP_ASGN__command_call, 3);
        ;}
    break;

  case 39:
#line 905 "redtree.y"
    {
          reduce_rule(stmt__lhs__EQ__mrhs, 3);
        ;}
    break;

  case 40:
#line 909 "redtree.y"
    {
          reduce_rule(stmt__mlhs__EQ__arg_value, 3);
        ;}
    break;

  case 41:
#line 913 "redtree.y"
    {
          reduce_rule(stmt__mlhs__EQ__mrhs, 3);
        ;}
    break;

  case 42:
#line 917 "redtree.y"
    {
            reduce_rule(stmt__expr, 1);
        ;}
    break;

  case 43:
#line 923 "redtree.y"
    {
          reduce_rule(command_asgn__lhs__EQ__command_call, 3);
        ;}
    break;

  case 44:
#line 927 "redtree.y"
    {
          reduce_rule(command_asgn__lhs__EQ__command_asgn, 3);
        ;}
    break;

  case 45:
#line 934 "redtree.y"
    {
          reduce_rule(expr__command_call, 1);
        ;}
    break;

  case 46:
#line 938 "redtree.y"
    {
          reduce_rule(expr__expr__keyword_and__expr, 3);
        ;}
    break;

  case 47:
#line 942 "redtree.y"
    {
          reduce_rule(expr__expr__keyword_or__expr, 3);
        ;}
    break;

  case 48:
#line 946 "redtree.y"
    {
          reduce_rule(expr__keyword_not__opt_nl__expr, 3);
        ;}
    break;

  case 49:
#line 950 "redtree.y"
    {
          reduce_rule(expr__BANG__command_call, 2);
        ;}
    break;

  case 50:
#line 954 "redtree.y"
    {
          reduce_rule(expr__arg, 1);
        ;}
    break;

  case 51:
#line 960 "redtree.y"
    {
          reduce_rule(expr_value__expr, 1);
        ;}
    break;

  case 52:
#line 966 "redtree.y"
    {
          reduce_rule(command_call__command, 1);
        ;}
    break;

  case 53:
#line 970 "redtree.y"
    {
          reduce_rule(command_call__block_command, 1);
        ;}
    break;

  case 54:
#line 976 "redtree.y"
    {
          reduce_rule(block_command__block_call, 1);
        ;}
    break;

  case 55:
#line 980 "redtree.y"
    {
          reduce_rule(block_command__block_call__DOT__operation2__command_args, 4);
        ;}
    break;

  case 56:
#line 984 "redtree.y"
    {
          reduce_rule(block_command__block_call__tCOLON2__operation2__command_args, 4);
        ;}
    break;

  case 57:
#line 990 "redtree.y"
    {
          (yyvsp[(1) - (1)].vars) = dyna_push();
        ;}
    break;

  case 58:
#line 994 "redtree.y"
    {
          reduce_rule(cmd_brace_block__tLBRACE_ARG__opt_block_param__compstmt__RC, 4);

          dyna_pop((yyvsp[(1) - (5)].vars));
        ;}
    break;

  case 59:
#line 1002 "redtree.y"
    {
          reduce_rule(command__operation__command_args, 2);
        ;}
    break;

  case 60:
#line 1006 "redtree.y"
    {
          reduce_rule(command__operation__command_args__cmd_brace_block, 3);
        ;}
    break;

  case 61:
#line 1010 "redtree.y"
    {
          reduce_rule(command__primary_value__DOT__operation2__command_args, 4);
        ;}
    break;

  case 62:
#line 1014 "redtree.y"
    {
          reduce_rule(command__primary_value__DOT__operation2__command_args__cmd_brace_block, 5);
       ;}
    break;

  case 63:
#line 1018 "redtree.y"
    {
          reduce_rule(command__primary_value__tCOLON2__operation2__command_args, 4);
        ;}
    break;

  case 64:
#line 1022 "redtree.y"
    {
          reduce_rule(command__primary_value__tCOLON2__operation2__command_args__cmd_brace_block, 5);
       ;}
    break;

  case 65:
#line 1026 "redtree.y"
    {
          reduce_rule(command__keyword_super__command_args, 2);
        ;}
    break;

  case 66:
#line 1030 "redtree.y"
    {
          reduce_rule(command__keyword_yield__command_args, 2);
        ;}
    break;

  case 67:
#line 1034 "redtree.y"
    {
          reduce_rule(command__keyword_return__call_args, 2);
        ;}
    break;

  case 68:
#line 1038 "redtree.y"
    {
          reduce_rule(command__keyword_break__call_args, 2);
        ;}
    break;

  case 69:
#line 1042 "redtree.y"
    {
          reduce_rule(command__keyword_next__call_args, 2);
        ;}
    break;

  case 70:
#line 1048 "redtree.y"
    {
          reduce_rule(mlhs__mlhs_basic, 1);
        ;}
    break;

  case 71:
#line 1052 "redtree.y"
    {
          reduce_rule(mlhs__tLPAREN__mlhs_inner__rparen, 3);
        ;}
    break;

  case 72:
#line 1058 "redtree.y"
    {
          reduce_rule(mlhs_inner__mlhs_basic, 1);
        ;}
    break;

  case 73:
#line 1062 "redtree.y"
    {
          reduce_rule(mlhs_inner__tLPAREN__mlhs_inner__rparen, 3);
        ;}
    break;

  case 74:
#line 1068 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head, 1);
        ;}
    break;

  case 75:
#line 1072 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head__mlhs_item, 2);
        ;}
    break;

  case 76:
#line 1076 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head__tSTAR__mlhs_node, 3);
        ;}
    break;

  case 77:
#line 1080 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head__tSTAR__mlhs_node__COMMA__mlhs_post, 5);
        ;}
    break;

  case 78:
#line 1084 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head__tSTAR, 2);
        ;}
    break;

  case 79:
#line 1088 "redtree.y"
    {
          reduce_rule(mlhs_basic__mlhs_head__tSTAR__COMMA__mlhs_post, 4);
        ;}
    break;

  case 80:
#line 1092 "redtree.y"
    {
          reduce_rule(mlhs_basic__tSTAR__mlhs_node, 2);
        ;}
    break;

  case 81:
#line 1096 "redtree.y"
    {
          reduce_rule(mlhs_basic__tSTAR__mlhs_node__COMMA__mlhs_post, 4);
        ;}
    break;

  case 82:
#line 1100 "redtree.y"
    {
          reduce_rule(mlhs_basic__tSTAR, 1);
        ;}
    break;

  case 83:
#line 1104 "redtree.y"
    {
          reduce_rule(mlhs_basic__tSTAR__COMMA__mlhs_post, 3);
        ;}
    break;

  case 84:
#line 1110 "redtree.y"
    {
          reduce_rule(mlhs_item__mlhs_node, 1);
        ;}
    break;

  case 85:
#line 1114 "redtree.y"
    {
          reduce_rule(mlhs_item__tLPAREN__mlhs_inner__rparen, 3);
        ;}
    break;

  case 86:
#line 1120 "redtree.y"
    {
          reduce_rule(mlhs_head__mlhs_item__COMMA, 2);
        ;}
    break;

  case 87:
#line 1124 "redtree.y"
    {
          reduce_rule(mlhs_head__mlhs_head__mlhs_item__COMMA, 3);
        ;}
    break;

  case 88:
#line 1130 "redtree.y"
    {
          reduce_rule(mlhs_post__mlhs_item, 1);
        ;}
    break;

  case 89:
#line 1134 "redtree.y"
    {
          reduce_rule(mlhs_post__mlhs_post__COMMA__mlhs_item, 3);
        ;}
    break;

  case 90:
#line 1140 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(mlhs_node__user_variable, 1);
        ;}
    break;

  case 91:
#line 1145 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(mlhs_node__keyword_variable, 1);
        ;}
    break;

  case 92:
#line 1150 "redtree.y"
    {
          reduce_rule(mlhs_node__primary_value__LS__opt_call_args__rbracket, 4);
        ;}
    break;

  case 93:
#line 1154 "redtree.y"
    {
          reduce_rule(mlhs_node__primary_value__DOT__tIDENTIFIER, 3);
        ;}
    break;

  case 94:
#line 1158 "redtree.y"
    {
          reduce_rule(mlhs_node__primary_value__tCOLON2__tIDENTIFIER, 3);
        ;}
    break;

  case 95:
#line 1162 "redtree.y"
    {
          reduce_rule(mlhs_node__primary_value__DOT__tCONSTANT, 3);
        ;}
    break;

  case 96:
#line 1166 "redtree.y"
    {
          if (in_def || in_single)
            yyerror("dynamic constant assignment");
          reduce_rule(mlhs_node__primary_value__tCOLON3__tCONSTANT, 3);
        ;}
    break;

  case 97:
#line 1172 "redtree.y"
    {
          reduce_rule(mlhs_node__tCOLON3__tCONSTANT, 2);
        ;}
    break;

  case 98:
#line 1176 "redtree.y"
    {
          reduce_rule(mlhs_node__backref, 1);
        ;}
    break;

  case 99:
#line 1182 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(lhs__user_variable, 1);
        ;}
    break;

  case 100:
#line 1187 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(lhs__keyword_variable, 1);
        ;}
    break;

  case 101:
#line 1192 "redtree.y"
    {
          reduce_rule(lhs__primary_value__LS__opt_call_args__rbracket, 4);
        ;}
    break;

  case 102:
#line 1196 "redtree.y"
    {
          reduce_rule(lhs__primary_value__DOT__tIDENTIFIER, 3);
        ;}
    break;

  case 103:
#line 1200 "redtree.y"
    {
          reduce_rule(lhs__primary_value__tCOLON2__tIDENTIFIER, 3);
        ;}
    break;

  case 104:
#line 1204 "redtree.y"
    {
          reduce_rule(lhs__primary_value__DOT__tCONSTANT, 3);
        ;}
    break;

  case 105:
#line 1208 "redtree.y"
    {
          if (in_def || in_single)
            yyerror("dynamic constant assignment");
          reduce_rule(lhs__primary_value__tCOLON3__tCONSTANT, 3);
        ;}
    break;

  case 106:
#line 1214 "redtree.y"
    {
          reduce_rule(lhs__tCOLON3__tCONSTANT, 2);
        ;}
    break;

  case 107:
#line 1218 "redtree.y"
    {
          reduce_rule(lhs__backref, 1);
        ;}
    break;

  case 108:
#line 1224 "redtree.y"
    {
          reduce_rule(cname__tIDENTIFIER, 1);
        ;}
    break;

  case 109:
#line 1228 "redtree.y"
    {
          reduce_rule(cname__tCONSTANT, 1);
        ;}
    break;

  case 110:
#line 1234 "redtree.y"
    {
          reduce_rule(cpath__tCOLON3__cname, 2);
        ;}
    break;

  case 111:
#line 1238 "redtree.y"
    {
          reduce_rule(cpath__cname, 1);
        ;}
    break;

  case 112:
#line 1242 "redtree.y"
    {
          reduce_rule(cpath__primary_value__tCOLON2__cname, 3);
        ;}
    break;

  case 113:
#line 1248 "redtree.y"
    {
          reduce_rule(fname__tIDENTIFIER, 1);
        ;}
    break;

  case 114:
#line 1252 "redtree.y"
    {
          reduce_rule(fname__tCONSTANT, 1);
        ;}
    break;

  case 115:
#line 1256 "redtree.y"
    {
          reduce_rule(fname__tFID, 1);
        ;}
    break;

  case 116:
#line 1260 "redtree.y"
    {
          lex_state = EXPR_ENDFN;
          reduce_rule(fname__op, 1);
        ;}
    break;

  case 117:
#line 1265 "redtree.y"
    {
          lex_state = EXPR_ENDFN;
          reduce_rule(fname__reswords, 1);
        ;}
    break;

  case 118:
#line 1272 "redtree.y"
    {
          reduce_rule(fsym__fname, 1);
        ;}
    break;

  case 119:
#line 1276 "redtree.y"
    {
          reduce_rule(fsym__symbol, 1);
        ;}
    break;

  case 120:
#line 1282 "redtree.y"
    {
          reduce_rule(fitem__fsym, 1);
        ;}
    break;

  case 121:
#line 1286 "redtree.y"
    {
          reduce_rule(fitem__dsym, 1);
        ;}
    break;

  case 122:
#line 1292 "redtree.y"
    {
          reduce_rule(undef_list__fitem, 1);
        ;}
    break;

  case 123:
#line 1295 "redtree.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 124:
#line 1296 "redtree.y"
    {
          reduce_rule(undef_list__COMMA__fitem, 2);
        ;}
    break;

  case 125:
#line 1301 "redtree.y"
    { reduce_rule(op__OR, 1); ;}
    break;

  case 126:
#line 1302 "redtree.y"
    { reduce_rule(op__CARET, 1); ;}
    break;

  case 127:
#line 1303 "redtree.y"
    { reduce_rule(op__AND, 1); ;}
    break;

  case 128:
#line 1304 "redtree.y"
    { reduce_rule(op__tCMP, 1); ;}
    break;

  case 129:
#line 1305 "redtree.y"
    { reduce_rule(op__tEQ, 1); ;}
    break;

  case 130:
#line 1306 "redtree.y"
    { reduce_rule(op__tEQQ, 1); ;}
    break;

  case 131:
#line 1307 "redtree.y"
    { reduce_rule(op__tMATCH, 1); ;}
    break;

  case 132:
#line 1308 "redtree.y"
    { reduce_rule(op__tNMATCH, 1); ;}
    break;

  case 133:
#line 1309 "redtree.y"
    { reduce_rule(op__GT, 1); ;}
    break;

  case 134:
#line 1310 "redtree.y"
    { reduce_rule(op__tGEQ, 1); ;}
    break;

  case 135:
#line 1311 "redtree.y"
    { reduce_rule(op__LE, 1); ;}
    break;

  case 136:
#line 1312 "redtree.y"
    { reduce_rule(op__tLEQ, 1); ;}
    break;

  case 137:
#line 1313 "redtree.y"
    { reduce_rule(op__tNEQ, 1); ;}
    break;

  case 138:
#line 1314 "redtree.y"
    { reduce_rule(op__tLSHFT, 1); ;}
    break;

  case 139:
#line 1315 "redtree.y"
    { reduce_rule(op__tRSHFT, 1); ;}
    break;

  case 140:
#line 1316 "redtree.y"
    { reduce_rule(op__PLUS, 1); ;}
    break;

  case 141:
#line 1317 "redtree.y"
    { reduce_rule(op__MINUS, 1); ;}
    break;

  case 142:
#line 1318 "redtree.y"
    { reduce_rule(op__TIMES, 1); ;}
    break;

  case 143:
#line 1319 "redtree.y"
    { reduce_rule(op__tSTAR, 1); ;}
    break;

  case 144:
#line 1320 "redtree.y"
    { reduce_rule(op__DIVIDE, 1); ;}
    break;

  case 145:
#line 1321 "redtree.y"
    { reduce_rule(op__MOD, 1); ;}
    break;

  case 146:
#line 1322 "redtree.y"
    { reduce_rule(op__tPOW, 1); ;}
    break;

  case 147:
#line 1323 "redtree.y"
    { reduce_rule(op__BANG, 1); ;}
    break;

  case 148:
#line 1324 "redtree.y"
    { reduce_rule(op__TILDE, 1); ;}
    break;

  case 149:
#line 1325 "redtree.y"
    { reduce_rule(op__tUPLUS, 1); ;}
    break;

  case 150:
#line 1326 "redtree.y"
    { reduce_rule(op__tUMINUS, 1); ;}
    break;

  case 151:
#line 1327 "redtree.y"
    { reduce_rule(op__tAREF, 1); ;}
    break;

  case 152:
#line 1328 "redtree.y"
    { reduce_rule(op__tASET, 1); ;}
    break;

  case 153:
#line 1329 "redtree.y"
    { reduce_rule(op__BACKTICK, 1); ;}
    break;

  case 154:
#line 1332 "redtree.y"
    { reduce_rule(reswords__keyword__LINE__, 2); ;}
    break;

  case 155:
#line 1333 "redtree.y"
    { reduce_rule(reswords__keyword__FILE__, 2); ;}
    break;

  case 156:
#line 1334 "redtree.y"
    { reduce_rule(reswords__keyword__ENCODING__, 2); ;}
    break;

  case 157:
#line 1335 "redtree.y"
    { reduce_rule(reswords__keyword_BEGIN, 1); ;}
    break;

  case 158:
#line 1336 "redtree.y"
    { reduce_rule(reswords__keyword_END, 1); ;}
    break;

  case 159:
#line 1337 "redtree.y"
    { reduce_rule(reswords__keyword_alias, 1); ;}
    break;

  case 160:
#line 1338 "redtree.y"
    { reduce_rule(reswords__keyword_and, 1); ;}
    break;

  case 161:
#line 1339 "redtree.y"
    { reduce_rule(reswords__keyword_begin, 1); ;}
    break;

  case 162:
#line 1340 "redtree.y"
    { reduce_rule(reswords__keyword_break, 1); ;}
    break;

  case 163:
#line 1341 "redtree.y"
    { reduce_rule(reswords__keyword_case, 1); ;}
    break;

  case 164:
#line 1342 "redtree.y"
    { reduce_rule(reswords__keyword_class, 1); ;}
    break;

  case 165:
#line 1343 "redtree.y"
    { reduce_rule(reswords__keyword_def, 1); ;}
    break;

  case 166:
#line 1344 "redtree.y"
    { reduce_rule(reswords__keyword_defined, 1); ;}
    break;

  case 167:
#line 1345 "redtree.y"
    { reduce_rule(reswords__keyword_do, 1); ;}
    break;

  case 168:
#line 1346 "redtree.y"
    { reduce_rule(reswords__keyword_else, 1); ;}
    break;

  case 169:
#line 1347 "redtree.y"
    { reduce_rule(reswords__keyword_elsif, 1); ;}
    break;

  case 170:
#line 1348 "redtree.y"
    { reduce_rule(reswords__keyword_end, 1); ;}
    break;

  case 171:
#line 1349 "redtree.y"
    { reduce_rule(reswords__keyword_ensure, 1); ;}
    break;

  case 172:
#line 1350 "redtree.y"
    { reduce_rule(reswords__keyword_false, 1); ;}
    break;

  case 173:
#line 1351 "redtree.y"
    { reduce_rule(reswords__keyword_for, 1); ;}
    break;

  case 174:
#line 1352 "redtree.y"
    { reduce_rule(reswords__keyword_in, 1); ;}
    break;

  case 175:
#line 1353 "redtree.y"
    { reduce_rule(reswords__keyword_module, 1); ;}
    break;

  case 176:
#line 1354 "redtree.y"
    { reduce_rule(reswords__keyword_next, 1); ;}
    break;

  case 177:
#line 1355 "redtree.y"
    { reduce_rule(reswords__keyword_nil, 1); ;}
    break;

  case 178:
#line 1356 "redtree.y"
    { reduce_rule(reswords__keyword_not, 1); ;}
    break;

  case 179:
#line 1357 "redtree.y"
    { reduce_rule(reswords__keyword_or, 1); ;}
    break;

  case 180:
#line 1358 "redtree.y"
    { reduce_rule(reswords__keyword_redo, 1); ;}
    break;

  case 181:
#line 1359 "redtree.y"
    { reduce_rule(reswords__keyword_rescue, 1); ;}
    break;

  case 182:
#line 1360 "redtree.y"
    { reduce_rule(reswords__keyword_retry, 1); ;}
    break;

  case 183:
#line 1361 "redtree.y"
    { reduce_rule(reswords__keyword_return, 1); ;}
    break;

  case 184:
#line 1362 "redtree.y"
    { reduce_rule(reswords__keyword_self, 1); ;}
    break;

  case 185:
#line 1363 "redtree.y"
    { reduce_rule(reswords__keyword_super, 1); ;}
    break;

  case 186:
#line 1364 "redtree.y"
    { reduce_rule(reswords__keyword_then, 1); ;}
    break;

  case 187:
#line 1365 "redtree.y"
    { reduce_rule(reswords__keyword_true, 1); ;}
    break;

  case 188:
#line 1366 "redtree.y"
    { reduce_rule(reswords__keyword_undef, 1); ;}
    break;

  case 189:
#line 1367 "redtree.y"
    { reduce_rule(reswords__keyword_when, 1); ;}
    break;

  case 190:
#line 1368 "redtree.y"
    { reduce_rule(reswords__keyword_yield, 1); ;}
    break;

  case 191:
#line 1369 "redtree.y"
    { reduce_rule(reswords__keyword_if, 1); ;}
    break;

  case 192:
#line 1370 "redtree.y"
    { reduce_rule(reswords__keyword_unless, 1); ;}
    break;

  case 193:
#line 1371 "redtree.y"
    { reduce_rule(reswords__keyword_while, 1); ;}
    break;

  case 194:
#line 1372 "redtree.y"
    { reduce_rule(reswords__keyword_until, 1); ;}
    break;

  case 195:
#line 1376 "redtree.y"
    {
          reduce_rule(arg__lhs__EQ__arg, 3);
        ;}
    break;

  case 196:
#line 1380 "redtree.y"
    {
          reduce_rule(arg__lhs__EQ__arg__modifier_rescue__arg, 5);
        ;}
    break;

  case 197:
#line 1384 "redtree.y"
    {
          reduce_rule(arg__var_lhs__tOP_ASGN__arg, 3);
        ;}
    break;

  case 198:
#line 1388 "redtree.y"
    {
          reduce_rule(arg__var_lhs__tOP_ASGN__arg__modifier_rescue__arg, 5);
        ;}
    break;

  case 199:
#line 1392 "redtree.y"
    {
          reduce_rule(arg__primary_value__LS__opt_call_args__rbracket__tOP_ASGN__arg, 6);
        ;}
    break;

  case 200:
#line 1396 "redtree.y"
    {
          reduce_rule(arg__primary_value__DOT__tIDENTIFIER__tOP_ASGN__arg, 5);
        ;}
    break;

  case 201:
#line 1400 "redtree.y"
    {
          reduce_rule(arg__primary_value__DOT__tCONSTANT__tOP_ASGN__arg, 5);
        ;}
    break;

  case 202:
#line 1404 "redtree.y"
    {
          reduce_rule(arg__primary_value__tCOLON2__tIDENTIFIER__tOP_ASGN__arg, 5);
        ;}
    break;

  case 203:
#line 1408 "redtree.y"
    {
          reduce_rule(arg__primary_value__tCOLON2__tCONSTANT__tOP_ASGN__arg, 5);
        ;}
    break;

  case 204:
#line 1412 "redtree.y"
    {
          reduce_rule(arg__tCOLON3__tCONSTANT__tOP_ASGN__arg, 4);
        ;}
    break;

  case 205:
#line 1416 "redtree.y"
    {
          reduce_rule(arg__backref__tOP_ASGN__arg, 3);
        ;}
    break;

  case 206:
#line 1420 "redtree.y"
    {
          reduce_rule(arg__arg__tDOT2__arg, 3);
        ;}
    break;

  case 207:
#line 1424 "redtree.y"
    {
          reduce_rule(arg__arg__tDOT3__arg, 3);
        ;}
    break;

  case 208:
#line 1428 "redtree.y"
    {
          reduce_rule(arg__arg__PLUS__arg, 3);
        ;}
    break;

  case 209:
#line 1432 "redtree.y"
    {
          reduce_rule(arg__arg__MINUS__arg, 3);
        ;}
    break;

  case 210:
#line 1436 "redtree.y"
    {
          reduce_rule(arg__arg__TIMES__arg, 3);
        ;}
    break;

  case 211:
#line 1440 "redtree.y"
    {
          reduce_rule(arg__arg__DIVIDE__arg, 3);
        ;}
    break;

  case 212:
#line 1444 "redtree.y"
    {
          reduce_rule(arg__arg__DIVIDE__arg, 3);
        ;}
    break;

  case 213:
#line 1448 "redtree.y"
    {
          reduce_rule(arg__arg__tPOW__arg, 3);
        ;}
    break;

  case 214:
#line 1452 "redtree.y"
    {
          reduce_rule(arg__tUMINUS_NUM__tINTEGER__tPOW__arg, 4);
        ;}
    break;

  case 215:
#line 1456 "redtree.y"
    {
          reduce_rule(arg__tUMINUS_NUM__tFLOAT__tPOW__arg, 4);
        ;}
    break;

  case 216:
#line 1460 "redtree.y"
    {
          reduce_rule(arg__tUPLUS__arg, 2);
        ;}
    break;

  case 217:
#line 1464 "redtree.y"
    {
          reduce_rule(arg__tUMINUS__arg, 2);
        ;}
    break;

  case 218:
#line 1468 "redtree.y"
    {
          reduce_rule(arg__arg__OR__arg, 3);
        ;}
    break;

  case 219:
#line 1472 "redtree.y"
    {
          reduce_rule(arg__arg__CARET__arg, 3);
        ;}
    break;

  case 220:
#line 1476 "redtree.y"
    {
          reduce_rule(arg__arg__AND__arg, 3);
        ;}
    break;

  case 221:
#line 1480 "redtree.y"
    {
          reduce_rule(arg__arg__tCMP__arg, 3);
        ;}
    break;

  case 222:
#line 1484 "redtree.y"
    {
          reduce_rule(arg__arg__GT__arg, 3);
        ;}
    break;

  case 223:
#line 1488 "redtree.y"
    {
          reduce_rule(arg__arg__tGEQ__arg, 3);
        ;}
    break;

  case 224:
#line 1492 "redtree.y"
    {
          reduce_rule(arg__arg__LT__arg, 3);
        ;}
    break;

  case 225:
#line 1496 "redtree.y"
    {
          reduce_rule(arg__arg__tLEQ__arg, 3);
        ;}
    break;

  case 226:
#line 1500 "redtree.y"
    {
          reduce_rule(arg__arg__tEQ__arg, 3);
        ;}
    break;

  case 227:
#line 1504 "redtree.y"
    {
          reduce_rule(arg__arg__tEQQ__arg, 3);
        ;}
    break;

  case 228:
#line 1508 "redtree.y"
    {
          reduce_rule(arg__arg__tNEQ__arg, 3);
        ;}
    break;

  case 229:
#line 1512 "redtree.y"
    {
          reduce_rule(arg__arg__tMATCH__arg, 3);
        ;}
    break;

  case 230:
#line 1516 "redtree.y"
    {
          reduce_rule(arg__arg__tNMATCH__arg, 3);
        ;}
    break;

  case 231:
#line 1520 "redtree.y"
    {
          reduce_rule(arg__BANG__arg, 2);
        ;}
    break;

  case 232:
#line 1524 "redtree.y"
    {
          reduce_rule(arg__TILDE__arg, 2);
        ;}
    break;

  case 233:
#line 1528 "redtree.y"
    {
          reduce_rule(arg__arg__tLSHFT__arg, 3);
        ;}
    break;

  case 234:
#line 1532 "redtree.y"
    {
          reduce_rule(arg__arg__tRSHFT__arg, 3);
        ;}
    break;

  case 235:
#line 1536 "redtree.y"
    {
          reduce_rule(arg__arg__tANDOP__arg, 3);
        ;}
    break;

  case 236:
#line 1540 "redtree.y"
    {
          reduce_rule(arg__arg__tOROP__arg, 3);
        ;}
    break;

  case 237:
#line 1543 "redtree.y"
    {in_defined = 1;;}
    break;

  case 238:
#line 1544 "redtree.y"
    {
          in_defined = 0;
          reduce_rule(arg__keyword_defined__opt_nl__arg, 3);
        ;}
    break;

  case 239:
#line 1549 "redtree.y"
    {
          reduce_rule(arg__QMARK__arg__opt_nl__COLON__arg, 5);
        ;}
    break;

  case 240:
#line 1553 "redtree.y"
    {
          reduce_rule(arg__primary, 1);
        ;}
    break;

  case 241:
#line 1559 "redtree.y"
    {
          reduce_rule(arg_value__arg, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 242:
#line 1566 "redtree.y"
    {
          reduce_rule(aref_args__none, 1);
        ;}
    break;

  case 243:
#line 1570 "redtree.y"
    {
          reduce_rule(aref_args__args__trailer, 2);
        ;}
    break;

  case 244:
#line 1574 "redtree.y"
    {
          reduce_rule(aref_args__args__COMMA__assocs__trailer, 4);
        ;}
    break;

  case 245:
#line 1578 "redtree.y"
    {
          reduce_rule(aref_args__assocs__trailer, 2);
        ;}
    break;

  case 246:
#line 1584 "redtree.y"
    {
          reduce_rule(paren_args__LR__opt_call_args__rparen, 3);
        ;}
    break;

  case 247:
#line 1590 "redtree.y"
    {
          reduce_rule(opt_paren_args__none, 1);
        ;}
    break;

  case 248:
#line 1594 "redtree.y"
    {
          reduce_rule(opt_paren_args__paren_args, 1);
        ;}
    break;

  case 249:
#line 1600 "redtree.y"
    {
          reduce_rule(opt_call_args__none, 1);
        ;}
    break;

  case 250:
#line 1604 "redtree.y"
    {
          reduce_rule(opt_call_args__call_args, 1);
        ;}
    break;

  case 251:
#line 1608 "redtree.y"
    {
          reduce_rule(opt_call_args__args__COMMA, 2);
        ;}
    break;

  case 252:
#line 1612 "redtree.y"
    {
          reduce_rule(opt_call_args__args__COMMA__assocs__COMMA, 4);
        ;}
    break;

  case 253:
#line 1616 "redtree.y"
    {
          reduce_rule(opt_call_args__assocs__COMMA, 2);
        ;}
    break;

  case 254:
#line 1622 "redtree.y"
    {
          reduce_rule(call_args__command, 1);
        ;}
    break;

  case 255:
#line 1626 "redtree.y"
    {
          reduce_rule(call_args__args__opt_block_arg, 2);
        ;}
    break;

  case 256:
#line 1630 "redtree.y"
    {
          reduce_rule(call_args__assocs__opt_block_arg, 2);
        ;}
    break;

  case 257:
#line 1634 "redtree.y"
    {
          reduce_rule(call_args__args__COMMA__assocs__opt_block_arg, 4);
        ;}
    break;

  case 258:
#line 1638 "redtree.y"
    {
          reduce_rule(call_args__block_arg, 1);
        ;}
    break;

  case 259:
#line 1644 "redtree.y"
    {
          (yyval.val) = cmdarg_stack;
          CMDARG_PUSH(1);
        ;}
    break;

  case 260:
#line 1649 "redtree.y"
    {
          /* CMDARG_POP() */
          cmdarg_stack = (yyvsp[(1) - (2)].val);
          reduce_rule(command_args__call_args, 1);
        ;}
    break;

  case 261:
#line 1657 "redtree.y"
    {
          reduce_rule(block_arg__tAMPER__arg_value, 2);
        ;}
    break;

  case 262:
#line 1663 "redtree.y"
    {
          reduce_rule(opt_block_arg__COMMA__block_arg, 2);
        ;}
    break;

  case 263:
#line 1667 "redtree.y"
    {
          reduce_rule(opt_block_arg__none, 1);
        ;}
    break;

  case 264:
#line 1673 "redtree.y"
    {
          reduce_rule(args__arg_value, 1);
        ;}
    break;

  case 265:
#line 1677 "redtree.y"
    {
          reduce_rule(args__tSTAR__arg_value, 2);
        ;}
    break;

  case 266:
#line 1681 "redtree.y"
    {
          reduce_rule(args__args__COMMA__arg_value, 3);
        ;}
    break;

  case 267:
#line 1685 "redtree.y"
    {
          reduce_rule(args__args__COMMA__tSTAR__arg_value, 4);
        ;}
    break;

  case 268:
#line 1691 "redtree.y"
    {
          reduce_rule(mrhs__args__COMMA__arg_value, 3);
        ;}
    break;

  case 269:
#line 1695 "redtree.y"
    {
          reduce_rule(mrhs__args__COMMA__tSTAR__arg_value, 4);
        ;}
    break;

  case 270:
#line 1699 "redtree.y"
    {
          reduce_rule(mrhs__tSTAR__arg_value, 2);
        ;}
    break;

  case 271:
#line 1705 "redtree.y"
    {
          reduce_rule(primary__literal, 1);
        ;}
    break;

  case 272:
#line 1709 "redtree.y"
    {
          reduce_rule(primary__strings, 1);
        ;}
    break;

  case 273:
#line 1713 "redtree.y"
    {
          reduce_rule(primary__xstring, 1);
        ;}
    break;

  case 274:
#line 1717 "redtree.y"
    {
          reduce_rule(primary__regexp, 1);
        ;}
    break;

  case 275:
#line 1721 "redtree.y"
    {
          reduce_rule(primary__words, 1);
        ;}
    break;

  case 276:
#line 1725 "redtree.y"
    {
          reduce_rule(primary__qwords, 1);
        ;}
    break;

  case 277:
#line 1729 "redtree.y"
    {
          reduce_rule(primary__var_ref, 1);
        ;}
    break;

  case 278:
#line 1733 "redtree.y"
    {
          reduce_rule(primary__backref, 1);
        ;}
    break;

  case 279:
#line 1737 "redtree.y"
    {
          reduce_rule(primary__tFID, 1);
        ;}
    break;

  case 280:
#line 1741 "redtree.y"
    {
          reduce_rule(primary__k_begin, 1);
        ;}
    break;

  case 281:
#line 1744 "redtree.y"
    {lex_state = EXPR_ENDARG;;}
    break;

  case 282:
#line 1745 "redtree.y"
    {
          rb_warning0("(...) interpreted as grouped expression");
          reduce_rule(primary__tLPAREN_ARG__expr__rparen, 3);
        ;}
    break;

  case 283:
#line 1750 "redtree.y"
    {
          reduce_rule(primary__tLPAREN__compstmt__RR, 3);
        ;}
    break;

  case 284:
#line 1754 "redtree.y"
    {
          reduce_rule(primary__primary_value__tCOLON2__tCONSTANT, 3);
        ;}
    break;

  case 285:
#line 1758 "redtree.y"
    {
          reduce_rule(primary__tCOLON3__tCONSTANT, 2);
        ;}
    break;

  case 286:
#line 1762 "redtree.y"
    {
          reduce_rule(primary__tLBRACK__aref_args__RS, 3);
        ;}
    break;

  case 287:
#line 1766 "redtree.y"
    {
          reduce_rule(primary__tLBRACE__assoc_list__RC, 3);
        ;}
    break;

  case 288:
#line 1770 "redtree.y"
    {
          reduce_rule(primary__keyword_return, 1);
        ;}
    break;

  case 289:
#line 1774 "redtree.y"
    {
          reduce_rule(primary__keyword_yield__LR__call_args__rparen, 4);
        ;}
    break;

  case 290:
#line 1778 "redtree.y"
    {
          reduce_rule(primary__keyword_yield__LR__rparen, 3);
        ;}
    break;

  case 291:
#line 1782 "redtree.y"
    {
          reduce_rule(primary__keyword_yield, 1);
        ;}
    break;

  case 292:
#line 1785 "redtree.y"
    {in_defined = 1;;}
    break;

  case 293:
#line 1786 "redtree.y"
    {
          in_defined = 0;
          reduce_rule(primary__keyword_defined__opt_nl__LR__expr__rparen, 5);
        ;}
    break;

  case 294:
#line 1791 "redtree.y"
    {
          reduce_rule(primary__keyword_not__LR__expr__rparen, 4);
        ;}
    break;

  case 295:
#line 1795 "redtree.y"
    {
          reduce_rule(primary__keyword_not__LR__rparen, 3);
        ;}
    break;

  case 296:
#line 1799 "redtree.y"
    {
          reduce_rule(primary__operation__brace_block, 2);
        ;}
    break;

  case 297:
#line 1803 "redtree.y"
    {
          reduce_rule(primary__method_call, 1);
        ;}
    break;

  case 298:
#line 1807 "redtree.y"
    {
          reduce_rule(primary__method_call__brace_block, 2);
        ;}
    break;

  case 299:
#line 1811 "redtree.y"
    {
          reduce_rule(primary__tLAMBDA__lambda, 2);
        ;}
    break;

  case 300:
#line 1815 "redtree.y"
    {
          reduce_rule(primary__k_if__expr_value__then__compstmt__if_tail__k_end, 6);
        ;}
    break;

  case 301:
#line 1819 "redtree.y"
    {
          reduce_rule(primary__k_unless__expr_value__then__compstmt__opt_else__k_end, 6);
        ;}
    break;

  case 302:
#line 1822 "redtree.y"
    {COND_PUSH(1);;}
    break;

  case 303:
#line 1822 "redtree.y"
    {COND_POP();;}
    break;

  case 304:
#line 1823 "redtree.y"
    {
          reduce_rule(primary__k_while__expr_value__do__compstmt__k_end, 5);
        ;}
    break;

  case 305:
#line 1826 "redtree.y"
    {COND_PUSH(1);;}
    break;

  case 306:
#line 1826 "redtree.y"
    {COND_POP();;}
    break;

  case 307:
#line 1827 "redtree.y"
    {
          reduce_rule(primary__k_until__expr_value__do__compstmt__k_end, 5);
        ;}
    break;

  case 308:
#line 1831 "redtree.y"
    {
          reduce_rule(primary__k_case__expr_value__opt_terms__case_body__k_end, 5);
        ;}
    break;

  case 309:
#line 1835 "redtree.y"
    {
          reduce_rule(primary__k_case__opt_terms__case_body__k_end, 4);
        ;}
    break;

  case 310:
#line 1839 "redtree.y"
    {COND_PUSH(1);;}
    break;

  case 311:
#line 1841 "redtree.y"
    {COND_POP();;}
    break;

  case 312:
#line 1844 "redtree.y"
    {
          reduce_rule(primary__k_for__for_var__keyword_in__expr_value__do__compstmt__k_end, 7);
        ;}
    break;

  case 313:
#line 1848 "redtree.y"
    {
          if (in_def || in_single)
          yyerror("class definition in method body");
          local_push(0);
        ;}
    break;

  case 314:
#line 1855 "redtree.y"
    {
          reduce_rule(primary__k_class__cpath__superclass__bodystmt__k_end, 5);

          local_pop();
        ;}
    break;

  case 315:
#line 1861 "redtree.y"
    {
          (yyval.num) = in_def;
          in_def = 0;
        ;}
    break;

  case 316:
#line 1866 "redtree.y"
    {
          (yyval.num) = in_single;
          in_single = 0;
          local_push(0);
        ;}
    break;

  case 317:
#line 1873 "redtree.y"
    {
          reduce_rule(primary__k_class__tLSHFT__expr__term__bodystmt__k_end, 6);

          local_pop();
          in_def = (yyvsp[(4) - (8)].num);
          in_single = (yyvsp[(6) - (8)].num);
        ;}
    break;

  case 318:
#line 1881 "redtree.y"
    {
          if (in_def || in_single)
          yyerror("module definition in method body");
          local_push(0);
        ;}
    break;

  case 319:
#line 1888 "redtree.y"
    {
          reduce_rule(primary__k_module__cpath__bodystmt__k_end, 4);

          local_pop();
        ;}
    break;

  case 320:
#line 1894 "redtree.y"
    {
          (yyval.id) = cur_mid;
          cur_mid = (yyvsp[(2) - (2)].val);
          in_def++;
          local_push(0);
        ;}
    break;

  case 321:
#line 1903 "redtree.y"
    {
          reduce_rule(primary__k_def__fname__f_arglist__bodystmt__k_end, 5);

          local_pop();
          in_def--;
          cur_mid = (yyvsp[(3) - (6)].id);
        ;}
    break;

  case 322:
#line 1910 "redtree.y"
    {lex_state = EXPR_FNAME;;}
    break;

  case 323:
#line 1911 "redtree.y"
    {
          in_single++;
          lex_state = EXPR_ENDFN; /* force for args */
          local_push(0);
        ;}
    break;

  case 324:
#line 1919 "redtree.y"
    {
          reduce_rule(primary__k_def__singleton__dot_or_colon__fname__f_arglist__bodystmt__k_end, 7);

          local_pop();
          in_single--;
        ;}
    break;

  case 325:
#line 1926 "redtree.y"
    {
          reduce_rule(primary__keyword_break, 1);
        ;}
    break;

  case 326:
#line 1930 "redtree.y"
    {
          reduce_rule(primary__keyword_next, 1);
        ;}
    break;

  case 327:
#line 1934 "redtree.y"
    {
          reduce_rule(primary__keyword_redo, 1);
        ;}
    break;

  case 328:
#line 1938 "redtree.y"
    {
          reduce_rule(primary__keyword_retry, 1);
        ;}
    break;

  case 329:
#line 1944 "redtree.y"
    {
          reduce_rule(primary_value__primary, 1);
        ;}
    break;

  case 330:
#line 1950 "redtree.y"
    {
          token_info_push("begin");
          reduce_rule(k_begin__keyword_begin, 1);
        ;}
    break;

  case 331:
#line 1957 "redtree.y"
    {
          token_info_push("if");
          reduce_rule(k_if__keyword_if, 1);
        ;}
    break;

  case 332:
#line 1964 "redtree.y"
    {
          reduce_rule(k_unless__keyword_unless, 1);
        ;}
    break;

  case 333:
#line 1970 "redtree.y"
    {
          reduce_rule(k_while__keyword_while, 1);
        ;}
    break;

  case 334:
#line 1976 "redtree.y"
    {
          reduce_rule(k_until__keyword_until, 1);
        ;}
    break;

  case 335:
#line 1982 "redtree.y"
    {
          reduce_rule(k_case__keyword_case, 1);
        ;}
    break;

  case 336:
#line 1988 "redtree.y"
    {
          reduce_rule(k_for__keyword_for, 1);
        ;}
    break;

  case 337:
#line 1994 "redtree.y"
    {
          reduce_rule(k_class__keyword_class, 1);
        ;}
    break;

  case 338:
#line 2000 "redtree.y"
    {
          reduce_rule(k_module__keyword_module, 1);
        ;}
    break;

  case 339:
#line 2006 "redtree.y"
    {
          reduce_rule(k_def__keyword_def, 1);
        ;}
    break;

  case 340:
#line 2012 "redtree.y"
    {
          reduce_rule(k_end__keyword_end, 1);
        ;}
    break;

  case 341:
#line 2018 "redtree.y"
    {
          reduce_rule(then__term, 1);
        ;}
    break;

  case 342:
#line 2022 "redtree.y"
    {
          reduce_rule(then__keyword_then, 1);
        ;}
    break;

  case 343:
#line 2026 "redtree.y"
    {
          reduce_rule(then__term__keyword_then, 2);
        ;}
    break;

  case 344:
#line 2032 "redtree.y"
    {
          reduce_rule(do__term, 1);
        ;}
    break;

  case 345:
#line 2036 "redtree.y"
    {
          reduce_rule(do__keyword_do_cond, 1);
        ;}
    break;

  case 346:
#line 2042 "redtree.y"
    {
          reduce_rule(if_tail__opt_else, 1);
        ;}
    break;

  case 347:
#line 2046 "redtree.y"
    {
          reduce_rule(if_tail__keyword_elsif__expr_value__then__compstmt__if_tail, 5);
        ;}
    break;

  case 348:
#line 2052 "redtree.y"
    {
          reduce_rule(opt_else__none, 1);
        ;}
    break;

  case 349:
#line 2056 "redtree.y"
    {
          reduce_rule(opt_else__keyword_else__compstmt, 2);
        ;}
    break;

  case 350:
#line 2062 "redtree.y"
    {
          reduce_rule(for_var__lhs, 1);
        ;}
    break;

  case 351:
#line 2066 "redtree.y"
    {
          reduce_rule(for_var__mlhs, 1);
        ;}
    break;

  case 352:
#line 2072 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(f_marg__f_norm_arg, 1);
        ;}
    break;

  case 353:
#line 2077 "redtree.y"
    {
          reduce_rule(f_marg__tLPAREN__f_margs__rparen, 3);
        ;}
    break;

  case 354:
#line 2083 "redtree.y"
    {
          reduce_rule(f_marg_list__f_marg, 1);
        ;}
    break;

  case 355:
#line 2087 "redtree.y"
    {
          reduce_rule(f_marg_list__f_marg_list__COMMA__f_marg, 3);
        ;}
    break;

  case 356:
#line 2093 "redtree.y"
    {
          reduce_rule(f_margs__f_marg_list, 1);
        ;}
    break;

  case 357:
#line 2097 "redtree.y"
    {
          assignable((yyvsp[(4) - (4)].val), 0);
          reduce_rule(f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg, 4);
        ;}
    break;

  case 358:
#line 2102 "redtree.y"
    {
          assignable((yyvsp[(4) - (6)].val), 0);
          reduce_rule(f_margs__f_marg_list__COMMA__tSTAR__f_norm_arg__COMMA__f_marg_list, 6);
        ;}
    break;

  case 359:
#line 2107 "redtree.y"
    {
          reduce_rule(f_margs__f_marg_list__COMMA__tSTAR, 3);
        ;}
    break;

  case 360:
#line 2111 "redtree.y"
    {
          reduce_rule(f_margs__f_marg_list__COMMA__tSTAR__COMMA__f_marg_list, 5);
        ;}
    break;

  case 361:
#line 2115 "redtree.y"
    {
          assignable((yyvsp[(2) - (2)].val), 0);
          reduce_rule(f_margs__tSTAR__f_norm_arg, 2);
        ;}
    break;

  case 362:
#line 2120 "redtree.y"
    {
          assignable((yyvsp[(2) - (4)].val), 0);
          reduce_rule(f_margs__tSTAR__f_norm_arg__COMMA__f_marg_list, 4);
        ;}
    break;

  case 363:
#line 2125 "redtree.y"
    {
          reduce_rule(f_margs__tSTAR, 1);
        ;}
    break;

  case 364:
#line 2129 "redtree.y"
    {
          reduce_rule(f_margs__tSTAR__COMMA__f_marg_list, 3);
        ;}
    break;

  case 365:
#line 2135 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 366:
#line 2139 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 8);
        ;}
    break;

  case 367:
#line 2143 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_block_optarg__opt_f_block_arg, 4);
        ;}
    break;

  case 368:
#line 2147 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_block_optarg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 369:
#line 2151 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_rest_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 370:
#line 2155 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA, 2);
        ;}
    break;

  case 371:
#line 2159 "redtree.y"
    {
          reduce_rule(block_param__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 372:
#line 2163 "redtree.y"
    {
          reduce_rule(block_param__f_arg__opt_f_block_arg, 2);
        ;}
    break;

  case 373:
#line 2167 "redtree.y"
    {
          reduce_rule(block_param__f_block_optarg__COMMA__f_rest_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 374:
#line 2171 "redtree.y"
    {
          reduce_rule(block_param__f_block_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 375:
#line 2175 "redtree.y"
    {
          reduce_rule(block_param__f_block_optarg__opt_f_block_arg, 2);
        ;}
    break;

  case 376:
#line 2179 "redtree.y"
    {
          reduce_rule(block_param__f_block_optarg__COMMA__f_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 377:
#line 2183 "redtree.y"
    {
          reduce_rule(block_param__f_rest_arg__opt_f_block_arg, 2);
        ;}
    break;

  case 378:
#line 2187 "redtree.y"
    {
          reduce_rule(block_param__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 379:
#line 2191 "redtree.y"
    {
          reduce_rule(block_param__f_block_arg, 1);
        ;}
    break;

  case 380:
#line 2197 "redtree.y"
    {
          reduce_rule(opt_block_param__none, 1);
        ;}
    break;

  case 381:
#line 2201 "redtree.y"
    {
          command_start = TRUE;
          reduce_rule(opt_block_param__block_param_def, 1);
        ;}
    break;

  case 382:
#line 2208 "redtree.y"
    {
          reduce_rule(block_param_def__OR__opt_bv_decl__OR, 3);
        ;}
    break;

  case 383:
#line 2212 "redtree.y"
    {
          reduce_rule(block_param_def__tOROP, 1);
        ;}
    break;

  case 384:
#line 2216 "redtree.y"
    {
          reduce_rule(block_param_def__OR__block_param__opt_bv_decl__OR, 4);
        ;}
    break;

  case 385:
#line 2223 "redtree.y"
    {
          reduce_rule(opt_bv_decl__none, 1);
        ;}
    break;

  case 386:
#line 2227 "redtree.y"
    {
          reduce_rule(opt_bv_decl__SEMI__bv_decls, 2);
        ;}
    break;

  case 387:
#line 2233 "redtree.y"
    {
          reduce_rule(bv_decls__bvar, 1);
        ;}
    break;

  case 388:
#line 2237 "redtree.y"
    {
          reduce_rule(bv_decls__bv_decls__COMMA__bvar, 3);
        ;}
    break;

  case 389:
#line 2244 "redtree.y"
    {
          new_bv(get_id((yyvsp[(1) - (1)].val)));
          get_value((yyvsp[(1) - (1)].val));
          reduce_rule(bvar__tIDENTIFIER, 1);
        ;}
    break;

  case 390:
#line 2250 "redtree.y"
    {
          reduce_rule(bvar__f_bad_arg, 1);
        ;}
    break;

  case 391:
#line 2255 "redtree.y"
    {
          (yyval.vars) = dyna_push();
        ;}
    break;

  case 392:
#line 2258 "redtree.y"
    {
          (yyval.num) = lpar_beg;
          lpar_beg = ++paren_nest;
        ;}
    break;

  case 393:
#line 2264 "redtree.y"
    {
          lpar_beg = (yyvsp[(2) - (4)].num);
          reduce_rule(lambda__f_larglist__lambda_body, 2);

          dyna_pop((yyvsp[(1) - (4)].vars));
        ;}
    break;

  case 394:
#line 2273 "redtree.y"
    {
          reduce_rule(f_larglist__LR__f_args__opt_bv_decl__rparen, 4);
        ;}
    break;

  case 395:
#line 2277 "redtree.y"
    {
          reduce_rule(f_larglist__f_args, 1);
        ;}
    break;

  case 396:
#line 2283 "redtree.y"
    {
          reduce_rule(lambda_body__tLAMBEG__compstmt__RC, 3);
        ;}
    break;

  case 397:
#line 2287 "redtree.y"
    {
          reduce_rule(lambda_body__keyword_do_LAMBDA__compstmt__keyword_end, 3);
        ;}
    break;

  case 398:
#line 2293 "redtree.y"
    {
          (yyvsp[(1) - (1)].vars) = dyna_push();
        ;}
    break;

  case 399:
#line 2299 "redtree.y"
    {
          reduce_rule(do_block__keyword_do_block__opt_block_param__compstmt__keyword_end, 4);

          dyna_pop((yyvsp[(1) - (5)].vars));
        ;}
    break;

  case 400:
#line 2307 "redtree.y"
    {
          reduce_rule(block_call__command__do_block, 2);
        ;}
    break;

  case 401:
#line 2311 "redtree.y"
    {
          reduce_rule(block_call__block_call__DOT__operation2__opt_paren_args, 4);
        ;}
    break;

  case 402:
#line 2315 "redtree.y"
    {
          reduce_rule(block_call__block_call__tCOLON2__operation2__opt_paren_args, 4);
        ;}
    break;

  case 403:
#line 2321 "redtree.y"
    {
          reduce_rule(method_call__operation__paren_args, 2);
        ;}
    break;

  case 404:
#line 2325 "redtree.y"
    {
          reduce_rule(method_call__primary_value__DOT__operation2__opt_paren_args, 4);
        ;}
    break;

  case 405:
#line 2329 "redtree.y"
    {
          reduce_rule(method_call__primary_value__tCOLON2__operation2__paren_args, 4);
        ;}
    break;

  case 406:
#line 2333 "redtree.y"
    {
          reduce_rule(method_call__primary_value__tCOLON2__operation3, 3);
        ;}
    break;

  case 407:
#line 2337 "redtree.y"
    {
          reduce_rule(method_call__primary_value__DOT__paren_args, 3);
        ;}
    break;

  case 408:
#line 2341 "redtree.y"
    {
          reduce_rule(method_call__primary_value__tCOLON2__paren_args, 3);
        ;}
    break;

  case 409:
#line 2345 "redtree.y"
    {
          reduce_rule(method_call__keyword_super__paren_args, 2);
        ;}
    break;

  case 410:
#line 2349 "redtree.y"
    {
          reduce_rule(method_call__keyword_super, 1);
        ;}
    break;

  case 411:
#line 2353 "redtree.y"
    {
          reduce_rule(method_call__primary_value__LS__opt_call_args__rbracket, 4);
        ;}
    break;

  case 412:
#line 2359 "redtree.y"
    {
          (yyvsp[(1) - (1)].vars) = dyna_push();
        ;}
    break;

  case 413:
#line 2364 "redtree.y"
    {
          reduce_rule(brace_block__LC__opt_block_param__compstmt__RC, 4);

          dyna_pop((yyvsp[(1) - (5)].vars));
        ;}
    break;

  case 414:
#line 2370 "redtree.y"
    {
          (yyvsp[(1) - (1)].vars) = dyna_push();
        ;}
    break;

  case 415:
#line 2375 "redtree.y"
    {
          reduce_rule(brace_block__keyword_do__opt_block_param__compstmt__keyword_end, 4);

          dyna_pop((yyvsp[(1) - (5)].vars));
        ;}
    break;

  case 416:
#line 2383 "redtree.y"
    {
          reduce_rule(case_body__keyword_when__args__then__compstmt__cases, 5);
        ;}
    break;

  case 417:
#line 2389 "redtree.y"
    {
          reduce_rule(cases__opt_else, 1);
        ;}
    break;

  case 418:
#line 2393 "redtree.y"
    {
          reduce_rule(cases__case_body, 1);
        ;}
    break;

  case 419:
#line 2399 "redtree.y"
    {
          reduce_rule(opt_rescue__keyword_rescue__exc_list__exc_var__then__compstmt__opt_rescue, 6);
        ;}
    break;

  case 420:
#line 2403 "redtree.y"
    {
          reduce_rule(opt_rescue__none, 1);
        ;}
    break;

  case 421:
#line 2409 "redtree.y"
    {
          reduce_rule(exc_list__arg_value, 1);
        ;}
    break;

  case 422:
#line 2413 "redtree.y"
    {
          reduce_rule(exc_list__mrhs, 1);
        ;}
    break;

  case 423:
#line 2417 "redtree.y"
    {
          reduce_rule(exc_list__none, 1);
        ;}
    break;

  case 424:
#line 2423 "redtree.y"
    {
          reduce_rule(exc_var__tASSOC__lhs, 2);
        ;}
    break;

  case 425:
#line 2427 "redtree.y"
    {
          reduce_rule(exc_var__none, 1);
        ;}
    break;

  case 426:
#line 2433 "redtree.y"
    {
          reduce_rule(opt_ensure__keyword_ensure__compstmt, 2);
        ;}
    break;

  case 427:
#line 2437 "redtree.y"
    {
          reduce_rule(opt_ensure__none, 1);
        ;}
    break;

  case 428:
#line 2443 "redtree.y"
    {
          reduce_rule(literal__numeric, 1);
        ;}
    break;

  case 429:
#line 2447 "redtree.y"
    {
          reduce_rule(literal__symbol, 1);
        ;}
    break;

  case 430:
#line 2451 "redtree.y"
    {
          reduce_rule(literal__dsym, 1);
        ;}
    break;

  case 431:
#line 2457 "redtree.y"
    {
          reduce_rule(strings__string, 1);
        ;}
    break;

  case 432:
#line 2463 "redtree.y"
    {
          reduce_rule(string__tCHAR, 1);
        ;}
    break;

  case 433:
#line 2467 "redtree.y"
    {
          reduce_rule(string__string1, 1);
        ;}
    break;

  case 434:
#line 2471 "redtree.y"
    {
          reduce_rule(string__string__string1, 2);
        ;}
    break;

  case 435:
#line 2477 "redtree.y"
    {
          reduce_rule(string1__tSTRING_BEG__string_contents__tSTRING_END, 3);
        ;}
    break;

  case 436:
#line 2483 "redtree.y"
    {
          reduce_rule(xstring__tXSTRING_BEG__xstring_contents__tSTRING_END, 3);
        ;}
    break;

  case 437:
#line 2489 "redtree.y"
    {
          reduce_rule(regexp__tREGEXP_BEG__regexp_contents__tREGEXP_END, 3);
        ;}
    break;

  case 438:
#line 2495 "redtree.y"
    {
          reduce_rule(words__tWORDS_BEG__SP__tSTRING_END, 3);
        ;}
    break;

  case 439:
#line 2499 "redtree.y"
    {
          reduce_rule(words__tWORDS_BEG__word_list__tSTRING_END, 3);
        ;}
    break;

  case 440:
#line 2505 "redtree.y"
    {
          reduce_rule(word_list__, 0);
        ;}
    break;

  case 441:
#line 2509 "redtree.y"
    {
          reduce_rule(word_list__word_list__word__SP, 3);
        ;}
    break;

  case 442:
#line 2515 "redtree.y"
    {
          reduce_rule(word__string_content, 1);
        ;}
    break;

  case 443:
#line 2519 "redtree.y"
    {
          reduce_rule(word__word__string_content, 2);
        ;}
    break;

  case 444:
#line 2525 "redtree.y"
    {
          reduce_rule(qwords__tQWORDS_BEG__SP__tSTRING_END, 3);
        ;}
    break;

  case 445:
#line 2529 "redtree.y"
    {
          reduce_rule(qwords__tQWORDS_BEG__qword_list__tSTRING_END, 3);
        ;}
    break;

  case 446:
#line 2535 "redtree.y"
    {
          reduce_rule(qword_list__, 0);
        ;}
    break;

  case 447:
#line 2539 "redtree.y"
    {
          reduce_rule(qword_list__qword_list__tSTRING_CONTENT__SP, 3);
        ;}
    break;

  case 448:
#line 2545 "redtree.y"
    {
          reduce_rule(string_contents__, 0);
        ;}
    break;

  case 449:
#line 2549 "redtree.y"
    {
          reduce_rule(string_contents__string_contents__string_content, 2);
        ;}
    break;

  case 450:
#line 2555 "redtree.y"
    {
          reduce_rule(xstring_contents__, 0);
        ;}
    break;

  case 451:
#line 2559 "redtree.y"
    {
          reduce_rule(xstring_contents__xstring_contents__string_content, 2);
        ;}
    break;

  case 452:
#line 2565 "redtree.y"
    {
          reduce_rule(regexp_contents__, 0);
        ;}
    break;

  case 453:
#line 2569 "redtree.y"
    {
          reduce_rule(regexp_contents__regexp_contents__string_content, 2);
        ;}
    break;

  case 454:
#line 2575 "redtree.y"
    {
          reduce_rule(string_content__tSTRING_CONTENT, 1);
        ;}
    break;

  case 455:
#line 2579 "redtree.y"
    {
          (yyval.node) = lex_strterm;
          lex_strterm = 0;
          lex_state = EXPR_BEG;
        ;}
    break;

  case 456:
#line 2585 "redtree.y"
    {
          lex_strterm = (yyvsp[(2) - (3)].node);
          reduce_rule(string_content__tSTRING_DVAR__string_dvar, 2);
        ;}
    break;

  case 457:
#line 2590 "redtree.y"
    {
          (yyvsp[(1) - (1)].val) = cond_stack;
          (yyval.val) = cmdarg_stack;
          cond_stack = 0;
          cmdarg_stack = 0;
        ;}
    break;

  case 458:
#line 2596 "redtree.y"
    {
          (yyval.node) = lex_strterm;
          lex_strterm = 0;
          lex_state = EXPR_BEG;
        ;}
    break;

  case 459:
#line 2602 "redtree.y"
    {
          cond_stack = (yyvsp[(1) - (5)].val);
          cmdarg_stack = (yyvsp[(2) - (5)].val);
          lex_strterm = (yyvsp[(3) - (5)].node);
          reduce_rule(string_content__tSTRING_DBEG__compstmt__RC, 3);
        ;}
    break;

  case 460:
#line 2611 "redtree.y"
    {
          reduce_rule(string_dvar__tGVAR, 1);
        ;}
    break;

  case 461:
#line 2615 "redtree.y"
    {
          reduce_rule(string_dvar__tIVAR, 1);
        ;}
    break;

  case 462:
#line 2619 "redtree.y"
    {
          reduce_rule(string_dvar__tCVAR, 1);
        ;}
    break;

  case 463:
#line 2623 "redtree.y"
    {
          reduce_rule(string_dvar__backref, 1);
        ;}
    break;

  case 464:
#line 2629 "redtree.y"
    {
          lex_state = EXPR_END;
          reduce_rule(symbol__tSYMBEG__sym, 2);
        ;}
    break;

  case 465:
#line 2636 "redtree.y"
    {
          reduce_rule(sym__fname, 1);
        ;}
    break;

  case 466:
#line 2640 "redtree.y"
    {
          reduce_rule(sym__tIVAR, 1);
        ;}
    break;

  case 467:
#line 2644 "redtree.y"
    {
          reduce_rule(sym__tGVAR, 1);
        ;}
    break;

  case 468:
#line 2648 "redtree.y"
    {
          reduce_rule(sym__tCVAR, 1);
        ;}
    break;

  case 469:
#line 2654 "redtree.y"
    {
          lex_state = EXPR_END;
          reduce_rule(dsym__tSYMBEG__xstring_contents__tSTRING_END, 3);
        ;}
    break;

  case 470:
#line 2661 "redtree.y"
    {
          reduce_rule(numeric__tINTEGER, 1);
        ;}
    break;

  case 471:
#line 2665 "redtree.y"
    {
          reduce_rule(numeric__tFLOAT, 1);
        ;}
    break;

  case 472:
#line 2669 "redtree.y"
    {
          reduce_rule(numeric__tUMINUS_NUM__tINTEGER, 2);
        ;}
    break;

  case 473:
#line 2673 "redtree.y"
    {
          reduce_rule(numeric__tUMINUS_NUM__tFLOAT, 2);
        ;}
    break;

  case 474:
#line 2679 "redtree.y"
    {
          reduce_rule(user_variable__tIDENTIFIER, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 475:
#line 2684 "redtree.y"
    {
          reduce_rule(user_variable__tIVAR, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 476:
#line 2689 "redtree.y"
    {
          reduce_rule(user_variable__tGVAR, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 477:
#line 2694 "redtree.y"
    {
          reduce_rule(user_variable__tCONSTANT, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 478:
#line 2699 "redtree.y"
    {
          reduce_rule(user_variable__tCVAR, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 479:
#line 2706 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_nil, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 480:
#line 2711 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_self, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 481:
#line 2716 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_true, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 482:
#line 2721 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_false, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 483:
#line 2726 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_FILE, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 484:
#line 2731 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_LINE, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 485:
#line 2736 "redtree.y"
    {
          reduce_rule(keyword_variable__keyword_ENCODING, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 486:
#line 2743 "redtree.y"
    {
          if (id_is_var(get_id((yyvsp[(1) - (1)].val)))) {
            reduce_rule(var_ref__user_variable, 1);
          }
          else {
            reduce_rule(vcall__user_variable, 1);
          }
        ;}
    break;

  case 487:
#line 2752 "redtree.y"
    {
          reduce_rule(var_ref__keyword_variable, 1);
        ;}
    break;

  case 488:
#line 2758 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(var_lhs__user_variable, 1);
        ;}
    break;

  case 489:
#line 2763 "redtree.y"
    {
          assignable((yyvsp[(1) - (1)].val), 0);
          reduce_rule(var_field__keyword_variable, 1);
        ;}
    break;

  case 490:
#line 2770 "redtree.y"
    {
          reduce_rule(backref__tNTH_REF, 1);
        ;}
    break;

  case 491:
#line 2774 "redtree.y"
    {
          reduce_rule(backref__tBACK_REF, 1);
        ;}
    break;

  case 492:
#line 2780 "redtree.y"
    {
          reduce_rule(superclass__term, 1);
        ;}
    break;

  case 493:
#line 2784 "redtree.y"
    {
          lex_state = EXPR_BEG;
        ;}
    break;

  case 494:
#line 2788 "redtree.y"
    {
          reduce_rule(superclass__LT__expr_value__term, 3);
        ;}
    break;

  case 495:
#line 2792 "redtree.y"
    {
          yyerrok;
          reduce_rule(superclass__error__term, 2);
        ;}
    break;

  case 496:
#line 2799 "redtree.y"
    {
          reduce_rule(f_arglist__LR__f_args__rparen, 3);

          lex_state = EXPR_BEG;
          command_start = TRUE;
        ;}
    break;

  case 497:
#line 2806 "redtree.y"
    {
          reduce_rule(f_arglist__f_args__term, 2);
        ;}
    break;

  case 498:
#line 2812 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 499:
#line 2816 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 8);
        ;}
    break;

  case 500:
#line 2820 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_optarg__opt_f_block_arg, 4);
        ;}
    break;

  case 501:
#line 2824 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_optarg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 502:
#line 2828 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_rest_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 503:
#line 2832 "redtree.y"
    {
          reduce_rule(f_args__f_arg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 504:
#line 2836 "redtree.y"
    {
          reduce_rule(f_args__f_arg__opt_f_block_arg, 2);
        ;}
    break;

  case 505:
#line 2840 "redtree.y"
    {
          reduce_rule(f_args__f_optarg__COMMA__f_rest_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 506:
#line 2844 "redtree.y"
    {
          reduce_rule(f_args__f_optarg__COMMA__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 6);
        ;}
    break;

  case 507:
#line 2848 "redtree.y"
    {
          reduce_rule(f_args__f_optarg__opt_f_block_arg, 2);
        ;}
    break;

  case 508:
#line 2852 "redtree.y"
    {
          reduce_rule(f_args__f_optarg__COMMA__f_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 509:
#line 2856 "redtree.y"
    {
          reduce_rule(f_args__f_rest_arg__opt_f_block_arg, 2);
        ;}
    break;

  case 510:
#line 2860 "redtree.y"
    {
          reduce_rule(f_args__f_rest_arg__COMMA__f_arg__opt_f_block_arg, 4);
        ;}
    break;

  case 511:
#line 2864 "redtree.y"
    {
          reduce_rule(f_args__f_block_arg, 1);
        ;}
    break;

  case 512:
#line 2868 "redtree.y"
    {
          reduce_rule(f_args__, 0);
        ;}
    break;

  case 513:
#line 2874 "redtree.y"
    {
          reduce_rule(f_bad_arg__tCONSTANT, 1);
        ;}
    break;

  case 514:
#line 2878 "redtree.y"
    {
          reduce_rule(f_bad_arg__tIVAR, 1);
        ;}
    break;

  case 515:
#line 2882 "redtree.y"
    {
          reduce_rule(f_bad_arg__tGVAR, 1);
        ;}
    break;

  case 516:
#line 2886 "redtree.y"
    {
          reduce_rule(f_bad_arg__tCVAR, 1);
        ;}
    break;

  case 517:
#line 2892 "redtree.y"
    {
          reduce_rule(f_norm_arg__f_bad_arg, 1);
        ;}
    break;

  case 518:
#line 2896 "redtree.y"
    {
          formal_argument(get_id((yyvsp[(1) - (1)].val)));
          reduce_rule(f_norm_arg__tIDENTIFIER, 1);
          (yyval.val) = (yyvsp[(1) - (1)].val);
        ;}
    break;

  case 519:
#line 2904 "redtree.y"
    {
          arg_var(get_id((yyvsp[(1) - (1)].val)));
          get_value((yyvsp[(1) - (1)].val));
          reduce_rule(f_arg_item__f_norm_arg, 1);
        ;}
    break;

  case 520:
#line 2910 "redtree.y"
    {
          ID tid = internal_id();
          arg_var(tid);

          reduce_rule(f_arg_item__tLPAREN__f_margs__rparen, 3);
        ;}
    break;

  case 521:
#line 2919 "redtree.y"
    {
          reduce_rule(f_arg__f_arg_item, 1);
        ;}
    break;

  case 522:
#line 2923 "redtree.y"
    {
          reduce_rule(f_arg__f_arg__COMMA__f_arg_item, 3);
        ;}
    break;

  case 523:
#line 2929 "redtree.y"
    {
          arg_var(formal_argument(get_id((yyvsp[(1) - (3)].val))));
          assignable((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
          reduce_rule(f_opt__tIDENTIFIER__EQ__arg_value, 3);
        ;}
    break;

  case 524:
#line 2937 "redtree.y"
    {
          arg_var(formal_argument(get_id((yyvsp[(1) - (3)].val))));
          assignable((yyvsp[(1) - (3)].val), (yyvsp[(3) - (3)].val));
          reduce_rule(f_block_opt__tIDENTIFIER__EQ__primary_value, 3);
        ;}
    break;

  case 525:
#line 2945 "redtree.y"
    {
          reduce_rule(f_block_optarg__f_block_opt, 1);
        ;}
    break;

  case 526:
#line 2949 "redtree.y"
    {
          reduce_rule(f_block_optarg__f_block_optarg__COMMA__f_block_opt, 3);
        ;}
    break;

  case 527:
#line 2955 "redtree.y"
    {
          reduce_rule(f_optarg__f_opt, 1);
        ;}
    break;

  case 528:
#line 2959 "redtree.y"
    {
          reduce_rule(f_optarg__f_optarg__COMMA__f_opt, 3);
        ;}
    break;

  case 529:
#line 2965 "redtree.y"
    {
          reduce_rule(restarg_mark__TIMES, 1);
        ;}
    break;

  case 530:
#line 2969 "redtree.y"
    {
          reduce_rule(restarg_mark__tSTAR, 1);
        ;}
    break;

  case 531:
#line 2975 "redtree.y"
    {
          arg_var(shadowing_lvar(get_id((yyvsp[(2) - (2)].val))));
          reduce_rule(f_rest_arg__restarg_mark__tIDENTIFIER, 2);
        ;}
    break;

  case 532:
#line 2980 "redtree.y"
    {
          reduce_rule(f_rest_arg__restarg_mark, 1);
        ;}
    break;

  case 533:
#line 2986 "redtree.y"
    {
          reduce_rule(blkarg_mark__AND, 1);
        ;}
    break;

  case 534:
#line 2990 "redtree.y"
    {
          reduce_rule(blkarg_mark__tAMPER, 1);
        ;}
    break;

  case 535:
#line 2996 "redtree.y"
    {
          arg_var(shadowing_lvar(get_id((yyvsp[(2) - (2)].val))));
          reduce_rule(f_block_arg__blkarg_mark__tIDENTIFIER, 2);
        ;}
    break;

  case 536:
#line 3003 "redtree.y"
    {
          reduce_rule(opt_f_block_arg__COMMA__f_block_arg, 2);
        ;}
    break;

  case 537:
#line 3007 "redtree.y"
    {
          reduce_rule(opt_f_block_arg__none, 1);
        ;}
    break;

  case 538:
#line 3013 "redtree.y"
    {
          reduce_rule(singleton__var_ref, 1);
        ;}
    break;

  case 539:
#line 3016 "redtree.y"
    {lex_state = EXPR_BEG;;}
    break;

  case 540:
#line 3017 "redtree.y"
    {
          reduce_rule(singleton__LR__expr__rparen, 3);
        ;}
    break;

  case 541:
#line 3023 "redtree.y"
    {
          reduce_rule(assoc_list__none, 1);
        ;}
    break;

  case 542:
#line 3027 "redtree.y"
    {
          reduce_rule(assoc_list__assocs__trailer, 2);
        ;}
    break;

  case 543:
#line 3033 "redtree.y"
    {
          reduce_rule(assocs__assoc, 1);
        ;}
    break;

  case 544:
#line 3037 "redtree.y"
    {
          reduce_rule(assocs__assocs__COMMA__assoc, 3);
        ;}
    break;

  case 545:
#line 3043 "redtree.y"
    {
          reduce_rule(assoc__arg_value__tASSOC__arg_value, 3);
        ;}
    break;

  case 546:
#line 3047 "redtree.y"
    {
          reduce_rule(assoc__tLABEL__arg_value, 2);
        ;}
    break;

  case 547:
#line 3053 "redtree.y"
    {
          reduce_rule(operation__tIDENTIFIER, 1);
        ;}
    break;

  case 548:
#line 3057 "redtree.y"
    {
          reduce_rule(operation__tCONSTANT, 1);
        ;}
    break;

  case 549:
#line 3061 "redtree.y"
    {
          reduce_rule(operation__tFID, 1);
        ;}
    break;

  case 550:
#line 3067 "redtree.y"
    {
          reduce_rule(operation2__tIDENTIFIER, 1);
        ;}
    break;

  case 551:
#line 3071 "redtree.y"
    {
          reduce_rule(operation2__tCONSTANT, 1);
        ;}
    break;

  case 552:
#line 3075 "redtree.y"
    {
          reduce_rule(operation2__tFID, 1);
        ;}
    break;

  case 553:
#line 3079 "redtree.y"
    {
          reduce_rule(operation2__op, 1);
        ;}
    break;

  case 554:
#line 3085 "redtree.y"
    {
          reduce_rule(operation3__tIDENTIFIER, 1);
        ;}
    break;

  case 555:
#line 3089 "redtree.y"
    {
          reduce_rule(operation3__tFID, 1);
        ;}
    break;

  case 556:
#line 3093 "redtree.y"
    {
          reduce_rule(operation3__op, 1);
        ;}
    break;

  case 557:
#line 3099 "redtree.y"
    {
          reduce_rule(dot_or_colon__DOT, 1);
        ;}
    break;

  case 558:
#line 3103 "redtree.y"
    {
          reduce_rule(dot_or_colon__tCOLON2, 1);
        ;}
    break;

  case 559:
#line 3109 "redtree.y"
    {
          reduce_rule(opt_terms__, 0);
        ;}
    break;

  case 560:
#line 3113 "redtree.y"
    {
          reduce_rule(opt_terms__terms, 1);
        ;}
    break;

  case 561:
#line 3119 "redtree.y"
    {
          reduce_rule(opt_nl__, 0);
        ;}
    break;

  case 562:
#line 3123 "redtree.y"
    {
          reduce_rule(opt_nl__NL, 1);
        ;}
    break;

  case 563:
#line 3129 "redtree.y"
    {
          reduce_rule(rparen__opt_nl__RR, 2);
        ;}
    break;

  case 564:
#line 3135 "redtree.y"
    {
          reduce_rule(rbracket__opt_nl__RS, 2);
        ;}
    break;

  case 565:
#line 3141 "redtree.y"
    {
          reduce_rule(trailer__, 0);
        ;}
    break;

  case 566:
#line 3145 "redtree.y"
    {
          reduce_rule(trailer__NL, 1);
        ;}
    break;

  case 567:
#line 3149 "redtree.y"
    {
          reduce_rule(trailer__COMMA, 1);
        ;}
    break;

  case 568:
#line 3155 "redtree.y"
    {
          yyerrok; reduce_rule(term__SEMI, 1);
        ;}
    break;

  case 569:
#line 3159 "redtree.y"
    {
          reduce_rule(term__NL, 1);
        ;}
    break;

  case 570:
#line 3165 "redtree.y"
    {
          reduce_rule(terms__term, 1);
        ;}
    break;

  case 571:
#line 3169 "redtree.y"
    {
          yyerrok;
          reduce_rule(terms__terms__SEMI, 2);
        ;}
    break;

  case 572:
#line 3176 "redtree.y"
    {
          reduce_rule(none__, 0);
        ;}
    break;


/* Line 1267 of yacc.c.  */
#line 8984 "ripper.c"
      default: break;
    }
  YY_SYMBOL_PRINT ("-> $$ =", yyr1[yyn], &yyval, &yyloc);

  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);

  *++yyvsp = yyval;


  /* Now `shift' the result of the reduction.  Determine what state
     that goes to, based on the state we popped back to and the rule
     number reduced by.  */

  yyn = yyr1[yyn];

  yystate = yypgoto[yyn - YYNTOKENS] + *yyssp;
  if (0 <= yystate && yystate <= YYLAST && yycheck[yystate] == *yyssp)
    yystate = yytable[yystate];
  else
    yystate = yydefgoto[yyn - YYNTOKENS];

  goto yynewstate;


/*------------------------------------.
| yyerrlab -- here on detecting error |
`------------------------------------*/
yyerrlab:
  /* If not already recovering from an error, report this error.  */
  if (!yyerrstatus)
    {
      ++yynerrs;
#if ! YYERROR_VERBOSE
      parser_yyerror (parser, YY_("syntax error"));
#else
      {
	YYSIZE_T yysize = yysyntax_error (0, yystate, yychar);
	if (yymsg_alloc < yysize && yymsg_alloc < YYSTACK_ALLOC_MAXIMUM)
	  {
	    YYSIZE_T yyalloc = 2 * yysize;
	    if (! (yysize <= yyalloc && yyalloc <= YYSTACK_ALLOC_MAXIMUM))
	      yyalloc = YYSTACK_ALLOC_MAXIMUM;
	    if (yymsg != yymsgbuf)
	      YYSTACK_FREE (yymsg);
	    yymsg = (char *) YYSTACK_ALLOC (yyalloc);
	    if (yymsg)
	      yymsg_alloc = yyalloc;
	    else
	      {
		yymsg = yymsgbuf;
		yymsg_alloc = sizeof yymsgbuf;
	      }
	  }

	if (0 < yysize && yysize <= yymsg_alloc)
	  {
	    (void) yysyntax_error (yymsg, yystate, yychar);
	    parser_yyerror (parser, yymsg);
	  }
	else
	  {
	    parser_yyerror (parser, YY_("syntax error"));
	    if (yysize != 0)
	      goto yyexhaustedlab;
	  }
      }
#endif
    }



  if (yyerrstatus == 3)
    {
      /* If just tried and failed to reuse look-ahead token after an
	 error, discard it.  */

      if (yychar <= YYEOF)
	{
	  /* Return failure if at end of input.  */
	  if (yychar == YYEOF)
	    YYABORT;
	}
      else
	{
	  yydestruct ("Error: discarding",
		      yytoken, &yylval, parser);
	  yychar = YYEMPTY;
	}
    }

  /* Else will try to reuse look-ahead token after shifting the error
     token.  */
  goto yyerrlab1;


/*---------------------------------------------------.
| yyerrorlab -- error raised explicitly by YYERROR.  |
`---------------------------------------------------*/
yyerrorlab:

  /* Pacify compilers like GCC when the user code never invokes
     YYERROR and the label yyerrorlab therefore never appears in user
     code.  */
  if (/*CONSTCOND*/ 0)
     goto yyerrorlab;

  /* Do not reclaim the symbols of the rule which action triggered
     this YYERROR.  */
  YYPOPSTACK (yylen);
  yylen = 0;
  YY_STACK_PRINT (yyss, yyssp);
  yystate = *yyssp;
  goto yyerrlab1;


/*-------------------------------------------------------------.
| yyerrlab1 -- common code for both syntax error and YYERROR.  |
`-------------------------------------------------------------*/
yyerrlab1:
  yyerrstatus = 3;	/* Each real token shifted decrements this.  */

  for (;;)
    {
      yyn = yypact[yystate];
      if (yyn != YYPACT_NINF)
	{
	  yyn += YYTERROR;
	  if (0 <= yyn && yyn <= YYLAST && yycheck[yyn] == YYTERROR)
	    {
	      yyn = yytable[yyn];
	      if (0 < yyn)
		break;
	    }
	}

      /* Pop the current state because it cannot handle the error token.  */
      if (yyssp == yyss)
	YYABORT;


      yydestruct ("Error: popping",
		  yystos[yystate], yyvsp, parser);
      YYPOPSTACK (1);
      yystate = *yyssp;
      YY_STACK_PRINT (yyss, yyssp);
    }

  if (yyn == YYFINAL)
    YYACCEPT;

  *++yyvsp = yylval;


  /* Shift the error token.  */
  YY_SYMBOL_PRINT ("Shifting", yystos[yyn], yyvsp, yylsp);

  yystate = yyn;
  goto yynewstate;


/*-------------------------------------.
| yyacceptlab -- YYACCEPT comes here.  |
`-------------------------------------*/
yyacceptlab:
  yyresult = 0;
  goto yyreturn;

/*-----------------------------------.
| yyabortlab -- YYABORT comes here.  |
`-----------------------------------*/
yyabortlab:
  yyresult = 1;
  goto yyreturn;

#ifndef yyoverflow
/*-------------------------------------------------.
| yyexhaustedlab -- memory exhaustion comes here.  |
`-------------------------------------------------*/
yyexhaustedlab:
  parser_yyerror (parser, YY_("memory exhausted"));
  yyresult = 2;
  /* Fall through.  */
#endif

yyreturn:
  if (yychar != YYEOF && yychar != YYEMPTY)
     yydestruct ("Cleanup: discarding lookahead",
		 yytoken, &yylval, parser);
  /* Do not reclaim the symbols of the rule which action triggered
     this YYABORT or YYACCEPT.  */
  YYPOPSTACK (yylen);
  YY_STACK_PRINT (yyss, yyssp);
  while (yyssp != yyss)
    {
      yydestruct ("Cleanup: popping",
		  yystos[*yyssp], yyvsp, parser);
      YYPOPSTACK (1);
    }
#ifndef yyoverflow
  if (yyss != yyssa)
    YYSTACK_FREE (yyss);
#endif
#if YYERROR_VERBOSE
  if (yymsg != yymsgbuf)
    YYSTACK_FREE (yymsg);
#endif
  /* Make sure YYID is used.  */
  return YYID (yyresult);
}


#line 3180 "redtree.y"

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
  // TODO(adgar): Into Lex Stream: redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
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
    // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tHEREDOC_BEG);
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
    if (!NIL_P(parser->delayed)) {
      // TODO(adgar): Into Lex Stream: redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
    }
    lex_goto_eol(parser);
    // TODO(adgar): Into Lex Stream: redtree_dispatch_ignored_scan_event(parser, tHEREDOC_END);
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
          // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tSTRING_CONTENT);
  }
  else {
          if (str ||
    ((len = lex_p - parser->tokp) > 0 &&
     (str = STR_NEW3(parser->tokp, len, enc, func), 1))) {
    rb_str_append(parser->delayed, str);
          }
          // TODO(adgar): Into Lex Stream: redtree_dispatch_delayed_token(parser, tSTRING_CONTENT);
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
  // reduce_rule(magic_comment, name, val); TODO(adgar): Insert into parse tree?
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

#define ambiguous_operator(op, syn)

#define warn_balanced(op, syn) ((void) \
    (last_state != EXPR_CLASS && last_state != EXPR_DOT && \
     last_state != EXPR_FNAME && last_state != EXPR_ENDFN && \
     last_state != EXPR_ENDARG && \
     space_seen && !ISSPACE(c) && \
     0))

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
  // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tSP);
  goto retry;

          case '#':   /* it's a comment */
  /* no magic_comment in shebang line */
  if (!parser_magic_comment(parser, lex_p, lex_pend - lex_p)) {
          if (comment_at_top(parser)) {
    set_file_encoding(parser, lex_p, lex_pend);
          }
  }
  lex_p = lex_pend;
        // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tCOMMENT);
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
                // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tIGNORED_NL);
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
                // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tEMBDOC_BEG);
    for (;;) {
        lex_goto_eol(parser);
                    if (!first_p) {
                        // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tEMBDOC);
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
                // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tEMBDOC_END);
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
          // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, tSP);
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
            // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, k__END__);
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

    redtree_lex_token(parser->parse_tree, t, 0, 0, 0, 0);
    if (!NIL_P(parser->delayed)) {
  // TODO(adgar): Into Lex Stream: redtree_dispatch_delayed_token(parser, t);
  return t;
    }
    if (t != 0) {
  // TODO(adgar): Into Lex Stream: redtree_dispatch_scan_event(parser, t);
    }
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
    parser->parse_tree = redtree_allocate();
    parser->redtree_stack = new_redtree_stack();
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

static const rb_data_type_t parser_data_type =  {"parser",
    parser_mark, parser_free, parser_memsize,
};

#define validate(x) ((x) = get_value(x))

static void redtree_reduce(struct parser_params *parser, int redtree_rule_num, int rhs_size) {
  // prepare pattern value
  int32_t pattern = 0;
  // look up size of rhs to pop from parser->redtree_stack
  // unsigned int rhs_size = yyr2[yyn];
  // pop from stack TODO(adgar): make volatile for speed
  int32_t* popped = redtree_stack_pop_n(parser, rhs_size);
  // for each on RHS
  while (rhs_size--) {
    int32_t val = *(popped + rhs_size);
    redtree_sequence_push(parser->parse_tree, *popped + rhs_size);
    pattern |= (0x3 & (val < 0));
  }
  redtree_sequence_push(parser->parse_tree, pattern);
  redtree_sequence_push(parser->parse_tree, -redtree_rule_num);
  redtree_stack_push(parser, -redtree_rule_num);
}

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
    redtree_init_struct(parser->parse_tree, src);

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

/*
 *  call-seq:
 *    redtree.yydebug   -> true or false
 *
 *  Get yydebug.
 */
VALUE
rb_parser_get_yydebug(VALUE self)
{
    struct parser_params *parser;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    return yydebug ? Qtrue : Qfalse;
}

/*
 *  call-seq:
 *    redtree.yydebug = flag
 *
 *  Set yydebug.
 */
VALUE
rb_parser_set_yydebug(VALUE self, VALUE flag)
{
    struct parser_params *parser;

    TypedData_Get_Struct(self, struct parser_params, &parser_data_type, parser);
    yydebug = RTEST(flag);
    return flag;
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
    /* ensure existing in symbol table */
    (void)rb_intern("||");
    (void)rb_intern("&&");
}

