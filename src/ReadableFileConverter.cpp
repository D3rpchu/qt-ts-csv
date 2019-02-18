#include "ReadableFileConverter.hpp"

#include "Reader.hpp"
#include "Writer.hpp"

#include <sstream>

void ReadableFileConverter::convert(std::string &&filename, std::string &&output)
{
    Writer().write(process(Reader().read(std::move(filename))), std::move(output));
}
