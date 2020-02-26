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

private:
    Ui::overload *ui;
};

#endif // OVERLOAD_H
