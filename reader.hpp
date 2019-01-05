#pragma once

#include <string>

class Reader
{
public:
    explicit Reader(std::string &&path);
    explicit Reader(const std::string &path);

    std::string read() const;

private:
    std::string _path;
};
