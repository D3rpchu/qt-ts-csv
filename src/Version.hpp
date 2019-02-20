#pragma once

#include <string>

static const std::string version = "1.1.0";

class Version
{
public:
    explicit Version(std::string &&version);

    static Version current() noexcept;

    bool operator==(const Version &other) const;
    bool operator>(const Version &other) const;
    bool operator<(const Version &other) const;
    bool operator<=(const Version &other) const;

    std::string as_string() const noexcept;

private:
    const std::string actual {version};

    std::tuple<int, int, int> get_maj_min_rev(const std::string &v) const;
};
