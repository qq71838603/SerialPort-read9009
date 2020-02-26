#include "overvoltage.h"
#include "ui_overvoltage.h"

Overvoltage::Overvoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Overvoltage)
{
    ui->setupUi(this);
}

Overvoltage::~Overvoltage()
{
    delete ui;
}

void Overvoltage::on_ABCOvervoltage_clicked()
{
    emit sendeventData("三相过压","68 11 11 11 11 11 11 68 11 04 33 33 36 36 1D 16");
    this->hide();
}
