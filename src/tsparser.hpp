#pragma once

#include "tspod.hpp"

class TsParser
{
public:
    TsParser() = default;
    ~TsParser() = default;

    TsPOD do_it(std::string &&content);

    unsigned short get_max_locations() const noexcept;

private:
    unsigned short max_locations{0};

    void delete_empty_translations(TsPOD *ts) const;
    void find_max_locations(const TsPOD &ts);
};
