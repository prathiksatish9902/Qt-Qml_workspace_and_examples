#ifndef CSVFILEREADER_H
#define CSVFILEREADER_H

#include "fileexample_cpplibplugin.h"

class CsvFileReader : public FileExample_CppLibPlugin
{
public:
    CsvFileReader();
    ~CsvFileReader();

    void readFile();
    void writeFile();
};

#endif // CSVFILEREADER_H
