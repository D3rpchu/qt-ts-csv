#pragma once

#include <string>
#include <vector>

class Location
{
public:
    std::string path;
    unsigned line;
};

class Traslation
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
    std::vector<Traslation> translations;
};

class TsPOD : public std::vector<Context>
{
public:
    std::string language;
    std::string version;
    unsigned short max_locations;
};
