/********************************************************************************
** Form generated from reading UI file 'event_log.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EVENT_LOG_H
#define UI_EVENT_LOG_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Event_log
{
public:
    QWidget *layoutWidget;
    QGridLayout *gridLayout;
    QPushButton *pushButton;
    QPushButton *voltageimbalance;
    QPushButton *Undervoltage;
    QPushButton *currentimbalance;
    QPushButton *Overvoltage;
    QPushButton *qualified_rateofvoltage;
    QPushButton *breakvoltage;
    QPushButton *overload;
    QPushButton *powerdown;
    QPushButton *overcurrent;
    QPushButton *breakcurrent;
    QPushButton *losscurrent;

    void setupUi(QWidget *Event_log)
    {
        if (Event_log->objectName().isEmpty())
            Event_log->setObjectName(QString::fromUtf8("Event_log"));
        Event_log->resize(302, 223);
        layoutWidget = new QWidget(Event_log);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(10, 10, 281, 201));
        gridLayout = new QGridLayout(layoutWidget);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        pushButton = new QPushButton(layoutWidget);
        pushButton->setObjectName(QString::fromUtf8("pushButton"));

        gridLayout->addWidget(pushButton, 0, 0, 1, 1);

        voltageimbalance = new QPushButton(layoutWidget);
        voltageimbalance->setObjectName(QString::fromUtf8("voltageimbalance"));

        gridLayout->addWidget(voltageimbalance, 0, 2, 1, 1);

        Undervoltage = new QPushButton(layoutWidget);
        Undervoltage->setObjectName(QString::fromUtf8("Undervoltage"));

        gridLayout->addWidget(Undervoltage, 1, 0, 1, 1);

        currentimbalance = new QPushButton(layoutWidget);
        currentimbalance->setObjectName(QString::fromUtf8("currentimbalance"));

        gridLayout->addWidget(currentimbalance, 1, 2, 1, 1);

        Overvoltage = new QPushButton(layoutWidget);
        Overvoltage->setObjectName(QString::fromUtf8("Overvoltage"));

        gridLayout->addWidget(Overvoltage, 2, 0, 1, 1);

        qualified_rateofvoltage = new QPushButton(layoutWidget);
        qualified_rateofvoltage->setObjectName(QString::fromUtf8("qualified_rateofvoltage"));

        gridLayout->addWidget(qualified_rateofvoltage, 2, 2, 1, 1);

        breakvoltage = new QPushButton(layoutWidget);
        breakvoltage->setObjectName(QString::fromUtf8("breakvoltage"));

        gridLayout->addWidget(breakvoltage, 3, 0, 1, 1);

        overload = new QPushButton(layoutWidget);
        overload->setObjectName(QString::fromUtf8("overload"));

        gridLayout->addWidget(overload, 3, 1, 1, 1);

        powerdown = new QPushButton(layoutWidget);
        powerdown->setObjectName(QString::fromUtf8("powerdown"));

        gridLayout->addWidget(powerdown, 3, 2, 1, 1);

        overcurrent = new QPushButton(layoutWidget);
        overcurrent->setObjectName(QString::fromUtf8("overcurrent"));

        gridLayout->addWidget(overcurrent, 1, 1, 1, 1);

        breakcurrent = new QPushButton(layoutWidget);
        breakcurrent->setObjectName(QString::fromUtf8("breakcurrent"));

        gridLayout->addWidget(breakcurrent, 2, 1, 1, 1);

        losscurrent = new QPushButton(layoutWidget);
        losscurrent->setObjectName(QString::fromUtf8("losscurrent"));

        gridLayout->addWidget(losscurrent, 0, 1, 1, 1);


        retranslateUi(Event_log);

        QMetaObject::connectSlotsByName(Event_log);
    } // setupUi

    void retranslateUi(QWidget *Event_log)
    {
        Event_log->setWindowTitle(QCoreApplication::translate("Event_log", "Form", nullptr));
        pushButton->setText(QCoreApplication::translate("Event_log", "\345\244\261\345\216\213\350\256\260\345\275\225", nullptr));
        voltageimbalance->setText(QCoreApplication::translate("Event_log", "\347\224\265\345\216\213\344\270\215\345\271\263\350\241\241\350\256\260\345\275\225", nullptr));
        Undervoltage->setText(QCoreApplication::translate("Event_log", "\346\254\240\345\216\213\350\256\260\345\275\225", nullptr));
        currentimbalance->setText(QCoreApplication::translate("Event_log", "\347\224\265\346\265\201\344\270\215\345\271\263\350\241\241\350\256\260\345\275\225", nullptr));
        Overvoltage->setText(QCoreApplication::translate("Event_log", "\350\277\207\345\216\213\350\256\260\345\275\225", nullptr));
        qualified_rateofvoltage->setText(QCoreApplication::translate("Event_log", "\347\224\265\345\216\213\345\220\210\346\240\274\347\216\207\350\256\260\345\275\225", nullptr));
        breakvoltage->setText(QCoreApplication::translate("Event_log", "\346\226\255\347\233\270\350\256\260\345\275\225", nullptr));
        overload->setText(QCoreApplication::translate("Event_log", "\350\277\207\350\275\275\350\256\260\345\275\225", nullptr));
        powerdown->setText(QCoreApplication::translate("Event_log", "\346\216\211\347\224\265\350\256\260\345\275\225", nullptr));
        overcurrent->setText(QCoreApplication::translate("Event_log", "\350\277\207\346\265\201\350\256\260\345\275\225", nullptr));
        breakcurrent->setText(QCoreApplication::translate("Event_log", "\346\226\255\346\265\201\350\256\260\345\275\225", nullptr));
        losscurrent->setText(QCoreApplication::translate("Event_log", "\345\244\261\346\265\201\350\256\260\345\275\225", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Event_log: public Ui_Event_log {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EVENT_LOG_H
