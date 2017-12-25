#include "serialport_information_bean.h"

SerialPort_Information_Bean::SerialPort_Information_Bean()
{
   m_Field="";
   m_ChannelNum=0;
   m_SubProjectName=0;
   m_SubProjectNum=0;
   m_Enable=0;
    m_BaudRate=0;
   m_DataBits=0;
   m_Parity=0;
   m_StopBit=0;
   m_SlaveId=0;
   m_Manufacturer=0;
   m_Protocol=0;

}

SerialPort_Information_Bean::SerialPort_Information_Bean(const SerialPort_Information_Bean &bean)
{
    m_Field=bean.m_Field;
    m_ChannelNum=bean.m_ChannelNum;
    m_SubProjectName=bean.m_SubProjectName;
    m_SubProjectNum=bean.m_SubProjectNum;
    m_Enable=bean.m_Enable;
    m_BaudRate=bean.m_BaudRate;
    m_DataBits=bean.m_DataBits;
    m_Parity=bean.m_Parity;
    m_StopBit=bean.m_StopBit;
    m_SlaveId=bean.m_SlaveId;
    m_Manufacturer=bean.m_Manufacturer;
    m_Protocol=bean.m_Protocol;

}

QStringList &SerialPort_Information_Bean::ToQstringlist()
{
    m_Stringlist.clear();

    m_Stringlist.append(m_Field);
    m_Stringlist.append(QString::number(m_ChannelNum,10));
    m_Stringlist.append(QString::number(m_SubProjectName,10));
    m_Stringlist.append(QString::number(m_SubProjectNum,10));
    m_Stringlist.append(QString::number(m_Enable,10));
    m_Stringlist.append(QString::number(m_BaudRate,10));
    m_Stringlist.append(QString::number(m_DataBits,10));
    m_Stringlist.append(QString::number(m_Parity,10));
    m_Stringlist.append(QString::number(m_StopBit,10));
    m_Stringlist.append(QString::number(m_SlaveId,10));
    m_Stringlist.append(QString::number(m_Manufacturer,10));
    m_Stringlist.append(QString::number(m_Protocol,10));
    return m_Stringlist;

}
