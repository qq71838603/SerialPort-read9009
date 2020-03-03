/********************************************************************************
** Form generated from reading UI file 'powerdown.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_POWERDOWN_H
#define UI_POWERDOWN_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_powerdown
{
public:
    QPushButton *Apowerdown;
    QComboBox *comboBox;
    QPushButton *query_button;

    void setupUi(QWidget *powerdown)
    {
        if (powerdown->objectName().isEmpty())
            powerdown->setObjectName(QString::fromUtf8("powerdown"));
        powerdown->resize(213, 237);
        Apowerdown = new QPushButton(powerdown);
        Apowerdown->setObjectName(QString::fromUtf8("Apowerdown"));
        Apowerdown->setGeometry(QRect(10, 10, 191, 23));
        comboBox = new QComboBox(powerdown);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));
        query_button = new QPushButton(powerdown);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 210, 75, 23));

        retranslateUi(powerdown);

        QMetaObject::connectSlotsByName(powerdown);
    } // setupUi

    void retranslateUi(QWidget *powerdown)
    {
        powerdown->setWindowTitle(QCoreApplication::translate("powerdown", "Form", nullptr));
        Apowerdown->setText(QCoreApplication::translate("powerdown", "\346\216\211\347\224\265\346\200\273\346\254\241\346\225\260", nullptr));
        query_button->setText(QCoreApplication::translate("powerdown", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class powerdown: public Ui_powerdown {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_POWERDOWN_H
