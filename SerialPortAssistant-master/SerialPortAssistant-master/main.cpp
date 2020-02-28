#include "serialportassistant.h"
#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SerialPortAssistant w;
    w.setWindowIcon(QIcon(":/rsc/dianbiao.png"));
    w.show();
    return a.exec();
}
