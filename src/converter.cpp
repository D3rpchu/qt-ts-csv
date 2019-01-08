#include "converter.hpp"

#include "reader.hpp"
#include "writer.hpp"

#include <sstream>

void Converter::convert(std::string &&filename, std::string &&output)
{
    Writer().write(process(Reader().read(std::move(filename))), std::move(output));
}
