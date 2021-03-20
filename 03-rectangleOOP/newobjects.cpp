#include "newobjects.h"

EO_any* EO_rectangle::EO_perimeter::eval() {
    auto aa = (parent->a)->eval();
    auto bb = (parent->b)->eval();
    auto resut = new EO_mul(new EO_int(2), new EO_add(aa, bb));
    return resut->eval();
}

EO_rectangle::EO_rectangle(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {
    perimeter.parent = this;
}
