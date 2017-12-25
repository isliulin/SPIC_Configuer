#include "slpic_database.h"
#include <QSqlRecord>
SLPIC_DataBase::SLPIC_DataBase(QObject *parent) : QObject(parent)
{

}

SLPIC_DataBase::SLPIC_DataBase(QString filePath)
{
    m_filePath=filePath;

}



bool SLPIC_DataBase::CreateDB(const QString &filePath)
{

    bool res=false;
    if(Open(filePath))
    {
        QSqlQuery sql_query;

        QString create_sql = "CREATE TABLE DI (Field VARCHAR, ChannelNum INT, SubProjectName INT, SubProjectNum INT, Enable INT, Alarm_RelatedTo INT)";



        if(!sql_query.exec(create_sql))
        {
            qDebug()<<sql_query.lastError();
            setLastError(sql_query.lastError().text());
            res=false;
            return res;
        }
        else
        {
            qDebug()<<"table DI created!";
            res=true;
        }


        create_sql = "CREATE TABLE SerialPort (Field VARCHAR, ChannelNum INT, SubProjectName INT, SubProjectNum INT, Enable INT, BaudRate INT, DataBit INT, Parity INT, StopBit INT, SlaveID INT, Manufacturer INT, Protocol INT)";

        if(!sql_query.exec(create_sql))
        {
            qDebug()<<sql_query.lastError();
            setLastError(sql_query.lastError().text());
            res=false;
            return res;
        }
        else
        {
            qDebug()<<"table SerialPort created!";
            res=true;
        }


        create_sql = "CREATE TABLE DO (Field VARCHAR, ChannelNum INT, SubProjectName INT, SubProjectNum INT, Enable INT)";

        if(!sql_query.exec(create_sql))
        {
            qDebug()<<sql_query.lastError();
            setLastError(sql_query.lastError().text());
            res=false;
            return res;
        }
        else
        {
            qDebug()<<"table DO created!";
            res=true;
        }

        create_sql = "CREATE TABLE AI (Field VARCHAR, ChannelNum INT, SubProjectName INT, SubProjectNum INT, Enable INT, RangeLV REAL, RangeHV REAL, AlarmHV REAL, AlarmHHV REAL, AlarmLV REAL, AlarmLLV REAL, H_Alarm_RelatedTo INT, HH_Alarm_RelatedTo INT, L_Alarm_RelatedTo INT, LL_Alarm_RelatedTo INT)";

        if(!sql_query.exec(create_sql))
        {
            qDebug()<<sql_query.lastError();
            setLastError(sql_query.lastError().text());
            res=false;
            return res;
        }
        else
        {
            qDebug()<<"table AI created!";
            res=true;
        }

        create_sql = "CREATE TABLE Other (Field VARCHAR, ChannelNum INT, SubProjectName INT, SubProjectNum INT, comm_protocol INT, comm_way INT, deviceID INTEGER, station_id INT, ip VARCHAR, port_num INT, retry_counter INT, retry_interval INT, heart_internal INT, rtc_timer INT, gprs_pass_mode INT, density REAL, sys_restart INT,last_volume real)";

        if(!sql_query.exec(create_sql))
        {
            qDebug()<<sql_query.lastError();
            setLastError(sql_query.lastError().text());
            res=false;
            return res;
        }
        else
        {
            qDebug()<<"table other created!";
            res=true;
        }


        m_filePath=filePath;
    }
    else {
        res=false;

    }
    return res;
}

QString SLPIC_DataBase::LastError() const
{
    return m_LastError;
}

void SLPIC_DataBase::setLastError(const QString &LastError)
{
    m_LastError = LastError;
}

bool SLPIC_DataBase::Open(const QString &filePath)
{
    bool res=true;

    m_filePath=filePath;
    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
        database.setDatabaseName(filePath);
    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(filePath);
//        database.setUserName("XingYeZhiXia");
//        database.setPassword("123456");
    }

    if (!database.open())
    {

        qDebug() << "Error: Failed to connect database." << database.lastError();
        setLastError(database.lastError().text());
        res=false;

    }

    return res;

}

bool SLPIC_DataBase::Open()
{
    bool res=true;

    if (QSqlDatabase::contains("qt_sql_default_connection"))
    {
        database = QSqlDatabase::database("qt_sql_default_connection");
        database.setDatabaseName(m_filePath);

    }
    else
    {
        database = QSqlDatabase::addDatabase("QSQLITE");
        database.setDatabaseName(m_filePath);

    }

    if (!database.open())
    {

        qDebug() << "Error: Failed to connect database." << database.lastError();
        setLastError(database.lastError().text());
        res=false;

    }

    return res;

}

bool SLPIC_DataBase::GetAiTableInfo()
{
    m_AiInforList.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM ai  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                AI_Information_Bean bean;
                bean.m_Field=query_select.value(0).toString();
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                bean.m_Enable=(byte)(query_select.value(4).toUInt());
                bean.m_RangeLV=(float)(query_select.value(5).toFloat());
                bean.m_RangeHV=(float)(query_select.value(6).toFloat());
                bean.m_AlarmHV=(float)(query_select.value(7).toFloat());
                bean.m_AlarmHHV=(float)(query_select.value(8).toFloat());
                bean.m_AlarmLV=(float)(query_select.value(9).toFloat());
                bean.m_AlarmLLV=(float)(query_select.value(10).toFloat());
                bean.m_H_Alarm_RelatedTo=query_select.value(11).toUInt();
                bean.m_HH_Alarm_RelatedTo=query_select.value(12).toUInt();
                bean.m_L_Alarm_RelatedTo=query_select.value(13).toUInt();
                bean.m_LL_Alarm_RelatedTo=query_select.value(14).toUInt();

                m_AiInforList.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;
}

int SLPIC_DataBase::GetAiTableInfo(QString filter)
{

    int res=false;
    if(this->Open())
    {

        QSqlTableModel model;
        model.setTable("AI");
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter=filter;
        model.setFilter( sql_filter);
        if (model.select()) {

            int rowCount=model.rowCount();

            res=rowCount;

        }
        else
        {
            res=0;
            setLastError( model.lastError().text());
        }
        this->database.close();

    }
    else
    {
        res=0;
        setLastError(this->database.lastError().text());


    }

    return res;


}

bool SLPIC_DataBase::DeleteInfoFromAiTable(const AI_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_delete;
        query_delete.prepare("DELETE FROM ai WHERE channelnum=?");
        int channelNum = bean.m_ChannelNum;
        query_delete.addBindValue(channelNum);
        if(!query_delete.exec())
        {
            //        qDebug()<<"delete record ["<<vecIdEscortStaffFingerPrint[i]<<"] in EscortStaffFingerPrint table failed!";

            setLastError(query_delete.lastError().text());
            res=false;

        }
        else
        {
            res=true;
            qDebug()<<"delete record ["<<QString::number(channelNum,10)<<"] in AI table failed!";
        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());


    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToAiTable(const AI_Information_Bean &bean)
{
    bool res=false;
    if(this->Open())
    {
        QSqlQuery query_insert;

        query_insert.prepare("INSERT INTO ai (Field, ChannelNum, SubProjectName,SubProjectNum,Enable,"
                             "RangeLV,RangeHV,AlarmHV,AlarmHHV,AlarmLV,AlarmLLV,"
                             "H_Alarm_RelatedTo,HH_Alarm_RelatedTo,L_Alarm_RelatedTo,LL_Alarm_RelatedTo) "
                             "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :Enable , "
                             ":RangeLV, :RangeHV, :AlarmHV, :AlarmHHV, :AlarmLV, :AlarmLLV,"
                             ":H_Alarm_RelatedTo, :HH_Alarm_RelatedTo, :L_Alarm_RelatedTo, :LL_Alarm_RelatedTo)");
        query_insert.bindValue(":Field",bean.m_Field);
        query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_insert.bindValue(":Enable",bean.m_Enable);
        query_insert.bindValue(":RangeLV",bean.m_RangeLV);
        query_insert.bindValue(":RangeHV",bean.m_RangeHV);
        query_insert.bindValue(":AlarmHV",bean.m_AlarmHV);
        query_insert.bindValue(":AlarmHHV",bean.m_AlarmHHV);
        query_insert.bindValue(":AlarmLV",bean.m_AlarmLV);
        query_insert.bindValue(":AlarmLLV",bean.m_AlarmLLV);
        query_insert.bindValue(":H_Alarm_RelatedTo",bean.m_H_Alarm_RelatedTo);
        query_insert.bindValue(":HH_Alarm_RelatedTo",bean.m_HH_Alarm_RelatedTo);
        query_insert.bindValue(":L_Alarm_RelatedTo",bean.m_L_Alarm_RelatedTo);
        query_insert.bindValue(":LL_Alarm_RelatedTo",bean.m_LL_Alarm_RelatedTo);


        if(!query_insert.exec())
        {

            setLastError(query_insert.lastError().text());
            res=false;
        }
        else
        {
            res=true;
            qDebug()<<"Insert infor into AI success!";

        }
        this->database.close();

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToAiTable(const QList<AI_Information_Bean> &InforList)
{
    bool res=false;
    QSqlQuery query_insert;
    QString sql_isnert="INSERT INTO ai (Field, ChannelNum, SubProjectName,SubProjectNum,Enable,"
                       "RangeLV,RangeHV,AlarmHV,AlarmHHV,AlarmLV,AlarmLLV,"
                       "H_Alarm_RelatedTo,HH_Alarm_RelatedTo,L_Alarm_RelatedTo,LL_Alarm_RelatedTo) "
                       "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :Enable , "
                       ":RangeLV, :RangeHV, :AlarmHV, :AlarmHHV, :AlarmLV, :AlarmLLV,"
                       ":H_Alarm_RelatedTo, :HH_Alarm_RelatedTo, :L_Alarm_RelatedTo, :LL_Alarm_RelatedTo)";
    if(this->Open())
    {
        for(int i=0;i<InforList.length();i++)
        {
            AI_Information_Bean bean=InforList[i];
            query_insert.bindValue(":Field",bean.m_Field);
            query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
            query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
            query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
            query_insert.bindValue(":Enable",bean.m_Enable);
            query_insert.bindValue(":RangeLV",bean.m_RangeLV);
            query_insert.bindValue(":RangeHV",bean.m_RangeHV);
            query_insert.bindValue(":AlarmHV",bean.m_AlarmHV);
            query_insert.bindValue(":AlarmHHV",bean.m_AlarmHHV);
            query_insert.bindValue(":AlarmLV",bean.m_AlarmLV);
            query_insert.bindValue(":AlarmLLV",bean.m_AlarmLLV);
            query_insert.bindValue(":H_Alarm_RelatedTo",bean.m_H_Alarm_RelatedTo);
            query_insert.bindValue(":HH_Alarm_RelatedTo",bean.m_HH_Alarm_RelatedTo);
            query_insert.bindValue(":L_Alarm_RelatedTo",bean.m_L_Alarm_RelatedTo);
            query_insert.bindValue(":LL_Alarm_RelatedTo",bean.m_LL_Alarm_RelatedTo);

            if(!query_insert.exec(sql_isnert))
            {
                setLastError(query_insert.lastError().text());
                this->database.close();
                res=false;
                return res;
            }
            else {
                res=true;

            }
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;

}

bool SLPIC_DataBase::UpdateInfoToAiTable(const AI_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_updata;

        query_updata.prepare("UPDATE ai SET Field=:Field,SubProjectName=:SubProjectName,SubProjectNum=:SubProjectNum,Enable=:Enable,"
                             "RangeLV=:RangeLV,RangeHV=:RangeHV,AlarmHV=:AlarmHV,AlarmHHV=:AlarmHHV,AlarmLV=:AlarmLV,AlarmLLV=:AlarmLLV,"
                             "H_Alarm_RelatedTo=:H_Alarm_RelatedTo, HH_Alarm_RelatedTo=:HH_Alarm_RelatedTo,L_Alarm_RelatedTo=:L_Alarm_RelatedTo,LL_Alarm_RelatedTo=:LL_Alarm_RelatedTo"
                             " WHERE ChannelNum=:ChannelNum");
        query_updata.bindValue(":Field",bean.m_Field);
        query_updata.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_updata.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_updata.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_updata.bindValue(":Enable",bean.m_Enable);
        query_updata.bindValue(":RangeLV",bean.m_RangeLV);
        query_updata.bindValue(":RangeHV",bean.m_RangeHV);
        query_updata.bindValue(":AlarmHV",bean.m_AlarmHV);
        query_updata.bindValue(":AlarmHHV",bean.m_AlarmHHV);
        query_updata.bindValue(":AlarmLV",bean.m_AlarmLV);
        query_updata.bindValue(":AlarmLLV",bean.m_AlarmLLV);
        query_updata.bindValue(":H_Alarm_RelatedTo",bean.m_H_Alarm_RelatedTo);
        query_updata.bindValue(":HH_Alarm_RelatedTo",bean.m_HH_Alarm_RelatedTo);
        query_updata.bindValue(":L_Alarm_RelatedTo",bean.m_L_Alarm_RelatedTo);
        query_updata.bindValue(":LL_Alarm_RelatedTo",bean.m_LL_Alarm_RelatedTo);
        if(!query_updata.exec())
        {
            res=false;
            setLastError(query_updata.lastError().text());
        }
        else
        {
            res=true;
            qDebug()<<tr("Updata info to AI table success!");
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());

    }

    return res;

}

bool SLPIC_DataBase::GetDiTableInfo()
{
    m_DiInforList.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM di  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DI_Information_Bean bean;
                bean.m_Field=query_select.value(0).toString();
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                bean.m_Enable=(byte)(query_select.value(4).toUInt());
                bean.m_DI_Alarm_RelatedTo=query_select.value(5).toUInt();
                m_DiInforList.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;

}

int SLPIC_DataBase::GetDiTableInfo(QString filter)
{
    int res=false;
    if(this->Open())
    {

        QSqlTableModel model;
        model.setTable("DI");
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter=filter;
        model.setFilter( sql_filter);
        if (model.select()) {

            int rowCount=model.rowCount();

            res=rowCount;

        }
        else
        {
            res=0;
            setLastError( model.lastError().text());
        }
        this->database.close();

    }
    else
    {
        res=0;
        setLastError(this->database.lastError().text());


    }

    return res;
}

bool SLPIC_DataBase::DeleteInfoFromDiTable(const DI_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_delete;
        query_delete.prepare("DELETE FROM di WHERE channelnum=?");
        int channelNum = bean.m_ChannelNum;
        query_delete.addBindValue(channelNum);
        if(!query_delete.exec())
        {
            //        qDebug()<<"delete record ["<<vecIdEscortStaffFingerPrint[i]<<"] in EscortStaffFingerPrint table failed!";

            setLastError(query_delete.lastError().text());
            res=false;

        }
        else
        {
            res=true;
            qDebug()<<"delete record ["<<QString::number(channelNum,10)<<"] in DI table failed!";
        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());


    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToDiTable(const DI_Information_Bean &bean)
{
    bool res=false;
    if(this->Open())
    {
        QSqlQuery query_insert;

        query_insert.prepare("INSERT INTO di (Field, ChannelNum, SubProjectName,SubProjectNum,Enable,Alarm_RelatedTo) "
                             "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :Enable, :Alarm_RelatedTo)");
        query_insert.bindValue(":Field",bean.m_Field);
        query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_insert.bindValue(":Enable",bean.m_Enable);

        query_insert.bindValue(":Alarm_RelatedTo",bean.m_DI_Alarm_RelatedTo);
        if(!query_insert.exec())
        {

            setLastError(query_insert.lastError().text());
            res=false;
        }
        else
        {
            res=true;
            qDebug()<<"Insert infor into DI success!";

        }
        this->database.close();

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;

}

bool SLPIC_DataBase::UpdateInfoToDiTable(const DI_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_updata;

        query_updata.prepare("UPDATE di SET Field=:Field,SubProjectName=:SubProjectName,SubProjectNum=:SubProjectNum,"
                             "Enable=:Enable,Alarm_RelatedTo=:Alarm_RelatedTo"
                             " WHERE ChannelNum=:ChannelNum");
        query_updata.bindValue(":Field",bean.m_Field);
        query_updata.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_updata.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_updata.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_updata.bindValue(":Enable",bean.m_Enable);

        query_updata.bindValue(":Alarm_RelatedTo",bean.m_DI_Alarm_RelatedTo);

        if(!query_updata.exec())
        {
            res=false;
            setLastError(query_updata.lastError().text());
        }
        else
        {
            res=true;
            qDebug()<<tr("Updata info to DI table success!");
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());

    }

    return res;

}

bool SLPIC_DataBase::GetDoTableInfo()
{
    m_DoInforList.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM do  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DO_Information_Bean bean;
                bean.m_Field=query_select.value(0).toString();
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                bean.m_Enable=(byte)(query_select.value(4).toUInt());
                m_DoInforList.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;

}

int SLPIC_DataBase::GetDoTableInfo(QString filter)
{
    int res=false;
    if(this->Open())
    {

        QSqlTableModel model;
        model.setTable("DO");
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter=filter;
        model.setFilter( sql_filter);
        if (model.select()) {

            int rowCount=model.rowCount();

            res=rowCount;

        }
        else
        {
            res=0;
            setLastError( model.lastError().text());
        }
        this->database.close();

    }
    else
    {
        res=0;
        setLastError(this->database.lastError().text());


    }

    return res;

}

bool SLPIC_DataBase::DeleteInfoFromDoTable(const DO_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_delete;
        query_delete.prepare("DELETE FROM do WHERE channelnum=?");
        int channelNum = bean.m_ChannelNum;
        query_delete.addBindValue(channelNum);
        if(!query_delete.exec())
        {

            setLastError(query_delete.lastError().text());
            res=false;

        }
        else
        {
            res=true;
            qDebug()<<"delete record ["<<QString::number(channelNum,10)<<"] in DO table failed!";
        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());


    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToDoTable(const DO_Information_Bean &bean)
{
    bool res=false;
    if(this->Open())
    {
        QSqlQuery query_insert;

        query_insert.prepare("INSERT INTO do (Field, ChannelNum, SubProjectName,SubProjectNum,Enable) "
                             "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :Enable)");
        query_insert.bindValue(":Field",bean.m_Field);
        query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_insert.bindValue(":Enable",bean.m_Enable);


        if(!query_insert.exec())
        {

            setLastError(query_insert.lastError().text());
            res=false;
        }
        else
        {
            res=true;
            qDebug()<<"Insert infor into DI success!";

        }
        this->database.close();

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;
}

bool SLPIC_DataBase::UpdateInfoToDoTable(const DO_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_updata;

        query_updata.prepare("UPDATE do SET Field=:Field,SubProjectName=:SubProjectName,SubProjectNum=:SubProjectNum,"
                             "Enable=:Enable  WHERE ChannelNum=:ChannelNum");
        query_updata.bindValue(":Field",bean.m_Field);
        query_updata.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_updata.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_updata.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_updata.bindValue(":Enable",bean.m_Enable);
        if(!query_updata.exec())
        {
            res=false;
            setLastError(query_updata.lastError().text());
        }
        else
        {
            res=true;
            qDebug()<<tr("Updata info to DI table success!");
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());

    }

    return res;

}

bool SLPIC_DataBase::GetSerialPortTableInfo()
{
    m_SerialPortInforList.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM serialport  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                SerialPort_Information_Bean bean;
                bean.m_Field=query_select.value(0).toString();
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                bean.m_Enable=(byte)(query_select.value(4).toUInt());
                bean.m_BaudRate=(dword)(query_select.value(5).toUInt());
                bean.m_DataBits=(byte)(query_select.value(6).toUInt());
                bean.m_Parity=(byte)(query_select.value(7).toUInt());
                bean.m_StopBit=(byte)(query_select.value(8).toUInt());
                bean.m_SlaveId=(byte)(query_select.value(9).toUInt());
                bean.m_Manufacturer=(byte)(query_select.value(10).toUInt());
                bean.m_Protocol=(byte)(query_select.value(11).toUInt());
                m_SerialPortInforList.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;

}

int SLPIC_DataBase::GetSerialPortTableInfo(QString filter)
{
    int res=false;
    if(this->Open())
    {

        QSqlTableModel model;
        model.setTable("SerialPort");
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter=filter;
        model.setFilter( sql_filter);
        if (model.select()) {

            int rowCount=model.rowCount();

            res=rowCount;

        }
        else
        {
            res=0;
            setLastError( model.lastError().text());
        }
        this->database.close();

    }
    else
    {
        res=0;
        setLastError(this->database.lastError().text());
    }

    return res;

}

bool SLPIC_DataBase::DeleteInfoFromSerialPortTable(const SerialPort_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_delete;
        query_delete.prepare("DELETE FROM serialport WHERE channelnum=?");
        int channelNum = bean.m_ChannelNum;
        query_delete.addBindValue(channelNum);
        if(!query_delete.exec())
        {
            //        qDebug()<<"delete record ["<<vecIdEscortStaffFingerPrint[i]<<"] in EscortStaffFingerPrint table failed!";

            setLastError(query_delete.lastError().text());
            res=false;

        }
        else
        {
            res=true;
            qDebug()<<"delete record ["<<QString::number(channelNum,10)<<"] in SerialPort table failed!";
        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());


    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToSerialPortTable(const SerialPort_Information_Bean &bean)
{

    bool res=false;
    if(this->Open())
    {
        QSqlQuery query_insert;

        query_insert.prepare("INSERT INTO serialport (Field, ChannelNum, SubProjectName,SubProjectNum,Enable,"
                             "BaudRate,DataBit,Parity,StopBit,SlaveID,Manufacturer,Protocol) "
                             "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :Enable,"
                             ":BaudRate, :DataBit, :Parity, :StopBit, :SlaveID, :Manufacturer, :Protocol)");
        query_insert.bindValue(":Field",bean.m_Field);
        query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_insert.bindValue(":Enable",bean.m_Enable);
        query_insert.bindValue(":BaudRate",bean.m_BaudRate);
        query_insert.bindValue(":DataBit",bean.m_DataBits);
        query_insert.bindValue(":Parity",bean.m_Parity);
        query_insert.bindValue(":StopBit",bean.m_StopBit);
        query_insert.bindValue(":SlaveID",bean.m_SlaveId);
        query_insert.bindValue(":Manufacturer",bean.m_Manufacturer);
        query_insert.bindValue(":Protocol",bean.m_Protocol);


        if(!query_insert.exec())
        {

            setLastError(query_insert.lastError().text());
            res=false;
        }
        else
        {
            res=true;
            qDebug()<<"Insert infor into SerialPort success!";

        }
        this->database.close();

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;
}

bool SLPIC_DataBase::UpdateInfoToSerialPortTable(const SerialPort_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_updata;

        query_updata.prepare("UPDATE SerialPort SET Field=:Field,SubProjectName=:SubProjectName,SubProjectNum=:SubProjectNum,Enable=:Enable,"
                             "BaudRate=:BaudRate,DataBit=:DataBit,Parity=:Parity,StopBit=:StopBit,SlaveID=:SlaveID,Manufacturer=:Manufacturer,Protocol=:Protocol"
                             " WHERE ChannelNum=:ChannelNum");
        query_updata.bindValue(":Field",bean.m_Field);
        query_updata.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_updata.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_updata.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_updata.bindValue(":Enable",bean.m_Enable);
        query_updata.bindValue(":BaudRate",bean.m_BaudRate);
        query_updata.bindValue(":DataBit",bean.m_DataBits);
        query_updata.bindValue(":Parity",bean.m_Parity);
        query_updata.bindValue(":StopBit",bean.m_StopBit);
        query_updata.bindValue(":SlaveID",bean.m_SlaveId);
        query_updata.bindValue(":Manufacturer",bean.m_Manufacturer);
        query_updata.bindValue(":Protocol",bean.m_Protocol);

        if(!query_updata.exec())
        {
            res=false;
            setLastError(query_updata.lastError().text());
        }
        else
        {
            res=true;
            qDebug()<<tr("Updata info to SerialPort table success!");
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());

    }

    return res;

}

bool SLPIC_DataBase::GetOtherTableInfo()
{
    m_OtherInforList.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM other  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                Other_Information_Bean bean;
                bean.m_Field=query_select.value(0).toString();
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                bean.m_Comm_protocol=(byte)(query_select.value(4).toUInt());
                bean.m_Comm_way=(byte)(query_select.value(5).toUInt());
                //7个字节BCD码！！！！！！！！
                bean.m_DeviceID=(qulonglong)(query_select.value(6).toULongLong());
                bean.m_Station_id=(word)(query_select.value(7).toUInt());
                bean.m_Ip=query_select.value(8).toString();
                bean.m_Port=(word)(query_select.value(9).toUInt());
                bean.m_Retry_counter=(byte)(query_select.value(10).toUInt());
                bean.m_Retry_interval=(word)(query_select.value(11).toUInt());
                bean.m_Heart_internal=(word)(query_select.value(12).toUInt());
                bean.m_Rtc_timer=(qulonglong)(query_select.value(13).toULongLong());
                bean.m_Gprs_pass_mode=(byte)(query_select.value(14).toUInt());
                bean.m_Density=query_select.value(15).toFloat();
                bean.m_Sys_restart=(byte)query_select.value(16).toUInt();

                bean.m_last_volume=(float)(query_select.value(17).toFloat());

                m_OtherInforList.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;

}

int SLPIC_DataBase::GetOtherTableInfo(QString filter)
{
    int res=false;
    if(this->Open())
    {

        QSqlTableModel model;
        model.setTable("Other");
        //QString sql_filter="ChannelNum="+QString::number(bean.m_ChannelNum,10) +" or SubProjectName="+QString::number(bean.m_SubProjectName,10);
        QString sql_filter=filter;
        model.setFilter( sql_filter);
        if (model.select()) {

            int rowCount=model.rowCount();

            res=rowCount;

        }
        else
        {
            res=0;
            setLastError( model.lastError().text());
        }
        this->database.close();

    }
    else
    {
        res=0;
        setLastError(this->database.lastError().text());


    }

    return res;

}

bool SLPIC_DataBase::DeleteInfoFromOtherTable(const Other_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_delete;
        query_delete.prepare("DELETE FROM other WHERE channelnum=?");
        int channelNum = bean.m_ChannelNum;
        query_delete.addBindValue(channelNum);
        if(!query_delete.exec())
        {
            //        qDebug()<<"delete record ["<<vecIdEscortStaffFingerPrint[i]<<"] in EscortStaffFingerPrint table failed!";

            setLastError(query_delete.lastError().text());
            res=false;

        }
        else
        {
            res=true;
            qDebug()<<"delete record ["<<QString::number(channelNum,10)<<"] in other table failed!";
        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());


    }
    return res;

}

bool SLPIC_DataBase::InsertInfoToOtherTable(const Other_Information_Bean &bean)
{

    bool res=false;
    if(this->Open())
    {
        QSqlQuery query_insert;


//         QString ="INSERT INTO  today1.Other (Field, ChannelNum, SubProjectName, SubProjectNum, comm_protocol, comm_way, deviceID, station_id, ip, port_num, retry_counter, retry_interval, heart_internal, rtc_timer, gprs_pass_mode, density, sys_restart) "
//                  "VALUES ('fdd', 1,  1, 2, 1, 1, 2434343434, 345, '127.0.0.1', 502, 2, 2, 2, 2033434343, 1, 324.56,1)";


        query_insert.prepare("INSERT INTO other (Field, ChannelNum, SubProjectName,SubProjectNum,comm_protocol,"
                             "comm_way,deviceID,station_id,ip,port_num,retry_counter,"
                             "retry_interval,heart_internal,rtc_timer,gprs_pass_mode,density,sys_restart,last_volume) "
                             "VALUES (:Field, :ChannelNum, :SubProjectName, :SubProjectNum, :comm_protocol , "
                             ":comm_way, :deviceID, :station_id, :ip, :port_num, :retry_counter,"
                             ":retry_interval, :heart_internal, :rtc_timer, :gprs_pass_mode,:density,:sys_restart,:last_volume)");
        query_insert.bindValue(":Field",bean.m_Field);
        query_insert.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_insert.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_insert.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_insert.bindValue(":comm_protocol",bean.m_Comm_protocol);
        query_insert.bindValue(":comm_way",bean.m_Comm_way);
        query_insert.bindValue(":deviceID",bean.m_DeviceID);
        query_insert.bindValue(":station_id",bean.m_Station_id);
        query_insert.bindValue(":ip",bean.m_Ip);
        query_insert.bindValue(":port_num",bean.m_Port);
        query_insert.bindValue(":retry_counter",bean.m_Retry_counter);
        query_insert.bindValue(":retry_interval",bean.m_Retry_interval);
        query_insert.bindValue(":heart_internal",bean.m_Heart_internal);
        query_insert.bindValue(":rtc_timer",bean.m_Rtc_timer);
        query_insert.bindValue(":gprs_pass_mode",bean.m_Gprs_pass_mode);
        query_insert.bindValue(":density",bean.m_Density);
        query_insert.bindValue(":sys_restart",bean.m_Sys_restart);
        query_insert.bindValue(":last_volume",bean.m_last_volume);


        if(!query_insert.exec())
        {

            setLastError(query_insert.lastError().text());
            res=false;
        }
        else
        {
            res=true;
            qDebug()<<"Insert infor into other success!";

        }
        this->database.close();

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;
}

bool SLPIC_DataBase::UpdateInfoToOtherTable(const Other_Information_Bean &bean)
{
    bool res=false;

    if(this->Open())
    {
        QSqlQuery query_updata;

        query_updata.prepare("UPDATE other SET Field=:Field,SubProjectName=:SubProjectName,SubProjectNum=:SubProjectNum,comm_protocol=:comm_protocol,"
                             "comm_way=:comm_way,deviceID=:deviceID,station_id=:station_id,ip=:ip,port_num=:port_num,retry_counter=:retry_counter,"
                             "retry_interval=:retry_interval, heart_internal=:heart_internal,rtc_timer=:rtc_timer,gprs_pass_mode=:gprs_pass_mode,"
                             "density=:density,sys_restart=:sys_restart,last_volume=:last_volume"
                             " WHERE ChannelNum=:ChannelNum");
        query_updata.bindValue(":Field",bean.m_Field);
        query_updata.bindValue(":ChannelNum",bean.m_ChannelNum);
        query_updata.bindValue(":SubProjectName",bean.m_SubProjectName);
        query_updata.bindValue(":SubProjectNum",bean.m_SubProjectNum);
        query_updata.bindValue(":comm_protocol",bean.m_Comm_protocol);
        query_updata.bindValue(":comm_way",bean.m_Comm_way);
        query_updata.bindValue(":deviceID",bean.m_DeviceID);
        query_updata.bindValue(":station_id",bean.m_Station_id);
        query_updata.bindValue(":ip",bean.m_Ip);
        query_updata.bindValue(":port_num",bean.m_Port);
        query_updata.bindValue(":retry_counter",bean.m_Retry_counter);
        query_updata.bindValue(":retry_interval",bean.m_Retry_interval);
        query_updata.bindValue(":heart_internal",bean.m_Heart_internal);
        query_updata.bindValue(":rtc_timer",bean.m_Rtc_timer);
        query_updata.bindValue(":gprs_pass_mode",bean.m_Gprs_pass_mode);
        query_updata.bindValue(":density",bean.m_Density);
        query_updata.bindValue(":sys_restart",bean.m_Sys_restart);

        query_updata.bindValue(":last_volume",bean.m_last_volume);
        if(!query_updata.exec())
        {
            res=false;
            setLastError(query_updata.lastError().text());
        }
        else
        {
            res=true;
            qDebug()<<tr("Updata info to other table success!");
        }

    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());

    }

    return res;

}

QString SLPIC_DataBase::filePath() const
{
    return m_filePath;
}

void SLPIC_DataBase::setFilePath(const QString &filePath)
{
    m_filePath = filePath;
}

bool SLPIC_DataBase::getAIStandPacketItems(DataPacketToSend::OperatorMode operateMode)
{
    m_standPacketItems_AI.clear();

    bool res=false;
    if(operateMode==DataPacketToSend::write)
    {
        if(this->Open())
        {


            QString sql_select = "SELECT * FROM ai  ORDER BY channelnum "  ;
            QSqlQuery query_select;
            if(query_select.exec(sql_select))
            {
                while (query_select.next()) {
                    DataPacketToSend::StandPacketRelevant bean;
                    //channelNum():1b
                    //SubProjectName():1b
                    //m_SubProjectNum():1b

                    /***************************TLV*******************************************************************************************/
                    //Enable(使能):01标题 [是否启用]     01:值长度              01：值 [启用]
                    //RangeLV():  03：标题 [最小量程]    04:值长度              00 00 00 00： 值 [0]
                    //RangeHV():  04：标题 [最大量程]    04:值长度              40 20 00 00： 值 [2.5]
                    //AlarmHV(): 05：标题 [高报]        04：值长度              3F 26 66 66： 值 [0.65]
                    //AlarmHHV(): 06：标题 [高高报]     04：值长度             3F 4C CC CD： 值 [0.8]
                    //AlarmLV(): 07：标题 [低报]       04：值长度              3E CC CC CD： 值 [0.4]
                    //AlarmLLV(): 08：标题 [低低报]    04：值长度              3E 4C CC CD： 值 [0.2]

                    //H_Alarm_RelatedTo():09：标题 [高报输出]   04:值长度     00 00 00 00：[不控制任何输出]
                    //HH_Alarm_RelatedTo():0A：标题 [高高报输出] 04： 值长度   00 04 00 05： [0005要求控制第1和第3个DO输出, 0004要求第1个DO输出低电平第3个DO输出高电平]
                    //L_Alarm_RelatedTo():0B：标题 [低报输出]    04： 值长度   00 00 00 00： [不控制任何输出]
                    //LL_Alarm_RelatedTo():0C:标题 [低低报输出]  04： 值长度   00 00 00 00： [不控制任何输出]


                    if(operateMode==DataPacketToSend::write)
                    {

                        bean.m_ChannelNum=(quint8)(query_select.value(1).toUInt());
                        bean.m_SubProjectName=(quint8)(query_select.value(2).toUInt());
                        bean.m_SubProjectNum=(quint8)(query_select.value(3).toUInt());
                        bean.m_ProjectName=0x01;




                        ////Enable

                        QByteArray valueList;
                        bean.m_ValuePacket.append(0x01);//t
                        bean.m_ValuePacket.append(0x01);//l
                        bean.m_ValuePacket.append((quint8)(query_select.value(4).toUInt()));//v

                        //RangeLV                        
                        Xconvert::InsertFloatToList((float)(query_select.value(5).toFloat()),valueList);
                        bean.m_ValuePacket.append(0x03);//t
                        bean.m_ValuePacket.append(0x04);//l
                        bean.m_ValuePacket.append(valueList);//v

                        //RangeHV
                        Xconvert::InsertFloatToList((float)(query_select.value(6).toFloat()),valueList);
//                      StandDataPackItem rangeHVItem(0x04,0x04,valueList);
//                      bean.m_StanddataPacketItems.append(rangeHVItem);
                        bean.m_ValuePacket.append(0x04);//t
                        bean.m_ValuePacket.append(0x04);//l
                        bean.m_ValuePacket.append(valueList);//v

                        //AlarmHV
                        Xconvert::InsertFloatToList((float)(query_select.value(7).toFloat()),valueList);
                        //StandDataPackItem alarmHVItem(0x05,0x04,valueList);
                        bean.m_ValuePacket.append(0x05);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);

                        //AlarmHHV

                        Xconvert::InsertFloatToList((float)(query_select.value(8).toFloat()),valueList);
//                      StandDataPackItem alarmHHVItem(0x06,0x04,valueList);
//                      bean.m_StanddataPacketItems.append(alarmHHVItem);
                        bean.m_ValuePacket.append(0x06);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);



                        //AlarmLV                                               
                        Xconvert::InsertFloatToList((float)(query_select.value(9).toFloat()),valueList);
//                        StandDataPackItem alarmLVItem(0x07,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(alarmLVItem);
                        bean.m_ValuePacket.append(0x07);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);

                        //AlarmLLV
                        Xconvert::InsertFloatToList((float)(query_select.value(10).toFloat()),valueList);
//                        StandDataPackItem alarmLLVItem(0x08,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(alarmLLVItem);
                        bean.m_ValuePacket.append(0x08);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);

                        //h_Alarm_RelatedToItem
                        Xconvert::InsertQuint32ToList((quint32)query_select.value(11).toUInt(),valueList);
//                        StandDataPackItem h_Alarm_RelatedToItem(0x09,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(h_Alarm_RelatedToItem);
                        bean.m_ValuePacket.append(0x09);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);


                        Xconvert::InsertQuint32ToList((quint32)query_select.value(12).toUInt(),valueList);
//                        StandDataPackItem hh_Alarm_RelatedToItem(0x0a,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(hh_Alarm_RelatedToItem);
                        bean.m_ValuePacket.append(0x0a);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);

                        //l_Alarm_RelatedToItem
                        Xconvert::InsertQuint32ToList((quint32)query_select.value(13).toUInt(),valueList);
//                        StandDataPackItem l_Alarm_RelatedToItem(0x0b,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(l_Alarm_RelatedToItem);
                        bean.m_ValuePacket.append(0x0b);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);


                        //ll_Alarm_RelatedToItem
                        Xconvert::InsertQuint32ToList((quint32)query_select.value(14).toUInt(),valueList);
//                        StandDataPackItem ll_Alarm_RelatedToItem(0x0c,0x04,valueList);
//                        bean.m_StanddataPacketItems.append(ll_Alarm_RelatedToItem);
                        bean.m_ValuePacket.append(0x0c);
                        bean.m_ValuePacket.append(0x04);
                        bean.m_ValuePacket.append(valueList);

                        /***************************TLV*******************************************************************************************/
                        m_standPacketItems_AI.append(bean);
                    }



                }
                res=true;
            }
            else
            {

                res=false;
                setLastError(query_select.lastError().text());


            }
            this->database.close();
        }
        else
        {
            res=false;
            setLastError(this->database.lastError().text());
        }

    }
    else if(operateMode==DataPacketToSend::write)
    {
        res=true;
        //8个通道全部读取
        for(int i=0;i<8;i++)
        {

        }

    }


    return res;
}

bool SLPIC_DataBase::getDIStandPacketItems(DataPacketToSend::OperatorMode operateMode)
{
    m_standPacketItems_DI.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM di  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DataPacketToSend::StandPacketRelevant bean;
//                bean.m_Field=query_select.value(0).toString();
//                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
//                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
//                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
//                bean.m_Enable=(byte)(query_select.value(4).toUInt());
//                bean.m_DI_Alarm_RelatedTo=query_select.value(5).toUInt();
//                m_DiInforList.append(bean);

                bean.m_ProjectName=0x02;
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());


                /****************************************TLV*********************************************/
                //eanble:01 01 01	01：标题 [是否启用]  01:值长度  01:值 [启用]
                bean.m_ValuePacket.append(0x01);//t
                bean.m_ValuePacket.append(0x01);//l
                bean.m_ValuePacket.append((byte)(query_select.value(4).toUInt()));//v

                //0D：标题 [DI报警输出]   04：值长度 00 08 00 0A： [000A要求控制第2和第4个DO输出, 0008要求第2个DO输出低电平第4个DO输出高电平]
                bean.m_ValuePacket.append(0x0d);//t
                bean.m_ValuePacket.append(0x04);//l
                QByteArray array;
                Xconvert::InsertQuint32ToList(query_select.value(5).toUInt(),array);
                bean.m_ValuePacket.append(array);//v

                m_standPacketItems_DI.append(bean);

                /****************************************TLV*********************************************/

            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;

}

bool SLPIC_DataBase::getDOStandPacketItems(DataPacketToSend::OperatorMode operateMode)
{

    m_standPacketItems_DI.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM do  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DataPacketToSend::StandPacketRelevant bean;
//                bean.m_Field=query_select.value(0).toString();
//                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
//                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
//                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
//                bean.m_Enable=(byte)(query_select.value(4).toUInt());

                bean.m_ProjectName=0x03;
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
                //01： 标题 [是否启用]   01： 值长度   01： 值 [启用]
                bean.m_ValuePacket.append(0x01);//t
                bean.m_ValuePacket.append(0x01);//l
                bean.m_ValuePacket.append((byte)(query_select.value(4).toUInt()));
                m_standPacketItems_DO.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }
    return res;


}

bool SLPIC_DataBase::getSPStandPacketItems(DataPacketToSend::OperatorMode operateMode)
{

    m_standPacketItems_SerialPort.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM serialport  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DataPacketToSend::StandPacketRelevant bean;
//                bean.m_Field=query_select.value(0).toString();
//                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
//                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
//                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
//                bean.m_Enable=(byte)(query_select.value(4).toUInt());
//                bean.m_BaudRate=(dword)(query_select.value(5).toUInt());
//                bean.m_DataBits=(byte)(query_select.value(6).toUInt());
//                bean.m_Parity=(byte)(query_select.value(7).toUInt());
//                bean.m_StopBit=(byte)(query_select.value(8).toUInt());
//                bean.m_SlaveId=(byte)(query_select.value(9).toUInt());
//                bean.m_Manufacturer=(byte)(query_select.value(10).toUInt());
//                bean.m_Protocol=(byte)(query_select.value(11).toUInt());
//                m_SerialPortInforList.append(bean);
                bean.m_ProjectName=0x04;
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());


                /***************************TLV***********************************************************/
                //Enable:   01：标题 [是否启用]    01： 值长度    01： 值 [启用]
                bean.m_ValuePacket.append(0x01);//t
                bean.m_ValuePacket.append(0x01);//l
                bean.m_ValuePacket.append((byte)(query_select.value(4).toUInt()));


                //m_BaudRate:  02：标题 [波特率]    04:值长度   00 00 25 80:值[9600]
                bean.m_ValuePacket.append(0x02);//t
                bean.m_ValuePacket.append(0x04);//l
                QByteArray array;
                Xconvert::InsertQuint32ToList((quint32)(query_select.value(5).toUInt()),array);
                bean.m_ValuePacket.append(array);//v


                //m_DataBits:01： 标题[数据位]    03： 值长度    08：值[08]
                bean.m_ValuePacket.append(0x03);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(6).toUInt()));

                //m_Parity:04：标题[奇偶校验]   01：值长度   4E： 值[‘N’]/[0x0]:[0x01]:[0x02]
                bean.m_ValuePacket.append(0x04);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(7).toUInt()));

                //m_StopBit:  05： 标题[停止位]    01：值长度   01：值[01]
                bean.m_ValuePacket.append(0x05);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(8).toUInt()));

                //m_SlaveId:  06：标题[节点地址]   01：值长度   01：值[01]
                bean.m_ValuePacket.append(0x06);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(9).toUInt()));


                //m_Manufacturer:07： 标题 [设备厂家]  01： 值长度  02： 值 [02 信东]
                bean.m_ValuePacket.append(0x07);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(10).toUInt()));


                //m_Protocol:08： 标题[设备协议]    01： 值长度  01： 值[01]
                bean.m_ValuePacket.append(0x08);
                bean.m_ValuePacket.append(0x01);
                bean.m_ValuePacket.append((byte)(query_select.value(11).toUInt()));
                m_standPacketItems_SerialPort.append(bean);


                /***************************TLV***********************************************************/

            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;

}

bool SLPIC_DataBase::getOtherStandPacketItems(DataPacketToSend::OperatorMode operateMode)
{


    m_standPacketItems_Other.clear();
    bool res=false;
    if(this->Open())
    {


        QString sql_select = "SELECT * FROM other  ORDER BY channelnum "  ;
        QSqlQuery query_select;
        if(query_select.exec(sql_select))
        {
            while (query_select.next()) {
                DataPacketToSend::StandPacketRelevant bean;
//                bean.m_Field=query_select.value(0).toString();
//                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
//                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
//                bean.m_SubProjectNum=(byte)(query_select.value(3).toUInt());
//                bean.m_Comm_protocol=(byte)(query_select.value(4).toUInt());
//                bean.m_Comm_way=(byte)(query_select.value(5).toUInt());
//                //7个字节BCD码！！！！！！！！
//                bean.m_DeviceID=(qulonglong)(query_select.value(6).toULongLong());
//                bean.m_Station_id=(word)(query_select.value(7).toUInt());
//                bean.m_Ip=query_select.value(8).toString();
//                bean.m_Port=(word)(query_select.value(9).toUInt());
//                bean.m_Retry_counter=(byte)(query_select.value(10).toUInt());
//                bean.m_Retry_interval=(word)(query_select.value(11).toUInt());
//                bean.m_Heart_internal=(word)(query_select.value(12).toUInt());
//                bean.m_Rtc_timer=(qulonglong)(query_select.value(13).toULongLong());
//                bean.m_Gprs_pass_mode=(byte)(query_select.value(14).toUInt());
//                bean.m_Density=query_select.value(15).toFloat();
//                bean.m_Sys_restart=(byte)query_select.value(16).toUInt();
//                m_OtherInforList.append(bean);



                bean.m_ProjectName=0x05;
                bean.m_ChannelNum=(byte)(query_select.value(1).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(2).toUInt());
                bean.m_SubProjectName=(byte)(query_select.value(3).toUInt());

//                01： 标题 [与中心通讯协议]     01： 值长度      01： 值[01富瑞]
               bean.m_ValuePacket.append(0x01);//t
               bean.m_ValuePacket.append(0x01);//l
               bean.m_ValuePacket.append((byte)(query_select.value(4).toUInt()));


//                02： 标题 [与中心通讯方式]    01： 值长度       01：值[01 GPRS]

               bean.m_ValuePacket.append(0x02);
               bean.m_ValuePacket.append(0x01);
               bean.m_ValuePacket.append((byte)(query_select.value(5).toUInt()));

//                03： 标题 [设备编号]        07：值长度     01 02 03 04 05 06 07
               bean.m_ValuePacket.append(0x03);
               bean.m_ValuePacket.append(0x07);
               QByteArray bcdArray;
               Xconvert::InsertQulonglongTOList((qulonglong)(query_select.value(6).toULongLong()),bcdArray);
               bean.m_ValuePacket.append(bcdArray);

//                04： 标题 [站点编号]         02： 值长度    11 22

               bean.m_ValuePacket.append(0x04);
               bean.m_ValuePacket.append(0x02);
               QByteArray array;
               Xconvert::InsertQuint16TOList((word)(query_select.value(7).toUInt()),array);
               bean.m_ValuePacket.append(array);


//                05：标题 [中心IP地址]      10：值长度      31 32 30 2E 31 39 32 2E 31 38 2E 32 34 35 00 00 [16字节IP地址， 右补0]
               bean.m_ValuePacket.append(0x05);//t
               QString ip=query_select.value(8).toString();
               int ip_length=ip.toLocal8Bit().length()+(16-ip.toLocal8Bit().length());
               bean.m_ValuePacket.append(ip_length);   //l
               bean.m_ValuePacket.append(ip.toLocal8Bit());//v
               //16byte 不满的补00
               for(int i=0;i<16-ip.toLocal8Bit().length();i++)
               {
                   quint8 dif=0x00;
                   bean.m_ValuePacket.append(dif);

               }

//                06：标题 [中心端口号]       02：值长度    BB 82： [端口48002]
               bean.m_ValuePacket.append(0x06);
               bean.m_ValuePacket.append(0x2);
               Xconvert::InsertQuint16TOList((word)(query_select.value(9).toUInt()),array);
               bean.m_ValuePacket.append(array);


//                07： 标题 [重发次数]      01： 值长度     03： [值3次]

               bean.m_ValuePacket.append(0x07);
               bean.m_ValuePacket.append(0x01);
               bean.m_ValuePacket.append((byte)(query_select.value(10).toUInt()));


//                08： 标题 [重发间隔]      02： 值长度    00 05： [值5秒]
               bean.m_ValuePacket.append(0x08);
               bean.m_ValuePacket.append(0x02);
               Xconvert::InsertQuint16TOList((word)(query_select.value(11).toUInt()),array);
               bean.m_ValuePacket.append(array);

//                09： 标题 [心跳间隔]      02： 值长度     00 3C： [值60秒]
               bean.m_ValuePacket.append(0x09);
               bean.m_ValuePacket.append(0x02);
               Xconvert::InsertQuint16TOList((word)(query_select.value(12).toUInt()),array);
               bean.m_ValuePacket.append(array);

//                0A： 标题 [RTC时钟]     07： 值长度      20 17 11 06 15 00 23： [值]
               bean.m_ValuePacket.append(0x0a);
               bean.m_ValuePacket.append(0x07);
               Xconvert::InsertQulonglongTOList((qulonglong)(query_select.value(13).toULongLong()),bcdArray);
               bean.m_ValuePacket.append(bcdArray);



//                0D： 标题 [GPRS透传模式]   01： 值长度    00：[值： 透传]
               bean.m_ValuePacket.append(0x0d);
               bean.m_ValuePacket.append(0x01);
               bean.m_ValuePacket.append((byte)(query_select.value(14).toUInt()));

//                0E： 标题 [密度]      04：值长度    00 00 00 00： [值]

               bean.m_ValuePacket.append(0x0e);
               bean.m_ValuePacket.append(0x04);
               Xconvert::InsertFloatToList(query_select.value(15).toFloat(),array);
               bean.m_ValuePacket.append(array);

//                0B ： 标题 [系统重启]    01：值长度     01：[值 01无特殊意义]


               bean.m_ValuePacket.append(0x0b);
               bean.m_ValuePacket.append(0x01);
               bean.m_ValuePacket.append((byte)query_select.value(16).toUInt());

 //                QByteArray valueList;
//               Xconvert::InsertFloatToList((float)(query_select.value(5).toFloat()),valueList);
//               bean.m_ValuePacket.append(0x03);//t
//               bean.m_ValuePacket.append(0x04);//l
//               bean.m_ValuePacket.append(valueList);//v

               QByteArray valueList;
               Xconvert::InsertFloatToList((float)(query_select.value(17).toFloat()),valueList);
               bean.m_ValuePacket.append(0x0f);//t
               bean.m_ValuePacket.append(0x04);//l
               bean.m_ValuePacket.append(valueList);//v

               m_standPacketItems_Other.append(bean);


            }
            res=true;
        }
        else
        {

            res=false;
            setLastError(query_select.lastError().text());


        }
        this->database.close();
    }
    else
    {
        res=false;
        setLastError(this->database.lastError().text());
    }

    return res;


}




