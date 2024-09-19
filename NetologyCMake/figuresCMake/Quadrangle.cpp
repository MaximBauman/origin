
#include "Quadrangle.h"

Quadrangle::Quadrangle(int a, int b, int c, int d, int A, int B, int C, int D, std::string name) : Basic(name), a{ a }, b{ b }, c{ c }, d{ d }, A{ A }, B{ B }, C{ C }, D{ D } {};
void Quadrangle::print_info() {
    std::cout << Basic::get_name() << std::endl;
    std::cout << "Sides: a=" << a << " b=" << b << " c=" << c << " d=" << d << std::endl;
    std::cout << "Corners: A=" << A << " B=" << B << " C=" << C << " D=" << D << std::endl;
    std::cout << std::endl;
};

Quadrangle::~Quadrangle() {};

