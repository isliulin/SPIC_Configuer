#ifndef DATABASEITEMFORPACKET_H
#define DATABASEITEMFORPACKET_H


/**
* @brief 数据库内包含：
*                    1.channelNum(通道号):1b
*                    2.SubProjectName(分项名):1b
*                    3.SubProjectNum(分项编号):1b
*                    4.TLV list
*
*
*
* @author xiaoyao
* @date 2017/11/21
*/
class DataBaseItemForPacket
{
public:
    DataBaseItemForPacket();
    quint8 m_ChannelNum;
    quint8 m_SubProjectName;
    quint8 m_SubProjectNum;
    QByteArray m_Value;

};

#endif // DATABASEITEMFORPACKET_H
