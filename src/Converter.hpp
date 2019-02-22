#pragma once

#include <QObject>

class Converter : public QObject
{
    Q_OBJECT

public:
    Q_INVOKABLE QString convert() const;

    Q_INVOKABLE QString setSource(const QString &source);
    Q_INVOKABLE QString setDest(const QString &dest);

private:
    std::string source = "";
    std::string dest = "";
};
