/********************************************************************************
** Form generated from reading UI file 'undervoltage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_UNDERVOLTAGE_H
#define UI_UNDERVOLTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Undervoltage
{
public:
    QComboBox *comboBox;
    QPushButton *query_button;
    QPushButton *ABCUndervoltage;

    void setupUi(QWidget *Undervoltage)
    {
        if (Undervoltage->objectName().isEmpty())
            Undervoltage->setObjectName(QString::fromUtf8("Undervoltage"));
        Undervoltage->resize(220, 262);
        comboBox = new QComboBox(Undervoltage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(20, 50, 191, 22));
        query_button = new QPushButton(Undervoltage);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(140, 230, 75, 23));
        ABCUndervoltage = new QPushButton(Undervoltage);
        ABCUndervoltage->setObjectName(QString::fromUtf8("ABCUndervoltage"));
        ABCUndervoltage->setGeometry(QRect(20, 10, 191, 23));

        retranslateUi(Undervoltage);

        QMetaObject::connectSlotsByName(Undervoltage);
    } // setupUi

    void retranslateUi(QWidget *Undervoltage)
    {
        Undervoltage->setWindowTitle(QCoreApplication::translate("Undervoltage", "Form", nullptr));
        query_button->setText(QCoreApplication::translate("Undervoltage", "\346\237\245\350\257\242", nullptr));
        ABCUndervoltage->setText(QCoreApplication::translate("Undervoltage", "A,B,C\347\233\270\346\254\240\345\216\213\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Undervoltage: public Ui_Undervoltage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_UNDERVOLTAGE_H
