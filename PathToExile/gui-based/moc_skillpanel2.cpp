/****************************************************************************
** Meta object code from reading C++ file 'skillpanel2.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.3.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../Testing/PathOfExile3/skillpanel2.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'skillpanel2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.3.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_SkillPanel2_t {
    QByteArrayData data[14];
    char stringdata[111];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_SkillPanel2_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_SkillPanel2_t qt_meta_stringdata_SkillPanel2 = {
    {
QT_MOC_LITERAL(0, 0, 11),
QT_MOC_LITERAL(1, 12, 15),
QT_MOC_LITERAL(2, 28, 0),
QT_MOC_LITERAL(3, 29, 5),
QT_MOC_LITERAL(4, 35, 5),
QT_MOC_LITERAL(5, 41, 16),
QT_MOC_LITERAL(6, 58, 11),
QT_MOC_LITERAL(7, 70, 15),
QT_MOC_LITERAL(8, 86, 3),
QT_MOC_LITERAL(9, 90, 8),
QT_MOC_LITERAL(10, 99, 2),
QT_MOC_LITERAL(11, 102, 2),
QT_MOC_LITERAL(12, 105, 2),
QT_MOC_LITERAL(13, 108, 2)
    },
    "SkillPanel2\0changeSecondImg\0\0img_x\0"
    "img_y\0changeSecondName\0secondtName\0"
    "changeSecondDes\0des\0drawLine\0x1\0y1\0"
    "x2\0y2"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_SkillPanel2[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       4,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    2,   34,    2, 0x0a /* Public */,
       5,    1,   39,    2, 0x0a /* Public */,
       7,    1,   42,    2, 0x0a /* Public */,
       9,    4,   45,    2, 0x0a /* Public */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,
    QMetaType::Void, QMetaType::QString,    6,
    QMetaType::Void, QMetaType::QString,    8,
    QMetaType::Void, QMetaType::Int, QMetaType::Int, QMetaType::Int, QMetaType::Int,   10,   11,   12,   13,

       0        // eod
};

void SkillPanel2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        SkillPanel2 *_t = static_cast<SkillPanel2 *>(_o);
        switch (_id) {
        case 0: _t->changeSecondImg((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 1: _t->changeSecondName((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 2: _t->changeSecondDes((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 3: _t->drawLine((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2])),(*reinterpret_cast< int(*)>(_a[3])),(*reinterpret_cast< int(*)>(_a[4]))); break;
        default: ;
        }
    }
}

const QMetaObject SkillPanel2::staticMetaObject = {
    { &QGraphicsScene::staticMetaObject, qt_meta_stringdata_SkillPanel2.data,
      qt_meta_data_SkillPanel2,  qt_static_metacall, 0, 0}
};


const QMetaObject *SkillPanel2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *SkillPanel2::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_SkillPanel2.stringdata))
        return static_cast<void*>(const_cast< SkillPanel2*>(this));
    return QGraphicsScene::qt_metacast(_clname);
}

int SkillPanel2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QGraphicsScene::qt_metacall(_c, _id, _a);
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
QT_END_MOC_NAMESPACE
