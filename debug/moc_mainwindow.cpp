/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created: Mon Apr 16 00:16:38 2012
**      by: The Qt Meta Object Compiler version 62 (Qt 4.7.3)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../mainwindow.h"
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 62
#error "This file was generated using the moc from 4.7.3. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
static const uint qt_meta_data_MainWindow[] = {

 // content:
       5,       // revision
       0,       // classname
       0,    0, // classinfo
      16,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       0,       // signalCount

 // slots: signature, parameters, type, tag, flags
      17,   11,   12,   11, 0x0a,
      34,   32,   11,   11, 0x0a,
      66,   11,   11,   11, 0x08,
      89,   11,   11,   11, 0x08,
     119,   11,   12,   11, 0x08,
     129,   11,   11,   11, 0x08,
     151,   11,   11,   11, 0x08,
     176,   11,   11,   11, 0x08,
     201,   11,   11,   11, 0x08,
     223,   11,   11,   11, 0x08,
     246,   11,   11,   11, 0x08,
     281,   11,   11,   11, 0x08,
     311,  306,   11,   11, 0x08,
     366,  306,   11,   11, 0x08,
     413,   11,   11,   11, 0x08,
     450,   11,   11,   11, 0x08,

       0        // eod
};

static const char qt_meta_stringdata_MainWindow[] = {
    "MainWindow\0\0bool\0slot_buildUI()\0,\0"
    "slot_MessageCenter(int,QString)\0"
    "actionLoad_Extension()\0"
    "actionSave_Current_Document()\0saveAll()\0"
    "openRecentExtension()\0slot_cFile_textChanged()\0"
    "slot_hFile_textChanged()\0slot_m4_textChanged()\0"
    "slot_w32_textChanged()\0"
    "slot_tabWidget_currentChanged(int)\0"
    "slot_compile_extension()\0item\0"
    "slot_listWidgetExtensionFile_changed(QListWidgetItem*)\0"
    "slot_listWidgetPHPFE_changed(QListWidgetItem*)\0"
    "slot_compile_OutputMessages(QString)\0"
    "slot_compile_clearOutputMessages()\0"
};

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow,
      qt_meta_data_MainWindow, 0 }
};

#ifdef Q_NO_DATA_RELOCATION
const QMetaObject &MainWindow::getStaticMetaObject() { return staticMetaObject; }
#endif //Q_NO_DATA_RELOCATION

const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->metaObject : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        switch (_id) {
        case 0: { bool _r = slot_buildUI();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: slot_MessageCenter((*reinterpret_cast< int(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: actionLoad_Extension(); break;
        case 3: actionSave_Current_Document(); break;
        case 4: { bool _r = saveAll();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 5: openRecentExtension(); break;
        case 6: slot_cFile_textChanged(); break;
        case 7: slot_hFile_textChanged(); break;
        case 8: slot_m4_textChanged(); break;
        case 9: slot_w32_textChanged(); break;
        case 10: slot_tabWidget_currentChanged((*reinterpret_cast< int(*)>(_a[1]))); break;
        case 11: slot_compile_extension(); break;
        case 12: slot_listWidgetExtensionFile_changed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 13: slot_listWidgetPHPFE_changed((*reinterpret_cast< QListWidgetItem*(*)>(_a[1]))); break;
        case 14: slot_compile_OutputMessages((*reinterpret_cast< QString(*)>(_a[1]))); break;
        case 15: slot_compile_clearOutputMessages(); break;
        default: ;
        }
        _id -= 16;
    }
    return _id;
}
QT_END_MOC_NAMESPACE
