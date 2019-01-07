#include "writer.hpp"

#include <fstream>
#include <sstream>

Writer::Writer(std::string &&name)
    : name{std::move(name)}
{}

void Writer::write(std::ostringstream &&oss) const
{
    std::ofstream file_output(std::move(name));
    file_output.write(oss.str().c_str(), oss.str().size());
    file_output.close();
}
