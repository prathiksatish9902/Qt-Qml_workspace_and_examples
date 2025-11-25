#include "mytreeview.h"
#include "company.h"
#include "employee.h"

TreeItem::TreeItem(TreeItem *parent)
    : m_type(Root), m_company(nullptr), m_employee(nullptr), m_parentItem(parent)
{
}

TreeItem::TreeItem(Company *company, TreeItem *parent)
    : m_type(CompanyType), m_company(company), m_employee(nullptr), m_parentItem(parent)
{
    setupFromCompany(company);
}

TreeItem::~TreeItem()
{
    qDeleteAll(m_childItems);
}

void TreeItem::setupFromCompany(Company *company)
{
    if (!company)
        return;

    // Add employees as children
    int empId = 0;
    for (auto emp : company->employeesAsQObjectList()) {
        TreeItem *empItem = new TreeItem(this);
        empItem->m_type = EmployeeType;
        empItem->m_employee = emp;
        appendChild(empId++, empItem);
    }
}

void TreeItem::appendChild(int key, TreeItem *child)
{
    if (!m_childItems.contains(key))
        m_childItems.insert(key, child);
}

TreeItem *TreeItem::child(int row) const
{
    if (row < 0 || row >= m_childItems.size())
        return nullptr;
    return m_childItems.values().at(row);
}

TreeItem *TreeItem::childByKey(int key) const
{
    return m_childItems.value(key, nullptr);
}

int TreeItem::childCount() const
{
    return m_childItems.size();
}

QList<int> TreeItem::childKeys() const
{
    return m_childItems.keys();
}

QString TreeItem::displayName() const
{
    switch (m_type) {
        case Root:
            return "";  // Root node, no display name needed
        case CompanyType: {
            if (!m_company)
                return "Unknown Company";
            return m_company->name();
        }
        case EmployeeType: {
            Employee *emp = static_cast<Employee*>(m_employee);
            if (!emp)
                return "Unknown Employee";
            // Display format: "Name (Role) - email"
            QString role = emp->role();
            QString name = emp->name();
            return QString("%1 (%2)").arg(name, role);
        }
    }
    return "Unknown";
}

Company *TreeItem::getCompany() const
{
    return m_company;
}

void *TreeItem::getEmployee() const
{
    return m_employee;
}

TreeItem::ItemType TreeItem::itemType() const
{
    return m_type;
}

TreeItem *TreeItem::parentItem() const
{
    return m_parentItem;
}

int TreeItem::row() const
{
    if (!m_parentItem)
        return 0;

    const QList<int> keys = m_parentItem->childKeys();
    for (int i = 0; i < keys.size(); ++i) {
        if (m_parentItem->childByKey(keys.at(i)) == this)
            return i;
    }
    return 0;
}
