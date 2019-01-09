TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt
QMAKE_CXXFLAGS_RELEASE *= -O3

SOURCES += \
    src/main.cpp \
    src/writer.cpp \
    src/reader.cpp \
    src/tsparser.cpp \
    src/csvbuilder.cpp \
    src/ts2csv.cpp \
    src/csv2ts.cpp \
    src/converter.cpp \
    src/csvparser.cpp \
    src/tsbuilder.cpp \
    src/version.cpp

HEADERS += \
    src/rapidxml-1.13/rapidxml.hpp \
    src/rapidxml-1.13/rapidxml_iterators.hpp \
    src/rapidxml-1.13/rapidxml_print.hpp \
    src/rapidxml-1.13/rapidxml_utils.hpp \
    src/writer.hpp \
    src/reader.hpp \
    src/tspod.hpp \
    src/tsparser.hpp \
    src/csvbuilder.hpp \
    src/ts2csv.hpp \
    src/csv2ts.hpp \
    src/converter.hpp \
    src/csvparser.hpp \
    src/tsbuilder.hpp \
    src/version.hpp
