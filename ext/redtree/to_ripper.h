#ifndef CARBONICA_REDTREE_TO_RIPPER_H_
#define CARBONICA_REDTREE_TO_RIPPER_H_

VALUE rb_cRedtreeRipper;

VALUE redtree_ripper_allocate(VALUE klass);
VALUE redtree_ripper_initialize(VALUE self, VALUE tree);
VALUE redtree_ripper_parse(VALUE self);

#endif  // CARBONICA_REDTREE_TO_RIPPER_H_