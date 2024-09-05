#pragma once
#include "Basic.h"

class Quadrangle : public Basic {

public:
    Quadrangle(int, int, int, int, int, int, int, int, std::string);

    void print_info() override;

    ~Quadrangle();
private:
    int a, b, c, d, A, B, C, D;

};