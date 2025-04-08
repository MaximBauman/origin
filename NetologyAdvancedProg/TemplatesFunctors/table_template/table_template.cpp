#include <iostream>

template<typename T>

class Table {
protected:
    T _rows_, _columns_;
    T** arr;
public: 
    Table(T rows, T columns) : _rows_(rows), _columns_(columns) {
        arr = new T * [rows];
        for (auto i = 0; i < rows; i++) {
            arr[i] = new T[columns];
        };
    };

    void print() {
        std::cout << _rows_ << _columns_ << std::endl;
    };
    T* operator[] (T i) const{
        return arr[i];
    };
    T* operator[](T i) {
        return arr[i];
    };
    T Size() const {
        return _rows_ * _columns_;
    };
    ~Table() {
        for (auto i = 0; i < _rows_; ++i) {
            delete[] arr[i];
        }
        delete[] arr;
    };
};

int main()
{
    Table table(2, 3); //For C++ 17+ standart, if using earlier Table<input types> name(num1, num2);
    std::cout << table.Size() << std::endl;
    table[1][2] = 10.5;
    table[0][0] = 4;
    std::cout << table[0][0] << " ";
    std::cout << table[1][2] << " ";


    return 0;
}
