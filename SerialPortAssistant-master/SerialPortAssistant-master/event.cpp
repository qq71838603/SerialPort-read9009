#include "event.h"
#include "ui_event.h"

event::event(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::event)
{
    ui->setupUi(this);
}

event::~event()
{
    delete ui;
}

void event::on_pushButton_clicked()
{

}
