/****************************************************************************
** Meta object code from reading C++ file 'multiinterface.h'
**
** Created: Wed Dec 15 09:36:18 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../multiinterface.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'multiinterface.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MultiInterface[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
      17,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,
      50,   16,   15,   15, 0x05,
      76,   73,   15,   15, 0x05,
     114,   15,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     146,   16,   15,   15, 0x0a,
     181,   15,   15,   15, 0x0a,
     204,   15,   15,   15, 0x0a,
     226,   15,   15,   15, 0x0a,
     246,   15,   15,   15, 0x0a,
     267,   16,   15,   15, 0x0a,
     298,   15,   15,   15, 0x0a,
     322,   15,   15,   15, 0x0a,
     347,   15,   15,   15, 0x0a,
     371,   15,   15,   15, 0x0a,
     394,   15,   15,   15, 0x0a,
     415,   15,   15,   15, 0x0a,
     463,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MultiInterface[] = {
    "MultiInterface\0\0,\0sianal_WarnMessage(int,QString)\0"
    "UpdateIOCard(int*,int)\0,,\0"
    "sianal_updateCountInfo(int,int,float)\0"
    "sianal_UpdateTable1(cErrorInfo)\0"
    "slots_ModeState(StateEnum,QString)\0"
    "slots_clickAccont(int)\0ServerNewConnection()\0"
    "onServerDataReady()\0slots_ConnectState()\0"
    "slots_OnUpdateIOCard(int*,int)\0"
    "slots_SaveCountBytime()\0"
    "slots_SaveCountByShift()\0"
    "slots_UpdateRecordSet()\0slots_UpdateShiftSet()\0"
    "slots_CloseConnect()\0"
    "slot_StateChanged(QAbstractSocket::SocketState)\0"
    "slots_loginState(int)\0"
};

void MultiInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MultiInterface *_t = static_cast<MultiInterface *>(_o);
        switch (_id) {
        case 0: _t->sianal_WarnMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->UpdateIOCard((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->sianal_updateCountInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 3: _t->sianal_UpdateTable1((*reinterpret_cast< cErrorInfo(*)>(_a[1]))); break;
        case 4: _t->slots_ModeState((*reinterpret_cast< StateEnum(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 5: _t->slots_clickAccont((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: _t->ServerNewConnection(); break;
        case 7: _t->onServerDataReady(); break;
        case 8: _t->slots_ConnectState(); break;
        case 9: _t->slots_OnUpdateIOCard((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 10: _t->slots_SaveCountBytime(); break;
        case 11: _t->slots_SaveCountByShift(); break;
        case 12: _t->slots_UpdateRecordSet(); break;
        case 13: _t->slots_UpdateShiftSet(); break;
        case 14: _t->slots_CloseConnect(); break;
        case 15: _t->slot_StateChanged((*reinterpret_cast< QAbstractSocket::SocketState(*)>(_a[1]))); break;
        case 16: _t->slots_loginState((*reinterpret_cast< int(*)>(_a[1]))); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData MultiInterface::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject MultiInterface::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MultiInterface,
      qt_meta_data_MultiInterface, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MultiInterface::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MultiInterface::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MultiInterface::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MultiInterface))
        return static_cast<void*>(const_cast< MultiInterface*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MultiInterface::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 17)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 17;
    }
    return _id;
}

// SIGNAL 0
void MultiInterface::sianal_WarnMessage(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void MultiInterface::UpdateIOCard(int * _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void MultiInterface::sianal_updateCountInfo(int _t1, int _t2, float _t3)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)), const_cast<void*>(reinterpret_cast<const void*>(&_t3)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void MultiInterface::sianal_UpdateTable1(cErrorInfo _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
