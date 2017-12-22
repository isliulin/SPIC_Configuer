#ifndef OTHER_INFORMATION_BEAN_H
#define OTHER_INFORMATION_BEAN_H
#include <QObject>
#include <QString>
#include "common/commonhead.h"
#include <QStringList>

class Other_Information_Bean
{
public:
    Other_Information_Bean();
    Other_Information_Bean(const Other_Information_Bean& bean);

    QString  m_Field;
    byte m_ChannelNum;
    byte m_SubProjectName;
    byte m_SubProjectNum;
    byte m_Comm_protocol;
    byte m_Comm_way;
    qulonglong m_DeviceID;
    word m_Station_id;
    QString m_Ip;
    word m_Port;
    byte m_Retry_counter;
    word m_Retry_interval;
    word m_Heart_internal;
    qulonglong m_Rtc_timer;
    byte m_Gprs_pass_mode;
    float m_Density;
    byte m_Sys_restart;

    QStringList m_Stringlist;

    QStringList & ToQstringlist();

};

#endif // OTHER_INFORMATION_BEAN_H
