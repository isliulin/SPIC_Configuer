#include "convert.h"

Convert::Convert()
{

}

word Convert::BcdToInt(byte *bTemp, byte Len)
{
    qint16 tInt = 0;
    byte i;

    for (i = 0; i < Len; i++)
    {	tInt *=	10;
        tInt +=	(bTemp[i] >> 4) ;
        tInt *=	10;
        tInt +=	(bTemp[i] & 0x0f);
    }
    return( tInt );

}

void Convert::IntToBcd(word iTemp, byte *bTemp, byte Len)
{
    qint16		tInt=0;
    int i;

    for (i = Len; i > 0; i--)
    {
        tInt		=	iTemp % 10;
        bTemp[i-1]	=	tInt;
        iTemp		-=	tInt;
        iTemp		/=	10;
        tInt		=	iTemp % 10;
        bTemp[i-1]	|=	(tInt << 4);
        iTemp		-=	tInt;
        iTemp		/=	10;
    }

}


