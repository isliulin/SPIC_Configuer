#include "wserialport.h"

WSerialport::WSerialport()
{

    m_ReadIntervalTimeout = 20;
    //5000
    m_ReadTotalTimeoutConstant = 2000;
    m_ReadTotalTimeoutMultiplier = 0;

    m_WriteTotalTimeoutMultiplier = 500;
    m_WriteTotalTimeoutConstant = 5000;

}

WSerialport::WSerialport(LPCTSTR  port,DWORD baudRate=CBR_9600, BYTE parity=NOPARITY, BYTE dataBits=8, BYTE stopBits=ONESTOPBIT)
{

    m_bIsOpen=false;
    m_BaudRate=baudRate;//9600
    m_StopBits=stopBits;//1
    m_DataBits=dataBits;//ByteSize:数据位  8
    m_Parity=parity;//n
    m_Port=port;
    m_ReadIntervalTimeout = 20;
    //5000
    m_ReadTotalTimeoutConstant = 2000;
    m_ReadTotalTimeoutMultiplier = 0;

    m_WriteTotalTimeoutMultiplier = 500;
    m_WriteTotalTimeoutConstant = 5000;

}

bool WSerialport::ComRead(LPBYTE buf, int &len)
{
    DWORD ReadSize = 0;
    BOOL res=FALSE;
    BOOL rtn = FALSE;

    //设置读取1个字节数据，当缓存中有数据到达时则会立即返回，否则直到超时
    rtn = ReadFile(m_Hcom, buf, 1024, &ReadSize, NULL);

    if(!rtn)
    {
        res=FALSE;
    }
    else {
        if (ReadSize>0)
        {
            res=TRUE;
            len=ReadSize;

        }
    }

    return res;


}

bool WSerialport::ComWrite(LPBYTE buf, int &len)
{
    PurgeComm(m_Hcom, PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR|PURGE_TXABORT);
    BOOL rtn = FALSE;
    DWORD WriteSize = 0;
    rtn = WriteFile(m_Hcom, buf, len, &WriteSize, NULL);

    len = WriteSize;
    return rtn != FALSE;

}

bool WSerialport::OpenCOM()
{
    BOOL res=FALSE;
    m_Hcom = INVALID_HANDLE_VALUE;
    m_Hcom = CreateFile(m_Port, GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING,
                      0/*同步方式打开串口*/, NULL);
    if (INVALID_HANDLE_VALUE == m_Hcom)
    {
        res=FALSE;
        //m_bIsOpen=false;
        return FALSE;
    }
    else {
        res=TRUE;
        m_bIsOpen=true;
    }

    SetupComm(m_Hcom, 4096, 4096);//设置缓存
    DCB dcb;
    GetCommState(m_Hcom, &dcb);//设置串口
    dcb.DCBlength = sizeof(dcb);
    //BAUD_9600
    dcb.BaudRate = m_BaudRate;
    dcb.StopBits = m_StopBits;
    dcb.Parity=m_Parity;
    dcb.ByteSize=m_DataBits;

    SetCommState(m_Hcom, &dcb);

    PurgeComm(m_Hcom, PURGE_RXABORT|PURGE_TXCLEAR|PURGE_RXCLEAR|PURGE_TXABORT);//清空缓存

    COMMTIMEOUTS ct;
    //设置读取超时时间，及ReadFlie最长等待时间

    ct.ReadIntervalTimeout = m_ReadIntervalTimeout;
    //5000
    ct.ReadTotalTimeoutConstant = m_ReadTotalTimeoutConstant;
    ct.ReadTotalTimeoutMultiplier = m_ReadTotalTimeoutMultiplier;

    ct.WriteTotalTimeoutMultiplier = m_WriteTotalTimeoutMultiplier;
    ct.WriteTotalTimeoutConstant = m_WriteTotalTimeoutConstant;

    SetCommTimeouts(m_Hcom, &ct);//设置超时
    return res;

}

bool WSerialport::CloseCOM()
{
    if(CloseHandle(m_Hcom))
    {
        m_bIsOpen=false;
        return TRUE;
    }
    else
    {
        return FALSE;
    }
}

DWORD WSerialport::GetLastErrors()
{
    return GetLastError();

}

bool WSerialport::isOpen()
{
    return m_bIsOpen;

}




