TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
QMAKE_CXXFLAGS_RELEASE *= -O3
QT += quick

include($$PWD/./qtxlsxwriter/src/xlsx/qtxlsx.pri)
include($$PWD/src.pri)

SOURCES += \
    $$PWD/main.cpp \

RESOURCES += \
    $$PWD/qml.qrc
