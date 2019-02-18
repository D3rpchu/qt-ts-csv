#pragma once

#include "ReadableFileConverter.hpp"

class Ts2Csv : public ReadableFileConverter
{
protected:
    std::ostringstream process(std::string &&data) const;
};
