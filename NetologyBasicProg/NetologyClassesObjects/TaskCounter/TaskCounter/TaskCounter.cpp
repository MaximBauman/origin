#include <iostream>

class Counter
{
public:
	Counter() : n_counter(1) {};

	void set_counter(int num) {
		this->n_counter = num;
	};
	void set_increment() {
		n_counter++;
	}
	void set_decrement() {
		n_counter--;
	}
	void get_actualValue() {
		std::cout << n_counter << std::endl;
	}


private:
	int n_counter;
};


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

	while (!(symbol == 'x' || symbol == 'х')){
		switch (symbol)
		{
		case '+' :
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


