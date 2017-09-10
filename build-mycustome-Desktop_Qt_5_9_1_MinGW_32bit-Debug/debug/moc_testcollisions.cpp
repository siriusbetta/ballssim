/****************************************************************************
** Meta object code from reading C++ file 'testcollisions.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mycustome/testcollisions.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testcollisions.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Testcollisions_t {
    QByteArrayData data[12];
    char stringdata0[287];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Testcollisions_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Testcollisions_t qt_meta_stringdata_Testcollisions = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Testcollisions"
QT_MOC_LITERAL(1, 15, 21), // "compareTwoCoordinates"
QT_MOC_LITERAL(2, 37, 0), // ""
QT_MOC_LITERAL(3, 38, 26), // "compareTwoCoordinates_data"
QT_MOC_LITERAL(4, 65, 25), // "testChechLengthToTheWalls"
QT_MOC_LITERAL(5, 91, 30), // "testChechLengthToTheWalls_data"
QT_MOC_LITERAL(6, 122, 28), // "testIsPlaceCompareOtherBalls"
QT_MOC_LITERAL(7, 151, 33), // "testIsPlaceCompareOtherBalls_..."
QT_MOC_LITERAL(8, 185, 16), // "testIsAvaiblePos"
QT_MOC_LITERAL(9, 202, 21), // "testIsAvaiblePos_data"
QT_MOC_LITERAL(10, 224, 28), // "testIsCoordinateLayInTheBall"
QT_MOC_LITERAL(11, 253, 33) // "testIsCoordinateLayInTheBall_..."

    },
    "Testcollisions\0compareTwoCoordinates\0"
    "\0compareTwoCoordinates_data\0"
    "testChechLengthToTheWalls\0"
    "testChechLengthToTheWalls_data\0"
    "testIsPlaceCompareOtherBalls\0"
    "testIsPlaceCompareOtherBalls_data\0"
    "testIsAvaiblePos\0testIsAvaiblePos_data\0"
    "testIsCoordinateLayInTheBall\0"
    "testIsCoordinateLayInTheBall_data"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Testcollisions[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      10,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   64,    2, 0x08 /* Private */,
       3,    0,   65,    2, 0x08 /* Private */,
       4,    0,   66,    2, 0x08 /* Private */,
       5,    0,   67,    2, 0x08 /* Private */,
       6,    0,   68,    2, 0x08 /* Private */,
       7,    0,   69,    2, 0x08 /* Private */,
       8,    0,   70,    2, 0x08 /* Private */,
       9,    0,   71,    2, 0x08 /* Private */,
      10,    0,   72,    2, 0x08 /* Private */,
      11,    0,   73,    2, 0x08 /* Private */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,

       0        // eod
};

void Testcollisions::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Testcollisions *_t = static_cast<Testcollisions *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->compareTwoCoordinates(); break;
        case 1: _t->compareTwoCoordinates_data(); break;
        case 2: _t->testChechLengthToTheWalls(); break;
        case 3: _t->testChechLengthToTheWalls_data(); break;
        case 4: _t->testIsPlaceCompareOtherBalls(); break;
        case 5: _t->testIsPlaceCompareOtherBalls_data(); break;
        case 6: _t->testIsAvaiblePos(); break;
        case 7: _t->testIsAvaiblePos_data(); break;
        case 8: _t->testIsCoordinateLayInTheBall(); break;
        case 9: _t->testIsCoordinateLayInTheBall_data(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Testcollisions::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Testcollisions.data,
      qt_meta_data_Testcollisions,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *Testcollisions::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Testcollisions::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Testcollisions.stringdata0))
        return static_cast<void*>(const_cast< Testcollisions*>(this));
    return QObject::qt_metacast(_clname);
}

int Testcollisions::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 10)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 10;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 10)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 10;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
