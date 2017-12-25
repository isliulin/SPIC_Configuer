#ifndef SERIALPORT_INFORMATION_BEAN_H
#define SERIALPORT_INFORMATION_BEAN_H
#include <QObject>
#include <QString>
#include "common/commonhead.h"
#include <QStringList>

class SerialPort_Information_Bean
{
public:
    SerialPort_Information_Bean();
    SerialPort_Information_Bean(const SerialPort_Information_Bean& bean);
    QString  m_Field;
    byte m_ChannelNum;
    byte m_SubProjectName;
    byte m_SubProjectNum;
    byte m_Enable;
    dword m_BaudRate;
    byte m_DataBits;
    byte m_Parity;
    byte m_StopBit;
    byte m_SlaveId;
    byte m_Manufacturer;
    byte m_Protocol;
    QStringList m_Stringlist;

    QStringList & ToQstringlist();
};

#endif // SERIALPORT_INFORMATION_BEAN_H
