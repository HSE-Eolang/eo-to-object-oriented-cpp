// Моделирование выходного представление для программы,
// осуществляющей работу с прямоугольником.
// Проводится анализ реализации и подключения различных объектов.

#include <iostream>

#include "newobjects.h"

// Тестирование разных вариантов по аналогии с использованием в образце
int main() {
//    EO_factorial factorial(new EO_int(1));
//    EO_factorial factorial(new EO_int(2));
//    EO_factorial factorial(new EO_int(3));
//    EO_factorial factorial(new EO_int(5));
//    ((new EO_factorial(new EO_int(10)))->eval())->testOut();
    (create(new EO_factorial(new EO_int(10)))->eval())->testOut();
/*
    auto f = new EO_factorial(new EO_int(10));
    auto fact = f->eval();
    std::cout << "Result:\n";
    fact->testOut();
*/
    return 0;
}
