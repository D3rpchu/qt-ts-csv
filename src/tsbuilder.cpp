#include "tsbuilder.hpp"

#include "rapidxml-1.13/rapidxml.hpp"
#include "rapidxml-1.13/rapidxml_print.hpp"

#include <sstream>
#include <iostream>
#include <fstream>

TsBuilder::TsBuilder(TsPOD &&data)
    : pod{std::move(data)}
{}

std::ostringstream TsBuilder::build() const
{
    rapidxml::xml_document<> doc;

    auto root = doc.allocate_node(rapidxml::node_element, "TS");
    root->append_attribute(doc.allocate_attribute("version", "2.1"));
    root->append_attribute(doc.allocate_attribute("language", "en_GB"));
    doc.append_node(root);

    for (const auto &d : pod) {
        auto node = doc.allocate_node(rapidxml::node_element, "context");
        auto name = doc.allocate_node(rapidxml::node_element, "name", d.name.c_str());
        node->append_node(name);
        for (const auto m : d.translations) {
            auto mex = doc.allocate_node(rapidxml::node_element, "message");
            for (const auto loc : m.locations) {
                const auto l = doc.allocate_node(rapidxml::node_element, "location");
                auto str = doc.allocate_string(loc.path.c_str());
                l->append_attribute(doc.allocate_attribute("filename", str));
                l->append_attribute(doc.allocate_attribute("line", std::to_string(loc.line).c_str()));
                mex->append_node(l);
            }
            const auto s1 = doc.allocate_string(m.source.c_str());
            auto source = doc.allocate_node(rapidxml::node_element, "source", s1);
            const auto s2 = doc.allocate_string(m.tr.c_str());
            auto tr = doc.allocate_node(rapidxml::node_element, "translation", s2);
            mex->append_node(source);
            mex->append_node(tr);
            node->append_node(mex);
        }
        root->append_node(node);
    }

    std::ostringstream oss;
    oss << "<?xml version=\"1.0\" encoding=\"utf-8\"?>\n";
    oss << "<!DOCTYPE TS>\n";
    oss << doc;
    doc.clear();
    return oss;
}
