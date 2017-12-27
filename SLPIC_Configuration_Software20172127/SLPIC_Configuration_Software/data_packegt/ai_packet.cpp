#include "ai_packet.h"
#include "common/convert.h"


AI_Packet::AI_Packet(OperatorMode mode):DataPacketInferface(mode)
{


}



QByteArray& AI_Packet::AssembleReadPacket(const StandPacketRelevant &standPacketRelevant)
{
    m_Packet.clear();
    m_ProjectName=standPacketRelevant.m_ProjectName;
    m_ChannelNum=standPacketRelevant.m_ChannelNum;

    /*标准包头*/
    m_Packet.append(m_STX);
    m_Packet.append(m_SlaveAddress);
    m_Packet.append(m_OperatorMode);
    //内容长度=项目名长度(1Byte)+项目通道长度(1Byte)+分项名长度(1Byte)+分项编号长度+值长度（1Byte）
    m_ContentLength=3+standPacketRelevant.m_ValuePacket.count();
    byte bytesOfContentLength[2];
    Convert::IntToBcd(m_ContentLength,bytesOfContentLength,sizeof(bytesOfContentLength)/1);
    m_Packet.append((char*)bytesOfContentLength,sizeof(bytesOfContentLength)/1);
    m_Packet.append(this->m_ProjectName);
    m_Packet.append(this->m_ChannelNum);
//    m_Packet.append(this->m_SubProjectName);
//    m_Packet.append(this->m_SubProjectNum);

    m_ValuesNum=standPacketRelevant.m_ValuePacket.count();
    m_Packet.append(m_ValuesNum);
    m_Packet.append(standPacketRelevant.m_ValuePacket);
    m_Packet.append(m_ETX);


    byte lrc=0;
    /*校验*/
    for(int i=0;i<m_Packet.count();i++)
    {
        lrc ^=m_Packet.at(i);

    }
    m_Packet.append(lrc);

    return m_Packet;



}

QByteArray& AI_Packet::AssembleWritePacket(const StandPacketRelevant &standPacketRelevant)
{
    m_Packet.clear();

    m_ProjectName=standPacketRelevant.m_ProjectName;
    m_ChannelNum=standPacketRelevant.m_ChannelNum;
    m_SubProjectName=standPacketRelevant.m_SubProjectName;
    m_SubProjectNum=standPacketRelevant.m_SubProjectNum;


    /*标准包头*/
    m_Packet.append(m_STX);
    m_Packet.append(m_SlaveAddress);
    m_Packet.append(m_OperatorMode);
    //内容长度=项目名长度(1Byte)+项目通道长度(1Byte)+分项名长度(1Byte)+分项编号长度+值长度（1Byte）
    m_ContentLength=5+standPacketRelevant.m_ValuePacket.count();
    byte bytesOfContentLength[2];
    Convert::IntToBcd(m_ContentLength,bytesOfContentLength,sizeof(bytesOfContentLength)/1);
    m_Packet.append((char*)bytesOfContentLength,sizeof(bytesOfContentLength)/1);
    m_Packet.append(this->m_ProjectName);
    m_Packet.append(this->m_ChannelNum);
    m_Packet.append(this->m_SubProjectName);
    m_Packet.append(this->m_SubProjectNum);

    m_ValuesNum=standPacketRelevant.m_ValuePacket.count();
    m_Packet.append(m_ValuesNum);
    m_Packet.append(standPacketRelevant.m_ValuePacket);
    m_Packet.append(m_ETX);


    byte lrc=0;
    /*校验*/
    for(int i=0;i<m_Packet.count();i++)
    {
        lrc ^=m_Packet.at(i);

    }
    m_Packet.append(lrc);

    return m_Packet;

}




