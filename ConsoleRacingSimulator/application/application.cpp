// application.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>

int main()
{
    int userAnsw, distance;

    std::cout << "Welcome, to the racing simulator!" << std::endl;
    std::cout << "1. Race for ground vehicles" << std::endl;
    std::cout << "2. Race for air vehicles" << std::endl;
    std::cout << "3. Race for ground and air vehicles" << std::endl;
    std::cout << "Select racing type: ";
    std::cin >> userAnsw;
    std::cout << std::endl;

    std::cout << "Set race distance (can't be negative): ";
    std::cin >> distance;

    std::cout << std::endl; 

}
