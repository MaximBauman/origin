#include <iostream>

void printer(int* arr, int size) {
	for (int i = 0; i < size; i++) {
		std::cout << arr[i] << " ";
		std::cout << std::endl;
	}
}



int main()
{
	const int n = 15;
	int arr[n] = { 1, 3, 4, 5, 8, 12, 54, 61, 67, 78, 78, 84, 88, 123, 201 };

	printer(arr, n);

	int left = 0;
		int counter = 0;
		int middle = 0;
	int right = n-1;

	int inputNumber;

	std::cout << "Input point: ";
	std::cin >> inputNumber;
	std::cout << std::endl;

	while (left < right) {
		middle = (left + right) / 2;
		if (arr[middle] < inputNumber) {
			left = middle + 1;
		}
		else {
			right = middle;

		}
	}

	std::cout << "counter = " << n - 1 - right;

	return 0;
}
