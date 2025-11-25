#include "myitem.h"

#include <QPainter>

MyItem::MyItem(QObject *parent)
    : QObject(parent)
{
    qDebug()<<Q_FUNC_INFO;
}


MyItem::~MyItem() {
    qDebug()<<Q_FUNC_INFO;
}

void MyItem::setName(QString name)
{
    qDebug()<<Q_FUNC_INFO;
    m_name = name;
    qDebug() << "Name:" <<name;
}
