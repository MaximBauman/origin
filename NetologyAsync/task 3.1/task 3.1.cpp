#include <iostream>
#include <vector>
#include <future>
#include <algorithm>

void findMinAsync(std::vector<int> v,int start,std::promise<int> p)
{
    int minIndex = start;

    for (int i = start; i < v.size(); i++) {
        if (v[i] < v[minIndex])
            minIndex = i;
    }

    p.set_value(minIndex);
}

void SelectSortAsync(std::vector<int>& v)
{
    for (int i = 0; i < v.size(); i++) {

        std::promise<int> p;
        std::future<int> f = p.get_future();

        std::async(std::launch::async, findMinAsync, v, i, std::move(p));

        int minIndex = f.get();

        std::swap(v[i], v[minIndex]);
    }
}

int main()
{
    std::vector<int> data;
    for (auto i = 0; i < 20; i++) {
        data.push_back(rand() % 1000);
    }

    std::cout << "Before sort: ";
    for (int x : data)
        std::cout << x << " ";
    std::cout << std::endl;

    SelectSortAsync(data);

    std::cout << "After sort:  ";
    for (int x : data)
        std::cout << x << " ";
    std::cout << std::endl;

    return 0;
}
