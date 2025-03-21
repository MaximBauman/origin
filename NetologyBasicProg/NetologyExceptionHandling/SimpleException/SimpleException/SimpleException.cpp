#include <iostream>

class MyException : public std::exception {
    public: 
        const char* what() const override {
            return "bad_length";
        }
};

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        throw MyException();
    }
    else {
        return str.length();
    }
};



int main()
{
    int length = 3;
    int actualLength;

    std::string word;
    std::cout << "Input length: ";
    std::cin >> length;
    while (true) {
        try { 
            std::cout << "Input word: ";
            std::cin >> word;
            actualLength = function(word, length);
            std::cout << "Length word \"" << word << "\"" << " is " << actualLength << std::endl;
        }
        catch (MyException& ex) {
            std::cout << "Wrong length!" << std::endl;
            break;
        }
        catch (...) {
            std::cout << "something wrong!" << std::endl;
        }
    }
    
}
