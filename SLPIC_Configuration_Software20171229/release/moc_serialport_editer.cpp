/****************************************************************************
** Meta object code from reading C++ file 'serialport_editer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../serialport_editer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'serialport_editer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_SerialPort_Editer_t {
    QByteArrayData data[20];
    char stringdata0[283];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SerialPort_Editer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SerialPort_Editer_t qt_meta_stringdata_SerialPort_Editer = {
    {
QT_MOC_LITERAL(0, 0, 17), // "SerialPort_Editer"
QT_MOC_LITERAL(1, 18, 12), // "Edit_Triggle"
QT_MOC_LITERAL(2, 31, 0), // ""
QT_MOC_LITERAL(3, 32, 11), // "EditPageNum"
QT_MOC_LITERAL(4, 44, 7), // "pageNum"
QT_MOC_LITERAL(5, 52, 18), // "linkSubProjectName"
QT_MOC_LITERAL(6, 71, 39), // "On_SerialPort_Table_DoubleCli..."
QT_MOC_LITERAL(7, 111, 5), // "items"
QT_MOC_LITERAL(8, 117, 13), // "EditAttribute"
QT_MOC_LITERAL(9, 131, 9), // "attribute"
QT_MOC_LITERAL(10, 141, 12), // "databasePath"
QT_MOC_LITERAL(11, 154, 21), // "on_ConfirmBtn_clicked"
QT_MOC_LITERAL(12, 176, 20), // "on_CancelBtn_clicked"
QT_MOC_LITERAL(13, 197, 16), // "on_linkActivated"
QT_MOC_LITERAL(14, 214, 1), // "s"
QT_MOC_LITERAL(15, 216, 18), // "on_linkActivated_2"
QT_MOC_LITERAL(16, 235, 18), // "on_setSP_Edit_Info"
QT_MOC_LITERAL(17, 254, 18), // "SubProjectNameBean"
QT_MOC_LITERAL(18, 273, 4), // "bean"
QT_MOC_LITERAL(19, 278, 4) // "page"

    },
    "SerialPort_Editer\0Edit_Triggle\0\0"
    "EditPageNum\0pageNum\0linkSubProjectName\0"
    "On_SerialPort_Table_DoubleClick_trigger\0"
    "items\0EditAttribute\0attribute\0"
    "databasePath\0on_ConfirmBtn_clicked\0"
    "on_CancelBtn_clicked\0on_linkActivated\0"
    "s\0on_linkActivated_2\0on_setSP_Edit_Info\0"
    "SubProjectNameBean\0bean\0page"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SerialPort_Editer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   54,    2, 0x06 /* Public */,
       5,    1,   57,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    3,   60,    2, 0x08 /* Private */,
      11,    0,   67,    2, 0x08 /* Private */,
      12,    0,   68,    2, 0x08 /* Private */,
      13,    1,   69,    2, 0x08 /* Private */,
      15,    1,   72,    2, 0x08 /* Private */,
      16,    2,   75,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 8, QMetaType::QString,    7,    9,   10,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, QMetaType::QString,   14,
    QMetaType::Void, 0x80000000 | 17, 0x80000000 | 3,   18,   19,

       0        // eod
};

void SerialPort_Editer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SerialPort_Editer *_t = static_cast<SerialPort_Editer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Edit_Triggle((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 1: _t->linkSubProjectName((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 2: _t->On_SerialPort_Table_DoubleClick_trigger((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< EditAttribute(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        case 3: _t->on_ConfirmBtn_clicked(); break;
        case 4: _t->on_CancelBtn_clicked(); break;
        case 5: _t->on_linkActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 6: _t->on_linkActivated_2((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 7: _t->on_setSP_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1])),(*reinterpret_cast< EditPageNum(*)>(_a[2]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (SerialPort_Editer::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort_Editer::Edit_Triggle)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (SerialPort_Editer::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&SerialPort_Editer::linkSubProjectName)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject SerialPort_Editer::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_SerialPort_Editer.data,
      qt_meta_data_SerialPort_Editer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *SerialPort_Editer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SerialPort_Editer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_SerialPort_Editer.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int SerialPort_Editer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 8)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 8;
    }
    return _id;
}

// SIGNAL 0
void SerialPort_Editer::Edit_Triggle(EditPageNum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void SerialPort_Editer::linkSubProjectName(EditPageNum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
