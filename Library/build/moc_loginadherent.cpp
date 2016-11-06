/****************************************************************************
** Meta object code from reading C++ file 'loginadherent.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../loginadherent.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'loginadherent.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_loginAdherent_t {
    QByteArrayData data[9];
    char stringdata[119];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_loginAdherent_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_loginAdherent_t qt_meta_stringdata_loginAdherent = {
    {
QT_MOC_LITERAL(0, 0, 13),
QT_MOC_LITERAL(1, 14, 13),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 9),
QT_MOC_LITERAL(4, 39, 8),
QT_MOC_LITERAL(5, 48, 19),
QT_MOC_LITERAL(6, 68, 17),
QT_MOC_LITERAL(7, 86, 17),
QT_MOC_LITERAL(8, 104, 13)
    },
    "loginAdherent\0send_adherent\0\0Adherent*\0"
    "adherent\0inscriptionAdherent\0"
    "connexionAdherent\0clear_inscription\0"
    "clear_connect\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_loginAdherent[] = {

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
       1,    1,   39,    2, 0x06,

 // slots: name, argc, parameters, tag, flags
       5,    0,   42,    2, 0x0a,
       6,    0,   43,    2, 0x0a,
       7,    0,   44,    2, 0x0a,
       8,    0,   45,    2, 0x0a,

 // signals: parameters
    QMetaType::Void, 0x80000000 | 3,    4,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void loginAdherent::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        loginAdherent *_t = static_cast<loginAdherent *>(_o);
        switch (_id) {
        case 0: _t->send_adherent((*reinterpret_cast< Adherent*(*)>(_a[1]))); break;
        case 1: _t->inscriptionAdherent(); break;
        case 2: _t->connexionAdherent(); break;
        case 3: _t->clear_inscription(); break;
        case 4: _t->clear_connect(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef void (loginAdherent::*_t)(Adherent * );
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&loginAdherent::send_adherent)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject loginAdherent::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_loginAdherent.data,
      qt_meta_data_loginAdherent,  qt_static_metacall, 0, 0}
};


const QMetaObject *loginAdherent::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *loginAdherent::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_loginAdherent.stringdata))
        return static_cast<void*>(const_cast< loginAdherent*>(this));
    return QWidget::qt_metacast(_clname);
}

int loginAdherent::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
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
void loginAdherent::send_adherent(Adherent * _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
