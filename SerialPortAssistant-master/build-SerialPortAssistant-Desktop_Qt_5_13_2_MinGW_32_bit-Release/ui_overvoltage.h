/********************************************************************************
** Form generated from reading UI file 'overvoltage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERVOLTAGE_H
#define UI_OVERVOLTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Overvoltage
{
public:
    QPushButton *ABCOvervoltage;
    QPushButton *query_button;
    QComboBox *comboBox;
    QComboBox *comboBox_2;
    QPushButton *query_button_2;

    void setupUi(QWidget *Overvoltage)
    {
        if (Overvoltage->objectName().isEmpty())
            Overvoltage->setObjectName(QString::fromUtf8("Overvoltage"));
        Overvoltage->resize(209, 249);
        ABCOvervoltage = new QPushButton(Overvoltage);
        ABCOvervoltage->setObjectName(QString::fromUtf8("ABCOvervoltage"));
        ABCOvervoltage->setGeometry(QRect(10, 10, 191, 23));
        query_button = new QPushButton(Overvoltage);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 220, 75, 23));
        comboBox = new QComboBox(Overvoltage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 191, 22));
        comboBox_2 = new QComboBox(Overvoltage);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(200, 180, 191, 22));
        query_button_2 = new QPushButton(Overvoltage);
        query_button_2->setObjectName(QString::fromUtf8("query_button_2"));
        query_button_2->setGeometry(QRect(320, 350, 75, 23));

        retranslateUi(Overvoltage);

        QMetaObject::connectSlotsByName(Overvoltage);
    } // setupUi

    void retranslateUi(QWidget *Overvoltage)
    {
        Overvoltage->setWindowTitle(QCoreApplication::translate("Overvoltage", "Form", nullptr));
        ABCOvervoltage->setText(QCoreApplication::translate("Overvoltage", "A,B,C,\347\233\270\350\277\207\345\216\213\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("Overvoltage", "\346\237\245\350\257\242", nullptr));
        query_button_2->setText(QCoreApplication::translate("Overvoltage", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class Overvoltage: public Ui_Overvoltage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERVOLTAGE_H
