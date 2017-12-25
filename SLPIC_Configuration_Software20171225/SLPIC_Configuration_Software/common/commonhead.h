#ifndef COMMONHEAD_H
#define COMMONHEAD_H
#include <QtCore>
typedef  unsigned char byte;
typedef unsigned int dword;
typedef unsigned short word;

enum DataBaseOperator{
    insert=0,
    update=1,
    slice_off=2,
    query=3
};

enum EditAttribute{
    InsertEdit=0,
    updateEdit=1

};

enum EditPageNum{
    AI_Page=0,
    DI_Page=1,
    DO_Page=2,
    SerialPortPage=3,
    Other_Page=4

};
#endif // COMMONHEAD_H
