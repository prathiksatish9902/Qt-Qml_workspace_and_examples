#include "fileexampleplugin_plugin.h"

#include "filereader.h"
#include "textfilereader.h"
#include "csvfilereader.h"
#include <qqml.h>

void FileExamplePluginPlugin::registerTypes(const char *uri)
{
    // @uri com.mycompany.qmlcomponents
    qDebug()<<Q_FUNC_INFO;
    // qmlRegisterType<FileReader>(uri, 1, 0, "FileReader");
    qmlRegisterType<TextFileReader>(uri, 1, 0, "TextFileReader");
    qmlRegisterType<CsvFileReader>(uri, 1, 0, "CsvFileReader");

}
