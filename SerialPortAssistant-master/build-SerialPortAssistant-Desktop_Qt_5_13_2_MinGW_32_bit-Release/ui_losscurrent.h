/********************************************************************************
** Form generated from reading UI file 'losscurrent.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_LOSSCURRENT_H
#define UI_LOSSCURRENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_losscurrent
{
public:
    QPushButton *ABClosscurrent;
    QPushButton *query_button;
    QComboBox *comboBox;

    void setupUi(QWidget *losscurrent)
    {
        if (losscurrent->objectName().isEmpty())
            losscurrent->setObjectName(QString::fromUtf8("losscurrent"));
        losscurrent->resize(209, 260);
        ABClosscurrent = new QPushButton(losscurrent);
        ABClosscurrent->setObjectName(QString::fromUtf8("ABClosscurrent"));
        ABClosscurrent->setGeometry(QRect(10, 10, 191, 23));
        query_button = new QPushButton(losscurrent);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 230, 75, 23));
        comboBox = new QComboBox(losscurrent);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 50, 191, 22));

        retranslateUi(losscurrent);

        QMetaObject::connectSlotsByName(losscurrent);
    } // setupUi

    void retranslateUi(QWidget *losscurrent)
    {
        losscurrent->setWindowTitle(QCoreApplication::translate("losscurrent", "Form", nullptr));
        ABClosscurrent->setText(QCoreApplication::translate("losscurrent", "A,B,C\347\233\270\345\244\261\346\265\201\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("losscurrent", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class losscurrent: public Ui_losscurrent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_LOSSCURRENT_H
