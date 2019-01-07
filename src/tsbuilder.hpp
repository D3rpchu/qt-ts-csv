#pragma once

#include "tspod.hpp"

class TsBuilder
{
public:
    TsBuilder(TsPOD &&data);

    std::ostringstream build() const;

private:
    TsPOD pod;
};
