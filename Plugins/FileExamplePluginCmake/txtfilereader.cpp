#include "txtfilereader.h"

TxtFileReader::TxtFileReader(QObject *parent)
    : FileReader{parent}
{
    qDebug()<<Q_FUNC_INFO;
}

TxtFileReader::~TxtFileReader()
{
    qDebug()<<Q_FUNC_INFO;
}

void TxtFileReader::readFile()
{
    qDebug()<<Q_FUNC_INFO;
}

void TxtFileReader::writeFile()
{
    qDebug()<<Q_FUNC_INFO;
}
