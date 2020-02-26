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

private:
    Ui::overcurrent *ui;
};

#endif // OVERCURRENT_H
