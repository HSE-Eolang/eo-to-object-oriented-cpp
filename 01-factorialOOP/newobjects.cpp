#include "newobjects.h"

EO_factorial::EO_factorial(EO_any* v): value{v} {}

EO_any* EO_factorial::eval() {
    // Предварительный запрос на вычисление аргумента
    value->eval();
    
    auto result = new EO_if(new EO_lt(value, new EO_int(2)), 
            value,
            new EO_mul(new EO_factorial(new EO_sub(value, new EO_int(1))),
                        value
            )
    );
    return result->eval();
}
