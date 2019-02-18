#include "Ts2Xlsx.hpp"

#include "XlsxBuilder.hpp"
#include "Reader.hpp"
#include "TsParser.hpp"

void Ts2Xlsx::convert(std::string &&filename, std::string &&output)
{
    XlsxBuilder().build(TsParser().parse(Reader().read(std::move(filename))),
                        std::move(output));
}
