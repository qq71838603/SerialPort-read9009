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
    event_log/event_log.cpp \
    event/loss_pressure.cpp \
    event/undervoltage.cpp \
    event/overvoltage.cpp \
    event/breakvoltage.cpp \
    event/voltageimbalance.cpp \
    event/currentimbalance.cpp \
    event/losscurrent.cpp \
    event/overcurrent.cpp \
    event/breakcurrent.cpp \
    event/overload.cpp \
    event/qualified_rateofvoltage.cpp \
    event/powerdown.cpp

HEADERS  += serialportassistant.h \
    helpdialog.h \
    event_log/event_log.h \
    event/loss_pressure.h \
    event/undervoltage.h \
    event/overvoltage.h \
    event/breakvoltage.h \
    event/voltageimbalance.h \
    event/currentimbalance.h \
    event/losscurrent.h \
    event/overcurrent.h \
    event/breakcurrent.h \
    event/overload.h \
    event/qualified_rateofvoltage.h \
    event/powerdown.h

FORMS    += serialportassistant.ui \
    event_log/event_log.ui \
    event/loss_pressure.ui \
    event/undervoltage.ui \
    event/overvoltage.ui \
    event/breakvoltage.ui \
    event/voltageimbalance.ui \
    event/currentimbalance.ui \
    event/losscurrent.ui \
    event/overcurrent.ui \
    event/breakcurrent.ui \
    event/overload.ui \
    event/qualified_rateofvoltage.ui \
    event/powerdown.ui

CONFIG += c++11

RESOURCES += \
    rsc.qrc
