#include <iostream>

class Basic
{
public:
    Basic() {
        char b = 0;
    };
    virtual void print_info() {};
    ~Basic() {};
};

class Triangle : public Basic
{
public:
    Triangle(int a, int b, int c, int A, int B, int C) : a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {
        
    };
	
    void get_name() {
        std::cout << name << std::endl;
    }

    void get_sides() {
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
    }
    void get_corners() {
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
    }

    void print_info() override {
        get_name();
        get_sides();
        get_corners();
    }

private:
    int a, b, c, A, B, C;
    std::string name = "Triangle: ";
};


class Quadrangle : public Basic {
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D) : a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {};

    void get_name() {
        std::cout << name << std::endl;
    }

    void get_sides() {
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    }
    void get_corners() {
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    }
    void print_info() override {
        get_name();
        get_sides();
        get_corners();
    }
private:
    int a, b, c, d, A, B, C, D;
    std::string name;
};

class RightTriangle : public Triangle
{
public:
    RightTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {}

private:
    std::string name = "Right triangle: ";
};

class IsoscelesTriangle : public Triangle //равнобедренный
{
public:
    IsoscelesTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {};
private:
    std::string name = "Isosceles triangle: ";
};

class EquilateralTriangle : public Triangle //равносторонний
{
public:
    EquilateralTriangle(int a, int b, int c, int A, int B, int C) : Triangle(a, b, c, A, B, C) {};

private:
    std::string name = "Equilateral triangle: ";
};


class Rectangle : public Quadrangle //прямоугольник
{
public:
    Rectangle(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {};
    ~Rectangle();

private:
    std::string name = "Rectangle: ";
};

class Square : public Quadrangle
{
public:
    Square(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {};
    ~Square();

private:
    std::string name = "Square: ";
};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {};
    ~Parallelogram();

private:
    std::string name = "Parallelogram: ";
};

class Rhombus : public Quadrangle
{
public:
    Rhombus(int a, int b, int c, int d, int A, int B, int C, int D) : Quadrangle(a, b, c, d, A, B, C, D) {};
    ~Rhombus();

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
    
    Triangle triangle(10, 20, 30, 50, 60, 70);
    RightTriangle righttriangle(10, 20, 30, 50, 60, 90);
    print_info(&righttriangle);


}
