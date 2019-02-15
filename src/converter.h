#pragma once

#include <QObject>
#include "version.hpp"
#include "csv2ts.hpp"
#include "ts2csv.hpp"
#include "xlsx2ts.hpp"
#include "ts2xlsx.hpp"

class Converter : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString convert(QString source, QString dest) const;
};
