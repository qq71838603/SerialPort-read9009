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

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::breakcurrent *ui;
};

#endif // BREAKCURRENT_H
