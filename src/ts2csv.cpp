#include "ts2csv.hpp"

#include "csvbuilder.hpp"
#include "tsparser.hpp"

std::ostringstream Ts2Csv::process(std::string &&data) const
{
    return CSVBuilder().build(TsParser().parse(std::move(data)));
}
