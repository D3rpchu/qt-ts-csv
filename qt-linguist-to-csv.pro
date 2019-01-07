TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    writer.cpp \
    reader.cpp \
    tsparser.cpp \
    csvbuilder.cpp \
    ts2csv.cpp \
    csv2ts.cpp \
    converter.cpp \
    csvparser.cpp \
    tsbuilder.cpp

HEADERS += \
    rapidxml-1.13/rapidxml.hpp \
    rapidxml-1.13/rapidxml_iterators.hpp \
    rapidxml-1.13/rapidxml_print.hpp \
    rapidxml-1.13/rapidxml_utils.hpp \
    writer.hpp \
    reader.hpp \
    tspod.hpp \
    tsparser.hpp \
    csvbuilder.hpp \
    ts2csv.hpp \
    csv2ts.hpp \
    converter.hpp \
    csvparser.hpp \
    tsbuilder.hpp
