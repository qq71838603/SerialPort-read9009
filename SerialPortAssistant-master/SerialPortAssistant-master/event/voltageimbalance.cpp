#include "voltageimbalance.h"
#include "ui_voltageimbalance.h"

voltageimbalance::voltageimbalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::voltageimbalance)
{
    ui->setupUi(this);
}

voltageimbalance::~voltageimbalance()
{
    delete ui;
}

void voltageimbalance::on_Avoltageimbalance_clicked()
{
    emit sendeventData("电压不平衡","68 11 11 11 11 11 11 68 11 04 33 33 3C 36 23 16");
    this->hide();
}
