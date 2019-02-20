#include "Version.hpp"

#include <tuple>

Version::Version(std::string &&version)
    : actual{std::move(version)}
{}

Version Version::current() noexcept
{
    return Version(std::string(version));
}

bool Version::operator==(const Version &other) const
{
    return other.actual == actual;
}

bool Version::operator>(const Version &other) const
{
    auto t1 = get_maj_min_rev(actual);
    auto maj1 = std::get<0>(t1);
    auto min1 = std::get<1>(t1);
    auto rev1 = std::get<2>(t1);

    auto t2 = get_maj_min_rev(other.actual);
    auto maj2 = std::get<0>(t2);
    auto min2 = std::get<1>(t2);
    auto rev2 = std::get<2>(t2);

    if (maj1 > maj2) { return true; }
    if (maj1 == maj2) {
        if (min1 > min2) { return true; }
        if (min1 == min2) { return rev1 > rev2; }
    }

    return false;
}

bool Version::operator<(const Version &other) const
{
    return !(*this == other && *this > other);
}

bool Version::operator<=(const Version &other) const
{
    return (*this == other || *this == other);
}

std::string Version::as_string() const noexcept
{
    return actual;
}

std::tuple<int, int, int> Version::get_maj_min_rev(const std::string &v) const
{
    auto delimiter = ".";
    auto maj = v.substr(0, v.find(delimiter));
    auto min = v.substr(v.find(delimiter) + 1, v.find_last_of(delimiter) - 2);
    auto rev = v.substr(v.find_last_of(delimiter) + 1, v.length());
    return std::make_tuple(std::atoi(maj.c_str()), std::atoi(min.c_str()),
                           std::atoi(rev.c_str()));
}
