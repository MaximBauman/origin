#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>

int threadCount = 5;
int workLength = 10;
int stepDelay = 1;
std::mutex m_work;

void consolePrinter(int index, int workLength, int stepDelay) {
    auto id = std::this_thread::get_id();
    auto start = std::chrono::steady_clock::now();
    std::string progressBar;

    for (int i = 0; i < workLength; i++) {
        std::this_thread::sleep_for(std::chrono::seconds(stepDelay));
        progressBar.push_back('#');
        std::lock_guard<std::mutex> lock(m_work);
        std::cout << "Thread " << index
            << " (id = " << id << "): [" << progressBar << "]\n";
    }
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> resultTime = finish - start;

    std::lock_guard<std::mutex> lock(m_work);
    std::cout << "Thread " << index << " finished in " << resultTime.count() << "s\n";
};

int main()
{
    std::vector<std::thread> threads;

    for (int i = 0; i < threadCount; i++) {
        threads.emplace_back(consolePrinter, i, workLength, stepDelay);
    }
    for (auto& i : threads) {
        i.join();
    }
    return 0;
}


