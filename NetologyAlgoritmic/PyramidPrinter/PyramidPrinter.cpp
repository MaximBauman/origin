
#include <iostream>

void array_filler(int* arr, int size);
void array_printer(int* arr, int size);
void print_pyramid(int* arr, int size);

int main()
{
    int size;
    std::cout << "Hi! It's pyramid printer. Please insert array size there (6/8/10 or custom): ";
    std::cin >> size;
    int* array = new int[size];

    std::cout << "Next, enter the numbers that should be included in the pyramid. Remember the principles of its construction (a pyramid with a maximum or minimum)." << std::endl; 
    std::cout << "But you can use examples : " << std::endl;
    std::cout << "1. [1 3 6 5 9 8] size = 6" << std::endl;
    std::cout << "2. [94 67 18 44 55 12 6 42] size = 8" << std::endl;
    std::cout << "3. [16 11 9 10 5 6 8 1 2 4] size = 10" << std::endl;

    array_filler(array, size);
    array_printer(array, size);
    print_pyramid(array, size);

    delete[] array;
    return 0;
}

void array_filler(int* arr, int size) {
    for (int i = 0; i < size; i++) {
        std::cout << "Please, input number by index [" << i << "]: ";
        std::cin >> arr[i];
    }
}
void array_printer(int* arr, int size) {
    std::cout << "Your original array: ";
    for (int i = 0; i < size; i++) {
        std::cout << arr[i] << " ";
    }
    std::cout << std::endl;
}
void print_pyramid(int* arr, int size) {
    std::cout << "Pyramid:" << std::endl;
    for (int i = 0; i < size; i++) {
        int level = static_cast<int>(log2(i + 1));
        if (i == 0) {
            std::cout << level << " root " << arr[i] << std::endl;
        }
        else {
            int parent_index = (i - 1) / 2;
            std::string chyldType = (i % 2 == 0) ? "right" : "left";
            std::cout << level << " " << chyldType << "(" << arr[parent_index] << ") " << arr[i] << std::endl;
        }
    }
}
