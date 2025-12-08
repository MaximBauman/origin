#include <iostream>
#include <thread>
#include <chrono>
#include <cstdlib>

int arr1[1000000];
int arr2[1000000];
int result[1000000];

void fillArrays(int size)
{
    for (int i = 0; i < size; i++) {
        arr1[i] = rand() % 100;
        arr2[i] = rand() % 100;
    }
}

void sumPart(int start, int end)
{
    for (int i = start; i < end; i++) {
        result[i] = arr1[i] + arr2[i];
    }
}

double runSum(int threadsCount, int size)
{
    fillArrays(size);

    std::thread threads[16];
    int part = size / threadsCount;

    auto start = std::chrono::high_resolution_clock::now();

    for (int t = 0; t < threadsCount; t++) {
        int begin = t * part;
        int end;
        if (t == threadsCount - 1)
            end = size;
        else
            end = begin + part;


        threads[t] = std::thread(sumPart, begin, end);
    }

    for (int t = 0; t < threadsCount; t++) {
        threads[t].join();
    }

    auto finish = std::chrono::high_resolution_clock::now();
    std::chrono::duration<double> elapsed = finish - start;

    return elapsed.count();
}

int main()
{
    std::cout << "Number of hardware cores: "
        << std::thread::hardware_concurrency() << "\n\n";

    int sizes[4] = { 1000, 10000, 100000, 1000000 };
    int threadCounts[5] = { 1, 2, 4, 8, 16 };

    std::cout << "                  1000        10000        100000       1000000\n";

    for (int i = 0; i < 5; i++)
    {
        int t = threadCounts[i];

        if (t == 1)  std::cout << "1 thread      ";
        if (t == 2)  std::cout << "2 threads     ";
        if (t == 4)  std::cout << "4 threads     ";
        if (t == 8)  std::cout << "8 threads    ";
        if (t == 16) std::cout << "16 threads   ";

        for (int j = 0; j < 4; j++) {
            double time = runSum(t, sizes[j]);
            std::cout << time << "s   ";
        }

        std::cout << std::endl;
    }

    return 0;
}