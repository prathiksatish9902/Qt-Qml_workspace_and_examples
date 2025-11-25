#ifndef EXTENSIONPLUGIN_PLUGIN_H
#define EXTENSIONPLUGIN_PLUGIN_H

#include <QQmlExtensionPlugin>

class ExtensionPluginPlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)

public:
    void registerTypes(const char *uri) override;
};

#endif // EXTENSIONPLUGIN_PLUGIN_H
