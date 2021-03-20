#ifndef __newobjects__
#define __newobjects__

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

#include "baseobjects.h"

// Класс, описывающий объект-функцию, вычисляющую число Фибоначчи
struct EO_fibonacci: EO_any {
    explicit EO_fibonacci(EO_any *v);
    EO_any *value;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_fibonacci"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attribute value is EO_any*"
                  << "\n";
        if(value != nullptr) { value->testOut(); }
    }
};

#endif // __newobjects__
