

#include <iostream>
#include <thread>
#include <chrono>

int counter = 0;
int maxClients = 10;

void clientsStandUpThread() {
    do {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        if (counter < maxClients) {
            counter++;
            std::cout << "Client add to thread" << std::endl;
        }
        else {
            std::cout << "Thread is full, can't add new client" << std::endl;
        }
    } while (true);
};
void operatorGetClient(){
    do {
        std::this_thread::sleep_for(std::chrono::seconds(2));
        if (counter > 0) {
            counter--;
            std::cout << "Operator - serrved client" << std::endl;
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


