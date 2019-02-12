TEMPLATE = app
CONFIG += c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_RELEASE *= -O3

SOURCES += \
    $$PWD/main.cpp \
    $$PWD/writer.cpp \
    $$PWD/reader.cpp \
    $$PWD/tsparser.cpp \
    $$PWD/csvbuilder.cpp \
    $$PWD/ts2csv.cpp \
    $$PWD/csv2ts.cpp \
    $$PWD/converter.cpp \
    $$PWD/csvparser.cpp \
    $$PWD/tsbuilder.cpp \
    $$PWD/version.cpp

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
    $$PWD/version.hpp
