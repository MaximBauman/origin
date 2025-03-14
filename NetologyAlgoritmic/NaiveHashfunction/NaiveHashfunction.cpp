#include <iostream>

int simple_string_hash(std::string text);


int main()
{
    std::string user_message;
    std::cout << "Hi! It's naive hash function realization. If you input <exit> the program will stop." << std::endl;
    do {
        std::cout << "Input string: ";
        std::cin >> user_message;
        int hash = simple_string_hash(user_message);
        std::cout << "Naive string hash = " << hash << std::endl;
    } while (user_message != "exit");

    return 0;
}

int simple_string_hash(std::string text) {
    int summ = 0;
    int size = text.length();
    for (int i = 0; i < size; i++) {
        summ += static_cast<int>(text[i]);
    }
    return summ;
}
