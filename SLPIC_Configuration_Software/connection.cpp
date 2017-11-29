#include "connection.h"
#include "ui_connection.h"

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
    QList<QSerialPortInfo> serialsInfor=QSerialPortInfo::availablePorts();
    for( QList<QSerialPortInfo>::iterator i=serialsInfor.begin();i!=serialsInfor.end();i++ )
    {
        ui->SerialNumCBX->addItem(i->portName());

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
    m_pSerialport=new QSerialPort(this);

    //com
    m_pSerialport->setPortName(ui->SerialNumCBX->currentText());
    //databits
    m_pSerialport->setDataBits((QSerialPort::DataBits)(ui->DataBitsCBX->currentText().toUInt()));

    //parity
    QSerialPort::Parity parity;
    switch (ui->ParityCBX->currentIndex()) {
    case 0:
        parity=QSerialPort::NoParity;
        break;
    case 1:
        parity=QSerialPort::OddParity;
        break;
    case 2:
        parity=QSerialPort::EvenParity;
        break;
    default:
        break;
    }
    m_pSerialport->setParity(parity);

    //stopbits
    QSerialPort::StopBits stopBits;
    switch (ui->StopBitCBX->currentIndex()) {
    case 0:
        stopBits=QSerialPort::OneStop;
        break;
    case 1:
        stopBits=QSerialPort::TwoStop;
        break;
    default:
        break;
    }
    m_pSerialport->setStopBits(stopBits);



    if(m_pSerialport->open(QIODevice::ReadWrite))
    {
        emit this->serialPortOpened(this->m_pSerialport);
        QMessageBox::information(this,tr("INFO"),tr("串口打开成功！"));
        ui->ConfirmButton->setEnabled(false);

        this->close();

    }
    else {
        //if open failed throw error with messagebox!
        QMessageBox::warning(this,tr("WARNING"),m_pSerialport->errorString());
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
