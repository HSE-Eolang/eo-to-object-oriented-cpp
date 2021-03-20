#ifndef __newobjects__
#define __newobjects__


#include "baseobjects.h"

// Класс прямоугольника, используемый для тестирования подхода
struct EO_rectangle: EO_any {
    explicit EO_rectangle(EO_any *arg1, EO_any *arg2);
    EO_any *a, *b;

    virtual EO_any* eval() { return this; }

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_rectangle"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
        perimeter.testOut();
    }

    EO_any* copy() {
        EO_rectangle* tmp = new EO_rectangle{a, b};
        return tmp;
    }

    // Вычисление периметра, опирающееся на данные в прямоугольнике
    struct EO_perimeter: EO_any  {
        explicit EO_perimeter() {}
        EO_rectangle* parent;

        virtual EO_any* eval();

        // получение имени объекта (пока для тестирования)
        virtual const char* getTypeName() { return "EO_rectangle_perimeter"; }
        // вывод тестовой информации об объекте
        virtual void testOut() {
            EO_any::testOut();
            std::cout << "  Attributes are absent"
                      << "\n";
        }
    } perimeter;
};

#endif // __newobjects__
