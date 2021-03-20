#ifndef __baseobjects__
#define __baseobjects__

#include "extfun.h"

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий пустой объект
// Данный объект заменяет пустой указатель и при попытке вычислить его
// порждает ошибку с завершением программы.
// В принципе на все программу достаточно одного пустого объекта
struct EO_empty: EO_any {
    explicit EO_empty() {
        message = "No special message";
    }
    const char* message;
    virtual EO_any* eval() {
        std::cout << "EO_empty: " << message << "\n";
        std::cout << "Dynamic evaluation error!! Empty object!!!\n";
        exit(1);
        return this;
    }

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_empty"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  It is Empty object\n";
    }
};

extern EO_empty empty;

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий атомарный целочисленный объект
struct EO_int: EO_any {
    explicit EO_int(int v): value{v} {}
    // атрибут целочисленного объекта
    int value;

    virtual EO_any* eval() { return this; }

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_int"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: [" << value << "]"
                  << "\n";
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий атомарный булевский объект
struct EO_bool: EO_any {
    explicit EO_bool(bool v): value{v} {}
    // атрибут целочисленного объекта
    bool value;

    virtual EO_any* eval() { return this; }

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_bool"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::string str = value? "true" : "false";
        std::cout << "  Attributes: [" << str << "]"
                  << "\n";
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сложения
struct EO_add: EO_any {
    explicit EO_add(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {}
    // атрибуты объекта-сложения
    EO_any *a, *b;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_add"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию вычитания
struct EO_sub: EO_any {
    explicit EO_sub(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {}
    // атрибуты объекта
    EO_any *a, *b;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_sub"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию умножения
struct EO_mul: EO_any {
    explicit EO_mul(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {}
    // атрибуты объекта-умножение
    EO_any *a, *b;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_mul"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сравнения "меньше"
struct EO_lt: EO_any {
    explicit EO_lt(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {}
    // атрибуты объекта-меньше
    EO_any *a, *b;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_lt"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий операцию сравнения "меньше или равно"
struct EO_le: EO_any {
    explicit EO_le(EO_any *arg1, EO_any *arg2): a{arg1}, b{arg2} {}
    // атрибуты объекта
    EO_any *a, *b;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_le"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: a, b are EO_any*"
                  << "\n";
        if(a != nullptr) { a->testOut(); }
        if(b != nullptr) { b->testOut(); }
    }
};

//------------------------------------------------------------------------------
// Предопределенный класс, описывающий объект, задающий условный оператор
struct EO_if: EO_any {
    explicit EO_if(EO_any *argCond, EO_any *argTrueBranch, EO_any *argFalseBranch)
        : cond{argCond}, trueBranch{argTrueBranch}, falseBranch {argFalseBranch} {}
    // атрибуты объекта
    EO_any *cond, *trueBranch, *falseBranch;

    virtual EO_any* eval();

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() { return "EO_if"; }
    // вывод тестовой информации об объекте
    virtual void testOut() {
        EO_any::testOut();
        std::cout << "  Attributes: cond, trueBranch, falseBranch are EO_any*"
                  << "\n";
        if(cond != nullptr) { cond->testOut(); }
        if(trueBranch != nullptr) { trueBranch->testOut(); }
        if(falseBranch != nullptr) { falseBranch->testOut(); }
    }
};


#endif // __baseobjects__
