#include <iostream>

int main(int argc, char** argv) {
	std::string name;

	std::cout << "Input your name: ";
	std::cin >> name;
	std::cout << std::endl;

	std::cout << "Hi, " << name << "!" << std::endl;

}