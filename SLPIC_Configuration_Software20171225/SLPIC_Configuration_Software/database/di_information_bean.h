#ifndef DI_INFORMATION_BEAN_H
#define DI_INFORMATION_BEAN_H

#include <QObject>
#include <QString>
#include "common/commonhead.h"
#include <QStringList>
class DI_Information_Bean
{
public:
    DI_Information_Bean();
    DI_Information_Bean(const DI_Information_Bean& bean);
    QString  m_Field;
    byte m_ChannelNum;
    byte m_SubProjectName;
    byte m_SubProjectNum;
    byte m_Enable;

    dword m_DI_Alarm_RelatedTo;


    QStringList m_Stringlist;

    QStringList & ToQstringlist();
};

#endif // DI_INFORMATION_BEAN_H
