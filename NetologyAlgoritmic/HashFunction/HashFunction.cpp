#include <iostream>

int real_string_hash(std::string text, int p, int n);

int main()
{
    int p, n, hash;
    std::string user_message;
    std::cout << "Hi! It's hash function realization. If you input <exit> the program will stop." << std::endl;
    std::cout << "Please, input simple number: ";
    std::cin >> p;
    std::cout << std::endl;
    std::cout << "Please, input modul: ";
    std::cin >> n;
    std::cout << std::endl;

    do {
        std::cout << "Input sting: ";
        std::cin >> user_message;
        hash = real_string_hash(user_message, p, n);
        std::cout << "Hash: " << hash << std::endl;
    } while (user_message != "exit");
}
int real_string_hash(std::string text, int p, int n)
{
    int size = text.length();
    int mult = 1;
    long long element_hash;
    int hash_code = 0;
    size ;

    for (int i = 0; i < size; i++) {
        element_hash = mult * static_cast<int>(text[i]);
        mult *= p;
        hash_code += element_hash;
    }
    return hash_code % n;
}