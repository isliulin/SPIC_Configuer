/****************************************************************************
** Meta object code from reading C++ file 'other_editer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../other_editer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'other_editer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Other_Editer_t {
    QByteArrayData data[13];
    char stringdata0[193];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Other_Editer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Other_Editer_t qt_meta_stringdata_Other_Editer = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Other_Editer"
QT_MOC_LITERAL(1, 13, 12), // "Edit_Triggle"
QT_MOC_LITERAL(2, 26, 0), // ""
QT_MOC_LITERAL(3, 27, 11), // "EditPageNum"
QT_MOC_LITERAL(4, 39, 7), // "pageNum"
QT_MOC_LITERAL(5, 47, 34), // "On_Other_Table_DoubleClick_tr..."
QT_MOC_LITERAL(6, 82, 5), // "items"
QT_MOC_LITERAL(7, 88, 13), // "EditAttribute"
QT_MOC_LITERAL(8, 102, 9), // "attribute"
QT_MOC_LITERAL(9, 112, 12), // "databasePath"
QT_MOC_LITERAL(10, 125, 21), // "on_ConfirmBtn_clicked"
QT_MOC_LITERAL(11, 147, 20), // "on_CancelBtn_clicked"
QT_MOC_LITERAL(12, 168, 24) // "on_getPC_TimeBtn_clicked"

    },
    "Other_Editer\0Edit_Triggle\0\0EditPageNum\0"
    "pageNum\0On_Other_Table_DoubleClick_trigger\0"
    "items\0EditAttribute\0attribute\0"
    "databasePath\0on_ConfirmBtn_clicked\0"
    "on_CancelBtn_clicked\0on_getPC_TimeBtn_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Other_Editer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       5,    3,   42,    2, 0x08 /* Private */,
      10,    0,   49,    2, 0x08 /* Private */,
      11,    0,   50,    2, 0x08 /* Private */,
      12,    0,   51,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 7, QMetaType::QString,    6,    8,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Other_Editer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Other_Editer *_t = static_cast<Other_Editer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Edit_Triggle((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 1: _t->On_Other_Table_DoubleClick_trigger((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< EditAttribute(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 2: _t->on_ConfirmBtn_clicked(); break;
        case 3: _t->on_CancelBtn_clicked(); break;
        case 4: _t->on_getPC_TimeBtn_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Other_Editer::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Other_Editer::Edit_Triggle)) {
                *result = 0;
                return;
            }
        }
    }
}

const QMetaObject Other_Editer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_Other_Editer.data,
      qt_meta_data_Other_Editer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Other_Editer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Other_Editer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Other_Editer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int Other_Editer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void Other_Editer::Edit_Triggle(EditPageNum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
