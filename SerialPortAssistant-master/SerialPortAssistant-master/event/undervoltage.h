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

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::Undervoltage *ui;
};

#endif // UNDERVOLTAGE_H
