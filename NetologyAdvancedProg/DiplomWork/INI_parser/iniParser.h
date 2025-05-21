#pragma once
#include <iostream>
#include <unordered_map>
#include <fstream>
#include <string>
#include <exception>

class ini_parser {
private:
    std::string _file_name_;
    std::ifstream _file_;
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> section;

public:
    ini_parser(std::string);

    void start_parsing(std::ifstream&);

    void printer();

    ~ini_parser();
    //Шаблон пришлось реализовать прямо в заголовочном файле, иначе возникает ошибка линковки
    template<typename T>
    T get_value(std::string name) {
        T value;
        std::string section_name;
        std::string id;
        if (name.find('.') == std::string::npos) {
            throw std::string("Wrong input to search value of section");
        }
        else {
            size_t pos = name.find('.');
            size_t last_elem = name.size();

            section_name = name.substr(0, pos);
            id = name.substr(pos + 1, last_elem);
        }

        std::cout << "Search started in: " << section_name << " with parameter " << id << ". Result: ";

        std::string result = get_value_string(section_name, id);

        if constexpr (std::is_same<int, T>::value) {
            value = std::stoi(result);
        }
        else if constexpr (std::is_same<double, T>::value) {
            value = std::stod(result);
        }
        else if constexpr (std::is_same<std::string, T>::value) {
            value = result;
        }
        else
        {
            static_assert(sizeof(T) == -1, "no implementation for this type!");
        }
        return value;
    }
private:
    //Поиск значения по итератору
    std::string get_value_string(const std::string&, const std::string&);
};