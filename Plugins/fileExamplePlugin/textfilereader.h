#ifndef TEXTFILEREADER_H
#define TEXTFILEREADER_H

#include "filereader.h"

class TextFileReader : public FileReader
{
public:
    explicit TextFileReader(QObject *parent = nullptr);
    ~TextFileReader();

   Q_INVOKABLE void readFile();
   Q_INVOKABLE void writeFile();
};

#endif // TEXTFILEREADER_H
