#include "converter.hpp"

#include "reader.hpp"
#include "writer.hpp"

#include <sstream>

void Converter::convert(std::string &&filename)
{
    Writer().write(process(Reader().read(std::move(filename))), "output.csv");
}
