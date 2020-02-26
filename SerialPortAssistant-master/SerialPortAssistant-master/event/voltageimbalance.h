#ifndef VOLTAGEIMBALANCE_H
#define VOLTAGEIMBALANCE_H

#include <QWidget>

namespace Ui {
class voltageimbalance;
}

class voltageimbalance : public QWidget
{
    Q_OBJECT

public:
    explicit voltageimbalance(QWidget *parent = nullptr);
    ~voltageimbalance();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_Avoltageimbalance_clicked();

private:
    Ui::voltageimbalance *ui;
};

#endif // VOLTAGEIMBALANCE_H
