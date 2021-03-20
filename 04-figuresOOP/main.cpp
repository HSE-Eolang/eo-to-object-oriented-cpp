// Моделирование выходного представление для программы,
// осуществляющей работу с прямоугольником.
// Проводится анализ реализации и подключения различных объектов.

#include <iostream>

#include "newobjects.h"


// Целочисленные объекты
EO_int i1{10};
EO_int i2{-5};

// Объект-сложение целочисленных объектов
//EO_add add(&i1, &i2);

// Исходный объект, используемый для клонирования
//EO_rectangle rectangle{&i1, &i2};

// Тестирование разных вариантов по аналогии с использованием в образце
int main() {
//    rectangle.testOut();
//    add.testOut();

//    auto addResult = add.eval();
//    addResult->testOut();
    
//    EO_mul mul(add.eval(), &i1);
//    auto addResult2 = mul.eval();
    //addResult2->testOut();
    
//    EO_bool b1{true};
//    b1.testOut();
//    return 0;
//    EO_le le(&i1, &i2);
//    auto leI1I2 = le.eval();
//    leI1I2->testOut();
/*    

    EO_le le2(&i1, &i1);
    auto leI1I1 = le2.eval();
    leI1I1->testOut();
*/
//    EO_sub sub(&i2, &i1);
//    sub.testOut();
//    auto subResult = sub.eval();
//    subResult->testOut();

    auto* rect = new EO_rectangle(new EO_int(10), new EO_int(7));
    auto result = (rect->perimeter).eval();
    result->testOut();

    EO_any* rect2 = new EO_rectangle(new EO_int(100), new EO_int(70));
    auto result2 = perimeter(rect2);
    result2->testOut();

    auto* trian1 = new EO_triangle(new EO_int(10), new EO_int(17), new EO_int(13));
    auto result3 = (trian1->perimeter).eval();
    result3->testOut();

    EO_any* trian2 = new EO_triangle(new EO_int(100), new EO_int(170), new EO_int(130));
    auto result4 = perimeter(trian2);
    result4->testOut();

    // Использование полиморфизма с выбором фигуры и вычисления ее периметра
    auto poly1 = new EO_if(new EO_lt(&i1, &i2), rect, trian1);
    auto ifresult1 = poly1->eval();
    EO_any* result5 = perimeter(ifresult1);
    result5->testOut();
    
    auto poly2 = new EO_if(new EO_lt(&i2, &i1), rect, trian1);
    EO_any* result7 = perimeter(poly2->eval());
    result7->testOut();

    EO_any* poly3 = (new EO_if(new EO_lt(&i1, &i2), rect2, trian2))->eval();
    auto result6 = perimeter(poly3);
    result6->testOut();
    
    //EO_any* poly3 = (new EO_if(new EO_lt(&i2, &i1), rect2, trian2))->eval();
    auto result8 = perimeter((new EO_if(new EO_lt(&i2, &i1), rect2, trian2))->eval());
    result8->testOut();


    return 0;
}
