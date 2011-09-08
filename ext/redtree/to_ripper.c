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

// VALUE rb_cRedtreeRipper;
struct redtree_ripper {
  struct redtree* tree;
};

static void
redtree_ripper_mark(void *ptr)
{
  struct redtree_ripper* node = (struct redtree_ripper*)ptr;
  tree_mark(node->tree);
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
	struct redtree *tree_ptr;
  TypedData_Get_Struct(tree, struct redtree, &tree_data_type, tree_ptr);
  struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  ripper_ptr->tree = tree_ptr;
  return Qnil;
}

VALUE redtree_ripper_parse(VALUE self) {
	struct redtree_ripper *ripper_ptr;
  TypedData_Get_Struct(self, struct redtree_ripper, &redtree_ripper_data_type, ripper_ptr);
  return redtree_ripper_walk(self, ripper_ptr->tree, ripper_ptr->tree->sequence_count - 1);  // root node
}

#define ARG1  (redtree_ripper_walk(self, tree, index-2))
#define ARG2  (redtree_ripper_walk(self, tree, index-3))
#define ARG3  (redtree_ripper_walk(self, tree, index-4))
#define ARG4  (redtree_ripper_walk(self, tree, index-5))
#define ARG5  (redtree_ripper_walk(self, tree, index-6))
#define ARG6  (redtree_ripper_walk(self, tree, index-7))
#define ARG7  (redtree_ripper_walk(self, tree, index-8))
#define ARG8  (redtree_ripper_walk(self, tree, index-9))
#define ARG9  (redtree_ripper_walk(self, tree, index-10))
#define ARG10 (redtree_ripper_walk(self, tree, index-11))
#define ARG11 (redtree_ripper_walk(self, tree, index-12))
#define ARG12 (redtree_ripper_walk(self, tree, index-13))
#define ARG13 (redtree_ripper_walk(self, tree, index-14))

VALUE redtree_ripper_walk(VALUE self, struct redtree* tree, uint32_t index) {
	redtree_sequence_entry entry = tree->sequence[index];
	if (entry > 0) {
		// grab line, index into it
		struct token_location location = tree->token_locations[index];
		VALUE line = tree->lines[location.start_line - 1];
		VALUE str = STR_NEW(RSTRING_PTR(line) + location.start_col, location.size);
		return ripper_dispatch1(self, redtree_token2eventid(tree->tokens[index]), str);
	} else {
		// production (rule)
		if (0) {  // to test ripperids.c generation
			return dispatch2(stmts_add, dispatch0(stmts_new), ARG1);
		}
	}
}

#undef ARG1 
#undef ARG2 
#undef ARG3 
#undef ARG4 
#undef ARG5 
#undef ARG6 
#undef ARG7 
#undef ARG8 
#undef ARG9 
#undef ARG10
#undef ARG11
#undef ARG12
#undef ARG13

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
    validate(a);
    return rb_funcall(walker, mid, 1, a);
}

static VALUE
ripper_dispatch2(VALUE walker, ID mid, VALUE a, VALUE b)
{
    validate(a);
    validate(b);
    return rb_funcall(walker, mid, 2, a, b);
}

static VALUE
ripper_dispatch3(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c)
{
    validate(a);
    validate(b);
    validate(c);
    return rb_funcall(walker, mid, 3, a, b, c);
}

static VALUE
ripper_dispatch4(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c, VALUE d)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    return rb_funcall(walker, mid, 4, a, b, c, d);
}

static VALUE
ripper_dispatch5(VALUE walker, ID mid, VALUE a, VALUE b, VALUE c, VALUE d, VALUE e)
{
    validate(a);
    validate(b);
    validate(c);
    validate(d);
    validate(e);
    return rb_funcall(walker, mid, 5, a, b, c, d, e);
}