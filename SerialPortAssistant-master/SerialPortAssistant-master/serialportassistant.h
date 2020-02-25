#ifndef SERIALPORTASSISTANT_H
#define SERIALPORTASSISTANT_H

//#define DEBUG

#include <QMainWindow>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QMessageBox>
#include <QDateTime>
#include <QFileDialog>
#include <QFile>
#include <QTimer>
#include <QScrollBar>
#include "helpdialog.h"
#include "event_log.h"


#ifdef DEBUG
#include <QDebug>
#endif

namespace Ui {
class SerialPortAssistant;
}

class SerialPortAssistant : public QMainWindow
{
    Q_OBJECT

public:
    QList<QSerialPort::BaudRate> baudRate;
    QList<QSerialPort::DataBits> dataBits;
    QList<QSerialPort::Parity> parity;
    QList<QSerialPort::StopBits> stopBits;

    explicit SerialPortAssistant(QWidget *parent = 0);
    ~SerialPortAssistant();
    void insertDataDisplay(const QString& text,const QColor& color=Qt::black);
    void insertDataDisplay_(const QString& text,const QColor& color=Qt::black);
    void Handle_data(QString& text1,const QString& text2);

    bool sleep(int msec);
    QString enddisplay;
    int flag = 0;

    Event_log *v;


public slots:
    void switchSerialPort(void);
    void receive(void);
    void send(void);
    void transmit(void);
    void transmitString(void);
    void transmitHexadecimal(void);
    void transmitCircularly(void);
    void transmitFile(void);
    void openFile(void);
    void saveAs(void);
    void clear(void);
    void on_Get_Active_Electric_clicked(void);
    void on_power_frequency_clicked();
    void on_sendclear_clicked(void);


private slots:
    void on_A_Electric_clicked();
    void on_B_Electric_clicked();
    void on_C_Electric_clicked();
    void on_A_active_power_clicked();
    void on_B_active_power_clicked();
    void on_C_active_power_clicked();
    void on_A_Reactive_power_clicked();
    void on_B_Reactive_power_clicked();
    void on_C_Reactive_power_clicked();
    void on_A_Apparent_power_clicked();
    void on_B_Apparent_power_clicked();
    void on_C_Apparent_power_clicked();
    void on_A_factor_power_clicked();
    void on_B_factor_power_clicked();
    void on_C_factor_power_clicked();
    void on_Total_active_power_clicked();
    void on_Total_Reactive_power_clicked();
    void on_Total_Apparent_power_clicked();
    void on_Total_power_factor__clicked();
    void on_A_Voltage_clicked();
    void on_B_Voltage_clicked();
    void on_C_Voltage_clicked();
    void on_N_Electric_clicked();
    void on_A_total_power_clicked();
    void on_B_total_power_clicked();
    void on_C_total_power_clicked();
    void on_Temperature_humidity_clicked();

    void on_testall_clicked();

    void on_checkBox_28_stateChanged();

    void on_query_version_clicked();

    void receivedata(QString text1,const QString text2);

    void on_pushButton_clicked();

private:
    Ui::SerialPortAssistant *ui;
    HelpDialog* helpDialog;
    QSerialPort* port;
    QTimer* timer;
    QList<QSerialPortInfo> infolist;
    bool isPortOpen = false;
    int delayms;
    int looptimes;
    void initSerialPortSetting(void);
    void connections(void);

#ifdef DEBUG
    void test(void);
#endif
};

#endif // SERIALPORTASSISTANT_H
