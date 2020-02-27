#ifndef OVERCURRENT_H
#define OVERCURRENT_H

#include <QWidget>

namespace Ui {
class overcurrent;
}

class overcurrent : public QWidget
{
    Q_OBJECT

public:
    explicit overcurrent(QWidget *parent = nullptr);
    ~overcurrent();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCovercurrent_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::overcurrent *ui;
};

#endif // OVERCURRENT_H
