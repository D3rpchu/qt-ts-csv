#pragma once

#include <QObject>

class Converter : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString convert(const QString &source,
                                const QString &dest) const;
};
