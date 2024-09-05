#include "Triangle.h"

Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) :Basic(name), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {};
void Triangle::print_info() {
    std::cout << Basic::get_name() << std::endl;
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << std::endl;
    std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << std::endl;
    std::cout << std::endl;
};
Triangle::~Triangle() {};