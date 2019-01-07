#pragma once

#include <sstream>

class TsPOD;

class CSVBuilder
{
public:
    CSVBuilder() = default;
    ~CSVBuilder() = default;

    std::ostringstream build(const TsPOD &ts,
                             unsigned short max_locations) const;
};
