#pragma once

#include "tspod.hpp"

class CsvParser
{
public:
    TsPOD parse(std::string &&content) const;
private:
    std::vector<std::string> split(std::string content,
                                   const std::string &delimiter) const;
    void restore_return(TsPOD *data) const;
    size_t find_row_items(const std::vector<std::string> &v) const;
    void split_last_cell_from_first_of_next_line(std::vector<std::string> *data,
                                                 size_t row_lenght) const;
};
