/****************************************************************************
** Meta object code from reading C++ file 'event_log.h'
**
** Created by: The Qt Meta Object Compiler version 67 (Qt 5.13.2)
**
** WARNING! All changes made in this file will be lost!
*****************************************************************************/

#include <memory>
#include "../../SerialPortAssistant-master/event_log/event_log.h"
#include <QtCore/qbytearray.h>
#include <QtCore/qmetatype.h>
#if !defined(Q_MOC_OUTPUT_REVISION)
#error "The header file 'event_log.h' doesn't include <QObject>."
#elif Q_MOC_OUTPUT_REVISION != 67
#error "This file was generated using the moc from 5.13.2. It"
#error "cannot be used with the include files from this version of Qt."
#error "(The moc has changed too much.)"
#endif

QT_BEGIN_MOC_NAMESPACE
QT_WARNING_PUSH
QT_WARNING_DISABLE_DEPRECATED
struct qt_meta_stringdata_Event_log_t {
    QByteArrayData data[16];
    char stringdata0[328];
};
#define QT_MOC_LITERAL(idx, ofs, len) \
    Q_STATIC_BYTE_ARRAY_DATA_HEADER_INITIALIZER_WITH_OFFSET(len, \
    qptrdiff(offsetof(qt_meta_stringdata_Event_log_t, stringdata0) + ofs \
        - idx * sizeof(QByteArrayData)) \
    )
static const qt_meta_stringdata_Event_log_t qt_meta_stringdata_Event_log = {
    {
QT_MOC_LITERAL(0, 0, 9), // "Event_log"
QT_MOC_LITERAL(1, 10, 8), // "sendData"
QT_MOC_LITERAL(2, 19, 0), // ""
QT_MOC_LITERAL(3, 20, 12), // "SendRecvData"
QT_MOC_LITERAL(4, 33, 21), // "on_pushButton_clicked"
QT_MOC_LITERAL(5, 55, 23), // "on_Undervoltage_clicked"
QT_MOC_LITERAL(6, 79, 22), // "on_Overvoltage_clicked"
QT_MOC_LITERAL(7, 102, 23), // "on_breakvoltage_clicked"
QT_MOC_LITERAL(8, 126, 27), // "on_voltageimbalance_clicked"
QT_MOC_LITERAL(9, 154, 27), // "on_currentimbalance_clicked"
QT_MOC_LITERAL(10, 182, 22), // "on_losscurrent_clicked"
QT_MOC_LITERAL(11, 205, 22), // "on_overcurrent_clicked"
QT_MOC_LITERAL(12, 228, 23), // "on_breakcurrent_clicked"
QT_MOC_LITERAL(13, 252, 19), // "on_overload_clicked"
QT_MOC_LITERAL(14, 272, 34), // "on_qualified_rateofvoltage_cl..."
QT_MOC_LITERAL(15, 307, 20) // "on_powerdown_clicked"

    },
    "Event_log\0sendData\0\0SendRecvData\0"
    "on_pushButton_clicked\0on_Undervoltage_clicked\0"
    "on_Overvoltage_clicked\0on_breakvoltage_clicked\0"
    "on_voltageimbalance_clicked\0"
    "on_currentimbalance_clicked\0"
    "on_losscurrent_clicked\0on_overcurrent_clicked\0"
    "on_breakcurrent_clicked\0on_overload_clicked\0"
    "on_qualified_rateofvoltage_clicked\0"
    "on_powerdown_clicked"
};
#undef QT_MOC_LITERAL

static const uint qt_meta_data_Event_log[] = {

 // content:
       8,       // revision
       0,       // classname
       0,    0, // classinfo
      14,   14, // methods
       0,    0, // properties
       0,    0, // enums/sets
       0,    0, // constructors
       0,       // flags
       1,       // signalCount

 // signals: name, argc, parameters, tag, flags
       1,    2,   84,    2, 0x06 /* Public */,

 // slots: name, argc, parameters, tag, flags
       3,    2,   89,    2, 0x08 /* Private */,
       4,    0,   94,    2, 0x08 /* Private */,
       5,    0,   95,    2, 0x08 /* Private */,
       6,    0,   96,    2, 0x08 /* Private */,
       7,    0,   97,    2, 0x08 /* Private */,
       8,    0,   98,    2, 0x08 /* Private */,
       9,    0,   99,    2, 0x08 /* Private */,
      10,    0,  100,    2, 0x08 /* Private */,
      11,    0,  101,    2, 0x08 /* Private */,
      12,    0,  102,    2, 0x08 /* Private */,
      13,    0,  103,    2, 0x08 /* Private */,
      14,    0,  104,    2, 0x08 /* Private */,
      15,    0,  105,    2, 0x08 /* Private */,

 // signals: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,

 // slots: parameters
    QMetaType::Void, QMetaType::QString, QMetaType::QString,    2,    2,
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
    QMetaType::Void,

       0        // eod
};

void Event_log::qt_static_metacall(QObject *_o, QMetaObject::Call _c, int _id, void **_a)
{
    if (_c == QMetaObject::InvokeMetaMethod) {
        auto *_t = static_cast<Event_log *>(_o);
        Q_UNUSED(_t)
        switch (_id) {
        case 0: _t->sendData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 1: _t->SendRecvData((*reinterpret_cast< QString(*)>(_a[1])),(*reinterpret_cast< QString(*)>(_a[2]))); break;
        case 2: _t->on_pushButton_clicked(); break;
        case 3: _t->on_Undervoltage_clicked(); break;
        case 4: _t->on_Overvoltage_clicked(); break;
        case 5: _t->on_breakvoltage_clicked(); break;
        case 6: _t->on_voltageimbalance_clicked(); break;
        case 7: _t->on_currentimbalance_clicked(); break;
        case 8: _t->on_losscurrent_clicked(); break;
        case 9: _t->on_overcurrent_clicked(); break;
        case 10: _t->on_breakcurrent_clicked(); break;
        case 11: _t->on_overload_clicked(); break;
        case 12: _t->on_qualified_rateofvoltage_clicked(); break;
        case 13: _t->on_powerdown_clicked(); break;
        default: ;
        }
    } else if (_c == QMetaObject::IndexOfMethod) {
        int *result = reinterpret_cast<int *>(_a[0]);
        {
            using _t = void (Event_log::*)(QString , QString );
            if (*reinterpret_cast<_t *>(_a[1]) == static_cast<_t>(&Event_log::sendData)) {
                *result = 0;
                return;
            }
        }
    }
}

QT_INIT_METAOBJECT const QMetaObject Event_log::staticMetaObject = { {
    &QWidget::staticMetaObject,
    qt_meta_stringdata_Event_log.data,
    qt_meta_data_Event_log,
    qt_static_metacall,
    nullptr,
    nullptr
} };


const QMetaObject *Event_log::metaObject() const
{
    return QObject::d_ptr->metaObject ? QObject::d_ptr->dynamicMetaObject() : &staticMetaObject;
}

void *Event_log::qt_metacast(const char *_clname)
{
    if (!_clname) return nullptr;
    if (!strcmp(_clname, qt_meta_stringdata_Event_log.stringdata0))
        return static_cast<void*>(this);
    return QWidget::qt_metacast(_clname);
}

int Event_log::qt_metacall(QMetaObject::Call _c, int _id, void **_a)
{
    _id = QWidget::qt_metacall(_c, _id, _a);
    if (_id < 0)
        return _id;
    if (_c == QMetaObject::InvokeMetaMethod) {
        if (_id < 14)
            qt_static_metacall(this, _c, _id, _a);
        _id -= 14;
    } else if (_c == QMetaObject::RegisterMethodArgumentMetaType) {
        if (_id < 14)
            *reinterpret_cast<int*>(_a[0]) = -1;
        _id -= 14;
    }
    return _id;
}

// SIGNAL 0
void Event_log::sendData(QString _t1, QString _t2)
{
    void *_a[] = { nullptr, const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t1))), const_cast<void*>(reinterpret_cast<const void*>(std::addressof(_t2))) };
    QMetaObject::activate(this, &staticMetaObject, 0, _a);
}
QT_WARNING_POP
QT_END_MOC_NAMESPACE
