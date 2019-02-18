#pragma once

#include "ReadableFileConverter.hpp"

class Csv2Ts : public ReadableFileConverter
{
protected:
    std::ostringstream process(std::string &&data) const override;
};
