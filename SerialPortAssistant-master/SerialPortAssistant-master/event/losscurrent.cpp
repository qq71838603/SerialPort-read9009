#include "losscurrent.h"
#include "ui_losscurrent.h"

losscurrent::losscurrent(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::losscurrent)
{
    ui->setupUi(this);
}

losscurrent::~losscurrent()
{
    delete ui;
}

void losscurrent::on_ABClosscurrent_clicked()
{
    emit sendeventData("三相失流","68 11 11 11 11 11 11 68 11 04 33 33 3E 36 25 16");
    this->hide();
}
