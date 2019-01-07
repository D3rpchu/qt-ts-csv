#pragma once

#include "converter.hpp"

class Ts2Csv : public Converter
{
public:
    Ts2Csv() = delete;
    explicit Ts2Csv(std::string &&filename);

    void convert() override;
};
