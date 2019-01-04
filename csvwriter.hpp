#pragma once

#include <ostream>

class CSVWriter
{
public:
    CSVWriter() = default;
    ~CSVWriter() = default;

    void do_it(std::string &&filename, std::ostringstream &&oss) const;
};
