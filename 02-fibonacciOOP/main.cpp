// Моделирование выходного представление для программы,
// осуществляющей работу с прямоугольником.
// Проводится анализ реализации и подключения различных объектов.

#include <iostream>

#include "newobjects.h"

// Тестирование разных вариантов по аналогии с использованием в образце
int main() {
//    EO_fibonacci fibonacci(new EO_int(1));
//    EO_fibonacci fibonacci(new EO_int(2));
//    EO_fibonacci fibonacci(new EO_int(3));
//    EO_fibonacci fibonacci(new EO_int(5));
/*
    EO_fibonacci fibonacci(new EO_int(10));
    //fibonacci.testOut();
    auto fibo = fibonacci.eval();
    std::cout << "Result:\n";
    fibo->testOut();
*/
    (create(new EO_fibonacci(new EO_int(10)))->eval())->testOut();
    return 0;
}
