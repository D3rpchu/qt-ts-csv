#include "Ts2Xlsx.hpp"

#include "Reader.hpp"
#include "TsParser.hpp"
#include "XlsxBuilder.hpp"

void Ts2Xlsx::convert(std::string &&filename, std::string &&output)
{
    XlsxBuilder().build(TsParser().parse(Reader().read(std::move(filename))),
                        std::move(output));
}
