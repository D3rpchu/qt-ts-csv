#include "csvbuilder.hpp"

#include "tspod.hpp"

static constexpr auto sep = ";";

std::ostringstream CSVBuilder::build(const TsPOD &ts,
                                     unsigned short max_locations) const
{
    std::ostringstream oss;
    oss << "context" << sep
        << "source" << sep
        << "translation" << sep
        << "location" << sep;

    for (int var = 0; var < max_locations - 1; ++var) {
        oss << "location" << var << sep;
    }

    oss << std::endl;

    for (const auto &c : ts) {
        for (const auto &t : c.translations) {
            oss << c.name << sep;
            oss << t.source << sep;
            oss << t.tr << sep;
            for (const auto &p : t.locations) {
                oss << p.path << " - " << p.line << sep;
            }
            oss << std::endl;
        }
    }
    return oss;
}

static_assert (sep == std::string_view(";"), "why separator has changed?");
