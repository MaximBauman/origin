#include <iostream>

class Calculator
{
private:
	double num1;
	double num2;

public:
	Calculator() : num1(0), num2(0) {};


	

public:
	bool set_num1(int num1) {
		this->num1 = num1;
		if (num1 == 0) {
			return false;
		}
		else {
			return true;
		}
	};
	bool set_num2(int num2) {
		this->num2 = num2;

		if (num2 == 0) {
			return false;
		}
		else {
			return true;
		}
	};

	double add() {
		return num1 + num2;
	};
	double multiply() {
		return num1 * num2;
	};
	double subtract_1_2() {
		return num1 - num2;
	};
	double subtract_2_1() {
		return num2 - num1;
	};
	double divde_1_2() {
		return num1 / num2;
	};
	double divde_2_1() {
		return num2 / num2;
	};
	
};

int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	double num_1; 
	double num_2;

	Calculator calculator;

	while (true) {
		std::cout << "Введите num1: ";
		std::cin >> num_1;
		while (!calculator.set_num1(num_1))
		{
			std::cout << "Неверный ввод!" << std::endl;
			std::cout << "Введите num1: ";
			std::cin >> num_1;
		}
		std::cout << "Введите num2: ";
		std::cin >> num_2;
		while (!calculator.set_num2(num_2))
		{
			std::cout << "Неверный ввод!" << std::endl;
			std::cout << "Введите num2: ";
			std::cin >> num_2;
		}
		std::cout << "num1 + num2 = " << calculator.add() << std::endl;
		std::cout << "num1 * num2 = " << calculator.multiply() << std::endl;
		std::cout << "num1 - num2 = " << calculator.subtract_1_2() << std::endl;
		std::cout << "num2 - num1 = " << calculator.subtract_2_1() << std::endl;
		std::cout << "num1 / num2 = " << calculator.divde_1_2() << std::endl;
		std::cout << "num2 / num1 = " << calculator.divde_2_1() << std::endl;

	}

}
