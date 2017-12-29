/****************************************************************************
** Meta object code from reading C++ file 'subprojectnametable.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../subprojectnametable.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'subprojectnametable.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SubProjectNameTable_t {
    QByteArrayData data[18];
    char stringdata0[296];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SubProjectNameTable_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SubProjectNameTable_t qt_meta_stringdata_SubProjectNameTable = {
    {
QT_MOC_LITERAL(0, 0, 19), // "SubProjectNameTable"
QT_MOC_LITERAL(1, 20, 15), // "setAI_Edit_Info"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 18), // "SubProjectNameBean"
QT_MOC_LITERAL(4, 56, 4), // "bean"
QT_MOC_LITERAL(5, 61, 15), // "setDI_Edit_Info"
QT_MOC_LITERAL(6, 77, 15), // "setDO_Edit_Info"
QT_MOC_LITERAL(7, 93, 15), // "setSP_Edit_Info"
QT_MOC_LITERAL(8, 109, 11), // "EditPageNum"
QT_MOC_LITERAL(9, 121, 4), // "page"
QT_MOC_LITERAL(10, 126, 10), // "on_linkced"
QT_MOC_LITERAL(11, 137, 24), // "on_aiTableview_dbClicked"
QT_MOC_LITERAL(12, 162, 5), // "index"
QT_MOC_LITERAL(13, 168, 24), // "on_diTableview_dbClicked"
QT_MOC_LITERAL(14, 193, 24), // "on_doTableview_dbClicked"
QT_MOC_LITERAL(15, 218, 24), // "on_spTableview_dbClicked"
QT_MOC_LITERAL(16, 243, 27), // "on_manufTableview_dbClicked"
QT_MOC_LITERAL(17, 271, 24) // "on_confirmButton_clicked"

    },
    "SubProjectNameTable\0setAI_Edit_Info\0"
    "\0SubProjectNameBean\0bean\0setDI_Edit_Info\0"
    "setDO_Edit_Info\0setSP_Edit_Info\0"
    "EditPageNum\0page\0on_linkced\0"
    "on_aiTableview_dbClicked\0index\0"
    "on_diTableview_dbClicked\0"
    "on_doTableview_dbClicked\0"
    "on_spTableview_dbClicked\0"
    "on_manufTableview_dbClicked\0"
    "on_confirmButton_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SubProjectNameTable[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   69,    2, 0x06 /* Public */,
       5,    1,   72,    2, 0x06 /* Public */,
       6,    1,   75,    2, 0x06 /* Public */,
       7,    2,   78,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      10,    1,   83,    2, 0x0a /* Public */,
      11,    1,   86,    2, 0x0a /* Public */,
      13,    1,   89,    2, 0x0a /* Public */,
      14,    1,   92,    2, 0x0a /* Public */,
      15,    1,   95,    2, 0x0a /* Public */,
      16,    1,   98,    2, 0x0a /* Public */,
      17,    0,  101,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3, 0x80000000 | 8,    4,    9,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 8,    9,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void, QMetaType::QModelIndex,   12,
    QMetaType::Void,

       0        // eod
};

void SubProjectNameTable::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SubProjectNameTable *_t = static_cast<SubProjectNameTable *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->setAI_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1]))); break;
        case 1: _t->setDI_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1]))); break;
        case 2: _t->setDO_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1]))); break;
        case 3: _t->setSP_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1])),(*reinterpret_cast< EditPageNum(*)>(_a[2]))); break;
        case 4: _t->on_linkced((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 5: _t->on_aiTableview_dbClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 6: _t->on_diTableview_dbClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 7: _t->on_doTableview_dbClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 8: _t->on_spTableview_dbClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 9: _t->on_manufTableview_dbClicked((*reinterpret_cast< QModelIndex(*)>(_a[1]))); break;
        case 10: _t->on_confirmButton_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SubProjectNameTable::*_t)(SubProjectNameBean );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubProjectNameTable::setAI_Edit_Info)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SubProjectNameTable::*_t)(SubProjectNameBean );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubProjectNameTable::setDI_Edit_Info)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (SubProjectNameTable::*_t)(SubProjectNameBean );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubProjectNameTable::setDO_Edit_Info)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (SubProjectNameTable::*_t)(SubProjectNameBean , EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SubProjectNameTable::setSP_Edit_Info)) {
                *result = 3;
                return;
            }
        }
    }
}

const QMetaObject SubProjectNameTable::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SubProjectNameTable.data,
      qt_meta_data_SubProjectNameTable,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SubProjectNameTable::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SubProjectNameTable::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SubProjectNameTable.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SubProjectNameTable::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}

// SIGNAL 0
void SubProjectNameTable::setAI_Edit_Info(SubProjectNameBean _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SubProjectNameTable::setDI_Edit_Info(SubProjectNameBean _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void SubProjectNameTable::setDO_Edit_Info(SubProjectNameBean _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void SubProjectNameTable::setSP_Edit_Info(SubProjectNameBean _t1, EditPageNum _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
