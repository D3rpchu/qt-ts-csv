#include "Csv2Ts.hpp"

#include "CsvParser.hpp"
#include "TsBuilder.hpp"

#include <sstream>

std::ostringstream Csv2Ts::process(std::string &&data) const
{
    return TsBuilder().build(CsvParser().parse(std::move(data)));
}
