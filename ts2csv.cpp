#include "ts2csv.hpp"

#include "reader.hpp"
#include "tsparser.hpp"
#include "csvbuilder.hpp"
#include "csvwriter.hpp"

Ts2Csv::Ts2Csv(std::string &&filename)
    : Converter{std::move(filename)}
{}

void Ts2Csv::convert()
{
    Converter::convert();

    TsParser tsp;
    const auto ts = tsp.do_it(std::move(input));

    CSVBuilder csvb;
    auto oss = csvb.build(ts, tsp.get_max_locations());

    CSVWriter csvw;
    csvw.do_it("output.csv", std::move(oss));
}
