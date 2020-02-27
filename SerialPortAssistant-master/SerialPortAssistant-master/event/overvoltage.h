#ifndef OVERVOLTAGE_H
#define OVERVOLTAGE_H

#include <QWidget>

namespace Ui {
class Overvoltage;
}

class Overvoltage : public QWidget
{
    Q_OBJECT

public:
    explicit Overvoltage(QWidget *parent = nullptr);
    ~Overvoltage();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCOvervoltage_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::Overvoltage *ui;
};

#endif // OVERVOLTAGE_H
