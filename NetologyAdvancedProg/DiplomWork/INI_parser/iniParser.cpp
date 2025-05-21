#include "iniParser.h"


ini_parser::ini_parser(std::string fileName) : _file_name_(fileName) {
        _file_.open(fileName);
        if (_file_.is_open()) {
            std::cout << "||||||||||||||||||||||||||||||||||| Start parsing |||||||||||||||||||||||||||||||||||" << std::endl;
            start_parsing(_file_);
        }
        else {
            throw std::string("Can't open file");
        };
    };

void ini_parser::start_parsing(std::ifstream& file) {
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

void ini_parser::printer() {
    for (auto& i : section) {
        std::cout << "[" << i.first << "]" << std::endl;
        for (auto& k : i.second) {
            std::cout << k.first << "=" << k.second << std::endl;
        }
        std::cout << std::endl;
        }
}

ini_parser::~ini_parser() {
        if (_file_.is_open()) {
            _file_.close();
        };
    }


    //Поиск значения по итератору
std::string ini_parser::get_value_string(const std::string& input_section, const std::string& var) {
    auto section_itr = section.find(input_section);
    if (section_itr == section.end()) {
        throw std::string("Can't find section");
    }
    auto var_itr = section_itr->second.find(var);
    if (var_itr == section_itr->second.end()) {
        throw std::string("Can't find parametr in " + input_section);
    }

    return var_itr->second;
}
   