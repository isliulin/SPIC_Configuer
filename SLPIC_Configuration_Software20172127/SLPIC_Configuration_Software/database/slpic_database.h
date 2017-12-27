#ifndef SLPIC_DATABASE_H
#define SLPIC_DATABASE_H

#include <QObject>
#include <QString>
#include <QMainWindow>
#include <QSqlDatabase>
#include <QSqlError>
#include <QSqlQuery>
#include <QDebug>
#include "database/ai_information_bean.h"
#include "database/di_information_bean.h"
#include "database/do_information_bean.h"
#include "database/serialport_information_bean.h"
#include "database/other_information_bean.h"
#include <QSqlQueryModel>
#include <QSqlTableModel>
#include "data_packegt/datapackettosend.h"
#include "common/xconvert.h"

//typedef DataPacketInferface::StandPacketRelevant DataBaseItem;

class SLPIC_DataBase : public QObject
{
    Q_OBJECT
public:

    explicit SLPIC_DataBase(QObject *parent = 0);
    SLPIC_DataBase(QString filePath);
private:
    QSqlDatabase database;
signals:
public:
    bool CreateDB(const QString &filePath);
    QString LastError() const;
    void setLastError(const QString &LastError);
    bool Open(const QString &filePath);
    bool Open();

    //bool UpadateAI_Table(const QString &filePath,const QList<AI_Information> inforlist);
    //add
    //delete
    //modify
    //select
    QList<AI_Information_Bean> m_AiInforList;
    QList<DI_Information_Bean> m_DiInforList;
    QList<DO_Information_Bean> m_DoInforList;
    QList<SerialPort_Information_Bean> m_SerialPortInforList;
    QList<Other_Information_Bean> m_OtherInforList;

    /************表AI的增删改查*************************************************/
    bool GetAiTableInfo();
    int GetAiTableInfo(QString filter);
    bool DeleteInfoFromAiTable(const AI_Information_Bean &bean);
    bool InsertInfoToAiTable(const AI_Information_Bean &bean );
    bool InsertInfoToAiTable(const QList<AI_Information_Bean> &InforList);
    bool UpdateInfoToAiTable(const AI_Information_Bean &bean);
    /*******************************************************************/



    /************表DI的增删改查*************************************************/
    bool GetDiTableInfo();
    int GetDiTableInfo(QString filter);
    bool DeleteInfoFromDiTable(const DI_Information_Bean &bean);
    bool InsertInfoToDiTable(const DI_Information_Bean &bean );
    bool InsertInfoToDiTable(const QList<DI_Information_Bean> &InforList);
    bool UpdateInfoToDiTable(const DI_Information_Bean &bean);
    /*******************************************************************/

    /************表DO的增删改查*************************************************/
    bool GetDoTableInfo();
    int GetDoTableInfo(QString filter);
    bool DeleteInfoFromDoTable(const DO_Information_Bean &bean);
    bool InsertInfoToDoTable(const DO_Information_Bean &bean );
    bool InsertInfoToDoTable(const QList<DO_Information_Bean> &InforList);
    bool UpdateInfoToDoTable(const DO_Information_Bean &bean);
    /*******************************************************************/


    /************表serialPort的增删改查*************************************************/
    bool GetSerialPortTableInfo();
    int GetSerialPortTableInfo(QString filter);
    bool DeleteInfoFromSerialPortTable(const SerialPort_Information_Bean &bean);
    bool InsertInfoToSerialPortTable(const SerialPort_Information_Bean &bean );
    bool InsertInfoToSerialPortTable(const QList<SerialPort_Information_Bean> &InforList);
    bool UpdateInfoToSerialPortTable(const SerialPort_Information_Bean &bean);
    /*******************************************************************/

    /************表other的增删改查*************************************************/
    bool GetOtherTableInfo();
    int GetOtherTableInfo(QString filter);
    bool DeleteInfoFromOtherTable(const Other_Information_Bean &bean);
    bool InsertInfoToOtherTable(const Other_Information_Bean &bean );
    bool InsertInfoToOtherTable(const QList<Other_Information_Bean> &InforList);
    bool UpdateInfoToOtherTable(const Other_Information_Bean &bean);
    /*******************************************************************/



    QString filePath() const;
    void setFilePath(const QString &filePath);

    /**
* @brief 从数据库中获取AI信息并转成 QList<quint8>：m_standPacketItems_AI
* @param operateMode:read or write
* @return 数据库操作是否成功
* @author xiaoyao
* @date 2017/11/21
*/
    bool getAIStandPacketItems(DataPacketToSend::OperatorMode operateMode);

    bool getDIStandPacketItems(DataPacketToSend::OperatorMode operateMode);

    bool getDOStandPacketItems(DataPacketToSend::OperatorMode operateMode);

    bool getSPStandPacketItems(DataPacketToSend::OperatorMode operateMode);

    bool getOtherStandPacketItems(DataPacketToSend::OperatorMode operateMode);

private:
    QString m_LastError;
    QString m_filePath;
public:
    QList<DataPacketToSend::StandPacketRelevant> m_standPacketItems_AI;
    QList<DataPacketToSend::StandPacketRelevant> m_standPacketItems_DI;
    QList<DataPacketToSend::StandPacketRelevant> m_standPacketItems_DO;
    QList<DataPacketToSend::StandPacketRelevant> m_standPacketItems_SerialPort;
    QList<DataPacketToSend::StandPacketRelevant> m_standPacketItems_Other;


    QSqlDatabase getDatabase() const;

public slots:
};

#endif // SLPIC_DATABASE_H
