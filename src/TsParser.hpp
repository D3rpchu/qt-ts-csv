#pragma once

#include "TsPod.hpp"
#include "rapidxml-1.13/rapidxml.hpp"

class TsParser
{
public:
    TsPOD parse(std::string &&content);

private:
    void delete_empty_context(TsPOD *ts) const;
    void delete_empty_translations(TsPOD *ts) const;
    uint16_t find_max_locations(const TsPOD &ts);
    bool check_attribute_type(rapidxml::xml_attribute<char> *att);
};
