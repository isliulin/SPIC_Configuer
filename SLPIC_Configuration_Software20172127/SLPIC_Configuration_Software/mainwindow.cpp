#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDebug>
#include <QString>
#include <QStringList>


#include <QHeaderView>
#include <QDir>
#include <QFileDialog>
#include <QTableWidget>

#include <windows.h>
#include "WinSerialPort/wserialport.h"
#include <QSqlTableModel>

//SubProjectNameTable* MainWindow:: m_pGSubProjectNameTable=Q_NULLPTR;

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{

    m_AI_Edit=Q_NULLPTR;
    m_DI_Edit=Q_NULLPTR;
    m_DO_Edit=Q_NULLPTR;
    m_SerialPort_Edit=Q_NULLPTR;
    m_pConnection=Q_NULLPTR;
    m_pSerialPort=Q_NULLPTR;
    m_SubProjectNameTable=Q_NULLPTR;
    m_FilePath=tr("");
    m_Title=("自学型工业控制器配置软件");
    m_Fram=1;
    m_RecivedText="";
    m_countSended=0;
    m_RetryCount=0;
    m_RecievedFlag=false;
    m_Timer.setInterval(1000);
    ui->setupUi(this);
    mainWindowInit();
    ui->splitter_2->setStretchFactor(0,9);
    ui->splitter_2->setStretchFactor(1,1);
    ui->splitter->setStretchFactor(1,1);
    m_pSerialPort=Q_NULLPTR;
    TreeWidgetInit();
    msgWidgetInit();
    stackedWidgetInit();
    //创建系统配置信息窗体，此窗体要在各edit窗口实例之前
    InitSysConfigInfoUI();
    //创建AI_Edit
    CreateAI_Edit();  
    CreateDI_Edit();
    CreateDO_Edit();
    CreateSerialPort_Edit();
    CreateOther_Edit();
    CreateActions();

    //InitSysConfigInfoUI();
    //m_pGSubProjectNameTable=this->m_SubProjectNameTable;

    //connect(&thread,SIGNAL(response(QString)),this,SLOT(on_response(QString)));
    //connect(&m_Timer,SIGNAL(timeout()),this,SLOT(on_timeout()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

//SubProjectNameTable *MainWindow::GetSubProjectNameTable()
//{
//    return m_pGSubProjectNameTable;
//}


void MainWindow::TreeWidgetInit()
{
    //设定头项名称

    ui->treeWidget->setHeaderLabels(QStringList()<< tr("工程"));
    //设定各个项
     QTreeWidgetItem* project = new QTreeWidgetItem(QStringList()<<tr("项目"));
     project->setIcon(0,QIcon(":/images/images/copy.png"));
     ui->treeWidget->addTopLevelItem(project);

     //添加AI子节点
     QTreeWidgetItem *childAI=new QTreeWidgetItem(QStringList()<<tr("配置AI"));

     childAI->setIcon(0,QIcon(":/images/images/AI.png"));
     project->addChild(childAI);

     QTreeWidgetItem *childDI=new QTreeWidgetItem(QStringList()<<tr("配置DI"));
     childDI->setIcon(0,QIcon(":/images/images/switch.png"));
     project->addChild(childDI);

     QTreeWidgetItem *childDO=new QTreeWidgetItem(QStringList()<<tr("配置DO"));
     //:/images/images/DO.png
     childDO->setIcon(0,QIcon(":/images/images/DO.png"));
     project->addChild(childDO);



     QTreeWidgetItem *childSerialPort=new QTreeWidgetItem(QStringList()<<tr("配置串口"));

     childSerialPort->setIcon(0,QIcon(":/images/images/prot2.png"));
     project->addChild(childSerialPort);


     QTreeWidgetItem *childOther=new QTreeWidgetItem(QStringList()<<tr("其他配置"));
     //:/images/images/other.png
     childOther->setIcon(0,QIcon(":/images/images/other.png"));
     project->addChild(childOther);


//     QTreeWidgetItem* project1 = new QTreeWidgetItem(QStringList()<<tr("项目1"));
//     ui->treeWidget->addTopLevelItem(project1);


     connect(ui->treeWidget,SIGNAL(itemClicked(QTreeWidgetItem*,int)), this,SLOT(checkItem(QTreeWidgetItem* ,int)));


}

void MainWindow::msgWidgetInit()
{

    //ui->msgWidget->setWindowTitle(tr("配置信息"));
    ui->label-> setStyleSheet("background-color:gray"); // 设置QLabel背景的颜色

}

void MainWindow::stackedWidgetInit()
{
    AI_PageInite();
    DI_PageInite();
    DO_PageInite();
    SerialPort_PageInite();
    Other_PageInite();



}

void MainWindow::mainWindowInit()
{
    this->setWindowIcon(QIcon(":/images/images/furuiselogo.png"));

}

void MainWindow::AI_PageInite()
{

    QStringList tableHeaders;


    tableHeaders.append(tr("点位名"));
    tableHeaders.append(tr("通道号"));
    tableHeaders.append(tr("分项名"));
    tableHeaders.append(tr("分项编号"));
    tableHeaders.append(tr("是否启用"));
    tableHeaders.append(tr("量程低限"));
    tableHeaders.append(tr("量程高限"));
    tableHeaders.append(tr("报警高限"));
    tableHeaders.append(tr("报警高高限"));
    tableHeaders.append(tr("报警低限"));
    tableHeaders.append(tr("报警低低限"));
    tableHeaders.append(tr("高报输出"));
    tableHeaders.append(tr("高高报输出"));
    tableHeaders.append(tr("低报输出"));
    tableHeaders.append(tr("低低报输出"));
#ifdef DEBUG
    ui->AI_TableWidget->setRowCount(1);
#else
    ui->AI_TableWidget->setRowCount(0);
#endif
    ui->AI_TableWidget->setColumnCount(tableHeaders.length());
    ui->AI_TableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->AI_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->AI_TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->AI_TableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->AI_TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->AI_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);

    connect(ui->AI_TableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_AI_TableWidget_DoubleClicked(QModelIndex)));


}

void MainWindow::DI_PageInite()
{
    QStringList tableHeaders;


    tableHeaders.append(tr("点位名"));
    tableHeaders.append(tr("通道号"));
    tableHeaders.append(tr("分项名"));
    tableHeaders.append(tr("分项编号"));
    tableHeaders.append(tr("是否启用"));
    tableHeaders.append(tr("报警输出"));
    ui->DI_TableWidget->setRowCount(0);

    ui->DI_TableWidget->setColumnCount(tableHeaders.length());
    ui->DI_TableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->DI_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->DI_TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->DI_TableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->DI_TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->DI_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->DI_TableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_DI_TableWidget_DoubleClicked(QModelIndex)));

}

void MainWindow::DO_PageInite()
{
    QStringList tableHeaders;


    tableHeaders.append(tr("点位名"));
    tableHeaders.append(tr("通道号"));
    tableHeaders.append(tr("分项名"));
    tableHeaders.append(tr("分项编号"));
    tableHeaders.append(tr("是否启用"));

    ui->DO_TableWidget->setRowCount(0);

    ui->DO_TableWidget->setColumnCount(tableHeaders.length());
    ui->DO_TableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->DO_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->DO_TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->DO_TableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->DO_TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->DO_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->DO_TableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_DO_TableWidget_DoubleClicked(QModelIndex)));

}

void MainWindow::SerialPort_PageInite()
{
    QStringList tableHeaders;


    tableHeaders.append(tr("点位名"));
    tableHeaders.append(tr("通道号"));
    tableHeaders.append(tr("分项名"));
    tableHeaders.append(tr("分项编号"));
    tableHeaders.append(tr("是否启用"));
    tableHeaders.append(tr("波特率"));
    tableHeaders.append(tr("数据位"));
    tableHeaders.append(tr("奇偶校验"));
    tableHeaders.append(tr("停止位"));
    tableHeaders.append(tr("从站地址"));
    tableHeaders.append(tr("流量计厂家"));
    tableHeaders.append(tr("协议类型"));
    ui->SerialPort_TableWidget->setRowCount(0);

    ui->SerialPort_TableWidget->setColumnCount(tableHeaders.length());
    ui->SerialPort_TableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->SerialPort_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->SerialPort_TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->SerialPort_TableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->SerialPort_TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->SerialPort_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->SerialPort_TableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_SerialPort_TableWidget_DoubleClicked(QModelIndex)));

}

void MainWindow::Other_PageInite()
{
    QStringList tableHeaders;


    tableHeaders.append(tr("点位名"));
    tableHeaders.append(tr("通道号"));
    tableHeaders.append(tr("分项名"));
    tableHeaders.append(tr("分项编号"));
    tableHeaders.append(tr("通信协议"));
    tableHeaders.append(tr("通信方式"));
    tableHeaders.append(tr("设备编号"));
    tableHeaders.append(tr("站点编号"));
    tableHeaders.append(tr("服务器IP"));
    tableHeaders.append(tr("服务器端口号"));
    tableHeaders.append(tr("重发次数"));
    tableHeaders.append(tr("重发间隔"));
    tableHeaders.append(tr("心跳间隔"));
    tableHeaders.append(tr("RCT时钟"));
    tableHeaders.append(tr("GPRS传输模式"));
    tableHeaders.append(tr("密度"));
    tableHeaders.append(tr("系统重启"));

    tableHeaders.append(tr("剩余关阀量"));
    ui->Oter_Page_TableWidget->setRowCount(0);

    ui->Oter_Page_TableWidget->setColumnCount(tableHeaders.length());
    ui->Oter_Page_TableWidget->setHorizontalHeaderLabels(tableHeaders);
    ui->Oter_Page_TableWidget->setSelectionBehavior(QAbstractItemView::SelectRows);
    ui->Oter_Page_TableWidget->horizontalHeader()->setSectionResizeMode(QHeaderView::Interactive);
    ui->Oter_Page_TableWidget->setHorizontalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->Oter_Page_TableWidget->setVerticalScrollBarPolicy(Qt::ScrollBarAsNeeded);
    ui->Oter_Page_TableWidget->setEditTriggers(QAbstractItemView::NoEditTriggers);
    connect(ui->Oter_Page_TableWidget,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_Oter_TableWidget_DoubleClicked(QModelIndex)));

}

void MainWindow::EnableStackedWidgetToBeEdit()
{
    ui->AI_TableWidget->setRowCount(1);

}

//创建AI设计框
void MainWindow::CreateAI_Edit()
{
    m_AI_Edit=new AI_Edit(this);


    Qt::WindowFlags flags=Qt::Dialog;
    flags |=Qt::WindowCloseButtonHint;
    m_AI_Edit->setWindowFlags(flags);

    m_AI_Edit->setFixedSize(771,474);
    if(m_AI_Edit!=Q_NULLPTR)
    {
        m_AI_Edit->getSubProjectNameTable(this->m_SubProjectNameTable);
        //信号槽绑定
        connect(this,SIGNAL(AI_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)),m_AI_Edit,SLOT(On_AI_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)));
        connect(m_AI_Edit,SIGNAL(Edit_Triggle(EditPageNum)),this,SLOT(on_Edit_Triggle(EditPageNum)));
    }

}

//创建DI设计框
void MainWindow::CreateDI_Edit()
{
    m_DI_Edit=new DI_Edit(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags|=Qt::WindowCloseButtonHint;
    m_DI_Edit->setWindowFlags(flags);

    m_DI_Edit->setFixedSize(771,474);
    if(m_DI_Edit!=Q_NULLPTR)
    {
        //信号槽绑定
        m_DI_Edit->getSubProjectNameTable(this->m_SubProjectNameTable);
        connect(this,SIGNAL(DI_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)),m_DI_Edit,SLOT(On_DI_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)));
        connect(m_DI_Edit,SIGNAL(Edit_Triggle(EditPageNum)),this,SLOT(on_Edit_Triggle(EditPageNum)));
    }





}

void MainWindow::CreateDO_Edit()
{
    m_DO_Edit=new DO_Editer(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags|=Qt::WindowCloseButtonHint;
    m_DO_Edit->setWindowFlags(flags);

    m_DO_Edit->setFixedSize(771,474);
    if(m_DO_Edit!=Q_NULLPTR)
    {
        m_DO_Edit->getSubProjectNameTable(this->m_SubProjectNameTable);
        //信号槽绑定
        connect(this,SIGNAL(DO_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)),m_DO_Edit,SLOT(On_DO_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)));
        connect(m_DO_Edit,SIGNAL(Edit_Triggle(EditPageNum)),this,SLOT(on_Edit_Triggle(EditPageNum)));
    }

}

void MainWindow::CreateSerialPort_Edit()
{
    m_SerialPort_Edit=new SerialPort_Editer(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags|=Qt::WindowCloseButtonHint;
    m_SerialPort_Edit->setWindowFlags(flags);


    m_SerialPort_Edit->setFixedSize(784,578);
    if(m_SerialPort_Edit!=Q_NULLPTR)
    {
        m_SerialPort_Edit->getSubProjectNameTable(this->m_SubProjectNameTable);
        //信号槽绑定
        connect(this,SIGNAL(SerialPort_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)),m_SerialPort_Edit,SLOT(On_SerialPort_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)));
        connect(m_SerialPort_Edit,SIGNAL(Edit_Triggle(EditPageNum)),this,SLOT(on_Edit_Triggle(EditPageNum)));
    }

}

void MainWindow::CreateOther_Edit()
{
    m_Other_Edit=new Other_Editer(this);
    Qt::WindowFlags flags=Qt::Dialog;
    flags|=Qt::WindowCloseButtonHint;
    m_Other_Edit->setWindowFlags(flags);

    m_Other_Edit->setFixedSize(784,578);

    //获取系统信息



    //系统信息传到other_Edit页面
    m_Other_Edit->getSysInfo(m_mapCommProtocol,m_mapCommWay);

    if(m_Other_Edit!=Q_NULLPTR)
    {
        //信号槽绑定
        connect(this,SIGNAL(Other_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)),m_Other_Edit,SLOT(On_Other_Table_DoubleClick_trigger(QStringList,EditAttribute,QString)));
        connect(m_Other_Edit,SIGNAL(Edit_Triggle(EditPageNum)),this,SLOT(on_Edit_Triggle(EditPageNum)));
    }

}

void MainWindow::AppendRowToAiTable( QList<AI_Information_Bean> &beans)
{

    for(int i=0;i<beans.length();i++)
    {
        int row = ui->AI_TableWidget->rowCount();
        ui->AI_TableWidget->insertRow(row);
       QStringList stringListOfBean= beans[i].ToQstringlist();
       for(int j  = 0 ; j < stringListOfBean.size() ; j++)
       {
           QTableWidgetItem *item = new QTableWidgetItem;
           item->setText(stringListOfBean.at(j));
           ui->AI_TableWidget->setItem(row , j , item);
       }
    }

}

void MainWindow::OnRefreshAiTable(QList<AI_Information_Bean> &beans)
{


    int rowCount = ui->AI_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->AI_TableWidget->removeRow(r);
    }
    if(beans.length()>0)
    {
        AppendRowToAiTable(beans);
    }

}

void MainWindow::OnRefreshAiTable()
{
    if(m_DataBase.Open(m_FilePath))
    {

        if(m_DataBase.GetAiTableInfo())
        {
            OnRefreshAiTable(m_DataBase.m_AiInforList);

        }

    }

}

void MainWindow::AppendRowToDiTable(QList<DI_Information_Bean> &beans)
{
    for(int i=0;i<beans.length();i++)
    {
        int row = ui->DI_TableWidget->rowCount();
        ui->DI_TableWidget->insertRow(row);
       QStringList stringListOfBean= beans[i].ToQstringlist();
       for(int j  = 0 ; j < stringListOfBean.size() ; j++)
       {
           QTableWidgetItem *item = new QTableWidgetItem;
           item->setText(stringListOfBean.at(j));
           ui->DI_TableWidget->setItem(row , j , item);
       }
    }

}

void MainWindow::OnRefreshDiTable(QList<DI_Information_Bean> &beans)
{
    int rowCount = ui->DI_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->DI_TableWidget->removeRow(r);
    }
    if(beans.length()>0)
    {
        AppendRowToDiTable(beans);
    }


}

void MainWindow::OnRefreshDiTable()
{
    if(m_DataBase.Open(m_FilePath))
    {

        if(m_DataBase.GetDiTableInfo())
        {
            OnRefreshDiTable(m_DataBase.m_DiInforList);

        }

    }

}

void MainWindow::AppendRowToDoTable(QList<DO_Information_Bean> &beans)
{
    for(int i=0;i<beans.length();i++)
    {
        int row = ui->DO_TableWidget->rowCount();
        ui->DO_TableWidget->insertRow(row);
       QStringList stringListOfBean= beans[i].ToQstringlist();
       for(int j  = 0 ; j < stringListOfBean.size() ; j++)
       {
           QTableWidgetItem *item = new QTableWidgetItem;
           item->setText(stringListOfBean.at(j));
           ui->DO_TableWidget->setItem(row , j , item);
       }
    }

}

void MainWindow::OnRefreshDoTable(QList<DO_Information_Bean> &beans)
{
    int rowCount = ui->DO_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->DO_TableWidget->removeRow(r);
    }
    if(beans.length()>0)
    {
        AppendRowToDoTable(beans);
    }

}

void MainWindow::OnRefreshDoTable()
{
    if(m_DataBase.Open(m_FilePath))
    {

        if(m_DataBase.GetDoTableInfo())
        {
            OnRefreshDoTable(m_DataBase.m_DoInforList);

        }

    }

}

void MainWindow::AppendRowToSerialPortTable(QList<SerialPort_Information_Bean> &beans)
{
    for(int i=0;i<beans.length();i++)
    {
        int row = ui->SerialPort_TableWidget->rowCount();
        ui->SerialPort_TableWidget->insertRow(row);
       QStringList stringListOfBean= beans[i].ToQstringlist();
       for(int j  = 0 ; j < stringListOfBean.size() ; j++)
       {
           QTableWidgetItem *item = new QTableWidgetItem;
           item->setText(stringListOfBean.at(j));
           ui->SerialPort_TableWidget->setItem(row , j , item);
       }
    }

}

void MainWindow::OnRefreshSerialPortTable(QList<SerialPort_Information_Bean> &beans)
{
    int rowCount = ui->SerialPort_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->SerialPort_TableWidget->removeRow(r);
    }
    if(beans.length()>0)
    {
        AppendRowToSerialPortTable(beans);
    }

}

void MainWindow::OnRefreshSerialPortTable()
{
    if(m_DataBase.Open(m_FilePath))
    {

        if(m_DataBase.GetSerialPortTableInfo())
        {
            OnRefreshSerialPortTable(m_DataBase.m_SerialPortInforList);

        }

    }



}

void MainWindow::AppendRowToOtherTable(QList<Other_Information_Bean> &beans)
{
    for(int i=0;i<beans.length();i++)
    {
        int row = ui->Oter_Page_TableWidget->rowCount();
         ui->Oter_Page_TableWidget->insertRow(row);
       QStringList stringListOfBean= beans[i].ToQstringlist();
       for(int j  = 0 ; j < stringListOfBean.size() ; j++)
       {
           QTableWidgetItem *item = new QTableWidgetItem;
           item->setText(stringListOfBean.at(j));
           ui->Oter_Page_TableWidget->setItem(row , j , item);
       }
    }

}

void MainWindow::OnRefreshOtherTable(QList<Other_Information_Bean> &beans)
{

    int rowCount = ui->Oter_Page_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->Oter_Page_TableWidget->removeRow(r);
    }
    if(beans.length()>0)
    {
        AppendRowToOtherTable(beans);
    }

}

void MainWindow::OnRefreshOtherTable()
{
    if(m_DataBase.Open(m_FilePath))
    {

        if(m_DataBase.GetOtherTableInfo())
        {
            OnRefreshOtherTable(m_DataBase.m_OtherInforList);

        }

    }


}

void MainWindow::CreateActions()
{
    //初始化qaction，并注册响应的槽函数
    m_pAct_Add = new QAction(tr("增加一行"), this);
    m_pAct_Edit = new QAction(tr("编辑记录"), this);
    m_pAct_Delete=new QAction(tr("删除记录"),this);
    connect(m_pAct_Add, SIGNAL(triggered()), this, SLOT(on_act_add_triggered()));
    connect(m_pAct_Edit, SIGNAL(triggered()), this, SLOT(on_act_edit_triggered()));
    connect(m_pAct_Delete,SIGNAL(triggered(bool)),this,SLOT(on_act_delete_triggered()));

}

void MainWindow::ClearAiTableInfo()
{

    int rowCount = ui->AI_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->AI_TableWidget->removeRow(r);
    }
}

void MainWindow::ClearDiTableInfo()
{
    int rowCount = ui->DI_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->DI_TableWidget->removeRow(r);
    }

}

void MainWindow::ClearDoTableInfo()
{
    int rowCount = ui->DO_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->DO_TableWidget->removeRow(r);
    }

}

void MainWindow::ClearSerialPortTableInfo()
{

    int rowCount = ui->SerialPort_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->SerialPort_TableWidget->removeRow(r);
    }
}

void MainWindow::ClearOtherTableInfo()
{
    int rowCount = ui->Oter_Page_TableWidget->rowCount();
    for(int r = rowCount-1 ; r >=0 ; r--)
    {
        ui->Oter_Page_TableWidget->removeRow(r);
    }

}

void MainWindow::DeleteSelectedRowInAiTable()
{
    AI_Information_Bean bean;
    int currentRow=ui->AI_TableWidget->currentRow();
    //获取Ai: ChannelNum的值
    QTableWidgetItem *item=ui->AI_TableWidget->item(currentRow,1);
    if(item==NULL)
    {
        //啥也不做
        return;


    }


    bean.m_ChannelNum=item->text().toUInt();
    //删除 含有当前ChannelNum的那行
    if(m_DataBase.DeleteInfoFromAiTable(bean))
    {

        QMessageBox::information(this,tr("INFO"),tr("删除")+"AI:"+item->text()+"成功！");
    }


}

void MainWindow::DeleteSelectedRowInDiTable()
{
    DI_Information_Bean bean;
    int currentRow=ui->DI_TableWidget->currentRow();
    //获取Ai: ChannelNum的值
    QTableWidgetItem *item=ui->DI_TableWidget->item(currentRow,1);
    if(item==NULL)
    {
        //啥也不做
        return;

    }

    bean.m_ChannelNum=item->text().toUInt();
    //删除 含有当前ChannelNum的那行
    if(m_DataBase.DeleteInfoFromDiTable(bean))
    {
        QMessageBox::information(this,tr("INFO"),tr("删除")+"DI:"+item->text()+"成功！");
    }

}

void MainWindow::DeleteSelectedRowInDOTable()
{
    DO_Information_Bean bean;
    int currentRow=ui->DO_TableWidget->currentRow();
    //获取Ai: ChannelNum的值
    QTableWidgetItem *item=ui->DO_TableWidget->item(currentRow,1);
    if(item==NULL)
    {
        //啥也不做
        return;

    }
    bean.m_ChannelNum=item->text().toUInt();
    //删除 含有当前ChannelNum的那行
    if(m_DataBase.DeleteInfoFromDoTable(bean))
    {
        QMessageBox::information(this,tr("INFO"),tr("删除")+"DO:"+item->text()+"成功！");
    }

}

void MainWindow::DeleteSelectedRowInSerialPortTable()
{

    SerialPort_Information_Bean bean;
    int currentRow=ui->SerialPort_TableWidget->currentRow();
    //获取Ai: ChannelNum的值
    QTableWidgetItem *item=ui->SerialPort_TableWidget->item(currentRow,1);
    if(item==NULL)
    {
        //啥也不做
        return;

    }
    bean.m_ChannelNum=item->text().toUInt();
    //删除 含有当前ChannelNum的那行
    if(m_DataBase.DeleteInfoFromSerialPortTable(bean))
    {
        QMessageBox::information(this,tr("INFO"),tr("删除")+"COM:"+item->text()+"成功！");
    }
}

void MainWindow::DeleteSelectedRowInOtherTable()
{
    Other_Information_Bean bean;
    int currentRow=ui->Oter_Page_TableWidget->currentRow();
    //获取Ai: ChannelNum的值
    QTableWidgetItem *item=ui->Oter_Page_TableWidget->item(currentRow,1);
    if(item==NULL)
    {
        //啥也不做
        return;

    }
    bean.m_ChannelNum=item->text().toUInt();
    //删除 含有当前ChannelNum的那行
    if(m_DataBase.DeleteInfoFromOtherTable(bean))
    {
        QMessageBox::information(this,tr("INFO"),tr("删除")+"Channel:"+item->text()+"成功！");
    }

}

void MainWindow::actionLoadPushDown()
{

    ui->actionDownload->setEnabled(false);
    ui->actionUpload->setEnabled(false);
}

void MainWindow::actionLoadPullUp()
{
    ui->actionDownload->setEnabled(true);
    ui->actionUpload->setEnabled(true);

}

QList<SubProjectNameBean> &MainWindow::getInforFroDataBase(QString tableName, QSqlDatabase db, Qt::SortOrder order)
{
    m_tempStringList.clear();
    //m_SysDataBase.getDatabase()
    QSqlTableModel *model = new QSqlTableModel(this,db);
    model->setTable(tableName);
    model->setSort(1,order);
    model->select();
    int rows=model->rowCount();

    //int s= model->index(0,1).data().toInt();
    SubProjectNameBean bean;
    for(int i=0;i<rows;i++)
    {
        bean.m_Filed= model->index(i,0).data().toString();
        bean.m_Filed= model->index(i,1).data().toInt();
        m_tempStringList.append(bean);
    }
    return m_tempStringList;

}

QString &MainWindow::RecievedTextToDisplay(const QByteArray &recievedArray)
{

    m_RecivedText.clear();
    int length=recievedArray.length();

    for(int i=0;i<length;i++ )
    {
        m_RecivedText+=QString::number((quint8)(recievedArray.at(i)),16)+" ";
        m_RecivedText=m_RecivedText.toUpper();

    }
    m_RecivedText="Rx:"+m_RecivedText;
    return m_RecivedText;
}

QString &MainWindow::SendedTextToDisplay(const QByteArray &recievedArray)
{
    m_SendedText.clear();
    int length=recievedArray.length();

    for(int i=0;i<length;i++ )
    {
        m_SendedText+=QString::number((quint8)(recievedArray.at(i)),16)+" ";
        m_SendedText=m_SendedText.toUpper();

    }
    m_SendedText="Tx:"+m_SendedText;
    return m_SendedText;
}






void MainWindow::checkItem(QTreeWidgetItem * item , int count)
{
    QTreeWidgetItem *parent = item->parent();
    //根节点判断
    if(parent==NULL)
    {
        //qDebug()<<tr("No parent!");
        if(item->text(0)==QString("项目"))
        {
            ui->stackedWidget->setCurrentIndex(0);
        }

    }
    else
    {
        int col = parent->indexOfChild(item);
        switch (col) {
        //AI
        case 0:
            ui->stackedWidget->setCurrentIndex(0);
            break;
         //DI
        case 1:
            ui->stackedWidget->setCurrentIndex(1);
            break;
         //DO
        case 2:
             ui->stackedWidget->setCurrentIndex(2);
            break;
         //serialport
        case 3:
             ui->stackedWidget->setCurrentIndex(3);
            break;
         //other
        case 4:
             ui->stackedWidget->setCurrentIndex(4);
            break;
        default:
            break;
        }
    }


}

void MainWindow::on_AI_TableWidget_DoubleClicked(QModelIndex)
{

    EditAttribute attribute;
    int row=ui->AI_TableWidget->currentRow();
    QStringList list;
    QTableWidgetItem *item=ui->AI_TableWidget->item(row,1);

    if(item==NULL)
    {
        //未被编辑过，为NULL
        attribute=InsertEdit;

    }
    else {
        //if
        //被编辑过但是为"" 或者"0"
        if(item->text().isEmpty()||item->text()==tr("0"))
        {
            attribute=InsertEdit;
        }
        //else
        //为修改。
        else {

            attribute=updateEdit;
            for(int i=0;i<15;i++)
            {
                list.append(ui->AI_TableWidget->item(row,i)->text());
            }

        }

    }
     //将系统配置信息表窗体所在指针传给AI_Edit
    emit AI_Table_DoubleClick_trigger(list,attribute,m_FilePath);

    m_AI_Edit->exec();



}

void MainWindow::on_DI_TableWidget_DoubleClicked(QModelIndex)
{
    EditAttribute attribute;
    int row=ui->DI_TableWidget->currentRow();
    QStringList list;
    QTableWidgetItem *item=ui->DI_TableWidget->item(row,1);
    if(item==NULL)
    {
        //未被编辑过，为NULL
        attribute=InsertEdit;

    }
    else {
        //if
        //被编辑过但是为"" 或者"0"
        if(item->text().isEmpty()||item->text()==tr("0"))
        {
            attribute=InsertEdit;
        }
        //else
        //为修改。
        else {

            attribute=updateEdit;
            for(int i=0;i<6;i++)
            {
                list.append(ui->DI_TableWidget->item(row,i)->text());
            }

        }

    }
    //将系统配置信息表窗体所在指针传给DI_Edit
    emit DI_Table_DoubleClick_trigger(list,attribute,m_FilePath);
    m_DI_Edit->exec();


}

void MainWindow::on_DO_TableWidget_DoubleClicked(QModelIndex)
{
    EditAttribute attribute;
    int row=ui->DO_TableWidget->currentRow();
    QStringList list;
    QTableWidgetItem *item=ui->DO_TableWidget->item(row,1);
    if(item==NULL)
    {
        //未被编辑过，为NULL
        attribute=InsertEdit;

    }
    else {
        //if
        //被编辑过但是为"" 或者"0"
        if(item->text().isEmpty()||item->text()==tr("0"))
        {
            attribute=InsertEdit;
        }
        //else
        //为修改。
        else {

            attribute=updateEdit;
            for(int i=0;i<5;i++)
            {
                list.append(ui->DO_TableWidget->item(row,i)->text());
            }

        }

    }
    emit DO_Table_DoubleClick_trigger(list,attribute,m_FilePath);
    m_DO_Edit->exec();

}

void MainWindow::on_SerialPort_TableWidget_DoubleClicked(QModelIndex)
{
    EditAttribute attribute;
    int row=ui->SerialPort_TableWidget->currentRow();
    QStringList list;
    QTableWidgetItem *item=ui->SerialPort_TableWidget->item(row,1);
    if(item==NULL)
    {
        //未被编辑过，为NULL
        attribute=InsertEdit;

    }
    else {
        //if
        //被编辑过但是为"" 或者"0"
        if(item->text().isEmpty()||item->text()==tr("0"))
        {
            attribute=InsertEdit;
        }
        //else
        //为修改。
        else {

            attribute=updateEdit;
            for(int i=0;i<12;i++)
            {
                list.append(ui->SerialPort_TableWidget->item(row,i)->text());
            }

        }

    }
    emit SerialPort_Table_DoubleClick_trigger(list,attribute,m_FilePath);
    m_SerialPort_Edit->exec();

}

void MainWindow::on_Oter_TableWidget_DoubleClicked(QModelIndex)
{
    EditAttribute attribute;
    int row=ui->Oter_Page_TableWidget->currentRow();
    QStringList list;
    QTableWidgetItem *item=ui->Oter_Page_TableWidget->item(row,1);
    if(item==NULL)
    {
        //未被编辑过，为NULL
        attribute=InsertEdit;

    }
    else {
        //if
        //被编辑过但是为"" 或者"0"
        if(item->text().isEmpty()||item->text()==tr("0"))
        {
            attribute=InsertEdit;
        }
        //else
        //为修改。
        else {

            attribute=updateEdit;
            for(int i=0;i<18;i++)
            {
                list.append(ui->Oter_Page_TableWidget->item(row,i)->text());
            }

        }

    }
    emit Other_Table_DoubleClick_trigger(list,attribute,m_FilePath);
    m_Other_Edit->exec();


}

void MainWindow::on_response( QByteArray bytesToRecieve)
{
    //如果校验通过，则插入bytesToRecieve
   m_RecieveArray.append(bytesToRecieve);
   ui->outMsgText->append(RecievedTextToDisplay(bytesToRecieve));


  // ui->outMsgText->append(s);

}

void MainWindow::on_timeout(QString s)
{

    ui->outMsgText->append(s);
    //将下载按钮使能
   actionLoadPullUp();


}

void MainWindow::on_error(QString s )
{
    ui->outMsgText->append(s);
    //将下载按钮使能
    actionLoadPullUp();


}

void MainWindow::on_complete(QString s )
{
    ui->outMsgText->append(s);
    //将下载按钮使能
    actionLoadPullUp();


}

void MainWindow::on_sRequest(QByteArray bytesToSend)
{
    ui->outMsgText->append(this->SendedTextToDisplay(bytesToSend));

}

void MainWindow::on_actionNew_triggered()
{
    QString projctPath=QCoreApplication::applicationDirPath()+"/project";

    QString file_path = QFileDialog::getSaveFileName(this, tr("保存"),projctPath);
    if(!file_path.isEmpty())
    {
        /*检查改目录下有没有同名文件，如有则删除*/
        QDir dir(projctPath);
        QFileInfoList fileNameList= dir.entryInfoList();
        QFileInfo fi(file_path);

        qDebug()<<fileNameList.indexOf(fi);
        if(fileNameList.indexOf(fi)!=-1)
        {
            QFile f;
            f.remove(file_path);
        }
        if(m_DataBase.CreateDB(file_path))
        {
            m_FilePath=file_path;
            setWindowTitle(m_Title+tr("-")+m_FilePath);
            //清画面残留信息AI  DI  DO SP other
            ClearAiTableInfo();
            ClearDiTableInfo();
            ClearDoTableInfo();
            ClearSerialPortTableInfo();
            ClearOtherTableInfo();
        }
    }
}

void MainWindow::on_actionabout_triggered()
{

}

void MainWindow::on_actionOpen_triggered()
{
    QString projctPath=QCoreApplication::applicationDirPath()+"/project";
    QString file_path = QFileDialog::getOpenFileName(this,tr("打开文件"),projctPath);
    if(!file_path.isEmpty())
    {

        if(m_DataBase.Open(file_path))
        {
            m_FilePath=file_path;

            //获取AI信息并展示到相应的表上
            if(m_DataBase.GetAiTableInfo())
            {
                OnRefreshAiTable(m_DataBase.m_AiInforList);

            }
            //获取DI信息并展示到相应的表上
            if(m_DataBase.GetDiTableInfo())
            {
                OnRefreshDiTable(m_DataBase.m_DiInforList);

            }

            //获取Do信息并展示到相应的表上
            if(m_DataBase.GetDoTableInfo())
            {
                OnRefreshDoTable(m_DataBase.m_DoInforList);

            }

            //获取SerialPort信息并展示到相应的表上
            if(m_DataBase.GetSerialPortTableInfo())
            {
                OnRefreshSerialPortTable(m_DataBase.m_SerialPortInforList);

            }

            //获取Other信息并展示到相应的表上
            if(m_DataBase.GetOtherTableInfo())
            {
                OnRefreshOtherTable(m_DataBase.m_OtherInforList);

            }



            setWindowTitle(m_Title+tr("-")+m_FilePath);

        }



    }
}

void MainWindow::on_act_add_triggered()
{
    //检测哪种类型的表格：是di 还是ai还是do， 还是串口...
    int index=ui->stackedWidget->currentIndex();
    switch (index) {
    case 0:ui->AI_TableWidget->insertRow(ui->AI_TableWidget->rowCount());


        break;
    case 1:ui->DI_TableWidget->insertRow(ui->DI_TableWidget->rowCount());
        break;
    case 2:ui->DO_TableWidget->insertRow(ui->DO_TableWidget->rowCount());

        break;
    case 3:
        ui->SerialPort_TableWidget->insertRow(ui->SerialPort_TableWidget->rowCount());
        break;
    case 4:
        ui->Oter_Page_TableWidget->insertRow(ui->Oter_Page_TableWidget->rowCount());

        break;
    default:
        break;
    }


}

void MainWindow::on_act_edit_triggered()
{

}

void MainWindow::on_act_delete_triggered()
{

    //检测哪种类型的表格：是di 还是ai还是do， 还是串口...
    int index=ui->stackedWidget->currentIndex();
    switch (index) {
    //AI
    case 0:
        //删除AI表中被选择的行
        DeleteSelectedRowInAiTable();
        OnRefreshAiTable();
        break;
    //DI
    case 1:
        DeleteSelectedRowInDiTable();
        OnRefreshDiTable();
        break;
    case 2:
        DeleteSelectedRowInDOTable();
        OnRefreshDoTable();
        break;
    case 3:
        DeleteSelectedRowInSerialPortTable();
        OnRefreshSerialPortTable();
        break;
    case 4:
        DeleteSelectedRowInOtherTable();
        OnRefreshOtherTable();
        break;
    default:
        break;
    }

}

void MainWindow::on_Edit_Triggle(EditPageNum pageNum)
{
    switch (pageNum) {
    case AI_Page:this->OnRefreshAiTable();
        break;
    case DI_Page:this->OnRefreshDiTable();
        break;
    case DO_Page:this->OnRefreshDoTable();
        break;
    case SerialPortPage:this->OnRefreshSerialPortTable();
        break;
    case Other_Page:this->OnRefreshOtherTable();
        break;
    default:
        break;
    }

}

void MainWindow::contextMenuEvent(QContextMenuEvent *event)
{
    QCursor cur=this->cursor();
    QMenu *menu=new QMenu(this);
    menu->addAction(m_pAct_Add);
    //menu->addAction(m_pAct_Edit);
    menu->addAction(m_pAct_Delete);
    if(m_FilePath.isEmpty())
    {
        menu->setEnabled(false);
    }
    else
    {
        menu->setEnabled(true);

    }
    menu->exec(cur.pos()); //关联到光标

}

void MainWindow::sleep(unsigned int msec)
{
    QTime dieTime = QTime::currentTime().addMSecs(msec);
    while( QTime::currentTime() < dieTime )
        QCoreApplication::processEvents(QEventLoop::AllEvents, 100);

}

void MainWindow::InitSysConfigInfoUI()
{

    if(m_SubProjectNameTable==Q_NULLPTR)
    {
        m_SubProjectNameTable=new SubProjectNameTable(this);


        //打开数据库，获取每一页的数据
        QString projctPath=QCoreApplication::applicationDirPath()+"/systems";

        QString file_path = projctPath+"/sysConfInfo.db";
        //QList<SubProjectNameBean> beans;
        if(m_SysDataBase.Open(file_path))
        {
            //QMessageBox::information(this,tr("info"),tr("打开系统数据陈成功"));
            //AI
            QSqlTableModel *aiModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            aiModel->setTable(tr("AI"));
            aiModel->setSort(1,Qt::AscendingOrder);
            aiModel->select();
//          int rows=model->rowCount();
//          m_SubProjectNameTable->setModel(model);
//          m_SubProjectNameTable->exec();
            m_SubProjectNameTable->SetModel(aiModel,SubProjectNameTable::AI);

            //DI
            QSqlTableModel *diModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            diModel->setTable(tr("DI"));
            diModel->setSort(1,Qt::AscendingOrder);
            diModel->select();
            m_SubProjectNameTable->SetModel(diModel,SubProjectNameTable::DI);
            //m_SubProjectNameTable->show();

            //DO
            QSqlTableModel *doModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            doModel->setTable(tr("DO"));
            doModel->setSort(1,Qt::AscendingOrder);
            doModel->select();
            m_SubProjectNameTable->SetModel(doModel,SubProjectNameTable::DO);

            //SerialPort
            QSqlTableModel *spModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            spModel->setTable(tr("SerialPort"));
            spModel->setSort(1,Qt::AscendingOrder);
            spModel->select();
            m_SubProjectNameTable->SetModel(spModel,SubProjectNameTable::SerialPort);


            //manufacture
            QSqlTableModel *manufactureModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            manufactureModel->setTable(tr("Manufacturers"));
            manufactureModel->setSort(1,Qt::AscendingOrder);
            manufactureModel->select();
            m_SubProjectNameTable->SetModel(manufactureModel,SubProjectNameTable::Manufacture);


            //com_protocol_to_host
            QSqlTableModel *commProtocoleModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            commProtocoleModel->setTable(tr("com_proto_to_host"));
            commProtocoleModel->setSort(1,Qt::AscendingOrder);
            commProtocoleModel->select();
            m_SubProjectNameTable->SetModel(commProtocoleModel,SubProjectNameTable::commProtocol);

            int commProtocolModelRowCount=commProtocoleModel->rowCount();
            m_mapCommProtocol.clear();
            for(int i=0;i<commProtocolModelRowCount;i++)
            {
                m_mapCommProtocol.insert(commProtocoleModel->index(i,1).data().toInt(), commProtocoleModel->index(i,0).data().toString());

            }

             //com_way_to_host
            QSqlTableModel *commWayModel = new QSqlTableModel(this,m_SysDataBase.getDatabase());
            commWayModel->setTable(tr("com_way_to_host"));
            commWayModel->setSort(1,Qt::AscendingOrder);
            commWayModel->select();
            m_SubProjectNameTable->SetModel(commWayModel,SubProjectNameTable::commWay);

            m_mapCommWay.clear();
            int commWayModelRowCount=commWayModel->rowCount();
            for(int i=0;i<commWayModelRowCount;i++)
            {
                m_mapCommWay.insert(commWayModel->index(i,1).data().toInt(), commWayModel->index(i,0).data().toString());

            }

        }








        //m_SubProjectNameTable->show();



        //其他参数（系统参数）combox内容需要从数据表中取出
    }


}

void MainWindow::on_actionClose_triggered()
{
    //清空m_FilePath
    m_FilePath="";
    //清空所有表格所残存信息
    this->ClearAiTableInfo();
    this->ClearDiTableInfo();
    this->ClearDoTableInfo();
    this->ClearSerialPortTableInfo();
    this->ClearOtherTableInfo();
    //清空标题
    setWindowTitle(tr("自学型工业控制器配置软件"));


}

void MainWindow::on_actionConnect_triggered()
{
    if(m_pConnection==Q_NULLPTR)
    {
        m_pConnection= new Connection(this);
        connect(m_pConnection,SIGNAL(serialPortOpened(WSerialport* )),this,SLOT(on_serialPortOpened(WSerialport*)));
        connect(this,SIGNAL(serialPortCLosed(bool)),m_pConnection,SLOT(on_SerialPortCLosed(bool)));
    }

    m_pConnection->exec();

}

void MainWindow::on_serialPortOpened(WSerialport *serialPort)
{
    m_pSerialPort=serialPort;
    //connect(m_pSerialPort,SIGNAL(readyRead()),this,SLOT(on_readyRead()));
    ui->actionConnect->setEnabled(false);
    ui->actionDisconnect->setEnabled(true);

}

void MainWindow::on_actionDisconnect_triggered()
{
    if(m_pSerialPort!=Q_NULLPTR)
    {


//        if(m_pSerialPort->isOpen())
//        {
//            m_pSerialPort->close();
//            //emit
//            emit serialPortCLosed(true);

//            //message:close success!
//            QMessageBox::information(this,tr("INFO"),tr("串口关闭成功！"));
//            ui->actionDisconnect->setEnabled(false);
//            ui->actionConnect->setEnabled(true);

//        }
//        else
//        {
//            //message:throw error
//            QMessageBox::warning(this,tr("WARNING"),m_pSerialPort->errorString());

//        }
        if(m_pSerialPort->CloseCOM())
        {
            emit serialPortCLosed(true);

            //message:close success!
            QMessageBox::information(this,tr("INFO"),tr("串口关闭成功！"));
            ui->actionDisconnect->setEnabled(false);
            ui->actionConnect->setEnabled(true);

        }
        else
        {
            //message:throw error
            DWORD errorCode=m_pSerialPort->GetLastErrors();
            QMessageBox::warning(this,tr("WARNING"),tr("串口打开失败,ERRORCODE:")+QString::number(errorCode, 16).toUpper());


        }
    }
}

void MainWindow::on_readyRead()
{


//    QByteArray array=m_pSerialPort->readAll();
//    //emit
//    ui->outMsgText->append(RecievedTextToDisplay(array));


}

void MainWindow::on_clearButton_clicked()
{
    ui->outMsgText->clear();
}

void MainWindow::on_actionDownload_triggered()
{

    m_AI_Packetes_ToSend.clear();
    if(m_pSerialPort==Q_NULLPTR)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("串口未打开"));
        return;
    }

    if(m_pSerialPort->isOpen())
    {
        //读取数据库信息 AI, DI,DO,serialport,other
        //AI
        if(m_DataBase.getAIStandPacketItems(DataPacketToSend::write))
        {

            //如果读取成功
            int length=m_DataBase.m_standPacketItems_AI.length();
            for(int i=0;i<length;i++)
            {
                DataPacketToSend ai_Packet(DataPacketToSend::write);

                ai_Packet.AssemblePacket(m_DataBase.m_standPacketItems_AI.at(i));
                m_AI_Packetes_ToSend.append(ai_Packet);


            }




        }
        else {
            //读取失败，抛出数据库异常
            QMessageBox::warning(this,tr("WARNING"),m_DataBase.LastError());
            return;
        }

        //DI

        m_DI_Packetes_ToSend.clear();
        if(m_DataBase.getDIStandPacketItems(DataPacketToSend::write))
        {

            //如果读取成功
            int length=m_DataBase.m_standPacketItems_DI.length();
            for(int i=0;i<length;i++)
            {
                DataPacketToSend di_Packet(DataPacketToSend::write);

                di_Packet.AssemblePacket(m_DataBase.m_standPacketItems_DI.at(i));
                m_DI_Packetes_ToSend.append(di_Packet);
            }

        }
        else {
            //读取失败，抛出数据库异常
            QMessageBox::warning(this,tr("WARNING"),m_DataBase.LastError());
            return;
        }

        //Do
        m_DO_Packetes_ToSend.clear();
        if(m_DataBase.getDOStandPacketItems(DataPacketToSend::write))
        {

            //如果读取成功
            int length=m_DataBase.m_standPacketItems_DO.length();
            for(int i=0;i<length;i++)
            {
                DataPacketToSend do_Packet(DataPacketToSend::write);

                do_Packet.AssemblePacket(m_DataBase.m_standPacketItems_DO.at(i));
                m_DO_Packetes_ToSend.append(do_Packet);
            }

        }
        else {
            //读取失败，抛出数据库异常
            QMessageBox::warning(this,tr("WARNING"),m_DataBase.LastError());
            return;
        }

        //other
        m_Other_Packetes_ToSend.clear();
        if(m_DataBase.getOtherStandPacketItems(DataPacketToSend::write))
        {

            //如果读取成功
            int length=m_DataBase.m_standPacketItems_Other.length();
            for(int i=0;i<length;i++)
            {
                DataPacketToSend other_Packet(DataPacketToSend::write);

                other_Packet.AssemblePacket(m_DataBase.m_standPacketItems_Other.at(i));
                m_Other_Packetes_ToSend.append(other_Packet);
            }

        }
        else {
            //读取失败，抛出数据库异常
            QMessageBox::warning(this,tr("WARNING"),m_DataBase.LastError());
            return;
        }


        //serialport
        m_SP_Packetes_ToSend.clear();
        if(m_DataBase.getSPStandPacketItems(DataPacketToSend::write))
        {

            //如果读取成功
            int length=m_DataBase.m_standPacketItems_SerialPort.length();
            for(int i=0;i<length;i++)
            {
                DataPacketToSend sp_Packet(DataPacketToSend::write);

                sp_Packet.AssemblePacket(m_DataBase.m_standPacketItems_SerialPort.at(i));
                m_SP_Packetes_ToSend.append(sp_Packet);
            }

        }
        else {
            //读取失败，抛出数据库异常
            QMessageBox::warning(this,tr("WARNING"),m_DataBase.LastError());
            return;
        }

    }
    else
    {
        //如果串口未打开，提示用户打开串口
        QMessageBox::information(this,tr("INFO"),tr("串口未打开"));
        return;
    }

    m_SendArray.clear();
    m_RecieveArray.clear();

    //AI

    for(int i=0;i<m_AI_Packetes_ToSend.length();i++)
    {

        m_SendArray.append(m_AI_Packetes_ToSend.at(i).m_Packet);

    }


    //di
        for(int i=0;i<m_DI_Packetes_ToSend.length();i++)
        {

            m_SendArray.append(m_DI_Packetes_ToSend.at(i).m_Packet);

        }

    //do

    for(int i=0;i<m_DO_Packetes_ToSend.length();i++)
    {

        m_SendArray.append(m_DO_Packetes_ToSend.at(i).m_Packet);

    }

    //sp
        for(int i=0;i<m_SP_Packetes_ToSend.length();i++)
        {

            m_SendArray.append(m_SP_Packetes_ToSend.at(i).m_Packet);

        }

    //other
    for(int i=0;i<m_Other_Packetes_ToSend.length();i++)
    {

        m_SendArray.append(m_Other_Packetes_ToSend.at(i).m_Packet);

    }




//    if(m_SendArray.length()>0)
//    {
//        actionLoadPushDown();


//        /*multthread*/
        MasterThread *thread=new MasterThread(this);

        connect(thread,SIGNAL(finished()),thread,SLOT(deleteLater()));
        connect(thread,SIGNAL(complete(QString)),this,SLOT(on_complete(QString)));
        connect(thread,SIGNAL(response(QByteArray)),this,SLOT(on_response(QByteArray)));
//        connect(thread,SIGNAL(timeout(QString)),this,SLOT(on_timeout(QString)));
        connect(thread,SIGNAL(error(QString)),this,SLOT(on_error(QString)));
        connect(thread,SIGNAL(sRequest(QByteArray)),this,SLOT(on_sRequest(QByteArray)));
        thread->transaction(m_pSerialPort,m_SendArray);

//    }


}

void MainWindow::on_actiondebug_triggered()
{
    if(m_SendArray.length()>0)
    {

        QByteArray requestData = this->m_SendArray[0];
        requestData[3]=0+1;
        Xconvert::LRC(requestData);

        int writeLength=requestData.length();
        m_pSerialPort->ComWrite((LPBYTE)requestData.data(),writeLength);
        Sleep(200);
        int recivedlength=0;
        BYTE* recvBuf=new BYTE[1024]();
        m_pSerialPort->ComRead(recvBuf,recivedlength);
        QByteArray array;
        array.append((char*)recvBuf,recivedlength);

        /*BYTE buff[]={0x02,0x01,0x02,0x01,0x00,0x68,0x01,0x06,0x01,0x02,0x3F,0x01,0x01,0x01,0x03,0x04,0x00,0x00,0x00,0x00,0x04,0x04,0x40,0x20,0x00,0x00,0x05,0x04,0x3F,0x26,0x66,0x66,0x06,0x04,0x3F,0x4C,0xCC,0xCD,0x07,0x04,0x3E,0xCC,0xCC,0xCD,0x08,0x04,0x3E,0x4C,0xCC,0xCD,0x09,0x04,0x00,0x00,0x00,0x00,0x0A,0x04,0x00,0x04,0x00,0x05,0x0B,0x04,0x00,0x00,0x00,0x00,0x0C,0x04,0x00,0x00,0x00,0x00,0x03,0xD4};


        int writeLength=sizeof(buff);

        m_pSerialPort->ComWrite(buff,writeLength);

        Sleep(200);
        int recivedlength=0;
        BYTE* recvBuf=new BYTE[1024]();
        m_pSerialPort->ComRead(recvBuf,recivedlength);
        QByteArray array;
        array.append((char*)recvBuf,recivedlength);*/

        ui->outMsgText->append(RecievedTextToDisplay(array));

    }



}

void MainWindow::on_actionUpload_triggered()
{
//    m_pSerialPort->flush();


//    if(m_SendArray.length()>0)
//    {
//        QByteArray requestData = this->m_SendArray[0];
//        requestData[3]=0+1;
//        Xconvert::LRC(requestData);
//        m_pSerialPort->write(requestData);
//    }









}

void MainWindow::on_actiontest_triggered()
{

}



void MainWindow::on_actiontest_2_triggered()
{

}
