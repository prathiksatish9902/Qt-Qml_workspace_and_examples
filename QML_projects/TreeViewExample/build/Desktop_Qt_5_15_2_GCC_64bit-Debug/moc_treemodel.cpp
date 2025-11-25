/****************************************************************************
** Meta object code from reading C++ file 'treemodel.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../treemodel.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'treemodel.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TreeModel_t {
    QByteArrayData data[40];
    char stringdata0[449];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TreeModel_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TreeModel_t qt_meta_stringdata_TreeModel = {
    {
QT_MOC_LITERAL(0, 0, 9), // "TreeModel"
QT_MOC_LITERAL(1, 10, 14), // "getCompanyData"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 3), // "row"
QT_MOC_LITERAL(4, 30, 21), // "getCompanyDataByIndex"
QT_MOC_LITERAL(5, 52, 11), // "QModelIndex"
QT_MOC_LITERAL(6, 64, 5), // "index"
QT_MOC_LITERAL(7, 70, 18), // "updateCompanyField"
QT_MOC_LITERAL(8, 89, 6), // "column"
QT_MOC_LITERAL(9, 96, 5), // "value"
QT_MOC_LITERAL(10, 102, 10), // "addCompany"
QT_MOC_LITERAL(11, 113, 4), // "name"
QT_MOC_LITERAL(12, 118, 2), // "id"
QT_MOC_LITERAL(13, 121, 4), // "year"
QT_MOC_LITERAL(14, 126, 8), // "location"
QT_MOC_LITERAL(15, 135, 8), // "industry"
QT_MOC_LITERAL(16, 144, 3), // "ceo"
QT_MOC_LITERAL(17, 148, 16), // "addEmptyTemplate"
QT_MOC_LITERAL(18, 165, 13), // "deleteCompany"
QT_MOC_LITERAL(19, 179, 11), // "addSubLevel"
QT_MOC_LITERAL(20, 191, 10), // "companyRow"
QT_MOC_LITERAL(21, 202, 8), // "subLevel"
QT_MOC_LITERAL(22, 211, 15), // "selectedCompany"
QT_MOC_LITERAL(23, 227, 19), // "addChildForSelected"
QT_MOC_LITERAL(24, 247, 18), // "addSub1ForSelected"
QT_MOC_LITERAL(25, 266, 18), // "addSub2ForSelected"
QT_MOC_LITERAL(26, 285, 18), // "addSub3ForSelected"
QT_MOC_LITERAL(27, 304, 11), // "CustomRoles"
QT_MOC_LITERAL(28, 316, 13), // "CompanyIdRole"
QT_MOC_LITERAL(29, 330, 9), // "ImageRole"
QT_MOC_LITERAL(30, 340, 13), // "IsCompanyRole"
QT_MOC_LITERAL(31, 354, 8), // "NameRole"
QT_MOC_LITERAL(32, 363, 8), // "YearRole"
QT_MOC_LITERAL(33, 372, 8), // "RoleRole"
QT_MOC_LITERAL(34, 381, 9), // "EmailRole"
QT_MOC_LITERAL(35, 391, 12), // "LocationRole"
QT_MOC_LITERAL(36, 404, 12), // "IndustryRole"
QT_MOC_LITERAL(37, 417, 7), // "CeoRole"
QT_MOC_LITERAL(38, 425, 12), // "selectedRole"
QT_MOC_LITERAL(39, 438, 10) // "StatusRole"

    },
    "TreeModel\0getCompanyData\0\0row\0"
    "getCompanyDataByIndex\0QModelIndex\0"
    "index\0updateCompanyField\0column\0value\0"
    "addCompany\0name\0id\0year\0location\0"
    "industry\0ceo\0addEmptyTemplate\0"
    "deleteCompany\0addSubLevel\0companyRow\0"
    "subLevel\0selectedCompany\0addChildForSelected\0"
    "addSub1ForSelected\0addSub2ForSelected\0"
    "addSub3ForSelected\0CustomRoles\0"
    "CompanyIdRole\0ImageRole\0IsCompanyRole\0"
    "NameRole\0YearRole\0RoleRole\0EmailRole\0"
    "LocationRole\0IndustryRole\0CeoRole\0"
    "selectedRole\0StatusRole"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TreeModel[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       1,  114, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // methods: name, argc, parameters, tag, flags
       1,    1,   74,    2, 0x02 /* Public */,
       4,    1,   77,    2, 0x02 /* Public */,
       7,    3,   80,    2, 0x02 /* Public */,
      10,    6,   87,    2, 0x02 /* Public */,
      17,    0,  100,    2, 0x02 /* Public */,
      18,    0,  101,    2, 0x02 /* Public */,
      19,    2,  102,    2, 0x02 /* Public */,
      22,    1,  107,    2, 0x02 /* Public */,
      23,    0,  110,    2, 0x02 /* Public */,
      24,    0,  111,    2, 0x02 /* Public */,
      25,    0,  112,    2, 0x02 /* Public */,
      26,    0,  113,    2, 0x02 /* Public */,

 // methods: parameters
    QMetaType::QVariantMap, QMetaType::Int,    3,
    QMetaType::QVariantMap, 0x80000000 | 5,    6,
    QMetaType::Bool, 0x80000000 | 5, QMetaType::Int, QMetaType::QString,    6,    8,    9,
    QMetaType::Void, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString, QMetaType::QString,   11,   12,   13,   14,   15,   16,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int, QMetaType::Int,   20,   21,
    QMetaType::Bool, QMetaType::Int,   20,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // enums: name, alias, flags, count, data
      27,   27, 0x0,   12,  119,

 // enum data: key, value
      28, uint(TreeModel::CompanyIdRole),
      29, uint(TreeModel::ImageRole),
      30, uint(TreeModel::IsCompanyRole),
      31, uint(TreeModel::NameRole),
      32, uint(TreeModel::YearRole),
      33, uint(TreeModel::RoleRole),
      34, uint(TreeModel::EmailRole),
      35, uint(TreeModel::LocationRole),
      36, uint(TreeModel::IndustryRole),
      37, uint(TreeModel::CeoRole),
      38, uint(TreeModel::selectedRole),
      39, uint(TreeModel::StatusRole),

       0        // eod
};

void TreeModel::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<TreeModel *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: { QVariantMap _r = _t->getCompanyData((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 1: { QVariantMap _r = _t->getCompanyDataByIndex((*reinterpret_cast< const QModelIndex(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QVariantMap*>(_a[0]) = std::move(_r); }  break;
        case 2: { bool _r = _t->updateCompanyField((*reinterpret_cast< const QModelIndex(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 3: _t->addCompany((*reinterpret_cast< const QString(*)>(_a[1])),(*reinterpret_cast< const QString(*)>(_a[2])),(*reinterpret_cast< const QString(*)>(_a[3])),(*reinterpret_cast< const QString(*)>(_a[4])),(*reinterpret_cast< const QString(*)>(_a[5])),(*reinterpret_cast< const QString(*)>(_a[6]))); break;
        case 4: _t->addEmptyTemplate(); break;
        case 5: _t->deleteCompany(); break;
        case 6: _t->addSubLevel((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 7: { bool _r = _t->selectedCompany((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 8: _t->addChildForSelected(); break;
        case 9: _t->addSub1ForSelected(); break;
        case 10: _t->addSub2ForSelected(); break;
        case 11: _t->addSub3ForSelected(); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject TreeModel::staticMetaObject = { {
    QMetaObject::SuperData::link<QAbstractItemModel::staticMetaObject>(),
    qt_meta_stringdata_TreeModel.data,
    qt_meta_data_TreeModel,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *TreeModel::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TreeModel::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TreeModel.stringdata0))
        return static_cast<void*>(this);
    return QAbstractItemModel::qt_metacast(_clname);
}

int TreeModel::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QAbstractItemModel::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
