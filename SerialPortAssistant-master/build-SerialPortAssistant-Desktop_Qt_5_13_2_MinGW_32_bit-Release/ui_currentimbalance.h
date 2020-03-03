/********************************************************************************
** Form generated from reading UI file 'currentimbalance.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CURRENTIMBALANCE_H
#define UI_CURRENTIMBALANCE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_currentimbalance
{
public:
    QPushButton *Acurrentimbalance;
    QComboBox *comboBox;
    QPushButton *query_button;

    void setupUi(QWidget *currentimbalance)
    {
        if (currentimbalance->objectName().isEmpty())
            currentimbalance->setObjectName(QString::fromUtf8("currentimbalance"));
        currentimbalance->resize(210, 249);
        Acurrentimbalance = new QPushButton(currentimbalance);
        Acurrentimbalance->setObjectName(QString::fromUtf8("Acurrentimbalance"));
        Acurrentimbalance->setGeometry(QRect(10, 10, 191, 23));
        comboBox = new QComboBox(currentimbalance);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));
        query_button = new QPushButton(currentimbalance);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 220, 75, 23));

        retranslateUi(currentimbalance);

        QMetaObject::connectSlotsByName(currentimbalance);
    } // setupUi

    void retranslateUi(QWidget *currentimbalance)
    {
        currentimbalance->setWindowTitle(QCoreApplication::translate("currentimbalance", "Form", nullptr));
        Acurrentimbalance->setText(QCoreApplication::translate("currentimbalance", "\347\224\265\346\265\201\344\270\215\345\271\263\350\241\241\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("currentimbalance", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class currentimbalance: public Ui_currentimbalance {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CURRENTIMBALANCE_H
