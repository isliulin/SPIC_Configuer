#ifndef AI_INFORMATION_BEAN_H
#define AI_INFORMATION_BEAN_H

#include <QObject>
#include <QString>
#include "common/commonhead.h"
#include <QStringList>
class AI_Information_Bean
{

public:
    AI_Information_Bean();
    AI_Information_Bean(const AI_Information_Bean& bean);
    QString  m_Field;
    byte m_ChannelNum;
    byte m_SubProjectName;
    byte m_SubProjectNum;
    byte m_Enable;
    float m_RangeLV;
    float m_RangeHV;
    float m_AlarmHV;
    float m_AlarmHHV;
    float m_AlarmLV;
    float m_AlarmLLV;
    dword m_H_Alarm_RelatedTo;
    dword m_HH_Alarm_RelatedTo;
    dword m_L_Alarm_RelatedTo;
    dword m_LL_Alarm_RelatedTo;

    QStringList m_Stringlist;

    QStringList & ToQstringlist();



};

#endif // AI_INFORMATION_BEAN_H
