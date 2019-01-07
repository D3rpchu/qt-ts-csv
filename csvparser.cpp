#include "csvparser.hpp"

#include <sstream>
#include <algorithm>
#include <iterator>

enum Row { Context, Source, Translation, Path };

template <class Container>
void split1(const std::string& str, Container& cont)
{
    std::istringstream iss(str);
    std::copy(std::istream_iterator<std::string>(iss),
              std::istream_iterator<std::string>(),
              std::back_inserter(cont));
}

TsPOD CsvParser::parse(std::string &&content) const
{
    auto lines = split(content, "\n");
    lines.erase(std::begin(lines));

    TsPOD ret;

    std::string old_context;
    for (const auto &l : lines) {
        const auto tokens = split(l, ";");
        Traslation t;
        t.source = tokens.at(Source);
        t.tr = tokens.at(Translation);
        for (size_t var = Path; var < tokens.size(); ++var) {
            if (tokens.at(var).empty()) {
                break;
            }
            std::vector<std::string> chunks;
            split1(tokens.at(var), chunks);
            Location l;
            l.path = chunks.front();
            l.line = static_cast<unsigned>(stoi(chunks.back()));
            t.locations.emplace_back(std::move(l));
        }

        if (old_context == tokens.at(Context)) {
            ret.back().translations.emplace_back(std::move(t));
        } else {
            class Context c;
            c.name = tokens.at(Context);
            c.translations.emplace_back(std::move(t));
            ret.emplace_back(std::move(c));
            old_context = c.name;
        }
    }

    return ret;
}

std::vector<std::string> CsvParser::split(std::string content,
                                          const std::string &delimiter) const
{
    std::vector<std::string> lines;
    size_t pos = 0;
    std::string token;
    while ((pos = content.find(delimiter)) != std::string::npos) {
        token = content.substr(0, pos);
        lines.emplace_back(token);
        content.erase(0, pos + delimiter.length());
    }
    return lines;
}
