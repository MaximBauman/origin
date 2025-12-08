

#include <iostream>
#include <thread>
#include <chrono>
#include <atomic>

std::atomic<int> counter = 0;
static std::atomic<int> maxClients{ 10 };

void clientsStandUpThread() {
    do {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        int status_counter = counter.load();
        if (status_counter < maxClients) {
            counter.fetch_add(1, std::memory_order_consume);
            std::cout << "Client add to thread" << std::endl;
            std::cout << "Total clients: " << counter << std::endl;
        }
        else {
            std::cout << "Thread is full, can't add new client" << std::endl;
        }
    } while (true);
};
void operatorGetClient() {
    do {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        int status_counter = counter.load();
        if (status_counter > 0) {
            counter.fetch_sub(1, std::memory_order_consume);
            std::cout << "Operator - serrved client" << std::endl;
            std::cout << "Total clients: " << counter << std::endl;
        }
        else {
            std::cout << "Client base is empty" << std::endl;
        }
    } while (true);

}

int main()
{


    std::thread t1(clientsStandUpThread);
    std::thread t2(operatorGetClient);
    t1.join();
    t2.join();
    return 0;
}


