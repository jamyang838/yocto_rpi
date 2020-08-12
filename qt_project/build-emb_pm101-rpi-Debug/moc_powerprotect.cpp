/****************************************************************************
** Meta object code from reading C++ file 'powerprotect.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.10.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../emb_pm101/powerprotect.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'powerprotect.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.10.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Powerprotect_t {
    QByteArrayData data[29];
    char stringdata0[401];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Powerprotect_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Powerprotect_t qt_meta_stringdata_Powerprotect = {
    {
QT_MOC_LITERAL(0, 0, 12), // "Powerprotect"
QT_MOC_LITERAL(1, 13, 20), // "power_displayChanged"
QT_MOC_LITERAL(2, 34, 0), // ""
QT_MOC_LITERAL(3, 35, 13), // "power_display"
QT_MOC_LITERAL(4, 49, 20), // "limit_displayChanged"
QT_MOC_LITERAL(5, 70, 13), // "limit_display"
QT_MOC_LITERAL(6, 84, 14), // "uplimitChanged"
QT_MOC_LITERAL(7, 99, 7), // "uplimit"
QT_MOC_LITERAL(8, 107, 15), // "lowlimitChanged"
QT_MOC_LITERAL(9, 123, 8), // "lowlimit"
QT_MOC_LITERAL(10, 132, 18), // "update_limitswitch"
QT_MOC_LITERAL(11, 151, 9), // "save_file"
QT_MOC_LITERAL(12, 161, 14), // "shutdown_relay"
QT_MOC_LITERAL(13, 176, 14), // "initial_signal"
QT_MOC_LITERAL(14, 191, 16), // "setPower_display"
QT_MOC_LITERAL(15, 208, 16), // "setLimit_display"
QT_MOC_LITERAL(16, 225, 10), // "setUplimit"
QT_MOC_LITERAL(17, 236, 11), // "setLowlimit"
QT_MOC_LITERAL(18, 248, 12), // "switch1_slot"
QT_MOC_LITERAL(19, 261, 3), // "val"
QT_MOC_LITERAL(20, 265, 12), // "input_number"
QT_MOC_LITERAL(21, 278, 3), // "str"
QT_MOC_LITERAL(22, 282, 11), // "input_click"
QT_MOC_LITERAL(23, 294, 21), // "set_is_set_upperlimit"
QT_MOC_LITERAL(24, 316, 17), // "switch_upperlimit"
QT_MOC_LITERAL(25, 334, 17), // "switch_lowerlimit"
QT_MOC_LITERAL(26, 352, 15), // "switch_savefile"
QT_MOC_LITERAL(27, 368, 12), // "get_rpi_desc"
QT_MOC_LITERAL(28, 381, 19) // "enter_advanced_mode"

    },
    "Powerprotect\0power_displayChanged\0\0"
    "power_display\0limit_displayChanged\0"
    "limit_display\0uplimitChanged\0uplimit\0"
    "lowlimitChanged\0lowlimit\0update_limitswitch\0"
    "save_file\0shutdown_relay\0initial_signal\0"
    "setPower_display\0setLimit_display\0"
    "setUplimit\0setLowlimit\0switch1_slot\0"
    "val\0input_number\0str\0input_click\0"
    "set_is_set_upperlimit\0switch_upperlimit\0"
    "switch_lowerlimit\0switch_savefile\0"
    "get_rpi_desc\0enter_advanced_mode"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Powerprotect[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      21,   14, // methods
       4,  172, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       8,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    1,  119,    2, 0x06 /* Public */,
       4,    1,  122,    2, 0x06 /* Public */,
       6,    1,  125,    2, 0x06 /* Public */,
       8,    1,  128,    2, 0x06 /* Public */,
      10,    0,  131,    2, 0x06 /* Public */,
      11,    0,  132,    2, 0x06 /* Public */,
      12,    0,  133,    2, 0x06 /* Public */,
      13,    0,  134,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
      14,    1,  135,    2, 0x0a /* Public */,
      15,    1,  138,    2, 0x0a /* Public */,
      16,    1,  141,    2, 0x0a /* Public */,
      17,    1,  144,    2, 0x0a /* Public */,
      18,    1,  147,    2, 0x0a /* Public */,
      20,    1,  150,    2, 0x0a /* Public */,
      22,    1,  153,    2, 0x0a /* Public */,
      23,    1,  156,    2, 0x0a /* Public */,
      24,    1,  159,    2, 0x0a /* Public */,
      25,    1,  162,    2, 0x0a /* Public */,
      26,    1,  165,    2, 0x0a /* Public */,
      27,    0,  168,    2, 0x0a /* Public */,
      28,    1,  169,    2, 0x0a /* Public */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // slots: parameters
    QMetaType::Void, QMetaType::QString,    3,
    QMetaType::Void, QMetaType::QString,    5,
    QMetaType::Void, QMetaType::Double,    7,
    QMetaType::Void, QMetaType::Double,    9,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::QString,   21,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::Void, QMetaType::Bool,   19,
    QMetaType::QString,
    QMetaType::Void, QMetaType::QString,   21,

 // properties: name, type, flags
       3, QMetaType::QString, 0x00495103,
       5, QMetaType::QString, 0x00495103,
       7, QMetaType::Double, 0x00495103,
       9, QMetaType::Double, 0x00495103,

 // properties: notify_signal_id
       0,
       1,
       2,
       3,

       0        // eod
};

void Powerprotect::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Powerprotect *_t = static_cast<Powerprotect *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->power_displayChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 1: _t->limit_displayChanged((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->uplimitChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 3: _t->lowlimitChanged((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 4: _t->update_limitswitch(); break;
        case 5: _t->save_file(); break;
        case 6: _t->shutdown_relay(); break;
        case 7: _t->initial_signal(); break;
        case 8: _t->setPower_display((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 9: _t->setLimit_display((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 10: _t->setUplimit((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 11: _t->setLowlimit((*reinterpret_cast< double(*)>(_a[1]))); break;
        case 12: _t->switch1_slot((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 13: _t->input_number((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 14: _t->input_click((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: _t->set_is_set_upperlimit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 16: _t->switch_upperlimit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 17: _t->switch_lowerlimit((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 18: _t->switch_savefile((*reinterpret_cast< bool(*)>(_a[1]))); break;
        case 19: { QString _r = _t->get_rpi_desc();
            if (_a[0]) *reinterpret_cast< QString*>(_a[0]) = std::move(_r); }  break;
        case 20: _t->enter_advanced_mode((*reinterpret_cast< QString(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            typedef void (Powerprotect::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::power_displayChanged)) {
                *result = 0;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)(QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::limit_displayChanged)) {
                *result = 1;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::uplimitChanged)) {
                *result = 2;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)(double );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::lowlimitChanged)) {
                *result = 3;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::update_limitswitch)) {
                *result = 4;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::save_file)) {
                *result = 5;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::shutdown_relay)) {
                *result = 6;
                return;
            }
        }
        {
            typedef void (Powerprotect::*_t)();
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Powerprotect::initial_signal)) {
                *result = 7;
                return;
            }
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Powerprotect *_t = static_cast<Powerprotect *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QString*>(_v) = _t->power_display(); break;
        case 1: *reinterpret_cast< QString*>(_v) = _t->limit_display(); break;
        case 2: *reinterpret_cast< double*>(_v) = _t->uplimit(); break;
        case 3: *reinterpret_cast< double*>(_v) = _t->lowlimit(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Powerprotect *_t = static_cast<Powerprotect *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPower_display(*reinterpret_cast< QString*>(_v)); break;
        case 1: _t->setLimit_display(*reinterpret_cast< QString*>(_v)); break;
        case 2: _t->setUplimit(*reinterpret_cast< double*>(_v)); break;
        case 3: _t->setLowlimit(*reinterpret_cast< double*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
}

QT_INIT_METAOBJECT const QMetaObject Powerprotect::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Powerprotect.data,
      qt_meta_data_Powerprotect,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Powerprotect::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Powerprotect::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Powerprotect.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int Powerprotect::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 21)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 21;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 21)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 21;
    }
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 4;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 4;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}

// SIGNAL 0
void Powerprotect::power_displayChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void Powerprotect::limit_displayChanged(QString _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void Powerprotect::uplimitChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void Powerprotect::lowlimitChanged(double _t1)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}

// SIGNAL 4
void Powerprotect::update_limitswitch()
{
    QMetaObject::activate(this, &staticMetaObject, 4, nullptr);
}

// SIGNAL 5
void Powerprotect::save_file()
{
    QMetaObject::activate(this, &staticMetaObject, 5, nullptr);
}

// SIGNAL 6
void Powerprotect::shutdown_relay()
{
    QMetaObject::activate(this, &staticMetaObject, 6, nullptr);
}

// SIGNAL 7
void Powerprotect::initial_signal()
{
    QMetaObject::activate(this, &staticMetaObject, 7, nullptr);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
