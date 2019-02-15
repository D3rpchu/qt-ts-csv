TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QMAKE_CXXFLAGS_RELEASE *= -O3

include(../libs/qtxlsxwriter/src/xlsx/qtxlsx.pri)

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/writer.cpp \
    $$PWD/reader.cpp \
    $$PWD/tsparser.cpp \
    $$PWD/csvbuilder.cpp \
    $$PWD/ts2csv.cpp \
    $$PWD/csv2ts.cpp \
    $$PWD/ReadableFileConverter.cpp \
    $$PWD/csvparser.cpp \
    $$PWD/tsbuilder.cpp \
    $$PWD/version.cpp \
    xlsxbuilder.cpp \
    xlsxparser.cpp \
    xlsx2ts.cpp \
    ts2xlsx.cpp

HEADERS += \
    $$PWD/rapidxml-1.13/rapidxml.hpp \
    $$PWD/rapidxml-1.13/rapidxml_iterators.hpp \
    $$PWD/rapidxml-1.13/rapidxml_print.hpp \
    $$PWD/rapidxml-1.13/rapidxml_utils.hpp \
    $$PWD/writer.hpp \
    $$PWD/reader.hpp \
    $$PWD/tspod.hpp \
    $$PWD/tsparser.hpp \
    $$PWD/csvbuilder.hpp \
    $$PWD/ts2csv.hpp \
    $$PWD/csv2ts.hpp \
    $$PWD/converter.hpp \
    $$PWD/csvparser.hpp \
    $$PWD/tsbuilder.hpp \
    $$PWD/version.hpp \
    xlsx2ts.hpp \
    xlsxbuilder.hpp \
    xlsxparser.hpp \
    ts2xlsx.hpp \
    iconverter.h \
    ReadableFileConverter.hpp
