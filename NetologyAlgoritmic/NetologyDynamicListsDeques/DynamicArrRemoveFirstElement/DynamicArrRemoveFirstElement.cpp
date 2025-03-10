#include <iostream>

void arrayFilling(int* arr, int size, int logic_size);

void print_dynamic_array(int* arr, int logical_size, int actual_size);
void remove_dynamic_array_head(int* arr, int &logical_size, int &actual_size);

int main()
{
	int input_logicalSize, input_actualSize;
	std::cout << "Input actual array size: ";
	std::cin >> input_actualSize;
	std::cout << "Input logical array size: ";
	std::cin >> input_logicalSize;

	if (input_logicalSize > input_actualSize) {
		std::cout << "Error!The logical size of an array cannot exceed the actual size.";
		return 0;
	}
	else {

		int* arr = new int[input_actualSize];

		arrayFilling(arr, input_actualSize, input_logicalSize);
		print_dynamic_array(arr, input_logicalSize, input_actualSize);
		remove_dynamic_array_head(arr, input_logicalSize, input_actualSize);

		return 0;
	}
}

void arrayFilling(int* arr, int size, int logic_size) {
	for (int i = 0; i < size; i++) {
		if (i < logic_size) {
			std::cout << "Input arr[" << i << "]: ";
			std::cin >> arr[i];
		}
		else {
			arr[i] = 0;
		}
	}
}

void print_dynamic_array(int* arr, int logical_size, int actual_size) {
	std::cout << "Dynmic array: ";
	for (int i = 0; i < actual_size; i++) {
		if (i >= logical_size) {
			std::cout << "_ ";
		}
		else if (logical_size == 0) {
			std::cout << "_";
		}
		else {
			std::cout << arr[i] << " ";
		}

	}
	if (actual_size == 0) {
		std::cout << "_";
	}
	std::cout << std::endl;
}
void remove_dynamic_array_head(int* arr, int& logical_size, int& actual_size) {
	std::string userAnswer;
	while (true) {
		std::cout << "Would you like to delete the first element? Use yes or no: ";
		std::cin >> userAnswer;
		if (userAnswer == "No" || userAnswer == "no") {
			std::cout << "Good job!";
			print_dynamic_array(arr, logical_size, actual_size);

			delete[] arr;
			break;
		}
		else if (logical_size == 0) {
			std::cout << "Error! Array is empty. Thank you!";
			delete[] arr;
			break;
		}
		else if (userAnswer == "Yes" || userAnswer == "yes") {
			
			if (logical_size - 1 <= actual_size / 3) {
				int new_size = std::max(actual_size / 3, logical_size - 1);
				int* new_arr = new int[new_size];
				for (int i = 0; i < logical_size - 1; i++) {
					new_arr[i] = arr[i+1];
				}
				delete[] arr;
				arr = new_arr;
				actual_size = new_size;


			}
			else {
				for (int i = 0; i < logical_size - 1; i++) {
						arr[i] = arr[i + 1];
				}
			}
			--logical_size;
			print_dynamic_array(arr, logical_size, actual_size);

			

		}
		else {
			std::cout << "Please enter 'yes' or 'no'.\n";
		}
	}
}

