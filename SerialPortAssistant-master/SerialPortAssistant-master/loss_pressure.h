#ifndef LOSS_PRESSURE_H
#define LOSS_PRESSURE_H

#include <QWidget>

namespace Ui {
class Loss_pressure;
}

class Loss_pressure : public QWidget
{
    Q_OBJECT

public:
    explicit Loss_pressure(QWidget *parent = nullptr);
    ~Loss_pressure();

signals:
    void  sendeventData(QString,QString);

private slots:
    //三相失压总次数总时间
    void on_pushButton_clicked();

    //A相失压记录
    void on_Loss_pressureA1_clicked();
    void on_Loss_pressureA2_clicked();
    void on_Loss_pressureA3_clicked();
    void on_Loss_pressureA4_clicked();
    void on_Loss_pressureA5_clicked();
    void on_Loss_pressureA6_clicked();
    void on_Loss_pressureA7_clicked();
    void on_Loss_pressureA8_clicked();
    void on_Loss_pressureA9_clicked();
    void on_Loss_pressureA10_clicked();

    //B相失压记录
    void on_Loss_pressureB1_clicked();
    void on_Loss_pressureB2_clicked();
    void on_Loss_pressureB3_clicked();
    void on_Loss_pressureB4_clicked();
    void on_Loss_pressureB5_clicked();
    void on_Loss_pressureB6_clicked();
    void on_Loss_pressureB7_clicked();
    void on_Loss_pressureB8_clicked();
    void on_Loss_pressureB9_clicked();
    void on_Loss_pressureB10_clicked();

    //C相失压记录
    void on_Loss_pressureC1_clicked();
    void on_Loss_pressureC2_clicked();
    void on_Loss_pressureC3_clicked();
    void on_Loss_pressureC4_clicked();
    void on_Loss_pressureC5_clicked();
    void on_Loss_pressureC6_clicked();
    void on_Loss_pressureC7_clicked();
    void on_Loss_pressureC8_clicked();
    void on_Loss_pressureC9_clicked();
    void on_Loss_pressureC10_clicked();
private:
    Ui::Loss_pressure *ui;
};

#endif // LOSS_PRESSURE_H
