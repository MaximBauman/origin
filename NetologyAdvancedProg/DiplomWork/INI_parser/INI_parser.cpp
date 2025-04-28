#include <iostream>
#include <unordered_map>
#include <algorithm>
#include <fstream>
#include <string>
#include <vector>
#include <exception>

class ini_parser {
private:
    std::string _file_name_;
    std::ifstream _file_; 
    std::unordered_map<std::string, std::unordered_map<std::string, std::string>> section;

public:
    ini_parser(std::string fileName) : _file_name_(fileName) {
        _file_.open(fileName);
        if (_file_.is_open()) {
            std::cout << "Start parsing" << std::endl;
            start_parsing(_file_);
        }
        else {
            throw std::string("Can't open file");
        };
    };

    void start_parsing(std::ifstream& file) {
        std::string line;
        std::string section_name;
        while(std::getline(file, line)){
            if (line[0] == ';' || line.empty()) {
                continue;
            };
            if (line.front() == '[' && line.back() == ']') {
                section_name = line.substr(1, line.size() - 2);
                section[section_name];
            }
            else {
                std::string id;
                std::string id_value;
                if (line.find('=') != std::string::npos) {
                    if (line.find(';') != std::string::npos) {
                        line.erase(line.find(';'), line.back());
                        id = line.substr(0, line.find('='));
                        id_value = line.substr(line.find('=') + 1, line.back());
                    }
                    else {
                        id = line.substr(0, line.find('='));
                        id_value = line.substr(line.find('=') + 1, line.back());
                    }
                }
                if (!section_name.empty()) {
                    section[section_name][id] = id_value;
                }
            }
        }
    }

    void printer() {
        for (auto& i : section) {
            std::cout << "[" << i.first << "]" << std::endl;
            for (auto& k : i.second) {
                std::cout << k.first << "=" << k.second << std::endl;
            }
            std::cout << std::endl;
        }
    }

    ~ini_parser() {
        if (_file_.is_open()) {
            _file_.close();
        };
    }
    template<typename T>
    T get_value(std::string name) {
        T value;
        if (name.find('.') == std::string::npos) {
            throw std::string("Wrong input to search value of section");
        }
        else {
            std::string section_name;
            std::string id;

            section_name = name.substr(name.front(), name.find('.'));
            id = name.substr(name.find('.') + 1, name.back());

            auto section_iterator = section.find(section_name);
            auto id_iterator = section_iterator->second.find(id);
            if (section_iterator == section.end()) {
                throw std::string("Wrong section input!");
            }
            if (id_iterator == section_iterator->second.end()) {
                throw std::string("ID not found");
            }
            value = std::stod(id_iterator->second); // THIS ???
        }
    }
    
};

int main()
{
    try {
        ini_parser parser("tst.txt");
        parser.printer();
        //auto value = parser.get_value<double>("Section1.var1");
    }
    catch(std::string ex){
        std::cout << ex << std::endl;
    }
    return 0;
}

