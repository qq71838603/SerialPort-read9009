#include "powerdown.h"
#include "ui_powerdown.h"

powerdown::powerdown(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::powerdown)
{
    ui->setupUi(this);
}

powerdown::~powerdown()
{
    delete ui;
}

void powerdown::on_Apowerdown_clicked()
{
    emit sendeventData("掉电总次数","68 11 11 11 11 11 11 68 11 04 33 33 44 36 2B 16");
    this->hide();
}
