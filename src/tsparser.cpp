#include "tsparser.hpp"

#include "rapidxml-1.13/rapidxml.hpp"

TsPOD TsParser::do_it(std::string &&content)
{
    rapidxml::xml_document<> doc;
    doc.parse<0>(const_cast<char *>(content.c_str()));

    TsPOD ret;
    auto node = doc.first_node();
    while (node != nullptr) {
        auto bro = node->first_node();
        while (bro != nullptr) {
            auto child = bro->first_node();
            Context c;
            c.name = child->value();
            while (child != nullptr) {
                auto att = child->first_node();
                Traslation t;
                while (att != nullptr) {
                    if (att->name() == std::string("location")) {
                        Location loc;
                        loc.path = att->first_attribute()->value();
                        loc.line = std::stoi(att->first_attribute()->next_attribute()->value());
                        t.locations.emplace_back(std::move(loc));
                    } else {
                        if (att->name() != std::string("")) {
                            if (att->name() == std::string("source")) {
                                t.source = att->value();
                            } else {
                                t.tr = att->value();
                            }
                        }
                    }
                    att = att->next_sibling();
                }
                c.translations.emplace_back(std::move(t));
                child = child->next_sibling();
            }
            ret.emplace_back(std::move(c));
            bro = bro->next_sibling();
        }
        node = node->next_sibling();
    }

    delete_empty_translations(&ret);
    find_max_locations(ret);
    return ret;
}

unsigned short TsParser::get_max_locations() const noexcept
{
    return max_locations;
}

void TsParser::delete_empty_translations(TsPOD *ts) const
{
    for (auto &c : *ts) {
        size_t i = 0;
        while (i < c.translations.size()) {
            if (c.translations[i].locations.empty()) {
                c.translations.erase(c.translations.begin() + i);
                continue;
            }
            ++i;
        }
    }
}

void TsParser::find_max_locations(const TsPOD &ts)
{
    for (const auto &c : ts) {
        if (c.translations.front().locations.size() > max_locations) {
            max_locations = static_cast<unsigned short>(c.translations.front().locations.size());
        }
    }
}
