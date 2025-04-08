#include <iostream>
#include <vector>

template<typename T>
T squaring(T a) {
	return a * a;
}
template< typename T2>
void vector_squaring(std::vector<T2>& vec) {
	for (auto i = 0; i < vec.size(); i++) {
		std::cout << vec[i] * vec[i] << " ";
	}
	std::cout << std::endl;
}
int main()
{
	int input = 0;
	std::cout << "Hello, it's square template function." << std::endl; 
	do {
		std::cout << "1. Enter an element 2. Enter an array of elements. If you want to finish entering, enter -999 \r" << std::endl;
		std::cin >> input;
		if (input == 1) {
			std::cout << "Input element: ";
			std::cin >> input;
			std::cout << squaring(input) << std::endl;
		}
		else if(input == 2) {
			std::cout << "Enter an array of elements. If you want to finish entering, enter -999: ";
			std::vector<int>numbers;
			 while (input != -999) {
				std::cin >> input;
				if (input != -999) {
					numbers.push_back(input);
				}
				else {
					input = 0; 
					break;
				}
				
			};
			vector_squaring(numbers);
		}
		else { continue; }
		
	} while (input != -999);

	return 0;
}

