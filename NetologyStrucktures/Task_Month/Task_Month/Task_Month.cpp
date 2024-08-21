#include <iostream>

enum class Month {
    January = 1,
    February,
    March,
    April,
    May,
    June,
    July,
    August,
    September,
    October,
    November,
    December
};

void monthParser(int userNumber);

int main()
{
    setlocale(LC_ALL, "Russian");
    int monthNumber;

    while (true) {
        std::cout << "������� ����� ������: ";
        std::cin >> monthNumber;
        if (monthNumber < 0 || monthNumber > 12) {
            std::cout << "����������, ������� ����� � ��������� �� 1 �� 12. \n\r ��� ������ �� ��������� ������� ����� 0!" << std::endl;
        }
        else if (monthNumber == 0) {
            std::cout << "�� ��������" << std::endl;
            break;
            return 0;
        }
        else {
            monthParser(monthNumber);
        }
    }
    return 0;
}
void monthParser(int userNumber) {
    Month season = static_cast<Month>(userNumber);
    switch (season) {
    case Month::January:
        std::cout << "������" << std::endl;
        break;
    case Month::February:
        std::cout << "�������" << std::endl;
        break;
    case Month::March:
        std::cout << "����" << std::endl;
        break;
    case Month::April:
        std::cout << "������" << std::endl;
        break;
    case Month::May:
        std::cout << "���" << std::endl;
        break;
    case Month::June:
        std::cout << "����" << std::endl;
        break;
    case Month::July:
        std::cout << "����" << std::endl;
        break;
    case Month::August:
        std::cout << "������" << std::endl;
        break;
    case Month::September:
        std::cout << "��������" << std::endl;
        break;
    case Month::October:
        std::cout << "�������" << std::endl;
        break;
    case Month::November:
        std::cout << "������" << std::endl;
        break;
    case Month::December:
        std::cout << "�������" << std::endl;
        break;
    default:
        break;
    }
}

