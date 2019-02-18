#include "ts2xlsx.hpp"

#include "xlsxbuilder.hpp"
#include "TsParser.hpp"
#include "Reader.hpp"

void Ts2Xlsx::convert(std::string &&filename, std::string &&output)
{
    XlsxBuilder().build(TsParser().parse(Reader().read(std::move(filename))),
                        std::move(output));
}
