#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H

#include "filereader.h"

class CsvFileReader : public FileReader
{
public:
    explicit CsvFileReader(QObject *parent = nullptr);
    ~CsvFileReader();

    Q_INVOKABLE void readFile();
    Q_INVOKABLE void writeFile();
};

#endif // CSVFILEREADER_H
