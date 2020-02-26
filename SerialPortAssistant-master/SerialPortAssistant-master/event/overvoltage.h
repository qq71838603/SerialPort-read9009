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

private:
    Ui::Overvoltage *ui;
};

#endif // OVERVOLTAGE_H
