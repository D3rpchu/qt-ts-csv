#pragma once

#include "TsPod.hpp"

#include <xlsxdocument.h>

class XlsxParser
{
public:
    TsPOD parse(std::string &&name) const;
};
