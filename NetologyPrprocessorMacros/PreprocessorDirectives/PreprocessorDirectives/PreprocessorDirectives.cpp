#include <iostream>

#define MODE 1

#ifndef MODE
#error "Please identify MODE"

#endif




#if MODE == 0
int main() {
	std::cout << "Work in training mode" << std::endl;
}
#elif MODE == 1
int add(int a, int b) {
	return a + b;
}
int main() {
	int a, b;
	std::cout << "Work in prod mode" << std::endl;
	std::cout << "Input number_1: ";
	std::cin >> a;
	std::cout << std::endl;
	std::cout << "Input number_2: ";
	std::cin >> b;
	std::cout << "Summary result: " << add(a,b) << std::endl;
}
#else
int main() {
	std::cout << "Mode not found. Program close." << std::endl;

}
#endif


