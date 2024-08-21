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
        std::cout << "Введите номер месяца: ";
        std::cin >> monthNumber;
        if (monthNumber < 0 || monthNumber > 12) {
            std::cout << "Пожалуйста, введите число в диапазоне от 1 до 12. \n\r Для выхода из программы введите число 0!" << std::endl;
        }
        else if (monthNumber == 0) {
            std::cout << "До свидания" << std::endl;
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
        std::cout << "Январь" << std::endl;
        break;
    case Month::February:
        std::cout << "Февраль" << std::endl;
        break;
    case Month::March:
        std::cout << "Март" << std::endl;
        break;
    case Month::April:
        std::cout << "Апрель" << std::endl;
        break;
    case Month::May:
        std::cout << "Май" << std::endl;
        break;
    case Month::June:
        std::cout << "Июнь" << std::endl;
        break;
    case Month::July:
        std::cout << "Июль" << std::endl;
        break;
    case Month::August:
        std::cout << "Август" << std::endl;
        break;
    case Month::September:
        std::cout << "Сентябрь" << std::endl;
        break;
    case Month::October:
        std::cout << "Октябрь" << std::endl;
        break;
    case Month::November:
        std::cout << "Ноябрь" << std::endl;
        break;
    case Month::December:
        std::cout << "Декабрь" << std::endl;
        break;
    default:
        break;
    }
}

