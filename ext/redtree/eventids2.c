#define tIGNORED_NL      (tLAST_TOKEN + 1)
#define tCOMMENT         (tLAST_TOKEN + 2)
#define tEMBDOC_BEG      (tLAST_TOKEN + 3)
#define tEMBDOC          (tLAST_TOKEN + 4)
#define tEMBDOC_END      (tLAST_TOKEN + 5)
#define tSP              (tLAST_TOKEN + 6)
#define tHEREDOC_BEG     (tLAST_TOKEN + 7)
#define tHEREDOC_END     (tLAST_TOKEN + 8)
#define k__END__         (tLAST_TOKEN + 9)

static ID redtree_id_backref;
static ID redtree_id_backtick;
static ID redtree_id_comma;
static ID redtree_id_const;
static ID redtree_id_cvar;
static ID redtree_id_embexpr_beg;
static ID redtree_id_embexpr_end;
static ID redtree_id_embvar;
static ID redtree_id_float;
static ID redtree_id_gvar;
static ID redtree_id_ident;
static ID redtree_id_int;
static ID redtree_id_ivar;
static ID redtree_id_kw;
static ID redtree_id_lbrace;
static ID redtree_id_lbracket;
static ID redtree_id_lparen;
static ID redtree_id_nl;
static ID redtree_id_op;
static ID redtree_id_period;
static ID redtree_id_rbrace;
static ID redtree_id_rbracket;
static ID redtree_id_rparen;
static ID redtree_id_semicolon;
static ID redtree_id_symbeg;
static ID redtree_id_tstring_beg;
static ID redtree_id_tstring_content;
static ID redtree_id_tstring_end;
static ID redtree_id_words_beg;
static ID redtree_id_qwords_beg;
static ID redtree_id_words_sep;
static ID redtree_id_regexp_beg;
static ID redtree_id_regexp_end;
static ID redtree_id_label;
static ID redtree_id_tlambda;
static ID redtree_id_tlambeg;

static ID redtree_id_ignored_nl;
static ID redtree_id_comment;
static ID redtree_id_embdoc_beg;
static ID redtree_id_embdoc;
static ID redtree_id_embdoc_end;
static ID redtree_id_sp;
static ID redtree_id_heredoc_beg;
static ID redtree_id_heredoc_end;
static ID redtree_id___end__;
static ID redtree_id_CHAR;

#include "eventids2table.c"

static void
redtree_init_eventids2(VALUE self)
{
    redtree_id_backref = rb_intern_const("on_backref");
    redtree_id_backtick = rb_intern_const("on_backtick");
    redtree_id_comma = rb_intern_const("on_comma");
    redtree_id_const = rb_intern_const("on_const");
    redtree_id_cvar = rb_intern_const("on_cvar");
    redtree_id_embexpr_beg = rb_intern_const("on_embexpr_beg");
    redtree_id_embexpr_end = rb_intern_const("on_embexpr_end");
    redtree_id_embvar = rb_intern_const("on_embvar");
    redtree_id_float = rb_intern_const("on_float");
    redtree_id_gvar = rb_intern_const("on_gvar");
    redtree_id_ident = rb_intern_const("on_ident");
    redtree_id_int = rb_intern_const("on_int");
    redtree_id_ivar = rb_intern_const("on_ivar");
    redtree_id_kw = rb_intern_const("on_kw");
    redtree_id_lbrace = rb_intern_const("on_lbrace");
    redtree_id_lbracket = rb_intern_const("on_lbracket");
    redtree_id_lparen = rb_intern_const("on_lparen");
    redtree_id_nl = rb_intern_const("on_nl");
    redtree_id_op = rb_intern_const("on_op");
    redtree_id_period = rb_intern_const("on_period");
    redtree_id_rbrace = rb_intern_const("on_rbrace");
    redtree_id_rbracket = rb_intern_const("on_rbracket");
    redtree_id_rparen = rb_intern_const("on_rparen");
    redtree_id_semicolon = rb_intern_const("on_semicolon");
    redtree_id_symbeg = rb_intern_const("on_symbeg");
    redtree_id_tstring_beg = rb_intern_const("on_tstring_beg");
    redtree_id_tstring_content = rb_intern_const("on_tstring_content");
    redtree_id_tstring_end = rb_intern_const("on_tstring_end");
    redtree_id_words_beg = rb_intern_const("on_words_beg");
    redtree_id_qwords_beg = rb_intern_const("on_qwords_beg");
    redtree_id_words_sep = rb_intern_const("on_words_sep");
    redtree_id_regexp_beg = rb_intern_const("on_regexp_beg");
    redtree_id_regexp_end = rb_intern_const("on_regexp_end");
    redtree_id_label = rb_intern_const("on_label");
    redtree_id_tlambda = rb_intern_const("on_tlambda");
    redtree_id_tlambeg = rb_intern_const("on_tlambeg");

    redtree_id_ignored_nl = rb_intern_const("on_ignored_nl");
    redtree_id_comment = rb_intern_const("on_comment");
    redtree_id_embdoc_beg = rb_intern_const("on_embdoc_beg");
    redtree_id_embdoc = rb_intern_const("on_embdoc");
    redtree_id_embdoc_end = rb_intern_const("on_embdoc_end");
    redtree_id_sp = rb_intern_const("on_sp");
    redtree_id_heredoc_beg = rb_intern_const("on_heredoc_beg");
    redtree_id_heredoc_end = rb_intern_const("on_heredoc_end");
    redtree_id___end__ = rb_intern_const("on___end__");
    redtree_id_CHAR = rb_intern_const("on_CHAR");

    redtree_init_eventids2_table(self);
}

static const struct token_assoc {
    int token;
    ID *id;
} token_to_eventid[] = {
    {' ',		&redtree_id_words_sep},
    {'!',		&redtree_id_op},
    {'%',		&redtree_id_op},
    {'&',		&redtree_id_op},
    {'*',		&redtree_id_op},
    {'+',		&redtree_id_op},
    {'-',		&redtree_id_op},
    {'/',		&redtree_id_op},
    {'<',		&redtree_id_op},
    {'=',		&redtree_id_op},
    {'>',		&redtree_id_op},
    {'?',		&redtree_id_op},
    {'^',		&redtree_id_op},
    {'|',		&redtree_id_op},
    {'~',		&redtree_id_op},
    {':',		&redtree_id_op},
    {',',		&redtree_id_comma},
    {'.',		&redtree_id_period},
    {';',		&redtree_id_semicolon},
    {'`',		&redtree_id_backtick},
    {'\n',              &redtree_id_nl},
    {keyword_alias,	&redtree_id_kw},
    {keyword_and,	&redtree_id_kw},
    {keyword_begin,	&redtree_id_kw},
    {keyword_break,	&redtree_id_kw},
    {keyword_case,	&redtree_id_kw},
    {keyword_class,	&redtree_id_kw},
    {keyword_def,	&redtree_id_kw},
    {keyword_defined,	&redtree_id_kw},
    {keyword_do,	&redtree_id_kw},
    {keyword_do_block,	&redtree_id_kw},
    {keyword_do_cond,	&redtree_id_kw},
    {keyword_else,	&redtree_id_kw},
    {keyword_elsif,	&redtree_id_kw},
    {keyword_end,	&redtree_id_kw},
    {keyword_ensure,	&redtree_id_kw},
    {keyword_false,	&redtree_id_kw},
    {keyword_for,	&redtree_id_kw},
    {keyword_if,	&redtree_id_kw},
    {modifier_if,	&redtree_id_kw},
    {keyword_in,	&redtree_id_kw},
    {keyword_module,	&redtree_id_kw},
    {keyword_next,	&redtree_id_kw},
    {keyword_nil,	&redtree_id_kw},
    {keyword_not,	&redtree_id_kw},
    {keyword_or,	&redtree_id_kw},
    {keyword_redo,	&redtree_id_kw},
    {keyword_rescue,	&redtree_id_kw},
    {modifier_rescue,	&redtree_id_kw},
    {keyword_retry,	&redtree_id_kw},
    {keyword_return,	&redtree_id_kw},
    {keyword_self,	&redtree_id_kw},
    {keyword_super,	&redtree_id_kw},
    {keyword_then,	&redtree_id_kw},
    {keyword_true,	&redtree_id_kw},
    {keyword_undef,	&redtree_id_kw},
    {keyword_unless,	&redtree_id_kw},
    {modifier_unless,	&redtree_id_kw},
    {keyword_until,	&redtree_id_kw},
    {modifier_until,	&redtree_id_kw},
    {keyword_when,	&redtree_id_kw},
    {keyword_while,	&redtree_id_kw},
    {modifier_while,	&redtree_id_kw},
    {keyword_yield,	&redtree_id_kw},
    {keyword__FILE__,	&redtree_id_kw},
    {keyword__LINE__,	&redtree_id_kw},
    {keyword__ENCODING__, &redtree_id_kw},
    {keyword_BEGIN,	&redtree_id_kw},
    {keyword_END,	&redtree_id_kw},
    {keyword_do_LAMBDA,	&redtree_id_kw},
    {tAMPER,		&redtree_id_op},
    {tANDOP,		&redtree_id_op},
    {tAREF,		&redtree_id_op},
    {tASET,		&redtree_id_op},
    {tASSOC,		&redtree_id_op},
    {tBACK_REF,		&redtree_id_backref},
    {tCHAR,		&redtree_id_CHAR},
    {tCMP,		&redtree_id_op},
    {tCOLON2,		&redtree_id_op},
    {tCOLON3,		&redtree_id_op},
    {tCONSTANT,		&redtree_id_const},
    {tCVAR,		&redtree_id_cvar},
    {tDOT2,		&redtree_id_op},
    {tDOT3,		&redtree_id_op},
    {tEQ,		&redtree_id_op},
    {tEQQ,		&redtree_id_op},
    {tFID,		&redtree_id_ident},
    {tFLOAT,		&redtree_id_float},
    {tGEQ,		&redtree_id_op},
    {tGVAR,		&redtree_id_gvar},
    {tIDENTIFIER,	&redtree_id_ident},
    {tINTEGER,		&redtree_id_int},
    {tIVAR,		&redtree_id_ivar},
    {tLBRACE,		&redtree_id_lbrace},
    {tLBRACE_ARG,	&redtree_id_lbrace},
    {'{',       	&redtree_id_lbrace},
    {'}',       	&redtree_id_rbrace},
    {tLBRACK,		&redtree_id_lbracket},
    {'[',       	&redtree_id_lbracket},
    {']',       	&redtree_id_rbracket},
    {tLEQ,		&redtree_id_op},
    {tLPAREN,		&redtree_id_lparen},
    {tLPAREN_ARG,	&redtree_id_lparen},
    {'(',		&redtree_id_lparen},
    {')',		&redtree_id_rparen},
    {tLSHFT,		&redtree_id_op},
    {tMATCH,		&redtree_id_op},
    {tNEQ,		&redtree_id_op},
    {tNMATCH,		&redtree_id_op},
    {tNTH_REF,		&redtree_id_backref},
    {tOP_ASGN,		&redtree_id_op},
    {tOROP,		&redtree_id_op},
    {tPOW,		&redtree_id_op},
    {tQWORDS_BEG,	&redtree_id_qwords_beg},
    {tREGEXP_BEG,	&redtree_id_regexp_beg},
    {tREGEXP_END,	&redtree_id_regexp_end},
    {tRPAREN,		&redtree_id_rparen},
    {tRSHFT,		&redtree_id_op},
    {tSTAR,		&redtree_id_op},
    {tSTRING_BEG,	&redtree_id_tstring_beg},
    {tSTRING_CONTENT,	&redtree_id_tstring_content},
    {tSTRING_DBEG,	&redtree_id_embexpr_beg},
    {tSTRING_DVAR,	&redtree_id_embvar},
    {tSTRING_END,	&redtree_id_tstring_end},
    {tSYMBEG,		&redtree_id_symbeg},
    {tUMINUS,		&redtree_id_op},
    {tUMINUS_NUM,	&redtree_id_op},
    {tUPLUS,		&redtree_id_op},
    {tWORDS_BEG,	&redtree_id_words_beg},
    {tXSTRING_BEG,	&redtree_id_backtick},
    {tLABEL,		&redtree_id_label},
    {tLAMBDA,		&redtree_id_tlambda},
    {tLAMBEG,		&redtree_id_tlambeg},

    /* redtree specific tokens */
    {tIGNORED_NL,       &redtree_id_ignored_nl},
    {tCOMMENT,          &redtree_id_comment},
    {tEMBDOC_BEG,       &redtree_id_embdoc_beg},
    {tEMBDOC,           &redtree_id_embdoc},
    {tEMBDOC_END,       &redtree_id_embdoc_end},
    {tSP,               &redtree_id_sp},
    {tHEREDOC_BEG,      &redtree_id_heredoc_beg},
    {tHEREDOC_END,      &redtree_id_heredoc_end},
    {k__END__,          &redtree_id___end__},
    {0, NULL}
};

static ID
redtree_token2eventid(int tok)
{
    const struct token_assoc *a;

    for (a = token_to_eventid; a->id != NULL; a++) {
        if (a->token == tok)
            return *a->id;
    }
    if (tok < 256) {
        return redtree_id_CHAR;
    }
    rb_raise(rb_eRuntimeError, "[Ripper FATAL] unknown token %d", tok);
}
