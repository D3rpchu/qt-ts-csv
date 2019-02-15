#pragma once

#include "xlsxdocument.h"
#include "reader.hpp"
#include "xlsx2ts.hpp"
#include "ts2xlsx.hpp"

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

TEST_F(test_xlsx_ts, completeConversion) {
    auto res = "../../qt-ts-csv/tests/r1.xlsx";
    Ts2Xlsx().convert("../../qt-ts-csv/tests/t4.ts", res);
    n_doc = "../../qt-ts-csv/tests/r1.ts";
    Xlsx2Ts().convert(res, n_doc);
    EXPECT_EQ(Reader().read(n_doc), Reader().read("../../qt-ts-csv/tests/t4.ts"));
    remove(res);
}
