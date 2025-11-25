#include "mymoduleplugin.h"
#include <qqml.h>
#include "myitem.h"
MyModulePlugin::MyModulePlugin()
{
    qDebug()<<Q_FUNC_INFO;
}

MyModulePlugin::~MyModulePlugin()
{
    qDebug()<<Q_FUNC_INFO;
}

void MyModulePlugin::registerTypes(const char *uri)
{
    qDebug()<<Q_FUNC_INFO;
    qmlRegisterType<MyItem>(uri , 1 , 0 , "MyItem");
}
