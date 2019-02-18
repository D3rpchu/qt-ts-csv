#pragma once

#include "Version.hpp"
#include "Csv2Ts.hpp"
#include "Ts2Csv.hpp"
#include "Xlsx2Ts.hpp"
#include "Ts2Xlsx.hpp"

#include <QObject>

class Converter : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString convert(QString source, QString dest) const;
};
