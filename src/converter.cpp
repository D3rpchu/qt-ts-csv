#include "converter.hpp"

#include "reader.hpp"

Converter::Converter(std::string &&filename)
    : _filename(filename)
      , input{}
{}

void Converter::convert()
{
    Reader reader(_filename);
    input = reader.read();
}
