#ifndef CURRENTIMBALANCE_H
#define CURRENTIMBALANCE_H

#include <QWidget>

namespace Ui {
class currentimbalance;
}

class currentimbalance : public QWidget
{
    Q_OBJECT

public:
    explicit currentimbalance(QWidget *parent = nullptr);
    ~currentimbalance();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_Acurrentimbalance_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::currentimbalance *ui;
};

#endif // CURRENTIMBALANCE_H
