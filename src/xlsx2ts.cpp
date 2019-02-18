#include "xlsx2ts.hpp"

#include "TsBuilder.hpp"
#include "xlsxparser.hpp"
#include "Writer.hpp"
#include <sstream>

void Xlsx2Ts::convert(std::string &&filename, std::string &&output) {
    Writer().write(TsBuilder().build(XlsxParser().parse(std::move(filename))),
                   std::move(output));
}
