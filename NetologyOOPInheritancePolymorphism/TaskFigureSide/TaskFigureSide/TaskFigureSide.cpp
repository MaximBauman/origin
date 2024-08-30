#include <iostream>

class Figure
{
public:
    Figure() {
        sideRange = 0;
        name = "Figure: ";
    };
public:
    void get_sides() {
        std::cout << name << sideRange << std::endl;
    }
protected:
    int sideRange;
    std::string name;
};


class Triangle : public Figure
{
public:
    Triangle() : Figure() {
        sideRange = 3;
        name = "Triangle: ";
    };
};


class Quadrangular : public Figure {
public:
    Quadrangular() : Figure() {
        sideRange = 4;
        name = "Четырёхугольник: ";
    };
};



int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    Figure figure;
    Triangle triangle;
    Quadrangular quadrangular;

    std::cout << "Количество сторон:" << std::endl;

    figure.get_sides();
    triangle.get_sides();
    quadrangular.get_sides();

    return 0;
}
