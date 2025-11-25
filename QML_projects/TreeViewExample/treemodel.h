// #pragma once
// #include <QAbstractItemModel>
// #include <QMap>

// class Company;

// class TreeModel : public QAbstractItemModel
// {
//     Q_OBJECT

// public:
//     enum CustomRoles {
//         CompanyIdRole = Qt::UserRole + 1,
//         ImageRole = Qt::UserRole + 2,
//         IsCompanyRole = Qt::UserRole + 3,
//         NameRole = Qt::UserRole + 4,
//         YearRole = Qt::UserRole + 5,
//         RoleRole = Qt::UserRole + 6,
//         EmailRole = Qt::UserRole + 7,
//         LocationRole = Qt::UserRole + 8,
//         IndustryRole = Qt::UserRole + 9,
//         CeoRole = Qt::UserRole + 10,
//         selectedRole = Qt::UserRole + 11,
//         StatusRole = Qt::UserRole + 12
//     };
//     Q_ENUM(CustomRoles)

//     explicit TreeModel(QObject *parent = nullptr);
//     explicit TreeModel(const QMap<int, Company*> &companies, QObject *parent = nullptr);
//     ~TreeModel();

//     QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
//     Qt::ItemFlags flags(const QModelIndex &index) const override;
//     QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
//     QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
//     QModelIndex parent(const QModelIndex &index) const override;
//     int rowCount(const QModelIndex &parent = QModelIndex()) const override;
//     int columnCount(const QModelIndex &parent = QModelIndex()) const override;
//     QHash<int, QByteArray> roleNames() const override;

//     void setupFromCompanyMap(const QMap<int, Company*> &companies);
//     Q_INVOKABLE QVariantMap getCompanyData(int row) const;
//     Q_INVOKABLE QVariantMap getCompanyDataByIndex(const QModelIndex &index) const;
//     Q_INVOKABLE bool updateCompanyField(const QModelIndex &index, int column, const QString &value);
//     Q_INVOKABLE void addCompany(const QString &name, const QString &id, const QString &year,
//                                const QString &location, const QString &industry, const QString &ceo);
//     Q_INVOKABLE void addEmptyTemplate();
//     Q_INVOKABLE void deleteCompany();
//     Q_INVOKABLE void addSubLevel(int companyRow, int subLevel);
//     Q_INVOKABLE bool selectedCompany(int companyRow);

// private:
//     QList<Company*> m_companies;
//     int getCompanyRowFromVisualRow(int visualRow) const;
// };












#pragma once
#include <QAbstractItemModel>
#include <QMap>

class Company;

class TreeModel : public QAbstractItemModel
{
    Q_OBJECT

public:
    enum CustomRoles {
        CompanyIdRole = Qt::UserRole + 1,
        ImageRole = Qt::UserRole + 2,
        IsCompanyRole = Qt::UserRole + 3,
        NameRole = Qt::UserRole + 4,
        YearRole = Qt::UserRole + 5,
        RoleRole = Qt::UserRole + 6,
        EmailRole = Qt::UserRole + 7,
        LocationRole = Qt::UserRole + 8,
        IndustryRole = Qt::UserRole + 9,
        CeoRole = Qt::UserRole + 10,
        selectedRole = Qt::UserRole + 11,
        StatusRole = Qt::UserRole + 12
    };
    Q_ENUM(CustomRoles)

    explicit TreeModel(QObject *parent = nullptr);
    explicit TreeModel(const QMap<int, Company*> &companies, QObject *parent = nullptr);
    ~TreeModel();

    QVariant data(const QModelIndex &index, int role = Qt::DisplayRole) const override;
    Qt::ItemFlags flags(const QModelIndex &index) const override;
    QVariant headerData(int section, Qt::Orientation orientation, int role = Qt::DisplayRole) const override;
    QModelIndex index(int row, int column, const QModelIndex &parent = QModelIndex()) const override;
    QModelIndex parent(const QModelIndex &index) const override;
    int rowCount(const QModelIndex &parent = QModelIndex()) const override;
    int columnCount(const QModelIndex &parent = QModelIndex()) const override;
    QHash<int, QByteArray> roleNames() const override;

    void setupFromCompanyMap(const QMap<int, Company*> &companies);
    Q_INVOKABLE QVariantMap getCompanyData(int row) const;
    Q_INVOKABLE QVariantMap getCompanyDataByIndex(const QModelIndex &index) const;
    Q_INVOKABLE bool updateCompanyField(const QModelIndex &index, int column, const QString &value);
    Q_INVOKABLE void addCompany(const QString &name, const QString &id, const QString &year,
                                const QString &location, const QString &industry, const QString &ceo);
    Q_INVOKABLE void addEmptyTemplate();
    Q_INVOKABLE void deleteCompany();
    Q_INVOKABLE void addSubLevel(int companyRow, int subLevel);

    // Selection + child-adding helpers exposed to QML:
    Q_INVOKABLE bool selectedCompany(int companyRow);    // toggles selection for a top-level company row
    Q_INVOKABLE void addChildForSelected();              // Add empty child under selected company
    Q_INVOKABLE void addSub1ForSelected();               // copy ID -> child ID (column 1)
    Q_INVOKABLE void addSub2ForSelected();               // copy ID + Year
    Q_INVOKABLE void addSub3ForSelected();               // copy ID + Year + Location

private:
    QList<Company*> m_companies;
    int getCompanyRowFromVisualRow(int visualRow) const;

    // currently selected top-level row (or -1 if none)
    int m_selectedCompanyRow = -1;

    // internal helper to add a child under companyRow, copying first copyCount columns (mapping explained below)
    void addChildUnderCompany(int companyRow, int copyCount);
};
