#include <iostream>

void arrayFilling(int* arr, int size, int logic_size);

void print_dynamic_array(int* arr, int logical_size, int actual_size);

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

	   delete[] arr;

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
