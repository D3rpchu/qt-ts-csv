#pragma once

#include <Ts2Xlsx.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_ts_xlsx : public testing::Test
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

TEST_F(test_ts_xlsx, completeConversione)
{
    n_doc = "../../qt-ts-csv/tests/r1.xlsx";
    Ts2Xlsx().convert("../../qt-ts-csv/tests/t4.ts", n_doc);
}
