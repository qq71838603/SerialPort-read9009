/********************************************************************************
** Form generated from reading UI file 'overload.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERLOAD_H
#define UI_OVERLOAD_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_overload
{
public:
    QPushButton *ABCoverload;
    QComboBox *comboBox;
    QPushButton *query_button;

    void setupUi(QWidget *overload)
    {
        if (overload->objectName().isEmpty())
            overload->setObjectName(QString::fromUtf8("overload"));
        overload->resize(200, 240);
        ABCoverload = new QPushButton(overload);
        ABCoverload->setObjectName(QString::fromUtf8("ABCoverload"));
        ABCoverload->setGeometry(QRect(0, 10, 191, 23));
        comboBox = new QComboBox(overload);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(0, 40, 191, 22));
        query_button = new QPushButton(overload);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(120, 210, 75, 23));

        retranslateUi(overload);

        QMetaObject::connectSlotsByName(overload);
    } // setupUi

    void retranslateUi(QWidget *overload)
    {
        overload->setWindowTitle(QCoreApplication::translate("overload", "Form", nullptr));
        ABCoverload->setText(QCoreApplication::translate("overload", "A,B,C\347\233\270\350\277\207\350\275\275\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("overload", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class overload: public Ui_overload {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERLOAD_H
