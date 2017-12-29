#include "di_edit.h"
#include "ui_di_edit.h"

DI_Edit::DI_Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DI_Edit)
{
    ui->setupUi(this);
    InitUi();
    InitRelevantValue();
    InitBaseTab();
}

DI_Edit::~DI_Edit()
{
    delete ui;
}

void DI_Edit::InitRelevantValue()
{
    QList<QCheckBox *> pCheckBox;
    pCheckBox.append(ui->DI_DO1_ENB);
    pCheckBox.append(ui->DI_DO2_ENB);
    pCheckBox.append(ui->DI_DO3_ENB);
    pCheckBox.append(ui->DI_DO4_ENB);
    pCheckBox.append(ui->DI_DO5_ENB);
    pCheckBox.append(ui->DI_DO6_ENB);
    pCheckBox.append(ui->DI_DO7_ENB);
    pCheckBox.append(ui->DI_DO8_ENB);
    pCheckBox.append(ui->DI_DO9_ENB);
    pCheckBox.append(ui->DI_DO10_ENB);
    pCheckBox.append(ui->DI_DO11_ENB);
    pCheckBox.append(ui->DI_DO12_ENB);
    pCheckBox.append(ui->DI_DO13_ENB);
    pCheckBox.append(ui->DI_DO14_ENB);
    pCheckBox.append(ui->DI_DO15_ENB);
    pCheckBox.append(ui->DI_DO16_ENB);

    pCheckBox.append(ui->DI_DO1_OUT);
    pCheckBox.append(ui->DI_DO2_OUT);
    pCheckBox.append(ui->DI_DO3_OUT);
    pCheckBox.append(ui->DI_DO4_OUT);
    pCheckBox.append(ui->DI_DO5_OUT);
    pCheckBox.append(ui->DI_DO6_OUT);
    pCheckBox.append(ui->DI_DO7_OUT);
    pCheckBox.append(ui->DI_DO8_OUT);
    pCheckBox.append(ui->DI_DO9_OUT);
    pCheckBox.append(ui->DI_DO10_OUT);
    pCheckBox.append(ui->DI_DO11_OUT);
    pCheckBox.append(ui->DI_DO12_OUT);
    pCheckBox.append(ui->DI_DO13_OUT);
    pCheckBox.append(ui->DI_DO14_OUT);
    pCheckBox.append(ui->DI_DO15_OUT);
    pCheckBox.append(ui->DI_DO16_OUT);
    m_DI_Relevant.setPCheckBox(pCheckBox);
}

void DI_Edit::InitBaseTab()
{
    //量程高限，量程低限只允许输入浮点型

    QIntValidator *iValidatorSubPrjNameID=new QIntValidator(this);
    ui->SubPrjNameID->setValidator(iValidatorSubPrjNameID);

    QIntValidator *iValidatorSubPrjNum=new QIntValidator(this);
    ui->SubPrjNum->setValidator(iValidatorSubPrjNum);

    QStringList items;
    items<<"DI1"
        <<"DI2"
       <<"DI3"
      <<"DI4"
     <<"DI5"
    <<"DI6"
    <<"DI7"
    <<"DI8";

    ui->ChannelCBX->addItems(items);
    ui->Linklable->setText(tr("<a href=\"#\">获取平台参数"));

    connect(ui->Linklable,SIGNAL(linkActivated(QString)),this,SLOT(on_linkActivated(QString)));
}

void DI_Edit::InitAlarmTab()
{

}

void DI_Edit::InitUi()
{
    ui->tabWidget->setTabText(0,tr("基本参数"));
    ui->tabWidget->setTabText(1,tr("报警参数"));
    ui->tabWidget->setTabText(2,tr("报警关联"));
}

void DI_Edit::getSubProjectNameTable(SubProjectNameTable *pSubProjectNameTable)
{

    m_pSubProjectNameTable=pSubProjectNameTable;

}

void DI_Edit::on_ConfirmBtn_clicked()
{
    if(m_Attribute==InsertEdit)
    {
        //添加记录
        DI_Information_Bean bean;
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;


        bean.m_Field=ui->SubPrjName->text();

        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();

        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;


        bean.m_DI_Alarm_RelatedTo=m_DI_Relevant.AlarmtRelevantValue();


        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter="(SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10)+")"+" or ChannelNum="+QString::number(bean.m_ChannelNum,10);
        if(m_DataBase.GetDiTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的DI通道,或者平台ID!"));
            return;
        }
        if(m_DataBase.InsertInfoToDiTable(bean))
        {
            //添加成功，提示成功

            QMessageBox::information(this,tr("INFO"),tr("添加成功"));
            emit Edit_Triggle(DI_Page);
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
        DI_Information_Bean bean;
        bean.m_Field=ui->SubPrjName->text();
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;
        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();


        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;


        bean.m_DI_Alarm_RelatedTo=m_DI_Relevant.AlarmtRelevantValue();


        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        //QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10);
        if(m_DataBase.GetDiTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的平台ID!"));
            return;
        }
        if(m_DataBase.UpdateInfoToDiTable(bean))
        {
            //如果成功
            QMessageBox::information(this,tr("INFO"),tr("修改成功"));
            emit Edit_Triggle(DI_Page);
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

void DI_Edit::On_DI_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath)
{
    m_DataBase.setFilePath(databasePath);
    m_Attribute=attribute;
    if(attribute==InsertEdit)
    {
        this->setWindowTitle(tr("数字量输入设置：添加"));
        ui->ChannelCBX->setEnabled(true);



    }
    else
    {
        this->setWindowTitle(tr("数字量输入设置：修改"));
        ui->ChannelCBX->setEnabled(false);
        ui->SubPrjName->setText(items.at(0));
        int currentIndeOfChannelCBX=(items.at(1).toInt())-1;
        ui->ChannelCBX->setCurrentIndex(currentIndeOfChannelCBX);
        ui->SubPrjNameID->setText(items.at(2));
        ui->SubPrjNum->setText(items.at(3));
        bool checked=(items.at(4).toInt()&0x1)==1?true:false;
        ui->EnableCBX->setChecked(checked);

        dword DiAlarmRelevantValue=items.at(5).toUInt();
        m_DI_Relevant.setAlarmtRelevantValue(DiAlarmRelevantValue);

    }
}

void DI_Edit::on_linkActivated(QString s)
{
    if(m_pSubProjectNameTable==Q_NULLPTR)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("未找到系统配置信息"));
        return;
    }
     connect(this,SIGNAL(linkSubProjectName(EditPageNum)),m_pSubProjectNameTable,SLOT(on_linkced(EditPageNum)));
     connect(m_pSubProjectNameTable,SIGNAL(setDI_Edit_Info(SubProjectNameBean)),this,SLOT(on_setDI_Edit_Info(SubProjectNameBean)));
    //发送信号：告知系统信息表属于：AI，DI，DO...的哪一种
    emit linkSubProjectName(DI_Page);
    m_pSubProjectNameTable->exec();

}

void DI_Edit::on_setDI_Edit_Info(SubProjectNameBean bean)
{
    //SubPrjNameID
    //SubPrjName
    ui->SubPrjName->setText(bean.m_Filed);
    ui->SubPrjNameID->setText(QString::number(bean.m_SeriesNumber,10));

}

