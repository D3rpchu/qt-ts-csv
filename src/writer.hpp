#pragma once

#include <ostream>

class Writer
{
public:
    explicit Writer(std::string &&name);

    void write(std::ostringstream &&oss) const;

private:
    std::string name;
};
