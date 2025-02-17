#include <iostream>

int fibo(int n);

int main()
{
    int userInput; 
    
    std::cout << "Hi! Input number to culculate Fibonachi number:";

    std::cin >> userInput;

    std::cout << std::endl; 

    std::cout << fibo(userInput);

    return 0;

}
int fibo(int n) {
    if (n <= 1) {
        return n;
    }
    return fibo(n - 1) + fibo(n - 2);
}