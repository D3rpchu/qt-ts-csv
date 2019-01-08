#include "csv2ts.hpp"

#include "csvparser.hpp"
#include "tsbuilder.hpp"

#include <sstream>

std::ostringstream Csv2Ts::process(std::string &&data) const
{
    return TsBuilder().build(CsvParser().parse(std::move(data)));
}
