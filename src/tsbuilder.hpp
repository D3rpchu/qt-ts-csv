#pragma once

#include "tspod.hpp"

class TsBuilder
{
public:
    std::ostringstream build(TsPOD &&pod) const;
};
