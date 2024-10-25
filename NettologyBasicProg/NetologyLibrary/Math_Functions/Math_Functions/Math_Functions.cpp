#include <iostream>
#include "mFunctions.h"

int main()
{
    int a, b;

    char userChoose;

    std::cout << "Input first number: ";
    std::cin >> a;
    std::cout << std::endl;

    std::cout << "Input second number: ";
    std::cin >> b;
    std::cout << std::endl;

    std::cout << "Select the operation (1 - addition, 2 subtraction, 3 - multiplication, 4 - division, 5 - exponentiation): ";
    std::cin >> userChoose;

        switch (userChoose)
        {
        case '1':
            std::cout << a << " plus " << b << " = " << add(a, b) << std::endl;
            break;
        case '2':
            std::cout << a << " minus " << b << " = " << sub(a, b) << std::endl;
            break;
        case '3':
            std::cout << a << " multiplication " << b << " = " << mult(a, b) << std::endl;
            break;
        case '4':
            std::cout << a << " division " << b << " = " << divn(a, b) << std::endl;
            break;
        case '5':
            std::cout << a << " exponentiation " << b << " = " << exp(a, b) << std::endl;
            break;
        default:
            break;
        }
    
}

