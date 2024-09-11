#include <iostream>
#include "Basic.h"
#include "Triangle.h"
#include "Quadrangle.h"
#include "RightTriangle.h"
#include "IsoscelesTriangle.h"
#include "EquilateralTriangle.h"
#include "Rectangle.h"
#include "Square.h"
#include "Parallelogram.h"
#include  "Rhombus.h"
#include "MyExceptionTriangle.h"
#include "MyExceptionQuadrangle.h"

void print_info(Basic* figure);

void recuirseCall();

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    
    recuirseCall();

    return 0;
}

void recuirseCall() {
    try {
        Triangle triangle(10, 20, 30, 50, 60, 70, "Triangle");
        print_info(&triangle);
        RightTriangle rightTriangle(10, 20, 30, 50, 40);
        print_info(&rightTriangle);
        IsoscelesTriangle isoscelesTriangle(10, 20, 50, 80);
        print_info(&isoscelesTriangle);
        EquilateralTriangle equilateralTriangle(30);
        print_info(&equilateralTriangle);
        Quadrangle quadrangle(10, 20, 30, 40, 100, 60, 90, 110, "Quadrangle");
        print_info(&quadrangle);
        Rectangle rectangle(10, 20);
        print_info(&rectangle);
        Square square(20);
        print_info(&square);
        Parallelogram parallelogram(20, 30, 30, 40);
        print_info(&parallelogram);
        Rhombus rhombus(30, 30, 40);
        print_info(&rhombus);
    }
    catch (MyExceptionTriangle& exTriangle) {
        std::cout << "Can't create figure. Corners > || < 180*" << std::endl;
    }
    catch (MyExceptionQuadrangle& exQuadrangle) {
        std::cout << "Can't create figure. Corners > || < 360*" << std::endl;
    }
    catch (...) {
        std::cout << "Something is wrong :( True again later" << std::endl;
    }
    
}

void print_info(Basic* figure) {
    figure->print_info();
}