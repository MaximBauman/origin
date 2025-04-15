#include <iostream>

template <typename T>

class Vector {
private:
    T* _arr_;
    T _capacity_;
    T _size_;

public: 
    Vector(T size) : _size_(size), _capacity_(size * 2) {
        _arr_ = new T[_capacity_];
        _size_ = 0;
    }

    T at(int index) {
        if (index <= _size_) {
            return _arr_[index];
        }
        else {
            std::cout << "wrong index!" << std::endl;
        }
    }

    void push_back(T value) {
        if (_size_ < _capacity_) {
            _arr_[_size_] = value;
            _size_++;
        }
        else if (_size_ >= _capacity_) {
            _capacity_ *= 2;
            T* newArr = new T[_capacity_];

            for (int i = 0; i < _size_; i++) {
                newArr[i] = _arr_[i];  
            }

            delete[] _arr_; 
            _arr_ = newArr;  
            _arr_[_size_] = value;
            _size_++;
        }



    }

    T size() {
        return _size_;
    }

    T capacity() {
        return _capacity_;
    }

    ~Vector() {
        delete _arr_;
    }

};

int main()
{
    Vector myVec(3);
    std::cout << "Size: " << myVec.size() << std::endl;
    myVec.push_back(5);
    myVec.push_back(6);
    myVec.push_back(3);
    std::cout << "Capacity: " << myVec.capacity() << std::endl;
    myVec.push_back(11);
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;

    std::cout << myVec.at(3) << std::endl;
    std::cout << myVec.at(1) << std::endl;
    myVec.push_back(325);
    myVec.push_back(12);
    myVec.push_back(99);
    std::cout << myVec.at(4) << std::endl;
    std::cout << "Size: " << myVec.size() << std::endl;
    std::cout << "Capacity: " << myVec.capacity() << std::endl;
    
        

    return 0;
}

