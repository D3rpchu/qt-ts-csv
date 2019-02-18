#include "XlsxBuilder.hpp"

void XlsxBuilder::build(const TsPOD &ts, std::string name) const
{
    QXlsx::Document doc;
    int col = 1;
    int row = 1;

    doc.write(row, col++, "context");
    doc.write(row, col++, "source");
    doc.write(row, col++, "translation");
    doc.write(row, col++, "location");

    for (int i = 1; i < ts.max_locations; ++i) {
        doc.write(row, col++, "location");
    }

    doc.write(row, col++, "version");
    doc.write(row, col++, "language");

    bool write_ver = true;
    for (const auto &c : ts) {
        for (const auto &d : c.translations) {
            col = 1;
            ++row;
            doc.write(row, col++, QString::fromStdString(c.name));
            doc.write(row, col++, QString::fromStdString(d.source));
            doc.write(row, col++, QString::fromStdString(d.tr));
            for (unsigned long long i = 0; i < ts.max_locations; ++i) {
                if (d.locations.size() != 0 && i <= d.locations.size() - 1) {
                    doc.write(row, col++,
                              QString::fromStdString(d.locations[i].path) +
                                  " - " + QString::number(d.locations[i].line));
                } else {
                    col++;
                }
            }
            if (write_ver) {
                write_ver = false;
                doc.write(row, col++, QString::fromStdString(ts.version));
                doc.write(row, col++, QString::fromStdString(ts.language));
            }
        }
    }

    doc.saveAs(QString::fromStdString(name));
}
