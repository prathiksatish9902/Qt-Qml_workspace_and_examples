#include "csvfilereader.h"

CsvFileReader::CsvFileReader(QObject *parent)
    : FileReader{parent}
{
    qDebug()<<Q_FUNC_INFO;
}

CsvFileReader::~CsvFileReader()
{
    qDebug()<<Q_FUNC_INFO;
}

void CsvFileReader::readFile()
{
    qDebug()<<Q_FUNC_INFO;
}

void CsvFileReader::writeFile()
{
    qDebug()<<Q_FUNC_INFO;
}
