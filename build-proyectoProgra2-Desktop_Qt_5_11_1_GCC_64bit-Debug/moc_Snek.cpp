/****************************************************************************
** Meta object code from reading C++ file 'Snek.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.11.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../src/Snek.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'Snek.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.11.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Snek_t {
    QByteArrayData data[8];
    char stringdata0[75];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Snek_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Snek_t qt_meta_stringdata_Snek = {
    {
QT_MOC_LITERAL(0, 0, 4), // "Snek"
QT_MOC_LITERAL(1, 5, 14), // "detectMovement"
QT_MOC_LITERAL(2, 20, 0), // ""
QT_MOC_LITERAL(3, 21, 10), // "setToRight"
QT_MOC_LITERAL(4, 32, 9), // "setToLeft"
QT_MOC_LITERAL(5, 42, 13), // "setToLeftStop"
QT_MOC_LITERAL(6, 56, 14), // "setToRightStop"
QT_MOC_LITERAL(7, 71, 3) // "pos"

    },
    "Snek\0detectMovement\0\0setToRight\0"
    "setToLeft\0setToLeftStop\0setToRightStop\0"
    "pos"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Snek[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       1,   44, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   39,    2, 0x09 /* Protected */,
       3,    0,   40,    2, 0x09 /* Protected */,
       4,    0,   41,    2, 0x09 /* Protected */,
       5,    0,   42,    2, 0x09 /* Protected */,
       6,    0,   43,    2, 0x09 /* Protected */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

 // properties: name, type, flags
       7, QMetaType::QPointF, 0x00095103,

       0        // eod
};

void Snek::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Snek *_t = static_cast<Snek *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->detectMovement(); break;
        case 1: _t->setToRight(); break;
        case 2: _t->setToLeft(); break;
        case 3: _t->setToLeftStop(); break;
        case 4: _t->setToRightStop(); break;
        default: ;
        }
    }
#ifndef QT_NO_PROPERTIES
    else if (_c == QMetaObject::ReadProperty) {
        Snek *_t = static_cast<Snek *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: *reinterpret_cast< QPointF*>(_v) = _t->pos(); break;
        default: break;
        }
    } else if (_c == QMetaObject::WriteProperty) {
        Snek *_t = static_cast<Snek *>(_o);
        Q_UNUSED(_t)
        void *_v = _a[0];
        switch (_id) {
        case 0: _t->setPos(*reinterpret_cast< QPointF*>(_v)); break;
        default: break;
        }
    } else if (_c == QMetaObject::ResetProperty) {
    }
#endif // QT_NO_PROPERTIES
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject Snek::staticMetaObject = {
    { &AnimatedObject::staticMetaObject, qt_meta_stringdata_Snek.data,
      qt_meta_data_Snek,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Snek::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Snek::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Snek.stringdata0))
        return static_cast<void*>(this);
    return AnimatedObject::qt_metacast(_clname);
}

int Snek::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = AnimatedObject::qt_metacall(_c, _id, _a);
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
#ifndef QT_NO_PROPERTIES
   else if (_c == QMetaObject::ReadProperty || _c == QMetaObject::WriteProperty
            || _c == QMetaObject::ResetProperty || _c == QMetaObject::RegisterPropertyMetaType) {
        qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyDesignable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyScriptable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyStored) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyEditable) {
        _id -= 1;
    } else if (_c == QMetaObject::QueryPropertyUser) {
        _id -= 1;
    }
#endif // QT_NO_PROPERTIES
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
