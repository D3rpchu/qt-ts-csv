#pragma once

#include <ostream>

class Writer
{
public:
    void write(std::ostringstream &&oss, std::string &&output) const;
};
