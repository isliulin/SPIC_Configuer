#ifndef AI_PACKET_H
#define AI_PACKET_H

#include <QObject>
#include <QCheckBox>
#include <QList>
#include <data_packegt/datapacketinferface.h>

class AI_Packet : public DataPacketInferface
{

public:



    explicit AI_Packet(OperatorMode mode);


protected:
    virtual QByteArray& AssembleReadPacket(const StandPacketRelevant &standPacketRelevant);//组读数据的包
    virtual QByteArray& AssembleWritePacket( const StandPacketRelevant &standPacketRelevant);//组写数据库的包



};

#endif // AI_PACKET_H
