#pragma once

#include "xlsxdocument.h"
#include "Reader.hpp"
#include "Xlsx2Ts.hpp"
#include "Ts2Xlsx.hpp"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_xlsx_ts : public testing::Test
{
public:
    const char *n_doc;

protected:
    virtual void TearDown()
    {
        remove(n_doc);
    }

    virtual void SetUp()
    {
        n_doc = nullptr;
    }
};

TEST_F(test_xlsx_ts, completeConversion)
{
    auto res = "../../qt-ts-csv/tests/r1.xlsx";
    Ts2Xlsx().convert("../../qt-ts-csv/tests/t4.ts", res);
    n_doc = "../../qt-ts-csv/tests/r1.ts";
    Xlsx2Ts().convert(res, n_doc);
    EXPECT_EQ(Reader().read(n_doc), Reader().read("../../qt-ts-csv/tests/xlsx2ts.ts"));
    remove(res);
}
