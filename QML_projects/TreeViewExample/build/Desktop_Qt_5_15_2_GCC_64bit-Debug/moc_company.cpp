/****************************************************************************
** Meta object code from reading C++ file 'company.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../company.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#include <QtCore/QList>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'company.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Company_t {
    QByteArrayData data[31];
    char stringdata0[301];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Company_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Company_t qt_meta_stringdata_Company = {
    {
QT_MOC_LITERAL(0, 0, 7), // "Company"
QT_MOC_LITERAL(1, 8, 9), // "idChanged"
QT_MOC_LITERAL(2, 18, 0), // ""
QT_MOC_LITERAL(3, 19, 11), // "nameChanged"
QT_MOC_LITERAL(4, 31, 11), // "yearChanged"
QT_MOC_LITERAL(5, 43, 12), // "imageChanged"
QT_MOC_LITERAL(6, 56, 15), // "locationChanged"
QT_MOC_LITERAL(7, 72, 15), // "industryChanged"
QT_MOC_LITERAL(8, 88, 10), // "ceoChanged"
QT_MOC_LITERAL(9, 99, 13), // "statusChanged"
QT_MOC_LITERAL(10, 113, 16), // "employeesChanged"
QT_MOC_LITERAL(11, 130, 15), // "selectedChanged"
QT_MOC_LITERAL(12, 146, 5), // "setId"
QT_MOC_LITERAL(13, 152, 2), // "id"
QT_MOC_LITERAL(14, 155, 7), // "setName"
QT_MOC_LITERAL(15, 163, 4), // "name"
QT_MOC_LITERAL(16, 168, 7), // "setYear"
QT_MOC_LITERAL(17, 176, 4), // "year"
QT_MOC_LITERAL(18, 181, 8), // "setImage"
QT_MOC_LITERAL(19, 190, 5), // "image"
QT_MOC_LITERAL(20, 196, 11), // "setLocation"
QT_MOC_LITERAL(21, 208, 8), // "location"
QT_MOC_LITERAL(22, 217, 11), // "setIndustry"
QT_MOC_LITERAL(23, 229, 8), // "industry"
QT_MOC_LITERAL(24, 238, 6), // "setCeo"
QT_MOC_LITERAL(25, 245, 3), // "ceo"
QT_MOC_LITERAL(26, 249, 9), // "setStatus"
QT_MOC_LITERAL(27, 259, 6), // "status"
QT_MOC_LITERAL(28, 266, 9), // "employees"
QT_MOC_LITERAL(29, 276, 15), // "QList<QObject*>"
QT_MOC_LITERAL(30, 292, 8) // "selected"

    },
    "Company\0idChanged\0\0nameChanged\0"
    "yearChanged\0imageChanged\0locationChanged\0"
    "industryChanged\0ceoChanged\0statusChanged\0"
    "employeesChanged\0selectedChanged\0setId\0"
    "id\0setName\0name\0setYear\0year\0setImage\0"
    "image\0setLocation\0location\0setIndustry\0"
    "industry\0setCeo\0ceo\0setStatus\0status\0"
    "employees\0QList<QObject*>\0selected"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Company[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      18,   14, // methods
      10,  138, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
      10,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  104,    2, 0x06 /* Public */,
       3,    0,  105,    2, 0x06 /* Public */,
       4,    0,  106,    2, 0x06 /* Public */,
       5,    0,  107,    2, 0x06 /* Public */,
       6,    0,  108,    2, 0x06 /* Public */,
       7,    0,  109,    2, 0x06 /* Public */,
       8,    0,  110,    2, 0x06 /* Public */,
       9,    0,  111,    2, 0x06 /* Public */,
      10,    0,  112,    2, 0x06 /* Public */,
      11,    0,  113,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      12,    1,  114,    2, 0x0a /* Public */,
      14,    1,  117,    2, 0x0a /* Public */,
      16,    1,  120,    2, 0x0a /* Public */,
      18,    1,  123,    2, 0x0a /* Public */,
      20,    1,  126,    2, 0x0a /* Public */,
      22,    1,  129,    2, 0x0a /* Public */,
      24,    1,  132,    2, 0x0a /* Public */,
      26,    1,  135,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,   13,
    QMetaType::Void, QMetaType::QString,   15,
    QMetaType::Void, QMetaType::QString,   17,
    QMetaType::Void, QMetaType::QString,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   23,
    QMetaType::Void, QMetaType::QString,   25,
    QMetaType::Void, QMetaType::QString,   27,

 // properties: name, type, flags
      13, QMetaType::QString, 0x00495103,
      15, QMetaType::QString, 0x00495103,
      17, QMetaType::QString, 0x00495103,
      19, QMetaType::QString, 0x00495103,
      21, QMetaType::QString, 0x00495103,
      23, QMetaType::QString, 0x00495103,
      25, QMetaType::QString, 0x00495103,
      27, QMetaType::QString, 0x00495103,
      28, 0x80000000 | 29, 0x00495009,
      30, QMetaType::Bool, 0x00495903,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,
       4,
       5,
       6,
       7,
       8,
       9,

       0        // eod
};

void Company::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Company *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->idChanged(); break;
        case 1: _t->nameChanged(); break;
        case 2: _t->yearChanged(); break;
        case 3: _t->imageChanged(); break;
        case 4: _t->locationChanged(); break;
        case 5: _t->industryChanged(); break;
        case 6: _t->ceoChanged(); break;
        case 7: _t->statusChanged(); break;
        case 8: _t->employeesChanged(); break;
        case 9: _t->selectedChanged(); break;
        case 10: _t->setId((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 11: _t->setName((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 12: _t->setYear((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 13: _t->setImage((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 14: _t->setLocation((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 15: _t->setIndustry((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 16: _t->setCeo((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 17: _t->setStatus((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::idChanged)) {
                *result = 0;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::nameChanged)) {
                *result = 1;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::yearChanged)) {
                *result = 2;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::imageChanged)) {
                *result = 3;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::locationChanged)) {
                *result = 4;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::industryChanged)) {
                *result = 5;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::ceoChanged)) {
                *result = 6;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::statusChanged)) {
                *result = 7;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::employeesChanged)) {
                *result = 8;
                return;
            }
        }
        {
            using _t = void (Company::*)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Company::selectedChanged)) {
                *result = 9;
                return;
            }
        }
    } else if (_c == QMetaObject::RegisterPropertyMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 8:
            *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< QList<QObject*> >(); break;
        }
    }

#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        auto *_t = static_cast<Company *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->id(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->name(); break;
        case 2: *reinterpret_cast< QString*>(_v) = _t->year(); break;
        case 3: *reinterpret_cast< QString*>(_v) = _t->image(); break;
        case 4: *reinterpret_cast< QString*>(_v) = _t->location(); break;
        case 5: *reinterpret_cast< QString*>(_v) = _t->industry(); break;
        case 6: *reinterpret_cast< QString*>(_v) = _t->ceo(); break;
        case 7: *reinterpret_cast< QString*>(_v) = _t->status(); break;
        case 8: *reinterpret_cast< QList<QObject*>*>(_v) = _t->employeesAsQObjectList(); break;
        case 9: *reinterpret_cast< bool*>(_v) = _t->selected(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        auto *_t = static_cast<Company *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setId(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setName(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setYear(*reinterpret_cast< QString*>(_v)); break;
        case 3: _t->setImage(*reinterpret_cast< QString*>(_v)); break;
        case 4: _t->setLocation(*reinterpret_cast< QString*>(_v)); break;
        case 5: _t->setIndustry(*reinterpret_cast< QString*>(_v)); break;
        case 6: _t->setCeo(*reinterpret_cast< QString*>(_v)); break;
        case 7: _t->setStatus(*reinterpret_cast< QString*>(_v)); break;
        case 9: _t->setSelected(*reinterpret_cast< bool*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Company::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_Company.data,
    qt_meta_data_Company,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Company::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Company::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Company.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Company::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 18)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 18;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 18)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 18;
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 10;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 10;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Company::idChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void Company::nameChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 1, nullptr);
}

// SIGNAL 2
void Company::yearChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 2, nullptr);
}

// SIGNAL 3
void Company::imageChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}

// SIGNAL 4
void Company::locationChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Company::industryChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Company::ceoChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Company::statusChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}

// SIGNAL 8
void Company::employeesChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 8, nullptr);
}

// SIGNAL 9
void Company::selectedChanged()
{
    QMetaObject::activate(this, &staticMetaObject, 9, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
