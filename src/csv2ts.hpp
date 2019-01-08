#pragma once

#include "converter.hpp"

class Csv2Ts : public Converter
{
protected:
    std::ostringstream process(std::string &&data) const override;
};
