#ifndef DATAPACKETRECIEVE_H
#define DATAPACKETRECIEVE_H



#include <QtCore>
#include <QList>
class DataPacketRecieve
{
    enum ProjectName
    {
        AnalogueInput=0x01,
        DigitalInput=0x02,
        DigitalOutputs=0x03,
        SerialPortConfiguration=0x04,
        OherConfiguration=0x05
    };
    enum PtType
    {
        BYTE=0,
        QUINT32=1,
        FLOAT=2,
        STRING=3,
        UINT64=4
    };



    struct Point
    {

        //Ttitle_Length_Value_field_type


        quint8 Ttitle;
        quint8 Length;
        QVariant Value;
        QString Field;
        PtType Type;
        Point() {}
    };

public:

    DataPacketRecieve();
public:
    quint8 m_ProjectName;//项目名(e.g.:AI模拟量输入)
    quint8 m_ChannelNum;//通道号
    quint8 m_SubProjectName;//分项名
    quint8 m_SubProjectNum;//分享编号
    QList<Point> m_Poites;//所有值放到list里

};

#endif // DATAPACKETRECIEVE_H
