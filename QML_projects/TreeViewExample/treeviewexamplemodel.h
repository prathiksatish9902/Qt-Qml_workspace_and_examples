#pragma once
#include <QAbstractItemModel>
#include <QString>
#include <QList>
#include <QVariant>

struct Employee {
    QString name;
    QString role;
};

struct Company {
    QString id;
    QString name;
    int year;
    QString image;
    QList<Employee> employees;
};

class TreeItem {
public:
    TreeItem(const QVariantMap &data, TreeItem *parent = nullptr);
    ~TreeItem();

    void appendChild(TreeItem *child);
    TreeItem *child(int row) const;
    int childCount() const;
    QVariant data(int role) const;
    int row() const;
    TreeItem *parentItem() const;

    QVariantMap m_data;
    QList<TreeItem*> m_children;
    TreeItem *m_parent;
};

class CompanyTreeModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    enum Roles {
        IdRole = Qt::UserRole + 1,
        NameRole,
        YearRole,
        ImageRole,
        RoleRole,
        IsCompanyRole
    };

    explicit CompanyTreeModel(QObject *parent = nullptr);
    ~CompanyTreeModel();

    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override { return 1; }
    QVariant data(const QModelIndex &index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    void loadFromBackend();

private:
    TreeItem *rootItem;
};
