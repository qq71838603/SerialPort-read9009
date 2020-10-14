#include "serialportassistant.h"
#include "ui_serialportassistant.h"
#include <QDebug>

void StringToHex(QString str, QByteArray &senddata);


SerialPortAssistant::SerialPortAssistant(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::SerialPortAssistant)
{
    ui->setupUi(this);

    //总记录界面
    SerialPortAssistant::v = new Event_log;

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
    /*event log*/
    connect(v,SIGNAL(sendData(QString,QString)),this,SLOT(receivedata(QString,QString)));

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


/*data reverse*/
QString reversalStr(QString &str)
{
    QString ret;
    for(QChar sz:str)
    {
        ret.push_front(sz);
    }
    return ret;
}

/*将字符串转换,十六进制转换为十进制,如果为0则补一位0*/
QString SerialPortAssistant::Qstringtransform(QString text)
{
    text = QString::number((text.toInt(nullptr,16) - 0x33),16);
    text = QString("%1").arg(text.toInt(), 2, 10, QLatin1Char('0'));
    return text;
}

//得到需要的字符串数据,一并处理小数点
QString SerialPortAssistant::getvalue(QStringList listdisplay,int num,int datalong,int spot)
{
    QString returnString;
    //算到总的数据长度后从后往前读取数据
    for(int i = num;i > num-datalong ; i--)
    {
        returnString = returnString + listdisplay[i];
    }
    //如果有小数点处理则在相应位置加上小数点
    if(spot > 0)
    {
        returnString = returnString.mid(0,spot) + "." + returnString.mid(spot,datalong*2);
    }

    return returnString;
}

/* Receive data from serial port. */
void SerialPortAssistant::receive(void)
{
    /* Receive data. */
    QByteArray data = port->readAll();
    //qDebug()<<"data is :"<<data;
    QString display,ndisplay;
    /* Convert data to hexadecimal. */
    if(ui->hexadecimaleReceive->isChecked())
    {
        QString temp;
        for(int i=0; i < data.size(); i++)
        {
            temp.sprintf("%02x ",(unsigned char)data.at(i));
            display += temp;
            ndisplay += temp;
        }
    }

    //修改bug,只用一个display在实现换行功能会出现多余字符导致错误
    //是否换行
    if(ui->autoNewLine->isChecked())
    {
        ndisplay += "\n";
        insertDataDisplay(ndisplay,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
    }
    else
        insertDataDisplay(display,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);

    //获取信息分段数目
    flag ++;
    enddisplay += display;

    QStringList listdisplay = enddisplay.split(" ");
    qDebug()<< "111111111111111111111111";
    qDebug()<< "listdisplayt:"<<listdisplay;
    qDebug()<< "listdisplay.count:"<<listdisplay.count();

    /*
    if(testflag == 0)
    {
        testflag =1;
        sleep(100);
        on_A_Voltage_clicked();
    }*/
    if(listdisplay[0] != "fe" )
    {
        enddisplay.clear();
        listdisplay.clear();
        flag = 0;
    }
    //用于读取接收到的电压,功率因数,电流,有功功率,无功功率,视在功率,正向有功总电能,三相正向有功电能,三相过载,数据分为多段,平均7-8次发送完全部数据,三相过载为8-9次
    if(flag == 5 || flag == 6 || flag == 7 || flag == 8 || flag ==9)
    {
        QStringList listdisplay = enddisplay.split(" ");
        //qDebug()<< "listdisplayt:"<<listdisplay;
        //qDebug()<< "listdisplay.count:"<<listdisplay.count();

        //如果为错误码,返回数据为19字节,则清空数据
        if(listdisplay.count() == 19 && listdisplay[12] == "d1")
        {
            QString showdata = ":空\n";

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            enddisplay.clear();
            showdata.clear();
            listdisplay.clear();
            flag = 0;
        }
        //电压,功率因数,电网频率返回数据为24个字节
        if(listdisplay.count() == 24)
        {
            QString tempdata,showdata;
            //电压
            if(listdisplay[16] == "34" && listdisplay[17] == "35")
            {
                listdisplay[19] = Qstringtransform(listdisplay[19]);
                listdisplay[18] = Qstringtransform(listdisplay[18]);

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
                listdisplay[19] = Qstringtransform(listdisplay[19]);
                listdisplay[18] = Qstringtransform(listdisplay[18]);

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
                if(listdisplay[14] == "35")
                {
                    listdisplay[19] = Qstringtransform(listdisplay[19]);
                    listdisplay[18] = Qstringtransform(listdisplay[18]);

                    tempdata = listdisplay[19] + listdisplay[18];
                    showdata = tempdata.mid(0,2) + "." + tempdata.mid(1,2)+ "\n";

                    insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                    enddisplay.clear();
                    showdata.clear();
                    listdisplay.clear();
                    flag = 0;
                }
            }
        }
        //电流,零线电流,有功功率,无功功率,视在功率,掉电总次数返回数据为25字节
        else if(listdisplay.count() == 25)
        {
            QString tempdata,showdata;
            //读取电流
            if(listdisplay[16] == "35" && listdisplay[17] == "35")
            {
                listdisplay[20] = Qstringtransform(listdisplay[20]);
                listdisplay[19] = Qstringtransform(listdisplay[19]);
                listdisplay[18] = Qstringtransform(listdisplay[18]);

                tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                showdata = tempdata.mid(0,3) + "." + tempdata.mid(3,3)+ "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            //读取零线电流
            else if(listdisplay[16] == "b3" || listdisplay[16] == "B3")
            {
                //为了区分读取版本号的指令
                if(listdisplay[17] == "35")
                {
                    listdisplay[20] = Qstringtransform(listdisplay[20]);
                    listdisplay[19] = Qstringtransform(listdisplay[19]);
                    listdisplay[18] = Qstringtransform(listdisplay[18]);

                    tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                    showdata = tempdata.mid(0,3) + "." + tempdata.mid(3,3)+ "\n";

                    insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                    enddisplay.clear();
                    showdata.clear();
                    listdisplay.clear();
                    flag = 0;
                }
            }
            //有功功率,无功功率,视在功率
            else if(listdisplay[16] == "36" || listdisplay[16] == "37" || listdisplay[16] == "38" )
            {
                if(listdisplay[17] == "35")
                {
                    listdisplay[20] = Qstringtransform(listdisplay[20]);
                    listdisplay[19] = Qstringtransform(listdisplay[19]);
                    listdisplay[18] = Qstringtransform(listdisplay[18]);

                    tempdata = listdisplay[20] + listdisplay[19] + listdisplay[18] ;
                    showdata = tempdata.mid(0,2) + "." + tempdata.mid(2,4)+ "\n";

                    insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                    enddisplay.clear();
                    showdata.clear();
                    listdisplay.clear();
                    flag = 0;
                }
            }
            //掉电总次数
            else if(listdisplay[16] == "44" && listdisplay[14] == "33")
            {
                listdisplay[20] = Qstringtransform(listdisplay[20]);
                listdisplay[19] = Qstringtransform(listdisplay[19]);
                listdisplay[18] = Qstringtransform(listdisplay[18]);

                showdata = listdisplay[20] + listdisplay[19] + listdisplay[18] + "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;

            }
        }
        //正向有功总电能,三相正向有功电能返回数据为26字节
        else if(listdisplay.count() == 26 && listdisplay[17] == "33" )
        {
            if( listdisplay[16] == "34" || listdisplay[16] == "48" || listdisplay[16] == "5c" || listdisplay[16] == "70")
            {
                listdisplay[21] = Qstringtransform(listdisplay[21]);
                listdisplay[20] = Qstringtransform(listdisplay[20]);
                listdisplay[19] = Qstringtransform(listdisplay[19]);
                listdisplay[18] = Qstringtransform(listdisplay[18]);

                QString showdata = listdisplay[21] + listdisplay[20] + listdisplay[19] + "." + listdisplay[18]+"\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
        }
        //三相过载,电压不平衡总次数.总累计时间, 电流不平衡总次数，总累计时间返回数据为28字节
        else if(listdisplay.count() == 28)
        {
            if(listdisplay[16] == "42" && listdisplay[14] == "33")
            {
                for(int i = 18;i<24;i++)
                {
                    listdisplay[i] = Qstringtransform(listdisplay[i]);
                }

                QString showdata =  getvalue(listdisplay,23,6,0) + "\n";

                insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                enddisplay.clear();
                showdata.clear();
                listdisplay.clear();
                flag = 0;
            }
            //3c 为电压不平衡 3d 为电流不平衡
            else if(listdisplay[16] == "3c" || listdisplay[16] == "3d" )
            {
                if(listdisplay[14] == "33")
                {
                    for(int i = 18;i<24;i++)
                    {
                        listdisplay[i] = Qstringtransform(listdisplay[i]);
                    }

                    QString showdata =  getvalue(listdisplay,23,6,6) + "\n";

                    insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
                    enddisplay.clear();
                    showdata.clear();
                    listdisplay.clear();
                    flag = 0;
                }
            }
        }
    }
    //用于读取温湿度,掉电发生时刻事件,分了10段或者是11段来读取温湿度,掉电发生时刻事件,分了11段或是12段来读取总累计时间总累计次数
    else if(flag == 10 || flag == 11 || flag ==12 || flag ==13)
    {
        QStringList listdisplay = enddisplay.split(" ");
        qDebug()<< "listdisplayt:"<<listdisplay;
        qDebug()<< "listdisplay.count:"<<listdisplay.count();
        int tep,hum; //温湿度
        QString A,B,C; //三相总累计时间总累计次数
        if(listdisplay.count() == 34 && listdisplay[16] == "3a")
        {
            listdisplay[18] = QString::number((listdisplay[18].toInt(nullptr,16) - 0x33),16);
            listdisplay[19] = QString::number((listdisplay[19].toInt(nullptr,16) - 0x33),16);
            listdisplay[20] = QString::number((listdisplay[20].toInt(nullptr,16) - 0x33),16);

            //温湿度数据从listdisplay[19]中对半拆分
            hum = listdisplay[19].toInt() / 10;
            tep = listdisplay[19].toInt() % 10;

            //qDebug()<< "(listdisplay[18].toInt() * 10) + tep:"<<(listdisplay[18].toInt() * 10) + tep;
            //qDebug()<< "(listdisplay[20].toInt() + hum *100) -40:"<<(listdisplay[20].toInt() + hum *100) -40;

            QString showdata = "湿度:" + QString::number((listdisplay[18].toInt() * 10) + hum)+ "%" +"\n" + "温度:" + QString::number((listdisplay[20].toInt() + tep *100) -40) + "°C" + "\n";

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            enddisplay.clear();
            showdata.clear();
            listdisplay.clear();
            flag = 0;
        }
        //用于读取掉电发生时刻事件
        else if(listdisplay.count() == 34 && listdisplay[16] == "44")
        {
            //将返回的数据内容做处理 从18开始为需要拿到的数据
            for(int i = 18;i<30;i++)
            {
                listdisplay[i] = Qstringtransform(listdisplay[i]);
            }

            QString showdata = getvalue(listdisplay,29,12,12) + "\n";

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            enddisplay.clear();
            showdata.clear();
            listdisplay.clear();
            flag = 0;
        }

        //用于读取总累计时间总累计次数,listdisplay[16] != "43"避免与（本月）电压合格率统计数据冲突
        else if(listdisplay.count() == 40 && listdisplay[15] == "33"  && listdisplay[14] == "33" && listdisplay[16] != "43")
        {
            //电表返回数据为18-35,转换为十进制后逆向为需要的数据
            for(int i =18;i<36;i++)
            {
                listdisplay[i] = Qstringtransform(listdisplay[i]);
            }

            //根据数据标识DI2来判断读出的是哪种事件
            if(listdisplay[16] == "34")
            {
                A = "A相失压总次数:";
                B = "B相失压总次数:";
                C = "C相失压总次数:";
            }
            else if(listdisplay[16] == "35")
            {
                A = "A相欠压总次数:";
                B = "B相欠压总次数:";
                C = "C相欠压总次数:";
            }
            else if(listdisplay[16] == "36")
            {
                A = "A相过压总次数:";
                B = "B相过压总次数:";
                C = "C相过压总次数:";
            }
            else if(listdisplay[16] == "37")
            {
                A = "A相断相总次数:";
                B = "B相断相总次数:";
                C = "C相断相总次数:";
            }
            else if(listdisplay[16] == "3e")
            {
                A = "A相失流总次数:";
                B = "B相失流总次数:";
                C = "C相失流总次数:";
            }
            else if(listdisplay[16] == "35")
            {
                A = "A相欠压总次数:";
                B = "B相欠压总次数:";
                C = "C相欠压总次数:";
            }
            else if(listdisplay[16] == "3f")
            {
                A = "A相过流总次数:";
                B = "B相过流总次数:";
                C = "C相过流总次数:";
            }
            else if(listdisplay[16] == "40")
            {
                A = "A相断流总次数:";
                B = "B相断流总次数:";
                C = "C相断流总次数:";
            }


            QString showdata = "\n" + A + listdisplay[35] + listdisplay[34] + listdisplay[33] + "次,"
                    +"总累计时间:" + listdisplay[32] + listdisplay[31] + listdisplay[30] +"分\n" + B +
                    listdisplay[29] + listdisplay[28] + listdisplay[27] + "次," + "总累计时间:" + listdisplay[26]
                    + listdisplay[25] + listdisplay[24] + "分\n" + C + listdisplay[23] + listdisplay[22]
                    + listdisplay[21] + "次," + "总累计时间:" + listdisplay[20] + listdisplay[19] + listdisplay[18]+"分\n";

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            showdata.clear();
            listdisplay.clear();
            flag = 0;
            enddisplay.clear();
        }
    }
    //用于读取软件版本与电压合格率数据统计,分了14段或者是15段来读取数据合格率统计,分了16段或者是17段来读取软件版本
    else if(flag == 14 || flag == 15 || flag == 16 || flag == 17)
    {
        QStringList listdisplay = enddisplay.split(" ");
        QString showdata,reservedata;
        //qDebug()<< "listdisplayt:"<<listdisplay;
        //qDebug()<< "listdisplay.count:"<<listdisplay.count();

        //软件版本接受数据长度为54
        if(listdisplay.count() == 54 && listdisplay[16] == "b3" )
        {
            for(int i = 0; i< 32 ;i++)
            {
                listdisplay[i+18] = QString::number((listdisplay[i+18].toInt(nullptr,16) - 0x33),16);
                //如果为0则补为00
                if(listdisplay[i+18] == "0")
                {
                    listdisplay[i+18] = QString("%1").arg(listdisplay[i+18].toInt(), 2, 10, QLatin1Char('0'));
                }
                reservedata = reservedata + listdisplay[i+18];
            }
            //将得到的字符串反转
            showdata = reversalStr(reservedata);
            showdata = showdata +"\n";

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            showdata.clear();
            listdisplay.clear();
            enddisplay.clear();
            flag = 0;
        }
        //用于读取电压合格率统计数据
        if(listdisplay.count() == 49 && listdisplay[16] == "43" )
        {
            //将返回的数据内容做处理 从18开始为需要拿到的数据
            for(int i = 18;i<45;i++)
            {
                listdisplay[i] = Qstringtransform(listdisplay[i]);
            }

            //拼接需要得到的字符串
            showdata ="\nA相电压监测时间:" + getvalue(listdisplay,44,3,0) + "\nA相电压合格率:" + getvalue(listdisplay,44-3,3,4) + "\nA相电压超限率:" + getvalue(listdisplay,44-3-3,3,4)
                    + "\nA相电压超上限时间:" + getvalue(listdisplay,44-3-3-3,3,0) + "\nA相电压超下限时间:" + getvalue(listdisplay,44-3-3-3-3,3,0) + "\nA相最高电压:" + getvalue(listdisplay,44-3-3-3-3-3,2,3)
                    + "\nA相最高电压出现时间:" + getvalue(listdisplay,44-3-3-3-3-3-2,4,0) + "\nA相最低电压:" + getvalue(listdisplay,44-3-3-3-3-3-2-4,2,3) + "\nA相最低电压出现时间:"+ getvalue(listdisplay,44-3-3-3-3-3-2-4-2,4,0)
                    +"\n";

            //这几个事件返回的数据均为相同的处理方式,因此直接替换字符
            if(listdisplay[15] == "33")
                showdata.replace("A相","");
            if(listdisplay[15] == "35")
                showdata.replace("A相","B相");
            if(listdisplay[15] == "36")
                showdata.replace("A相","C相");

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            showdata.clear();
            listdisplay.clear();
            flag = 0;
            enddisplay.clear();
        }
    }
    //主要用于获取失压,欠压,过压,断相,失流,过流,断流,过载事件记录的数据
    else if(flag > 17)
    {
        QStringList listdisplay = enddisplay.split(" ");
        QString showdata;
        qDebug()<< "listdisplayt:"<<listdisplay;
        qDebug()<< "listdisplay.count:"<<listdisplay.count();
        //过载事件返回的数据长度为66个字节
        if(listdisplay.count() == 66 && listdisplay[16] == "42")
        {
            for(int i = 18;i<62;i++)
            {
                listdisplay[i] = Qstringtransform(listdisplay[i]);
            }
            showdata = "\n发生时刻:" + getvalue(listdisplay,61,6,0) + "\n结束时刻:" + getvalue(listdisplay,61-6,6,0)
                    + "\nA相过载期间正向有功总电能增量" + getvalue(listdisplay,61-6*2,4,6) + "\nA相过载期间反向有功总电能增量:" + getvalue(listdisplay,61-6*2-4,4,6)
                    + "\nA相过载期间A相正向有功电能增量:" + getvalue(listdisplay,61-6*2-4*2,4,6) + "\nA相过载期间A相反向有功电能增量:" + getvalue(listdisplay,61-6*2-4*3,4,6)
                    + "\nA相过载期间B相正向有功电能增量:" + getvalue(listdisplay,61-6*2-4*4,4,6) + "\nA相过载期间B相反向有功电能增量:" + getvalue(listdisplay,61-6*2-4*5,4,6)
                    + "\nA相过载期间C相正向有功电能增量:" + getvalue(listdisplay,61-6*2-4*6,4,6) + "\nA相过载期间C相反向有功电能增量:" + getvalue(listdisplay,61-6*2-4*7,4,6)
                    + "\n";

            if(listdisplay[15] == "35")
                showdata.replace("A相过载","B相过载");
            if(listdisplay[15] == "36")
                showdata.replace("A相过载","C相过载");

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            showdata.clear();
            listdisplay.clear();
            flag = 0;
            enddisplay.clear();
        }
        //失压,欠压,过压,断相,失流,过流,断流事件返回的数据长度为105个字节
        if(listdisplay.count() == 105)
        {
            //将返回的数据内容做处理 从18开始为需要拿到的数据
            for(int i = 18;i<101;i++)
            {
                listdisplay[i] = Qstringtransform(listdisplay[i]);
            }
            //拼接需要得到的字符串
            showdata = "\n发生时刻:" + getvalue(listdisplay,100,6,0) + "\n结束时刻:" + getvalue(listdisplay,100-6,6,0)
                    + "\n失压期间正向有功总电能增量:" + getvalue(listdisplay,100-6*2,4,6) + "\n失压期间反向有功总电能增量:" + getvalue(listdisplay,100-6*2-4,4,6)
                    + "\n失压期间A相正向有功电能增量:" +  getvalue(listdisplay,100-6*2-4*2,4,6) + "\n失压期间A相反向有功电能增量:" + getvalue(listdisplay,100-6*2-4*3,4,6)
                    + "\n失压时刻A相电压:" + getvalue(listdisplay,100-6*2-4*4,2,3) + "\n失压时刻A相电流:" +  getvalue(listdisplay,100-6*2-4*4-2,3,3)
                    + "\n失压时刻A相有功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3,3,2) + "\n失压时刻A相无功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3*2,3,2)
                    + "\n失压时刻A相功率因数:" + getvalue(listdisplay,100-6*2-4*4-2-3*3,2,1) + "\n失压期间B相正向有功电能增量:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2,4,6)
                    + "\n失压期间B相反向有功电能增量:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4,4,6) + "\n失压时刻B相电压:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2,2,3)
                    + "\n失压时刻B相电流:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2,3,3) + "\n失压时刻B相有功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3,3,2)
                    + "\n失压时刻B相无功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*2,3,2) + "\n失压时刻B相功率因数:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3,2,1)
                    + "\n失压期间C相正向有功电能增量:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2,4,6) + "\n失压期间C相反向有功电能增量:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4,4,6)
                    + "\n失压时刻C相电压:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4*2,2,3) + "\n失压时刻C相电流:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4*2-2,3,3)
                    + "\n失压时刻C相有功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4*2-2-3,3,2) + "\n失压时刻C相无功功率:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4*2-2-3*2,3,2)
                    + "\n失压时刻C相功率因数:" + getvalue(listdisplay,100-6*2-4*4-2-3*3-2-4*2-2-3*3-2-4*2-2-3*3,2,1) + "\n";

            //这几个事件返回的数据均为相同的处理方式,因此直接替换字符
            if(listdisplay[16] == "35")
                showdata.replace("失压","欠压");
            if(listdisplay[16] == "36")
                showdata.replace("失压","过压");
            if(listdisplay[16] == "37")
                showdata.replace("失压","断相");
            if(listdisplay[16] == "3e")
                showdata.replace("失压","失流");
            if(listdisplay[16] == "3f")
                showdata.replace("失压","过流");
            if(listdisplay[16] == "40")
                showdata.replace("失压","断流");

            insertDataDisplay_(showdata,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
            showdata.clear();
            listdisplay.clear();
            flag = 0;
            enddisplay.clear();
        }
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

        qDebug()<<"data is :"<<data;

        foreach(const QString& i, dataList)
        {
            showData += i + " ";
            int n = i.toInt(nullptr,16);
            newData += data.sprintf("%c",static_cast<char>(n));
        }

        qDebug()<<"newData is :"<<newData;

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


/* 电网频率使用通用处理无法接受数据,先这样处理 */
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

/* 零线电流使用通用处理无法接受数据,先这样处理 */
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

/*查询软件版本*/
void SerialPortAssistant::on_query_version_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 34 33 B3 37 9C 16";
    QString dataname = "软件版本:";
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

/* 读取温湿度特殊处理 */
void SerialPortAssistant::on_Temperature_humidity_clicked()
{
    QString text1 = "68 11 11 11 11 11 11 68 11 04 33 33 3A 35 20 16";
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
    }
    else
    {
        statusBar()->showMessage("Data format is error",5000);
    }
}

void SerialPortAssistant::on_Get_Active_Electric_clicked()
{
    QString data = "68 11 11 11 11 11 11 68 11 04 33 33 34 33 18 16";
    QString dataname = "当前正向有功总电能:";
    Handle_data(data,dataname);
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

/* 处理数据函数,用于指定按钮发送指定数据内容 */
void SerialPortAssistant::Handle_data(QString& text1,const QString& text2)
{
    // 串口未打开
    if ( !isPortOpen )
    {
        QMessageBox::warning(this, tr("Error"), QString::fromLocal8Bit("串口未打开，发送失败"), QMessageBox::Ok);
        return;
    }
    qDebug()<<"text1 is "<<text1;

    QRegExp regExp(" *([0-9A-Fa-f]{2} +)+[0-9A-Fa-f]{2} *");
    if(regExp.exactMatch(text1))
    {
        //每2个字符转换为十六进制
        QStringList dataList = text1.split(QRegExp(" +"));
        QString newData,showData;
        //修改时间显示bug,删除从recive中实现,改为发送信息就提示时间
        if(ui->showTime->isChecked())
            showData += "发送信息->";
        else
            showData += "\n发送信息->";
        foreach(const QString& i, dataList)
        {
            showData += i + " ";
            int n = i.toInt(nullptr,16);
            newData += text1.sprintf("%c",static_cast<char>(n));
            //qDebug()<<"newData is "<<newData;
        }

        qDebug()<<"dataList is "<<dataList;
        qDebug()<<"newData.toStdString().c_str() is "<<newData.toStdString().c_str();

        //发送数据
        if(port->write(newData.toStdString().c_str()) == -1)
        {
            statusBar()->showMessage("Send data failed : "+ port->errorString());
            return;
        }
        //添加打印时间
        if(ui->showTime->isChecked())
        {
            QDateTime time = QDateTime::currentDateTime();
            showData ="\n"+ time.toString("yyyy-MM-dd hh:mm:ss") + " : " + showData;
        }
        //添加新的一行
        if(ui->autoNewLine->isChecked())
        {
            showData += "\n";
        }
        //显示信息在两个文本框内
        showData += "\n";
        insertDataDisplay(showData,ui->doubleColor->isChecked() ? Qt::green : Qt::black);
        insertDataDisplay_(text2,ui->doubleColor->isChecked() ? Qt::blue : Qt::black);
    }
    else
    {
        statusBar()->showMessage("Data format is error",5000);
    }
}

/* Millisecond 延时函数,单位为毫秒 */
bool SerialPortAssistant::sleep(int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);

    while (QTime::currentTime() < dieTime)
    {
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);
    }
    return true;
}

/* 勾选测试 */
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
    if(ui->checkBox_29->isChecked())
    {
        on_Temperature_humidity_clicked();
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

/*  全选/取消全选 */
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
        ui->checkBox_29->setChecked(true);
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
        ui->checkBox_29->setChecked(false);
    }
}

void SerialPortAssistant::receivedata(QString text1, QString text2)
{
    qDebug()<< "text1 is :"<<text1<< "text2 is :" <<text2;
    Handle_data(text2,text1);
}

/*事件记录页面显示按钮*/
void SerialPortAssistant::on_pushButton_clicked()
{
    v->show();
}
