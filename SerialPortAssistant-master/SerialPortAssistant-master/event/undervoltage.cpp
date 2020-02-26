#include "undervoltage.h"
#include "ui_undervoltage.h"

Undervoltage::Undervoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Undervoltage)
{
    ui->setupUi(this);
}

Undervoltage::~Undervoltage()
{
    delete ui;
}

void Undervoltage::on_ABCUndervoltage_clicked()
{
    emit sendeventData("三相欠压","68 11 11 11 11 11 11 68 11 04 33 33 35 36 1C 16");
    this->hide();
}
