#pragma once

#include <string>

class Converter
{
public:
    explicit Converter(std::string &&filename);
    virtual ~Converter() = default;

    virtual void convert();

protected:
    std::string _filename;
    std::string input;
};
