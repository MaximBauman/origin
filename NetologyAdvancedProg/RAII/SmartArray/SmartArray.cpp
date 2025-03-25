#include <iostream>

class Smart_Array {
public:
    Smart_Array(int size){
        this->size = size;
        arr = new int[size];
    }
    void add_element(int element) {
        if (position != size) {
            arr[position] = element;
            std::cout << "Success!" << std::endl;
            position++;
        }
        else {
            throw std::overflow_error(size_exception);
        }
    }
    int get_element(int index) {
        if (index >= size) {
            throw std::out_of_range(index_exception);
        }
        else {
            return arr[index];
        }
    }
    void printer() {
        for (int i = 0; i < size; i++) {
            std::cout << arr[i];
        }
        std::cout << std::endl;
    }
private: 
    int size = 0;
    int position = 0;
    int* arr = nullptr;
    std::string size_exception = "Array is full! Create new object!";
    std::string index_exception = "Uncorrected index! Please, try again!";

public:
    ~Smart_Array() {
        delete[] arr;
    };
};

int main()
{
    int size = 0;

    try {
        Smart_Array arr(5);
        arr.add_element(1);
        arr.add_element(4);
        arr.add_element(155);
        arr.add_element(14);
        arr.add_element(15);
        arr.add_element(69);
        std::cout << arr.get_element(1) << std::endl;
        std::cout << arr.get_element(13) << std::endl;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }

}

