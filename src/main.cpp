#include "converter.h"
#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include "QQmlContext"

#include <iostream>

int main(int argc,  char **argv)
{
    /*std::cout << "{ qt-ts-csv } version "
              << Version::current().as_string() << std::endl;
    if (argc <= 2) {
        std::cerr << "no argumets" << std::endl;
        return -1;
    }

    std::string input(argv[1]);
    std::string output(argv[2]);
    if (input.find(".ts") != std::string::npos &&
        input.find(".csv") != std::string::npos &&
        input.find(".xlsx") != std::string::npos) {
        std::cerr <<  "file not supported" << std::endl;
        return -2;
    }

    if (input.find(".xlsx") != std::string::npos &&
        output.find(".ts") == std::string::npos) {
        std::cerr <<  "file not supported" << std::endl;
        return -2;
    }

    std::cout << "converting file " << input;

    if (input.find(".ts") != std::string::npos) {
        std::cout << " in " << output << std::endl;
        if (output.find(".csv") != std::string::npos) {
            Ts2Csv().convert(std::move(input), std::move(output));
        } else if (output.find(".xlsx") != std::string::npos) {
            Ts2Xlsx().convert(std::move(input), std::move(output));
        } else {
            std::cerr <<  "Conversion not supported" << std::endl;
            return -2;
        }
    } else if (input.find(".csv") != std::string::npos){
        std::cout << " in " << output << std::endl;
        if (output.find(".ts") != std::string::npos) {
            Csv2Ts().convert(std::move(input), std::move(output));
        } else {
            std::cerr <<  "Conversion not supported" << std::endl;
            return -2;
        }
    } else {
        std::cout << " in " << output << std::endl;
        if (output.find(".ts") != std::string::npos) {
            Xlsx2Ts().convert(std::move(input), std::move(output));
        } else {
            std::cerr <<  "Conversion not supported" << std::endl;
            return -2;
        }
    }

    std::cout << "terminated" << std::endl;

    return 0;*/

    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    Converter c;

    QQmlApplicationEngine engine;
    engine.rootContext()->setContextProperty(QString("conv"), &c);
    engine.load(QUrl(QStringLiteral("qrc:Graphics.qml")));
    if (engine.rootObjects().isEmpty())
        return -1;

    return app.exec();
}
