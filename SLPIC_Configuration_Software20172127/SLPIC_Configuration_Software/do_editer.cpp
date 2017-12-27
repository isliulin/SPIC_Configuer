#include "do_editer.h"
#include "ui_do_editer.h"

DO_Editer::DO_Editer(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::DO_Editer)
{
    ui->setupUi(this);
    InitUi();
    InitBaseTab();
    InitAlarmTab();
}

DO_Editer::~DO_Editer()
{
    delete ui;
}

void DO_Editer::InitUi()
{
    ui->tabWidget->setTabText(0,tr("基本参数"));
    ui->tabWidget->setTabText(1,tr("报警参数"));
}

void DO_Editer::InitBaseTab()
{
    QIntValidator *iValidatorSubPrjNameID=new QIntValidator(this);
    ui->SubPrjNameID->setValidator(iValidatorSubPrjNameID);

    QIntValidator *iValidatorSubPrjNum=new QIntValidator(this);
    ui->SubPrjNum->setValidator(iValidatorSubPrjNum);

    QStringList items;
    items<<"DO1"
        <<"DO2"
       <<"DO3"
      <<"DO4"
     <<"DO5"
    <<"DO6"
    <<"DO7"
    <<"DO8";
    ui->ChannelCBX->addItems(items);

    ui->Linklable->setText(tr("<a href=\"#\">获取平台参数"));
    connect(ui->Linklable,SIGNAL(linkActivated(QString)),this,SLOT(on_linkActivated(QString)));


}

void DO_Editer::InitAlarmTab()
{

}

void DO_Editer::getSubProjectNameTable(SubProjectNameTable *pSubProjectNameTable)
{
     m_pSubProjectNameTable=pSubProjectNameTable;

}

void DO_Editer::On_DO_Table_DoubleClick_trigger(QStringList items, EditAttribute attribute, QString databasePath)
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
    }

}

void DO_Editer::on_ConfirmBtn_clicked()
{

    if(m_Attribute==InsertEdit)
    {
        //添加记录
        DO_Information_Bean bean;
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;


        bean.m_Field=ui->SubPrjName->text();

        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();

        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="(SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10)+")"+" or ChannelNum="+QString::number(bean.m_ChannelNum,10);
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetDoTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的DO通道,或者平台ID!"));
            return;
        }
        if(m_DataBase.InsertInfoToDoTable(bean))
        {
            //添加成功，提示成功

            QMessageBox::information(this,tr("INFO"),tr("添加成功"));
            emit Edit_Triggle(DO_Page);
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
        DO_Information_Bean bean;
        bean.m_Field=ui->SubPrjName->text();
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;
        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();


        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10)+" and SubProjectNum="+QString::number(bean.m_SubProjectNum,10);
        //QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetDoTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的平台ID!"));
            return;
        }
        if(m_DataBase.UpdateInfoToDoTable(bean))
        {
            //如果成功
            QMessageBox::information(this,tr("INFO"),tr("修改成功"));
            emit Edit_Triggle(DO_Page);
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

void DO_Editer::on_linkActivated(QString s)
{
    if(m_pSubProjectNameTable==Q_NULLPTR)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("未找到系统配置信息"));
        return;
    }
     connect(this,SIGNAL(linkSubProjectName(EditPageNum)),m_pSubProjectNameTable,SLOT(on_linkced(EditPageNum)));
     connect(m_pSubProjectNameTable,SIGNAL(setDO_Edit_Info(SubProjectNameBean)),this,SLOT(on_setDO_Edit_Info(SubProjectNameBean)));
    //发送信号：告知系统信息表属于：AI，DI，DO...的哪一种
    emit linkSubProjectName(DO_Page);
    m_pSubProjectNameTable->exec();

}

void DO_Editer::on_setDO_Edit_Info(SubProjectNameBean bean)
{
    ui->SubPrjName->setText(bean.m_Filed);
    ui->SubPrjNameID->setText(QString::number(bean.m_SeriesNumber,10));


}
