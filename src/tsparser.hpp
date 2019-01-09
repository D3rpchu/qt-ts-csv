#pragma once

#include "tspod.hpp"

class TsParser
{
public:
    TsPOD parse(std::string &&content);

private:
    void delete_empty_context(TsPOD *ts) const;
    void delete_empty_translations(TsPOD *ts) const;
    uint16_t find_max_locations(const TsPOD &ts);
};
