#pragma once
#include <QMap>
#include <QStringList>

class Company;

class TreeItem
{
public:
    enum ItemType { Root, CompanyType, EmployeeType };

    explicit TreeItem(TreeItem *parent = nullptr);
    explicit TreeItem(Company *company, TreeItem *parent = nullptr);
    ~TreeItem();

    void appendChild(int key, TreeItem *child);
    TreeItem *child(int row) const;
    TreeItem *childByKey(int key) const;

    int childCount() const;
    QList<int> childKeys() const;

    QString displayName() const;
    Company *getCompany() const;
    void *getEmployee() const;
    ItemType itemType() const;

    TreeItem *parentItem() const;
    int row() const;

private:
    void setupFromCompany(Company *company);
    
    ItemType m_type;
    Company *m_company;
    void *m_employee;  // Employee pointer (avoid circular include)
    TreeItem *m_parentItem;
    QMap<int, TreeItem*> m_childItems;
};
