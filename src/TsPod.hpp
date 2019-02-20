#pragma once

#include <string>
#include <vector>

class Location
{
public:
    std::string path;
    unsigned line;
};

class Translation
{
public:
    std::vector<Location> locations;
    std::string source;
    std::string tr;
};

class Context
{
public:
    std::string name;
    std::vector<Translation> translations;
};

class TsPOD : public std::vector<Context>
{
public:
    std::string language;
    std::string version;
    uint16_t max_locations;
};
