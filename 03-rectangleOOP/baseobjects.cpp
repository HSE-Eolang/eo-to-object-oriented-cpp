#include "baseobjects.h"

// Пустой объект, предназначенный для завершения программы при некорректном
// построении дерева объектов
EO_empty empty;

//------------------------------------------------------------------------------
// функция, вычисляющая сложение чисел в объекте EO_add
EO_any* EO_add::eval() {
    EO_any* aa = a->eval();
    EO_any* bb = b->eval();
    if(EO_int* argA = dynamic_cast<EO_int*>(aa)) {
        if(EO_int* argB = dynamic_cast<EO_int*>(bb)) {
            return new EO_int(argA->value + argB-> value);
        } else {
            return &empty;
        }
    } else {
        return &empty;
    }
}

//------------------------------------------------------------------------------
// функция, вычисляющая вычитание чисел в объекте EO_sub
EO_any* EO_sub::eval() {
    EO_any* aa = a->eval();
    EO_any* bb = b->eval();
    if(EO_int* argA = dynamic_cast<EO_int*>(aa)) {
        if(EO_int* argB = dynamic_cast<EO_int*>(bb)) {
            return new EO_int(argA->value - argB-> value);
        } else {
            return &empty;
        }
    } else {
        return &empty;
    }
}

//------------------------------------------------------------------------------
// функция, вычисляющая умножение чисел в объекте EO_mul
EO_any* EO_mul::eval() {
    EO_any* aa = a->eval();
    EO_any* bb = b->eval();
    if(EO_int* argA = dynamic_cast<EO_int*>(aa)) {
        if(EO_int* argB = dynamic_cast<EO_int*>(bb)) {
            return new EO_int(argA->value * argB-> value);
        } else {
            return &empty;
        }
    } else {
        return &empty;
    }
}

//------------------------------------------------------------------------------
// функция, вычисляющая отношение "меньше" в объекте EO_lt
EO_any* EO_lt::eval() {
    EO_any* aa = a->eval();
    EO_any* bb = b->eval();
    if(EO_int* argA = dynamic_cast<EO_int*>(aa)) {
        if(EO_int* argB = dynamic_cast<EO_int*>(bb)) {
            return new EO_bool(argA->value < argB-> value);
        } else {
            return &empty;
        }
    } else {
        return &empty;
    }
}

//------------------------------------------------------------------------------
// функция, вычисляющая отношение "меньше или равно" в объекте EO_le
EO_any* EO_le::eval() {
    EO_any* aa = a->eval();
    EO_any* bb = b->eval();
    if(EO_int* argA = dynamic_cast<EO_int*>(aa)) {
        if(EO_int* argB = dynamic_cast<EO_int*>(bb)) {
            return new EO_bool(argA->value <= argB-> value);
        } else {
            return &empty;
        }
    } else {
        return &empty;
    }
}

//------------------------------------------------------------------------------
// функция, вычисляющая условие в объекте EO_if
EO_any* EO_if::eval() {
    EO_any* boolResult = cond->eval();
    if(EO_bool* argCond = dynamic_cast<EO_bool*>(boolResult)) {
        if(argCond->value) {
            return trueBranch->eval();
        } else {
            return falseBranch->eval();
        }
    } else {
        return &empty;
    }
}
