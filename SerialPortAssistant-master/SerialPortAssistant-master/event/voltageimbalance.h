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

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::voltageimbalance *ui;
};

#endif // VOLTAGEIMBALANCE_H
