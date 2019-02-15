#pragma once

#include <sstream>

#include "tspod.hpp"
#include "xlsxdocument.h"

class XlsxBuilder {
public:
    void build(const TsPOD &ts, std::string name) const;
};
