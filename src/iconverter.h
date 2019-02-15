#pragma once

#include <string>

class IConverter
{
public:
    virtual ~IConverter() = default;

    virtual void convert(std::string &&filename,
                         std::string &&output) = 0;
};
