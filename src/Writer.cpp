#include "Writer.hpp"

#include <fstream>
#include <sstream>

void Writer::write(std::ostringstream &&oss, std::string &&output) const
{
    std::ofstream file_output(output);
    file_output.write(oss.str().c_str(), static_cast<int>(oss.str().size()));
    file_output.close();
}
