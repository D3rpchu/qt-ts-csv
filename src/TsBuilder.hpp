#pragma once

#include "TsPod.hpp"

class TsBuilder
{
public:
    std::ostringstream build(TsPOD &&pod) const;
};
