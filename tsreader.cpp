#include "tsreader.hpp"

#include <fstream>

std::string TSReader::do_it(std::string &&filename) const
{
    std::ifstream ifs;
    ifs.open(std::move(filename));
    std::string all;
    std::string line;
    while (std::getline(ifs, line)) {
        all += line;
    }
    return all;
}
