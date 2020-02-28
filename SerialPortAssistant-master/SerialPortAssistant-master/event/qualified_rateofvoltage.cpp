#include "qualified_rateofvoltage.h"
#include "ui_qualified_rateofvoltage.h"
#include "qdebug.h"

qualified_rateofvoltage::qualified_rateofvoltage(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::qualified_rateofvoltage)
{
    ui->setupUi(this);
    ui->comboBox->clear();
    ui->comboBox_2->clear();

    QStringList strList,strList1;

    strList<<"(本月)A 相电压合格率统计数据："<<"(上1月)A 相电压合格率统计数据："<<"(上2月)A 相电压合格率统计数据："<<"(上3月)A 相电压合格率统计数据："<<"(上4月)A 相电压合格率统计数据："<<"(上5月)A 相电压合格率统计数据："<<"(上6月)A 相电压合格率统计数据："<<"(上7月)A 相电压合格率统计数据："<<"(上8月)A 相电压合格率统计数据："<<"(上9月)A 相电压合格率统计数据："<<"(上10月)A 相电压合格率统计数据："<<"(上11月)A 相电压合格率统计数据："<<"(上12月)A 相电压合格率统计数据："
             <<"(本月)B 相电压合格率统计数据："<<"(上1月)B 相电压合格率统计数据："<<"(上2月)B 相电压合格率统计数据："<<"(上3月)B 相电压合格率统计数据："<<"(上4月)B 相电压合格率统计数据："<<"(上5月)A 相电压合格率统计数据："<<"(上6月)B 相电压合格率统计数据："<<"(上7月)B 相电压合格率统计数据："<<"(上8月)B 相电压合格率统计数据："<<"(上9月)B 相电压合格率统计数据："<<"(上10月)B 相电压合格率统计数据："<<"(上11月)B 相电压合格率统计数据："<<"(上12月)B 相电压合格率统计数据："
               <<"(本月)C 相电压合格率统计数据："<<"(上1月)C 相电压合格率统计数据："<<"(上2月)C 相电压合格率统计数据："<<"(上3月)C 相电压合格率统计数据："<<"(上4月)C 相电压合格率统计数据："<<"(上5月)C 相电压合格率统计数据："<<"(上6月)C 相电压合格率统计数据："<<"(上7月)C 相电压合格率统计数据："<<"(上8月)C 相电压合格率统计数据："<<"(上9月)C 相电压合格率统计数据："<<"(上10月)C 相电压合格率统计数据："<<"(上11月)C 相电压合格率统计数据："<<"(上12月)C 相电压合格率统计数据：";

    strList1<<"（本月）电压合格率统计数据："<<"（上1月）电压合格率统计数据:"<<"（上2月）电压合格率统计数据:"<<"（上3月）电压合格率统计数据:"<<"（上4月）电压合格率统计数据:"<<"（上5月）电压合格率统计数据:"
              <<"（上6月）电压合格率统计数据:"<<"（上7月）电压合格率统计数据:"<<"（上8月）电压合格率统计数据:"<<"（上9月）电压合格率统计数据:"<<"（上10月）电压合格率统计数据:"<<"（上11月）电压合格率统计数据:"<<"（上12月）电压合格率统计数据:";

    ui->comboBox->addItems(strList);
    ui->comboBox_2->addItems(strList1);
}

qualified_rateofvoltage::~qualified_rateofvoltage()
{
    delete ui;
}

//查询电压合格率统计数据
void qualified_rateofvoltage::on_query_button_2_clicked()
{
    //初始的4个数据标识
    int va0 = 0x00,va1 = 0x00 ,va2 = 0x10,va3 = 0x03;
    //处理后的4个数据标识
    QString DI0,DI1,DI2,DI3;
    //获得下拉列表当前序号
    int event_num = ui->comboBox_2->currentIndex();

    //通过判断下拉列表的序号将4个数据标识转换为字符串
    DI3 = tr("%1").arg(va3);
    DI2 = tr("%1").arg(va2);

    if(event_num < 13)
        DI1 = tr("%1").arg(va1);
    else if(event_num < 26)
        DI1 = tr("%1").arg(va1+1);
    else if(event_num < 39)
        DI1 = tr("%1").arg(va1+2);

    DI0 = tr("%1").arg(va0+event_num%13);

    //增加0x33后得到处理后的数据标识
    DI3 = QString::number((DI3.toInt(nullptr,10) + 0x33),16);
    DI2 = QString::number((DI2.toInt(nullptr,10) + 0x33),16);
    DI1 = QString::number((DI1.toInt(nullptr,10) + 0x33),16);
    DI0 = QString::number((DI0.toInt(nullptr,10) + 0x33),16);

    qDebug()<<"event_num is :"<<event_num<<"DI3 is :"<<DI3<<"DI2 is :"<<DI2<<"DI1 is :"<<DI1<<"DI0 is :"<<DI0;

    //根据数据标识得到校验码,并组装查询命令
    QString Query_command = get_Check_code(DI3,DI2,DI1,DI0);

    //将组装好的信号发出,格式为当前项文字+处理过后的查询码
    emit sendeventData(ui->comboBox_2->currentText(),Query_command);
    this->hide();
}

//查询三相电压合格率统计数据
void qualified_rateofvoltage::on_query_button_clicked()
{
    //初始的4个数据标识
    int va0 = 0x00,va1 = 0x01 ,va2 = 0x10,va3 = 0x03;
    //处理后的4个数据标识
    QString DI0,DI1,DI2,DI3;
    //获得下拉列表当前序号
    int event_num = ui->comboBox->currentIndex();

    //通过判断下拉列表的序号将4个数据标识转换为字符串
    DI3 = tr("%1").arg(va3);
    DI2 = tr("%1").arg(va2);

    if(event_num < 13)
        DI1 = tr("%1").arg(va1);
    else if(event_num < 26)
        DI1 = tr("%1").arg(va1+1);
    else if(event_num < 39)
        DI1 = tr("%1").arg(va1+2);

    DI0 = tr("%1").arg(va0+event_num%13);

    //增加0x33后得到处理后的数据标识
    DI3 = QString::number((DI3.toInt(nullptr,10) + 0x33),16);
    DI2 = QString::number((DI2.toInt(nullptr,10) + 0x33),16);
    DI1 = QString::number((DI1.toInt(nullptr,10) + 0x33),16);
    DI0 = QString::number((DI0.toInt(nullptr,10) + 0x33),16);

    qDebug()<<"event_num is :"<<event_num<<"DI3 is :"<<DI3<<"DI2 is :"<<DI2<<"DI1 is :"<<DI1<<"DI0 is :"<<DI0;

    //根据数据标识得到校验码,并组装查询命令
    QString Query_command = get_Check_code(DI3,DI2,DI1,DI0);

    //将组装好的信号发出,格式为当前项文字+处理过后的查询码
    emit sendeventData(ui->comboBox->currentText(),Query_command);
    this->hide();
}

//查询码组装函数
QString qualified_rateofvoltage::get_Check_code(QString DI3,QString DI2,QString DI1,QString DI0)
{
    //将发送过来的数据标识转换为16进制整型
    int a = DI3.toInt(nullptr,16);
    int b = DI2.toInt(nullptr,16);
    int c = DI1.toInt(nullptr,16);
    int d = DI0.toInt(nullptr,16);
    //校验码的计算方式为:从第一个帧起始符开始到校验码之前的所有各字节的模 256 的和，
    int checknum = (0x68 + 0x11 + 0x11 + 0x11 + 0x11 + 0x11 + 0x11 + 0x68 +0x11 + 0x04 + a + b + c + d) % 256 ;
    //再将得到的校验码转换为16进制显示的字符串
    QString check = tr("%1").arg(checknum);
    check = QString::number((check.toInt(nullptr,10)),16);
    //组装查询码
    QString Query_command = "68 11 11 11 11 11 11 68 11 04 "+ DI0 +" " + DI1+" " + DI2+" " + DI3+" " + check +" 16";
    //qDebug()<<"Query_command is :"<<Query_command;
    return Query_command;
}
