#ifndef BREAKCURRENT_H
#define BREAKCURRENT_H

#include <QWidget>

namespace Ui {
class breakcurrent;
}

class breakcurrent : public QWidget
{
    Q_OBJECT

public:
    explicit breakcurrent(QWidget *parent = nullptr);
    ~breakcurrent();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCbreakcurrent_clicked();

private:
    Ui::breakcurrent *ui;
};

#endif // BREAKCURRENT_H
