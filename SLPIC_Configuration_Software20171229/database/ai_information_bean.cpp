#include "ai_information_bean.h"

AI_Information_Bean::AI_Information_Bean()
{
    m_Field="";
    m_ChannelNum=0;
    m_SubProjectName=0;
    m_SubProjectNum=0;
    m_Enable=0;
    m_RangeLV=0;
    m_RangeHV=0;
    m_AlarmHV=0;
    m_AlarmHHV=0;
    m_AlarmLV=0;
    m_AlarmLLV=0;
    m_H_Alarm_RelatedTo=0;
    m_HH_Alarm_RelatedTo=0;
    m_L_Alarm_RelatedTo=0;
    m_LL_Alarm_RelatedTo=0;
    
}

AI_Information_Bean::AI_Information_Bean(const AI_Information_Bean &bean)
{
    m_Field                         =bean.m_Field;                 
    m_ChannelNum                    =bean.m_ChannelNum;        
    m_SubProjectName                =bean.m_SubProjectName;    
    m_SubProjectNum                 =bean.m_SubProjectNum;     
    m_Enable                        =bean.m_Enable;            
    m_RangeLV                       =bean.m_RangeLV;           
    m_RangeHV                       =bean.m_RangeHV;           
    m_AlarmHV                       =bean.m_AlarmHV;           
    m_AlarmHHV                      =bean.m_AlarmHHV;          
    m_AlarmLV                       =bean.m_AlarmLV;           
    m_AlarmLLV                      =bean.m_AlarmLLV;          
    m_H_Alarm_RelatedTo             =bean.m_H_Alarm_RelatedTo; 
    m_HH_Alarm_RelatedTo            =bean.m_HH_Alarm_RelatedTo;
    m_L_Alarm_RelatedTo             =bean.m_L_Alarm_RelatedTo; 
    m_LL_Alarm_RelatedTo            =bean.m_LL_Alarm_RelatedTo;
                                     
}

QStringList &AI_Information_Bean::ToQstringlist()
{

    m_Stringlist.clear();
    m_Stringlist.append(m_Field);
    m_Stringlist.append(QString::number(m_ChannelNum,10));
    m_Stringlist.append(QString::number(m_SubProjectName,10));
    m_Stringlist.append(QString::number(m_SubProjectNum,10));
    m_Stringlist.append(QString::number(m_Enable,10));
    m_Stringlist.append(QString::number(m_RangeLV));
    m_Stringlist.append(QString::number(m_RangeHV) );
    m_Stringlist.append(QString::number(m_AlarmHV));
    m_Stringlist.append(QString::number(m_AlarmHHV));
    m_Stringlist.append(QString::number(m_AlarmLV) );
    m_Stringlist.append(QString::number(m_AlarmLLV));
    m_Stringlist.append(QString::number(m_H_Alarm_RelatedTo,10));
    m_Stringlist.append(QString::number(m_HH_Alarm_RelatedTo,10));
    m_Stringlist.append(QString::number(m_L_Alarm_RelatedTo,10));
    m_Stringlist.append(QString::number(m_LL_Alarm_RelatedTo,10));
    
    return this->m_Stringlist;
}
