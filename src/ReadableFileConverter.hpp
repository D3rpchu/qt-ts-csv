#pragma once

#include "IConverter.hpp"
#include "TsPod.hpp"

#include <string>

class ReadableFileConverter : public IConverter
{
public:
    void convert(std::string &&filename, std::string &&output) override;

protected:
    virtual std::ostringstream process(std::string &&data) const = 0;
};
