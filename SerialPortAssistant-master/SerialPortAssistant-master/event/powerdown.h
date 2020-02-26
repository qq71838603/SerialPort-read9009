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

private:
    Ui::powerdown *ui;
};

#endif // POWERDOWN_H
