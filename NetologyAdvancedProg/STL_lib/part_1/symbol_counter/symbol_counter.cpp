#include <iostream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>
#include <map>

void counter_func(std::list<char>& list);

int main()
{
    std::string user_input;
    do {
        
        std::cout << "Input string or exit to exit: ";
        getline(std::cin, user_input);
        std::list<char> inputArr;
        for (auto i : user_input) {
            inputArr.push_back(i);
        }
        counter_func(inputArr);
    } while (user_input != "exit");

    return 0;
}

void counter_func(std::list<char>& list) {
    std::map<char, int> MyMap;
    for (char i : list) {
        MyMap[i]++;
    }
    std::vector<std::pair<char, int>> myVec(MyMap.begin(), MyMap.end());
    std::sort(myVec.begin(), myVec.end(), [](auto i, auto j) {return i.second > j.second; });

    for (auto i : myVec) {
        std::cout << i.first << " : " << i.second << std::endl;
    }
}
