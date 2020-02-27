#ifndef LOSSCURRENT_H
#define LOSSCURRENT_H

#include <QWidget>

namespace Ui {
class losscurrent;
}

class losscurrent : public QWidget
{
    Q_OBJECT

public:
    explicit losscurrent(QWidget *parent = nullptr);
    ~losscurrent();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABClosscurrent_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::losscurrent *ui;
};

#endif // LOSSCURRENT_H
