#include "overcurrent.h"
#include "ui_overcurrent.h"

overcurrent::overcurrent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overcurrent)
{
    ui->setupUi(this);
}

overcurrent::~overcurrent()
{
    delete ui;
}

void overcurrent::on_ABCovercurrent_clicked()
{
    emit sendeventData("三相过流","68 11 11 11 11 11 11 68 11 04 33 33 3F 36 26 16");
    this->hide();
}
