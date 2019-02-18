#pragma once

#include "TsPod.hpp"

#include <xlsxdocument.h>

#include <sstream>

class XlsxBuilder
{
public:
    void build(const TsPOD &ts, std::string name) const;
};
