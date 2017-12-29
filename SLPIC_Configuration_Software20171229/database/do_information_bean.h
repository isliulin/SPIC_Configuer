#ifndef DO_INFORMATION_BEAN_H
#define DO_INFORMATION_BEAN_H


#include <QObject>
#include <QString>
#include "common/commonhead.h"
#include <QStringList>


class DO_Information_Bean
{
public:
    DO_Information_Bean();
    DO_Information_Bean(const DO_Information_Bean& bean);
    QString  m_Field;
    byte m_ChannelNum;
    byte m_SubProjectName;
    byte m_SubProjectNum;
    byte m_Enable;
    QStringList m_Stringlist;

    QStringList & ToQstringlist();
};

#endif // DO_INFORMATION_BEAN_H
