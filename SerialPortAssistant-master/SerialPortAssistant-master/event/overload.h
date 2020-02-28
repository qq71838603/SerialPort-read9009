#ifndef OVERLOAD_H
#define OVERLOAD_H

#include <QWidget>

namespace Ui {
class overload;
}

class overload : public QWidget
{
    Q_OBJECT

public:
    explicit overload(QWidget *parent = nullptr);
    ~overload();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCoverload_clicked();

    void on_query_button_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::overload *ui;
};

#endif // OVERLOAD_H
