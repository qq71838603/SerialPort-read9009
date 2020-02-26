#include "overload.h"
#include "ui_overload.h"

overload::overload(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::overload)
{
    ui->setupUi(this);
}

overload::~overload()
{
    delete ui;
}

void overload::on_ABCoverload_clicked()
{
    emit sendeventData("三相过载","68 11 11 11 11 11 11 68 11 04 33 33 42 36 29 16");
    this->hide();
}
