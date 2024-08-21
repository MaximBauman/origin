#include <iostream>
#include <string>
#include <windows.h>



struct Address
{
	std::string city;
	std::string street;
	int homeNumber;
	int apartmentNumber;
	int index;

};

void addresInput(Address* address_array,const int rows);

void addresPrinter(Address* address_array,const int rows);


int main()
{
	system("chcp 1251");
	setlocale(LC_ALL, "Russian");

	int rows;

	std::cout << "������� ���-�� �������, ������� �� ������ ������: ";
	std::cin >> rows;
	std::cout << std::endl;

	Address* address_array = new Address[rows]();

	addresInput(address_array, rows);

	addresPrinter(address_array, rows);


	return 0;
}

void addresInput(Address* address_array, int rows) {

	for (int i = 0; i < rows; i++) {

		std::cout << "///////////////////////////������� ������ ������ �" << i+1 << "///////////////////////////" << std::endl;
		std::cout << "///////////////////////////����� ������� ������, ��� �������///////////////////////////" << std::endl;

		Sleep(500);

		std::cout << "�����: ";
		std::cin >> address_array[i].city;

		std::cout << "�����: ";
		std::cin >> address_array[i].street;

		std::cout << "����� ����: ";
		std::cin >> address_array[i].homeNumber;

		std::cout << "����� ��������: ";
		std::cin >> address_array[i].apartmentNumber;

		std::cout << "������: ";
		std::cin >> address_array[i].index;

		std::cout << "///////////////////////////�� ����� ����� �" << i+1 << "///////////////////////////" << std::endl;
		std::cout << std::endl;
	}
}

void addresPrinter(Address* address_array, int rows) {
for (int i = 0; i < rows; i++) {
	std::cout << "///////////////////////////����� �" << i+1 << "///////////////////////////" << std::endl;
	std::cout << address_array[i].city << " " << address_array[i].street << " " << address_array[i].homeNumber << " " << address_array[i].apartmentNumber << " " << address_array[i].index << std::endl;
}
}
