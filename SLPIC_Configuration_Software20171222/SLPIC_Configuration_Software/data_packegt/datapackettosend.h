#ifndef DATAPACKETTOSEND_H
#define DATAPACKETTOSEND_H

#include <QtCore>
#include "common/convert.h"

class DataPacketToSend
{


public:
    enum OperatorMode{
        read=0x01,
        write=0x02
    };
    //标准数据包相关数据：一般从ui上获取
    class StandPacketRelevant
    {
    public:
        StandPacketRelevant() {
             m_ProjectName=0;//项目名(e.g.:AI模拟量输入)
             m_ChannelNum=0;//通道号
             m_SubProjectName=0;//分项名
             m_SubProjectNum=0;//分享编号

        }

    public:
        byte m_ProjectName;//项目名(e.g.:AI模拟量输入)
        byte m_ChannelNum;//通道号
        byte m_SubProjectName;//分项名
        byte m_SubProjectNum;//分享编号
        QByteArray m_ValuePacket;



    };

     DataPacketToSend();
     DataPacketToSend(OperatorMode mode);

public:
      QByteArray m_Packet;//AssemblePacket()函数处理后的数据包



protected:
    byte m_STX;
    byte m_SlaveAddress;
    byte m_OperatorMode;//读或者写
    byte m_Frame; //帧
    word m_ContentLength;//内从长度
    byte m_ProjectName;//项目名(e.g.:AI模拟量输入)
    byte m_ChannelNum;//通道号
    byte m_SubProjectName;//分项名
    byte m_SubProjectNum;//分享编号
    byte m_ValuesNum;//值长度

    //QByteArray m_ValuePacket;//值内容的数组
    byte m_ETX;
//    static byte Frame;//全局的供类排成的所有对象使用

protected:

//     void AddFrameNum( byte &frame);

      QByteArray& AssembleReadPacket( const StandPacketRelevant &standPacketRelevant);//组读数据的包
      QByteArray& AssembleWritePacket( const StandPacketRelevant &standPacketRelevant);//组写数据库的包


public :
     QByteArray& AssemblePacket( const StandPacketRelevant &standPacketRelevant);//把所有内容组合成数据包下至到下位机


     QByteArray& Packet();
     //QByteArray ValuePacket() const;
     void setFrame(const byte &Frame);
};

#endif // DATAPACKETTOSEND_H
