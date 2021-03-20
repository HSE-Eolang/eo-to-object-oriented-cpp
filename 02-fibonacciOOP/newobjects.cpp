#include "newobjects.h"

/*
#[n] > fibo
#  if. > @
#    less. n 2
#    n
#    add.
#      fibo (sub. n 1)
#      fibo (sub. n 2)

[n] > fibo
  (n.less 2).if > @
    n
    ((fibo (n.sub 1)).add (fibo (n.sub 2)))
*/

EO_fibonacci::EO_fibonacci(EO_any* v): value{v} {}

EO_any* EO_fibonacci::eval() {
    // Предварительный запрос на вычисление аргумента
    value->eval();
    auto result = new EO_if(new EO_lt(value, new EO_int(2)), 
            value,
            new EO_add(new EO_fibonacci(new EO_sub(value, new EO_int(1))),
                       new EO_fibonacci(new EO_sub(value, new EO_int(2)))
            )
    );
    return result->eval();
}
