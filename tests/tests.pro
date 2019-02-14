include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += $$PWD/../src

HEADERS += \
    tst_ts_csv.hpp \
    tst_csv_ts.hpp \
    $$PWD/../src/rapidxml-1.13/rapidxml.hpp \
    $$PWD/../src/rapidxml-1.13/rapidxml_iterators.hpp \
    $$PWD/../src/rapidxml-1.13/rapidxml_print.hpp \
    $$PWD/../src/rapidxml-1.13/rapidxml_utils.hpp \
    $$PWD/../src/writer.hpp \
    $$PWD/../src/reader.hpp \
    $$PWD/../src/tspod.hpp \
    $$PWD/../src/tsparser.hpp \
    $$PWD/../src/csvbuilder.hpp \
    $$PWD/../src/ts2csv.hpp \
    $$PWD/../src/csv2ts.hpp \
    $$PWD/../src/converter.hpp \
    $$PWD/../src/csvparser.hpp \
    $$PWD/../src/tsbuilder.hpp \
    $$PWD/../src/version.hpp

SOURCES += \
    main.cpp \
    $$PWD/../src/writer.cpp \
    $$PWD/../src/reader.cpp \
    $$PWD/../src/tsparser.cpp \
    $$PWD/../src/csvbuilder.cpp \
    $$PWD/../src/ts2csv.cpp \
    $$PWD/../src/csv2ts.cpp \
    $$PWD/../src/converter.cpp \
    $$PWD/../src/csvparser.cpp \
    $$PWD/../src/tsbuilder.cpp \
    $$PWD/../src/version.cpp
