/****************************************************************************
** Meta object code from reading C++ file 'SimulationScene.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SimulationScene.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationScene.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SimulationScene_t {
    QByteArrayData data[13];
    char stringdata0[155];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimulationScene_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimulationScene_t qt_meta_stringdata_SimulationScene = {
    {
QT_MOC_LITERAL(0, 0, 15), // "SimulationScene"
QT_MOC_LITERAL(1, 16, 15), // "updateBoardSize"
QT_MOC_LITERAL(2, 32, 0), // ""
QT_MOC_LITERAL(3, 33, 4), // "size"
QT_MOC_LITERAL(4, 38, 12), // "replaceField"
QT_MOC_LITERAL(5, 51, 11), // "BoardField*"
QT_MOC_LITERAL(6, 63, 9), // "old_field"
QT_MOC_LITERAL(7, 73, 9), // "new_field"
QT_MOC_LITERAL(8, 83, 14), // "removeSpecimen"
QT_MOC_LITERAL(9, 98, 9), // "Specimen*"
QT_MOC_LITERAL(10, 108, 8), // "specimen"
QT_MOC_LITERAL(11, 117, 18), // "showSpecimenWidget"
QT_MOC_LITERAL(12, 136, 18) // "hideSpecimenWidget"

    },
    "SimulationScene\0updateBoardSize\0\0size\0"
    "replaceField\0BoardField*\0old_field\0"
    "new_field\0removeSpecimen\0Specimen*\0"
    "specimen\0showSpecimenWidget\0"
    "hideSpecimenWidget"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulationScene[] = {

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
       1,    1,   39,    2, 0x0a /* Public */,
       4,    2,   42,    2, 0x0a /* Public */,
       8,    1,   47,    2, 0x0a /* Public */,
      11,    1,   50,    2, 0x0a /* Public */,
      12,    0,   53,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::QPoint,    3,
    QMetaType::Void, 0x80000000 | 5, 0x80000000 | 5,    6,    7,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void, 0x80000000 | 9,   10,
    QMetaType::Void,

       0        // eod
};

void SimulationScene::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimulationScene *_t = static_cast<SimulationScene *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->updateBoardSize((*reinterpret_cast< const QPoint(*)>(_a[1]))); break;
        case 1: _t->replaceField((*reinterpret_cast< BoardField*(*)>(_a[1])),(*reinterpret_cast< BoardField*(*)>(_a[2]))); break;
        case 2: _t->removeSpecimen((*reinterpret_cast< Specimen*(*)>(_a[1]))); break;
        case 3: _t->showSpecimenWidget((*reinterpret_cast< Specimen*(*)>(_a[1]))); break;
        case 4: _t->hideSpecimenWidget(); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 2:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Specimen* >(); break;
            }
            break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Specimen* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SimulationScene::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_SimulationScene.data,
      qt_meta_data_SimulationScene,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimulationScene::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationScene::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimulationScene.stringdata0))
        return static_cast<void*>(const_cast< SimulationScene*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int SimulationScene::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
