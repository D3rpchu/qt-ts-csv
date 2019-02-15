#pragma once

#include <string>
#include "iconverter.h"

class Ts2Xlsx : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output);
};
