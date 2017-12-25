#include "serialport_editer.h"
#include "ui_serialport_editer.h"
#include <QtSerialPort/QSerialPort>
SerialPort_Editer::SerialPort_Editer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SerialPort_Editer),
    m_BaudeRateValue(9600),m_DataBitsValue(8),m_ParityValue(78),m_StopBitValue(1)

{
    ui->setupUi(this);
    InitUi();
    InitBaseTab();
    InitAlarmTab();
}

SerialPort_Editer::~SerialPort_Editer()
{
    delete ui;

}

void SerialPort_Editer::InitUi()
{
    ui->tabWidget->setTabText(0,tr("基本参数"));
    ui->tabWidget->setTabText(1,tr("报警参数"));
    //ui->tabWidget->setTabText(2,tr("报警关联"));

}

void SerialPort_Editer::InitBaseTab()
{
    QIntValidator *iValidatorSubPrjNameID=new QIntValidator(this);
    ui->SubPrjNameID->setValidator(iValidatorSubPrjNameID);

    QIntValidator *iValidatorSubPrjNum=new QIntValidator(this);
    ui->SubPrjNum->setValidator(iValidatorSubPrjNum);

    QStringList items;
    items<<"COM1"
        <<"COM2"
       <<"COM3"
      <<"COM4";
    ui->ChannelCBX->addItems(items);

    items.clear();
    items<<"9600"<<"19200"<<"38400"<<"57600"<<"115200";
    ui->BaudRateCBX->addItems(items);

    items.clear();
    items<<"7 Bits"<<"8 Bits";
    ui->DataBitsCBX->addItems(items);
    ui->DataBitsCBX->setCurrentIndex(1);

    items.clear();
    items<<"None"<<"Odd"<<"Even";
    ui->ParityCBX->addItems(items);

    items.clear();
    items<<"1 StopBit"<<"2 StopBits";
    ui->StopBitCBX->addItems(items);


    ui->Linklable->setText(tr("<a href=\"#\">获取平台参数"));


}

void SerialPort_Editer::InitAlarmTab()
{

}

byte SerialPort_Editer::StopBitValue()
{
    int currentStopBitCBX_Index=ui->StopBitCBX->currentIndex();

    switch(currentStopBitCBX_Index){
    case 0:
        m_StopBitValue= QSerialPort::OneStop;
        break;
    case 1:
        m_StopBitValue=QSerialPort::TwoStop;
        break;

    default:
        break;
    }

    return m_StopBitValue;
}

void SerialPort_Editer::setStopBitValue(const byte &StopBitValue)
{
    m_StopBitValue = StopBitValue;
    switch (m_StopBitValue) {
    case QSerialPort::OneStop:
        ui->StopBitCBX->setCurrentIndex(0);
        break;
    case QSerialPort::TwoStop:
        ui->StopBitCBX->setCurrentIndex(1);
        break;
    default:
        break;
    }
}

byte SerialPort_Editer::ParityValue()
{
    int currentParityCBX_Index=ui->ParityCBX->currentIndex();

    switch(currentParityCBX_Index){
    case 0:
        m_ParityValue= None;
        break;
    case 1:
        m_ParityValue=Odd;
        break;
    case 2:
        m_ParityValue=Even;
        break;
    default:

        break;
    }

    return m_ParityValue;
}

void SerialPort_Editer::setParityValue(const byte &ParityValue)
{
    m_ParityValue = ParityValue;
    switch (m_ParityValue) {
    case None:
        ui->ParityCBX->setCurrentIndex(0);
        break;
    case Odd:
        ui->ParityCBX->setCurrentIndex(1);
        break;
    case Even:
        ui->ParityCBX->setCurrentIndex(2);
        break;
    default:
        break;
    }
}

byte SerialPort_Editer::DataBitsValue()
{
    int currentDataBitsCBX_Index=ui->DataBitsCBX->currentIndex();

    switch(currentDataBitsCBX_Index){
    case 0:
        m_DataBitsValue=QSerialPort::Data7;
        break;
    case 1:
        m_DataBitsValue=QSerialPort::Data8;
        break;

    default:
        break;
    }

    return m_DataBitsValue;
}

void SerialPort_Editer::setDataBitsValue(const byte &DataBitsValue)
{
    m_DataBitsValue = DataBitsValue;
    switch (m_DataBitsValue) {
    case QSerialPort::Data7:
        ui->BaudRateCBX->setCurrentIndex(0);
        break;
    case QSerialPort::Data8:
        ui->BaudRateCBX->setCurrentIndex(1);
        break;
    default:
        break;
    }


}

void SerialPort_Editer::On_SerialPort_Table_DoubleClick_trigger(QStringList items, EditAttribute attribute, QString databasePath)
{
    m_DataBase.setFilePath(databasePath);
    m_Attribute=attribute;
    if(attribute==InsertEdit)
    {
        this->setWindowTitle(tr("串口设置：添加"));
        ui->ChannelCBX->setEnabled(true);



    }
    else
    {
        this->setWindowTitle(tr("串口设置：修改"));
        ui->ChannelCBX->setEnabled(false);
        ui->SubPrjName->setText(items.at(0));
        int currentIndeOfChannelCBX=(items.at(1).toInt())-1;
        ui->ChannelCBX->setCurrentIndex(currentIndeOfChannelCBX);
        ui->SubPrjNameID->setText(items.at(2));
        ui->SubPrjNum->setText(items.at(3));
        bool checked=(items.at(4).toInt()&0x1)==1?true:false;
        ui->EnableCBX->setChecked(checked);

        word currentValueOfBaudRateCBX=(items.at(5).toUInt());
        setBaudeRateValue(currentValueOfBaudRateCBX);

        byte currentValueOfDataBitsCBX =items.at(6).toUInt();
        setDataBitsValue(currentValueOfDataBitsCBX);

        byte currentValueOfParityCBX=items.at(7).toUInt();
        setParityValue(currentValueOfParityCBX);

        byte currentValueOfStopBitsCBX=items.at(8).toUInt();
        setStopBitValue(currentValueOfStopBitsCBX);


        ui->SlaveID->setText(items.at(9));
        ui->Manufacture->setText(items.at(10));

        ui->Protocol->setText(items.at(11));



    }


}


dword SerialPort_Editer::BaudeRateValue()
{
    int currentBaudRateCBX_Index=ui->BaudRateCBX->currentIndex();

    switch(currentBaudRateCBX_Index){
    case 0:
        m_BaudeRateValue=QSerialPort::Baud9600;
        break;
    case 1:
        m_BaudeRateValue=QSerialPort::Baud19200;
        break;
    case 2:
        m_BaudeRateValue=QSerialPort::Baud38400;
        break;
    case 3:
        m_BaudeRateValue=QSerialPort::Baud57600;
        break;
    case 4:
        m_BaudeRateValue=QSerialPort::Baud115200;
        break;
    }
    return m_BaudeRateValue;
}

void SerialPort_Editer::setBaudeRateValue(const dword &BaudeRateValue)
{
    // 0        1        2        4         5
    //<<"9600"<<"19200"<<"38400"<<"57600"<<"115200";
    m_BaudeRateValue = BaudeRateValue;

    switch (m_BaudeRateValue) {
    case QSerialPort::Baud9600:
        ui->BaudRateCBX->setCurrentIndex(0);
        break;
    case QSerialPort::Baud19200:
        ui->BaudRateCBX->setCurrentIndex(1);
        break;
    case QSerialPort::Baud38400:
        ui->BaudRateCBX->setCurrentIndex(2);

        break;
    case QSerialPort::Baud57600:
        ui->BaudRateCBX->setCurrentIndex(3);

        break;
    case QSerialPort::Baud115200:
        ui->BaudRateCBX->setCurrentIndex(4);
        break;

    default:
        break;
    }
}



void SerialPort_Editer::on_ConfirmBtn_clicked()
{
    if(m_Attribute==InsertEdit)
    {
        //添加记录

        SerialPort_Information_Bean bean;
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;


        bean.m_Field=ui->SubPrjName->text();

        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();

        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;
        bean.m_BaudRate=BaudeRateValue();
        bean.m_DataBits=DataBitsValue();
        bean.m_Parity=ParityValue();
        bean.m_StopBit=StopBitValue();
        bean.m_SlaveId=ui->SlaveID->text().toUInt();
        bean.m_Manufacturer=ui->Manufacture->text().toUInt();
        bean.m_Protocol=ui->Protocol->text().toUInt();

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetSerialPortTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的COM通道,或者平台ID!"));
            return;
        }
        if(m_DataBase.InsertInfoToSerialPortTable(bean))
        {
            //添加成功，提示成功

            QMessageBox::information(this,tr("INFO"),tr("添加成功"));
            emit Edit_Triggle(SerialPortPage);
            this->close();
        }
        else
        {
            //添加失败，提示失败信息
            QMessageBox::information(this,tr("ERROR"),m_DataBase.LastError());
            this->close();
        }
    }
    else
    {
        //更改记录
        SerialPort_Information_Bean bean;
        bean.m_Field=ui->SubPrjName->text();
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;
        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();


        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;

        bean.m_BaudRate=BaudeRateValue();
        bean.m_DataBits=DataBitsValue();
        bean.m_Parity=ParityValue();
        bean.m_StopBit=StopBitValue();
        bean.m_SlaveId=ui->SlaveID->text().toUInt();
        bean.m_Manufacturer=ui->Manufacture->text().toUInt();
        bean.m_Protocol=ui->Protocol->text().toUInt();

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetSerialPortTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的平台ID!"));
            return;
        }
        if(m_DataBase.UpdateInfoToSerialPortTable(bean))
        {
            //如果成功
            QMessageBox::information(this,tr("INFO"),tr("修改成功"));
            emit Edit_Triggle(SerialPortPage);
            this->close();
        }
        else
        {
            //如果失败提示报错信息
            QMessageBox::warning(this,tr("ERROR"),m_DataBase.LastError());
            this->close();
        }

    }


}

void SerialPort_Editer::on_CancelBtn_clicked()
{
    this->close();
}
