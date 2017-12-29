/****************************************************************************
** Meta object code from reading C++ file 'ai_edit.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../ai_edit.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'ai_edit.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_AI_Edit_t {
    QByteArrayData data[18];
    char stringdata0[241];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_AI_Edit_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_AI_Edit_t qt_meta_stringdata_AI_Edit = {
    {
QT_MOC_LITERAL(0, 0, 7), // "AI_Edit"
QT_MOC_LITERAL(1, 8, 12), // "Edit_Triggle"
QT_MOC_LITERAL(2, 21, 0), // ""
QT_MOC_LITERAL(3, 22, 11), // "EditPageNum"
QT_MOC_LITERAL(4, 34, 7), // "pageNum"
QT_MOC_LITERAL(5, 42, 18), // "linkSubProjectName"
QT_MOC_LITERAL(6, 61, 21), // "on_ConfirmBtn_clicked"
QT_MOC_LITERAL(7, 83, 16), // "on_linkActivated"
QT_MOC_LITERAL(8, 100, 1), // "s"
QT_MOC_LITERAL(9, 102, 20), // "on_CancelBtn_clicked"
QT_MOC_LITERAL(10, 123, 18), // "on_setAI_Edit_Info"
QT_MOC_LITERAL(11, 142, 18), // "SubProjectNameBean"
QT_MOC_LITERAL(12, 161, 4), // "bean"
QT_MOC_LITERAL(13, 166, 31), // "On_AI_Table_DoubleClick_trigger"
QT_MOC_LITERAL(14, 198, 5), // "items"
QT_MOC_LITERAL(15, 204, 13), // "EditAttribute"
QT_MOC_LITERAL(16, 218, 9), // "attribute"
QT_MOC_LITERAL(17, 228, 12) // "databasePath"

    },
    "AI_Edit\0Edit_Triggle\0\0EditPageNum\0"
    "pageNum\0linkSubProjectName\0"
    "on_ConfirmBtn_clicked\0on_linkActivated\0"
    "s\0on_CancelBtn_clicked\0on_setAI_Edit_Info\0"
    "SubProjectNameBean\0bean\0"
    "On_AI_Table_DoubleClick_trigger\0items\0"
    "EditAttribute\0attribute\0databasePath"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_AI_Edit[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       7,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,   49,    2, 0x06 /* Public */,
       5,    1,   52,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       6,    0,   55,    2, 0x08 /* Private */,
       7,    1,   56,    2, 0x08 /* Private */,
       9,    0,   59,    2, 0x08 /* Private */,
      10,    1,   60,    2, 0x08 /* Private */,
      13,    3,   63,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 11,   12,
    QMetaType::Void, QMetaType::QStringList, 0x80000000 | 15, QMetaType::QString,   14,   16,   17,

       0        // eod
};

void AI_Edit::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        AI_Edit *_t = static_cast<AI_Edit *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->Edit_Triggle((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 1: _t->linkSubProjectName((*reinterpret_cast< EditPageNum(*)>(_a[1]))); break;
        case 2: _t->on_ConfirmBtn_clicked(); break;
        case 3: _t->on_linkActivated((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 4: _t->on_CancelBtn_clicked(); break;
        case 5: _t->on_setAI_Edit_Info((*reinterpret_cast< SubProjectNameBean(*)>(_a[1]))); break;
        case 6: _t->On_AI_Table_DoubleClick_trigger((*reinterpret_cast< QStringList(*)>(_a[1])),(*reinterpret_cast< EditAttribute(*)>(_a[2])),(*reinterpret_cast< QString(*)>(_a[3]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (AI_Edit::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AI_Edit::Edit_Triggle)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (AI_Edit::*_t)(EditPageNum );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&AI_Edit::linkSubProjectName)) {
                *result = 1;
                return;
            }
        }
    }
}

const QMetaObject AI_Edit::staticMetaObject = {
    { &QDialog::staticMetaObject, qt_meta_stringdata_AI_Edit.data,
      qt_meta_data_AI_Edit,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *AI_Edit::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *AI_Edit::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_AI_Edit.stringdata0))
        return static_cast<void*>(this);
    return QDialog::qt_metacast(_clname);
}

int AI_Edit::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QDialog::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 7)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 7;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 7)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 7;
    }
    return _id;
}

// SIGNAL 0
void AI_Edit::Edit_Triggle(EditPageNum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void AI_Edit::linkSubProjectName(EditPageNum _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
