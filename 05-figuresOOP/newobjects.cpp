#include "newobjects.h"

EO_any* EO_rectangle::EO_perimeter::eval() {
    auto aa = (parent->a)->eval();
    auto bb = (parent->b)->eval();
    auto resut = new EO_mul(new EO_mul(new EO_int(2), new EO_add(aa, bb)), coefficient);
    return resut->eval();
}

EO_rectangle::EO_rectangle(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {
    perimeter.parent = this;
}

//==============================================================================

EO_any* EO_triangle::EO_perimeter::eval() {
    auto aa = (parent->a)->eval();
    auto bb = (parent->b)->eval();
    auto cc = (parent->c)->eval();
    auto resut = new EO_mul(new EO_add(cc, new EO_add(aa, bb)), coefficient);
    return resut->eval();
}

EO_triangle::EO_triangle(EO_any *arg1, EO_any *arg2, EO_any *arg3): a{arg1}, b{arg2}, c{arg3} {
    perimeter.parent = this;
}

EO_any* EO_triangle::eval() { return this; }

