#ifndef MYITEM_H
#define MYITEM_H

#include <QObject>
#include <QDebug>
class MyItem :public QObject
{
    Q_OBJECT

    Q_DISABLE_COPY(MyItem)
public:
    explicit MyItem(QObject *parent = nullptr);
    ~MyItem() override;
     void setName(QString name);
private:
QString m_name;
};

#endif // MYITEM_H
