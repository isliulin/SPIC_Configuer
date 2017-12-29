#include "other_information_bean.h"

Other_Information_Bean::Other_Information_Bean()
{
    m_Field="";
    m_ChannelNum=0;
    m_SubProjectName=0;
    m_SubProjectNum=0;
    m_Comm_protocol=0;
    m_Comm_way=0;
    m_DeviceID=0;
    m_Station_id=0;
    m_Ip="";
    m_Port=0;
    m_Retry_counter=0;
    m_Retry_interval=0;
    m_Heart_internal=0;
    m_Rtc_timer=0;
    m_Gprs_pass_mode=0;
    m_Density=0;
    m_Sys_restart=0;
    m_last_volume=0;

}

Other_Information_Bean::Other_Information_Bean(const Other_Information_Bean &bean)
{
    m_Field=bean.m_Field;
    m_ChannelNum=bean.m_ChannelNum;
    m_SubProjectName=bean.m_SubProjectName;
    m_SubProjectNum=bean.m_SubProjectNum;
    m_Comm_protocol=bean.m_Comm_protocol;
    m_Comm_way=bean.m_Comm_way;
    m_DeviceID=bean.m_DeviceID;
    m_Station_id=bean.m_Station_id;
    m_Ip=bean.m_Ip;
    m_Port=bean.m_Port;
    m_Retry_counter=bean.m_Retry_counter;
    m_Retry_interval=bean.m_Retry_interval;
    m_Heart_internal=bean.m_Heart_internal;
    m_Rtc_timer=bean.m_Rtc_timer;
    m_Gprs_pass_mode=bean.m_Gprs_pass_mode;
    m_Density=bean.m_Density;
    m_Sys_restart=bean.m_Sys_restart;
    m_last_volume=bean.m_last_volume;

}

QStringList &Other_Information_Bean::ToQstringlist()
{
    m_Stringlist.clear();
    m_Stringlist.append(m_Field);
    m_Stringlist.append(QString::number(m_ChannelNum,10));
    m_Stringlist.append(QString::number(m_SubProjectName,10));
    m_Stringlist.append(QString::number(m_SubProjectNum,10));
    m_Stringlist.append(QString::number(m_Comm_protocol,10));

    m_Stringlist.append(QString::number(m_Comm_way,10));
    m_Stringlist.append(QString::number(m_DeviceID,10));
    m_Stringlist.append(QString::number(m_Station_id,10));
    m_Stringlist.append(m_Ip);

    m_Stringlist.append(QString::number(m_Port,10));
    m_Stringlist.append(QString::number(m_Retry_counter,10));
    m_Stringlist.append(QString::number(m_Retry_interval,10));
    m_Stringlist.append(QString::number(m_Heart_internal,10));

    m_Stringlist.append(QString::number(m_Rtc_timer,10));
    m_Stringlist.append(QString::number(m_Gprs_pass_mode,10));
    m_Stringlist.append(QString::number(m_Density));
    m_Stringlist.append(QString::number(m_Sys_restart,10));
    //m_last_volume

    m_Stringlist.append(QString::number(m_last_volume));
    return m_Stringlist;

}
