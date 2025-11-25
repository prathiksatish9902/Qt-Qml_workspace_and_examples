#ifndef IMAGEMODEL_H
#define IMAGEMODEL_H

#include <QAbstractListModel>
#include <QMap>
#include <QDateTime>
#include <QStringList>

class ImageModel : public QAbstractListModel
{
    Q_OBJECT
    Q_PROPERTY(QMap<QDateTime, QStringList> imagesByDate READ getImagesByDate WRITE setImagesByDate NOTIFY imagesByDateChanged FINAL)

public:
    explicit ImageModel(QObject *parent = nullptr);
    ~ImageModel();

    QMap<QDateTime, QStringList> getImagesByDate() const;
    void setImagesByDate(const QMap<QDateTime, QStringList> &newImagesByDate);

    // Load from CSV
    Q_INVOKABLE void loadFromCsv(const QString &csvPath);

    int rowCount(const QModelIndex &parent) const override;
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum Roles
    {
        DateRole = Qt::UserRole + 1,
        ImagesRole
    };

signals:
    void imagesByDateChanged();

private:
    QMap<QDateTime, QStringList> m_imagesByDate;
};

#endif // IMAGEMODEL_H
