#include "event_log.h"
#include "ui_event_log.h"

Event_log::Event_log(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Event_log)
{
    ui->setupUi(this);

    /*去除标题栏状态栏*/
    //this->setWindowFlags(Qt::FramelessWindowHint | Qt::Tool );

    //失压记录界面
    Event_log::losspressure = new Loss_pressure;
    //欠压记录界面
    Event_log::undervoltage = new Undervoltage;
    //失压记录关联槽函数
    connect(losspressure,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //欠压记录关联槽函数
    connect(undervoltage,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));

}

Event_log::~Event_log()
{
    delete ui;
}

void Event_log::on_pushButton_clicked()
{
    losspressure->show();
    this->hide();
}

void Event_log::on_Undervoltage_clicked()
{
    undervoltage->show();
    this->hide();
}

void Event_log::SendRecvData(QString text1,QString text2)
{
    emit sendData(text1,text2);
}


