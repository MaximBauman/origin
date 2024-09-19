
#include <iostream>
#include "Greeter.h"

int main()
{
    std::string name;
    std::cout << "Input your name: ";
    std::cin >> name; 
    std::cout << std::endl;
    Greeter Name;
    Name.printer(name);
}

