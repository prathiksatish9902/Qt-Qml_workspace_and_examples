#include "filereaderplugin.h"
FileReaderPlugin::FileReaderPlugin()
{
    qDebug()<<Q_FUNC_INFO;
}

FileReaderPlugin::~FileReaderPlugin()
{
    qDebug()<<Q_FUNC_INFO;
}

void FileReaderPlugin::registerTypes(const char *uri)
{
    qDebug()<<Q_FUNC_INFO;
    qmlRegisterType<TxtFileReader> (uri , 1 , 0 , "TxtFileReader");
    qmlRegisterType<CsvFileReader> (uri , 1 , 0 , "CsvFileReader");
}
