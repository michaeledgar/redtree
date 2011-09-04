#!/bin/sed -f
/\/\* Shift the look-ahead token.  \*\//{
a\
  redtree_stack_push(parser, yytoken);
}