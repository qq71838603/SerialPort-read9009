#ifndef QUALIFIED_RATEOFVOLTAGE_H
#define QUALIFIED_RATEOFVOLTAGE_H

#include <QWidget>

namespace Ui {
class qualified_rateofvoltage;
}

class qualified_rateofvoltage : public QWidget
{
    Q_OBJECT

public:
    explicit qualified_rateofvoltage(QWidget *parent = nullptr);
    ~qualified_rateofvoltage();

signals:
    void  sendeventData(QString,QString);

private slots:
    void on_ABCqualified_rateofvoltage_clicked();

private:
    Ui::qualified_rateofvoltage *ui;
};

#endif // QUALIFIED_RATEOFVOLTAGE_H
