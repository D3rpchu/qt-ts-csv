#pragma once

#include <Csv2Ts.hpp>
#include <Reader.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_csv_ts : public testing::Test
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

TEST_F(test_csv_ts, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/r1.ts";
    const auto file_compare = "../../qt-ts-csv/tests/tc1.ts";

    Csv2Ts().convert("../../qt-ts-csv/tests/t1.csv", n_doc);

    EXPECT_EQ(Reader().read(n_doc), Reader().read(file_compare));
}
