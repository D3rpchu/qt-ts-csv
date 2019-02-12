#include "csvparser.hpp"

#include <iostream>
#include <algorithm>
#include <iterator>
#include <sstream>

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
    auto tmp = content;
    auto tokens = split(content, "|");
    const auto row_lenght = find_row_items(tokens);
    split_last_cell_from_first_of_next_line(&tokens, row_lenght);
    tokens.erase(tokens.begin(), tokens.begin() + static_cast<long long>(row_lenght));
    const auto Version = row_lenght - 2;
    const auto Language = row_lenght - 1;

    TsPOD ret;
    const unsigned short field_not_location = 5;
    ret.max_locations = static_cast<unsigned short>(row_lenght) - field_not_location;
    for (size_t i = 0; i < tokens.size(); i += row_lenght) {
        class Context c;
        class Translation t;
        for (size_t j = 0; j + i < row_lenght; ++j) {
            if (j == Context) {
                c.name = tokens.at(j + i);
            } else if (j == Source) {
                t.source = tokens.at(j + i);
            } else if (j == Translation) {
                t.tr = tokens.at(j + i);
            } else if (j == Language) {
                ret.language = ret.language.empty() ? tokens.at(j + i) : ret.language;
            } else if (j == Version) {
                ret.version = ret.version.empty() ? tokens.at(j + i) : ret.version;
            } else {
                Location l;
                std::vector<std::string> loc;
                split1(tokens.at(j + i), loc);
                if (loc.empty()) {
                    continue;
                }
                l.path = loc.front();
                l.line = static_cast<unsigned>(std::stoi(loc.back()));
                t.locations.emplace_back(std::move(l));
            }
        }
        c.translations.emplace_back(std::move(t));
        ret.emplace_back(std::move(c));
    }

    for (auto &&r : ret) {
        for (auto &&t : r.translations) {
            if (t.tr.find("\"") != std::string::npos) {
                t.tr.erase(t.tr.begin());
                t.tr.erase(t.tr.end() - 1);
            }
            if (t.source.find("\"") != std::string::npos) {
                t.source.erase(t.source.begin());
                t.source.erase(t.source.end() - 1);
            }
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
    do {
        pos = content.find(delimiter);
        token = content.substr(0, pos);
        lines.emplace_back(token);
        content.erase(0, pos + delimiter.length());
    } while (pos != std::string::npos);

    return lines;
}

size_t CsvParser::find_row_items(const std::vector<std::string> &v) const
{
    size_t count = 0;
    for (const auto &vv : v) {
        if (vv.find("language") == std::string::npos) {
            ++count;
        } else {
            break;
        }
    }
    return ++count;
}

void CsvParser::
    split_last_cell_from_first_of_next_line(std::vector<std::string> *data,
                                            size_t row_lenght) const
{
    for (size_t i = row_lenght -1; i < data->size(); i += row_lenght) {
        const auto index = i;
        if (index >= data->size()) {
            return;
        }
        std::vector<std::string> v;
        split1(data->at(index), v);
        data->at(index) = (v.front() == v.back()) ? "" : v.front();
        data->insert(data->begin() + static_cast<long long>(index + 1), v.back());
        ++i;
    }
}
