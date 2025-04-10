#include <iostream>

template<typename T, typename T2>

class Table {
protected:
    T _rows_, _columns_;
    T2** arr;
public: 
    Table(T rows, T columns) : _rows_(rows), _columns_(columns) {
        arr = new T2 * [rows];
        for (auto i = 0; i < rows; i++) {
            arr[i] = new T2[columns];
        };
    };

    void print() {
        std::cout << _rows_ << _columns_ << std::endl;
    };
    T2* operator[] (T i) const{
        return arr[i];
    };
    T2* operator[](T i) {
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
    Table<int, int> table(2, 3); //For C++ 17+ standart, if using earlier Table<input types> name(num1, num2);
    std::cout << table.Size() << std::endl;
    table[1][2] = 10;
    table[0][0] = 4;
    std::cout << table[0][0] << " ";
    std::cout << table[1][2] << " " << std::endl;

    Table<int, double> table2(2, 3); //For C++ 17+ standart, if using earlier Table<input types> name(num1, num2);
    std::cout << table2.Size() << std::endl;
    table2[1][2] = 10.5;
    table2[0][0] = 4;
    std::cout << table2[0][0] << " ";
    std::cout << table2[1][2] << " " << std::endl;

    Table<int, float> table3(2, 3); //For C++ 17+ standart, if using earlier Table<input types> name(num1, num2);
    std::cout << table3.Size() << std::endl;
    table3[1][2] = 10.5231;
    table3[0][0] = 4.321;
    std::cout << table3[0][0] << " ";
    std::cout << table3[1][2] << " " << std::endl;

    return 0;
}
