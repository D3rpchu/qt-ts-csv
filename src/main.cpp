#include "ts2csv.hpp"
#include "csv2ts.hpp"

#include <iostream>

int main(int argc,  char **argv)
{
    if (argc <= 1) {
        throw std::logic_error("no argumets");
    }

    std::string file(argv[1]);
    if (file.find(".ts") != std::string::npos &&
        file.find(".csv") != std::string::npos) {
        throw std::logic_error("file not supported");
    }

    std::cout << "converting file " << file;

    if (file.find(".ts") != std::string::npos) {
        std::cout << " in csv" << std::endl;
        Ts2Csv().convert(std::move(file), "output.csv");
    } else {
        std::cout << " in ts" << std::endl;
        Csv2Ts().convert(std::move(file), "output.ts");
    }

    std::cout << "terminated" << std::endl;

    return 0;
}
