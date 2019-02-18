#include "Reader.hpp"

#include <fstream>
#include <sstream>

std::string Reader::read(std::string &&filename) const
{
    std::ifstream ifs;
    ifs.open(filename);
    std::stringstream ss;
    ss << ifs.rdbuf();
    auto tmp = ss.str();
    return ss.str();
}
