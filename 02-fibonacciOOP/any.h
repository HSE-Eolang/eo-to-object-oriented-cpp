#ifndef __any__
#define __any__

#include <iostream>

//------------------------------------------------------------------------------
// Структура, формирующая родительский класс,
// подключаемый ко всем дочерним классам
struct EO_any {
    // Виртуальный метод, реализующий вычисление внутри объекта
    virtual EO_any* eval() = 0;
    // Виртуальный метод, реализующий вычисление с результатом в заданном объекте
    //virtual bool eval(EO_any& reciver) = 0;

    // получение имени объекта (пока для тестирования)
    virtual const char* getTypeName() = 0;
    // вывод тестовой информации об объекте
    virtual void testOut() {
        std::cout << "Name is: " << getTypeName()
                  << "\n";
    }
    
};

// Функция - оболочка для обезличивания типа создаваемого объекта. 
// Используется для сведения типа любого создаваемого объекта к типу EO_any
// что необходимо для адекватного моделирования концепции EOLANG.
EO_any* create(EO_any* anyObject);

#endif // __any__
