#include "Ts2Csv.hpp"

#include "CsvBuilder.hpp"
#include "TsParser.hpp"

std::ostringstream Ts2Csv::process(std::string &&data) const
{
    return CSVBuilder().build(TsParser().parse(std::move(data)));
}
