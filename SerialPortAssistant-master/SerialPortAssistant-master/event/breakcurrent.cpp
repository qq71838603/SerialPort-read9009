#include "breakcurrent.h"
#include "ui_breakcurrent.h"

breakcurrent::breakcurrent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::breakcurrent)
{
    ui->setupUi(this);
}

breakcurrent::~breakcurrent()
{
    delete ui;
}

void breakcurrent::on_ABCbreakcurrent_clicked()
{
    emit sendeventData("三相断流","68 11 11 11 11 11 11 68 11 04 33 33 40 36 27 16");
    this->hide();
}
