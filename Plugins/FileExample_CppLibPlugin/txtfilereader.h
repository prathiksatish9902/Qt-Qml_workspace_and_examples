#ifndef TXTFILEREADER_H
#define TXTFILEREADER_H

#include "fileexample_cpplibplugin.h"

class TxtFileReader : public FileExample_CppLibPlugin
{
public:
    TxtFileReader();
    ~TxtFileReader();

    void readFile();
    void writeFile();
};

#endif // TXTFILEREADER_H
