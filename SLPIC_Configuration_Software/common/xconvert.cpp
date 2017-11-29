#include "xconvert.h"

Xconvert::Xconvert()
{


}

int Xconvert::convert(quint8 *dst, const quint8 *src, int length)
{
    int i;

    for(i=0; i<length; i++)
    {
        dst[i] = src[i]^0xFF;
    }
    return 0;

}
quint32  Xconvert::HextoDec(const quint8 *hex, int length)
{
    int i;
    quint32 rslt = 0;

    for(i=0; i<length; i++)
    {
        rslt += (quint32)(hex[i])<<(8*(length-1-i));

    }

    return rslt;
}

int Xconvert::DectoHex(qint32 dec, quint8 *hex, int length)
{
    int i;

    for(i=length-1; i>=0; i--)
    {
        hex[i] = (dec%256)&0xFF;
        dec /= 256;
    }

    return 0;
}

quint32 Xconvert::power(int base, int times)
{
    int i;
    unsigned long rslt = 1;

    for(i=0; i<times; i++)
        rslt *= base;

    return rslt;
}

quint32 Xconvert::BCDtoDec(const quint8 *bcd, int length)
{
    int i, tmp;
    quint32 dec = 0;

    for(i=0; i<length; i++)
    {
        tmp = ((bcd[i]>>4)&0x0F)*10 + (bcd[i]&0x0F);
        dec += tmp * power(100, length-1-i);
    }

    return dec;

}

int Xconvert::DectoBCD(qint32 Dec, quint8 *Bcd, int length)
{
    int i;
    int temp;

    for(i=length-1; i>=0; i--)
    {
        temp = Dec%100;
        Bcd[i] = ((temp/10)<<4) + ((temp%10) & 0x0F);
        Dec /= 100;
    }

    return 0;

}

quint8 Xconvert::BCDtoDec(quint8 temp)
{
    return ( ( temp/16 )*10+temp%16);
}

quint8 Xconvert::DectoBCD(quint8 temp)
{
    return ( (temp/10)*16 + temp%10 );
}
void Xconvert::floatToBytes(float f,quint8* pArray)
{
    float a=f;

    memcpy(pArray,&a,4);
}

void Xconvert::InsertFloatToList(float f,  QList<quint8>& list)
{
    list.clear();
    quint8 array[4];
    floatToBytes(f,array);
    for(int i=0;i<4;i++)
    {
        list.append(array[i]);
    }

}

void Xconvert::InsertQuint32ToList(quint32 i, QList<quint8>& list)
{
    quint32 a=i;
    list.clear();
    quint8 array[4];
    memcpy(array,&a,4);
    for(int i=0;i<4;i++)
    {
        list.append(array[i]);
    }

}

void Xconvert::InsertFloatToList(float f,QByteArray &list)
{
    float a=f;

    list.clear();
    quint8 array[4];
    memcpy(array,&a,4);
    for(int i=3;i>=0;i--)
    {
        list.append(array[i]);
    }


}



void Xconvert::InsertQuint32ToList(quint32 i,QByteArray &list)
{
    quint32 a=i;

    list.clear();
    quint8 array[4];
    memcpy(array,&a,4);
    for(int i=3;i>=0;i--)
    {
        list.append(array[i]);
    }
}




