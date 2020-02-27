#ifndef BREAKVOLTAGE_H
#define BREAKVOLTAGE_H

#include <QWidget>

namespace Ui {
class breakvoltage;
}

class breakvoltage : public QWidget
{
    Q_OBJECT

public:
    explicit breakvoltage(QWidget *parent = nullptr);
    ~breakvoltage();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCbreakvoltage_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::breakvoltage *ui;
};

#endif // BREAKVOLTAGE_H
