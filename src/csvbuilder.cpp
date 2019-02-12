#include "csvbuilder.hpp"

#include "tspod.hpp"

std::ostringstream CSVBuilder::build(const TsPOD &ts) const
{
    std::ostringstream oss;
    oss << "\"" << "context"        << "\"" << sep
        << "\"" << "source"         << "\"" << sep
        << "\"" << "translation"    << "\"" << sep
        << "\"" << "location"       << "\""/* << sep*/;

    for (int var = 0; var < ts.max_locations - 1; ++var) {
        oss << "\"" << "location" << "\"" << sep;
    }

    oss << "\"" << "version"    << "\"" << sep
        << "\"" << "language"   << "\"" << sep << "\n";

    bool write_ver = true;
    for (const auto &c : ts) {
        for (const auto &d : c.translations) {
            oss << "\"" << c.name   << "\"" << sep;
            oss << "\"" << d.source << "\"" << sep;
            oss << "\"" << d.tr     << "\"" << sep;
            for (uint16_t j = 0; j < ts.max_locations; ++j) {
                oss << "\"";
                if (d.locations.size() != 0 && j <= d.locations.size() - 1) {
                    oss << d.locations[j].path << " - " << d.locations[j].line;
                }
                oss << "\"" << sep;
            }
            if (write_ver) {
                write_ver = false;
                oss << ts.version   << sep
                    << ts.language  << sep << "\n";
            } else {
                oss << "\"" << "\"" << sep
                    << "\"" << "\"" << sep << "\n";
            }
        }
    }

    return oss;
}
