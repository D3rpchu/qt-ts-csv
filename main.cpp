#include <rapidxml-1.13/rapidxml.hpp>

#include <fstream>
#include <sstream>
#include <iostream>
#include <vector>
#include <tuple>

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

int main(int argc,  char **argv)
{
    if (argc <= 1) {
        std::cerr << "no arguments" << std::endl;
        return 0;
    }

    std::string file(argv[1]);
    if (file.find(".ts") == std::string::npos) {
        std::cerr << "file not supported" << std::endl;
        return 0;
    }

    std::ifstream ifs;
    ifs.open(file);
    std::string all;
    std::string line;
    while (std::getline(ifs, line)) {
        all += line;
    }

    rapidxml::xml_document<> doc;
    doc.parse<0>(const_cast<char *>(all.c_str()));

    std::vector<Context> csv;

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
                    if (att->name() == std::string_view("location")) {
                        Location loc;
                        loc.path = att->first_attribute()->value();
                        loc.line = std::stoi(att->first_attribute()->next_attribute()->value());
                        t.locations.emplace_back(std::move(loc));
                    } else {
                        if (att->name() != std::string_view("")) {
                            if (att->name() == std::string_view("source")) {
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
            csv.emplace_back(std::move(c));
            bro = bro->next_sibling();
        }
        node = node->next_sibling();
    }

    for (auto &c : csv) {
        size_t i = 0;
        while (i < c.translations.size()) {
            if (c.translations[i].locations.empty()) {
                c.translations.erase(c.translations.begin() + i);
                continue;
            }
            ++i;
        }
    }

    for (const auto &c : csv) {
        std::cout << c.name << std::endl;
        for (const auto &t : c.translations) {
            for (const auto &l : t.locations) {
                std::cout << "\tlocation: " << l.path
                          << "\tat line: " << l.line << std::endl;
            }
            std::cout << "\tsource: " << t.source << std::endl
                      << "\ttr: " << t.tr << std::endl;
            std::cout << std::endl;
        }
        std::cout << std::endl;
        std::cout << std::endl;
    }
}
