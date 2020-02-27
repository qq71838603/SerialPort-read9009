#include "loss_pressure.h"
#include "ui_loss_pressure.h"

Loss_pressure::Loss_pressure(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::Loss_pressure)
{
    ui->setupUi(this);
}

Loss_pressure::~Loss_pressure()
{
    delete ui;
}

void Loss_pressure::on_pushButton_clicked()
{
    emit sendeventData("三相失压:","68 11 11 11 11 11 11 68 11 04 33 33 34 36 1B 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA1_clicked()
{
    emit sendeventData("上1次A相失压记录:","68 11 11 11 11 11 11 68 11 04 34 34 34 36 1D 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA2_clicked()
{
    emit sendeventData("上2次A相失压记录:","68 11 11 11 11 11 11 68 11 04 35 34 34 36 1E 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA3_clicked()
{
    emit sendeventData("上3次A相失压记录:","68 11 11 11 11 11 11 68 11 04 36 34 34 36 1F 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA4_clicked()
{
    emit sendeventData("上4次A相失压记录:","68 11 11 11 11 11 11 68 11 04 37 34 34 36 20 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA5_clicked()
{
    emit sendeventData("上5次A相失压记录:","68 11 11 11 11 11 11 68 11 04 38 34 34 36 21 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA6_clicked()
{
    emit sendeventData("上6次A相失压记录:","68 11 11 11 11 11 11 68 11 04 39 34 34 36 22 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA7_clicked()
{
    emit sendeventData("上7次A相失压记录:","68 11 11 11 11 11 11 68 11 04 3A 34 34 36 23 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA8_clicked()
{
    emit sendeventData("上8次A相失压记录:","68 11 11 11 11 11 11 68 11 04 3B 34 34 36 24 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA9_clicked()
{
    emit sendeventData("上9次A相失压记录:","68 11 11 11 11 11 11 68 11 04 3C 34 34 36 25 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureA10_clicked()
{
    emit sendeventData("上10次A相失压记录:","68 11 11 11 11 11 11 68 11 04 3D 34 34 36 26 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB1_clicked()
{
    emit sendeventData("上1次B相失压记录:","68 11 11 11 11 11 11 68 11 04 34 35 34 36 1E 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB2_clicked()
{
    emit sendeventData("上2次B相失压记录:","68 11 11 11 11 11 11 68 11 04 35 35 34 36 1F 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB3_clicked()
{
    emit sendeventData("上3次B相失压记录:","68 11 11 11 11 11 11 68 11 04 36 35 34 36 20 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB4_clicked()
{
    emit sendeventData("上4次B相失压记录:","68 11 11 11 11 11 11 68 11 04 37 35 34 36 21 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB5_clicked()
{
    emit sendeventData("上5次B相失压记录:","68 11 11 11 11 11 11 68 11 04 38 35 34 36 22 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB6_clicked()
{
    emit sendeventData("上6次B相失压记录:","68 11 11 11 11 11 11 68 11 04 39 35 34 36 23 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB7_clicked()
{
    emit sendeventData("上7次B相失压记录:","68 11 11 11 11 11 11 68 11 04 3A 35 34 36 24 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB8_clicked()
{
    emit sendeventData("上8次B相失压记录:","68 11 11 11 11 11 11 68 11 04 3B 35 34 36 25 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB9_clicked()
{
    emit sendeventData("上9次B相失压记录:","68 11 11 11 11 11 11 68 11 04 3C 35 34 36 26 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureB10_clicked()
{
    emit sendeventData("上10次B相失压记录:","68 11 11 11 11 11 11 68 11 04 3D 35 34 36 27 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC1_clicked()
{
    emit sendeventData("上1次C相失压记录:","68 11 11 11 11 11 11 68 11 04 34 36 34 36 1F 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC2_clicked()
{
    emit sendeventData("上2次C相失压记录:","68 11 11 11 11 11 11 68 11 04 35 36 34 36 20 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC3_clicked()
{
    emit sendeventData("上3次C相失压记录:","68 11 11 11 11 11 11 68 11 04 36 36 34 36 21 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC4_clicked()
{
    emit sendeventData("上4次C相失压记录:","68 11 11 11 11 11 11 68 11 04 37 36 34 36 22 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC5_clicked()
{
    emit sendeventData("上5次C相失压记录:","68 11 11 11 11 11 11 68 11 04 38 36 34 36 23 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC6_clicked()
{
    emit sendeventData("上6次C相失压记录:","68 11 11 11 11 11 11 68 11 04 39 36 34 36 24 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC7_clicked()
{
    emit sendeventData("上7次C相失压记录:","68 11 11 11 11 11 11 68 11 04 3A 36 34 36 25 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC8_clicked()
{
    emit sendeventData("上8次C相失压记录:","68 11 11 11 11 11 11 68 11 04 3B 36 34 36 26 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC9_clicked()
{
    emit sendeventData("上9次C相失压记录:","68 11 11 11 11 11 11 68 11 04 3C 36 34 36 27 16");
    this->hide();
}

void Loss_pressure::on_Loss_pressureC10_clicked()
{
    emit sendeventData("上10次C相失压记录:","68 11 11 11 11 11 11 68 11 04 3D 36 34 36 28 16");
    this->hide();
}
