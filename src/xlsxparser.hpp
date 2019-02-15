#pragma once

#include "tspod.hpp"
#include "xlsxdocument.h"

class XlsxParser {
public:
    TsPOD parse(std::string &&name) const;
};
