#include "reader.hpp"

#include <fstream>
#include <sstream>

Reader::Reader(std::string &&path) : _path{std::move(path)}
{}

Reader::Reader(const std::string &path) : _path{path}
{}

std::string Reader::read() const
{
    std::ifstream ifs;
    ifs.open(_path);
    std::stringstream ss;
    ss << ifs.rdbuf();
    return ss.str();
}
