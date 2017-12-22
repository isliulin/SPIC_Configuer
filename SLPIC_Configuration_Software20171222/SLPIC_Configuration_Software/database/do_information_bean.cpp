#include "do_information_bean.h"

DO_Information_Bean::DO_Information_Bean()
{
    m_Field="";
    m_ChannelNum=0;
    m_SubProjectName=0;
    m_SubProjectNum=0;
    m_Enable=0;

}

DO_Information_Bean::DO_Information_Bean(const DO_Information_Bean &bean)
{
    m_Field=bean.m_Field;
    m_ChannelNum=bean.m_ChannelNum;
    m_SubProjectName=bean.m_SubProjectName;
    m_SubProjectNum=bean.m_SubProjectNum;
    m_Enable=bean.m_Enable;

}

QStringList &DO_Information_Bean::ToQstringlist()
{

    m_Stringlist.clear();
    m_Stringlist.append(m_Field);
    m_Stringlist.append(QString::number(m_ChannelNum,10));
    m_Stringlist.append(QString::number(m_SubProjectName,10));
    m_Stringlist.append(QString::number(m_SubProjectNum,10));
    m_Stringlist.append(QString::number(m_Enable,10));
    return this->m_Stringlist;

}
