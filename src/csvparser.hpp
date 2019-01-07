#pragma once

#include "tspod.hpp"

class CsvParser
{
public:
    TsPOD parse(std::string &&content) const;

private:
    std::vector<std::string> split(std::string content, const std::string &delimiter) const;
};
