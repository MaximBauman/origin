#pragma once
#include "Basic.h"

class Triangle : public Basic
{
public:
    Triangle(int, int, int, int, int, int, std::string);

    void print_info() override;

    ~Triangle();
private:
    int a, b, c, A, B, C;
};