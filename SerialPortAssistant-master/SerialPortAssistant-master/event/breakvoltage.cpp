#include "breakvoltage.h"
#include "ui_breakvoltage.h"

breakvoltage::breakvoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::breakvoltage)
{
    ui->setupUi(this);
}

breakvoltage::~breakvoltage()
{
    delete ui;
}

void breakvoltage::on_ABCbreakvoltage_clicked()
{
    emit sendeventData("三相断相","68 11 11 11 11 11 11 68 11 04 33 33 37 36 1E 16");
    this->hide();
}
