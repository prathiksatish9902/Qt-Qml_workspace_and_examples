#include "treeviewexamplemodel.h"

// ===== TreeItem =====
TreeItem::TreeItem(const QVariantMap &data, TreeItem *parent)
    : m_data(data), m_parent(parent) {}

TreeItem::~TreeItem() { qDeleteAll(m_children); }

void TreeItem::appendChild(TreeItem *child) { m_children.append(child); }

TreeItem *TreeItem::child(int row) const { return m_children.value(row); }

int TreeItem::childCount() const { return m_children.size(); }

int TreeItem::row() const {
    if (m_parent)
        return m_parent->m_children.indexOf(const_cast<TreeItem*>(this));
    return 0;
}

TreeItem *TreeItem::parentItem() const { return m_parent; }

QVariant TreeItem::data(int role) const {
    return m_data.value(QString::number(role));
}

// ===== Model =====
CompanyTreeModel::CompanyTreeModel(QObject *parent)
    : QAbstractItemModel(parent)
{
    rootItem = new TreeItem({});
    loadFromBackend();
}

CompanyTreeModel::~CompanyTreeModel() { delete rootItem; }

int CompanyTreeModel::rowCount(const QModelIndex &parent) const {
    TreeItem *parentItem = parent.isValid() ? static_cast<TreeItem*>(parent.internalPointer()) : rootItem;
    return parentItem->childCount();
}

QModelIndex CompanyTreeModel::index(int row, int column, const QModelIndex &parent) const {
    if (!hasIndex(row, column, parent))
        return QModelIndex();

    TreeItem *parentItem = parent.isValid() ? static_cast<TreeItem*>(parent.internalPointer()) : rootItem;
    TreeItem *childItem = parentItem->child(row);
    if (childItem)
        return createIndex(row, column, childItem);
    return QModelIndex();
}

QModelIndex CompanyTreeModel::parent(const QModelIndex &index) const {
    if (!index.isValid()) return QModelIndex();

    TreeItem *childItem = static_cast<TreeItem*>(index.internalPointer());
    TreeItem *parentItem = childItem->parentItem();
    if (parentItem == rootItem || !parentItem)
        return QModelIndex();

    return createIndex(parentItem->row(), 0, parentItem);
}

QVariant CompanyTreeModel::data(const QModelIndex &index, int role) const {
    if (!index.isValid()) return QVariant();
    TreeItem *item = static_cast<TreeItem*>(index.internalPointer());
    return item->m_data.value(QString::number(role));
}

QHash<int, QByteArray> CompanyTreeModel::roleNames() const {
    return {
        {IdRole, "id"},
        {NameRole, "name"},
        {YearRole, "year"},
        {ImageRole, "image"},
        {RoleRole, "role"},
        {IsCompanyRole, "isCompany"}
    };
}

void CompanyTreeModel::loadFromBackend() {
    QList<Company> companies = {
        {"C001", "TechCorp", 2005, ":/images/techcorp.png",
         {{"Alice", "Engineer"}, {"Bob", "Manager"}}},
        {"C002", "SoftVision", 2010, ":/images/softvision.png",
         {{"Charlie", "Designer"}, {"Diana", "Developer"}}}
    };

    for (const auto &c : companies) {
        QVariantMap companyMap;
        companyMap[QString::number(IdRole)] = c.id;
        companyMap[QString::number(NameRole)] = c.name;
        companyMap[QString::number(YearRole)] = c.year;
        companyMap[QString::number(ImageRole)] = c.image;
        companyMap[QString::number(IsCompanyRole)] = true;

        TreeItem *companyItem = new TreeItem(companyMap, rootItem);
        rootItem->appendChild(companyItem);

        for (const auto &e : c.employees) {
            QVariantMap empMap;
            empMap[QString::number(NameRole)] = e.name;
            empMap[QString::number(RoleRole)] = e.role;
            empMap[QString::number(IsCompanyRole)] = false;
            companyItem->appendChild(new TreeItem(empMap, companyItem));
        }
    }
}
