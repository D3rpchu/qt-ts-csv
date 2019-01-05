#pragma once

#include <string>

class Ts2Csv
{
public:
    explicit Ts2Csv(std::string &&filename);

    void convert() const;

private:
    std::string filename;
};
