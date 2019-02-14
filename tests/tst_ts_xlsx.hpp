#pragma once

#include "xlsxdocument.h"

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_ts_xlsx : public ::testing::Test {
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

TEST_F(test_ts_xlsx, t1) {
    QXlsx::Document x;
    x.write("A1", "Hello qt!");
    x.saveAs("Test.xlsx");
}
