// Моделирование выходного представление для программы,
// осуществляющей работу с прямоугольником.
// Проводится анализ реализации и подключения различных объектов.

#include <iostream>

#include "newobjects.h"


// Тестирование разных вариантов по аналогии с использованием в образце
int main() {
    (((new EO_rectangle(new EO_int(10), new EO_int(7)))->perimeter).eval())->testOut();
    return 0;
}
