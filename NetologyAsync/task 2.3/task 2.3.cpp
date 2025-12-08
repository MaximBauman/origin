#include <iostream>
#include <mutex>
#include <thread>

class Data {
public:
    Data(int a) : info(a) {};
    int info;
    std::mutex m;
};

void swapDataLock(Data& obj1, Data& obj2) {
    std::cout << "Before swap lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;
    std::lock(obj1.m, obj2.m);

    std::lock_guard<std::mutex> lock1(obj1.m, std::adopt_lock_t{});
    std::lock_guard<std::mutex> lock2(obj2.m, std::adopt_lock_t{});
    std::swap(obj1.info, obj2.info);
    std::cout << "After swap lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;
    std::cout << std::endl;

}

void swapDataScoped_lock(Data& obj1, Data& obj2) {
    std::cout << "Before swap scoped_lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;

    std::scoped_lock lock(obj1.m, obj2.m);
    std::swap(obj1.info, obj2.info);
    std::cout << "After swap scoped_lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;
    std::cout << std::endl;

}

void swapDataUnique_lock(Data& obj1, Data& obj2) {
    std::cout << "Before swap unique_lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;

    std::unique_lock lock1{ obj1.m, std::defer_lock };
    std::unique_lock lock2{ obj2.m, std::defer_lock };
    std::lock(lock1, lock2);
    std::swap(obj1.info, obj2.info);
    std::cout << "After swap unique_lock: object 1 value = " << obj1.info << ", object 2 value = " << obj2.info << std::endl;
    std::cout << std::endl;

}

int main()
{
    Data a(5);
    Data b(10);
    Data c(23);
    Data d(55);
    Data e(1);
    Data f(100);

    swapDataLock(a, b);
    swapDataScoped_lock(c, d);
    swapDataUnique_lock(e, f);
}


