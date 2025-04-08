#include <iostream>
#include <algorithm>
#include <vector>

template<typename T>
class Counter {
private: 
    T sum = 0;
    T count = 0;
    std::vector<T> _vector_;
public: 
    Counter(std::vector<T> vector) : _vector_(vector) {

    };

    void operator()(){
        for (auto i : _vector_) {
            if (i % 3 == 0) {
               count++;
               sum += i;
            }
        }
    };
    T get_sum() {
        return sum;
    }
    T get_count() {
        return count;
    }
};


int main()
{
    std::vector<int> numbers = {4, 1, 3, 6, 25, 54};
    Counter counter(numbers);
    std::cout << counter.get_count() << "\n";
    std::cout << counter.get_sum() << "\n";
    counter();
    std::cout << counter.get_count() << "\n";
    std::cout << counter.get_sum();
}
