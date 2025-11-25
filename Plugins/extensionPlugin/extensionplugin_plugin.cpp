#include "extensionplugin_plugin.h"

#include "myitem.h"

#include <qqml.h>

void ExtensionPluginPlugin::registerTypes(const char *uri)
{
    qDebug()<<Q_FUNC_INFO;
    qmlRegisterType<MyItem>(uri, 1, 0, "MyItem");
    qmlRegisterSingletonType(QUrl("file:////home/prathik/QT_WORKSPACE/Plugins/extensionPlugin/example.qml"), "com.mycompany.qmlcomponents" , 1 , 0 , "ExampleSingleton");
}
