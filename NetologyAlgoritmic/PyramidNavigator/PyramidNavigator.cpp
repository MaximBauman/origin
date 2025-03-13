
#include <iostream>

struct Navigation {
    std::string Up = "up";
    std::string Left = "left";
    std::string Right = "right";
    std::string Exit = "exit";
};

void array_filler(int* arr, int size);
void array_printer(int* arr, int size);
void print_pyramid(int* arr, int size);
void navigation_print(Navigation s);
void pyramid_navigation(int* arr, int size);

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
    pyramid_navigation(array, size);


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


void navigation_print(Navigation s) {
    std::cout << "Command's:" << std::endl;
    std::cout << "1. " << s.Up << std::endl;
    std::cout << "2. " << s.Left << std::endl;
    std::cout << "3. " << s.Right << std::endl;
    std::cout << "4. " << s.Exit << std::endl;
    std::cout << "Input command: ";
};

void pyramid_navigation(int* arr, int size) {
    Navigation navigation;
    std::string user_answer;
    bool status;
    int position = 0;
    int parent_index, parentNumber, chyld_index, chyldNumber, level;
    std::string type;
    do {
        navigation_print(navigation);
        std::cin >> user_answer;
        if (user_answer == "up") {
            if(position == 0){
                std::cout << "Error! No parent!";
                std::cout << "Your position: ";
                std::cout << position << " root " << arr[position] << std::endl;
            }
            else {
                std::cout << "Ok" << std::endl;
                parent_index = (position - 1) / 2;
                position = parent_index;
                if (position == 0) {
                    std::cout << "Your position: ";
                    std::cout << position << " root " << arr[position] << std::endl;
                }
                else {
                    type = (parent_index % 2 == 0) ? " right" : " left";
                    parentNumber = (parent_index - 1) / 2;
                    level = static_cast<int>(log2(position + 1));
                    std::cout << "Your position: ";
                    std::cout << level << type << "(" << arr[parentNumber] << ") " << arr[position] << std::endl;
                }
            }
        }
        else if (user_answer == "left") {
            chyld_index = position * 2 + 1;
            if (chyld_index > size) {
                std::cout << "Error! Left stream missing!" << std::endl;
                std::cout << "Your position: ";
                level = static_cast<int>(log2(position + 1));
                type = (position % 2 == 0) ? " right" : " left";
                parentNumber = (position - 1) / 2;
                std::cout << level << type << "(" << arr[parentNumber] << ") " << arr[position] << std::endl;
            }
            else {
                std::cout << "Ok" << std::endl;
                position = chyld_index;
                parentNumber = (position - 1) / 2;
                type = " left";
                level = static_cast<int>(log2(position + 1));
                std::cout << "Your position: ";
                std::cout << level << type << "(" << arr[parentNumber] << ") " << arr[position] << std::endl;
            }
        }
        else if (user_answer == "right") {
            chyld_index = position * 2 + 2;
            if (chyld_index > size - 1) {
                std::cout << "Error! Right stream missing!" << std::endl;
                std::cout << "Your position: ";
                level = static_cast<int>(log2(position + 1));
                type = (position % 2 == 0) ? " right" : " left";
                parentNumber = (position - 1) / 2;
                std::cout << level << type << "(" << arr[parentNumber] << ") " << arr[position] << std::endl;
            }
            else {
                std::cout << "Ok" << std::endl;
                position = chyld_index;
                parentNumber = (position - 1) / 2;
                type = " right";
                level = static_cast<int>(log2(position + 1));
                std::cout << "Your position: ";
                std::cout << level << type << "(" << arr[parentNumber] << ") " << arr[position] << std::endl;
            }
        }
        else {
            std::cout << "Wrong command!" << std::endl;
        }
    } while (user_answer != "exit");
}