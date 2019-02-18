#pragma once

#include <sstream>

#include "TsPod.hpp"
#include "xlsxdocument.h"

class XlsxBuilder
{
public:
    void build(const TsPOD &ts, std::string name) const;
};
