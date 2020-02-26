#ifndef UNDERVOLTAGE_H
#define UNDERVOLTAGE_H

#include <QWidget>

namespace Ui {
class Undervoltage;
}

class Undervoltage : public QWidget
{
    Q_OBJECT

public:
    explicit Undervoltage(QWidget *parent = nullptr);
    ~Undervoltage();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCUndervoltage_clicked();

private:
    Ui::Undervoltage *ui;
};

#endif // UNDERVOLTAGE_H
