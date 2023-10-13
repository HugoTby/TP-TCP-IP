/****************************************************************************
** Meta object code from reading C++ file 'InitiationQt.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.14.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../InitiationQt.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'InitiationQt.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.14.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_InitiationQt_t {
    QByteArrayData data[14];
    char stringdata0[239];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_InitiationQt_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_InitiationQt_t qt_meta_stringdata_InitiationQt = {
    {
QT_MOC_LITERAL(0, 0, 12), // "InitiationQt"
QT_MOC_LITERAL(1, 13, 29), // "onDisplayMessageButtonClicked"
QT_MOC_LITERAL(2, 43, 0), // ""
QT_MOC_LITERAL(3, 44, 22), // "onConnectButtonClicked"
QT_MOC_LITERAL(4, 67, 17), // "onSocketConnected"
QT_MOC_LITERAL(5, 85, 20), // "onSocketDisconnected"
QT_MOC_LITERAL(6, 106, 26), // "onSendMessageButtonClicked"
QT_MOC_LITERAL(7, 133, 17), // "onSocketReadyRead"
QT_MOC_LITERAL(8, 151, 21), // "onServerNewConnection"
QT_MOC_LITERAL(9, 173, 20), // "onClientDisconnected"
QT_MOC_LITERAL(10, 194, 17), // "onClientReadyRead"
QT_MOC_LITERAL(11, 212, 8), // "EnvoiCel"
QT_MOC_LITERAL(12, 221, 8), // "EnvoiFar"
QT_MOC_LITERAL(13, 230, 8) // "EnvoiHyg"

    },
    "InitiationQt\0onDisplayMessageButtonClicked\0"
    "\0onConnectButtonClicked\0onSocketConnected\0"
    "onSocketDisconnected\0onSendMessageButtonClicked\0"
    "onSocketReadyRead\0onServerNewConnection\0"
    "onClientDisconnected\0onClientReadyRead\0"
    "EnvoiCel\0EnvoiFar\0EnvoiHyg"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_InitiationQt[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      12,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   74,    2, 0x0a /* Public */,
       3,    0,   75,    2, 0x0a /* Public */,
       4,    0,   76,    2, 0x0a /* Public */,
       5,    0,   77,    2, 0x0a /* Public */,
       6,    0,   78,    2, 0x0a /* Public */,
       7,    0,   79,    2, 0x0a /* Public */,
       8,    0,   80,    2, 0x0a /* Public */,
       9,    0,   81,    2, 0x0a /* Public */,
      10,    0,   82,    2, 0x0a /* Public */,
      11,    0,   83,    2, 0x0a /* Public */,
      12,    0,   84,    2, 0x0a /* Public */,
      13,    0,   85,    2, 0x0a /* Public */,

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
    QMetaType::Void,

       0        // eod
};

void InitiationQt::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<InitiationQt *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->onDisplayMessageButtonClicked(); break;
        case 1: _t->onConnectButtonClicked(); break;
        case 2: _t->onSocketConnected(); break;
        case 3: _t->onSocketDisconnected(); break;
        case 4: _t->onSendMessageButtonClicked(); break;
        case 5: _t->onSocketReadyRead(); break;
        case 6: _t->onServerNewConnection(); break;
        case 7: _t->onClientDisconnected(); break;
        case 8: _t->onClientReadyRead(); break;
        case 9: _t->EnvoiCel(); break;
        case 10: _t->EnvoiFar(); break;
        case 11: _t->EnvoiHyg(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

QT_INIT_METAOBJECT const QMetaObject InitiationQt::staticMetaObject = { {
    QMetaObject::SuperData::link<QMainWindow::staticMetaObject>(),
    qt_meta_stringdata_InitiationQt.data,
    qt_meta_data_InitiationQt,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *InitiationQt::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *InitiationQt::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_InitiationQt.stringdata0))
        return static_cast<void*>(this);
    return QMainWindow::qt_metacast(_clname);
}

int InitiationQt::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 12)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 12;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 12)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 12;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
