#pragma once

#include <sstream>

class TsPOD;

class CSVBuilder
{
public:
    std::ostringstream build(const TsPOD &ts) const;
};
