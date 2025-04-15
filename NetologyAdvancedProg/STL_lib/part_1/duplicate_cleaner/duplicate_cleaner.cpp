
#include <iostream>
#include <vector>
#include <set>

int main()
{
    int user_input;
    std::vector<int> myVec;
    std::cout << "Please, input vector size: ";
    std::cin >> user_input;
    myVec.reserve(user_input);

    std::cout << "Now, fill vector: ";
    std::set<int> mySet;
    for (int i = 0; i < myVec.capacity(); i++) {
        std::cin >> user_input;
        myVec.push_back(user_input);
        mySet.insert(myVec[i]);
    }
   
    for (auto i = mySet.rbegin(); i != mySet.rend(); i++) {
        std::cout << *i << " ";
    }

    return 0;
}

