#include "filereader.h"

FileReader::FileReader(QObject *parent)
    : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
}

FileReader::~FileReader()
{
    qDebug()<<Q_FUNC_INFO;
}
