#include "textfilereader.h"

TextFileReader::TextFileReader(QObject *parent)
    : FileReader{parent}
{
    qDebug()<<Q_FUNC_INFO;
}

TextFileReader::~TextFileReader()
{
    qDebug()<<Q_FUNC_INFO;
}

void TextFileReader::readFile()
{
    qDebug()<<Q_FUNC_INFO;
    qDebug()<<"read text file";
}

void TextFileReader::writeFile()
{
    qDebug()<<Q_FUNC_INFO;
    qDebug()<<"write text file";
}
