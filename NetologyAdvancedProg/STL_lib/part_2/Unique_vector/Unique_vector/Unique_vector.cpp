#include <iostream>
#include <algorithm>
#include <vector>

std::vector<int> vector_filler();
void duplicate_cleanup(std::vector<int> V);

int main()
{
    std::vector<int> V1;
    std::string again = "continue";
    std::string exit = "exit";
    std::string user_string;

    std::cout << "Hi! This is a duplicate cleanup program. " << std::endl; 
    do{
        std::vector<int> V1 = vector_filler();
        duplicate_cleanup(V1);
        std::cout << "If you won't to input new vector, enter continue, or exit to stop program: ";
        std::cin >> user_string;
    } while (user_string != exit);

    return 0;
}

std::vector<int> vector_filler() {
    std::vector<int> V;
    int user_int;
    int vector_size;
    std::cout << "First, enter how many numbers you are entering and start entering the numbers for the vector there: ";
    std::cin >> vector_size;
    for (auto i = 0; i < vector_size; i++) {
        std::cin >> user_int;
        V.push_back(user_int);
    }
    std::cout << "Your vector: ";
    for (auto i : V) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
    return V;
}

void duplicate_cleanup(std::vector<int> V) {
    std::sort(V.begin(), V.end());
    std::cout << "Sorted vector: ";
    for (auto i : V) {
        std::cout << i << " ";
    }
    std::cout << std::endl;

    auto it = std::unique(V.begin(), V.end());
    V.erase(it, V.end());
    std::cout << "Vector with out duplicate's: ";
    for (auto i : V) {
        std::cout << i << " ";
    }
    std::cout << std::endl;
};
