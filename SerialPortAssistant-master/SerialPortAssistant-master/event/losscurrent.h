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

private:
    Ui::losscurrent *ui;
};

#endif // LOSSCURRENT_H
