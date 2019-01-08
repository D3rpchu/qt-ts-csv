#pragma once

#include <string>

class Reader
{
public:
    std::string read(std::string &&filename) const;
};
