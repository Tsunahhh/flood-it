/****************************************************************************
** Meta object code from reading C++ file 'GameView2.h'
**
** Created by: The Qt Meta Object Compiler version 68 (Qt 6.4.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../../include/GameView2.h"
#include <QtGui/qtextcursor.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'GameView2.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 68
#error "This file was generated using the moc from 6.4.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

#ifndef Q_CONSTINIT
#define Q_CONSTINIT
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
namespace {
struct qt_meta_stringdata_view__GameView2_t {
    uint offsetsAndSizes[10];
    char stringdata0[16];
    char stringdata1[14];
    char stringdata2[1];
    char stringdata3[2];
    char stringdata4[2];
};
#define QT_MOC_LITERAL(ofs, len) \
    uint(sizeof(qt_meta_stringdata_view__GameView2_t::offsetsAndSizes) + ofs), len 
Q_CONSTINIT static const qt_meta_stringdata_view__GameView2_t qt_meta_stringdata_view__GameView2 = {
    {
        QT_MOC_LITERAL(0, 15),  // "view::GameView2"
        QT_MOC_LITERAL(16, 13),  // "onCellClicked"
        QT_MOC_LITERAL(30, 0),  // ""
        QT_MOC_LITERAL(31, 1),  // "x"
        QT_MOC_LITERAL(33, 1)   // "y"
    },
    "view::GameView2",
    "onCellClicked",
    "",
    "x",
    "y"
};
#undef QT_MOC_LITERAL
} // unnamed namespace

Q_CONSTINIT static const uint qt_meta_data_view__GameView2[] = {

 // content:
      10,       // revision
       0,       // classname
       0,    0, // classinfo
       1,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags, initial metatype offsets
       1,    2,   20,    2, 0x08,    1 /* Private */,

 // slots: parameters
    QMetaType::Void, QMetaType::Int, QMetaType::Int,    3,    4,

       0        // eod
};

Q_CONSTINIT const QMetaObject view::GameView2::staticMetaObject = { {
    QMetaObject::SuperData::link<QWidget::staticMetaObject>(),
    qt_meta_stringdata_view__GameView2.offsetsAndSizes,
    qt_meta_data_view__GameView2,
    qt_static_metacall,
    nullptr,
    qt_incomplete_metaTypeArray<qt_meta_stringdata_view__GameView2_t,
        // Q_OBJECT / Q_GADGET
        QtPrivate::TypeAndForceComplete<GameView2, std::true_type>,
        // method 'onCellClicked'
        QtPrivate::TypeAndForceComplete<void, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>,
        QtPrivate::TypeAndForceComplete<int, std::false_type>
    >,
    nullptr
} };

void view::GameView2::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<GameView2 *>(_o);
        (void)_t;
        switch (_id) {
        case 0: _t->onCellClicked((*reinterpret_cast< std::add_pointer_t<int>>(_a[1])),(*reinterpret_cast< std::add_pointer_t<int>>(_a[2]))); break;
        default: ;
        }
    }
}

const QMetaObject *view::GameView2::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *view::GameView2::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_view__GameView2.stringdata0))
        return static_cast<void*>(this);
    if (!strcmp(_clname, "utils::Observer"))
        return static_cast< utils::Observer*>(this);
    return QWidget::qt_metacast(_clname);
}

int view::GameView2::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 1)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 1;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 1)
            *reinterpret_cast<QMetaType *>(_a[0]) = QMetaType();
        _id -= 1;
    }
    return _id;
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
