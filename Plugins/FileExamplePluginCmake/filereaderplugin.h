#ifndef FILEREADERPLUGIN_H
#define FILEREADERPLUGIN_H

#include <QQmlExtensionPlugin>
#include <QDebug>
#include <qqml.h>
#include "csvfilereader.h"
#include "txtfilereader.h"

class FileReaderPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    FileReaderPlugin();
    ~FileReaderPlugin();

    // QQmlTypesExtensionInterface interface
public:
    void registerTypes(const char *uri);
};

#endif // FILEREADERPLUGIN_H
