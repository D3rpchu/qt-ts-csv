#include "reader.hpp"

#include <fstream>

Reader::Reader(std::string &&path) : _path{std::move(path)}
{}

Reader::Reader(const std::string &path) : _path{path}
{}

std::string Reader::read() const
{
    std::ifstream ifs;
    ifs.open(std::move(_path));
    std::string all;
    std::string line;
    while (std::getline(ifs, line)) {
        all += line;
        all += "\n";
    }
    return all;
}
