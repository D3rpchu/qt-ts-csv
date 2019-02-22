#pragma once

#include <string>

class IConverter
{
public:
    IConverter() = default;
    IConverter(const IConverter &other) = default;
    IConverter(IConverter &&other) = default;
    virtual ~IConverter() = default;

    IConverter &operator=(const IConverter &other) = default;
    IConverter &operator=(IConverter &&other) = default;

    virtual void convert(std::string &&filename,
                         std::string &&output) = 0;
};
