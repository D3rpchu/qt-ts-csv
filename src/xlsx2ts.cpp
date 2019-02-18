#include "Xlsx2Ts.hpp"

#include "TsBuilder.hpp"
#include "Writer.hpp"
#include "XlsxParser.hpp"

#include <sstream>

void Xlsx2Ts::convert(std::string &&filename, std::string &&output)
{
    Writer().write(TsBuilder().build(XlsxParser().parse(std::move(filename))),
                   std::move(output));
}
