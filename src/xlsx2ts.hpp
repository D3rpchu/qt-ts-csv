#pragma once

#include "iconverter.h"

class Xlsx2Ts : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output);
};
