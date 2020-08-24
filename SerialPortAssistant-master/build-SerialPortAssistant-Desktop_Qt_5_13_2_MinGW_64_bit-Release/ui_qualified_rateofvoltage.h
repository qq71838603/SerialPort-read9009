/********************************************************************************
** Form generated from reading UI file 'qualified_rateofvoltage.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_QUALIFIED_RATEOFVOLTAGE_H
#define UI_QUALIFIED_RATEOFVOLTAGE_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_qualified_rateofvoltage
{
public:
    QPushButton *query_button;
    QComboBox *comboBox;
    QPushButton *query_button_2;
    QComboBox *comboBox_2;

    void setupUi(QWidget *qualified_rateofvoltage)
    {
        if (qualified_rateofvoltage->objectName().isEmpty())
            qualified_rateofvoltage->setObjectName(QString::fromUtf8("qualified_rateofvoltage"));
        qualified_rateofvoltage->resize(248, 361);
        query_button = new QPushButton(qualified_rateofvoltage);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(170, 330, 75, 23));
        comboBox = new QComboBox(qualified_rateofvoltage);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 190, 231, 22));
        query_button_2 = new QPushButton(qualified_rateofvoltage);
        query_button_2->setObjectName(QString::fromUtf8("query_button_2"));
        query_button_2->setGeometry(QRect(170, 160, 75, 23));
        comboBox_2 = new QComboBox(qualified_rateofvoltage);
        comboBox_2->setObjectName(QString::fromUtf8("comboBox_2"));
        comboBox_2->setGeometry(QRect(10, 10, 231, 22));

        retranslateUi(qualified_rateofvoltage);

        QMetaObject::connectSlotsByName(qualified_rateofvoltage);
    } // setupUi

    void retranslateUi(QWidget *qualified_rateofvoltage)
    {
        qualified_rateofvoltage->setWindowTitle(QCoreApplication::translate("qualified_rateofvoltage", "Form", nullptr));
        query_button->setText(QCoreApplication::translate("qualified_rateofvoltage", "\346\237\245\350\257\242", nullptr));
        query_button_2->setText(QCoreApplication::translate("qualified_rateofvoltage", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class qualified_rateofvoltage: public Ui_qualified_rateofvoltage {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_QUALIFIED_RATEOFVOLTAGE_H
