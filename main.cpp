#include "csvwriter.hpp"
#include "tsreader.hpp"
#include "tsparser.hpp"
#include "csvbuilder.hpp"

#include <iostream>

int main(int argc,  char **argv)
{
    if (argc <= 1) {
        std::cerr << "no arguments" << std::endl;
        return 0;
    }

    std::string file(argv[1]);
    if (file.find(".ts") == std::string::npos) {
        std::cerr << "file not supported" << std::endl;
        return 0;
    }

    TSReader tsr;
    auto file_content = tsr.do_it(std::move(file));

    TsParser tsp;
    const auto ts = tsp.do_it(std::move(file_content));

    CSVBuilder csvb;
    auto oss = csvb.build(ts, tsp.get_max_locations());

    CSVWriter csvw;
    csvw.do_it("output.csv", std::move(oss));
}
