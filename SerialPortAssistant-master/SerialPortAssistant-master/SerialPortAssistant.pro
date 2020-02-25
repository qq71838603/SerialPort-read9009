#-------------------------------------------------
#
# Project created by QtCreator 2016-12-22T18:18:24
#
#-------------------------------------------------

QT       += core gui serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SerialPortAssistant
TEMPLATE = app


SOURCES += main.cpp\
        serialportassistant.cpp \
    helpdialog.cpp \
    event_log.cpp \
    loss_pressure.cpp \
    undervoltage.cpp

HEADERS  += serialportassistant.h \
    helpdialog.h \
    event_log.h \
    loss_pressure.h \
    undervoltage.h

FORMS    += serialportassistant.ui \
    event_log.ui \
    loss_pressure.ui \
    undervoltage.ui

CONFIG += c++11

RESOURCES += \
    rsc.qrc
