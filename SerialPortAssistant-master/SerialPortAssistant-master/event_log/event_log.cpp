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
    //过压记录界面
    Event_log::overvoltage = new Overvoltage;
    //断相记录界面
    Event_log::breakvoltage1 = new breakvoltage;
    //电压不平衡记录界面
    Event_log::voltageimbalance1 = new voltageimbalance;
    //电流不平衡记录界面
    Event_log::currentimbalance1 = new currentimbalance;
    //失流记录页面
    Event_log::losscurrent1 = new losscurrent;
    //过流记录页面
    Event_log::overcurrent1 = new overcurrent;
    //断流记录页面
    Event_log::breakcurrent1 = new breakcurrent;
    //过载记录页面
    Event_log::overload1 = new overload;
    //电压合格率记录页面
    Event_log::qualified_rateofvoltage1 = new qualified_rateofvoltage;
    //掉电记录页面
    Event_log::powerdown1 = new powerdown;
    //失压记录关联槽函数
    connect(losspressure,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //欠压记录关联槽函数
    connect(undervoltage,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //过压记录关联槽函数
    connect(overvoltage,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //断相记录关联槽函数
    connect(breakvoltage1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //电压不平衡记录关联槽函数
    connect(voltageimbalance1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //电流不平衡记录关联槽函数
    connect(currentimbalance1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //失流记录关联槽函数
    connect(losscurrent1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //过流记录关联槽函数
    connect(overcurrent1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //断流记录关联槽函数
    connect(breakcurrent1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //过载记录关联槽函数
    connect(overload1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //电压合格率记录关联槽函数
    connect(qualified_rateofvoltage1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
    //掉电记录关联槽函数
    connect(powerdown1,SIGNAL(sendeventData(QString,QString)),this,SLOT(SendRecvData(QString,QString)));
}

Event_log::~Event_log()
{
    delete ui;
}

//槽函数,发送信号
void Event_log::SendRecvData(QString text1,QString text2)
{
    emit sendData(text1,text2);
}

//显示失压记录页面
void Event_log::on_pushButton_clicked()
{
    losspressure->show();
    this->hide();
}

//显示欠压记录页面
void Event_log::on_Undervoltage_clicked()
{
    undervoltage->show();
    this->hide();
}

//显示过压记录页面
void Event_log::on_Overvoltage_clicked()
{
    overvoltage->show();
    this->hide();
}

//显示断相记录页面
void Event_log::on_breakvoltage_clicked()
{
    breakvoltage1->show();
    this->hide();
}

//显示电压不平衡记录页面
void Event_log::on_voltageimbalance_clicked()
{
    voltageimbalance1->show();
    this->hide();
}

//显示电流不平衡记录页面
void Event_log::on_currentimbalance_clicked()
{
    currentimbalance1->show();
    this->hide();
}

//显示失流记录页面
void Event_log::on_losscurrent_clicked()
{
    losscurrent1->show();
    this->hide();
}

//显示过流记录页面
void Event_log::on_overcurrent_clicked()
{
    overcurrent1->show();
    this->hide();
}

//显示断流记录页面
void Event_log::on_breakcurrent_clicked()
{
    breakcurrent1->show();
    this->hide();
}

//显示过载记录页面
void Event_log::on_overload_clicked()
{
    overload1->show();
    this->hide();
}

//显示电压合格率记录页面
void Event_log::on_qualified_rateofvoltage_clicked()
{
    qualified_rateofvoltage1->show();
    this->hide();
}

//显示掉电记录页面
void Event_log::on_powerdown_clicked()
{
    powerdown1->show();
    this->hide();
}
