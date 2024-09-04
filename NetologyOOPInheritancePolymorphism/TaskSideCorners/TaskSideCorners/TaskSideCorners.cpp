#include <iostream>

class Basic
{
public:
    Basic(std::string name) : name_(name) {};
    virtual void print_info() {};
    virtual ~Basic() {};
    std::string get_name() const { 
        return name_;
    }
private:
    std::string name_;

};

class Triangle : public Basic
{
public:
    Triangle(int a, int b, int c, int A, int B, int C, std::string name) : Basic(name), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {};

    void print_info() override {
        std::cout << Basic::get_name() << std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
        std::cout << std::endl;
    }

    ~Triangle() {};
private:
    int a, b, c, A, B, C;
};


class Quadrangle : public Basic {
public:

    Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Basic(name), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {
        
    };
    
    void print_info() override {
        std::cout << Basic::get_name() << std::endl;
        std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
        std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
        std::cout << std::endl;

    }

    ~Quadrangle() {};
private:
    int a, b, c, d, A, B, C, D;

};

class RightTriangle : public Triangle
{

public:
    RightTriangle(int a, int b, int c, int A, int B) : Triangle(a, b, c, A, B, 90, "Right triangle") {
    }
    ~RightTriangle() {};
};

class IsoscelesTriangle : public Triangle //равнобедренный
{
public:
    IsoscelesTriangle(int a, int b, int A, int B) : Triangle(a, b, a, A, B, A, "Isosceles triangle: ") {
    };
    ~IsoscelesTriangle() {};
};

class EquilateralTriangle : public Triangle //равносторонний
{
public:
    EquilateralTriangle(int a) : Triangle(a, a, a, 60, 60, 60, "Equilateral triangle: ") {
    };
    ~EquilateralTriangle() {};
};


class Rectangle : public Quadrangle //прямоугольник
{
public:
    Rectangle(int a, int b) : Quadrangle(a, b, a, b, 90, 90, 90, 90, "Rectangle") {
    };
    ~Rectangle() {};

};

class Square : public Quadrangle
{
public:
    Square(int a) : Quadrangle(a, a, a, a, 90, 90, 90, 90, "Square") {

    };
    ~Square() {};

private:

};

class Parallelogram : public Quadrangle
{
public:
    Parallelogram(int a, int b, int A, int B) : Quadrangle(a, b, a, b, A, B, A, B, "Parallelogram") {

    };
    ~Parallelogram() {};

private:

};

class Rhombus : public Quadrangle
{
public:
    Rhombus(int a, int A, int B) : Quadrangle(a, a, a, a, A, B, A, B, "Rhombus") {

    };
    ~Rhombus() {};

private:

};

void print_info(Basic* figure) {
    figure->print_info();
}
int main()
{
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");
    
    Triangle triangle(10,20,30,50,60,70, "Triangle");
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



    return 0;
}


