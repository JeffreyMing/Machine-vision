/****************************************************************************
** Meta object code from reading C++ file 'machine_vision.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.6.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../../machine_vision.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'machine_vision.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.6.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_Machine_Vision_t {
    QByteArrayData data[13];
    char stringdata0[169];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Machine_Vision_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Machine_Vision_t qt_meta_stringdata_Machine_Vision = {
    {
QT_MOC_LITERAL(0, 0, 14), // "Machine_Vision"
QT_MOC_LITERAL(1, 15, 9), // "OpenImage"
QT_MOC_LITERAL(2, 25, 0), // ""
QT_MOC_LITERAL(3, 26, 9), // "SaveImage"
QT_MOC_LITERAL(4, 36, 9), // "Smoothing"
QT_MOC_LITERAL(5, 46, 14), // "Smoothing_Data"
QT_MOC_LITERAL(6, 61, 6), // "Median"
QT_MOC_LITERAL(7, 68, 12), // "Equalization"
QT_MOC_LITERAL(8, 81, 8), // "PowerLaw"
QT_MOC_LITERAL(9, 90, 13), // "change_slider"
QT_MOC_LITERAL(10, 104, 22), // "Conservative_Smoothing"
QT_MOC_LITERAL(11, 127, 28), // "Second_Derivative_Sharpening"
QT_MOC_LITERAL(12, 156, 12) // "Thresholding"

    },
    "Machine_Vision\0OpenImage\0\0SaveImage\0"
    "Smoothing\0Smoothing_Data\0Median\0"
    "Equalization\0PowerLaw\0change_slider\0"
    "Conservative_Smoothing\0"
    "Second_Derivative_Sharpening\0Thresholding"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Machine_Vision[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
      11,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: name, argc, parameters, tag, flags
       1,    0,   69,    2, 0x08 /* Private */,
       3,    0,   70,    2, 0x08 /* Private */,
       4,    0,   71,    2, 0x08 /* Private */,
       5,    0,   72,    2, 0x08 /* Private */,
       6,    0,   73,    2, 0x08 /* Private */,
       7,    0,   74,    2, 0x08 /* Private */,
       8,    0,   75,    2, 0x08 /* Private */,
       9,    0,   76,    2, 0x08 /* Private */,
      10,    0,   77,    2, 0x08 /* Private */,
      11,    0,   78,    2, 0x08 /* Private */,
      12,    0,   79,    2, 0x08 /* Private */,

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

       0        // eod
};

void Machine_Vision::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        Machine_Vision *_t = static_cast<Machine_Vision *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->OpenImage(); break;
        case 1: _t->SaveImage(); break;
        case 2: _t->Smoothing(); break;
        case 3: _t->Smoothing_Data(); break;
        case 4: _t->Median(); break;
        case 5: _t->Equalization(); break;
        case 6: _t->PowerLaw(); break;
        case 7: _t->change_slider(); break;
        case 8: _t->Conservative_Smoothing(); break;
        case 9: _t->Second_Derivative_Sharpening(); break;
        case 10: _t->Thresholding(); break;
        default: ;
        }
    }
    Q_UNUSED(_a);
}

const QMetaObject Machine_Vision::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_Machine_Vision.data,
      qt_meta_data_Machine_Vision,  qt_static_metacall, Q_NULLPTR, Q_NULLPTR}
};


const QMetaObject *Machine_Vision::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Machine_Vision::qt_metacast(const char *_clname)
{
    if (!_clname) return Q_NULLPTR;
    if (!strcmp(_clname, qt_meta_stringdata_Machine_Vision.stringdata0))
        return static_cast<void*>(const_cast< Machine_Vision*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int Machine_Vision::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 11)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 11;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 11)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 11;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
