/****************************************************************************
** Meta object code from reading C++ file 'widgetAlert.h'
**
** Created: Mon Aug 30 16:15:29 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgetAlert.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetAlert.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_widget_Alert[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x0a,
      32,   13,   13,   13, 0x0a,
      55,   13,   13,   13, 0x0a,
      75,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_widget_Alert[] = {
    "widget_Alert\0\0slot_JudgeAlert()\0"
    "slot_PushAlretDelete()\0slot_PushAlretAdd()\0"
    "slot_Sure()\0"
};

void widget_Alert::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        widget_Alert *_t = static_cast<widget_Alert *>(_o);
        switch (_id) {
        case 0: _t->slot_JudgeAlert(); break;
        case 1: _t->slot_PushAlretDelete(); break;
        case 2: _t->slot_PushAlretAdd(); break;
        case 3: _t->slot_Sure(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObjectExtraData widget_Alert::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject widget_Alert::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_widget_Alert,
      qt_meta_data_widget_Alert, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &widget_Alert::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *widget_Alert::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *widget_Alert::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_widget_Alert))
        return static_cast<void*>(const_cast< widget_Alert*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int widget_Alert::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 4)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 4;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
