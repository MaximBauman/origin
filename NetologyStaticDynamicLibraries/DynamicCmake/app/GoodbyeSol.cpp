#include <iostream>
#include "Leaver.h"

int main()
{
	std::string name;
	std::cout << "Input your name: ";
	std::cin >> name;
	std::cout << std::endl;
	Leaver leaver;
	leaver.printer(name);
}
