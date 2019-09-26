/********************************************************************************
** Form generated from reading UI file 'serialportassistant.ui'
**
** Created by: Qt User Interface Compiler version 5.12.0
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
    QWidget *layoutWidget;
    QVBoxLayout *verticalLayout_4;
    QTextEdit *dataDisplay;
    QHBoxLayout *horizontalLayout_8;
    QPlainTextEdit *dataToSend;
    QVBoxLayout *verticalLayout_2;
    QPushButton *send;
    QPushButton *sendclear;
    QGroupBox *loopSetting;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout_6;
    QLabel *labelDelay;
    QLineEdit *delay;
    QLabel *labelMs;
    QCheckBox *loop;
    QHBoxLayout *horizontalLayout_7;
    QLabel *labelTimes;
    QLineEdit *times;
    QLabel *label;
    QGroupBox *basicSetting;
    QWidget *layoutWidget1;
    QHBoxLayout *horizontalLayout_23;
    QHBoxLayout *horizontalLayout_24;
    QCheckBox *checkBox_12;
    QPushButton *A_Reactive_power;
    QHBoxLayout *horizontalLayout_25;
    QCheckBox *checkBox_13;
    QPushButton *B_Reactive_power;
    QHBoxLayout *horizontalLayout_26;
    QCheckBox *checkBox_14;
    QPushButton *C_Reactive_power;
    QWidget *layoutWidget_2;
    QHBoxLayout *horizontalLayout_27;
    QHBoxLayout *horizontalLayout_28;
    QCheckBox *checkBox_15;
    QPushButton *A_Apparent_power;
    QHBoxLayout *horizontalLayout_29;
    QCheckBox *checkBox_16;
    QPushButton *B_Apparent_power;
    QHBoxLayout *horizontalLayout_30;
    QCheckBox *checkBox_17;
    QPushButton *C_Apparent_power;
    QWidget *layoutWidget_3;
    QHBoxLayout *horizontalLayout_31;
    QHBoxLayout *horizontalLayout_32;
    QCheckBox *checkBox_18;
    QPushButton *A_factor_power;
    QHBoxLayout *horizontalLayout_33;
    QCheckBox *checkBox_19;
    QPushButton *B_factor_power;
    QHBoxLayout *horizontalLayout_34;
    QCheckBox *checkBox_20;
    QPushButton *C_factor_power;
    QWidget *layoutWidget_4;
    QHBoxLayout *horizontalLayout_35;
    QHBoxLayout *horizontalLayout_36;
    QCheckBox *checkBox_21;
    QPushButton *Total_active_power;
    QHBoxLayout *horizontalLayout_37;
    QCheckBox *checkBox_22;
    QPushButton *Total_Reactive_power;
    QHBoxLayout *horizontalLayout_38;
    QCheckBox *checkBox_23;
    QPushButton *Total_Apparent_power;
    QWidget *layoutWidget_5;
    QHBoxLayout *horizontalLayout_39;
    QHBoxLayout *horizontalLayout_40;
    QCheckBox *checkBox_24;
    QPushButton *A_total_power;
    QHBoxLayout *horizontalLayout_41;
    QCheckBox *checkBox_25;
    QPushButton *B_total_power;
    QHBoxLayout *horizontalLayout_42;
    QCheckBox *checkBox_26;
    QPushButton *C_total_power;
    QWidget *layoutWidget2;
    QVBoxLayout *verticalLayout_3;
    QHBoxLayout *horizontalLayout_51;
    QHBoxLayout *horizontalLayout;
    QLabel *labelSerialPortNumber;
    QComboBox *serialPortNumber;
    QHBoxLayout *horizontalLayout_2;
    QLabel *labelBaudRate;
    QComboBox *baudRate;
    QHBoxLayout *horizontalLayout_52;
    QHBoxLayout *horizontalLayout_3;
    QLabel *labelDataBits;
    QComboBox *dataBits;
    QHBoxLayout *horizontalLayout_4;
    QLabel *labelParity;
    QComboBox *parity;
    QHBoxLayout *horizontalLayout_53;
    QHBoxLayout *horizontalLayout_5;
    QLabel *labelStopBits;
    QComboBox *stopBits;
    QPushButton *serialPortSwitch;
    QWidget *layoutWidget3;
    QHBoxLayout *horizontalLayout_18;
    QHBoxLayout *horizontalLayout_20;
    QCheckBox *checkBox_9;
    QPushButton *A_active_power;
    QHBoxLayout *horizontalLayout_21;
    QCheckBox *checkBox_10;
    QPushButton *B_active_power;
    QHBoxLayout *horizontalLayout_22;
    QCheckBox *checkBox_11;
    QPushButton *C_active_power;
    QWidget *layoutWidget4;
    QHBoxLayout *horizontalLayout_17;
    QHBoxLayout *horizontalLayout_19;
    QCheckBox *checkBox;
    QPushButton *Get_Active_Electric;
    QHBoxLayout *horizontalLayout_10;
    QCheckBox *checkBox_1;
    QPushButton *power_frequency;
    QHBoxLayout *horizontalLayout_9;
    QCheckBox *checkBox_2;
    QPushButton *N_Electric;
    QWidget *layoutWidget5;
    QHBoxLayout *horizontalLayout_16;
    QHBoxLayout *horizontalLayout_11;
    QCheckBox *checkBox_6;
    QPushButton *A_Electric;
    QHBoxLayout *horizontalLayout_12;
    QCheckBox *checkBox_7;
    QPushButton *B_Electric;
    QHBoxLayout *horizontalLayout_15;
    QCheckBox *checkBox_8;
    QPushButton *C_Electric;
    QWidget *layoutWidget6;
    QHBoxLayout *horizontalLayout_44;
    QHBoxLayout *horizontalLayout_43;
    QCheckBox *checkBox_27;
    QPushButton *Total_power_factor_;
    QPushButton *testall;
    QWidget *layoutWidget_6;
    QHBoxLayout *horizontalLayout_45;
    QHBoxLayout *horizontalLayout_13;
    QCheckBox *checkBox_3;
    QPushButton *A_Voltage;
    QHBoxLayout *horizontalLayout_14;
    QCheckBox *checkBox_4;
    QPushButton *B_Voltage;
    QHBoxLayout *horizontalLayout_46;
    QCheckBox *checkBox_5;
    QPushButton *C_Voltage;
    QGroupBox *extraSetting;
    QWidget *layoutWidget7;
    QGridLayout *gridLayout;
    QCheckBox *autoNewLine;
    QCheckBox *doubleColor;
    QCheckBox *showTime;
    QCheckBox *hexadecimaleReceive;
    QCheckBox *hexadecimalSend;
    QPushButton *clear;
    QPushButton *sendFile;
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
        layoutWidget = new QWidget(centralWidget);
        layoutWidget->setObjectName(QString::fromUtf8("layoutWidget"));
        layoutWidget->setGeometry(QRect(360, 10, 481, 551));
        verticalLayout_4 = new QVBoxLayout(layoutWidget);
        verticalLayout_4->setSpacing(6);
        verticalLayout_4->setContentsMargins(11, 11, 11, 11);
        verticalLayout_4->setObjectName(QString::fromUtf8("verticalLayout_4"));
        verticalLayout_4->setContentsMargins(0, 0, 0, 0);
        dataDisplay = new QTextEdit(layoutWidget);
        dataDisplay->setObjectName(QString::fromUtf8("dataDisplay"));
        dataDisplay->setReadOnly(true);

        verticalLayout_4->addWidget(dataDisplay);

        horizontalLayout_8 = new QHBoxLayout();
        horizontalLayout_8->setSpacing(6);
        horizontalLayout_8->setObjectName(QString::fromUtf8("horizontalLayout_8"));
        dataToSend = new QPlainTextEdit(layoutWidget);
        dataToSend->setObjectName(QString::fromUtf8("dataToSend"));

        horizontalLayout_8->addWidget(dataToSend);

        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setSpacing(6);
        verticalLayout_2->setObjectName(QString::fromUtf8("verticalLayout_2"));
        verticalLayout_2->setSizeConstraint(QLayout::SetMaximumSize);
        send = new QPushButton(layoutWidget);
        send->setObjectName(QString::fromUtf8("send"));
        send->setMaximumSize(QSize(150, 16777215));

        verticalLayout_2->addWidget(send);

        sendclear = new QPushButton(layoutWidget);
        sendclear->setObjectName(QString::fromUtf8("sendclear"));

        verticalLayout_2->addWidget(sendclear);

        loopSetting = new QGroupBox(layoutWidget);
        loopSetting->setObjectName(QString::fromUtf8("loopSetting"));
        loopSetting->setMaximumSize(QSize(150, 16777215));
        gridLayout_3 = new QGridLayout(loopSetting);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QString::fromUtf8("gridLayout_3"));
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

        loop = new QCheckBox(loopSetting);
        loop->setObjectName(QString::fromUtf8("loop"));

        gridLayout_3->addWidget(loop, 0, 0, 1, 1);

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


        verticalLayout_4->addLayout(horizontalLayout_8);

        basicSetting = new QGroupBox(centralWidget);
        basicSetting->setObjectName(QString::fromUtf8("basicSetting"));
        basicSetting->setGeometry(QRect(-10, 10, 371, 451));
        basicSetting->setMinimumSize(QSize(200, 0));
        basicSetting->setMaximumSize(QSize(10000, 16777215));
        basicSetting->setFlat(false);
        layoutWidget1 = new QWidget(basicSetting);
        layoutWidget1->setObjectName(QString::fromUtf8("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(10, 250, 302, 27));
        horizontalLayout_23 = new QHBoxLayout(layoutWidget1);
        horizontalLayout_23->setSpacing(6);
        horizontalLayout_23->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_23->setObjectName(QString::fromUtf8("horizontalLayout_23"));
        horizontalLayout_23->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_24 = new QHBoxLayout();
        horizontalLayout_24->setSpacing(6);
        horizontalLayout_24->setObjectName(QString::fromUtf8("horizontalLayout_24"));
        checkBox_12 = new QCheckBox(layoutWidget1);
        checkBox_12->setObjectName(QString::fromUtf8("checkBox_12"));
        checkBox_12->setChecked(true);

        horizontalLayout_24->addWidget(checkBox_12);

        A_Reactive_power = new QPushButton(layoutWidget1);
        A_Reactive_power->setObjectName(QString::fromUtf8("A_Reactive_power"));

        horizontalLayout_24->addWidget(A_Reactive_power);


        horizontalLayout_23->addLayout(horizontalLayout_24);

        horizontalLayout_25 = new QHBoxLayout();
        horizontalLayout_25->setSpacing(6);
        horizontalLayout_25->setObjectName(QString::fromUtf8("horizontalLayout_25"));
        checkBox_13 = new QCheckBox(layoutWidget1);
        checkBox_13->setObjectName(QString::fromUtf8("checkBox_13"));
        checkBox_13->setChecked(true);

        horizontalLayout_25->addWidget(checkBox_13);

        B_Reactive_power = new QPushButton(layoutWidget1);
        B_Reactive_power->setObjectName(QString::fromUtf8("B_Reactive_power"));

        horizontalLayout_25->addWidget(B_Reactive_power);


        horizontalLayout_23->addLayout(horizontalLayout_25);

        horizontalLayout_26 = new QHBoxLayout();
        horizontalLayout_26->setSpacing(6);
        horizontalLayout_26->setObjectName(QString::fromUtf8("horizontalLayout_26"));
        checkBox_14 = new QCheckBox(layoutWidget1);
        checkBox_14->setObjectName(QString::fromUtf8("checkBox_14"));
        checkBox_14->setChecked(true);

        horizontalLayout_26->addWidget(checkBox_14);

        C_Reactive_power = new QPushButton(layoutWidget1);
        C_Reactive_power->setObjectName(QString::fromUtf8("C_Reactive_power"));

        horizontalLayout_26->addWidget(C_Reactive_power);


        horizontalLayout_23->addLayout(horizontalLayout_26);

        layoutWidget_2 = new QWidget(basicSetting);
        layoutWidget_2->setObjectName(QString::fromUtf8("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(10, 280, 302, 27));
        horizontalLayout_27 = new QHBoxLayout(layoutWidget_2);
        horizontalLayout_27->setSpacing(6);
        horizontalLayout_27->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_27->setObjectName(QString::fromUtf8("horizontalLayout_27"));
        horizontalLayout_27->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_28 = new QHBoxLayout();
        horizontalLayout_28->setSpacing(6);
        horizontalLayout_28->setObjectName(QString::fromUtf8("horizontalLayout_28"));
        checkBox_15 = new QCheckBox(layoutWidget_2);
        checkBox_15->setObjectName(QString::fromUtf8("checkBox_15"));
        checkBox_15->setChecked(true);

        horizontalLayout_28->addWidget(checkBox_15);

        A_Apparent_power = new QPushButton(layoutWidget_2);
        A_Apparent_power->setObjectName(QString::fromUtf8("A_Apparent_power"));

        horizontalLayout_28->addWidget(A_Apparent_power);


        horizontalLayout_27->addLayout(horizontalLayout_28);

        horizontalLayout_29 = new QHBoxLayout();
        horizontalLayout_29->setSpacing(6);
        horizontalLayout_29->setObjectName(QString::fromUtf8("horizontalLayout_29"));
        checkBox_16 = new QCheckBox(layoutWidget_2);
        checkBox_16->setObjectName(QString::fromUtf8("checkBox_16"));
        checkBox_16->setChecked(true);

        horizontalLayout_29->addWidget(checkBox_16);

        B_Apparent_power = new QPushButton(layoutWidget_2);
        B_Apparent_power->setObjectName(QString::fromUtf8("B_Apparent_power"));

        horizontalLayout_29->addWidget(B_Apparent_power);


        horizontalLayout_27->addLayout(horizontalLayout_29);

        horizontalLayout_30 = new QHBoxLayout();
        horizontalLayout_30->setSpacing(6);
        horizontalLayout_30->setObjectName(QString::fromUtf8("horizontalLayout_30"));
        checkBox_17 = new QCheckBox(layoutWidget_2);
        checkBox_17->setObjectName(QString::fromUtf8("checkBox_17"));
        checkBox_17->setChecked(true);

        horizontalLayout_30->addWidget(checkBox_17);

        C_Apparent_power = new QPushButton(layoutWidget_2);
        C_Apparent_power->setObjectName(QString::fromUtf8("C_Apparent_power"));

        horizontalLayout_30->addWidget(C_Apparent_power);


        horizontalLayout_27->addLayout(horizontalLayout_30);

        layoutWidget_3 = new QWidget(basicSetting);
        layoutWidget_3->setObjectName(QString::fromUtf8("layoutWidget_3"));
        layoutWidget_3->setGeometry(QRect(10, 310, 302, 27));
        horizontalLayout_31 = new QHBoxLayout(layoutWidget_3);
        horizontalLayout_31->setSpacing(6);
        horizontalLayout_31->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_31->setObjectName(QString::fromUtf8("horizontalLayout_31"));
        horizontalLayout_31->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_32 = new QHBoxLayout();
        horizontalLayout_32->setSpacing(6);
        horizontalLayout_32->setObjectName(QString::fromUtf8("horizontalLayout_32"));
        checkBox_18 = new QCheckBox(layoutWidget_3);
        checkBox_18->setObjectName(QString::fromUtf8("checkBox_18"));
        checkBox_18->setChecked(true);

        horizontalLayout_32->addWidget(checkBox_18);

        A_factor_power = new QPushButton(layoutWidget_3);
        A_factor_power->setObjectName(QString::fromUtf8("A_factor_power"));

        horizontalLayout_32->addWidget(A_factor_power);


        horizontalLayout_31->addLayout(horizontalLayout_32);

        horizontalLayout_33 = new QHBoxLayout();
        horizontalLayout_33->setSpacing(6);
        horizontalLayout_33->setObjectName(QString::fromUtf8("horizontalLayout_33"));
        checkBox_19 = new QCheckBox(layoutWidget_3);
        checkBox_19->setObjectName(QString::fromUtf8("checkBox_19"));
        checkBox_19->setChecked(true);

        horizontalLayout_33->addWidget(checkBox_19);

        B_factor_power = new QPushButton(layoutWidget_3);
        B_factor_power->setObjectName(QString::fromUtf8("B_factor_power"));

        horizontalLayout_33->addWidget(B_factor_power);


        horizontalLayout_31->addLayout(horizontalLayout_33);

        horizontalLayout_34 = new QHBoxLayout();
        horizontalLayout_34->setSpacing(6);
        horizontalLayout_34->setObjectName(QString::fromUtf8("horizontalLayout_34"));
        checkBox_20 = new QCheckBox(layoutWidget_3);
        checkBox_20->setObjectName(QString::fromUtf8("checkBox_20"));
        checkBox_20->setChecked(true);

        horizontalLayout_34->addWidget(checkBox_20);

        C_factor_power = new QPushButton(layoutWidget_3);
        C_factor_power->setObjectName(QString::fromUtf8("C_factor_power"));

        horizontalLayout_34->addWidget(C_factor_power);


        horizontalLayout_31->addLayout(horizontalLayout_34);

        layoutWidget_4 = new QWidget(basicSetting);
        layoutWidget_4->setObjectName(QString::fromUtf8("layoutWidget_4"));
        layoutWidget_4->setGeometry(QRect(10, 340, 302, 27));
        horizontalLayout_35 = new QHBoxLayout(layoutWidget_4);
        horizontalLayout_35->setSpacing(6);
        horizontalLayout_35->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_35->setObjectName(QString::fromUtf8("horizontalLayout_35"));
        horizontalLayout_35->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_36 = new QHBoxLayout();
        horizontalLayout_36->setSpacing(6);
        horizontalLayout_36->setObjectName(QString::fromUtf8("horizontalLayout_36"));
        checkBox_21 = new QCheckBox(layoutWidget_4);
        checkBox_21->setObjectName(QString::fromUtf8("checkBox_21"));
        checkBox_21->setChecked(true);

        horizontalLayout_36->addWidget(checkBox_21);

        Total_active_power = new QPushButton(layoutWidget_4);
        Total_active_power->setObjectName(QString::fromUtf8("Total_active_power"));

        horizontalLayout_36->addWidget(Total_active_power);


        horizontalLayout_35->addLayout(horizontalLayout_36);

        horizontalLayout_37 = new QHBoxLayout();
        horizontalLayout_37->setSpacing(6);
        horizontalLayout_37->setObjectName(QString::fromUtf8("horizontalLayout_37"));
        checkBox_22 = new QCheckBox(layoutWidget_4);
        checkBox_22->setObjectName(QString::fromUtf8("checkBox_22"));
        checkBox_22->setChecked(true);

        horizontalLayout_37->addWidget(checkBox_22);

        Total_Reactive_power = new QPushButton(layoutWidget_4);
        Total_Reactive_power->setObjectName(QString::fromUtf8("Total_Reactive_power"));

        horizontalLayout_37->addWidget(Total_Reactive_power);


        horizontalLayout_35->addLayout(horizontalLayout_37);

        horizontalLayout_38 = new QHBoxLayout();
        horizontalLayout_38->setSpacing(6);
        horizontalLayout_38->setObjectName(QString::fromUtf8("horizontalLayout_38"));
        checkBox_23 = new QCheckBox(layoutWidget_4);
        checkBox_23->setObjectName(QString::fromUtf8("checkBox_23"));
        checkBox_23->setChecked(true);

        horizontalLayout_38->addWidget(checkBox_23);

        Total_Apparent_power = new QPushButton(layoutWidget_4);
        Total_Apparent_power->setObjectName(QString::fromUtf8("Total_Apparent_power"));

        horizontalLayout_38->addWidget(Total_Apparent_power);


        horizontalLayout_35->addLayout(horizontalLayout_38);

        layoutWidget_5 = new QWidget(basicSetting);
        layoutWidget_5->setObjectName(QString::fromUtf8("layoutWidget_5"));
        layoutWidget_5->setGeometry(QRect(10, 370, 302, 27));
        horizontalLayout_39 = new QHBoxLayout(layoutWidget_5);
        horizontalLayout_39->setSpacing(6);
        horizontalLayout_39->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_39->setObjectName(QString::fromUtf8("horizontalLayout_39"));
        horizontalLayout_39->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_40 = new QHBoxLayout();
        horizontalLayout_40->setSpacing(6);
        horizontalLayout_40->setObjectName(QString::fromUtf8("horizontalLayout_40"));
        checkBox_24 = new QCheckBox(layoutWidget_5);
        checkBox_24->setObjectName(QString::fromUtf8("checkBox_24"));
        checkBox_24->setChecked(true);

        horizontalLayout_40->addWidget(checkBox_24);

        A_total_power = new QPushButton(layoutWidget_5);
        A_total_power->setObjectName(QString::fromUtf8("A_total_power"));

        horizontalLayout_40->addWidget(A_total_power);


        horizontalLayout_39->addLayout(horizontalLayout_40);

        horizontalLayout_41 = new QHBoxLayout();
        horizontalLayout_41->setSpacing(6);
        horizontalLayout_41->setObjectName(QString::fromUtf8("horizontalLayout_41"));
        checkBox_25 = new QCheckBox(layoutWidget_5);
        checkBox_25->setObjectName(QString::fromUtf8("checkBox_25"));
        checkBox_25->setChecked(true);

        horizontalLayout_41->addWidget(checkBox_25);

        B_total_power = new QPushButton(layoutWidget_5);
        B_total_power->setObjectName(QString::fromUtf8("B_total_power"));

        horizontalLayout_41->addWidget(B_total_power);


        horizontalLayout_39->addLayout(horizontalLayout_41);

        horizontalLayout_42 = new QHBoxLayout();
        horizontalLayout_42->setSpacing(6);
        horizontalLayout_42->setObjectName(QString::fromUtf8("horizontalLayout_42"));
        checkBox_26 = new QCheckBox(layoutWidget_5);
        checkBox_26->setObjectName(QString::fromUtf8("checkBox_26"));
        checkBox_26->setChecked(true);

        horizontalLayout_42->addWidget(checkBox_26);

        C_total_power = new QPushButton(layoutWidget_5);
        C_total_power->setObjectName(QString::fromUtf8("C_total_power"));

        horizontalLayout_42->addWidget(C_total_power);


        horizontalLayout_39->addLayout(horizontalLayout_42);

        layoutWidget2 = new QWidget(basicSetting);
        layoutWidget2->setObjectName(QString::fromUtf8("layoutWidget2"));
        layoutWidget2->setGeometry(QRect(10, 20, 310, 87));
        verticalLayout_3 = new QVBoxLayout(layoutWidget2);
        verticalLayout_3->setSpacing(6);
        verticalLayout_3->setContentsMargins(11, 11, 11, 11);
        verticalLayout_3->setObjectName(QString::fromUtf8("verticalLayout_3"));
        verticalLayout_3->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_51 = new QHBoxLayout();
        horizontalLayout_51->setSpacing(6);
        horizontalLayout_51->setObjectName(QString::fromUtf8("horizontalLayout_51"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QString::fromUtf8("horizontalLayout"));
        labelSerialPortNumber = new QLabel(layoutWidget2);
        labelSerialPortNumber->setObjectName(QString::fromUtf8("labelSerialPortNumber"));
        labelSerialPortNumber->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout->addWidget(labelSerialPortNumber);

        serialPortNumber = new QComboBox(layoutWidget2);
        serialPortNumber->setObjectName(QString::fromUtf8("serialPortNumber"));
        serialPortNumber->setMinimumSize(QSize(100, 0));

        horizontalLayout->addWidget(serialPortNumber);


        horizontalLayout_51->addLayout(horizontalLayout);

        horizontalLayout_2 = new QHBoxLayout();
        horizontalLayout_2->setSpacing(6);
        horizontalLayout_2->setObjectName(QString::fromUtf8("horizontalLayout_2"));
        labelBaudRate = new QLabel(layoutWidget2);
        labelBaudRate->setObjectName(QString::fromUtf8("labelBaudRate"));
        labelBaudRate->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_2->addWidget(labelBaudRate);

        baudRate = new QComboBox(layoutWidget2);
        baudRate->setObjectName(QString::fromUtf8("baudRate"));
        baudRate->setMinimumSize(QSize(100, 0));

        horizontalLayout_2->addWidget(baudRate);


        horizontalLayout_51->addLayout(horizontalLayout_2);


        verticalLayout_3->addLayout(horizontalLayout_51);

        horizontalLayout_52 = new QHBoxLayout();
        horizontalLayout_52->setSpacing(6);
        horizontalLayout_52->setObjectName(QString::fromUtf8("horizontalLayout_52"));
        horizontalLayout_3 = new QHBoxLayout();
        horizontalLayout_3->setSpacing(6);
        horizontalLayout_3->setObjectName(QString::fromUtf8("horizontalLayout_3"));
        labelDataBits = new QLabel(layoutWidget2);
        labelDataBits->setObjectName(QString::fromUtf8("labelDataBits"));
        labelDataBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_3->addWidget(labelDataBits);

        dataBits = new QComboBox(layoutWidget2);
        dataBits->setObjectName(QString::fromUtf8("dataBits"));
        dataBits->setMinimumSize(QSize(100, 0));

        horizontalLayout_3->addWidget(dataBits);


        horizontalLayout_52->addLayout(horizontalLayout_3);

        horizontalLayout_4 = new QHBoxLayout();
        horizontalLayout_4->setSpacing(6);
        horizontalLayout_4->setObjectName(QString::fromUtf8("horizontalLayout_4"));
        labelParity = new QLabel(layoutWidget2);
        labelParity->setObjectName(QString::fromUtf8("labelParity"));
        labelParity->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_4->addWidget(labelParity);

        parity = new QComboBox(layoutWidget2);
        parity->setObjectName(QString::fromUtf8("parity"));
        parity->setMinimumSize(QSize(100, 0));

        horizontalLayout_4->addWidget(parity);


        horizontalLayout_52->addLayout(horizontalLayout_4);


        verticalLayout_3->addLayout(horizontalLayout_52);

        horizontalLayout_53 = new QHBoxLayout();
        horizontalLayout_53->setSpacing(6);
        horizontalLayout_53->setObjectName(QString::fromUtf8("horizontalLayout_53"));
        horizontalLayout_5 = new QHBoxLayout();
        horizontalLayout_5->setSpacing(6);
        horizontalLayout_5->setObjectName(QString::fromUtf8("horizontalLayout_5"));
        labelStopBits = new QLabel(layoutWidget2);
        labelStopBits->setObjectName(QString::fromUtf8("labelStopBits"));
        labelStopBits->setAlignment(Qt::AlignRight|Qt::AlignTrailing|Qt::AlignVCenter);

        horizontalLayout_5->addWidget(labelStopBits);

        stopBits = new QComboBox(layoutWidget2);
        stopBits->setObjectName(QString::fromUtf8("stopBits"));
        stopBits->setMinimumSize(QSize(100, 0));

        horizontalLayout_5->addWidget(stopBits);


        horizontalLayout_53->addLayout(horizontalLayout_5);

        serialPortSwitch = new QPushButton(layoutWidget2);
        serialPortSwitch->setObjectName(QString::fromUtf8("serialPortSwitch"));
        serialPortSwitch->setMaximumSize(QSize(16777215, 16777215));

        horizontalLayout_53->addWidget(serialPortSwitch);


        verticalLayout_3->addLayout(horizontalLayout_53);

        layoutWidget3 = new QWidget(basicSetting);
        layoutWidget3->setObjectName(QString::fromUtf8("layoutWidget3"));
        layoutWidget3->setGeometry(QRect(10, 220, 302, 27));
        horizontalLayout_18 = new QHBoxLayout(layoutWidget3);
        horizontalLayout_18->setSpacing(6);
        horizontalLayout_18->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_18->setObjectName(QString::fromUtf8("horizontalLayout_18"));
        horizontalLayout_18->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_20 = new QHBoxLayout();
        horizontalLayout_20->setSpacing(6);
        horizontalLayout_20->setObjectName(QString::fromUtf8("horizontalLayout_20"));
        checkBox_9 = new QCheckBox(layoutWidget3);
        checkBox_9->setObjectName(QString::fromUtf8("checkBox_9"));
        checkBox_9->setChecked(true);

        horizontalLayout_20->addWidget(checkBox_9);

        A_active_power = new QPushButton(layoutWidget3);
        A_active_power->setObjectName(QString::fromUtf8("A_active_power"));

        horizontalLayout_20->addWidget(A_active_power);


        horizontalLayout_18->addLayout(horizontalLayout_20);

        horizontalLayout_21 = new QHBoxLayout();
        horizontalLayout_21->setSpacing(6);
        horizontalLayout_21->setObjectName(QString::fromUtf8("horizontalLayout_21"));
        checkBox_10 = new QCheckBox(layoutWidget3);
        checkBox_10->setObjectName(QString::fromUtf8("checkBox_10"));
        checkBox_10->setChecked(true);

        horizontalLayout_21->addWidget(checkBox_10);

        B_active_power = new QPushButton(layoutWidget3);
        B_active_power->setObjectName(QString::fromUtf8("B_active_power"));

        horizontalLayout_21->addWidget(B_active_power);


        horizontalLayout_18->addLayout(horizontalLayout_21);

        horizontalLayout_22 = new QHBoxLayout();
        horizontalLayout_22->setSpacing(6);
        horizontalLayout_22->setObjectName(QString::fromUtf8("horizontalLayout_22"));
        checkBox_11 = new QCheckBox(layoutWidget3);
        checkBox_11->setObjectName(QString::fromUtf8("checkBox_11"));
        checkBox_11->setChecked(true);

        horizontalLayout_22->addWidget(checkBox_11);

        C_active_power = new QPushButton(layoutWidget3);
        C_active_power->setObjectName(QString::fromUtf8("C_active_power"));

        horizontalLayout_22->addWidget(C_active_power);


        horizontalLayout_18->addLayout(horizontalLayout_22);

        layoutWidget4 = new QWidget(basicSetting);
        layoutWidget4->setObjectName(QString::fromUtf8("layoutWidget4"));
        layoutWidget4->setGeometry(QRect(10, 130, 343, 27));
        horizontalLayout_17 = new QHBoxLayout(layoutWidget4);
        horizontalLayout_17->setSpacing(6);
        horizontalLayout_17->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_17->setObjectName(QString::fromUtf8("horizontalLayout_17"));
        horizontalLayout_17->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_19 = new QHBoxLayout();
        horizontalLayout_19->setSpacing(6);
        horizontalLayout_19->setObjectName(QString::fromUtf8("horizontalLayout_19"));
        checkBox = new QCheckBox(layoutWidget4);
        checkBox->setObjectName(QString::fromUtf8("checkBox"));
        checkBox->setChecked(true);

        horizontalLayout_19->addWidget(checkBox);

        Get_Active_Electric = new QPushButton(layoutWidget4);
        Get_Active_Electric->setObjectName(QString::fromUtf8("Get_Active_Electric"));

        horizontalLayout_19->addWidget(Get_Active_Electric);


        horizontalLayout_17->addLayout(horizontalLayout_19);

        horizontalLayout_10 = new QHBoxLayout();
        horizontalLayout_10->setSpacing(6);
        horizontalLayout_10->setObjectName(QString::fromUtf8("horizontalLayout_10"));
        checkBox_1 = new QCheckBox(layoutWidget4);
        checkBox_1->setObjectName(QString::fromUtf8("checkBox_1"));
        checkBox_1->setChecked(true);

        horizontalLayout_10->addWidget(checkBox_1);

        power_frequency = new QPushButton(layoutWidget4);
        power_frequency->setObjectName(QString::fromUtf8("power_frequency"));

        horizontalLayout_10->addWidget(power_frequency);


        horizontalLayout_17->addLayout(horizontalLayout_10);

        horizontalLayout_9 = new QHBoxLayout();
        horizontalLayout_9->setSpacing(6);
        horizontalLayout_9->setObjectName(QString::fromUtf8("horizontalLayout_9"));
        checkBox_2 = new QCheckBox(layoutWidget4);
        checkBox_2->setObjectName(QString::fromUtf8("checkBox_2"));
        checkBox_2->setChecked(true);

        horizontalLayout_9->addWidget(checkBox_2);

        N_Electric = new QPushButton(layoutWidget4);
        N_Electric->setObjectName(QString::fromUtf8("N_Electric"));

        horizontalLayout_9->addWidget(N_Electric);


        horizontalLayout_17->addLayout(horizontalLayout_9);

        layoutWidget5 = new QWidget(basicSetting);
        layoutWidget5->setObjectName(QString::fromUtf8("layoutWidget5"));
        layoutWidget5->setGeometry(QRect(10, 190, 302, 27));
        horizontalLayout_16 = new QHBoxLayout(layoutWidget5);
        horizontalLayout_16->setSpacing(6);
        horizontalLayout_16->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_16->setObjectName(QString::fromUtf8("horizontalLayout_16"));
        horizontalLayout_16->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_11 = new QHBoxLayout();
        horizontalLayout_11->setSpacing(6);
        horizontalLayout_11->setObjectName(QString::fromUtf8("horizontalLayout_11"));
        checkBox_6 = new QCheckBox(layoutWidget5);
        checkBox_6->setObjectName(QString::fromUtf8("checkBox_6"));
        checkBox_6->setChecked(true);

        horizontalLayout_11->addWidget(checkBox_6);

        A_Electric = new QPushButton(layoutWidget5);
        A_Electric->setObjectName(QString::fromUtf8("A_Electric"));

        horizontalLayout_11->addWidget(A_Electric);


        horizontalLayout_16->addLayout(horizontalLayout_11);

        horizontalLayout_12 = new QHBoxLayout();
        horizontalLayout_12->setSpacing(6);
        horizontalLayout_12->setObjectName(QString::fromUtf8("horizontalLayout_12"));
        checkBox_7 = new QCheckBox(layoutWidget5);
        checkBox_7->setObjectName(QString::fromUtf8("checkBox_7"));
        checkBox_7->setChecked(true);

        horizontalLayout_12->addWidget(checkBox_7);

        B_Electric = new QPushButton(layoutWidget5);
        B_Electric->setObjectName(QString::fromUtf8("B_Electric"));

        horizontalLayout_12->addWidget(B_Electric);


        horizontalLayout_16->addLayout(horizontalLayout_12);

        horizontalLayout_15 = new QHBoxLayout();
        horizontalLayout_15->setSpacing(6);
        horizontalLayout_15->setObjectName(QString::fromUtf8("horizontalLayout_15"));
        checkBox_8 = new QCheckBox(layoutWidget5);
        checkBox_8->setObjectName(QString::fromUtf8("checkBox_8"));
        checkBox_8->setChecked(true);

        horizontalLayout_15->addWidget(checkBox_8);

        C_Electric = new QPushButton(layoutWidget5);
        C_Electric->setObjectName(QString::fromUtf8("C_Electric"));

        horizontalLayout_15->addWidget(C_Electric);


        horizontalLayout_16->addLayout(horizontalLayout_15);

        layoutWidget6 = new QWidget(basicSetting);
        layoutWidget6->setObjectName(QString::fromUtf8("layoutWidget6"));
        layoutWidget6->setGeometry(QRect(20, 400, 191, 27));
        horizontalLayout_44 = new QHBoxLayout(layoutWidget6);
        horizontalLayout_44->setSpacing(6);
        horizontalLayout_44->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_44->setObjectName(QString::fromUtf8("horizontalLayout_44"));
        horizontalLayout_44->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_43 = new QHBoxLayout();
        horizontalLayout_43->setSpacing(6);
        horizontalLayout_43->setObjectName(QString::fromUtf8("horizontalLayout_43"));
        checkBox_27 = new QCheckBox(layoutWidget6);
        checkBox_27->setObjectName(QString::fromUtf8("checkBox_27"));
        checkBox_27->setChecked(true);

        horizontalLayout_43->addWidget(checkBox_27);

        Total_power_factor_ = new QPushButton(layoutWidget6);
        Total_power_factor_->setObjectName(QString::fromUtf8("Total_power_factor_"));

        horizontalLayout_43->addWidget(Total_power_factor_);


        horizontalLayout_44->addLayout(horizontalLayout_43);

        testall = new QPushButton(layoutWidget6);
        testall->setObjectName(QString::fromUtf8("testall"));

        horizontalLayout_44->addWidget(testall);

        layoutWidget_6 = new QWidget(basicSetting);
        layoutWidget_6->setObjectName(QString::fromUtf8("layoutWidget_6"));
        layoutWidget_6->setGeometry(QRect(10, 160, 302, 27));
        horizontalLayout_45 = new QHBoxLayout(layoutWidget_6);
        horizontalLayout_45->setSpacing(6);
        horizontalLayout_45->setContentsMargins(11, 11, 11, 11);
        horizontalLayout_45->setObjectName(QString::fromUtf8("horizontalLayout_45"));
        horizontalLayout_45->setContentsMargins(0, 0, 0, 0);
        horizontalLayout_13 = new QHBoxLayout();
        horizontalLayout_13->setSpacing(6);
        horizontalLayout_13->setObjectName(QString::fromUtf8("horizontalLayout_13"));
        checkBox_3 = new QCheckBox(layoutWidget_6);
        checkBox_3->setObjectName(QString::fromUtf8("checkBox_3"));
        checkBox_3->setChecked(true);

        horizontalLayout_13->addWidget(checkBox_3);

        A_Voltage = new QPushButton(layoutWidget_6);
        A_Voltage->setObjectName(QString::fromUtf8("A_Voltage"));

        horizontalLayout_13->addWidget(A_Voltage);


        horizontalLayout_45->addLayout(horizontalLayout_13);

        horizontalLayout_14 = new QHBoxLayout();
        horizontalLayout_14->setSpacing(6);
        horizontalLayout_14->setObjectName(QString::fromUtf8("horizontalLayout_14"));
        checkBox_4 = new QCheckBox(layoutWidget_6);
        checkBox_4->setObjectName(QString::fromUtf8("checkBox_4"));
        checkBox_4->setChecked(true);

        horizontalLayout_14->addWidget(checkBox_4);

        B_Voltage = new QPushButton(layoutWidget_6);
        B_Voltage->setObjectName(QString::fromUtf8("B_Voltage"));

        horizontalLayout_14->addWidget(B_Voltage);


        horizontalLayout_45->addLayout(horizontalLayout_14);

        horizontalLayout_46 = new QHBoxLayout();
        horizontalLayout_46->setSpacing(6);
        horizontalLayout_46->setObjectName(QString::fromUtf8("horizontalLayout_46"));
        checkBox_5 = new QCheckBox(layoutWidget_6);
        checkBox_5->setObjectName(QString::fromUtf8("checkBox_5"));
        checkBox_5->setChecked(true);

        horizontalLayout_46->addWidget(checkBox_5);

        C_Voltage = new QPushButton(layoutWidget_6);
        C_Voltage->setObjectName(QString::fromUtf8("C_Voltage"));

        horizontalLayout_46->addWidget(C_Voltage);


        horizontalLayout_45->addLayout(horizontalLayout_46);

        extraSetting = new QGroupBox(centralWidget);
        extraSetting->setObjectName(QString::fromUtf8("extraSetting"));
        extraSetting->setGeometry(QRect(0, 450, 341, 111));
        extraSetting->setMinimumSize(QSize(200, 0));
        extraSetting->setMaximumSize(QSize(50000, 16777215));
        layoutWidget7 = new QWidget(extraSetting);
        layoutWidget7->setObjectName(QString::fromUtf8("layoutWidget7"));
        layoutWidget7->setGeometry(QRect(12, 22, 279, 69));
        gridLayout = new QGridLayout(layoutWidget7);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QString::fromUtf8("gridLayout"));
        gridLayout->setContentsMargins(0, 0, 0, 0);
        autoNewLine = new QCheckBox(layoutWidget7);
        autoNewLine->setObjectName(QString::fromUtf8("autoNewLine"));

        gridLayout->addWidget(autoNewLine, 0, 0, 1, 1);

        doubleColor = new QCheckBox(layoutWidget7);
        doubleColor->setObjectName(QString::fromUtf8("doubleColor"));
        doubleColor->setChecked(true);

        gridLayout->addWidget(doubleColor, 0, 1, 1, 2);

        showTime = new QCheckBox(layoutWidget7);
        showTime->setObjectName(QString::fromUtf8("showTime"));

        gridLayout->addWidget(showTime, 0, 3, 1, 1);

        hexadecimaleReceive = new QCheckBox(layoutWidget7);
        hexadecimaleReceive->setObjectName(QString::fromUtf8("hexadecimaleReceive"));
        hexadecimaleReceive->setChecked(true);

        gridLayout->addWidget(hexadecimaleReceive, 1, 0, 1, 2);

        hexadecimalSend = new QCheckBox(layoutWidget7);
        hexadecimalSend->setObjectName(QString::fromUtf8("hexadecimalSend"));
        hexadecimalSend->setEnabled(true);
        hexadecimalSend->setTabletTracking(false);
        hexadecimalSend->setChecked(true);

        gridLayout->addWidget(hexadecimalSend, 1, 2, 1, 2);

        clear = new QPushButton(layoutWidget7);
        clear->setObjectName(QString::fromUtf8("clear"));

        gridLayout->addWidget(clear, 2, 2, 1, 2);

        sendFile = new QPushButton(layoutWidget7);
        sendFile->setObjectName(QString::fromUtf8("sendFile"));

        gridLayout->addWidget(sendFile, 2, 0, 1, 2);

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
        send->setText(QApplication::translate("SerialPortAssistant", "\345\217\221\351\200\201", nullptr));
        sendclear->setText(QApplication::translate("SerialPortAssistant", "\346\270\205\347\251\272\345\217\221\351\200\201\346\225\260\346\215\256", nullptr));
        loopSetting->setTitle(QApplication::translate("SerialPortAssistant", "\345\276\252\347\216\257\350\256\276\347\275\256", nullptr));
        labelDelay->setText(QApplication::translate("SerialPortAssistant", "\351\227\264\351\232\224", nullptr));
        delay->setText(QApplication::translate("SerialPortAssistant", "1000", nullptr));
        labelMs->setText(QApplication::translate("SerialPortAssistant", "ms", nullptr));
        loop->setText(QApplication::translate("SerialPortAssistant", "\345\276\252\347\216\257\345\217\221\351\200\201", nullptr));
        labelTimes->setText(QApplication::translate("SerialPortAssistant", "\351\207\215\345\244\215", nullptr));
        times->setText(QApplication::translate("SerialPortAssistant", "10", nullptr));
        label->setText(QApplication::translate("SerialPortAssistant", "\346\254\241", nullptr));
        basicSetting->setTitle(QApplication::translate("SerialPortAssistant", "\344\270\262\345\217\243\350\256\276\347\275\256", nullptr));
        checkBox_12->setText(QString());
        A_Reactive_power->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\346\227\240\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_13->setText(QString());
        B_Reactive_power->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\346\227\240\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_14->setText(QString());
        C_Reactive_power->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\346\227\240\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_15->setText(QString());
        A_Apparent_power->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\350\247\206\345\234\250\345\212\237\347\216\207", nullptr));
        checkBox_16->setText(QString());
        B_Apparent_power->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\350\247\206\345\234\250\345\212\237\347\216\207", nullptr));
        checkBox_17->setText(QString());
        C_Apparent_power->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\350\247\206\345\234\250\345\212\237\347\216\207", nullptr));
        checkBox_18->setText(QString());
        A_factor_power->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        checkBox_19->setText(QString());
        B_factor_power->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        checkBox_20->setText(QString());
        C_factor_power->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        checkBox_21->setText(QString());
        Total_active_power->setText(QApplication::translate("SerialPortAssistant", "\346\200\273\346\234\211\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_22->setText(QString());
        Total_Reactive_power->setText(QApplication::translate("SerialPortAssistant", "\346\200\273\346\227\240\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_23->setText(QString());
        Total_Apparent_power->setText(QApplication::translate("SerialPortAssistant", "\346\200\273\350\247\206\345\234\250\345\212\237\347\216\207", nullptr));
        checkBox_24->setText(QString());
        A_total_power->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\346\200\273\347\224\265\350\203\275", nullptr));
        checkBox_25->setText(QString());
        B_total_power->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\346\200\273\347\224\265\350\203\275", nullptr));
        checkBox_26->setText(QString());
        C_total_power->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\346\200\273\347\224\265\350\203\275", nullptr));
        labelSerialPortNumber->setText(QApplication::translate("SerialPortAssistant", "\344\270\262\345\217\243:", nullptr));
        labelBaudRate->setText(QApplication::translate("SerialPortAssistant", "\346\263\242\347\211\271\347\216\207:", nullptr));
        labelDataBits->setText(QApplication::translate("SerialPortAssistant", "\346\225\260\346\215\256\344\275\215:", nullptr));
        labelParity->setText(QApplication::translate("SerialPortAssistant", "\346\240\241\351\252\214\344\275\215:", nullptr));
        labelStopBits->setText(QApplication::translate("SerialPortAssistant", "\345\201\234\346\255\242\344\275\215:", nullptr));
        serialPortSwitch->setText(QApplication::translate("SerialPortAssistant", "\346\211\223\345\274\200\344\270\262\345\217\243", nullptr));
        checkBox_9->setText(QString());
        A_active_power->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\346\234\211\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_10->setText(QString());
        B_active_power->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\346\234\211\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox_11->setText(QString());
        C_active_power->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\346\234\211\345\212\237\345\212\237\347\216\207", nullptr));
        checkBox->setText(QString());
        Get_Active_Electric->setText(QApplication::translate("SerialPortAssistant", "\345\275\223\345\211\215\346\255\243\345\220\221\346\234\211\345\212\237\346\200\273\347\224\265\350\203\275", nullptr));
        checkBox_1->setText(QString());
        power_frequency->setText(QApplication::translate("SerialPortAssistant", "\347\224\265\347\275\221\351\242\221\347\216\207", nullptr));
        checkBox_2->setText(QString());
        N_Electric->setText(QApplication::translate("SerialPortAssistant", "N\347\233\270\347\224\265\346\265\201", nullptr));
        checkBox_6->setText(QString());
        A_Electric->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\347\224\265\346\265\201", nullptr));
        checkBox_7->setText(QString());
        B_Electric->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\347\224\265\346\265\201", nullptr));
        checkBox_8->setText(QString());
        C_Electric->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\347\224\265\346\265\201", nullptr));
        checkBox_27->setText(QString());
        Total_power_factor_->setText(QApplication::translate("SerialPortAssistant", "\346\200\273\345\212\237\347\216\207\345\233\240\346\225\260", nullptr));
        testall->setText(QApplication::translate("SerialPortAssistant", "\345\213\276\351\200\211\346\265\213\350\257\225", nullptr));
        checkBox_3->setText(QString());
        A_Voltage->setText(QApplication::translate("SerialPortAssistant", "A\347\233\270\347\224\265\345\216\213", nullptr));
        checkBox_4->setText(QString());
        B_Voltage->setText(QApplication::translate("SerialPortAssistant", "B\347\233\270\347\224\265\345\216\213", nullptr));
        checkBox_5->setText(QString());
        C_Voltage->setText(QApplication::translate("SerialPortAssistant", "C\347\233\270\347\224\265\345\216\213", nullptr));
        extraSetting->setTitle(QApplication::translate("SerialPortAssistant", "\350\276\205\345\212\251\345\212\237\350\203\275", nullptr));
        autoNewLine->setText(QApplication::translate("SerialPortAssistant", "\350\207\252\345\212\250\346\215\242\350\241\214", nullptr));
        doubleColor->setText(QApplication::translate("SerialPortAssistant", "\346\224\266\345\217\221\345\217\214\350\211\262\346\230\276\347\244\272", nullptr));
        showTime->setText(QApplication::translate("SerialPortAssistant", "\346\230\276\347\244\272\346\224\266\345\217\221\346\227\266\351\227\264", nullptr));
        hexadecimaleReceive->setText(QApplication::translate("SerialPortAssistant", "\345\215\201\345\205\255\350\277\233\345\210\266\346\230\276\347\244\272", nullptr));
        hexadecimalSend->setText(QApplication::translate("SerialPortAssistant", "\345\215\201\345\205\255\350\277\233\345\210\266\345\217\221\351\200\201", nullptr));
        clear->setText(QApplication::translate("SerialPortAssistant", "\346\270\205\347\251\272\346\216\245\345\217\227\346\225\260\346\215\256", nullptr));
        sendFile->setText(QApplication::translate("SerialPortAssistant", "\345\217\221\351\200\201\346\226\207\344\273\266", nullptr));
        menu_F->setTitle(QApplication::translate("SerialPortAssistant", "\346\226\207\344\273\266(&F)", nullptr));
        menu_H->setTitle(QApplication::translate("SerialPortAssistant", "\345\270\256\345\212\251(&H)", nullptr));
    } // retranslateUi

};

namespace Ui {
    class SerialPortAssistant: public Ui_SerialPortAssistant {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORTASSISTANT_H
