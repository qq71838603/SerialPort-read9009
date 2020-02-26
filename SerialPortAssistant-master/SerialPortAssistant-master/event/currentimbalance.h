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

private:
    Ui::currentimbalance *ui;
};

#endif // CURRENTIMBALANCE_H
