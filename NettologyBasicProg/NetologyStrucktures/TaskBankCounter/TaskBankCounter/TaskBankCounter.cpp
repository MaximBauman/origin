#include <iostream>
#include <locale>
#include <iomanip>

struct BankAccount
{
    long cardNumber;
    std::string Name;
    double balance;
};
// объ€вл€ем функцию апдейта баланса счЄта
void balanceUpdate(BankAccount& bankAccount, double newBalance);

int main()
{
    setlocale(LC_ALL, "Russian");

    double newCash;
    BankAccount bankAccount; //создаем экземпл€р
    // запрашиваем номер счЄта
    std::cout << "¬ведите номер счЄта: ";
    std::cin >> bankAccount.cardNumber;
    std::cout << std::endl;
    // запрашиваем »м€
    std::cout << "¬ведите им€ владельца: ";
    std::cin >> bankAccount.Name;
    std::cout << std::endl;
    // запрашиваем баланс
    std::cout << "¬ведите баланс: ";
    std::cin >> bankAccount.balance;
    std::cout << std::endl;

    // запрашиваем новый баланс

    std::cout << "¬ведите новый баланс: ";
    std::cin >> newCash;
    std::cout << std::endl;

    balanceUpdate(bankAccount, newCash);

    std::cout << bankAccount.Name << " " << bankAccount.cardNumber << " " << std::fixed << std::setprecision(2) << bankAccount.balance << std::endl;

}

void balanceUpdate(BankAccount& bankAccount, double newBalance) {
    bankAccount.balance = newBalance;
}
