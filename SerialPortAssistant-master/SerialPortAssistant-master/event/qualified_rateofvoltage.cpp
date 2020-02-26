#include "qualified_rateofvoltage.h"
#include "ui_qualified_rateofvoltage.h"

qualified_rateofvoltage::qualified_rateofvoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qualified_rateofvoltage)
{
    ui->setupUi(this);
}

qualified_rateofvoltage::~qualified_rateofvoltage()
{
    delete ui;
}

void qualified_rateofvoltage::on_ABCqualified_rateofvoltage_clicked()
{
    emit sendeventData("本月电压合格率","68 11 11 11 11 11 11 68 11 04 33 33 43 36 2A 16");
    this->hide();
}
