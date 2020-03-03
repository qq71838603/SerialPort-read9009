/********************************************************************************
** Form generated from reading UI file 'voltageimbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_VOLTAGEIMBALANCE_H
#define UI_VOLTAGEIMBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_voltageimbalance
{
public:
    QPushButton *Avoltageimbalance;
    QPushButton *query_button;
    QComboBox *comboBox;

    void setupUi(QWidget *voltageimbalance)
    {
        if (voltageimbalance->objectName().isEmpty())
            voltageimbalance->setObjectName(QString::fromUtf8("voltageimbalance"));
        voltageimbalance->resize(209, 247);
        Avoltageimbalance = new QPushButton(voltageimbalance);
        Avoltageimbalance->setObjectName(QString::fromUtf8("Avoltageimbalance"));
        Avoltageimbalance->setGeometry(QRect(10, 10, 191, 23));
        query_button = new QPushButton(voltageimbalance);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 220, 75, 23));
        comboBox = new QComboBox(voltageimbalance);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));

        retranslateUi(voltageimbalance);

        QMetaObject::connectSlotsByName(voltageimbalance);
    } // setupUi

    void retranslateUi(QWidget *voltageimbalance)
    {
        voltageimbalance->setWindowTitle(QCoreApplication::translate("voltageimbalance", "Form", nullptr));
        Avoltageimbalance->setText(QCoreApplication::translate("voltageimbalance", "\347\224\265\345\216\213\344\270\215\345\271\263\350\241\241\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("voltageimbalance", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class voltageimbalance: public Ui_voltageimbalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_VOLTAGEIMBALANCE_H
