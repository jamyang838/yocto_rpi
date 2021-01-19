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
    QByteArrayData data[25];
    char stringdata0[318];
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
QT_MOC_LITERAL(7, 57, 15), // "change_keyboard"
QT_MOC_LITERAL(8, 73, 11), // "save_recipe"
QT_MOC_LITERAL(9, 85, 5), // "index"
QT_MOC_LITERAL(10, 91, 11), // "load_recipe"
QT_MOC_LITERAL(11, 103, 16), // "get_status_power"
QT_MOC_LITERAL(12, 120, 20), // "get_status_frequency"
QT_MOC_LITERAL(13, 141, 15), // "get_status_rate"
QT_MOC_LITERAL(14, 157, 16), // "get_status_range"
QT_MOC_LITERAL(15, 174, 13), // "get_quick_msg"
QT_MOC_LITERAL(16, 188, 21), // "insert_keyboard_value"
QT_MOC_LITERAL(17, 210, 5), // "value"
QT_MOC_LITERAL(18, 216, 20), // "clear_keyboard_value"
QT_MOC_LITERAL(19, 237, 21), // "delete_keyboard_value"
QT_MOC_LITERAL(20, 259, 12), // "get_kb_value"
QT_MOC_LITERAL(21, 272, 14), // "is_kb_in_range"
QT_MOC_LITERAL(22, 287, 12), // "get_kb_title"
QT_MOC_LITERAL(23, 300, 5), // "kb_ok"
QT_MOC_LITERAL(24, 306, 11) // "start_popup"

    },
    "rust\0status_signal\0\0enable_signal\0enb\0"
    "command_signal\0cmd\0change_keyboard\0"
    "save_recipe\0index\0load_recipe\0"
    "get_status_power\0get_status_frequency\0"
    "get_status_rate\0get_status_range\0"
    "get_quick_msg\0insert_keyboard_value\0"
    "value\0clear_keyboard_value\0"
    "delete_keyboard_value\0get_kb_value\0"
    "is_kb_in_range\0get_kb_title\0kb_ok\0"
    "start_popup"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_rust[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      19,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,  109,    2, 0x06 /* Public */,
       3,    1,  110,    2, 0x06 /* Public */,
       5,    1,  113,    2, 0x06 /* Public */,
       7,    0,  116,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       8,    1,  117,    2, 0x0a /* Public */,
      10,    1,  120,    2, 0x0a /* Public */,
      11,    0,  123,    2, 0x0a /* Public */,
      12,    0,  124,    2, 0x0a /* Public */,
      13,    0,  125,    2, 0x0a /* Public */,
      14,    0,  126,    2, 0x0a /* Public */,
      15,    1,  127,    2, 0x0a /* Public */,
      16,    1,  130,    2, 0x0a /* Public */,
      18,    0,  133,    2, 0x0a /* Public */,
      19,    0,  134,    2, 0x0a /* Public */,
      20,    0,  135,    2, 0x0a /* Public */,
      21,    0,  136,    2, 0x0a /* Public */,
      22,    0,  137,    2, 0x0a /* Public */,
      23,    0,  138,    2, 0x0a /* Public */,
      24,    1,  139,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void,
    QMetaType::Void, QMetaType::Bool,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,    9,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::Int,
    QMetaType::QString, QMetaType::Int,    9,
    QMetaType::Void, QMetaType::Int,   17,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Int,
    QMetaType::Bool,
    QMetaType::QString,
    QMetaType::Void,
    QMetaType::Void, QMetaType::Int,    9,

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
        case 3: _t->change_keyboard(); break;
        case 4: _t->save_recipe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 5: _t->load_recipe((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: { int _r = _t->get_status_power();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 7: { int _r = _t->get_status_frequency();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 8: { int _r = _t->get_status_rate();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 9: { int _r = _t->get_status_range();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 10: { QString _r = _t->get_quick_msg((*reinterpret_cast< int(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 11: _t->insert_keyboard_value((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 12: _t->clear_keyboard_value(); break;
        case 13: _t->delete_keyboard_value(); break;
        case 14: { int _r = _t->get_kb_value();
            if (_a[0]) *reinterpret_cast< int*>(_a[0]) = std::move(_r); }  break;
        case 15: { bool _r = _t->is_kb_in_range();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = std::move(_r); }  break;
        case 16: { QString _r = _t->get_kb_title();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 17: _t->kb_ok(); break;
        case 18: _t->start_popup((*reinterpret_cast< int(*)>(_a[1]))); break;
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
        {
            typedef void (rust::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&rust::change_keyboard)) {
                *result = 3;
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
        if (_id < 19)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 19;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 19)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 19;
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

// SIGNAL 3
void rust::change_keyboard()
{
    QMetaObject::activate(this, &staticMetaObject, 3, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
