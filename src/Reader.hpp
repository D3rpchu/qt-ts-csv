#pragma once

#include "xlsxdocument.h"

#include <string>

class Reader
{
public:
    std::string read(std::string &&filename) const;
};
