#include "ts2csv.hpp"

#include <iostream>

int main(int argc,  char **argv)
{
    if (argc <= 1) {
        std::cerr << "no arguments" << std::endl;
        return 0;
    }

    std::string file(argv[1]);
    if (file.find(".ts") == std::string::npos) {
        std::cerr << "file not supported" << std::endl;
        return 0;
    }

    if (file.find(".ts") != std::string::npos) {
        std::cout << "converting file " << file << " in csv" << std::endl;
        Ts2Csv ts2csv(std::move(file));
        ts2csv.convert();
    }

    std::cout << "terminated" << std::endl;

    return 0;
}
