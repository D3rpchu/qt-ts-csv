#include "csv2ts.hpp"

Csv2Ts::Csv2Ts(std::string &&filename)
    : Converter{std::move(filename)}
{}

void Csv2Ts::convert()
{
    Converter::convert();
}
