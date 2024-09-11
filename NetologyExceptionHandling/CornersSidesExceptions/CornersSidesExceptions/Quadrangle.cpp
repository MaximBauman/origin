
#include "Quadrangle.h"


Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Basic(name), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {
    if (A + B + C + D != 360 || (A == 0 || B == 0 || C == 0 || D == 0)) {
        throw MyExceptionQuadrangle();
    }
    else {
        continue;
    }
};
void Quadrangle::print_info() {
    std::cout << Basic::get_name() << " ";
    std::cout << "(Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << "; ";
    std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << ")" << "created" << std::endl;
    std::cout << std::endl;
};



Quadrangle::~Quadrangle() {};



