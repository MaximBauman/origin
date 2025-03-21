#include <iostream>
#include <locale>
#include <iomanip>

struct BankAccount
{
    long cardNumber;
    std::string Name;
    double balance;
};
// ��������� ������� ������� ������� �����
void balanceUpdate(BankAccount& bankAccount, double newBalance);

int main()
{
    setlocale(LC_ALL, "Russian");

    double newCash;
    BankAccount bankAccount; //������� ���������
    // ����������� ����� �����
    std::cout << "������� ����� �����: ";
    std::cin >> bankAccount.cardNumber;
    std::cout << std::endl;
    // ����������� ���
    std::cout << "������� ��� ���������: ";
    std::cin >> bankAccount.Name;
    std::cout << std::endl;
    // ����������� ������
    std::cout << "������� ������: ";
    std::cin >> bankAccount.balance;
    std::cout << std::endl;

    // ����������� ����� ������

    std::cout << "������� ����� ������: ";
    std::cin >> newCash;
    std::cout << std::endl;

    balanceUpdate(bankAccount, newCash);

    std::cout << bankAccount.Name << " " << bankAccount.cardNumber << " " << std::fixed << std::setprecision(2) << bankAccount.balance << std::endl;

}

void balanceUpdate(BankAccount& bankAccount, double newBalance) {
    bankAccount.balance = newBalance;
}
