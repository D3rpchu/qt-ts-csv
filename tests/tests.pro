include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

INCLUDEPATH += $$PWD/../src

include(../libs/qtxlsxwriter/src/xlsx/qtxlsx.pri)

HEADERS += \
    tst_ts_csv.hpp \
    tst_csv_ts.hpp \
    tst_ts_xlsx.hpp \
    tst_xlsx_ts.hpp \
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
    $$PWD/../src/version.hpp \
    $$PWD/../src/xlsxbuilder.hpp \
    $$PWD/../src/xlsxparser.hpp \
    $$PWD/../src/xlsx2ts.hpp \
    $$PWD/../src/ts2xlsx.hpp

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
    $$PWD/../src/version.cpp \
    $$PWD/../src/xlsxbuilder.cpp \
    $$PWD/../src/xlsxparser.cpp \
    $$PWD/../src/xlsx2ts.cpp \
    $$PWD/../src/ts2xlsx.cpp

XLSX_NO_LIB
