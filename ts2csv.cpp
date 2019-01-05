#include "ts2csv.hpp"

#include "tsreader.hpp"
#include "tsparser.hpp"
#include "csvbuilder.hpp"
#include "csvwriter.hpp"

Ts2Csv::Ts2Csv(std::string &&filename)
    : filename{filename}
{}

void Ts2Csv::convert() const
{
    TSReader tsr;
    auto file_content = tsr.do_it(filename);

    TsParser tsp;
    const auto ts = tsp.do_it(std::move(file_content));

    CSVBuilder csvb;
    auto oss = csvb.build(ts, tsp.get_max_locations());

    CSVWriter csvw;
    csvw.do_it("output.csv", std::move(oss));
}
