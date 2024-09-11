#pragma once
#include "Basic.h"
#include "MyExceptionQuadrangle.h"

class Quadrangle : public Basic , public MyExceptionQuadrangle{

public:
    Quadrangle(int, int, int, int, int, int, int, int, std::string);

    void print_info() override;
    

    ~Quadrangle();
private:
    int a, b, c, d, A, B, C, D;

};