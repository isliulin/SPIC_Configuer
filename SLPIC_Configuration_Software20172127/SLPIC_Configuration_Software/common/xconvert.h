#ifndef XCONVERT_H
#define XCONVERT_H

#include<QtCore>
#include <QByteArray>
class Xconvert
{
public:
    Xconvert();

/**
* @brief 二进制取反
* @param src:二进制数据
* @param length:待转换的二进制数据长度
* @param dst:取反后的二进制数据
* @return 返回0表示成功
* @author xiaoyao
* @date 2017/11/21
*/
    static int convert(quint8 *dst, const quint8 *src, int length);

    /**
* @brief 十六进制转为十进制
* @param hex:待转换的十六进制数据
* @param length: 十六进制数据长度
* @return 转换后的十进制数据
* @author xiaoyao
* @date 2017/11/21
*/
    static quint32 HextoDec(const quint8 *hex, int length);


    /**
* @brief 摘要
* @param dec:待转换的十进制数据
* @param length:转换后的十六进制数据长度
* @param hex: 转换后的十六进制数据
* @return 0:表示成功
* @author xiaoyao
* @date 2017/11/21
*/
    static int DectoHex(qint32 dec, quint8 *hex, int length);

    /**
* @brief 摘要
* @param base:进制基数
* @param times:权级数
* @return 当前数据位的权
* @author xiaoyao
* @date 2017/11/21
*/
   static quint32 power(int base, int times);

    /**
* @brief 摘要
* @param bcd:待转换的 BCD 码
* @param length:BCD 码数据长度
* @return 当前数据位的权
* @author xiaoyao
* @date 2017/11/21
*/
    static quint32 BCDtoDec(const quint8 *bcd, int length);


    /**
* @brief 摘要
* @param Dec: 待转换的十进制数据
* @param length: BCD 码数据长度
* @param Bcd:转换后的 BCD 码
* @return 0:成功
* @author xiaoyao
* @date 2017/11/21
*/
    static int DectoBCD(qint32 Dec, quint8 *Bcd, int length);


    /**
* @brief 摘要
* @param temp: 转化的 BCD 码
* @return 转化后的十进制码
* @author xiaoyao
* @date 2017/11/21
*/
    static quint8  BCDtoDec( quint8 temp );


    /**
* @brief 摘要
* @param temp: 转化的十进制码
* @return 转化后的 BCD 码
* @author xiaoyao
* @date 2017/11/21
*/
    static quint8 DectoBCD( quint8 temp);


    //float to bytes:4b
    static void floatToBytes(float f,quint8* pArray);

    //insert float to List:4b
    static void InsertFloatToList(float f,QList<quint8> &list);
    static void InsertFloatToList(float f,QByteArray &list);


    //insert quint32 to List:4b
    static void InsertQuint32ToList(quint32 i,QList<quint8> &list);
    static void InsertQuint32ToList(quint32 i,QByteArray &list);

    //insert qulonglong to list:7b
    static void InsertQulonglongTOList(qulonglong i,QByteArray &list);

    //insert quint16 to list:2b
    static void InsertQuint16TOList(quint16 i,QByteArray &list);
    //异或
    static void LRC(QByteArray &packet);





};

#endif // XCONVERT_H
