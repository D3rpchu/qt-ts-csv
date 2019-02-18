#pragma once

#include "IConverter.hpp"

#include <string>

class Ts2Xlsx : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output) override;
};
