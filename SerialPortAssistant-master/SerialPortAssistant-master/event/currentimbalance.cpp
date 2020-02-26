#include "currentimbalance.h"
#include "ui_currentimbalance.h"

currentimbalance::currentimbalance(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::currentimbalance)
{
    ui->setupUi(this);
}

currentimbalance::~currentimbalance()
{
    delete ui;
}

void currentimbalance::on_Acurrentimbalance_clicked()
{
    emit sendeventData("电流不平衡","68 11 11 11 11 11 11 68 11 04 33 33 3D 36 24 16");
    this->hide();
}
