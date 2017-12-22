#include "ai_edit.h"
#include "ui_ai_edit.h"
#include <QStringList>
#include <QMessageBox>
AI_Edit::AI_Edit(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AI_Edit)
{
    ui->setupUi(this);
    InitUi();
    ui->gridLayout->setRowStretch(0,9);
    ui->gridLayout->setRowStretch(1,1);
    InitRelaventTab();
    InitBaseTab();
    InitAlarmTab();
}

AI_Edit::~AI_Edit()
{
    delete ui;
}



void AI_Edit::InitUi()
{
    ui->tabWidget->setTabText(0,tr("基本参数"));
    ui->tabWidget->setTabText(1,tr("报警参数"));
    ui->tabWidget->setTabText(2,tr("报警关联"));



}

void AI_Edit::InitH_ALM()
{
    QList<QCheckBox *> pCheckBox;
    pCheckBox.append(ui->H_DO1_ENB);
    pCheckBox.append(ui->H_DO2_ENB);
    pCheckBox.append(ui->H_DO3_ENB);
    pCheckBox.append(ui->H_DO4_ENB);
    pCheckBox.append(ui->H_DO5_ENB);
    pCheckBox.append(ui->H_DO6_ENB);
    pCheckBox.append(ui->H_DO7_ENB);
    pCheckBox.append(ui->H_DO8_ENB);
    pCheckBox.append(ui->H_DO9_ENB);
    pCheckBox.append(ui->H_DO10_ENB);
    pCheckBox.append(ui->H_DO11_ENB);
    pCheckBox.append(ui->H_DO12_ENB);
    pCheckBox.append(ui->H_DO13_ENB);
    pCheckBox.append(ui->H_DO14_ENB);
    pCheckBox.append(ui->H_DO15_ENB);
    pCheckBox.append(ui->H_DO16_ENB);

    pCheckBox.append(ui->H_DO1_OUT);
    pCheckBox.append(ui->H_DO2_OUT);
    pCheckBox.append(ui->H_DO3_OUT);
    pCheckBox.append(ui->H_DO4_OUT);
    pCheckBox.append(ui->H_DO5_OUT);
    pCheckBox.append(ui->H_DO6_OUT);
    pCheckBox.append(ui->H_DO7_OUT);
    pCheckBox.append(ui->H_DO8_OUT);
    pCheckBox.append(ui->H_DO9_OUT);
    pCheckBox.append(ui->H_DO10_OUT);
    pCheckBox.append(ui->H_DO11_OUT);
    pCheckBox.append(ui->H_DO12_OUT);
    pCheckBox.append(ui->H_DO13_OUT);
    pCheckBox.append(ui->H_DO14_OUT);
    pCheckBox.append(ui->H_DO15_OUT);
    pCheckBox.append(ui->H_DO16_OUT);
    m_H_Relevant.setPCheckBox(pCheckBox);

}

void AI_Edit::InitHH_ALM()
{

    QList<QCheckBox *> pCheckBox;
    pCheckBox.append(ui->HH_DO1_ENB);
    pCheckBox.append(ui->HH_DO2_ENB);
    pCheckBox.append(ui->HH_DO3_ENB);
    pCheckBox.append(ui->HH_DO4_ENB);
    pCheckBox.append(ui->HH_DO5_ENB);
    pCheckBox.append(ui->HH_DO6_ENB);
    pCheckBox.append(ui->HH_DO7_ENB);
    pCheckBox.append(ui->HH_DO8_ENB);
    pCheckBox.append(ui->HH_DO9_ENB);
    pCheckBox.append(ui->HH_DO10_ENB);
    pCheckBox.append(ui->HH_DO11_ENB);
    pCheckBox.append(ui->HH_DO12_ENB);
    pCheckBox.append(ui->HH_DO13_ENB);
    pCheckBox.append(ui->HH_DO14_ENB);
    pCheckBox.append(ui->HH_DO15_ENB);
    pCheckBox.append(ui->HH_DO16_ENB);

    pCheckBox.append(ui->HH_DO1_OUT);
    pCheckBox.append(ui->HH_DO2_OUT);
    pCheckBox.append(ui->HH_DO3_OUT);
    pCheckBox.append(ui->HH_DO4_OUT);
    pCheckBox.append(ui->HH_DO5_OUT);
    pCheckBox.append(ui->HH_DO6_OUT);
    pCheckBox.append(ui->HH_DO7_OUT);
    pCheckBox.append(ui->HH_DO8_OUT);
    pCheckBox.append(ui->HH_DO9_OUT);
    pCheckBox.append(ui->HH_DO10_OUT);
    pCheckBox.append(ui->HH_DO11_OUT);
    pCheckBox.append(ui->HH_DO12_OUT);
    pCheckBox.append(ui->HH_DO13_OUT);
    pCheckBox.append(ui->HH_DO14_OUT);
    pCheckBox.append(ui->HH_DO15_OUT);
    pCheckBox.append(ui->HH_DO16_OUT);
    m_HH_Relevant.setPCheckBox(pCheckBox);
}

void AI_Edit::InitL_ALM()
{
    QList<QCheckBox *> pCheckBox;
    pCheckBox.append(ui->L_DO1_ENB);
    pCheckBox.append(ui->L_DO2_ENB);
    pCheckBox.append(ui->L_DO3_ENB);
    pCheckBox.append(ui->L_DO4_ENB);
    pCheckBox.append(ui->L_DO5_ENB);
    pCheckBox.append(ui->L_DO6_ENB);
    pCheckBox.append(ui->L_DO7_ENB);
    pCheckBox.append(ui->L_DO8_ENB);
    pCheckBox.append(ui->L_DO9_ENB);
    pCheckBox.append(ui->L_DO10_ENB);
    pCheckBox.append(ui->L_DO11_ENB);
    pCheckBox.append(ui->L_DO12_ENB);
    pCheckBox.append(ui->L_DO13_ENB);
    pCheckBox.append(ui->L_DO14_ENB);
    pCheckBox.append(ui->L_DO15_ENB);
    pCheckBox.append(ui->L_DO16_ENB);

    pCheckBox.append(ui->L_DO1_OUT);
    pCheckBox.append(ui->L_DO2_OUT);
    pCheckBox.append(ui->L_DO3_OUT);
    pCheckBox.append(ui->L_DO4_OUT);
    pCheckBox.append(ui->L_DO5_OUT);
    pCheckBox.append(ui->L_DO6_OUT);
    pCheckBox.append(ui->L_DO7_OUT);
    pCheckBox.append(ui->L_DO8_OUT);
    pCheckBox.append(ui->L_DO9_OUT);
    pCheckBox.append(ui->L_DO10_OUT);
    pCheckBox.append(ui->L_DO11_OUT);
    pCheckBox.append(ui->L_DO12_OUT);
    pCheckBox.append(ui->L_DO13_OUT);
    pCheckBox.append(ui->L_DO14_OUT);
    pCheckBox.append(ui->L_DO15_OUT);
    pCheckBox.append(ui->L_DO16_OUT);
    m_L_Relevant.setPCheckBox(pCheckBox);

}

void AI_Edit::InitLL_ALM()
{
    QList<QCheckBox *> pCheckBox;
    pCheckBox.append(ui->LL_DO1_ENB);
    pCheckBox.append(ui->LL_DO2_ENB);
    pCheckBox.append(ui->LL_DO3_ENB);
    pCheckBox.append(ui->LL_DO4_ENB);
    pCheckBox.append(ui->LL_DO5_ENB);
    pCheckBox.append(ui->LL_DO6_ENB);
    pCheckBox.append(ui->LL_DO7_ENB);
    pCheckBox.append(ui->LL_DO8_ENB);
    pCheckBox.append(ui->LL_DO9_ENB);
    pCheckBox.append(ui->LL_DO10_ENB);
    pCheckBox.append(ui->LL_DO11_ENB);
    pCheckBox.append(ui->LL_DO12_ENB);
    pCheckBox.append(ui->LL_DO13_ENB);
    pCheckBox.append(ui->LL_DO14_ENB);
    pCheckBox.append(ui->LL_DO15_ENB);
    pCheckBox.append(ui->LL_DO16_ENB);

    pCheckBox.append(ui->LL_DO1_OUT);
    pCheckBox.append(ui->LL_DO2_OUT);
    pCheckBox.append(ui->LL_DO3_OUT);
    pCheckBox.append(ui->LL_DO4_OUT);
    pCheckBox.append(ui->LL_DO5_OUT);
    pCheckBox.append(ui->LL_DO6_OUT);
    pCheckBox.append(ui->LL_DO7_OUT);
    pCheckBox.append(ui->LL_DO8_OUT);
    pCheckBox.append(ui->LL_DO9_OUT);
    pCheckBox.append(ui->LL_DO10_OUT);
    pCheckBox.append(ui->LL_DO11_OUT);
    pCheckBox.append(ui->LL_DO12_OUT);
    pCheckBox.append(ui->LL_DO13_OUT);
    pCheckBox.append(ui->LL_DO14_OUT);
    pCheckBox.append(ui->LL_DO15_OUT);
    pCheckBox.append(ui->LL_DO16_OUT);
    m_LL_Relevant.setPCheckBox(pCheckBox);

}

void AI_Edit::InitRelaventTab()
{
    InitRelevantValue();

}

void AI_Edit::InitBaseTab()
{

    //量程高限，量程低限只允许输入浮点型
    QDoubleValidator *fValidatorForRangeLvLEDT= new QDoubleValidator(this);
    ui->RangeLvlineEdit->setValidator(fValidatorForRangeLvLEDT);
    QDoubleValidator *fValidatorForRangeHvLEDT= new QDoubleValidator(this);
    ui->RangeHvlineEdit->setValidator(fValidatorForRangeHvLEDT);
    QIntValidator *iValidatorSubPrjNameID=new QIntValidator(this);
    ui->SubPrjNameID->setValidator(iValidatorSubPrjNameID);

    QIntValidator *iValidatorSubPrjNum=new QIntValidator(this);
    ui->SubPrjNum->setValidator(iValidatorSubPrjNum);

    QStringList items;
    items<<"A1"
        <<"A2"
       <<"A3"
      <<"A4"
     <<"A5"
    <<"A6"
    <<"A7"
    <<"A8"
    <<"A9"
    <<"A10"
    <<"A11"
    <<"A12"
    <<"A13"
    <<"A14"
    <<"A15"
    <<"A16";

    ui->ChannelCBX->addItems(items);


    ui->Linklable->setText(tr("<a href=\"#\">获取平台参数"));
    connect(ui->Linklable,SIGNAL(linkActivated(QString)),this,SLOT(on_linkActivated(QString)));

}

void AI_Edit::InitAlarmTab()
{
    QDoubleValidator *fValidatorForAlarmHHvLineEdit= new QDoubleValidator(this);
    ui->AlarmHHvLineEdit->setValidator(fValidatorForAlarmHHvLineEdit);
    QDoubleValidator *fValidatorForAlarmHvLineEdit= new QDoubleValidator(this);
    ui->AlarmHvLineEdit->setValidator(fValidatorForAlarmHvLineEdit);
    QDoubleValidator *fValidatorForAlarmLLvLineEdit= new QDoubleValidator(this);
    ui->AlarmLLvLineEdit->setValidator(fValidatorForAlarmLLvLineEdit);
    QDoubleValidator *fValidatorForAlarmLvLineEdit= new QDoubleValidator(this);
    ui->AlarmLvLineEdit->setValidator(fValidatorForAlarmLvLineEdit);

}



void AI_Edit::InitRelevantValue()
{
    InitH_ALM();
    InitHH_ALM();
    InitL_ALM();
    InitLL_ALM();


}






void AI_Edit::on_ConfirmBtn_clicked()
{


    if(m_Attribute==InsertEdit)
    {
        //添加记录
        AI_Information_Bean bean;
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;


        bean.m_Field=ui->SubPrjName->text();

        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();
        bean.m_RangeHV=ui->RangeHvlineEdit->text().toFloat();
        bean.m_RangeLV=ui->RangeLvlineEdit->text().toFloat();

        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;
        bean.m_AlarmHV=ui->AlarmHvLineEdit->text().toFloat();
        bean.m_AlarmHHV=ui->AlarmHHvLineEdit->text().toFloat();
        bean.m_AlarmLV=ui->AlarmLvLineEdit->text().toFloat();
        bean.m_AlarmLLV=ui->AlarmLLvLineEdit->text().toFloat();

        bean.m_H_Alarm_RelatedTo=m_H_Relevant.AlarmtRelevantValue();
        bean.m_HH_Alarm_RelatedTo=m_HH_Relevant.AlarmtRelevantValue();
        bean.m_L_Alarm_RelatedTo=m_L_Relevant.AlarmtRelevantValue();
        bean.m_LL_Alarm_RelatedTo=m_LL_Relevant.AlarmtRelevantValue();

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetAiTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的AI通道,或者平台ID!"));
            return;
        }
        if(m_DataBase.InsertInfoToAiTable(bean))
        {
            //添加成功，提示成功

            QMessageBox::information(this,tr("INFO"),tr("添加成功"));
            emit Edit_Triggle(AI_Page);
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
        AI_Information_Bean bean;
        bean.m_Field=ui->SubPrjName->text();
        bean.m_ChannelNum=ui->ChannelCBX->currentIndex()+1;
        bean.m_SubProjectName=ui->SubPrjNameID->text().toUInt();
        bean.m_SubProjectNum=ui->SubPrjNum->text().toUInt();
        bean.m_RangeHV=ui->RangeHvlineEdit->text().toFloat();
        bean.m_RangeLV=ui->RangeLvlineEdit->text().toFloat();

        bean.m_Enable=(ui->EnableCBX->isChecked())?0x1:0x0;
        bean.m_AlarmHV=ui->AlarmHvLineEdit->text().toFloat();
        bean.m_AlarmHHV=ui->AlarmHHvLineEdit->text().toFloat();
        bean.m_AlarmLV=ui->AlarmLvLineEdit->text().toFloat();
        bean.m_AlarmLLV=ui->AlarmLLvLineEdit->text().toFloat();

        bean.m_H_Alarm_RelatedTo=m_H_Relevant.AlarmtRelevantValue();
        bean.m_HH_Alarm_RelatedTo=m_HH_Relevant.AlarmtRelevantValue();
        bean.m_L_Alarm_RelatedTo=m_L_Relevant.AlarmtRelevantValue();
        bean.m_LL_Alarm_RelatedTo=m_LL_Relevant.AlarmtRelevantValue();

        /*不能与其他记录的 channelNum 和 subProjectName相同*/
        QString sql_filter="ChannelNum<>"+QString::number(bean.m_ChannelNum,10) +" and SubProjectName="+QString::number(bean.m_SubProjectName,10);
        if(m_DataBase.GetAiTableInfo(sql_filter))
        {
            QMessageBox::information(this,tr("ERROR"),tr("存在相同的平台ID!"));
            return;
        }
        if(m_DataBase.UpdateInfoToAiTable(bean))
        {
            //如果成功
            QMessageBox::information(this,tr("INFO"),tr("修改成功"));
            emit Edit_Triggle(AI_Page);
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

void AI_Edit::on_linkActivated(QString s)
{
    QMessageBox::information(this,tr("test"),s);
}

void AI_Edit::On_AI_Table_DoubleClick_trigger(QStringList items, EditAttribute attribute,QString databasePath)
{
    m_DataBase.setFilePath(databasePath);
    m_Attribute=attribute;
    if(attribute==InsertEdit)
    {
        this->setWindowTitle(tr("模拟量设置：添加"));
        ui->ChannelCBX->setEnabled(true);



    }
    else
    {
        this->setWindowTitle(tr("模拟量设置：修改"));
        ui->ChannelCBX->setEnabled(false);
        ui->SubPrjName->setText(items.at(0));
        int currentIndeOfChannelCBX=(items.at(1).toInt())-1;
        ui->ChannelCBX->setCurrentIndex(currentIndeOfChannelCBX);
        ui->SubPrjNameID->setText(items.at(2));
        ui->SubPrjNum->setText(items.at(3));
        bool checked=(items.at(4).toInt()&0x1)==1?true:false;
        ui->EnableCBX->setChecked(checked);
        ui->RangeLvlineEdit->setText(items.at(5));
        ui->RangeHvlineEdit->setText(items.at(6));
        ui->AlarmHvLineEdit->setText(items.at(7));
        ui->AlarmHHvLineEdit->setText(items.at(8));
        ui->AlarmLvLineEdit->setText(items.at(9));
        ui->AlarmLLvLineEdit->setText(items.at(10));
        dword hAlarmRelevantValue=items.at(11).toUInt();
        m_H_Relevant.setAlarmtRelevantValue(hAlarmRelevantValue);
        dword hHAlarmRelevantValue=items.at(12).toUInt();
        m_HH_Relevant.setAlarmtRelevantValue(hHAlarmRelevantValue);
        dword LAlarmRelevantValue=items.at(13).toUInt();
        m_L_Relevant.setAlarmtRelevantValue(LAlarmRelevantValue);

        dword LLAlarmRelevantValue=items.at(14).toUInt();
        m_LL_Relevant.setAlarmtRelevantValue(LLAlarmRelevantValue);

    }
}


void AI_Edit::on_CancelBtn_clicked()
{

    this->close();
}
