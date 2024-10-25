#include <iostream>

#define sub(a,b) (a - (b))

int main()
{
    int a = 6, b = 5, c = 2;
	std::cout << sub(a, b) << std::endl;
	std::cout << sub(a, b) * c << std::endl;
	std::cout << sub(a, b + c) * c << std::endl;
	return 0;
}

