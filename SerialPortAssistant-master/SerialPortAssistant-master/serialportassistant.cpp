#include "serialportassistant.h"
#include "ui_serialportassistant.h"
#include <QDebug>

void StringToHex(QString str, QByteArray &senddata);


SerialPortAssistant::SerialPortAssistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialPortAssistant)
{
    ui->setupUi(this);
    port = new QSerialPort(this);
    helpDialog = new HelpDialog(this);
    timer = new QTimer(this);
    ui->send->setEnabled(false);
    ui->sendFile->setEnabled(false);
    ui->delay->setValidator(new QIntValidator(0, 10000, this));
    ui->times->setValidator(new QIntValidator(0, 10000, this));
    initSerialPortSetting();
    connections();

#ifdef DEBUG
    test();
#endif
}

SerialPortAssistant::~SerialPortAssistant()
{
    delete ui;
}


/* Initialize the serial port setting UI. */
void SerialPortAssistant::initSerialPortSetting(void)
{
    /* Insert the available serial ports into QComboBox. Keep infolist and ui->serialPortNumber in same order.*/
    infolist = QSerialPortInfo::availablePorts();
    foreach(const QSerialPortInfo& info,infolist)
    {
        ui->serialPortNumber->addItem(info.portName());
    }
    if(ui->serialPortNumber->count() == 0)
    {
        ui->serialPortNumber->addItem(tr("NULL"));
        ui->serialPortSwitch->setEnabled(false);
    }

    /* Insert choices of baud rate into QComboBox. Keep this->baudRate and baudRate in same order. */
    this->baudRate << QSerialPort::Baud2400  << QSerialPort::Baud115200 << QSerialPort::Baud57600
                   << QSerialPort::Baud38400 << QSerialPort::Baud19200 << QSerialPort::Baud9600 << QSerialPort::Baud4800
                   << QSerialPort::Baud1200;
    QStringList baudRate;
    baudRate << tr("2400") << tr("115200") << tr("57600")
             << tr("38400") << tr("19200") << tr("9600") << tr("4800")
             << tr("1200");
    ui->baudRate->addItems(baudRate);

    /* Insert choices of data bits into QComboBox. Keep this->dataBits and dataBits in same order. */
    this->dataBits << QSerialPort::Data8 << QSerialPort::Data7
                   << QSerialPort::Data6 << QSerialPort::Data5;
    QStringList dataBits;
    dataBits << tr("8") << tr("7") << tr("6") << tr("5");
    ui->dataBits->addItems(dataBits);

    /* Insert choices of parity into QComboBox. Keep this->parity and parity in same order. */
    this->parity << QSerialPort::EvenParity << QSerialPort::OddParity << QSerialPort::NoParity
                 << QSerialPort::SpaceParity << QSerialPort::MarkParity;
    QStringList parity;
    parity << tr("偶校验") << tr("奇校验") << tr("无校验")
           << tr("空校验") << tr("标记校验");
    ui->parity->addItems(parity);

    /* Insert choices of stop bits into QComboBox. Keep this->stopBits and stopBits in same order. */
    this->stopBits << QSerialPort::OneStop << QSerialPort::OneAndHalfStop << QSerialPort::TwoStop;
    QStringList stopBits;
    stopBits << tr("1") << tr("1.5") << tr("2");
    ui->stopBits->addItems(stopBits);

}


/* Connect all signals and slots. */
void SerialPortAssistant::connections(void)
{
    /* Close */
    connect(ui->actionExit,&QAction::triggered,this,&SerialPortAssistant::close);

    /* Show about. */
    connect(ui->actionAbout,&QAction::triggered,[this]{QMessageBox::information(this,tr("关于"),
                                                       tr("~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~\n"));});

    /* Show about Qt. */
    connect(ui->actionQt,&QAction::triggered,[this]{QMessageBox::aboutQt(this);});

    /* Open or close serial port. */
    connect(ui->serialPortSwitch,&QPushButton::clicked,this,&SerialPortAssistant::switchSerialPort);

    /* Show help */
    connect(ui->actionHelp,&QAction::triggered,helpDialog,&QWidget::show);

    /* Open and save file. */
    connect(ui->actionOpenFile,&QAction::triggered,this,&SerialPortAssistant::openFile);
    connect(ui->actionSaveFile,&QAction::triggered,this,&SerialPortAssistant::saveAs);

    /* Clear */
    connect(ui->clear,&QPushButton::clicked,this,&SerialPortAssistant::clear);

    /* Receive */
    connect(port,&QSerialPort::readyRead,this,&SerialPortAssistant::receive);

    /* Start send. */
    connect(ui->send,&QPushButton::clicked,this,&SerialPortAssistant::send);

    /* Transmit file. */
    connect(ui->sendFile,&QPushButton::clicked,this,&SerialPortAssistant::transmitFile);

    /* Transmit data. */
    connect(timer,&QTimer::timeout,this,&SerialPortAssistant::transmit);

    /* Stop transmit loop */
    connect(timer,&QTimer::timeout,[&]{looptimes--;if(looptimes<=0) timer->stop();});
}

/* Insert text into ui->dataDisplay with color(default black). */
void SerialPortAssistant::insertDataDisplay(const QString& text, const QColor& color)
{
    QTextCharFormat fmt;
    fmt.setForeground(color);
    //ui->dataDisplay->setCurrentCharFormat(fmt);
    //ui->dataDisplay->insertPlainText(text);
    ui->dataToSend->setCurrentCharFormat(fmt);
    ui->dataToSend->insertPlainText(text);
    //QScrollBar* scroll = ui->dataDisplay->verticalScrollBar();
    QScrollBar* scroll = ui->dataToSend->verticalScrollBar();
    scroll->setSliderPosition(scroll->maximum());
}

/* Insert text into ui->dataDisplay_ with color(default black). */
void SerialPortAssistant::insertDataDisplay_(const QString& text, const QColor& color)
{
    QTextCharFormat fmt;
    fmt.setForeground(color);
    ui->dataDisplay->setCurrentCharFormat(fmt);
    ui->dataDisplay->insertPlainText(text);
    QScrollBar* scroll = ui->dataDisplay->verticalScrollBar();
    scroll->setSliderPosition(scroll->maximum());
}


/* Open or close the serial port. */
void SerialPortAssistant::switchSerialPort(void)
{
    if(isPortOpen)
    {
        /* If serial port is open,close it. */
        port->close();
        ui->serialPortSwitch->setText(tr("打开串口"));
        isPortOpen = false;

        /* Enable all QComboBox.*/
        ui->serialPortNumber->setEnabled(true);
        ui->baudRate->setEnabled(true);
        ui->dataBits->setEnabled(true);
        ui->parity->setEnabled(true);
        ui->stopBits->setEnabled(true);
    }
    else
    {
        /* If serial port is closed,open it. */

        /* List and QComboBox are in same order,so they can use the same index. */
        port->setPort(infolist[ui->serialPortNumber->currentIndex()]);
        port->setBaudRate(baudRate[ui->baudRate->currentIndex()]);
        port->setDataBits(dataBits[ui->dataBits->currentIndex()]);
        port->setParity(parity[ui->parity->currentIndex()]);
        port->setStopBits(stopBits[ui->stopBits->currentIndex()]);
        if(port->open(QSerialPort::ReadWrite))
        {
            ui->serialPortSwitch->setText(tr("关闭串口"));
            isPortOpen = true;
            /* Disable all QComboBox.*/
            ui->serialPortNumber->setEnabled(false);
            ui->baudRate->setEnabled(false);
            ui->dataBits->setEnabled(false);
            ui->parity->setEnabled(false);
            ui->stopBits->setEnabled(false);
        }
        else
        {
            QString message = "Connect to " + ui->serialPortNumber->currentText() + " failed : " + port->errorString();
            statusBar()->showMessage(message,5000);
        }
    }

    /* Enable or disable ui->send QPushButton. */
    ui->send->setEnabled(isPortOpen);
    ui->sendFile->setEnabled(isPortOpen);
}

/* Receive data from serial port. */
void SerialPortAssistant::receive(void)
{
    /* Receive data. */
    QByteArray data = port->readAll();
    //qDebug()<<"data is :"<<data;
    QString display;
    /* Convert data to hexadecimal. */
    if(ui->hexadecimaleReceive->isChecked())
    {
        QString temp;
        for(int i=0; i < data.size(); i++)
        {
            temp.sprintf("%02x ",(unsigned char)data.at(i));
            display += temp;
        }
    }

    /* Add time to show. */
    if(ui->showTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        display = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + display;
    }
    /* Add newline to show. */
    if(ui->autoNewLine->isChecked())
    {
        display += "\n";
    }

    /* Show the data received. */
    insertDataDisplay(display,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);

    flag ++;
    enddisplay += display;
    //接受到的数据分为多段,平均7-8次发送完全部数据
    if(flag == 6 || flag == 7 || flag == 8)
    {
        QStringList listdisplay = enddisplay.split(" ");
        //qDebug()<< "listdisplay:"<<listdisplay;
        //电压,功率因数分割为了24个数据
        if(listdisplay.count() == 24)
        {
            QString tempdata,showdata;
            //电压
            if(listdisplay[16] == "34" && listdisplay[17] == "35")
            {
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                tempdata = listdisplay[19] + listdisplay[18];
                showdata = tempdata.mid(0,3) + "." + tempdata.mid(3,1)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            //功率因数
            else if(listdisplay[16] == "39")
            {
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                tempdata = listdisplay[19] + listdisplay[18];
                showdata = tempdata.mid(0,1) + "." + tempdata.mid(1,3)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            //电网频率
            else if(listdisplay[16] == "b3" || listdisplay[16] == "B3")
            {
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                tempdata = listdisplay[19] + listdisplay[18];
                showdata = tempdata.mid(0,2) + "." + tempdata.mid(1,2)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }

        }
        //电流,有功功率,无功功率,视在功率分割为25个数据
        else if(listdisplay.count() == 25)
        {
            QString tempdata,showdata;
            //电流
            if(listdisplay[16] == "35" && listdisplay[17] == "35")
            {
                listdisplay[20] = QString::number((listdisplay[20].toInt(nullptr,16) - 0x33),16);
                listdisplay[20] = QString("%1").arg(listdisplay[20].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                showdata = tempdata.mid(0,3) + "." + tempdata.mid(3,3)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            else if(listdisplay[16] == "b3" || listdisplay[16] == "B3")
            {
                listdisplay[20] = QString::number((listdisplay[20].toInt(nullptr,16) - 0x33),16);
                listdisplay[20] = QString("%1").arg(listdisplay[20].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                showdata = tempdata.mid(0,3) + "." + tempdata.mid(3,3)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            //有功功率,无功功率,视在功率
            else if(listdisplay[16] == "36" || listdisplay[16] == "37" || listdisplay[16] == "38" )
            {
                if(listdisplay[17] == "35")
                {
                    listdisplay[20] = QString::number((listdisplay[20].toInt(nullptr,16) - 0x33),16);
                    listdisplay[20] = QString("%1").arg(listdisplay[20].toInt(), 2, 10, QLatin1Char('0'));
                    listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                    listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                    listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                    listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));

                    tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                    showdata = tempdata.mid(0,2) + "." + tempdata.mid(2,4)+ "\n";

                    insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                    enddisplay.clear();
                    showdata.clear();
                    listdisplay.clear();
                    flag = 0;
                }
            }
        }
        //正向有功总电能,三相正向有功电能分割为了26个数据
        else if(listdisplay.count() == 26 && listdisplay[17] == "33" )
        {
            if( listdisplay[16] == "34" || listdisplay[16] == "48" || listdisplay[16] == "5c" || listdisplay[16] == "70")
            {
                listdisplay[21] = QString::number((listdisplay[21].toInt(nullptr,16) - 0x33),16);
                listdisplay[21] = QString("%1").arg(listdisplay[21].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[20] = QString::number((listdisplay[20].toInt(nullptr,16) - 0x33),16);
                listdisplay[20] = QString("%1").arg(listdisplay[20].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
                listdisplay[19] = QString("%1").arg(listdisplay[19].toInt(), 2, 10, QLatin1Char('0'));
                listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
                listdisplay[18] = QString("%1").arg(listdisplay[18].toInt(), 2, 10, QLatin1Char('0'));
                QString showdata = listdisplay[21] + listdisplay[20] + listdisplay[19] + "." + listdisplay[18]+"\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
        }
    }
    if(flag == 9)
    {
        flag = 0;
        enddisplay.clear();
    }
}

/* Start send. */
void SerialPortAssistant::send(void)
{
    if(ui->loop->isChecked())
    {
        transmitCircularly();//send some times.
    }
    else
    {
        transmit();  //send once.
    }

}

/* Transmit data from serial port. */
void  SerialPortAssistant::transmit()
{
    if(ui->hexadecimalSend->isChecked())
    {
        transmitHexadecimal();
    }
    else
    {
        transmitString();
    }
}

/* Transmit String from serial port. */
void SerialPortAssistant::transmitString(void)
{
    /* Transmit data. */
    QString data = ui->dataToSend->toPlainText();
    if(port->write(data.toStdString().c_str()) == -1)
    {
        statusBar()->showMessage("Send data failed : "+ port->errorString());
        return;
    }

    /* Add time to show. */
    if(ui->showTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        data = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + data;
    }
    /* Add newline to show. */
    if(ui->autoNewLine->isChecked())
    {
        data += "\n";
    }

    /* Show the date sended. */
    insertDataDisplay(data,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
}

/* Transmit hexadecimal number from serial port. */
void SerialPortAssistant::transmitHexadecimal(void)
{
    /* Check if the data is splited by withspace every 2 characters. */
    QString data = ui->dataToSend->toPlainText();
    QRegExp regExp(" *([0-9A-Fa-f]{2} +)+[0-9A-Fa-f]{2} *");
    if(regExp.exactMatch(data))
    {
        /* Convert every 2 characters to hexadecimal. */
        QStringList dataList = data.split(QRegExp(" +"));
        QString newData,showData;
        showData += "\n发送信息->";
        foreach(const QString& i, dataList)
        {
            showData += i + " ";
            int n = i.toInt(nullptr,16);
            newData += data.sprintf("%c",static_cast<char>(n));
        }

        /* Transmit data. */
        if(port->write(newData.toStdString().c_str()) == -1)
        {
            statusBar()->showMessage("Send data failed : "+ port->errorString());
            return;
        }

        /* Add time to show. */
        if(ui->showTime->isChecked())
        {
            QDateTime time = QDateTime::currentDateTime();
            showData = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + showData;
        }
        /* Add newline to show. */
        if(ui->autoNewLine->isChecked())
        {
            showData += "\n";
        }

        showData += "\n";

        /* Show data. */
        insertDataDisplay(showData,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
    }
    else
    {
        statusBar()->showMessage("Data format is error",5000);
    }
}

/* Transmit data circularly by setting. */
void SerialPortAssistant::transmitCircularly(void)
{
    delayms = ui->delay->text().toInt();
    looptimes = ui->times->text().toInt();
    if(looptimes>0)
    {
        timer->start(delayms);
    }
}

/* Transmit file from serial port. */
void SerialPortAssistant::transmitFile(void)
{
    QString filename = QFileDialog::getOpenFileName(this,tr("打开"));
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
    {
        statusBar()->showMessage("Open file failed",5000);
    }
    else if(port->write(file.readAll()) == -1)
    {
        statusBar()->showMessage("Send data failed : "+ port->errorString(),5000);
    }
    else
    {
        QString message = "[Sended file <" + filename +">]\n";
        insertDataDisplay(message,Qt::red);
    }
}

/* Read file's content to ui->dataToSend. */
void SerialPortAssistant::openFile(void)
{
    QString filename = QFileDialog::getOpenFileName(this,tr("打开"));
    QFile file(filename);
    if(!file.open(QFile::ReadOnly))
    {
        statusBar()->showMessage("Open file failed",5000);
        return;
    }
    ui->dataToSend->setPlainText(file.readAll());
    file.close();
}

/* Save content of ui->dataDisplay into file. */
void SerialPortAssistant::saveAs(void)
{
    QString filename = QFileDialog::getSaveFileName(this,tr("保存"));
    QFile file(filename);
    if(!file.open(QFile::WriteOnly))
    {
        statusBar()->showMessage("Save file failed",5000);
        return;
    }
    QString text = ui->dataDisplay->toPlainText();
    file.write(text.toStdString().c_str());
    file.close();
}


/* Clear ui->dataDisplay */
void SerialPortAssistant::clear(void)
{
    ui->dataDisplay->clear();
}

/* Clear ui->dataToSend */
void SerialPortAssistant::on_sendclear_clicked(void)
{
     ui->dataToSend->clear();
}

/*Get Forward Active Power*/
void SerialPortAssistant::on_Get_Active_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 34 33 18 16";
    QString dataname = "当前正向有功总电能:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_power_frequency_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 35 33 B3 35 9B 16";
    QString dataname = "电网频率:";
    // 串口未打开
    if ( !isPortOpen )
    {
        QMessageBox::warning(this, tr("Error"), QString::fromLocal8Bit("串口未打开，发送失败"), QMessageBox::Ok);
        return;
    }

    char16_t i,num = 0;
    QByteArray send_data;
    int len = data.length();
    QString send_str,showData = "\n发送信息->" + data;
    for(i=0;i<len;i++)
    {
        if(data.at(i)!= ' ')
        {
            send_str[num] = data.at(i);
            num ++;
        }
    }
    StringToHex(data,send_data);//将str字符串转换为16进制的形式
    send_data.resize(num/2);
    port->write(send_data);

    /* Add time to show. */
    if(ui->showTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        showData = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + showData;
    }
    /* Add newline to show. */
    if(ui->autoNewLine->isChecked())
    {
        showData += "\n";
    }
    /* Show data. */
    showData += "\n";
    insertDataDisplay(showData,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
    insertDataDisplay_(dataname,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
}


void SerialPortAssistant::on_N_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 34 33 B3 35 9A 16";
    QString dataname = "零线电流:";
    // 串口未打开
    if ( !isPortOpen )
    {
        QMessageBox::warning(this, tr("Error"), QString::fromLocal8Bit("串口未打开，发送失败"), QMessageBox::Ok);
        return;
    }

    char16_t i,num = 0;
    QByteArray send_data;
    int len = data.length();
    QString send_str,showData = "\n发送信息->" + data;
    for(i=0;i<len;i++)
    {
        if(data.at(i)!= ' ')
        {
            send_str[num] = data.at(i);
            num ++;
        }
    }
    StringToHex(data,send_data);//将str字符串转换为16进制的形式
    send_data.resize(num/2);
    port->write(send_data);

    /* Add time to show. */
    if(ui->showTime->isChecked())
    {
        QDateTime time = QDateTime::currentDateTime();
        showData = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + showData;
    }
    /* Add newline to show. */
    if(ui->autoNewLine->isChecked())
    {
        showData += "\n";
    }
    /* Show data. */
    showData += "\n";
    insertDataDisplay(showData,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
    insertDataDisplay_(dataname,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
}

void SerialPortAssistant::on_A_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 35 35 1C 16";
    QString dataname = "A相电流:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 35 35 1D 16";
    QString dataname = "B相电流:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 35 35 1E 16";
    QString dataname = "C相电流:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_active_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 36 35 1D 16";
    QString dataname = "A相有功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_active_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 36 35 1E 16";
    QString dataname = "B相有功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_active_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 36 35 1F 16";
    QString dataname = "C相有功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_Reactive_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 37 35 1E 16";
    QString dataname = "A相无功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_Reactive_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 37 35 1F 16";
    QString dataname = "B相无功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_Reactive_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 37 35 20 16";
    QString dataname = "C相无功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_Apparent_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 38 35 1F 16";
    QString dataname = "A相视在功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_Apparent_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 38 35 20 16";
    QString dataname = "B相视在功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_Apparent_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 38 35 21 16";
    QString dataname = "C相视在功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_factor_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 39 35 20 16";
    QString dataname = "A相功率因数:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_factor_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 39 35 21 16";
    QString dataname = "B相功率因数:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_factor_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 39 35 22 16";
    QString dataname = "C相功率因数:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_Total_active_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 36 35 1C 16";
    QString dataname = "总有功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_Total_Reactive_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 37 35 1D 16";
    QString dataname = "总无功功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_Total_Apparent_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 38 35 1E 16";
    QString dataname = "总视在功率:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_Total_power_factor__clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 39 35 1F 16";
    QString dataname = "总功率因数:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_Voltage_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 34 34 35 1B 16";
    QString dataname = "A相电压:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_Voltage_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 35 34 35 1C 16";
    QString dataname = "B相电压:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_Voltage_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 36 34 35 1D 16";
    QString dataname = "C相电压:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_A_total_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 48 33 2C 16";
    QString dataname = "A相正向有功电能:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_B_total_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 5C 33 40 16";
    QString dataname = "B相正向有功电能:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::on_C_total_power_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 70 33 54 16";
    QString dataname = "C相正向有功电能:";
    Handle_data(data,dataname);
}

void SerialPortAssistant::Handle_data(QString& text1,const QString& text2)
{
    // 串口未打开
    if ( !isPortOpen )
    {
        QMessageBox::warning(this, tr("Error"), QString::fromLocal8Bit("串口未打开，发送失败"), QMessageBox::Ok);
        return;
    }

    QRegExp regExp(" *([0-9A-Fa-f]{2} +)+[0-9A-Fa-f]{2} *");
    if(regExp.exactMatch(text1))
    {
        /* Convert every 2 characters to hexadecimal. */
        QStringList dataList = text1.split(QRegExp(" +"));
        QString newData,showData;
        showData += "\n发送信息->";
        foreach(const QString& i, dataList)
        {
            showData += i + " ";
            int n = i.toInt(nullptr,16);
            newData += text1.sprintf("%c",static_cast<char>(n));
        }
        /* Transmit data. */
        if(port->write(newData.toStdString().c_str()) == -1)
        {
            statusBar()->showMessage("Send data failed : "+ port->errorString());
            return;
        }

        /* Add time to show. */
        if(ui->showTime->isChecked())
        {
            QDateTime time = QDateTime::currentDateTime();
            showData = time.toString("yyyy-MM-dd hh:mm:ss") + " : " + showData;
        }
        /* Add newline to show. */
        if(ui->autoNewLine->isChecked())
        {
            showData += "\n";
        }
        /* Show data. */
        showData += "\n";
        insertDataDisplay(showData,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
        insertDataDisplay_(text2,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
    }
    else
    {
        statusBar()->showMessage("Data format is error",5000);
    }
}

//Millisecond
bool SerialPortAssistant::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    return true;
}

void SerialPortAssistant::on_testall_clicked()
{
    if(isPortOpen != true)
        return;
    if(ui->checkBox->isChecked())
    {
        on_Get_Active_Electric_clicked();
        sleep(500);
    }
    if(ui->checkBox_1->isChecked())
    {
        on_power_frequency_clicked();
        sleep(500);
    }
    if(ui->checkBox_2->isChecked())
    {
        on_N_Electric_clicked();
        sleep(500);
    }
    if(ui->checkBox_3->isChecked())
    {
        on_A_Voltage_clicked();
        sleep(500);
    }
    if(ui->checkBox_4->isChecked())
    {
        on_B_Voltage_clicked();
        sleep(500);
    }
    if(ui->checkBox_5->isChecked())
    {
        on_C_Voltage_clicked();
        sleep(500);
    }
    if(ui->checkBox_6->isChecked())
    {
        on_A_Electric_clicked();
        sleep(500);
    }
    if(ui->checkBox_7->isChecked())
    {
        on_B_Electric_clicked();
        sleep(500);
    }
    if(ui->checkBox_8->isChecked())
    {
        on_C_Electric_clicked();
        sleep(500);
    }
    if(ui->checkBox_9->isChecked())
    {
        on_A_active_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_10->isChecked())
    {
        on_B_active_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_11->isChecked())
    {
        on_C_active_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_12->isChecked())
    {
        on_A_Reactive_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_13->isChecked())
    {
        on_B_Reactive_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_14->isChecked())
    {
        on_C_Reactive_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_15->isChecked())
    {
        on_A_Apparent_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_16->isChecked())
    {
        on_B_Apparent_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_17->isChecked())
    {
        on_C_Apparent_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_18->isChecked())
    {
        on_A_factor_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_19->isChecked())
    {
        on_B_factor_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_20->isChecked())
    {
        on_C_factor_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_21->isChecked())
    {
        on_Total_active_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_22->isChecked())
    {
        on_Total_Reactive_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_23->isChecked())
    {
        on_Total_Apparent_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_24->isChecked())
    {
        on_A_total_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_25->isChecked())
    {
        on_B_total_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_26->isChecked())
    {
        on_C_total_power_clicked();
        sleep(500);
    }
    if(ui->checkBox_27->isChecked())
    {
        on_Total_power_factor__clicked();
        sleep(500);
    }
}



/*将十六进制转换为字符*/
char ConvertHexChar(char ch)
{
    if((ch >= '0') && (ch <= '9'))
        return ch-0x30;
    else if((ch >= 'A') && (ch <= 'F'))
        return ch-'A'+10;
    else if((ch >= 'a') && (ch <= 'f'))
        return ch-'a'+10;
    else return ch-ch;//不在0-f范围内的会发送成0
}



/*将字符串转换为hex格式*/
void StringToHex(QString str, QByteArray &senddata)
{
    int hexdata,lowhexdata;
    int hexdatalen = 0;
    int len = str.length();
    senddata.resize(len/2);
    char lstr,hstr;

    for(int i=0; i<len; )
    {
        //char lstr,
        hstr=str[i].toLatin1();
        if(hstr == ' ')
        {
            i++;
            continue;
        }
        i++;
        if(i >= len)
            break;
        lstr = str[i].toLatin1();
        hexdata = ConvertHexChar(hstr);
        lowhexdata = ConvertHexChar(lstr);
        if((hexdata == 16) || (lowhexdata == 16))
            break;
        else
            hexdata = hexdata*16+lowhexdata;
        i++;
        senddata[hexdatalen] = (char)hexdata;
        hexdatalen++;
    }
    senddata.resize(hexdatalen);
}


void SerialPortAssistant::on_checkBox_28_stateChanged()
{
    if(ui->checkBox_28->isChecked())
    {
        ui->checkBox->setChecked(true);
        ui->checkBox_1->setChecked(true);
        ui->checkBox_2->setChecked(true);
        ui->checkBox_3->setChecked(true);
        ui->checkBox_4->setChecked(true);
        ui->checkBox_5->setChecked(true);
        ui->checkBox_6->setChecked(true);
        ui->checkBox_7->setChecked(true);
        ui->checkBox_8->setChecked(true);
        ui->checkBox_9->setChecked(true);
        ui->checkBox_10->setChecked(true);
        ui->checkBox_11->setChecked(true);
        ui->checkBox_12->setChecked(true);
        ui->checkBox_13->setChecked(true);
        ui->checkBox_14->setChecked(true);
        ui->checkBox_15->setChecked(true);
        ui->checkBox_16->setChecked(true);
        ui->checkBox_17->setChecked(true);
        ui->checkBox_18->setChecked(true);
        ui->checkBox_19->setChecked(true);
        ui->checkBox_20->setChecked(true);
        ui->checkBox_21->setChecked(true);
        ui->checkBox_22->setChecked(true);
        ui->checkBox_23->setChecked(true);
        ui->checkBox_24->setChecked(true);
        ui->checkBox_25->setChecked(true);
        ui->checkBox_26->setChecked(true);
        ui->checkBox_27->setChecked(true);
    }
    else
    {
        ui->checkBox->setChecked(false);
        ui->checkBox_1->setChecked(false);
        ui->checkBox_2->setChecked(false);
        ui->checkBox_3->setChecked(false);
        ui->checkBox_4->setChecked(false);
        ui->checkBox_5->setChecked(false);
        ui->checkBox_6->setChecked(false);
        ui->checkBox_7->setChecked(false);
        ui->checkBox_8->setChecked(false);
        ui->checkBox_9->setChecked(false);
        ui->checkBox_10->setChecked(false);
        ui->checkBox_11->setChecked(false);
        ui->checkBox_12->setChecked(false);
        ui->checkBox_13->setChecked(false);
        ui->checkBox_14->setChecked(false);
        ui->checkBox_15->setChecked(false);
        ui->checkBox_16->setChecked(false);
        ui->checkBox_17->setChecked(false);
        ui->checkBox_18->setChecked(false);
        ui->checkBox_19->setChecked(false);
        ui->checkBox_20->setChecked(false);
        ui->checkBox_21->setChecked(false);
        ui->checkBox_22->setChecked(false);
        ui->checkBox_23->setChecked(false);
        ui->checkBox_24->setChecked(false);
        ui->checkBox_25->setChecked(false);
        ui->checkBox_26->setChecked(false);
        ui->checkBox_27->setChecked(false);
    }
}
