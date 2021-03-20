#ifndef __any__
#define __any__

#include <iostream>

//------------------------------------------------------------------------------
// Структура, формирующая родительский класс,
// подключаемый ко всем дочерним классам
//--------------------------------------------
// The structure that forms the parent class
// that is to be used as the base type for any of its child classes (EO objects)
struct EO_any {
    // виртуальный метод, реализующий вычисление (датаризацию) объекта
    //--------------------------------------------
    // the virtual method that performs the evaluation (or dataization) operation on the object
    virtual EO_any *eval() = 0;

    // получение имени (иначе: типа) объекта (пока для тестирования)
    //--------------------------------------------
    // retrieves the name of the object (in other words, the type of the object) 
    // abstracted by the EO_any (for testing purposes)
    virtual const char *getTypeName() = 0;

    // вывод тестовой информации об объекте
    //-------------------------------------
    // prints the debug information about the object
    virtual void testOut() {
        std::cout << "Name is: " << getTypeName()
                  << "\n";
    }
};

#endif // __any__
