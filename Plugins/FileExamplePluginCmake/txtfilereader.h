#ifndef TXTFILEREADER_H
#define TXTFILEREADER_H

#include "filereader.h"

class TxtFileReader : public FileReader
{
public:
    explicit TxtFileReader(QObject *parent = nullptr);
    ~TxtFileReader();

    Q_INVOKABLE void readFile();
    Q_INVOKABLE void writeFile();
};

#endif // TXTFILEREADER_H
