#include <iostream>
#include <mutex>
#include <thread>
#include <chrono>
#include <vector>
#include <Windows.h>
#include <string>

int threadCount = 5;
int workLength = 10;
int stepDelay = 1000;
std::mutex m_work;

void setCursorPosition(int x, int y) {
    HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
    COORD setCursorPos = { y, x };
    SetConsoleCursorPosition(hConsole, setCursorPos);

}

void functionToLoadThread() {
    int load = 1 + rand() % 100;
    double x = 0;

    for (int i = 0; i < load * 1000000; i++) {
        x += std::sqrt(i * 0.1);
    }
}

void consolePrinter(int index, int workLength, int stepDelay) {
    auto id = std::this_thread::get_id();
    auto start = std::chrono::steady_clock::now();
    std::string progressBar(workLength, ' ');

    int row, colId, barStart, colTime;
    row = index + 1;
    colId = 6;
    barStart = 18;
    colTime = barStart + workLength + 15;

    for (int i = 0; i < workLength; i++) {
        std::this_thread::sleep_for(std::chrono::milliseconds(stepDelay + rand() % 500));
        std::lock_guard<std::mutex> lock(m_work);
        setCursorPosition(row, colId);
        std::cout << id;
        progressBar[i] = '#';

        functionToLoadThread();

        setCursorPosition(row, barStart);
        std::cout << progressBar << "] ";
 
    }
    auto finish = std::chrono::steady_clock::now();
    std::chrono::duration<double> resultTime = finish - start;

    std::lock_guard<std::mutex> lock(m_work);
    std::cout <<  resultTime.count() << "s\n";
};

int main()
{
    std::vector<std::thread> threads; 

    std::cout << "#     id         Progress     Time" << std::endl;
    for (int i = 0; i < threadCount; i++) {
        std::cout << i << "               " << "[           ]" << std::endl;
    };
    for (int i = 0; i < threadCount; i++) {
        
        threads.emplace_back(consolePrinter, i, workLength, stepDelay);
    }
    for (auto& i : threads) {
        i.join();
    }

    setCursorPosition(11, 0);
    return 0;
}

