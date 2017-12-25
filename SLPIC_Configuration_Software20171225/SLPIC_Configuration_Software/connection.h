#ifndef CONNECTION_H
#define CONNECTION_H

#include <QDialog>
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QList>
#include <QSerialPort>
#include <QSerialPortInfo>

#include<QMessageBox>
#include "WinSerialPort/wserialport.h"

namespace Ui {
class Connection;
}

class Connection : public QDialog
{
    Q_OBJECT

public:
    explicit Connection(QWidget *parent = 0);

    ~Connection();

private:
    Ui::Connection *ui;
    WSerialport *m_pSerialport;


signals:
    /**
* @brief 摘要
* @param serialPort:transmit this serialport which is opened success to other object (reciever)
* @return void
* @author xiaoyao
* @date 2017/11/22
*/
    void serialPortOpened(WSerialport *serialPort);


private:

    //load serialNumberCBX's items
    void initSerialNumbers();

    //load baudRateCBX's items
    void initBaudrateCBX();

    //load dataBitsCBX's items
    void initDataBitsCBX();

    //load paritCBX's items
    void initParityCBX();

    //load StopBitsCBX's imtes
    void initStopBitsCBX();
    // init ui
    void initUi();


public slots:
    /**
* @brief 摘要
* @param closeFlag:accept flag of the serialport which is closed by other object(sender)
* @return
* @author xiaoyao
* @date 2017/11/22
*/
    void on_SerialPortCLosed(bool closeFlag);






private slots:
    void on_ConfirmButton_clicked();
    void on_CancleButton_clicked();
    void on_RefreshButton_2_clicked();
};

#endif // CONNECTION_H
