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

    void on_query_button_clicked();

    void on_query_button_2_clicked();

private:

    QString get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0);

    Ui::qualified_rateofvoltage *ui;
};

#endif // QUALIFIED_RATEOFVOLTAGE_H
