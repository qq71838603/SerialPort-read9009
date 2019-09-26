/********************************************************************************
** Form generated from reading UI file 'serialportassistant.ui'
**
** Created by: Qt User Interface Compiler version 5.12.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORTASSISTANT_H
#define UI_SERIALPORTASSISTANT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPlainTextEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SerialPortAssistant
{
public:
    QAction *actionOpenFile;
    QAction *actionExit;
    QAction *actionHelp;
    QAction *actionAbout;
    QAction *actionQt;
    QAction *actionSaveFile;
    QWidget *centralWidget;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *basicSetting;
    QGridLayout *gridLayout;
    QPushButton *Get_Active_Electric;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBaudRate;
    QComboBox *baudRate;
    QPushButton *serialPortSwitch;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelDataBits;
    QComboBox *dataBits;
    QPushButton *pushButton_2;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParity;
    QComboBox *parity;
    QPushButton *pushButton_3;
    QPushButton *pushButton_4;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSerialPortNumber;
    QComboBox *serialPortNumber;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStopBits;
    QComboBox *stopBits;
    QSpacerItem *verticalSpacer;
    QPushButton *pushButton_5;
    QGroupBox *extraSetting;
    QGridLayout *gridLayout_2;
    QCheckBox *showTime;
    QCheckBox *hexadecimaleReceive;
    QPushButton *sendFile;
    QCheckBox *doubleColor;
    QCheckBox *hexadecimalSend;
    QCheckBox *autoNewLine;
    QPushButton *clear;
    QVBoxLayout *verticalLayout_3;
    QTextEdit *dataDisplay;
    QHBoxLayout *horizontalLayout_8;
    QPlainTextEdit *dataToSend;
    QVBoxLayout *verticalLayout_2;
    QPushButton *send;
    QGroupBox *loopSetting;
    QGridLayout *gridLayout_3;
    QCheckBox *loop;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelDelay;
    QLineEdit *delay;
    QLabel *labelMs;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelTimes;
    QLineEdit *times;
    QLabel *label;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menu_F;
    QMenu *menu_H;

    void setupUi(QMainWindow *SerialPortAssistant)
    {
        if (SerialPortAssistant->objectName().isEmpty())
            SerialPortAssistant->setObjectName(QString::fromUtf8("SerialPortAssistant"));
        SerialPortAssistant->resize(842, 607);
        actionOpenFile = new QAction(SerialPortAssistant);
        actionOpenFile->setObjectName(QString::fromUtf8("actionOpenFile"));
        actionExit = new QAction(SerialPortAssistant);
        actionExit->setObjectName(QString::fromUtf8("actionExit"));
        actionHelp = new QAction(SerialPortAssistant);
        actionHelp->setObjectName(QString::fromUtf8("actionHelp"));
        actionAbout = new QAction(SerialPortAssistant);
        actionAbout->setObjectName(QString::fromUtf8("actionAbout"));
        actionQt = new QAction(SerialPortAssistant);
        actionQt->setObjectName(QString::fromUtf8("actionQt"));
        actionSaveFile = new QAction(SerialPortAssistant);
        actionSaveFile->setObjectName(QString::fromUtf8("actionSaveFile"));
        centralWidget = new QWidget(SerialPortAssistant);
        centralWidget->setObjectName(QString::fromUtf8("centralWidget"));
        gridLayout_4 = new QGridLayout(centralWidget);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QString::fromUtf8("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setSpacing(6);
        verticalLayout->setObjectName(QString::fromUtf8("verticalLayout"));
        basicSetting = new QGroupBox(centralWidget);
        basicSetting->setObjectName(QString::fromUtf8("basicSetting"));
        basicSetting->setMinimumSize(QSize(200, 0));
        basicSetting->setMaximumSize(QSize(200, 16777215));
        basicSetting->setFlat(false);
        gridLayout = new QGridLayout(basicSetting);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        Get_Active_Electric = new QPushButton(basicSetting);
        Get_Active_Electric->setObjectName(QString::fromUtf8("Get_Active_Electric"));

        gridLayout->addWidget(Get_Active_Electric, 6, 0, 1, 1);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelBaudRate = new QLabel(basicSetting);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        labelBaudRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelBaudRate);

        baudRate = new QComboBox(basicSetting);
        baudRate->setObjectName(QString::fromUtf8("baudRate"));
        baudRate->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(baudRate);


        gridLayout->addLayout(horizontalLayout_2, 1, 0, 1, 1);

        serialPortSwitch = new QPushButton(basicSetting);
        serialPortSwitch->setObjectName(QString::fromUtf8("serialPortSwitch"));
        serialPortSwitch->setMaximumSize(QSize(16777215, 16777215));

        gridLayout->addWidget(serialPortSwitch, 5, 0, 1, 1);

        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelDataBits = new QLabel(basicSetting);
        labelDataBits->setObjectName(QString::fromUtf8("labelDataBits"));
        labelDataBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelDataBits);

        dataBits = new QComboBox(basicSetting);
        dataBits->setObjectName(QString::fromUtf8("dataBits"));
        dataBits->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(dataBits);


        gridLayout->addLayout(horizontalLayout_3, 2, 0, 1, 1);

        pushButton_2 = new QPushButton(basicSetting);
        pushButton_2->setObjectName(QString::fromUtf8("pushButton_2"));

        gridLayout->addWidget(pushButton_2, 7, 0, 1, 1);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelParity = new QLabel(basicSetting);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelParity);

        parity = new QComboBox(basicSetting);
        parity->setObjectName(QString::fromUtf8("parity"));
        parity->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(parity);


        gridLayout->addLayout(horizontalLayout_4, 3, 0, 1, 1);

        pushButton_3 = new QPushButton(basicSetting);
        pushButton_3->setObjectName(QString::fromUtf8("pushButton_3"));

        gridLayout->addWidget(pushButton_3, 8, 0, 1, 1);

        pushButton_4 = new QPushButton(basicSetting);
        pushButton_4->setObjectName(QString::fromUtf8("pushButton_4"));

        gridLayout->addWidget(pushButton_4, 9, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelSerialPortNumber = new QLabel(basicSetting);
        labelSerialPortNumber->setObjectName(QString::fromUtf8("labelSerialPortNumber"));
        labelSerialPortNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelSerialPortNumber);

        serialPortNumber = new QComboBox(basicSetting);
        serialPortNumber->setObjectName(QString::fromUtf8("serialPortNumber"));
        serialPortNumber->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(serialPortNumber);


        gridLayout->addLayout(horizontalLayout, 0, 0, 1, 1);

        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelStopBits = new QLabel(basicSetting);
        labelStopBits->setObjectName(QString::fromUtf8("labelStopBits"));
        labelStopBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelStopBits);

        stopBits = new QComboBox(basicSetting);
        stopBits->setObjectName(QString::fromUtf8("stopBits"));
        stopBits->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(stopBits);


        gridLayout->addLayout(horizontalLayout_5, 4, 0, 1, 1);

        verticalSpacer = new QSpacerItem(20, 40, QSizePolicy::Minimum, QSizePolicy::Expanding);

        gridLayout->addItem(verticalSpacer, 11, 0, 1, 1);

        pushButton_5 = new QPushButton(basicSetting);
        pushButton_5->setObjectName(QString::fromUtf8("pushButton_5"));

        gridLayout->addWidget(pushButton_5, 10, 0, 1, 1);


        verticalLayout->addWidget(basicSetting);

        extraSetting = new QGroupBox(centralWidget);
        extraSetting->setObjectName(QString::fromUtf8("extraSetting"));
        extraSetting->setMinimumSize(QSize(200, 0));
        extraSetting->setMaximumSize(QSize(200, 16777215));
        gridLayout_2 = new QGridLayout(extraSetting);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QString::fromUtf8("gridLayout_2"));
        showTime = new QCheckBox(extraSetting);
        showTime->setObjectName(QString::fromUtf8("showTime"));

        gridLayout_2->addWidget(showTime, 2, 0, 1, 1);

        hexadecimaleReceive = new QCheckBox(extraSetting);
        hexadecimaleReceive->setObjectName(QString::fromUtf8("hexadecimaleReceive"));

        gridLayout_2->addWidget(hexadecimaleReceive, 3, 0, 1, 1);

        sendFile = new QPushButton(extraSetting);
        sendFile->setObjectName(QString::fromUtf8("sendFile"));

        gridLayout_2->addWidget(sendFile, 5, 0, 1, 1);

        doubleColor = new QCheckBox(extraSetting);
        doubleColor->setObjectName(QString::fromUtf8("doubleColor"));

        gridLayout_2->addWidget(doubleColor, 1, 0, 1, 1);

        hexadecimalSend = new QCheckBox(extraSetting);
        hexadecimalSend->setObjectName(QString::fromUtf8("hexadecimalSend"));

        gridLayout_2->addWidget(hexadecimalSend, 4, 0, 1, 1);

        autoNewLine = new QCheckBox(extraSetting);
        autoNewLine->setObjectName(QString::fromUtf8("autoNewLine"));

        gridLayout_2->addWidget(autoNewLine, 0, 0, 1, 1);

        clear = new QPushButton(extraSetting);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout_2->addWidget(clear, 6, 0, 1, 1);


        verticalLayout->addWidget(extraSetting);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        verticalLayout_3 = new QVBoxLayout();
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        dataDisplay = new QTextEdit(centralWidget);
        dataDisplay->setObjectName(QString::fromUtf8("dataDisplay"));
        dataDisplay->setReadOnly(true);

        verticalLayout_3->addWidget(dataDisplay);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        dataToSend = new QPlainTextEdit(centralWidget);
        dataToSend->setObjectName(QString::fromUtf8("dataToSend"));

        horizontalLayout_8->addWidget(dataToSend);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        send = new QPushButton(centralWidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(send);

        loopSetting = new QGroupBox(centralWidget);
        loopSetting->setObjectName(QString::fromUtf8("loopSetting"));
        loopSetting->setMaximumSize(QSize(150, 16777215));
        gridLayout_3 = new QGridLayout(loopSetting);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
        loop = new QCheckBox(loopSetting);
        loop->setObjectName(QString::fromUtf8("loop"));

        gridLayout_3->addWidget(loop, 0, 0, 1, 1);

        horizontalLayout_6 = new QHBoxLayout();
        horizontalLayout_6->setSpacing(6);
        horizontalLayout_6->setObjectName(QString::fromUtf8("horizontalLayout_6"));
        labelDelay = new QLabel(loopSetting);
        labelDelay->setObjectName(QString::fromUtf8("labelDelay"));
        labelDelay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(labelDelay);

        delay = new QLineEdit(loopSetting);
        delay->setObjectName(QString::fromUtf8("delay"));
        delay->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_6->addWidget(delay);

        labelMs = new QLabel(loopSetting);
        labelMs->setObjectName(QString::fromUtf8("labelMs"));

        horizontalLayout_6->addWidget(labelMs);


        gridLayout_3->addLayout(horizontalLayout_6, 1, 0, 1, 1);

        horizontalLayout_7 = new QHBoxLayout();
        horizontalLayout_7->setSpacing(6);
        horizontalLayout_7->setObjectName(QString::fromUtf8("horizontalLayout_7"));
        labelTimes = new QLabel(loopSetting);
        labelTimes->setObjectName(QString::fromUtf8("labelTimes"));
        labelTimes->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(labelTimes);

        times = new QLineEdit(loopSetting);
        times->setObjectName(QString::fromUtf8("times"));
        times->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_7->addWidget(times);

        label = new QLabel(loopSetting);
        label->setObjectName(QString::fromUtf8("label"));

        horizontalLayout_7->addWidget(label);


        gridLayout_3->addLayout(horizontalLayout_7, 2, 0, 1, 1);


        verticalLayout_2->addWidget(loopSetting);


        horizontalLayout_8->addLayout(verticalLayout_2);

        horizontalLayout_8->setStretch(0, 10);

        verticalLayout_3->addLayout(horizontalLayout_8);

        verticalLayout_3->setStretch(0, 10);
        verticalLayout_3->setStretch(1, 1);

        gridLayout_4->addLayout(verticalLayout_3, 0, 1, 1, 1);

        SerialPortAssistant->setCentralWidget(centralWidget);
        statusBar = new QStatusBar(SerialPortAssistant);
        statusBar->setObjectName(QString::fromUtf8("statusBar"));
        SerialPortAssistant->setStatusBar(statusBar);
        menuBar = new QMenuBar(SerialPortAssistant);
        menuBar->setObjectName(QString::fromUtf8("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 842, 23));
        menu_F = new QMenu(menuBar);
        menu_F->setObjectName(QString::fromUtf8("menu_F"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QString::fromUtf8("menu_H"));
        SerialPortAssistant->setMenuBar(menuBar);

        menuBar->addAction(menu_F->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menu_F->addAction(actionOpenFile);
        menu_F->addAction(actionSaveFile);
        menu_F->addSeparator();
        menu_F->addAction(actionExit);
        menu_H->addAction(actionHelp);
        menu_H->addAction(actionAbout);
        menu_H->addSeparator();
        menu_H->addAction(actionQt);

        retranslateUi(SerialPortAssistant);

        QMetaObject::connectSlotsByName(SerialPortAssistant);
    } // setupUi

    void retranslateUi(QMainWindow *SerialPortAssistant)
    {
        SerialPortAssistant->setWindowTitle(QApplication::translate("SerialPortAssistant", "SerialPortAssistant", nullptr));
        actionOpenFile->setText(QApplication::translate("SerialPortAssistant", "\346\211\223\345\274\200", nullptr));
#ifndef QT_NO_SHORTCUT
        actionOpenFile->setShortcut(QApplication::translate("SerialPortAssistant", "Ctrl+O", nullptr));
#endif // QT_NO_SHORTCUT
        actionExit->setText(QApplication::translate("SerialPortAssistant", "\351\200\200\345\207\272", nullptr));
#ifndef QT_NO_SHORTCUT
        actionExit->setShortcut(QApplication::translate("SerialPortAssistant", "Ctrl+Q", nullptr));
#endif // QT_NO_SHORTCUT
        actionHelp->setText(QApplication::translate("SerialPortAssistant", "\345\270\256\345\212\251", nullptr));
        actionAbout->setText(QApplication::translate("SerialPortAssistant", "\345\205\263\344\272\216", nullptr));
        actionQt->setText(QApplication::translate("SerialPortAssistant", "Qt", nullptr));
        actionSaveFile->setText(QApplication::translate("SerialPortAssistant", "\345\217\246\345\255\230\344\270\272...", nullptr));
#ifndef QT_NO_SHORTCUT
        actionSaveFile->setShortcut(QApplication::translate("SerialPortAssistant", "Ctrl+S", nullptr));
#endif // QT_NO_SHORTCUT
        basicSetting->setTitle(QApplication::translate("SerialPortAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        Get_Active_Electric->setText(QApplication::translate("SerialPortAssistant", "\345\275\223\345\211\215\346\255\243\345\220\221\346\234\211\345\212\237\346\200\273\347\224\265\350\203\275", nullptr));
        labelBaudRate->setText(QApplication::translate("SerialPortAssistant", "\346\263\242\347\211\271\347\216\207:", nullptr));
        serialPortSwitch->setText(QApplication::translate("SerialPortAssistant", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        labelDataBits->setText(QApplication::translate("SerialPortAssistant", "\346\225\260\346\215\256\344\275\215:", nullptr));
        pushButton_2->setText(QApplication::translate("SerialPortAssistant", "PushButton", nullptr));
        labelParity->setText(QApplication::translate("SerialPortAssistant", "\346\240\241\351\252\214\344\275\215:", nullptr));
        pushButton_3->setText(QApplication::translate("SerialPortAssistant", "PushButton", nullptr));
        pushButton_4->setText(QApplication::translate("SerialPortAssistant", "PushButton", nullptr));
        labelSerialPortNumber->setText(QApplication::translate("SerialPortAssistant", "\344\270\262\345\217\243:", nullptr));
        labelStopBits->setText(QApplication::translate("SerialPortAssistant", "\345\201\234\346\255\242\344\275\215:", nullptr));
        pushButton_5->setText(QApplication::translate("SerialPortAssistant", "PushButton", nullptr));
        extraSetting->setTitle(QApplication::translate("SerialPortAssistant", "\350\276\205\345\212\251\345\212\237\350\203\275", nullptr));
        showTime->setText(QApplication::translate("SerialPortAssistant", "\346\230\276\347\244\272\346\224\266\345\217\221\346\227\266\351\227\264", nullptr));
        hexadecimaleReceive->setText(QApplication::translate("SerialPortAssistant", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        sendFile->setText(QApplication::translate("SerialPortAssistant", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        doubleColor->setText(QApplication::translate("SerialPortAssistant", "\346\224\266\345\217\221\345\217\214\350\211\262\346\230\276\347\244\272", nullptr));
        hexadecimalSend->setText(QApplication::translate("SerialPortAssistant", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        autoNewLine->setText(QApplication::translate("SerialPortAssistant", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        clear->setText(QApplication::translate("SerialPortAssistant", "\346\270\205\347\251\272\346\225\260\346\215\256", nullptr));
        send->setText(QApplication::translate("SerialPortAssistant", "\345\217\221\351\200\201", nullptr));
        loopSetting->setTitle(QApplication::translate("SerialPortAssistant", "\345\276\252\347\216\257\350\256\276\347\275\256", nullptr));
        loop->setText(QApplication::translate("SerialPortAssistant", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        labelDelay->setText(QApplication::translate("SerialPortAssistant", "\351\227\264\351\232\224", nullptr));
        delay->setText(QApplication::translate("SerialPortAssistant", "1000", nullptr));
        labelMs->setText(QApplication::translate("SerialPortAssistant", "ms", nullptr));
        labelTimes->setText(QApplication::translate("SerialPortAssistant", "\351\207\215\345\244\215", nullptr));
        times->setText(QApplication::translate("SerialPortAssistant", "10", nullptr));
        label->setText(QApplication::translate("SerialPortAssistant", "\346\254\241", nullptr));
        menu_F->setTitle(QApplication::translate("SerialPortAssistant", "\346\226\207\344\273\266(&F)", nullptr));
        menu_H->setTitle(QApplication::translate("SerialPortAssistant", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortAssistant: public Ui_SerialPortAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTASSISTANT_H
