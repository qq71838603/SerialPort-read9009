#ifndef EVENT_LOG_H
#define EVENT_LOG_H

#include <QWidget>
#include "loss_pressure.h"
#include "undervoltage.h"

namespace Ui {
class Event_log;
}

class Event_log : public QWidget
{
    Q_OBJECT

public:
    explicit Event_log(QWidget *parent = nullptr);
    ~Event_log();

    Loss_pressure * losspressure;
    Undervoltage * undervoltage;


signals:
    void  sendData(QString,QString);


private slots:
    void on_pushButton_clicked();

    void SendRecvData(QString ,QString );


    void on_Undervoltage_clicked();

private:
    Ui::Event_log *ui;
};

#endif // EVENT_LOG_H
