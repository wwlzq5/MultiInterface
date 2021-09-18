/****************************************************************************
** Meta object code from reading C++ file 'widgetUser.h'
**
** Created: Mon Aug 30 16:15:30 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widgetUser.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widgetUser.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_UserWidget[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       5,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: signature, parameters, type, tag, flags
      12,   11,   11,   11, 0x05,

 // slots: signature, parameters, type, tag, flags
      36,   11,   11,   11, 0x08,
      50,   11,   11,   11, 0x08,
      73,   11,   11,   11, 0x08,
     101,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_UserWidget[] = {
    "UserWidget\0\0signal_TimeLogin(QTime)\0"
    "slots_login()\0slots_changePassWrod()\0"
    "slots_loginChangePassWrod()\0"
    "slots_CancelchangePassWrod()\0"
};

void UserWidget::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        UserWidget *_t = static_cast<UserWidget *>(_o);
        switch (_id) {
        case 0: _t->signal_TimeLogin((*reinterpret_cast< QTime(*)>(_a[1]))); break;
        case 1: _t->slots_login(); break;
        case 2: _t->slots_changePassWrod(); break;
        case 3: _t->slots_loginChangePassWrod(); break;
        case 4: _t->slots_CancelchangePassWrod(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData UserWidget::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject UserWidget::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_UserWidget,
      qt_meta_data_UserWidget, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &UserWidget::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *UserWidget::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *UserWidget::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_UserWidget))
        return static_cast<void*>(const_cast< UserWidget*>(this));
    return QWidget::qt_metacast(_clname);
}

int UserWidget::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 5)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 5;
    }
    return _id;
}

// SIGNAL 0
void UserWidget::signal_TimeLogin(QTime _t1)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_END_MOC_NAMESPACE
