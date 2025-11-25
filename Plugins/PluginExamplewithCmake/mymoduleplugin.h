#ifndef MYMODULEPLUGIN_H
#define MYMODULEPLUGIN_H

#include <QQmlExtensionPlugin>
#include<QDebug>

class MyModulePlugin : public QQmlExtensionPlugin
{
    Q_OBJECT
    Q_PLUGIN_METADATA(IID QQmlExtensionInterface_iid)
public:
    MyModulePlugin();
    ~MyModulePlugin();

    // QQmlTypesExtensionInterface interface
public:
    void registerTypes(const char *uri);
};

#endif // MYMODULEPLUGIN_H
