#include <iostream>

void arrayFilling(int* arr, int size, int logic_size);

void print_dynamic_array(int* arr, int logical_size, int actual_size);

void append_to_dynamic_array(int* arr, int& logical_size, int& actual_size);

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
		append_to_dynamic_array(arr, input_logicalSize, input_actualSize);


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
		else {
			std::cout << arr[i] << " ";
		}
	}
	std::cout << std::endl;
}

void append_to_dynamic_array(int* arr, int& logical_size, int& actual_size) {
	int user_input;
	while (true) {
		std::cout << "Input element: ";
		std::cin >> user_input;
		if (user_input == 0) {
			std::cout << "Good job!";
			print_dynamic_array(arr, logical_size, actual_size);
			delete[] arr;


			break;
		}
		if (logical_size == actual_size) {
			int* new_arr = new int[actual_size * 2];
			for (int i = 0; i < logical_size; ++i) {
				new_arr[i] = arr[i];  // Копируем старые элементы в новый массив
			}
			delete[] arr;
			arr = new_arr;
			actual_size *= 2;
		}
		arr[logical_size] = user_input;
		logical_size++;
		print_dynamic_array(arr, logical_size, actual_size);

	}
}
