/****************************************************************************
** Meta object code from reading C++ file 'mainwindow.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.1.1)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include "../indexador/mainwindow.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'mainwindow.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.1.1. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
struct qt_meta_stringdata_MainWindow_t {
    QByteArrayData data[15];
    char stringdata[234];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    offsetof(qt_meta_stringdata_MainWindow_t, stringdata) + ofs \
        - idx * sizeof(QByteArrayData) \
    )
static const qt_meta_stringdata_MainWindow_t qt_meta_stringdata_MainWindow = {
    {
QT_MOC_LITERAL(0, 0, 10),
QT_MOC_LITERAL(1, 11, 4),
QT_MOC_LITERAL(2, 16, 0),
QT_MOC_LITERAL(3, 17, 32),
QT_MOC_LITERAL(4, 50, 17),
QT_MOC_LITERAL(5, 68, 4),
QT_MOC_LITERAL(6, 73, 21),
QT_MOC_LITERAL(7, 95, 20),
QT_MOC_LITERAL(8, 116, 23),
QT_MOC_LITERAL(9, 140, 22),
QT_MOC_LITERAL(10, 163, 24),
QT_MOC_LITERAL(11, 188, 4),
QT_MOC_LITERAL(12, 193, 31),
QT_MOC_LITERAL(13, 225, 5),
QT_MOC_LITERAL(14, 231, 1)
    },
    "MainWindow\0addQ\0\0on_tableWidget_itemDoubleClicked\0"
    "QTableWidgetItem*\0item\0on_alfaButton_clicked\0"
    "on_perButton_clicked\0on_eventsButton_clicked\0"
    "on_totalButton_clicked\0on_searchBar_textChanged\0"
    "arg1\0on_addCurriculoButton_triggered\0"
    "on_go\0a\0"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_MainWindow[] = {

 // content:
       7,       // revision
       0,       // classname
       0,    0, // classinfo
       9,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    0,   59,    2, 0x05,

 // slots: name, argc, parameters, tag, flags
       3,    1,   60,    2, 0x08,
       6,    0,   63,    2, 0x08,
       7,    0,   64,    2, 0x08,
       8,    0,   65,    2, 0x08,
       9,    0,   66,    2, 0x08,
      10,    1,   67,    2, 0x08,
      12,    0,   70,    2, 0x08,
      13,    1,   71,    2, 0x08,

 // signals: parameters
    QMetaType::Bool,

 // slots: parameters
    QMetaType::Void, 0x80000000 | 4,    5,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void,
    QMetaType::Void, QMetaType::QString,   11,
    QMetaType::Void,
    QMetaType::Bool, QMetaType::QString,   14,

       0        // eod
};

void MainWindow::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        MainWindow *_t = static_cast<MainWindow *>(_o);
        switch (_id) {
        case 0: { bool _r = _t->addQ();
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        case 1: _t->on_tableWidget_itemDoubleClicked((*reinterpret_cast< QTableWidgetItem*(*)>(_a[1]))); break;
        case 2: _t->on_alfaButton_clicked(); break;
        case 3: _t->on_perButton_clicked(); break;
        case 4: _t->on_eventsButton_clicked(); break;
        case 5: _t->on_totalButton_clicked(); break;
        case 6: _t->on_searchBar_textChanged((*reinterpret_cast< const QString(*)>(_a[1]))); break;
        case 7: _t->on_addCurriculoButton_triggered(); break;
        case 8: { bool _r = _t->on_go((*reinterpret_cast< QString(*)>(_a[1])));
            if (_a[0]) *reinterpret_cast< bool*>(_a[0]) = _r; }  break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        void **func = reinterpret_cast<void **>(_a[1]);
        {
            typedef bool (MainWindow::*_t)();
            if (*reinterpret_cast<_t *>(func) == static_cast<_t>(&MainWindow::addQ)) {
                *result = 0;
            }
        }
    }
}

const QMetaObject MainWindow::staticMetaObject = {
    { &QMainWindow::staticMetaObject, qt_meta_stringdata_MainWindow.data,
      qt_meta_data_MainWindow,  qt_static_metacall, 0, 0}
};


const QMetaObject *MainWindow::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *MainWindow::qt_metacast(const char *_clname)
{
    if (!_clname) return 0;
    if (!strcmp(_clname, qt_meta_stringdata_MainWindow.stringdata))
        return static_cast<void*>(const_cast< MainWindow*>(this));
    return QMainWindow::qt_metacast(_clname);
}

int MainWindow::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QMainWindow::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 9)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 9;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 9)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 9;
    }
    return _id;
}

// SIGNAL 0
bool MainWindow::addQ()
{
    bool _t0 = bool();
    void *_a[] = { const_cast<void*>(reinterpret_cast<const void*>(&_t0)) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
    return _t0;
}
QT_END_MOC_NAMESPACE
