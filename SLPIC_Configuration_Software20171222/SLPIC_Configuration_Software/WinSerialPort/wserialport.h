#ifndef WSERIALPORT_H
#define WSERIALPORT_H
#include <windows.h>
#include <QString>
class WSerialport
{
public:
    WSerialport();
    WSerialport(LPCTSTR  port,DWORD baudRate, BYTE parity,BYTE dataBits,BYTE stopBits );



    bool ComRead( LPBYTE buf, int &len);
    bool ComWrite( LPBYTE buf, int &len);

    bool OpenCOM();
    bool CloseCOM();
    DWORD GetLastErrors();

    bool isOpen();

    DWORD m_BaudRate;//9600
    BYTE m_StopBits;//1
    BYTE m_DataBits;//ByteSize:数据位  8
    BYTE m_Parity;//n
    LPCTSTR  m_Port;


    //eg.读10个数据，读总超时＝ReadTotalTimeoutMultiplier×10＋ReadTotalTimeoutConstant
    DWORD m_ReadIntervalTimeout; //读间隔超时
    DWORD m_ReadTotalTimeoutMultiplier; //读时间系数=0,因为读数据个数较多，不设此参数
    DWORD m_ReadTotalTimeoutConstant; //读时间常量
    DWORD m_WriteTotalTimeoutMultiplier; // 写时间系数
    DWORD m_WriteTotalTimeoutConstant; //写时间常量

private:

    //9600,n,8,1
    HANDLE m_Hcom;//串口句柄示例
    //HANDLE InitCOM();
    bool m_bIsOpen;


};

#endif // WSERIALPORT_H
