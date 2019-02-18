#pragma once

#include "IConverter.hpp"

class Xlsx2Ts : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output) override;
};
