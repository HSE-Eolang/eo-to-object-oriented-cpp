#ifndef __baseobjects__
#define __baseobjects__

#include "any.h"

//----------------------------------------------------------------------
// Предопределенный класс, описывающий пустой объект
// Данный объект заменяет пустой указатель, и при попытке вычислить его
// порождает ошибку с завершением программы.
// На все программы достаточно одного пустого объекта.
//--------------------------------------------
// A predefined runtime class that represents an empty object.
// Causes a runtime error resulting in the halt of the program once it is
// asked to evaluate itself. Implements η (eta) from the φ-calculus.
struct EO_empty : EO_any {
    explicit EO_empty() {
        message = "No special message";
    }

    const char *message;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval() {
        std::cout << "EO_empty: " << message << "\n";
        std::cout << "Dynamic evaluation error! The empty object cannot be evaluated!\n";
        exit(1);
        return this;
    }

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_empty"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  It is the Empty object\n";
    }
};

extern EO_empty empty;

//-------------------------------------------------------------------
// Предопределенный класс, описывающий атомарный целочисленный объект
//--------------------------------------------
// A predefined runtime class that represents an integer atomic numeral
struct EO_int : EO_any {
    explicit EO_int(int v) : value{v} {}

    // хранимое значение
    //-------------------------------------
    // the encapsulated value
    int value;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval() { return this; }

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_int"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: [" << value << "]"
                  << "\n";
    }
};

//----------------------------------------------------------------
// Предопределенный класс, описывающий атомарный булевский объект
//--------------------------------------------
// A predefined runtime class that represents an atomic boolean value
struct EO_bool : EO_any {
    explicit EO_bool(bool v) : value{v} {}

    // хранимое значение
    //-------------------------------------
    // the encapsulated value
    bool value;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval() { return this; }

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_bool"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::string str = value ? "true" : "false";
        std::cout << "  Attributes: [" << str << "]"
                  << "\n";
    }
};

//-----------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сложения
//--------------------------------------------
// A predefined runtime class that represents the sum operation on two objects
struct EO_add : EO_any {
    explicit EO_add(EO_any *arg1, EO_any *arg2) : a{arg1}, b{arg2} {}

    // атрибуты объекта-сложения
    //-------------------------------------
    // the free attributes of the sum object
    EO_any *a, *b;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_add"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if (a != nullptr) { a->testOut(); }
        if (b != nullptr) { b->testOut(); }
    }
};

//-------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию вычитания
//--------------------------------------------
// A predefined runtime class that represents the subtraction operation on two objects
struct EO_sub : EO_any {
    explicit EO_sub(EO_any *arg1, EO_any *arg2) : a{arg1}, b{arg2} {}

    // атрибуты объекта-вычитания
    //-------------------------------------
    // the free attributes of the subtraction object
    EO_any *a, *b;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_sub"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if (a != nullptr) { a->testOut(); }
        if (b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию умножения
//--------------------------------------------
// A predefined runtime class that represents the multiplication operation on two objects
struct EO_mul : EO_any {
    explicit EO_mul(EO_any *arg1, EO_any *arg2) : a{arg1}, b{arg2} {}

    // атрибуты объекта-умножения
    //-------------------------------------
    // the free attributes of the multiplication object
    EO_any *a, *b;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_mul"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if (a != nullptr) { a->testOut(); }
        if (b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сравнения "меньше"
//--------------------------------------------
// A predefined runtime class that represents the comparison 'less than' on two objects
struct EO_lt : EO_any {
    explicit EO_lt(EO_any *arg1, EO_any *arg2) : a{arg1}, b{arg2} {}

    // атрибуты объекта-меньше
    //-------------------------------------
    // the free attributes of the 'less than' object
    EO_any *a, *b;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_lt"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if (a != nullptr) { a->testOut(); }
        if (b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сравнения "меньше или равно"
//--------------------------------------------
// A predefined runtime class that represents the comparison 'less than or equal to' on two objects
struct EO_le : EO_any {
    explicit EO_le(EO_any *arg1, EO_any *arg2) : a{arg1}, b{arg2} {}

    // атрибуты объекта
    //-------------------------------------
    // the free attributes of the 'less than or equal to' object
    EO_any *a, *b;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_le"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if (a != nullptr) { a->testOut(); }
        if (b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий условный оператор
//--------------------------------------------
// A predefined runtime class that represents the conditional 'if'/ternary operator
struct EO_if : EO_any {
    explicit EO_if(EO_any *argCond, EO_any *argTrueBranch, EO_any *argFalseBranch)
            : cond{argCond}, trueBranch{argTrueBranch}, falseBranch{argFalseBranch} {}

    // атрибуты объекта
    //-------------------------------------
    // the free attributes of the 'if' object
    EO_any *cond, *trueBranch, *falseBranch;

    // метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval();

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object
    // (in other words, the type of the object) (for testing purposes)
    virtual const char *getTypeName() { return "EO_if"; }

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: cond, trueBranch, falseBranch are EO_any*"
                  << "\n";
        if (cond != nullptr) { cond->testOut(); }
        if (trueBranch != nullptr) { trueBranch->testOut(); }
        if (falseBranch != nullptr) { falseBranch->testOut(); }
    }
};


#endif // __baseobjects__
