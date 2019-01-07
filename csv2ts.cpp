#include "csv2ts.hpp"

#include "csvparser.hpp"
#include "tsbuilder.hpp"
#include "writer.hpp"

#include <sstream>

Csv2Ts::Csv2Ts(std::string &&filename)
    : Converter{std::move(filename)}
{}

void Csv2Ts::convert()
{
    Converter::convert();

    CsvParser csvp;
    auto data = csvp.parse(std::move(input));

    TsBuilder tsb(std::move(data));
    auto oss = tsb.build();

    Writer w("output.ts");
    w.write(std::move(oss));
}
