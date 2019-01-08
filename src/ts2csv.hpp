#pragma once

#include "converter.hpp"

class Ts2Csv : public Converter
{
protected:
    std::ostringstream process(std::string &&data) const override;
};
