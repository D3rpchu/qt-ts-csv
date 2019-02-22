#include "Converter.hpp"

#include "Csv2Ts.hpp"
#include "Ts2Csv.hpp"
#include "Ts2Xlsx.hpp"
#include "Xlsx2Ts.hpp"

QString Converter::convert() const
{
    std::string input = source;
    std::string output = dest;

    if (input.empty() || output.empty()) {
        return "Empty arguments";
    }

    if (input.find(".ts") != std::string::npos &&
        input.find(".csv") != std::string::npos &&
        input.find(".xlsx") != std::string::npos) {
        return "Invalid extention";
    }

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".ts") == std::string::npos) {
        return "Invalid conversion";
    }
    if (input.find(".ts") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    } else if (input.find(".csv") != std::string::npos){
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    } else {
        if (output.find(".ts") != std::string::npos) {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Invalid conversion";
        }
    }
    return "Conversion terminated";
}

QString Converter::setSource(const QString &source)
{
    std::string sep = "///";
    std::string input = source.toStdString();
    this->source = input.substr(input.find(sep) + sep.length());
    return QString::fromStdString(this->source);
}

QString Converter::setDest(const QString &dest)
{
    std::string sep = "///";
    std::string input = dest.toStdString();
    this->dest = input.substr(input.find(sep) + sep.length());
    return QString::fromStdString(this->dest);
}
