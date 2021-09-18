/****************************************************************************
** Meta object code from reading C++ file 'widget_count.h'
**
** Created: Sat Sep 18 14:37:51 2021
**      by: The Qt Meta Object Compiler version 63 (Qt 4.8.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../widget_count.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'widget_count.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 63
#error "This file was generated using the moc from 4.8.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_widget_count[] = {

 // content:
       6,       // revision
       0,       // classname
       0,    0, // classinfo
       8,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      14,   13,   13,   13, 0x08,
      55,   31,   13,   13, 0x0a,
     104,   92,   13,   13, 0x0a,
     151,   92,   13,   13, 0x0a,
     207,  196,   13,   13, 0x0a,
     245,   92,   13,   13, 0x0a,
     293,   92,   13,   13, 0x0a,
     341,   13,   13,   13, 0x0a,

       0        // eod
};

static const char qt_meta_stringdata_widget_count[] = {
    "widget_count\0\0slots_turnPage()\0"
    "total,failNum,modelRate\0"
    "slots_updateCountInfo(int,int,float)\0"
    "pCountdates\0slots_UpdateTable1(QList<cErrorTypeCountInfo>)\0"
    "slots_UpdateTable2(QList<cErrorCountbyTime>)\0"
    "pCountdate\0slots_UpdateTable2(cErrorCountbyTime)\0"
    "slots_ShowPieImage1(QList<cErrorTypeCountInfo>)\0"
    "slots_ShowPieImage2(QList<cErrorTypeCountInfo>)\0"
    "slots_ShowShiftIamge()\0"
};

void widget_count::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Q_ASSERT(staticMetaObject.cast(_o));
        widget_count *_t = static_cast<widget_count *>(_o);
        switch (_id) {
        case 0: _t->slots_turnPage(); break;
        case 1: _t->slots_updateCountInfo((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< float(*)>(_a[3]))); break;
        case 2: _t->slots_UpdateTable1((*reinterpret_cast< QList<cErrorTypeCountInfo>(*)>(_a[1]))); break;
        case 3: _t->slots_UpdateTable2((*reinterpret_cast< QList<cErrorCountbyTime>(*)>(_a[1]))); break;
        case 4: _t->slots_UpdateTable2((*reinterpret_cast< cErrorCountbyTime(*)>(_a[1]))); break;
        case 5: _t->slots_ShowPieImage1((*reinterpret_cast< QList<cErrorTypeCountInfo>(*)>(_a[1]))); break;
        case 6: _t->slots_ShowPieImage2((*reinterpret_cast< QList<cErrorTypeCountInfo>(*)>(_a[1]))); break;
        case 7: _t->slots_ShowShiftIamge(); break;
        default: ;
        }
    }
}

const QMetaObjectExtraData widget_count::staticMetaObjectExtraData = {
    0,  qt_static_metacall 
};

const QMetaObject widget_count::staticMetaObject = {
    { &QWidget::staticMetaObject, qt_meta_stringdata_widget_count,
      qt_meta_data_widget_count, &staticMetaObjectExtraData }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &widget_count::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *widget_count::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *widget_count::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_widget_count))
        return static_cast<void*>(const_cast< widget_count*>(this));
    return QWidget::qt_metacast(_clname);
}

int widget_count::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 8)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 8;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
