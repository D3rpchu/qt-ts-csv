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
    rapidxml::xml_node<>* decl = doc.allocate_node(rapidxml::node_declaration);
    decl->append_attribute(doc.allocate_attribute("version", "1.0"));
    decl->append_attribute(doc.allocate_attribute("encoding", "utf-8"));
    doc.append_node(decl);

    std::ostringstream oss;
    oss << doc;
    doc.clear();
    return oss;
}
