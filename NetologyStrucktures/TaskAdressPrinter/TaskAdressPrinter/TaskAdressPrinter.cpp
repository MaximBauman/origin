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

	std::cout << "Ââåäèòå êîë-âî àäğåñîâ, êîòîğûå âû õîòèòå âíåñòè: ";
	std::cin >> rows;
	std::cout << std::endl;

	Address* address_array = new Address[rows]();

	addresInput(address_array, rows);

	addresPrinter(address_array, rows);


	return 0;
}

void addresInput(Address* address_array, int rows) {

	for (int i = 0; i < rows; i++) {

		std::cout << "///////////////////////////ÂÂÅÄÈÒÅ ÄÀÍÍÛÅ ÀÄĞÅÑÀ ¹" << i+1 << "///////////////////////////" << std::endl;
		std::cout << "///////////////////////////ÓËÈÖÓ ÂÂÎÄÈÒÅ ÑËÈÒÍÎ, ÁÅÇ ÏĞÎÁÅËÀ///////////////////////////" << std::endl;

		Sleep(500);

		std::cout << "Ãîğîä: ";
		std::cin >> address_array[i].city;

		std::cout << "Óëèöà: ";
		std::cin >> address_array[i].street;

		std::cout << "Íîìåğ äîìà: ";
		std::cin >> address_array[i].homeNumber;

		std::cout << "Íîìåğ êâàğòèğû: ";
		std::cin >> address_array[i].apartmentNumber;

		std::cout << "Èíäåêñ: ";
		std::cin >> address_array[i].index;

		std::cout << "///////////////////////////ÂÛ ÂÂÅËÈ ÀÄĞÅÑ ¹" << i+1 << "///////////////////////////" << std::endl;
		std::cout << std::endl;
	}
}

void addresPrinter(Address* address_array, int rows) {
for (int i = 0; i < rows; i++) {
	std::cout << "///////////////////////////ÀÄĞÅÑ ¹" << i+1 << "///////////////////////////" << std::endl;
	std::cout << address_array[i].city << " " << address_array[i].street << " " << address_array[i].homeNumber << " " << address_array[i].apartmentNumber << " " << address_array[i].index << std::endl;
}
}
