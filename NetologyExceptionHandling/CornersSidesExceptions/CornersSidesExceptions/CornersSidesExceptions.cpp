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

int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    try {
        Triangle triangle(10, 20, 30, 50, 60, 70, "Triangle");
        RightTriangle rightTriangle(10, 20, 30, 50, 60);
        IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
        EquilateralTriangle equilateralTriangle(30);
        Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80, "Quadrangle");
        Rectangle rectangle(10, 20);
        Square square(20);
        Parallelogram parallelogram(20, 30, 30, 40);
        Rhombus rhombus(30, 30, 40);

        print_info(&triangle);
        print_info(&rightTriangle);
        print_info(&isoscelesTriangle);
        print_info(&equilateralTriangle);
        print_info(&quadrangle);
        print_info(&rectangle);
        print_info(&square);
        print_info(&parallelogram);
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


    return 0;
}

void print_info(Basic* figure) {
    figure->print_info();
}