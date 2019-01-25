include(gtest_dependency.pri)

TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG += thread
CONFIG -= qt

INCLUDEPATH += $$PWD/../src

HEADERS += \
    tst_ts_csv.hpp

SOURCES += \
    main.cpp
