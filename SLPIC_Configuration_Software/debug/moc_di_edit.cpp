/****************************************************************************
** Meta object code from reading C++ file 'di_edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.8.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../di_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'di_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.8.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_DI_Edit_t {
    QByteArrayData data[11];
    char stringdata0[139];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_DI_Edit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_DI_Edit_t qt_meta_stringdata_DI_Edit = {
    {
QT_MOC_LITERAL(0, 0, 7), // "DI_Edit"
QT_MOC_LITERAL(1, 8, 12), // "Edit_Triggle"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "EditPageNum"
QT_MOC_LITERAL(4, 34, 7), // "pageNum"
QT_MOC_LITERAL(5, 42, 21), // "on_ConfirmBtn_clicked"
QT_MOC_LITERAL(6, 64, 31), // "On_DI_Table_DoubleClick_trigger"
QT_MOC_LITERAL(7, 96, 5), // "items"
QT_MOC_LITERAL(8, 102, 13), // "EditAttribute"
QT_MOC_LITERAL(9, 116, 9), // "attribute"
QT_MOC_LITERAL(10, 126, 12) // "databasePath"

    },
    "DI_Edit\0Edit_Triggle\0\0EditPageNum\0"
    "pageNum\0on_ConfirmBtn_clicked\0"
    "On_DI_Table_DoubleClick_trigger\0items\0"
    "EditAttribute\0attribute\0databasePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_DI_Edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       3,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   29,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    0,   32,    2, 0x08 /* Private */,
       6,    3,   33,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 8, QMetaType::QString,    7,    9,   10,

       0        // eod
};

void DI_Edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        DI_Edit *_t = static_cast<DI_Edit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Edit_Triggle((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 1: _t->on_ConfirmBtn_clicked(); break;
        case 2: _t->On_DI_Table_DoubleClick_trigger((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< EditAttribute(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (DI_Edit::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&DI_Edit::Edit_Triggle)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject DI_Edit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_DI_Edit.data,
      qt_meta_data_DI_Edit,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *DI_Edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *DI_Edit::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_DI_Edit.stringdata0))
        return static_cast<void*>(const_cast< DI_Edit*>(this));
    return QDialog::qt_metacast(_clname);
}

int DI_Edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 3)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 3;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 3)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 3;
    }
    return _id;
}

// SIGNAL 0
void DI_Edit::Edit_Triggle(EditPageNum _t1)
{
    void *_a[] = { Q_NULLPTR, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
