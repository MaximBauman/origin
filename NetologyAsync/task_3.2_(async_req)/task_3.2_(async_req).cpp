#include <iostream>
#include <vector>
#include <algorithm>
#include <future>

void parallel_for_each(std::vector<int>::iterator begin, std::vector<int>::iterator end,void (*func)(int&))
{
    int length = end - begin; 

    if (length <= 2) {
        for (auto it = begin; it != end; ++it) {
            func(*it);
        }
        return;
    }

    auto middle = begin + length / 2;
    auto future = std::async(
        std::launch::async,
        parallel_for_each,
        begin,
        middle,
        func
    );
    parallel_for_each(middle, end, func);
    future.get();
}


void customFunc(int& x) {
    x += 1;
}

int main()
{
    std::vector<int> v = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    for (auto x : v) {
        std::cout << x << " ";
    }
    std::cout << std::endl;
    parallel_for_each(v.begin(), v.end(), customFunc);
    std::cout << "After custom for_each (+1): " << std::endl;
    for (auto x : v) {
        std::cout << x << " ";
    }
    return 0;
}
