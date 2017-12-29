#include "datapackettosend.h"


//byte DataPacketToSend::Frame=1;

DataPacketToSend::DataPacketToSend()
{

}


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
DataPacketToSend::DataPacketToSend(OperatorMode mode)
    :  m_STX(0x02),m_SlaveAddress(0x01),m_OperatorMode(mode)
    ,m_ContentLength(0),m_ProjectName(0),m_ChannelNum(0),m_SubProjectName(0)
    ,m_SubProjectNum(0),m_ETX(0x03)

{
//    this->AddFrameNum(Frame);

    //AddFrameNum(Frame);
}

void DataPacketToSend::setFrame(const byte &Frame)
{
    m_Frame = Frame;
    m_Packet[3]=m_Frame;


}



//void DataPacketToSend::AddFrameNum(byte &frame)
//{
//    frame++;
//    if(frame==0)
//      {
//         frame=1;
//      }
//      m_Frame=frame;

//}



QByteArray& DataPacketToSend::Packet()
{
    return m_Packet;
}



QByteArray &DataPacketToSend::AssembleReadPacket(const DataPacketToSend::StandPacketRelevant &standPacketRelevant)
{
    //m_Packet.clear();
    m_ProjectName=standPacketRelevant.m_ProjectName;
    m_ChannelNum=standPacketRelevant.m_ChannelNum;


    /*标准包头*/
    m_Packet.append(m_STX);
    m_Packet.append(m_SlaveAddress);
    m_Packet.append(m_OperatorMode);
    m_Packet.append(m_Frame);
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
    m_Packet.append(lrc);
//    byte lrc=m_Packet.at(0);
//    /*校验*/
//    for(int i=1;i<m_Packet.count();i++)
//    {
//        lrc =lrc^m_Packet.at(i);

//    }
//    m_Packet.append(lrc);


    return m_Packet;


}

QByteArray &DataPacketToSend::AssembleWritePacket(const DataPacketToSend::StandPacketRelevant &standPacketRelevant)
{

    //m_Packet.clear();

    m_ProjectName=standPacketRelevant.m_ProjectName;
    m_ChannelNum=standPacketRelevant.m_ChannelNum;
    m_SubProjectName=standPacketRelevant.m_SubProjectName;
    m_SubProjectNum=standPacketRelevant.m_SubProjectNum;


    /*标准包头*/
    m_Packet.append(m_STX);
    m_Packet.append(m_SlaveAddress);
    m_Packet.append(m_OperatorMode);
    m_Packet.append(m_Frame);
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
//    byte lrc=m_Packet.at(0);
//    /*校验*/
//    for(int i=1;i<m_Packet.count();i++)
//    {
//        lrc =lrc^m_Packet.at(i);

//    }
    //放到发送前做异或
    m_Packet.append(lrc);

    return m_Packet;
}



QByteArray& DataPacketToSend::AssemblePacket( const DataPacketToSend::StandPacketRelevant &standPacketRelevant)
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
