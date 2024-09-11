#include "Triangle.h"



Triangle::Triangle(int a, int b, int c, int A, int B, int C, std::string name) :Basic(name), a{ a }, b{ b }, c{ c }, A{ A }, B{ B }, C{ C } {
    if (A + B + C != 180 || (A == 0 || B == 0 || C == 0)) {
        throw MyExceptionTriangle();
    }
};


void Triangle::print_info() {
    std::cout << Basic::get_name() << " ";
    std::cout << "(Sides: a=" << a << " b=" << b << " c=" << c << "; ";
    std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << ") " << "created" << std::endl; 
    std::cout << std::endl;
};
Triangle::~Triangle() {};