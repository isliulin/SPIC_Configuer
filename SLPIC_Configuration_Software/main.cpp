#include "mainwindow.h"
#include <QApplication>

#include "data_packegt/ai_packet.h"
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
//    AI_Packet ai1(DataPacketInferface::write);
//    AI_Packet::StandPacketRelevant standPacketRelevant;
//    standPacketRelevant.m_ChannelNum=0x01;
//    standPacketRelevant.m_ProjectName=0x02;
//    standPacketRelevant.m_SubProjectName=0x03;
//    standPacketRelevant.m_SubProjectNum=0x04;
//    standPacketRelevant.m_ValuePacket.append(0x0a);
//    standPacketRelevant.m_ValuePacket.append(0x0b);
//    ai1.AssemblePacket(standPacketRelevant);

    return a.exec();
}
