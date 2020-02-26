#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include <QWidget>
#include "event/loss_pressure.h"
#include "event/undervoltage.h"
#include "event/overvoltage.h"
#include "event/breakvoltage.h"
#include "event/voltageimbalance.h"
#include "event/currentimbalance.h"
#include "event/losscurrent.h"
#include "event/overcurrent.h"
#include "event/breakcurrent.h"
#include "event/overload.h"
#include "event/qualified_rateofvoltage.h"
#include "event/powerdown.h"

namespace Ui {
class Event_log;
}

class Event_log : public QWidget
{
    Q_OBJECT

public:
    explicit Event_log(QWidget *parent = nullptr);
    ~Event_log();

    //定义相应的事件页面
    Loss_pressure * losspressure;
    Undervoltage * undervoltage;
    Overvoltage * overvoltage;
    breakvoltage * breakvoltage1;
    voltageimbalance * voltageimbalance1;
    currentimbalance * currentimbalance1;
    losscurrent * losscurrent1;
    overcurrent * overcurrent1;
    breakcurrent * breakcurrent1;
    overload * overload1;
    qualified_rateofvoltage * qualified_rateofvoltage1;
    powerdown * powerdown1;


signals:
    void  sendData(QString,QString);


private slots:

    void SendRecvData(QString ,QString );

    //打开各个记录页面槽函数
    void on_pushButton_clicked();
    void on_Undervoltage_clicked();
    void on_Overvoltage_clicked();
    void on_breakvoltage_clicked();
    void on_voltageimbalance_clicked();
    void on_currentimbalance_clicked();
    void on_losscurrent_clicked();
    void on_overcurrent_clicked();
    void on_breakcurrent_clicked();
    void on_overload_clicked();
    void on_qualified_rateofvoltage_clicked();
    void on_powerdown_clicked();

private:
    Ui::Event_log *ui;
};

#endif // EVENT_LOG_H
