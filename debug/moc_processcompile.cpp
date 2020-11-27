/****************************************************************************
** Meta object code from reading C++ file 'processcompile.h'
**
** Created: Thu Apr 12 00:19:35 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../processcompile.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'processcompile.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_ProcessCompile[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       4,       // signalCount

 // signals: signature, parameters, type, tag, flags
      18,   16,   15,   15, 0x05,
      55,   16,   15,   15, 0x05,
      91,   16,   15,   15, 0x05,
     127,   16,   15,   15, 0x05,

 // slots: signature, parameters, type, tag, flags
     163,   15,   15,   15, 0x0a,
     186,   15,   15,   15, 0x0a,
     213,   15,   15,   15, 0x0a,
     252,   15,   15,   15, 0x0a,
     296,  290,   15,   15, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_ProcessCompile[] = {
    "ProcessCompile\0\0,\0"
    "signal_compileStarted(QString,Q_PID)\0"
    "signal_compileFinished(QString,int)\0"
    "signal_compileStdOut(QString,Q_PID)\0"
    "signal_compileStdErr(QString,Q_PID)\0"
    "slot_compile_Started()\0"
    "slot_compile_Finished(int)\0"
    "slot_compile_readyReadStandardOutput()\0"
    "slot_compile_readyReadStandardError()\0"
    "error\0slot_compile_error(QProcess::ProcessError)\0"
};

const QMetaObject ProcessCompile::staticMetaObject = {
    { &QObject::staticMetaObject, qt_meta_stringdata_ProcessCompile,
      qt_meta_data_ProcessCompile, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &ProcessCompile::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *ProcessCompile::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *ProcessCompile::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_ProcessCompile))
        return static_cast<void*>(const_cast< ProcessCompile*>(this));
    return QObject::qt_metacast(_clname);
}

int ProcessCompile::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QObject::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: signal_compileStarted((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Q_PID(*)>(_a[2]))); break;
        case 1: signal_compileFinished((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< int(*)>(_a[2]))); break;
        case 2: signal_compileStdOut((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Q_PID(*)>(_a[2]))); break;
        case 3: signal_compileStdErr((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< Q_PID(*)>(_a[2]))); break;
        case 4: slot_compile_Started(); break;
        case 5: slot_compile_Finished((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 6: slot_compile_readyReadStandardOutput(); break;
        case 7: slot_compile_readyReadStandardError(); break;
        case 8: slot_compile_error((*reinterpret_cast< QProcess::ProcessError(*)>(_a[1]))); break;
        default: ;
        }
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
void ProcessCompile::signal_compileStarted(QString _t1, Q_PID _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}

// SIGNAL 1
void ProcessCompile::signal_compileFinished(QString _t1, int _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 1, _a);
}

// SIGNAL 2
void ProcessCompile::signal_compileStdOut(QString _t1, Q_PID _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 2, _a);
}

// SIGNAL 3
void ProcessCompile::signal_compileStdErr(QString _t1, Q_PID _t2)
{
    void *_a[] = { 0, const_cast<void*>(reinterpret_cast<const void*>(&_t1)), const_cast<void*>(reinterpret_cast<const void*>(&_t2)) };
    QMetaObject::activate(this, &staticMetaObject, 3, _a);
}
QT_END_MOC_NAMESPACE
