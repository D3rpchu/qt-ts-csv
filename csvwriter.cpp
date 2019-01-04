#include "csvwriter.hpp"

#include <fstream>
#include <sstream>

void CSVWriter::do_it(std::string &&filename, std::ostringstream &&oss) const
{
    std::ofstream file_output(std::move(filename));
    file_output.write(oss.str().c_str(), oss.str().size());
    file_output.close();
}
