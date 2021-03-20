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
        a->testOut();
        b->testOut();
        perimeter.testOut();
    }

    EO_any* copy() {
        EO_rectangle* tmp = new EO_rectangle{a, b};
        return tmp;
    }

    // Вычисление периметра, опирающееся на данные в прямоугольнике
    struct EO_perimeter: EO_any  {
        explicit EO_perimeter(EO_any* c = &empty): coefficient{c} {}
        EO_rectangle* parent;
        // Дополнительный параметр, играющий роль коэффициента
        EO_any* coefficient;

        virtual EO_any* eval();
        virtual bool set(EO_any* arg, int index) {
            EO_empty* c = dynamic_cast<EO_empty*>(coefficient);
            if(index == 0 && c != nullptr) {
                coefficient = arg;
                return true;
            }
            std::cout << "Set method: Incorrect using of Immutable Attribute!!!\n";
            exit(2);
            return false;
        }

        // получение имени объекта (пока для тестирования)
        virtual const char* getTypeName() { return "EO_perimeter"; }
        // вывод тестовой информации об объекте
        virtual void testOut() {
            EO_any::testOut();
            std::cout << "  Attribute: coefficient\n";
            coefficient->testOut();
        }
    } perimeter;
};

// Класс треугольника, используемый для тестирования подхода
struct EO_triangle: EO_any {
    explicit EO_triangle(EO_any *arg1, EO_any *arg2, EO_any *arg3);
    EO_any *a, *b, *c;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_triangle"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b, c are EO_any*"
                  << "\n";
        a->testOut();
        b->testOut();
        c->testOut();
        perimeter.testOut();
    }

    EO_any* copy() {
        EO_triangle* tmp = new EO_triangle{a, b, c};
        return tmp;
    }

    // Вычисление периметра, опирающееся на данные в треугольнике
    struct EO_perimeter: EO_any  {
        explicit EO_perimeter(EO_any* c = &empty): coefficient{c} {}
        EO_triangle* parent;
        EO_any* coefficient;

        virtual EO_any* eval();
        virtual bool set(EO_any* arg, int index) {
            EO_empty* c = dynamic_cast<EO_empty*>(coefficient);
            if(index == 0 && c != nullptr) {
                coefficient = arg;
                return true;
            }
            std::cout << "Set method: Incorrect using of Immutable Attribute!!!\n";
            exit(2);
            return false;
        }

        // получение имени объекта (пока для тестирования)
        virtual const char* getTypeName() { return "EO_perimeter"; }
        // вывод тестовой информации об объекте
        virtual void testOut() {
            EO_any::testOut();
            std::cout << "  Attribute [" << coefficient <<"]"
                      << "\n";
        }
    } perimeter;
};

#endif // __newobjects__
