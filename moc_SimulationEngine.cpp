/****************************************************************************
** Meta object code from reading C++ file 'SimulationEngine.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.7.0)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "SimulationEngine.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'SimulationEngine.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.7.0. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SimulationEngine_t {
    QByteArrayData data[9];
    char stringdata0[87];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SimulationEngine_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SimulationEngine_t qt_meta_stringdata_SimulationEngine = {
    {
QT_MOC_LITERAL(0, 0, 16), // "SimulationEngine"
QT_MOC_LITERAL(1, 17, 9), // "startWork"
QT_MOC_LITERAL(2, 27, 0), // ""
QT_MOC_LITERAL(3, 28, 5), // "pause"
QT_MOC_LITERAL(4, 34, 6), // "resume"
QT_MOC_LITERAL(5, 41, 11), // "addSpecimen"
QT_MOC_LITERAL(6, 53, 9), // "Specimen*"
QT_MOC_LITERAL(7, 63, 8), // "specimen"
QT_MOC_LITERAL(8, 72, 14) // "removeSpecimen"

    },
    "SimulationEngine\0startWork\0\0pause\0"
    "resume\0addSpecimen\0Specimen*\0specimen\0"
    "removeSpecimen"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SimulationEngine[] = {

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
       1,    0,   39,    2, 0x0a /* Public */,
       3,    0,   40,    2, 0x0a /* Public */,
       4,    0,   41,    2, 0x0a /* Public */,
       5,    1,   42,    2, 0x0a /* Public */,
       8,    1,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, 0x80000000 | 6,    7,
    QMetaType::Void, 0x80000000 | 6,    7,

       0        // eod
};

void SimulationEngine::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SimulationEngine *_t = static_cast<SimulationEngine *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->startWork(); break;
        case 1: _t->pause(); break;
        case 2: _t->resume(); break;
        case 3: _t->addSpecimen((*reinterpret_cast< Specimen*(*)>(_a[1]))); break;
        case 4: _t->removeSpecimen((*reinterpret_cast< Specimen*(*)>(_a[1]))); break;
        default: ;
        }
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        switch (_id) {
        default: *reinterpret_cast<int*>(_a[0]) = -1; break;
        case 3:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Specimen* >(); break;
            }
            break;
        case 4:
            switch (*reinterpret_cast<int*>(_a[1])) {
            default: *reinterpret_cast<int*>(_a[0]) = -1; break;
            case 0:
                *reinterpret_cast<int*>(_a[0]) = qRegisterMetaType< Specimen* >(); break;
            }
            break;
        }
    }
}

const QMetaObject SimulationEngine::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_SimulationEngine.data,
      qt_meta_data_SimulationEngine,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *SimulationEngine::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SimulationEngine::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_SimulationEngine.stringdata0))
        return static_cast<void*>(const_cast< SimulationEngine*>(this));
    return QObject::qt_metacast(_clname);
}

int SimulationEngine::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
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
