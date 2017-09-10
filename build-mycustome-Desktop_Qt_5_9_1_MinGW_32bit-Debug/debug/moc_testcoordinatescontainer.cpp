/****************************************************************************
** Meta object code from reading C++ file 'testcoordinatescontainer.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.9.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../mycustome/testcoordinatescontainer.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'testcoordinatescontainer.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.9.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_TestCoordinatescontainer_t {
    QByteArrayData data[13];
    char stringdata0[246];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_TestCoordinatescontainer_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_TestCoordinatescontainer_t qt_meta_stringdata_TestCoordinatescontainer = {
    {
QT_MOC_LITERAL(0, 0, 24), // "TestCoordinatescontainer"
QT_MOC_LITERAL(1, 25, 23), // "testCoordinatsInsertion"
QT_MOC_LITERAL(2, 49, 0), // ""
QT_MOC_LITERAL(3, 50, 15), // "testPreparation"
QT_MOC_LITERAL(4, 66, 21), // "testCoordinatsGetting"
QT_MOC_LITERAL(5, 88, 16), // "testPreparation1"
QT_MOC_LITERAL(6, 105, 25), // "testFindBallByCoordinates"
QT_MOC_LITERAL(7, 131, 30), // "testFindBallByCoordinates_data"
QT_MOC_LITERAL(8, 162, 16), // "testPreparation2"
QT_MOC_LITERAL(9, 179, 14), // "testRemoveItem"
QT_MOC_LITERAL(10, 194, 19), // "testRemoveItem_data"
QT_MOC_LITERAL(11, 214, 16), // "testPreparation3"
QT_MOC_LITERAL(12, 231, 14) // "testUpdateData"

    },
    "TestCoordinatescontainer\0"
    "testCoordinatsInsertion\0\0testPreparation\0"
    "testCoordinatsGetting\0testPreparation1\0"
    "testFindBallByCoordinates\0"
    "testFindBallByCoordinates_data\0"
    "testPreparation2\0testRemoveItem\0"
    "testRemoveItem_data\0testPreparation3\0"
    "testUpdateData"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_TestCoordinatescontainer[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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
    QMetaType::Void,

       0        // eod
};

void TestCoordinatescontainer::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        TestCoordinatescontainer *_t = static_cast<TestCoordinatescontainer *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->testCoordinatsInsertion(); break;
        case 1: _t->testPreparation(); break;
        case 2: _t->testCoordinatsGetting(); break;
        case 3: _t->testPreparation1(); break;
        case 4: _t->testFindBallByCoordinates(); break;
        case 5: _t->testFindBallByCoordinates_data(); break;
        case 6: _t->testPreparation2(); break;
        case 7: _t->testRemoveItem(); break;
        case 8: _t->testRemoveItem_data(); break;
        case 9: _t->testPreparation3(); break;
        case 10: _t->testUpdateData(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject TestCoordinatescontainer::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_TestCoordinatescontainer.data,
      qt_meta_data_TestCoordinatescontainer,  qt_static_metacall, nullptr, nullptr}
};


const QMetaObject *TestCoordinatescontainer::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *TestCoordinatescontainer::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_TestCoordinatescontainer.stringdata0))
        return static_cast<void*>(const_cast< TestCoordinatescontainer*>(this));
    return QObject::qt_metacast(_clname);
}

int TestCoordinatescontainer::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
