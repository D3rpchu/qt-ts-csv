#pragma once

#include "xlsxdocument.h"

#include <iostream>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_xlsx_ts : public ::testing::Test {
protected:
    virtual void TearDown() {
        remove(n_doc);
    }
    virtual void SetUp() {
        n_doc = nullptr;
    }
public:
    const char* n_doc;
};

TEST_F(test_xlsx_ts, t1) {
    QXlsx::Document x(QString("Test.xlsx"));
    while(true) {}
}
