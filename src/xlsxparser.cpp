#include "XlsxParser.hpp"

#include <sstream>

template <class Container>
void split1(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(cont));
}

TsPOD XlsxParser::parse(std::string &&name) const {
    QXlsx::Document doc(QString::fromStdString(name));
    TsPOD ret;

    int row = 1;
    int col = 0;
    std::string cell = "";
    do {
        col++;
        cell = doc.read(row, col).toString().toStdString();
    } while (cell.compare("language") != 0);

    int row_lenght = col;
    int Context = 1;
    int Source = 2;
    int Translation = 3;
    int Version = row_lenght - 1;
    int Language = row_lenght;
    const unsigned short field_not_location = 5;
    ret.max_locations = static_cast<unsigned short>(row_lenght)
                                - field_not_location;
    col = 1;
    ++row;
    while (!doc.read(row, col).toString().toStdString().empty()) {
        class Context c;
        class Translation t;
        for (; col <= row_lenght; col++) {
            cell = doc.read(row, col).toString().toStdString();
            if (col == Context) {
                c.name = cell;
            } else if (col == Source) {
                t.source = cell;
            } else if (col == Translation) {
                t.tr = cell;
            } else if (col == Language) {
                ret.language = ret.language.empty() ? cell : ret.language;
            } else if (col == Version) {
                ret.version = ret.version.empty() ? cell : ret.version;
            } else {
                Location l;
                std::vector<std::string> loc;
                split1(cell, loc);
                if (loc.empty() || cell.empty()) {
                    continue;
                }
                l.path = loc.front();
                l.line = static_cast<unsigned>(std::stoi(loc.back()));
                t.locations.emplace_back(std::move(l));
            }
        }
        c.translations.emplace_back(std::move(t));
        ret.emplace_back(std::move(c));
        ++row;
        col = 1;
    }

    return ret;
}
