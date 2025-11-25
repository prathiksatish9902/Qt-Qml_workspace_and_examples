#ifndef FILEEXAMPLEPLUGIN_PLUGIN_H
#define FILEEXAMPLEPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>
#include <QDebug>

class FileExamplePluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // FILEEXAMPLEPLUGIN_PLUGIN_H
