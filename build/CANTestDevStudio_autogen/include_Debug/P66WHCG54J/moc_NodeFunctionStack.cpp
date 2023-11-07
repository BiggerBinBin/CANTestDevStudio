/****************************************************************************
** Meta object code from reading C++ file 'NodeFunctionStack.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.15.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../../common/NodeFunctionStack.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'NodeFunctionStack.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.15.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_NodeFunctionStack_t {
    QByteArrayData data[9];
    char stringdata0[112];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_NodeFunctionStack_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_NodeFunctionStack_t qt_meta_stringdata_NodeFunctionStack = {
    {
QT_MOC_LITERAL(0, 0, 17), // "NodeFunctionStack"
QT_MOC_LITERAL(1, 18, 17), // "connectionCreated"
QT_MOC_LITERAL(2, 36, 0), // ""
QT_MOC_LITERAL(3, 37, 12), // "ConnectionId"
QT_MOC_LITERAL(4, 50, 12), // "connectionId"
QT_MOC_LITERAL(5, 63, 17), // "connectionDeleted"
QT_MOC_LITERAL(6, 81, 11), // "nodeCreated"
QT_MOC_LITERAL(7, 93, 6), // "NodeId"
QT_MOC_LITERAL(8, 100, 11) // "nodeDeleted"

    },
    "NodeFunctionStack\0connectionCreated\0"
    "\0ConnectionId\0connectionId\0connectionDeleted\0"
    "nodeCreated\0NodeId\0nodeDeleted"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_NodeFunctionStack[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    1,   34,    2, 0x0a /* Public */,
       5,    1,   37,    2, 0x0a /* Public */,
       6,    1,   40,    2, 0x0a /* Public */,
       8,    1,   43,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 3,    4,
    QMetaType::Void, 0x80000000 | 7,    4,
    QMetaType::Void, 0x80000000 | 7,    4,

       0        // eod
};

void NodeFunctionStack::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<NodeFunctionStack *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->connectionCreated((*reinterpret_cast< const ConnectionId(*)>(_a[1]))); break;
        case 1: _t->connectionDeleted((*reinterpret_cast< const ConnectionId(*)>(_a[1]))); break;
        case 2: _t->nodeCreated((*reinterpret_cast< const NodeId(*)>(_a[1]))); break;
        case 3: _t->nodeDeleted((*reinterpret_cast< const NodeId(*)>(_a[1]))); break;
        default: ;
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject NodeFunctionStack::staticMetaObject = { {
    QMetaObject::SuperData::link<QObject::staticMetaObject>(),
    qt_meta_stringdata_NodeFunctionStack.data,
    qt_meta_data_NodeFunctionStack,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *NodeFunctionStack::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *NodeFunctionStack::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_NodeFunctionStack.stringdata0))
        return static_cast<void*>(this);
    return QObject::qt_metacast(_clname);
}

int NodeFunctionStack::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 4)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 4;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
