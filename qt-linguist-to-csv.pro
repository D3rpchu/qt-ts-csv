TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    main.cpp \
    csvwriter.cpp \
    reader.cpp \
    tsparser.cpp \
    csvbuilder.cpp \
    ts2csv.cpp \
    csv2ts.cpp \
    converter.cpp

HEADERS += \
    rapidxml-1.13/rapidxml.hpp \
    rapidxml-1.13/rapidxml_iterators.hpp \
    rapidxml-1.13/rapidxml_print.hpp \
    rapidxml-1.13/rapidxml_utils.hpp \
    csvwriter.hpp \
    reader.hpp \
    tspod.hpp \
    tsparser.hpp \
    csvbuilder.hpp \
    ts2csv.hpp \
    csv2ts.hpp \
    converter.hpp
