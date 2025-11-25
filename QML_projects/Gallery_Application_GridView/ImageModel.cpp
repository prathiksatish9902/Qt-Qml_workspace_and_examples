#include "ImageModel.h"
#include <QFile>
#include <QTextStream>
#include <QDebug>

ImageModel::ImageModel(QObject *parent)
    : QAbstractListModel(parent)
{
    qDebug()<<Q_FUNC_INFO;
}

ImageModel::~ImageModel()
{
    qDebug()<<Q_FUNC_INFO;
}

QMap<QDateTime, QStringList> ImageModel::getImagesByDate() const
{
    return m_imagesByDate;
}

void ImageModel::setImagesByDate(const QMap<QDateTime, QStringList> &newImagesByDate)
{
    qDebug()<<Q_FUNC_INFO;
    if (m_imagesByDate == newImagesByDate)
        return;
    beginResetModel();
    m_imagesByDate = newImagesByDate;
    endResetModel();
    emit imagesByDateChanged();
}

void ImageModel::loadFromCsv(const QString &csvPath)
{
    QFile file(csvPath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text)) {
        qWarning() << "Cannot open CSV file:" << csvPath;
        return;
    }
    QMap<QDateTime, QStringList> imagesMap;
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList parts = line.split(",");
        if (parts.size() == 2) {
            QDate date = QDate::fromString(parts[0], "yyyy-MM-dd");
            QStringList images = parts[1].split("|", Qt::SkipEmptyParts);
            if (date.isValid()) {
                imagesMap[QDateTime(date, QTime(0,0,0))] = images;
            }
        }
    }
    setImagesByDate(imagesMap);
}

int ImageModel::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid()) return 0;
    return m_imagesByDate.size();
}

QVariant ImageModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || index.row() >= m_imagesByDate.size()) return QVariant();

    auto imageIterator = m_imagesByDate.begin();
    std::advance(imageIterator , index.row());

    switch(role)
    {
    case DateRole:
        return imageIterator.key().date().toString("dd MMM yyyy");
    case ImagesRole:
        return imageIterator.value();
    }
    return QVariant();
}

QHash<int, QByteArray> ImageModel::roleNames() const
{
    QHash<int, QByteArray> l_GalleryRole;
    l_GalleryRole[DateRole] = "date";
    l_GalleryRole[ImagesRole] = "images";
    return l_GalleryRole;
}
