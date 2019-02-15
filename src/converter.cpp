#include "converter.h"
#include <iostream>

QString Converter::convert(QString source, QString dest) const
{
    std::string input = source.toStdString();
    input = input.substr(input.find("C"));
    std::string output = dest.toStdString();
    output = output.substr(output.find("C"));

    if (input.find(".ts") != std::string::npos &&
        input.find(".csv") != std::string::npos &&
        input.find(".xlsx") != std::string::npos) {
        return "Estensione non valida";
    }

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".ts") == std::string::npos) {
        return "Conversione non valida";
    }
    if (input.find(".ts") != std::string::npos) {
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        } else {
            return "Conversione non valida";
        }
    } else if (input.find(".csv") != std::string::npos){
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Conversione non valida";
        }
    } else {
        if (output.find(".ts") != std::string::npos) {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        } else {
            return "Conversione non valida";
        }
    }
    return "Conversione eseguita";
}
