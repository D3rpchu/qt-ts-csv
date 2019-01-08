#pragma once

#include "tspod.hpp"

class TsParser
{
public:
    TsPOD parse(std::string &&content);

private:
    void delete_empty_translations(TsPOD *ts) const;
    unsigned short find_max_locations(const TsPOD &ts);
};
