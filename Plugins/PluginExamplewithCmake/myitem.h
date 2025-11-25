#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QDebug>
class MyItem : public QObject
{
    Q_OBJECT
    // QML_ELEMENT
    Q_DISABLE_COPY(MyItem)
public:
    explicit MyItem(QObject *parent = nullptr);
    ~MyItem() override;

    QString getName() const;
    void setName(const QString &newName);

private:
    QString m_name;
};

#endif // MYITEM_H
