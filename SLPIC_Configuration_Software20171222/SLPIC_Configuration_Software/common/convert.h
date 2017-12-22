#ifndef CONVERT_H
#define CONVERT_H

#include "common/commonhead.h"
#include <QtCore>
class Convert
{
public:
    Convert();

    static word BcdToInt( byte* bTemp, byte Len);
    static void IntToBcd( word iTemp, byte* bTemp,byte Len );
};



#endif // CONVERT_H
