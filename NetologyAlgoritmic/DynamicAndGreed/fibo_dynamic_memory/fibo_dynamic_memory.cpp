#include <iostream>
#include <vector>

int fibo(int n);

int main()
{
    int userInput;
    std::cout << "Hello! Please input fibo number there:\n";
    std::cin >> userInput;
    std::cout << std::endl;
    std::cout << "Your fibo number:" << fibo(userInput) << std::endl;

    return 0;

}

int fibo(int n) {
    std::vector<int> fiboArr(n);
    fiboArr[0] = 1;
    fiboArr[1] = 1;
    for (int i = 2; i < n; i++) {
        fiboArr[i] = fiboArr[i - 2] + fiboArr[i - 1];
    }
    return fiboArr[n - 1];
}

