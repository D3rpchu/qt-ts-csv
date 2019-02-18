include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread

INCLUDEPATH += $$PWD/../src

include($$PWD/../libs/qtxlsxwriter/src/xlsx/qtxlsx.pri)
include($$PWD/../src/src.pri)

HEADERS += \
    $$PWD/tst_ts_csv.hpp \
    $$PWD/tst_csv_ts.hpp \
    $$PWD/tst_ts_xlsx.hpp \
    $$PWD/tst_xlsx_ts.hpp

SOURCES += \
    main.cpp \
