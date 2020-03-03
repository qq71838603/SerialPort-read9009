/********************************************************************************
** Form generated from reading UI file 'overcurrent.ui'
**
** Created by: Qt User Interface Compiler version 5.13.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OVERCURRENT_H
#define UI_OVERCURRENT_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_overcurrent
{
public:
    QPushButton *ABCovercurrent;
    QPushButton *query_button;
    QComboBox *comboBox;

    void setupUi(QWidget *overcurrent)
    {
        if (overcurrent->objectName().isEmpty())
            overcurrent->setObjectName(QString::fromUtf8("overcurrent"));
        overcurrent->resize(206, 246);
        ABCovercurrent = new QPushButton(overcurrent);
        ABCovercurrent->setObjectName(QString::fromUtf8("ABCovercurrent"));
        ABCovercurrent->setGeometry(QRect(10, 10, 191, 23));
        query_button = new QPushButton(overcurrent);
        query_button->setObjectName(QString::fromUtf8("query_button"));
        query_button->setGeometry(QRect(130, 220, 75, 23));
        comboBox = new QComboBox(overcurrent);
        comboBox->setObjectName(QString::fromUtf8("comboBox"));
        comboBox->setGeometry(QRect(10, 40, 191, 22));

        retranslateUi(overcurrent);

        QMetaObject::connectSlotsByName(overcurrent);
    } // setupUi

    void retranslateUi(QWidget *overcurrent)
    {
        overcurrent->setWindowTitle(QCoreApplication::translate("overcurrent", "Form", nullptr));
        ABCovercurrent->setText(QCoreApplication::translate("overcurrent", "A,B,C\347\233\270\350\277\207\346\265\201\346\200\273\346\254\241\346\225\260,\346\200\273\347\264\257\350\256\241\346\227\266\351\227\264", nullptr));
        query_button->setText(QCoreApplication::translate("overcurrent", "\346\237\245\350\257\242", nullptr));
    } // retranslateUi

};

namespace Ui {
    class overcurrent: public Ui_overcurrent {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OVERCURRENT_H
