#include <iostream>

class Basic
{
public:
    Basic() {
        char z = 0;
    };
    virtual void print_info() {};
    ~Basic() {};

};

class Triangle : public Basic
{
public:
    Triangle(int a, int b, int c, int A, int B, int C) : a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {};

    void set_name(std::string name) {
        this->name = name;
    }
	
    void get_name() {
        std::cout << name << std::endl;
    }

    void get_sides() {
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
    }
    void get_corners() {
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }

    void print_info() override {
        get_name();
        get_sides();
        get_corners();
    }

    ~Triangle() {};
private:
    int a, b, c, A, B, C;
    std::string name = "Triangle: ";
};


class Quadrangle : public Basic {
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {
    };

    void set_name(std::string name) {
        this->name = name;
    }

    void get_name() {
        std::cout << name << std::endl;
    }

    void get_sides() {
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    }
    void get_corners() {
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;
    }
    void print_info() override {
        get_name();
        get_sides();
        get_corners();
    }
    ~Quadrangle() {};
private:
    int a, b, c, d, A, B, C, D;
    std::string name = "Quadrangle: ";
};

class RightTriangle : public Triangle
{

public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90) {
        Triangle::set_name(name);
    }
    ~RightTriangle() {};
private:
    std::string name = "Right triangle: ";
};

class IsoscelesTriangle : public Triangle //равнобедренный
{
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A) {
        Triangle::set_name(name);
    };
    ~IsoscelesTriangle() {};
private:
    std::string name = "Isosceles triangle: ";
};

class EquilateralTriangle : public Triangle //равносторонний
{
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60) {
        Triangle::set_name(name);
    };
    ~EquilateralTriangle() {};
private:
    std::string name = "Equilateral triangle: ";
};


class Rectangle : public Quadrangle //прямоугольник
{
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90) {
        Quadrangle::set_name(name);
    };
    ~Rectangle() {};

private:
    std::string name = "Rectangle: ";
};

class Square : public Quadrangle
{
public:
    Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90) {
        Quadrangle::set_name(name);
    };
    ~Square() {};

private:
    std::string name = "Square: ";
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B) {
        Quadrangle::set_name(name);
    };
    ~Parallelogram() {};

private:
    std::string name = "Parallelogram: ";
};

class Rhombus : public Quadrangle
{
public:
    Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B) {
        Quadrangle::set_name(name);
    };
    ~Rhombus() {};

private:
    std::string name = "Rhombus: ";
};

void print_info(Basic* figure) {
    figure->print_info();
}
int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    Triangle triangle(10,20,30,50,60,70);
    RightTriangle rightTriangle(10, 20, 30, 50, 60);
    IsoscelesTriangle isoscelesTriangle(10, 20, 50, 60);
    EquilateralTriangle equilateralTriangle(30);
    Quadrangle quadrangle(10, 20, 30, 40, 50, 60, 70, 80);
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



    return 0;
}


