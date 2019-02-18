#pragma once

#include <Ts2Csv.hpp>
#include <Reader.hpp>

#include <gtest/gtest.h>
#include <gmock/gmock-matchers.h>

class test_ts_csv : public testing::Test
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

TEST_F(test_ts_csv, conversion)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
                        "\"AddNewForm\"|\"Cottura Manuale\"|\"Manual Cooking\"|\"../../QML/OggettiEditDash/AddNewForm.qml - 21\"|\"2.1\"|\"en_GB\"\n";

    n_doc = "../../qt-ts-csv/tests/r1.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/t1.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, multirow)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n"
                        "\"Connettivita\"|\"Impostazioni\n    Wi-fi\"|\"WI-fi\n"
                        "    settings\"|\"../../QML/OggettiSettings/Connettivita.qml - 66\"|\"2.1\"|\"en_GB\"\n";

    n_doc = "../../qt-ts-csv/tests/r2.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/t2.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, typeVanishedAndObsolete)
{
    const auto output = "\"context\"|\"source\"|\"translation\"|\"location\"|\"version\"|\"language\"\n";

    n_doc = "../../qt-ts-csv/tests/r3.csv";
    Ts2Csv().convert("../../qt-ts-csv/tests/t3.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), output);
}

TEST_F(test_ts_csv, completeConversion)
{
    n_doc = "../../qt-ts-csv/tests/r4.csv";
    const auto file_compare = "../../qt-ts-csv/tests/tc4.csv";

    Ts2Csv().convert("../../qt-ts-csv/tests/t4.ts", n_doc);

    EXPECT_EQ(Reader().read(n_doc), Reader().read(file_compare));
}
