#include <iostream>
#include "IncDec.h"

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	int userNumber;
	std::string userAction;
	char symbol;

	Counter counter;
	std::cout << "Вы хотите указать начальное значение счётчика? Введите да или нет: ";
	std::cin >> userAction;

	if (userAction == "да") {
		std::cout << "Введите начальное значение счётчика: ";
		std::cin >> userNumber;

		counter.set_counter(userNumber);
	}
	std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
	std::cin >> symbol;

	while (!(symbol == 'x' || symbol == 'х')) {
		switch (symbol)
		{
		case '+':
		{
			counter.set_increment();
			break;
		}
		case '-':
		{
			counter.set_decrement();
			break;
		}
		case '=':
		{
			counter.get_actualValue();
			break;
		}
		default:
			std::cout << "Symbol is not correct!" << std::endl;
			break;
		}
		/*if (symbol == '+') {
			counter.set_increment();
		}
		else if (symbol == '-') {
			counter.set_decrement();
		}
		else if (symbol == '=') {
			counter.get_actualValue();
		}*/
		std::cout << "Введите команду ('+', '-', '=' или 'x'): ";
		std::cin >> symbol;
	};
	std::cout << "До свидания!";
}

