#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTreeWidgetItem>
#include <QTableWidget>
#include "ai_edit.h"
#include "di_edit.h"
#include "do_editer.h"
#include "serialport_editer.h"
#include "other_editer.h"
#include <QString>
#include "database/slpic_database.h"
#include <QTableWidget>
#include <QStringList>
#include <QMessageBox>
#include "common/commonhead.h"
#include "connection.h"
#include <QSerialPort>
#include <QSerialPortInfo>
#include <QByteArray>


#include "data_packegt/datapackettosend.h"
//#include "database/di_information_bean.h"
//#define DEBUG
namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();
public slots:
     void checkItem(QTreeWidgetItem* item ,int count);
     void on_AI_TableWidget_DoubleClicked(QModelIndex);
     void on_DI_TableWidget_DoubleClicked(QModelIndex);
     void on_DO_TableWidget_DoubleClicked(QModelIndex);
     void on_SerialPort_TableWidget_DoubleClicked(QModelIndex);
     void on_Oter_TableWidget_DoubleClicked(QModelIndex);

private slots:
     void on_actionNew_triggered();

     void on_actionabout_triggered();

     void on_actionOpen_triggered();

     void on_act_add_triggered();
     void on_act_edit_triggered();
     void on_act_delete_triggered();
     void on_Edit_Triggle(EditPageNum pageNum);

     void on_actionClose_triggered();

     void on_actionConnect_triggered();
     void on_serialPortOpened(QSerialPort* serialPort);

     void on_actionDisconnect_triggered();
     void on_readyRead();

     void on_clearButton_clicked();

     void on_actionDownload_triggered();

     void on_actiondebug_triggered();

protected:
     virtual void contextMenuEvent(QContextMenuEvent *event);
private:
    Ui::MainWindow *ui;
    void TreeWidgetInit();
    void msgWidgetInit();
    void stackedWidgetInit();
    void mainWindowInit();
    void AI_PageInite();
    void DI_PageInite();
    void DO_PageInite();    
    void SerialPort_PageInite();
    void Other_PageInite();

    void EnableStackedWidgetToBeEdit();
    void CreateAI_Edit();
    void CreateDI_Edit();
    void CreateDO_Edit();
    void CreateSerialPort_Edit();
    void CreateOther_Edit();

    void AppendRowToAiTable(QList<AI_Information_Bean> &beans);
    void OnRefreshAiTable(QList<AI_Information_Bean> &beans);
    void OnRefreshAiTable();

    void AppendRowToDiTable(QList<DI_Information_Bean> &beans);
    void OnRefreshDiTable(QList<DI_Information_Bean> &beans);
    void OnRefreshDiTable();

    void AppendRowToDoTable(QList<DO_Information_Bean> &beans);
    void OnRefreshDoTable(QList<DO_Information_Bean> &beans);
    void OnRefreshDoTable();

    void AppendRowToSerialPortTable(QList<SerialPort_Information_Bean> &beans);
    void OnRefreshSerialPortTable(QList<SerialPort_Information_Bean> &beans);
    void OnRefreshSerialPortTable();

    void AppendRowToOtherTable(QList<Other_Information_Bean> &beans);
    void OnRefreshOtherTable(QList<Other_Information_Bean> &beans);
    void OnRefreshOtherTable();



    void CreateActions();

    void ClearAiTableInfo();
    void ClearDiTableInfo();
    void ClearDoTableInfo();
    void ClearSerialPortTableInfo();
    void ClearOtherTableInfo();



    //删除被选中的AI表中的行信息
    void DeleteSelectedRowInAiTable();
    //删除被选中的DI表中的行信息
    void DeleteSelectedRowInDiTable();
    //删除被选中的Do表中的行信息
    void DeleteSelectedRowInDOTable();       
    //删除被选中的serialPort表中的行信息
    void DeleteSelectedRowInSerialPortTable();
    //删除被选中的Other表中的行信息
    void DeleteSelectedRowInOtherTable();


    /**
* @brief translate recievedArray which is  recieced by  local serialport to Qstring, then show
* this to user
* @param
* @return
* @author xiaoyao
* @date 2017/11/21
*/
    QString& RecievedTextToDisplay(const QByteArray &recievedArray);
    QString& SendedTextToDisplay(const QByteArray &recievedArray);

private:

    AI_Edit *m_AI_Edit;
    DI_Edit *m_DI_Edit;
    DO_Editer *m_DO_Edit;
    SerialPort_Editer *m_SerialPort_Edit;
    Other_Editer *m_Other_Edit;

    QString m_FilePath;//数据库文件所在路径
    SLPIC_DataBase m_DataBase;
    QString m_Title;

    QAction* m_pAct_Add;
    QAction* m_pAct_Edit;
    QAction* m_pAct_Delete;

    Connection* m_pConnection;
    QSerialPort* m_pSerialPort;

    //AI报文:发送的
    QList<DataPacketToSend> m_AI_Packetes_ToSend;
    //DI报文:发送的
    QList<DataPacketToSend> m_DI_Packetes_ToSend;

    //DO
    QList<DataPacketToSend> m_DO_Packetes_ToSend;

    //serialport
    QList<DataPacketToSend> m_SP_Packetes_ToSend;

    //other
    QList<DataPacketToSend> m_Other_Packetes_ToSend;


    //用来转换接收的数据(QbyteArray---->Qstring)
    QString m_RecivedText;
    QString m_SendedText;

    quint8  m_Fram;//帧号

signals:

    void AI_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
    void DI_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
    void DO_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
    void SerialPort_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
    void Other_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
    void serialPortCLosed(bool closeFlag);



};

#endif // MAINWINDOW_H
