/****************************************************************************
** Meta object code from reading C++ file 'multiinterface.h'
**
** Created: Tue Nov 2 15:06:11 2021
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
      13,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,
      50,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
      73,   16,   15,   15, 0x0a,
     108,   15,   15,   15, 0x0a,
     131,   15,   15,   15, 0x0a,
     153,   15,   15,   15, 0x0a,
     173,   15,   15,   15, 0x0a,
     194,   16,   15,   15, 0x0a,
     225,   15,   15,   15, 0x0a,
     248,   15,   15,   15, 0x0a,
     272,   15,   15,   15, 0x0a,
     297,   15,   15,   15, 0x0a,
     321,   15,   15,   15, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_MultiInterface[] = {
    "MultiInterface\0\0,\0sianal_WarnMessage(int,QString)\0"
    "UpdateIOCard(int*,int)\0"
    "slots_ModeState(StateEnum,QString)\0"
    "slots_clickAccont(int)\0ServerNewConnection()\0"
    "onServerDataReady()\0slots_ConnectState()\0"
    "slots_OnUpdateIOCard(int*,int)\0"
    "slots_TimeLogin(QTime)\0slots_SaveCountBytime()\0"
    "slots_SaveCountByShift()\0"
    "slots_UpdateRecordSet()\0slots_UpdateShiftSet()\0"
};

void MultiInterface::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        MultiInterface *_t = static_cast<MultiInterface *>(_o);
        switch (_id) {
        case 0: _t->sianal_WarnMessage((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->UpdateIOCard((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: _t->slots_ModeState((*reinterpret_cast< StateEnum(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 3: _t->slots_clickAccont((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 4: _t->ServerNewConnection(); break;
        case 5: _t->onServerDataReady(); break;
        case 6: _t->slots_ConnectState(); break;
        case 7: _t->slots_OnUpdateIOCard((*reinterpret_cast< int*(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 8: _t->slots_TimeLogin((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 9: _t->slots_SaveCountBytime(); break;
        case 10: _t->slots_SaveCountByShift(); break;
        case 11: _t->slots_UpdateRecordSet(); break;
        case 12: _t->slots_UpdateShiftSet(); break;
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
        if (_id < 13)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 13;
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
QT_END_MOC_NAMESPACE
