#include "Converter.hpp"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQmlContext>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>

int main(int argc,  char **argv)
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine engine;

    Converter c;
    engine.rootContext()->setContextProperty(QString("conv"), &c);

    engine.load(QUrl(QStringLiteral("qrc:Graphics.qml")));
    if (engine.rootObjects().isEmpty()) {
        return -1;
    }

    auto ret = app.exec();
    system("PAUSE");

    return ret;
}
