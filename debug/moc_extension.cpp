/****************************************************************************
** Meta object code from reading C++ file 'extension.h'
**
** Created: Mon Apr 16 00:16:39 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../extension.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'extension.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_Extension[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       2,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       2,       // signalCount

 // signals: signature, parameters, type, tag, flags
      11,   10,   10,   10, 0x05,
      46,   44,   10,   10, 0x05,

       0        // eod
};

static const char qt_meta_stringdata_Extension[] = {
    "Extension\0\0signal_extension_load_finished()\0"
    ",\0signal_extension_load_failed(int,QString)\0"
};

const QMetaObject Extension::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_Extension,
      qt_meta_data_Extension, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &Extension::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *Extension::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *Extension::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_Extension))
        return static_cast<void*>(const_cast< Extension*>(this));
    return QObject::qt_metacast(_clname);
}

int Extension::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_extension_load_finished(); break;
        case 1: signal_extension_load_failed((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        default: ;
        }
        _id -= 2;
    }
    return _id;
}

// SIGNAL 0
void Extension::signal_extension_load_finished()
{
    QMetaObject::activate(this, &staticMetaObject, 0, 0);
}

// SIGNAL 1
void Extension::signal_extension_load_failed(int _t1, QString _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}
QT_END_MOC_NAMESPACE