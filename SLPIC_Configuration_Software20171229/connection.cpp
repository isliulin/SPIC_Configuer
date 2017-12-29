#include "connection.h"
#include "ui_connection.h"
#include <windows.h>
Connection::Connection(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Connection),m_pSerialport(Q_NULLPTR)
{
    ui->setupUi(this);
    initUi();
}

void Connection::on_SerialPortCLosed(bool closeFlag)
{
    if(closeFlag)
    {
        ui->ConfirmButton->setEnabled(true);
    }

}

Connection::~Connection()
{
    delete ui;
}

void Connection::initSerialNumbers()
{
//    QList<QSerialPortInfo> serialsInfor=QSerialPortInfo::availablePorts();
//    for( QList<QSerialPortInfo>::iterator i=serialsInfor.begin();i!=serialsInfor.end();i++ )
//    {
//        ui->SerialNumCBX->addItem(i->portName());

//    }

   QStringList serialPortNames;
   serialPortNames.append(tr("COM1"));
   serialPortNames.append(tr("COM2"));
   serialPortNames.append(tr("COM3"));
   serialPortNames.append(tr("COM4"));
   serialPortNames.append(tr("COM5"));
   serialPortNames.append(tr("COM6"));
   serialPortNames.append(tr("COM7"));
   serialPortNames.append(tr("COM8"));
   serialPortNames.append(tr("COM9"));
   serialPortNames.append(tr("COM10"));
   serialPortNames.append(tr("COM11"));
   serialPortNames.append(tr("COM12"));
   for(int i=0;i<serialPortNames.length();i++)
   {
       ui->SerialNumCBX->addItem(serialPortNames.at(i));
   }



}

void Connection::initBaudrateCBX()
{

    QList<QString> baudRateItems;
    baudRateItems<<tr("9600")<<tr("19200")<<tr("38400")<<tr("57600")<<tr("115200");
    ui->BaudRateCBX->addItems(baudRateItems);

}

void Connection::initDataBitsCBX()
{

    QList<QString> dataBitsItems;
    dataBitsItems<<tr("8")<<tr("7");
    ui->DataBitsCBX->addItems(dataBitsItems);

}

void Connection::initParityCBX()
{
    QList<QString> parityItems;
    parityItems<<tr("None")<<tr("Odd")<<tr("Even");
    ui->ParityCBX->addItems(parityItems);

}

void Connection::initStopBitsCBX()
{
    QList<QString> stopBitsItems;
    stopBitsItems<<tr("1")<<tr("2");
    ui->StopBitCBX->addItems(stopBitsItems);
}

void Connection::initUi()
{
    initSerialNumbers();
    initBaudrateCBX();
    initDataBitsCBX();
    initParityCBX();
    initStopBitsCBX();
}

void Connection::on_ConfirmButton_clicked()
{
    m_pSerialport=new WSerialport();


    //com
    //QString to wchar_t *:

    LPCTSTR portName=reinterpret_cast<const wchar_t *>(ui->SerialNumCBX->currentText().utf16());
    m_pSerialport->m_Port=portName;



    m_pSerialport-> m_BaudRate=ui->BaudRateCBX->currentText().toUInt();

    //m_pSerialport->m_BaudRate=CBR_9600;
    //databits
    //m_pSerialport->setDataBits((QSerialPort::DataBits)(ui->DataBitsCBX->currentText().toUInt()));

    m_pSerialport->m_DataBits=(BYTE)(ui->DataBitsCBX->currentText().toUInt());
    //parity
    BYTE parity;
    switch (ui->ParityCBX->currentIndex()) {
    case 0:
        parity=PARITY_NONE;
        break;
    case 1:
        parity=PARITY_ODD;
        break;
    case 2:
        parity=PARITY_EVEN;
        break;
    default:
        break;
    }
    //parity


    m_pSerialport->m_Parity=parity;

    //stopbits
    BYTE stopBits;
    switch (ui->StopBitCBX->currentIndex()) {
    case 0:
        stopBits=ONESTOPBIT;
        break;
    case 1:
        stopBits=TWOSTOPBITS;
        break;
    default:
        break;
    }
    m_pSerialport->m_StopBits=stopBits;


    if(m_pSerialport->OpenCOM())
    {
        emit this->serialPortOpened(this->m_pSerialport);
        QMessageBox::information(this,tr("INFO"),tr("串口打开成功！"));
        ui->ConfirmButton->setEnabled(false);
        this->close();

    }
    else {
        //if open failed throw error with messagebox!

        DWORD errorCode=m_pSerialport->GetLastErrors();
        QMessageBox::warning(this,tr("WARNING"),tr("串口打开失败,ERRORCODE:")+QString::number(errorCode, 16).toUpper());
        this->close();
    }


}

void Connection::on_CancleButton_clicked()
{
    this->close();

}

void Connection::on_RefreshButton_2_clicked()
{
    initSerialNumbers();
}
