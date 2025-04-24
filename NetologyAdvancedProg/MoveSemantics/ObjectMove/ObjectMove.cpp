#include <iostream>
#include <vector>

template<typename T>
void move_vectors(T& first, T& second) {
	T obj1 = std::move(second);
	second = std::move(first);
	first = std::move(obj1);
}


int main()
{
	std::vector<std::string> one = { "test_string1", "test_string2" , "test_string3", "test_string4" };
	std::vector<std::string> two;
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||Before swap||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "It's one now: " << std::endl;
	for (auto i : one) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "It's two now: " << std::endl;
	for (auto i : two) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	move_vectors(one, two);
	std::cout << "||||||||||||||||||||||||||||||||||||||||||||||||||||||After swap||||||||||||||||||||||||||||||||||||||||||||||||||||||" << std::endl;
	std::cout << "It's one now: " << std::endl;
	for (auto i : one) {
		std::cout << i << " ";
	}
	std::cout << std::endl;
	std::cout << "It's two now: " << std::endl;
	for (auto i : two) {
		std::cout << i << " ";
	}
	std::cout << std::endl;

	return 0;
}
