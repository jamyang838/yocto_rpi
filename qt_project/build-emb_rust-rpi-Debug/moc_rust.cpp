/****************************************************************************
** Meta object code from reading C++ file 'rust.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../emb_rust/rust.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'rust.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_rust_t {
    QByteArrayData data[14];
    char stringdata0[158];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_rust_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_rust_t qt_meta_stringdata_rust = {
    {
QT_MOC_LITERAL(0, 0, 4), // "rust"
QT_MOC_LITERAL(1, 5, 13), // "status_signal"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 13), // "enable_signal"
QT_MOC_LITERAL(4, 34, 3), // "enb"
QT_MOC_LITERAL(5, 38, 14), // "command_signal"
QT_MOC_LITERAL(6, 53, 3), // "cmd"
QT_MOC_LITERAL(7, 57, 11), // "save_recipe"
QT_MOC_LITERAL(8, 69, 5), // "index"
QT_MOC_LITERAL(9, 75, 11), // "load_recipe"
QT_MOC_LITERAL(10, 87, 16), // "get_status_power"
QT_MOC_LITERAL(11, 104, 20), // "get_status_frequency"
QT_MOC_LITERAL(12, 125, 15), // "get_status_rate"
QT_MOC_LITERAL(13, 141, 16) // "get_status_range"

    },
    "rust\0status_signal\0\0enable_signal\0enb\0"
    "command_signal\0cmd\0save_recipe\0index\0"
    "load_recipe\0get_status_power\0"
    "get_status_frequency\0get_status_rate\0"
    "get_status_range"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rust[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       3,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x06 /* Public */,
       3,    1,   60,    2, 0x06 /* Public */,
       5,    1,   63,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       7,    1,   66,    2, 0x0a /* Public */,
       9,    1,   69,    2, 0x0a /* Public */,
      10,    0,   72,    2, 0x0a /* Public */,
      11,    0,   73,    2, 0x0a /* Public */,
      12,    0,   74,    2, 0x0a /* Public */,
      13,    0,   75,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Void, QMetaType::Int,    8,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,

       0        // eod
};

void rust::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        rust *_t = static_cast<rust *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->status_signal(); break;
        case 1: _t->enable_signal((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 2: _t->command_signal((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->save_recipe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->load_recipe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: { int _r = _t->get_status_power();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 6: { int _r = _t->get_status_frequency();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->get_status_rate();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->get_status_range();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (rust::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rust::status_signal)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (rust::*_t)(bool );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rust::enable_signal)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (rust::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rust::command_signal)) {
                *result = 2;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject rust::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_rust.data,
      qt_meta_data_rust,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *rust::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *rust::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_rust.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int rust::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void rust::status_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 0, nullptr);
}

// SIGNAL 1
void rust::enable_signal(bool _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void rust::command_signal(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
