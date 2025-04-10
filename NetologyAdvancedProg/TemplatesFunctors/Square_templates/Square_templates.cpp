#include <iostream>
#include <vector>

template<typename T>
auto squaring(T a) {
	return a * a;
}
template< typename T2>
void vector_squaring(std::vector<T2>& vec) {
	for (auto i = 0; i < vec.size(); i++) {
		std::cout << vec[i] * vec[i] << " ";
	}
	std::cout << std::endl;
}

template<typename T3>
void ReadInput(T3& value) {
	std::cin >> value;
}

int main()
{
	auto input = 0.0;
	std::cout << "Hello, it's square template function." << std::endl; 
	do {
		std::cout << "1. Enter an element 2. Enter an array of elements. If you want to finish entering, enter -999 \r" << std::endl;
		std::cin >> input;
		if (input == 1) {
			std::cout << "Input element: ";
			ReadInput(input);
			std::cout << squaring(input) << std::endl;
		}
		else if(input == 2) {
			std::cout << "Enter an array of elements. If you want to finish entering, enter -999: ";
			std::vector<int>numbers;
			 while (input != -999) {
				 ReadInput(input);
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

	std::vector<double> vector_double{ 1.68, 2.5, 10.12 };
	std::vector<int> vector_int{ 1, 2, 10 };
	vector_squaring(vector_double);
	vector_squaring(vector_int);

	return 0;
}

