#include "txtfilereader.h"

TxtFileReader::TxtFileReader()
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

// Factory function
extern "C" TxtFileReader* createTxtReader()
{
    return new TxtFileReader();
}

// Helper functions that work with void pointers
extern "C" void txtReaderRead(void* reader)
{
    if (reader) {
        static_cast<TxtFileReader*>(reader)->readFile();
    }
}

extern "C" void txtReaderWrite(void* reader)
{
    if (reader) {
        static_cast<TxtFileReader*>(reader)->writeFile();
    }
}

extern "C" void deleteTxtReader(void* reader)
{
    if (reader) {
        delete static_cast<TxtFileReader*>(reader);
    }
}
