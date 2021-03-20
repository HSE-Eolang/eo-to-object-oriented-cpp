#include "baseobjects.h"

// Необходимо также подключить заголовочные файлы классов с проверяемыми 
// пользовательскими типами
#include "newobjects.h"

// Функция - оболочка для обезличивания типа создаваемого объекта. 
// Используется для сведения типа любого создаваемого объекта к типу EO_any
// что необходимо для адекватного моделирования концепции EOLANG.
EO_any* create(EO_any* anyObject) {
    return anyObject;
}

//------------------------------------------------------------------------------
// Прямое решение для конкретных методов через использование внешних функций
// Проверяется и вызывается конкретный объект-метод
// Проверка и вызов объектов - периметров
EO_any* perimeter(EO_any *src) {
    // Явная динамическая проверка типа, используемого в методе.
    if(EO_rectangle* ptr = dynamic_cast<EO_rectangle*>(src)) {
        return (ptr->perimeter).eval();
    } else if(EO_triangle* ptr = dynamic_cast<EO_triangle*>(src)) {
        return (ptr->perimeter).eval();
    } else {
        std::cout << "eval: Method perimeter. Type of object is absent\n";
        return &empty;
    }
}
