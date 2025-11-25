#include "myitem.h"

MyItem::MyItem(QObject *parent)
    : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
}

MyItem::~MyItem()
{
    qDebug()<<Q_FUNC_INFO;
}

QString MyItem::getName() const
{
    qDebug()<<Q_FUNC_INFO;
    return m_name;
}

void MyItem::setName(const QString &newName)
{
    qDebug()<<Q_FUNC_INFO;
    m_name = newName;
}
