#include "datapacketinferface.h"

byte DataPacketInferface::Frame=1;


/*
    byte m_STX;
    byte m_SlaveAddress;
    byte m_OperatorMode;//读或者写
    byte m_Frame; //帧
    qint16 m_ContentLength;//内从长度
    byte m_ProjectName;//项目名(e.g.:AI模拟量输入)
    byte m_ChannelNum;//通道号
    byte m_SubProjectName;//分项名
    byte m_SubProjectNum;//分享编号
    byte m_ValuesNum;//值长度

*/
DataPacketInferface::DataPacketInferface(OperatorMode mode)
    :  m_STX(0x02),m_SlaveAddress(0x01),m_OperatorMode(mode)
    ,m_ContentLength(0),m_ProjectName(0),m_ChannelNum(0),m_SubProjectName(0)
    ,m_SubProjectNum(0),m_ETX(0x03)

{

    AddFrameNum(Frame);
}

QByteArray& DataPacketInferface::Packet()
{
    return m_Packet;
}

void DataPacketInferface::AddFrameNum( byte &frame)
{
    frame++;
    if(frame==0)
    {
       frame=1;
    }
    m_Frame=frame;

}



QByteArray& DataPacketInferface::AssemblePacket( const StandPacketRelevant &standPacketRelevant)
{

    m_Packet.clear();
    switch (m_OperatorMode) {
    case read:
        m_Packet=this->AssembleReadPacket(standPacketRelevant);
        break;
    case write:
        m_Packet=this->AssembleWritePacket(standPacketRelevant);
        break;
    default:
        break;
    }
    return m_Packet;

}


