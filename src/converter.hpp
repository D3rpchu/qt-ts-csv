#pragma once

#include "tspod.hpp"

#include <string>

class Converter
{
public:
    virtual ~Converter() = default;

    void convert(std::string &&filename, std::string &&output);

protected:
    virtual std::ostringstream process(std::string &&data) const = 0;
};
