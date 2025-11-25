#ifndef FILEREADER_H
#define FILEREADER_H

#include <QObject>
#include <QDebug>
class FileReader : public QObject
{
    Q_OBJECT
    // QML_ELEMENT
    Q_DISABLE_COPY(FileReader)
public:
    explicit FileReader(QObject *parent = nullptr);
    ~FileReader() override;

    Q_INVOKABLE virtual void readFile() = 0;
    Q_INVOKABLE virtual void writeFile() = 0;
};

#endif // FILEREADER_H
