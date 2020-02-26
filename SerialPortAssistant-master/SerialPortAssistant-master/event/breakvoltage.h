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

private:
    Ui::breakvoltage *ui;
};

#endif // BREAKVOLTAGE_H
