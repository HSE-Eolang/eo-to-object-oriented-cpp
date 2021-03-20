#ifndef __newobjects__
#define __newobjects__


#include "baseobjects.h"

// Класс, описывающий объект-функцию, вычисляющую факториал
struct EO_factorial: EO_any {
    explicit EO_factorial(EO_any *v);
    EO_any *value;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_factorial"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attribute value is EO_any*"
                  << "\n";
        if(value != nullptr) { value->testOut(); }
    }
};

#endif // __newobjects__
