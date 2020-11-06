#include <iostream>
#include "sap.hpp"

int main(int argc, char* argv[])
{
    Sap simple_parser(argc, argv);

    std::vector<std::string> args;
    simple_parser.getArgs(args,"-v");

    std::cout << "Arguments:" << std::endl;
    for(const auto &it : args)
    {
        std::cout << it << std::endl;
    }
    std::cout << "End of main" << std::endl;
    return 0;
}
