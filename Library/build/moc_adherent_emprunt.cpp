/****************************************************************************
** Meta object code from reading C++ file 'adherent_emprunt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.2.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../adherent_emprunt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'adherent_emprunt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.2.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Adherent_emprunt_t {
    QByteArrayData data[9];
    char stringdata[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_Adherent_emprunt_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_Adherent_emprunt_t qt_meta_stringdata_Adherent_emprunt = {
    {
QT_MOC_LITERAL(0, 0, 16),
QT_MOC_LITERAL(1, 17, 12),
QT_MOC_LITERAL(2, 30, 0),
QT_MOC_LITERAL(3, 31, 9),
QT_MOC_LITERAL(4, 41, 8),
QT_MOC_LITERAL(5, 50, 11),
QT_MOC_LITERAL(6, 62, 15),
QT_MOC_LITERAL(7, 78, 15),
QT_MOC_LITERAL(8, 94, 16)
    },
    "Adherent_emprunt\0get_adherent\0\0Adherent*\0"
    "adherent\0add_emprunt\0refresh_emprunt\0"
    "annuler_emprunt\0refresh_articles\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Adherent_emprunt[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   39,    2, 0x0a,
       5,    0,   42,    2, 0x0a,
       6,    0,   43,    2, 0x0a,
       7,    0,   44,    2, 0x0a,
       8,    0,   45,    2, 0x0a,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Adherent_emprunt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Adherent_emprunt *_t = static_cast<Adherent_emprunt *>(_o);
        switch (_id) {
        case 0: _t->get_adherent((*reinterpret_cast< Adherent*(*)>(_a[1]))); break;
        case 1: _t->add_emprunt(); break;
        case 2: _t->refresh_emprunt(); break;
        case 3: _t->annuler_emprunt(); break;
        case 4: _t->refresh_articles(); break;
        default: ;
        }
    }
}

const QMetaObject Adherent_emprunt::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_Adherent_emprunt.data,
      qt_meta_data_Adherent_emprunt,  qt_static_metacall, 0, 0}
};


const QMetaObject *Adherent_emprunt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Adherent_emprunt::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Adherent_emprunt.stringdata))
        return static_cast<void*>(const_cast< Adherent_emprunt*>(this));
    return QWidget::qt_metacast(_clname);
}

int Adherent_emprunt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
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
QT_END_MOC_NAMESPACE
