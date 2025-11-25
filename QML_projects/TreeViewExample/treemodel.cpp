// #include "treemodel.h"
// #include "company.h"
// #include "employee.h"
// #include "qdebug.h"

// TreeModel::TreeModel(QObject *parent)
//     : QAbstractItemModel(parent)
// {
// }

// TreeModel::TreeModel(const QMap<int, Company*> &companies, QObject *parent)
//     : QAbstractItemModel(parent)
// {
//     setupFromCompanyMap(companies);
// }

// TreeModel::~TreeModel()
// {
// }

// void TreeModel::setupFromCompanyMap(const QMap<int, Company*> &companies)
// {
//     beginResetModel();
//     m_companies.clear();

//     for (auto it = companies.begin(); it != companies.end(); ++it) {
//         Company *company = it.value();
//         if (company) {
//             m_companies.append(company);
//         }
//     }

//     endResetModel();
// }

// QVariant TreeModel::data(const QModelIndex &index, int role) const
// {
//     if (!index.isValid())
//         return QVariant();

//     if (!index.parent().isValid()) {
//         // Top-level: companies
//         if (index.row() >= m_companies.size())
//             return QVariant();

//         Company *company = m_companies.at(index.row());

//         if (role == Qt::DisplayRole) {
//             switch (index.column()) {
//             case 0: return company->name();
//             case 1: return company->id();
//             case 2: return company->year();
//             case 3: return company->location();
//             case 4: return company->industry();
//             case 5: return company->ceo();
//             case 6: return company->status(); // Status column
//             case 7: return "⚙️"; // Action column (icon)
//             case 8: return "⭐⭐⭐⭐⭐"; // Rating column (icon)
//             default: return QVariant();
//             }
//         }

//         if (role == ImageRole)
//             return company->image();

//         if (role == IsCompanyRole)
//             return true;

//         if (role == CompanyIdRole)
//             return company->id();

//         if (role == NameRole)
//             return company->name();

//         if (role == YearRole)
//             return company->year();

//         if (role == LocationRole)
//             return company->location();

//         if (role == IndustryRole)
//             return company->industry();

//         if (role == CeoRole)
//             return company->ceo();

//         if(role == selectedRole)
//             return company->selected();

//         if(role == StatusRole)
//             return company->status();

//     } else {
//         // Children: employees
//         int parentRow = index.parent().row();
//         if (parentRow >= m_companies.size())
//             return QVariant();

//         Company *company = m_companies.at(parentRow);
//         auto employees = company->employeesAsQObjectList();

//         if (index.row() >= employees.size())
//             return QVariant();

//         Employee *emp = static_cast<Employee*>(employees.at(index.row()));
//         if (!emp)
//             return QVariant();

//         if (role == Qt::DisplayRole) {
//             switch (index.column()) {
//             case 0: return emp->name();
//             case 1: return emp->id();
//             case 2: return "";
//             case 3: return "";
//             case 4: return emp->role();
//             case 5: return "";
//             default: return QVariant();
//             }
//         }

//         if (role == IsCompanyRole)
//             return false;

//         if (role == NameRole)
//             return emp->name();

//         if (role == CompanyIdRole)
//             return emp->id();

//         if (role == RoleRole)
//             return emp->role();

//         if (role == EmailRole)
//             return emp->email();
//     }

//     return QVariant();
// }

// QHash<int, QByteArray> TreeModel::roleNames() const
// {
//     QHash<int, QByteArray> roles;
//     roles[Qt::DisplayRole] = "display";
//     roles[ImageRole] = "image";
//     roles[IsCompanyRole] = "isCompany";
//     roles[CompanyIdRole] = "companyId";
//     roles[NameRole] = "name";
//     roles[YearRole] = "year";
//     roles[RoleRole] = "role";
//     roles[EmailRole] = "email";
//     roles[LocationRole] = "location";
//     roles[IndustryRole] = "industry";
//     roles[CeoRole] = "ceo";
//     roles[selectedRole] = "selected";
//     roles[StatusRole] = "status";
//     return roles;
// }

// Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
// {
//     if (!index.isValid())
//         return Qt::NoItemFlags;
//     return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
// }

// QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
// {
//     if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
//         switch (section) {
//         case 0: return "Name";
//         case 1: return "ID";
//         case 2: return "Year";
//         case 3: return "Location";
//         case 4: return "Industry";
//         case 5: return "CEO";
//         default: return QVariant();
//         }
//     }
//     return QVariant();
// }

// QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
// {
//     if (!hasIndex(row, column, parent))
//         return QModelIndex();

//     if (!parent.isValid()) {
//         // Top-level companies - use row as internal id
//         if (row < m_companies.size())
//             return createIndex(row, column, (quintptr)row);
//     } else {
//         // Employees under company
//         int parentRow = parent.row();
//         if (parentRow < m_companies.size()) {
//             Company *company = m_companies.at(parentRow);
//             if (row < company->employeesAsQObjectList().size()) {
//                 // Use negative parent row + 1 to distinguish employees
//                 return createIndex(row, column, (quintptr)(parentRow + 1000));
//             }
//         }
//     }

//     return QModelIndex();
// }

// QModelIndex TreeModel::parent(const QModelIndex &index) const
// {
//     if (!index.isValid())
//         return QModelIndex();

//     quintptr id = (quintptr)index.internalId();

//     // If id >= 1000, this is an employee (id - 1000 is the parent company row)
//     if (id >= 1000) {
//         int parentRow = id - 1000;
//         if (parentRow >= 0 && parentRow < m_companies.size())
//             return createIndex(parentRow, 0, (quintptr)parentRow);
//     }

//     return QModelIndex();
// }

// int TreeModel::rowCount(const QModelIndex &parent) const
// {
//     if (!parent.isValid()) {
//         // Top-level: companies
//         return m_companies.size();
//     }

//     // Show employees under companies
//     if (parent.row() >= 0 && parent.row() < m_companies.size()) {
//         Company *company = m_companies.at(parent.row());
//         return company->employeesAsQObjectList().size();
//     }

//     return 0;
// }

// int TreeModel::columnCount(const QModelIndex &parent) const
// {
//     Q_UNUSED(parent);
//     return 9;
// }

// int TreeModel::getCompanyRowFromVisualRow(int visualRow) const
// {
//     for (int i = 0; i < m_companies.size(); ++i) {
//         if (i == visualRow) {
//             return i;
//         }
//     }

//     return -1;
// }

// QVariantMap TreeModel::getCompanyData(int row) const
// {
//     QVariantMap result;

//     // Find the actual company index from visual row
//     int companyIndex = getCompanyRowFromVisualRow(row);

//     if (companyIndex >= 0 && companyIndex < m_companies.size()) {
//         Company *company = m_companies.at(companyIndex);

//         result["name"] = company->name();
//         result["id"] = company->id();
//         result["year"] = company->year();
//         result["image"] = company->image();

//         QString employeesList;
//         auto employees = company->employeesAsQObjectList();
//         for (int i = 0; i < employees.size(); ++i) {
//             Employee *emp = static_cast<Employee*>(employees.at(i));
//             if (emp) {
//                 if (i > 0) employeesList += "\n";
//                 employeesList += QString("• %1 (%2) - %3")
//                                      .arg(emp->name(), emp->role(), emp->email());
//             }
//         }
//         result["employees"] = employeesList;
//     }

//     return result;
// }

// QVariantMap TreeModel::getCompanyDataByIndex(const QModelIndex &index) const
// {
//     QVariantMap result;

//     if (!index.isValid() || index.row() >= m_companies.size())
//         return result;

//     Company *company = m_companies.at(index.row());

//     result["name"] = company->name();
//     result["id"] = company->id();
//     result["year"] = company->year();
//     result["image"] = company->image();

//     QString employeesList;
//     auto employees = company->employeesAsQObjectList();
//     for (int i = 0; i < employees.size(); ++i) {
//         Employee *emp = static_cast<Employee*>(employees.at(i));
//         if (emp) {
//             if (i > 0) employeesList += "\n";
//             employeesList += QString("• %1 (%2) - %3")
//                                  .arg(emp->name(), emp->role(), emp->email());
//         }
//     }
//     result["employees"] = employeesList;

//     return result;
// }

// void TreeModel::addCompany(const QString &name, const QString &id, const QString &year,
//                            const QString &location, const QString &industry, const QString &ceo)
// {
//     beginInsertRows(QModelIndex(), m_companies.size(), m_companies.size());

//     Company *newCompany = new Company(id, name, year, "🏢", this);
//     newCompany->setLocation(location);
//     newCompany->setIndustry(industry);
//     newCompany->setCeo(ceo);

//     m_companies.append(newCompany);

//     endInsertRows();
// }

// bool TreeModel::updateCompanyField(const QModelIndex &index, int column, const QString &value)
// {
//     if (!index.isValid() || index.parent().isValid()) {
//         return false; // Only update companies, not employees
//     }

//     if (index.row() >= m_companies.size()) {
//         return false;
//     }

//     Company *company = m_companies.at(index.row());
//     if (!company) {
//         return false;
//     }

//     bool updated = false;
//     switch (column) {
//     case 0:
//         company->setName(value);
//         updated = true;
//         break;
//     case 1:
//         company->setId(value);
//         updated = true;
//         break;
//     case 2:
//         company->setYear(value);
//         updated = true;
//         break;
//     case 3:
//         company->setLocation(value);
//         updated = true;
//         break;
//     case 4:
//         company->setIndustry(value);
//         updated = true;
//         break;
//     case 5:
//         company->setCeo(value);
//         updated = true;
//         break;
//     case 6:
//         company->setStatus(value);
//         updated = true;
//         break;
//     default:
//         break;
//     }

//     if (updated) {
//         emit dataChanged(index, index);
//         return true;
//     }

//     return false;
// }

// void TreeModel::addEmptyTemplate()
// {
//     beginInsertRows(QModelIndex(), m_companies.size(), m_companies.size());

//     Company *emptyCompany = new Company("", "", "", "https://via.placeholder.com/50x50?text=+", this);
//     emptyCompany->setLocation("");
//     emptyCompany->setIndustry("");
//     emptyCompany->setCeo("");
//     emptyCompany->setStatus("");

//     m_companies.append(emptyCompany);

//     endInsertRows();
// }

// void TreeModel::deleteCompany()
// {

// }

// void TreeModel::addSubLevel(int companyRow, int subLevel)
// {
//     if (companyRow < 0 || companyRow >= m_companies.size()) {
//         return;
//     }

//     Company *company = m_companies.at(companyRow);
//     if (!company) {
//         return;
//     }

//     // Clear existing employees to start fresh
//     company->clearEmployees();

//     // Add sub-level entries based on the level requested
//     QModelIndex parentIndex = index(companyRow, 0);

//     QString subLevelNames[] = {"ID Entry", "Year Entry", "Location Entry", "Industry Entry", "CEO Entry", "Status Entry"};

//     // Add entries up to the requested sub level
//     for (int i = 0; i < subLevel && i < 6; ++i) {
//         beginInsertRows(parentIndex, i, i);

//         Employee *subEntry = new Employee(QString("sub_%1_%2").arg(companyRow).arg(i),
//                                           subLevelNames[i],
//                                           QString("Level %1").arg(i + 1),
//                                           "", company);
//         company->addEmployee(subEntry);

//         endInsertRows();
//     }
// }

// // bool TreeModel::selectedCompany(int companyRow)
// // {
// //     // companyRow passed from QML is a visual row (TreeView row). Map it to actual company index.
// //     int companyIndex = getCompanyRowFromVisualRow(companyRow);
// //     if (companyIndex < 0 || companyIndex >= m_companies.size()) {
// //         return false;
// //     }

// //     Company *company = m_companies.at(companyIndex);
// //     if (!company) {
// //         return false;
// //     }else{
// //         qDebug() << "In else of selected";
// //     }

// //     company->setSelected(!company->selected());

// //     // notify view for the actual company row (map back to index)
// //     QModelIndex startingIndex = createIndex(companyIndex, 0, (quintptr)companyIndex);
// //     QModelIndex endingIndex = createIndex(companyIndex, columnCount() - 1, (quintptr)companyIndex);
// //     emit dataChanged(startingIndex, endingIndex);

// //     qDebug() << Q_FUNC_INFO << "CompanyIndex" << companyIndex << "(visualRow" << companyRow << ") selected:" << company->selected();

// //     return true;
// // }
// bool TreeModel::selectedCompany(int companyRow)
// {
//     qDebug() << Q_FUNC_INFO << "Input companyRow (visual):" << companyRow;
    
//     // For a flat company list, visual row == actual index
//     if (companyRow < 0 || companyRow >= m_companies.size()) {
//         qDebug() << "Invalid company row:" << companyRow << "size:" << m_companies.size();
//         return false;
//     }

//     Company *company = m_companies.at(companyRow);
//     if (!company) {
//         qDebug() << "Company at row" << companyRow << "is null";
//         return false;
//     }

//     // First, clear selection from all other companies
//     for (int i = 0; i < m_companies.size(); ++i) {
//         if (i != companyRow && m_companies.at(i)->selected()) {
//             m_companies.at(i)->setSelected(false);
//         }
//     }

//     // Toggle selected state of clicked company
//     bool newState = !company->selected();
//     company->setSelected(newState);

//     // Force a complete model refresh to ensure UI updates
//     emit beginResetModel();
//     emit endResetModel();

//     qDebug() << Q_FUNC_INFO << "Company:" << company->name()
//              << "at row:" << companyRow << "selected:" << newState;

//     return true;
// }



















#include "treemodel.h"
#include "company.h"
#include "employee.h"
#include <QDebug>

TreeModel::TreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
}

TreeModel::TreeModel(const QMap<int, Company*> &companies, QObject *parent)
    : QAbstractItemModel(parent)
{
    setupFromCompanyMap(companies);
}

TreeModel::~TreeModel()
{
}

void TreeModel::setupFromCompanyMap(const QMap<int, Company*> &companies)
{
    beginResetModel();
    m_companies.clear();

    for (auto it = companies.begin(); it != companies.end(); ++it) {
        Company *company = it.value();
        if (company) {
            m_companies.append(company);
        }
    }

    endResetModel();
}

QVariant TreeModel::data(const QModelIndex &index, int role) const
{
    if (!index.isValid())
        return QVariant();

    if (!index.parent().isValid()) {
        // Top-level: companies
        if (index.row() >= m_companies.size())
            return QVariant();

        Company *company = m_companies.at(index.row());

        if (role == Qt::DisplayRole) {
            switch (index.column()) {
            case 0: return company->name();
            case 1: return company->id();
            case 2: return company->year();
            case 3: return company->location();
            case 4: return company->industry();
            case 5: return company->ceo();
            case 6: return company->status(); // Status column
            case 7: return "⚙️"; // Action column (icon)
            case 8: return "⭐⭐⭐⭐⭐"; // Rating column (icon)
            default: return QVariant();
            }
        }

        if (role == ImageRole)
            return company->image();

        if (role == IsCompanyRole)
            return true;

        if (role == CompanyIdRole)
            return company->id();

        if (role == NameRole)
            return company->name();

        if (role == YearRole)
            return company->year();

        if (role == LocationRole)
            return company->location();

        if (role == IndustryRole)
            return company->industry();

        if (role == CeoRole)
            return company->ceo();

        if(role == selectedRole)
            return company->selected();

        if(role == StatusRole)
            return company->status();

    } else {
        // Children: employees
        int parentRow = index.parent().row();
        if (parentRow >= m_companies.size())
            return QVariant();

        Company *company = m_companies.at(parentRow);
        auto employees = company->employeesAsQObjectList();

        if (index.row() >= employees.size())
            return QVariant();

        Employee *emp = static_cast<Employee*>(employees.at(index.row()));
        if (!emp)
            return QVariant();

        if (role == Qt::DisplayRole) {
            // Map employee fields to the same visual columns as companies so copying makes sense:
            // column 0 -> we still show a small icon reserved column (kept empty for employees)
            // column 1 -> emp->id (shows copied company id when requested)
            // column 2 -> emp->role (used for copied year)
            // column 3 -> emp->email (used for copied location)
            // to preserve original delegates, for column 0 we'll show name (if any)
            switch (index.column()) {
            case 0: return emp->name();
            case 1: return emp->id();
            case 2: return emp->role();
            case 3: return emp->email();
            default: return QVariant();
            }
        }

        if (role == IsCompanyRole)
            return false;

        if (role == NameRole)
            return emp->name();

        if (role == CompanyIdRole)
            return emp->id();

        if (role == RoleRole)
            return emp->role();

        if (role == EmailRole)
            return emp->email();
    }

    return QVariant();
}

QHash<int, QByteArray> TreeModel::roleNames() const
{
    QHash<int, QByteArray> roles;
    roles[Qt::DisplayRole] = "display";
    roles[ImageRole] = "image";
    roles[IsCompanyRole] = "isCompany";
    roles[CompanyIdRole] = "companyId";
    roles[NameRole] = "name";
    roles[YearRole] = "year";
    roles[RoleRole] = "role";
    roles[EmailRole] = "email";
    roles[LocationRole] = "location";
    roles[IndustryRole] = "industry";
    roles[CeoRole] = "ceo";
    roles[selectedRole] = "selected";
    roles[StatusRole] = "status";
    return roles;
}

Qt::ItemFlags TreeModel::flags(const QModelIndex &index) const
{
    if (!index.isValid())
        return Qt::NoItemFlags;
    return Qt::ItemIsEnabled | Qt::ItemIsSelectable;
}

QVariant TreeModel::headerData(int section, Qt::Orientation orientation, int role) const
{
    if (orientation == Qt::Horizontal && role == Qt::DisplayRole) {
        switch (section) {
        case 0: return "Name";
        case 1: return "ID";
        case 2: return "Year";
        case 3: return "Location";
        case 4: return "Industry";
        case 5: return "CEO";
        default: return QVariant();
        }
    }
    return QVariant();
}

QModelIndex TreeModel::index(int row, int column, const QModelIndex &parent) const
{
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    if (!parent.isValid()) {
        // Top-level companies - use row as internal id
        if (row < m_companies.size())
            return createIndex(row, column, (quintptr)row);
    } else {
        // Employees under company
        int parentRow = parent.row();
        if (parentRow < m_companies.size()) {
            Company *company = m_companies.at(parentRow);
            if (row < company->employeesAsQObjectList().size()) {
                // Use offset 1000 to distinguish employees in internalId
                return createIndex(row, column, (quintptr)(parentRow + 1000));
            }
        }
    }

    return QModelIndex();
}

QModelIndex TreeModel::parent(const QModelIndex &index) const
{
    if (!index.isValid())
        return QModelIndex();

    quintptr id = (quintptr)index.internalId();

    // If id >= 1000, this is an employee (id - 1000 is the parent company row)
    if (id >= 1000) {
        int parentRow = id - 1000;
        if (parentRow >= 0 && parentRow < m_companies.size())
            return createIndex(parentRow, 0, (quintptr)parentRow);
    }

    return QModelIndex();
}

int TreeModel::rowCount(const QModelIndex &parent) const
{
    if (!parent.isValid()) {
        // Top-level: companies
        return m_companies.size();
    }

    // Show employees under companies
    if (parent.row() >= 0 && parent.row() < m_companies.size()) {
        Company *company = m_companies.at(parent.row());
        return company->employeesAsQObjectList().size();
    }

    return 0;
}

int TreeModel::columnCount(const QModelIndex &parent) const
{
    Q_UNUSED(parent);
    return 9;
}

int TreeModel::getCompanyRowFromVisualRow(int visualRow) const
{
    for (int i = 0; i < m_companies.size(); ++i) {
        if (i == visualRow) {
            return i;
        }
    }

    return -1;
}

QVariantMap TreeModel::getCompanyData(int row) const
{
    QVariantMap result;

    // Find the actual company index from visual row
    int companyIndex = getCompanyRowFromVisualRow(row);

    if (companyIndex >= 0 && companyIndex < m_companies.size()) {
        Company *company = m_companies.at(companyIndex);

        result["name"] = company->name();
        result["id"] = company->id();
        result["year"] = company->year();
        result["image"] = company->image();

        QString employeesList;
        auto employees = company->employeesAsQObjectList();
        for (int i = 0; i < employees.size(); ++i) {
            Employee *emp = static_cast<Employee*>(employees.at(i));
            if (emp) {
                if (i > 0) employeesList += "\n";
                employeesList += QString("• %1 (%2) - %3")
                                     .arg(emp->name(), emp->role(), emp->email());
            }
        }
        result["employees"] = employeesList;
    }

    return result;
}

QVariantMap TreeModel::getCompanyDataByIndex(const QModelIndex &index) const
{
    QVariantMap result;

    if (!index.isValid() || index.row() >= m_companies.size())
        return result;

    Company *company = m_companies.at(index.row());

    result["name"] = company->name();
    result["id"] = company->id();
    result["year"] = company->year();
    result["image"] = company->image();

    QString employeesList;
    auto employees = company->employeesAsQObjectList();
    for (int i = 0; i < employees.size(); ++i) {
        Employee *emp = static_cast<Employee*>(employees.at(i));
        if (emp) {
            if (i > 0) employeesList += "\n";
            employeesList += QString("• %1 (%2) - %3")
                                 .arg(emp->name(), emp->role(), emp->email());
        }
    }
    result["employees"] = employeesList;

    return result;
}

void TreeModel::addCompany(const QString &name, const QString &id, const QString &year,
                           const QString &location, const QString &industry, const QString &ceo)
{
    beginInsertRows(QModelIndex(), m_companies.size(), m_companies.size());

    Company *newCompany = new Company(id, name, year, "🏢", this);
    newCompany->setLocation(location);
    newCompany->setIndustry(industry);
    newCompany->setCeo(ceo);

    m_companies.append(newCompany);

    endInsertRows();
}

bool TreeModel::updateCompanyField(const QModelIndex &index, int column, const QString &value)
{
    if (!index.isValid() || index.parent().isValid()) {
        return false; // Only update companies, not employees
    }

    if (index.row() >= m_companies.size()) {
        return false;
    }

    Company *company = m_companies.at(index.row());
    if (!company) {
        return false;
    }

    bool updated = false;
    switch (column) {
    case 0:
        company->setName(value);
        updated = true;
        break;
    case 1:
        company->setId(value);
        updated = true;
        break;
    case 2:
        company->setYear(value);
        updated = true;
        break;
    case 3:
        company->setLocation(value);
        updated = true;
        break;
    case 4:
        company->setIndustry(value);
        updated = true;
        break;
    case 5:
        company->setCeo(value);
        updated = true;
        break;
    case 6:
        company->setStatus(value);
        updated = true;
        break;
    default:
        break;
    }

    if (updated) {
        // notify all columns for the updated row
        QModelIndex start = createIndex(index.row(), 0, (quintptr)index.row());
        QModelIndex end = createIndex(index.row(), columnCount() - 1, (quintptr)index.row());
        emit dataChanged(start, end);
        return true;
    }

    return false;
}

void TreeModel::addEmptyTemplate()
{
    // Keep original behavior: add a new top-level empty company
    beginInsertRows(QModelIndex(), m_companies.size(), m_companies.size());

    Company *emptyCompany = new Company("", "", "", "https://via.placeholder.com/50x50?text=+", this);
    emptyCompany->setLocation("");
    emptyCompany->setIndustry("");
    emptyCompany->setCeo("");
    emptyCompany->setStatus("");

    m_companies.append(emptyCompany);

    endInsertRows();
}

void TreeModel::deleteCompany()
{

}

void TreeModel::addSubLevel(int companyRow, int subLevel)
{
    // legacy / different behavior - not used by QML in updated UI
    if (companyRow < 0 || companyRow >= m_companies.size()) {
        return;
    }

    Company *company = m_companies.at(companyRow);
    if (!company) {
        return;
    }

    // Clear existing employees to start fresh
    company->clearEmployees();

    // Add sub-level entries based on the level requested
    QModelIndex parentIndex = index(companyRow, 0);

    QString subLevelNames[] = {"ID Entry", "Year Entry", "Location Entry", "Industry Entry", "CEO Entry", "Status Entry"};

    // Add entries up to the requested sub level
    for (int i = 0; i < subLevel && i < 6; ++i) {
        beginInsertRows(parentIndex, i, i);

        Employee *subEntry = new Employee(QString("sub_%1_%2").arg(companyRow).arg(i),
                                          subLevelNames[i],
                                          QString("Level %1").arg(i + 1),
                                          "", company);
        company->addEmployee(subEntry);

        endInsertRows();
    }
}

void TreeModel::addChildUnderCompany(int companyRow, int copyCount)
{
    // If no selection, treat as top-level insert
    if (companyRow < 0 || companyRow >= m_companies.size()) {
        qDebug() << "No valid selected company -> adding top-level company instead";
        addEmptyTemplate();
        return;
    }

    Company *company = m_companies.at(companyRow);
    if (!company) {
        return;
    }

    auto employees = company->employeesAsQObjectList();
    int pos = employees.size();
    QModelIndex parentIndex = index(companyRow, 0);

    beginInsertRows(parentIndex, pos, pos);

    // Create new Employee under company (so it will be deleted with company)
    // We create the employee as a QObject child of the Company to keep lifetime tied.
    Employee *child = new Employee("", "", "", "", company);

    // Copy mapping:
    // - Add Sub 1 (copyCount >=1): copy company->id -> employee->id (so child shows ID in column 1)
    // - Add Sub 2 (copyCount >=2): copy company->id -> emp->id, company->year -> emp->role
    // - Add Sub 3 (copyCount >=3): copy company->id -> emp->id, company->year -> emp->role, company->location -> emp->email
    if (copyCount >= 1) child->setId(company->id());
    if (copyCount >= 2) child->setRole(company->year());
    if (copyCount >= 3) child->setEmail(company->location());

    // Name can remain empty unless you want to copy it; leaving blank preserves "format-only" requirement.
    company->addEmployee(child);

    endInsertRows();

    // Notify view for the parent row to show it has children (if delegates depend on that)
    QModelIndex start = createIndex(companyRow, 0, (quintptr)companyRow);
    QModelIndex end = createIndex(companyRow, columnCount() - 1, (quintptr)companyRow);
    emit dataChanged(start, end);
}

bool TreeModel::selectedCompany(int companyRow)
{
    qDebug() << Q_FUNC_INFO << "Input companyRow (visual):" << companyRow;

    if (companyRow < 0 || companyRow >= m_companies.size()) {
        qDebug() << "Invalid company row:" << companyRow << "size:" << m_companies.size();
        return false;
    }

    Company *company = m_companies.at(companyRow);
    if (!company) {
        qDebug() << "Company at row" << companyRow << "is null";
        return false;
    }

    // Toggle selection state for this row, clear others
    bool newState = !company->selected();

    // track rows whose selection changed so we can emit dataChanged for each
    QList<int> changedRows;

    for (int i = 0; i < m_companies.size(); ++i) {
        Company *c = m_companies.at(i);
        if (!c) continue;
        if (i == companyRow) {
            if (c->selected() != newState) {
                c->setSelected(newState);
                changedRows.append(i);
            }
        } else {
            if (c->selected()) {
                c->setSelected(false);
                changedRows.append(i);
            }
        }
    }

    // Update internal selected row variable
    m_selectedCompanyRow = (newState ? companyRow : -1);

    // Notify only the rows that changed
    for (int r : changedRows) {
        QModelIndex start = createIndex(r, 0, (quintptr)r);
        QModelIndex end = createIndex(r, columnCount() - 1, (quintptr)r);
        emit dataChanged(start, end);
    }

    qDebug() << Q_FUNC_INFO << "Company:" << company->name()
             << "at row:" << companyRow << "selected:" << newState;

    return true;
}

void TreeModel::addChildForSelected()
{
    addChildUnderCompany(m_selectedCompanyRow, 0);
}

void TreeModel::addSub1ForSelected()
{
    addChildUnderCompany(m_selectedCompanyRow, 1);
}

void TreeModel::addSub2ForSelected()
{
    addChildUnderCompany(m_selectedCompanyRow, 2);
}

void TreeModel::addSub3ForSelected()
{
    addChildUnderCompany(m_selectedCompanyRow, 3);
}
