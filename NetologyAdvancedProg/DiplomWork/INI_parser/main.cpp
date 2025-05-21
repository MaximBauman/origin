#include"iniParser.h"

int main()
{
    try {
        ini_parser parser("test.txt");
        parser.printer();
        std::cout << parser.get_value<double>("Section1.var1") << std::endl;
        std::cout << parser.get_value<std::string>("Section1.var2") << std::endl;
        std::cout << parser.get_value<int>("Section1.var1") << std::endl;
        std::cout << parser.get_value<double>("Section2.var3") << std::endl; // exception there
        //std::cout << parser.get_value<std::string>("Section2var2") << std::endl;

    }
    catch(std::string ex){
        std::cout << ex << std::endl;
    }
    return 0;
}

