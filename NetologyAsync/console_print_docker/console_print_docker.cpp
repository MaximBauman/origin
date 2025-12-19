#include <iostream>
#include <fstream>
#include <vector>
#include <string>

class Address {
public:
    Address(const std::string& city, const std::string& street, int house, int apartment)
        : city(city), street(street), house(house), apartment(apartment) {
    }

    std::string get_output_address() const {
        return city + ", " + street + ", " + std::to_string(house) + ", " + std::to_string(apartment);
    }

private:
    std::string city;
    std::string street;
    int house;
    int apartment;
};

int main() {
    system("chcp 1251");
    setlocale(LC_ALL, "Russian");

    int rows;
    std::string city;
    std::string street;
    int house;
    int apartment;

    std::ifstream inputFile("in.txt");
    std::ofstream outputFile("out.txt");


    if (!inputFile.is_open()) {
        std::cout << "Can't open file" << std::endl;
        return 1;
    }

    inputFile >> rows;
    std::vector<Address> address;

    for (int i = 0; i < rows; i++) {
        inputFile >> city >> street >> house >> apartment;
        address.emplace_back(city, street, house, apartment);
    }

    if (!outputFile.is_open()) {
        std::cout << "Can't open output file!" << std::endl;
        return 1;
    }
    outputFile << rows << std::endl;
    for (int i = rows - 1; i >= 0; i--) {
        outputFile << address[i].get_output_address() << std::endl;
    }

    inputFile.close();
    outputFile.close();
    return 0;
}