#ifndef FILEEXAMPLE_CPPLIBPLUGIN_H
#define FILEEXAMPLE_CPPLIBPLUGIN_H

#include "FileExample_CppLibPlugin_global.h"
#include <QDebug>
class FILEEXAMPLE_CPPLIBPLUGIN_EXPORT FileExample_CppLibPlugin
{
public:
    FileExample_CppLibPlugin();
    ~FileExample_CppLibPlugin();

    virtual void readFile() = 0;
    virtual void writeFile() = 0;
};

#endif // FILEEXAMPLE_CPPLIBPLUGIN_H
