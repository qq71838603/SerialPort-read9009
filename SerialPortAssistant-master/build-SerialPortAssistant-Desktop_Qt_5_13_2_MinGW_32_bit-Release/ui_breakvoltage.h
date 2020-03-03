/********************************************************************************
** Form generated from reading UI file 'breakvoltage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKVOLTAGE_H
#define UI_BREAKVOLTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_breakvoltage
{
public:
    QPushButton *ABCbreakvoltage;
    QPushButton *query_button;
    QComboBox *comboBox;

    void setupUi(QWidget *breakvoltage)
    {
        if (breakvoltage->objectName().isEmpty())
            breakvoltage->setObjectName(QString::fromUtf8("breakvoltage"));
        breakvoltage->resize(239, 280);
        ABCbreakvoltage = new QPushButton(breakvoltage);
        ABCbreakvoltage->setObjectName(QString::fromUtf8("ABCbreakvoltage"));
        ABCbreakvoltage->setGeometry(QRect(10, 10, 221, 23));
        query_button = new QPushButton(breakvoltage);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(160, 250, 75, 23));
        comboBox = new QComboBox(breakvoltage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 221, 22));

        retranslateUi(breakvoltage);

        QMetaObject::connectSlotsByName(breakvoltage);
    } // setupUi

    void retranslateUi(QWidget *breakvoltage)
    {
        breakvoltage->setWindowTitle(QCoreApplication::translate("breakvoltage", "Form", nullptr));
        ABCbreakvoltage->setText(QCoreApplication::translate("breakvoltage", "A,B,C\347\233\270\346\226\255\347\233\270\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("breakvoltage", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class breakvoltage: public Ui_breakvoltage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKVOLTAGE_H
