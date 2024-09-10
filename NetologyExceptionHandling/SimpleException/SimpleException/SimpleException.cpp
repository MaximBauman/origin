#include <iostream>

int function(std::string str, int forbidden_length) {
    if (str.length() == forbidden_length) {
        std::exception ex("bad_length");
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
        catch (std::exception ex) {
            std::cout << ex.what() << std::endl;
            break;
        }
    }
    
}
