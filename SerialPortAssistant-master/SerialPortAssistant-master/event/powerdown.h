#ifndef POWERDOWN_H
#define POWERDOWN_H

#include <QWidget>

namespace Ui {
class powerdown;
}

class powerdown : public QWidget
{
    Q_OBJECT

public:
    explicit powerdown(QWidget *parent = nullptr);
    ~powerdown();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_Apowerdown_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::powerdown *ui;
};

#endif // POWERDOWN_H
