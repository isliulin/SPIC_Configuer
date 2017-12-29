#include "other_editer.h"
#include "ui_other_editer.h"

Other_Editer::Other_Editer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Other_Editer)
{
    ui->setupUi(this);
    InitUi();
    InitBaseTab();
    InitSystemTab();
}

Other_Editer::~Other_Editer()
{
    delete ui;

}



void Other_Editer::InitUi()
{
    ui->tabWidget->setTabText(0,tr("基本参数"));
    ui->tabWidget->setTabText(1,tr("系统参数"));
    InitDeviceIdLineEditers();
    //InitRtcTimerLineEditers();


    ui->Linklable->setText(tr("<a href=\"#\">获取平台参数"));

    connect(ui->Linklable,SIGNAL(linkActivated(QString)),this,SLOT(on_linkActivated(QString)));


}

void Other_Editer::InitBaseTab()
{
    QIntValidator *iValidatorSubPrjNameID=new QIntValidator(this);
    ui->SubPrjNameID->setValidator(iValidatorSubPrjNameID);

    QIntValidator *iValidatorSubPrjNum=new QIntValidator(this);
    ui->SubPrjNum->setValidator(iValidatorSubPrjNum);

    QStringList items;
    items<<tr("Channel1");
    ui->ChannelCBX->addItems(items);



    QIntValidator *iValidatorServerPortNum=new QIntValidator(0,65536,this);
    ui->ServerPortNum->setValidator(iValidatorServerPortNum);


    QIntValidator *iValidatorRetryCount=new QIntValidator(0,255,this);
    ui->RetryCount->setValidator(iValidatorRetryCount);

    QIntValidator *iValidatorRetryInternal=new QIntValidator(0,65536,this);
    ui->RetryInternal->setValidator(iValidatorRetryInternal);

    QIntValidator *iValidatorHeartInternal=new QIntValidator(0,65536,this);
    ui->HeartInternal->setValidator(iValidatorHeartInternal);

    QIntValidator *iValidatorDeviceID1=new QIntValidator(0,99,this);
    ui->DeviceID1->setValidator(iValidatorDeviceID1);
    //
    QIntValidator *iValidatorDeviceID2=new QIntValidator(0,99,this);
    ui->DeviceID2->setValidator(iValidatorDeviceID2);

    QIntValidator *iValidatorDeviceID3=new QIntValidator(0,99,this);
    ui->DeviceID3->setValidator(iValidatorDeviceID3);

    QIntValidator *iValidatorDeviceID4=new QIntValidator(0,99,this);
    ui->DeviceID4->setValidator(iValidatorDeviceID4);

    QIntValidator *iValidatorDeviceID5=new QIntValidator(0,99,this);
    ui->DeviceID5->setValidator(iValidatorDeviceID5);

    QIntValidator *iValidatorDeviceID6=new QIntValidator(0,99,this);
    ui->DeviceID6->setValidator(iValidatorDeviceID6);

    QIntValidator *iValidatorDeviceID7=new QIntValidator(0,99,this);
    ui->DeviceID7->setValidator(iValidatorDeviceID7);

    // QDoubleValidator *fValidatorForRangeLvLEDT= new QDoubleValidator(this);
    //ui->RangeLvlineEdit->setValidator(fValidatorForRangeLvLEDT);
    QDoubleValidator *fValidatorForDensity= new QDoubleValidator(this);
    ui->Density->setValidator(fValidatorForDensity);

    QDoubleValidator *fValidatorForlastVolue= new QDoubleValidator(this);
    ui->lastVolumeText->setValidator(fValidatorForlastVolue);
}

void Other_Editer::InitSystemTab()
{
//    QStringList commProtocolItems;
//    commProtocolItems<<tr("1.富瑞")<<tr("2.山东普联");
//    ui->CommProtocol->addItems(commProtocolItems);

//    QStringList commWayItems;
//    commWayItems<<tr("1.GPRS")<<tr("2.有线网络");
//    ui->CommWay->addItems(commWayItems);

    QStringList gprsPassModeItems;
    gprsPassModeItems<<tr("1.透传")<<tr("2.AT命令");
    ui->GPRS_Pass_Mode->addItems(gprsPassModeItems);

    QStringList sysRestartItems;
    sysRestartItems<<tr("1.不操作")<<tr("2.重启");
    ui->SystemRestart->addItems(sysRestartItems);

    QDoubleValidator *dValidatorDensity=new QDoubleValidator(this);
    ui->Density->setValidator(dValidatorDensity);


}

void Other_Editer::InitDeviceIdLineEditers()
{
    QList<QLineEdit*> pDeviceIdLineEditers;
    pDeviceIdLineEditers.append(ui->DeviceID1);
    pDeviceIdLineEditers.append(ui->DeviceID2);
    pDeviceIdLineEditers.append(ui->DeviceID3);
    pDeviceIdLineEditers.append(ui->DeviceID4);
    pDeviceIdLineEditers.append(ui->DeviceID5);
    pDeviceIdLineEditers.append(ui->DeviceID6);
    pDeviceIdLineEditers.append(ui->DeviceID7);
    m_DeviceId.setPLineEditers(pDeviceIdLineEditers);

}



bool Other_Editer::CheckIp(const QString &ip)
{   bool res=false;
    QString  rx="((25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))\\.){3}(25[0-5]|2[0-4]\\d|((1\\d{2})|([1-9]?\\d)))";
    QRegExp regExp(rx);
    if(regExp.exactMatch(ip))
    {
        res=true;

    }
   return res;


}

void Other_Editer::On_Other_Table_DoubleClick_trigger(QStringList items, EditAttribute attribute, QString databasePath)
{

    m_DataBase.setFilePath(databasePath);
    m_Attribute=attribute;
    quint8 array[7];
//    DateTimeToArray(QDateTime::currentDateTime(), array);
//    m_RtcTimer.setDecValue(array);
    ui->dateTimeEdit->setDateTime(QDateTime::currentDateTime());

    if(attribute==InsertEdit)
    {
        this->setWindowTitle(tr("其他参数设置：添加"));
        ui->ChannelCBX->setEnabled(true);

    }
    else
    {
        this->setWindowTitle(tr("其他参数设置：修改"));
        ui->ChannelCBX->setEnabled(false);
        ui->SubPrjName->setText(items.at(0));
        int currentIndeOfChannelCBX=(items.at(1).toInt())-1;
        ui->ChannelCBX->setCurrentIndex(currentIndeOfChannelCBX);
        ui->SubPrjNameID->setText(items.at(2));
        ui->SubPrjNum->setText(items.at(3));

        int CommProtocolCbxIndex=(items.at(4).toInt())-1;
        ui->CommProtocol->setCurrentIndex(CommProtocolCbxIndex);
        int CommWayCbxIndex=(items.at(5).toInt())-1;
        ui->CommWay->setCurrentIndex(CommWayCbxIndex);
        m_DeviceId.setValue(items.at(6).toULongLong());
        ui->StationID->setText(items.at(7));
        ui->IP_Address->setText(items.at(8));
        ui->ServerPortNum->setText(items.at(9));
        ui->RetryCount->setText(items.at(10));
        ui->RetryInternal->setText(items.at(11));
        ui->HeartInternal->setText(items.at(12));
        //m_RtcTimer.setValue(items.at(13).toULongLong());

        //设置时钟控件数据
        DataBaseToDtEditValue(items.at(13).toULongLong(),ui->dateTimeEdit);

        ui->GPRS_Pass_Mode->setCurrentIndex((items.at(14).toInt())-1);
        ui->Density->setText(items.at(15));
        ui->SystemRestart->setCurrentIndex((items.at(16).toInt())-1);

        ui->lastVolumeText->setText(items.at(17));

    }
}


void Other_Editer::on_ConfirmBtn_clicked()
{
    if(m_Attribute==InsertEdit)
    {
        //添加记录

        Other_Information_Bean bean;
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;


        bean.m_Field=ui->SubPrjName->text();

        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();


        bean.m_Comm_protocol=ui->CommProtocol->currentIndex()+1;
        bean.m_Comm_way=ui->CommWay->currentIndex()+1;
        bean.m_DeviceID=m_DeviceId.Value();
        bean.m_Station_id=(word)(ui->StationID->text().toUInt());
        if(CheckIp(ui->IP_Address->text()))
        {
            bean.m_Ip=ui->IP_Address->text();

        }
        else
        {
            QMessageBox::warning(this,tr("WARNING"),tr("输入IP错误！"));
            return;
        }

        bean.m_Port=(word)(ui->ServerPortNum->text().toUInt());
        bean.m_Retry_counter=(byte)(ui->RetryCount->text().toUInt());
        bean.m_Retry_interval=(word)(ui->RetryInternal->text().toUInt());
        bean.m_Heart_internal=(word)(ui->HeartInternal->text().toUInt());
        //bean.m_Rtc_timer=m_RtcTimer.Value();
        bean.m_Rtc_timer=DtEditToDataBaseValue();
        bean.m_Gprs_pass_mode=ui->GPRS_Pass_Mode->currentIndex()+1;
        bean.m_Density=ui->Density->text().toFloat();
        bean.m_Sys_restart=ui->SystemRestart->currentIndex()+1;
        bean.m_last_volume=ui->lastVolumeText->text().toFloat();









        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter="SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10)+" or ChannelNum="+QString::number(bean.m_ChannelNum,10);
        if(m_DataBase.GetOtherTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的通道,或者平台ID!"));
            return;
        }
        if(m_DataBase.InsertInfoToOtherTable(bean))
        {
            //添加成功，提示成功

            QMessageBox::information(this,tr("INFO"),tr("添加成功"));
            emit Edit_Triggle(Other_Page);
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
        Other_Information_Bean bean;
        bean.m_Field=ui->SubPrjName->text();
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;
        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();


//        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;

//        bean.m_BaudRate=BaudeRateValue();
//        bean.m_DataBits=DataBitsValue();
//        bean.m_Parity=ParityValue();
//        bean.m_StopBit=StopBitValue();
//        bean.m_SlaveId=ui->SlaveID->text().toUInt();
//        bean.m_Manufacturer=ui->Manufacture->text().toUInt();
//        bean.m_Protocol=ui->Protocol->text().toUInt();
        bean.m_Comm_protocol=ui->CommProtocol->currentIndex()+1;
        bean.m_Comm_way=ui->CommWay->currentIndex()+1;
        bean.m_DeviceID=m_DeviceId.Value();
        bean.m_Station_id=(word)(ui->StationID->text().toUInt());
        if(CheckIp(ui->IP_Address->text()))
        {
            bean.m_Ip=ui->IP_Address->text();
        }
        else {
            QMessageBox::warning(this,tr("WARNING"),tr("输入IP错误！"));
            return;
        }

        bean.m_Port=(word)(ui->ServerPortNum->text().toUInt());
        bean.m_Retry_counter=(byte)(ui->RetryCount->text().toUInt());
        bean.m_Retry_interval=(word)(ui->RetryInternal->text().toUInt());
        bean.m_Heart_internal=(word)(ui->HeartInternal->text().toUInt());
        //bean.m_Rtc_timer=m_RtcTimer.Value();
        bean.m_Rtc_timer=DtEditToDataBaseValue();
        bean.m_Gprs_pass_mode=ui->GPRS_Pass_Mode->currentIndex()+1;
        bean.m_Density=ui->Density->text().toFloat();
        bean.m_Sys_restart=ui->SystemRestart->currentIndex()+1;
        bean.m_last_volume=ui->lastVolumeText->text().toFloat();



        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10);
        //QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetSerialPortTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的平台ID!"));
            return;
        }
        if(m_DataBase.UpdateInfoToOtherTable(bean))
        {
            //如果成功
            QMessageBox::information(this,tr("INFO"),tr("修改成功"));
            emit Edit_Triggle(Other_Page);
            this->close();
        }
        else
        {
            //如果失败提示报错信息
            QMessageBox::information(this,tr("ERROR"),m_DataBase.LastError());
            this->close();
        }

    }

}

void Other_Editer::DateTimeToArray(const QDateTime &dt, quint8 *array)
{
    quint8 *pArray=array;
    *(pArray+6)=dt.date().year()/100;
    *(pArray+5)=dt.date().year()%100;
    *(pArray+4)=dt.date().month();
    *(pArray+3)=dt.date().day();
    *(pArray+2)=dt.time().hour();
    *(pArray+1)=dt.time().minute();
    *(pArray+0)=dt.time().second();

}

qulonglong Other_Editer::DtEditToDataBaseValue()
{

    QByteArray dtArray(8,0);
    dtArray[6]=ui->dateTimeEdit->date().year()/100;
    dtArray[5]=ui->dateTimeEdit->date().year()%100;
    dtArray[4]=ui->dateTimeEdit->date().month();
    dtArray[3]=ui->dateTimeEdit->date().day();
    dtArray[2]=ui->dateTimeEdit->time().hour();
    dtArray[1]=ui->dateTimeEdit->time().minute();
    dtArray[0]=ui->dateTimeEdit->time().second();
    //dt_uint64=dtArray.toULongLong();
    qulonglong value=0;
    qulonglong temp=0;
    qulonglong bcd=0;
//    bcd=Xconvert::DectoBCD((quint8)(m_pLineEditers.at(i)->text().toUInt()));
//    temp=bcd<<(i*8);
//    m_Value|=temp;

    for(int i=0;i<dtArray.length();i++)
    {
        bcd=Xconvert::DectoBCD((quint8)dtArray[i]);
        temp=bcd<<(i*8);
        value|=temp;
    }
    return value;
}

void Other_Editer::DataBaseToDtEditValue(qulonglong value, QDateTimeEdit *dtEdit)
{

    quint8 temp=0;
    quint8 dec=0;


    QByteArray dtArray(7,0);
    for(int i=0;i<7;i++)
    {
        temp=(value>>(i*8))&0xff;
        dtArray[i]=Xconvert::BCDtoDec(temp);

    }

    int y=(dtArray[6]*100)+dtArray[5];


    dtEdit->setDate(QDate(y,dtArray[4],dtArray[3]));
    dtEdit->setTime(QTime(dtArray[2],dtArray[1],dtArray[0]));



}


void Other_Editer::on_CancelBtn_clicked()
{
    this->close();

}

void Other_Editer::on_getPC_TimeBtn_clicked()
{
//    quint8 array[7];
//    DateTimeToArray(QDateTime::currentDateTime(), array);
//    m_RtcTimer.setDecValue(array);
    ui->dateTimeEdit->setDateTime(QDateTime(QDate::currentDate(),QTime::currentTime()));

}

void Other_Editer::on_linkActivated(QString s)
{
//    if(m_pSubProjectNameTable==Q_NULLPTR)
//    {
//        QMessageBox::warning(this,tr("WARNING"),tr("未找到系统配置信息"));
//        return;
//    }
//     connect(this,SIGNAL(linkSubProjectName(EditPageNum)),m_pSubProjectNameTable,SLOT(on_linkced(EditPageNum)));
//     connect(m_pSubProjectNameTable,SIGNAL(setDI_Edit_Info(SubProjectNameBean)),this,SLOT(on_setDI_Edit_Info(SubProjectNameBean)));
//    //发送信号：告知系统信息表属于：AI，DI，DO...的哪一种
//    emit linkSubProjectName(DI_Page);
//    m_pSubProjectNameTable->exec();

}

void Other_Editer::getSysInfo(QMap<int, QString> commProtocol, QMap<int, QString> commWay)
{
    //把数据表（来自系统信息数据库）

    m_mapCommProtocol=commProtocol;

    m_mapcommWay=commWay;

    QMap<int, QString>::const_iterator i;


    for(i=commProtocol.begin();i!=commProtocol.end();i++)
    {

        ui->CommProtocol->addItem(i.value());
    }

    for(i=commWay.begin();i!=commWay.end();i++)
    {

        ui->CommWay->addItem(i.value());
    }

}
