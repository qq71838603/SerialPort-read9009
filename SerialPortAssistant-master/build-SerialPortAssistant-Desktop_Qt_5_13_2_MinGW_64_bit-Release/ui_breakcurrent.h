/********************************************************************************
** Form generated from reading UI file 'breakcurrent.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_BREAKCURRENT_H
#define UI_BREAKCURRENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_breakcurrent
{
public:
    QPushButton *ABCbreakcurrent;
    QPushButton *query_button;
    QComboBox *comboBox;

    void setupUi(QWidget *breakcurrent)
    {
        if (breakcurrent->objectName().isEmpty())
            breakcurrent->setObjectName(QString::fromUtf8("breakcurrent"));
        breakcurrent->resize(210, 248);
        ABCbreakcurrent = new QPushButton(breakcurrent);
        ABCbreakcurrent->setObjectName(QString::fromUtf8("ABCbreakcurrent"));
        ABCbreakcurrent->setGeometry(QRect(10, 10, 191, 23));
        query_button = new QPushButton(breakcurrent);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 220, 75, 23));
        comboBox = new QComboBox(breakcurrent);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));

        retranslateUi(breakcurrent);

        QMetaObject::connectSlotsByName(breakcurrent);
    } // setupUi

    void retranslateUi(QWidget *breakcurrent)
    {
        breakcurrent->setWindowTitle(QCoreApplication::translate("breakcurrent", "Form", nullptr));
        ABCbreakcurrent->setText(QCoreApplication::translate("breakcurrent", "A,B,C\347\233\270\346\226\255\346\265\201\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("breakcurrent", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class breakcurrent: public Ui_breakcurrent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_BREAKCURRENT_H
