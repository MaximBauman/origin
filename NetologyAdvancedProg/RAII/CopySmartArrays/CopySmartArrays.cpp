#include <iostream>

class Smart_Array {
public:
    Smart_Array(int size) {
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

    Smart_Array& operator=(const Smart_Array& other) {
        if (this != &other) {
            delete[] arr;
            size = other.size;
            position = other.position;
            arr = new int[size];
            for (int i = 0; i < position; i++) {
                arr[i] = other.arr[i];
            }
        }
        return *this;
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

        Smart_Array new_arr(2);
        new_arr.add_element(44);
        new_arr.add_element(34);
        
        arr = new_arr;
    }
    catch (const std::exception& ex) {
        std::cout << ex.what() << std::endl;
    }
    return 0;
}

