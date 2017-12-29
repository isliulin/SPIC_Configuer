#include "subprojectnametable.h"
#include "ui_subprojectnametable.h"

SubProjectNameTable::SubProjectNameTable(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::SubProjectNameTable)
{
    ui->setupUi(this);

    initAiUi();
    initDiUi();
    initDoUi();
    initSpUi();
    initManufactUi();
    initComProtocolUi();
    initComWayUi();
    connect(ui->aiTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_aiTableview_dbClicked(QModelIndex)));
    connect(ui->diTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_diTableview_dbClicked(QModelIndex)));
    connect(ui->doTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_doTableview_dbClicked(QModelIndex)));
    connect(ui->serialTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_spTableview_dbClicked(QModelIndex)));
    connect(ui->manufactTableView,SIGNAL(doubleClicked(QModelIndex)),this,SLOT(on_spTableview_dbClicked(QModelIndex)));

}

SubProjectNameTable::~SubProjectNameTable()
{
    delete ui;
}



void SubProjectNameTable::SetModel(QSqlTableModel *model,TableName tableName)
{
    //enum TableName {AI=0, DI, DO, SerialPort, Manufacture, commProtocol, commWay};
    switch (tableName) {
    case AI:
        ui->aiTableView->setModel(model);
        break;
    case DI:
        ui->diTableView->setModel(model);
        break;
    case DO:
        ui->doTableView->setModel(model);
        break;
    case SerialPort:
        ui->serialTableView->setModel(model);
        break;
    case Manufacture:
         ui->manufactTableView->setModel(model);
        break;
    case commProtocol:
        ui->commprotoTableView->setModel(model);
        break;
    case commWay:
        ui->commwaytableView->setModel(model);
        break;

    default:
        break;
    }

}

QMap<int, QString> &SubProjectNameTable::getFtManufactureMap()
{
    //ui->manufactTableView->
    m_FtManufactureMap.clear();
     QAbstractItemModel* pModel =ui->manufactTableView->model();
     int rowCount=pModel->rowCount();
     for(int i=0;i<rowCount;i++)
     {
         //pModel->index(i,0).data().toString(),

         m_FtManufactureMap.insert(pModel->index(i,1).data().toInt(),pModel->index(i,0).data().toString());
     }
     return m_FtManufactureMap;


}

void SubProjectNameTable::initAiUi()
{
    ui->aiTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->aiTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->aiTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void SubProjectNameTable::initDiUi()
{
    ui->diTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->diTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->diTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);


}

void SubProjectNameTable::initDoUi()
{
    ui->doTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->doTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->doTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
}

void SubProjectNameTable::initSpUi()
{
    ui->serialTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->serialTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->serialTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void SubProjectNameTable::initManufactUi()
{
    ui->manufactTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->manufactTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->manufactTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

}

void SubProjectNameTable::initComProtocolUi()
{
    ui->commprotoTableView->setEnabled(false);


    /*
    ui->commprotoTableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->commprotoTableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->commprotoTableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    */
}

void SubProjectNameTable::initComWayUi()
{
    ui->commwaytableView->setEnabled(false);
    /*
    ui->commwaytableView->setSelectionBehavior(QAbstractItemView::SelectRows);

    ui->commwaytableView->setSelectionMode ( QAbstractItemView::SingleSelection);

    ui->commwaytableView->setEditTriggers(QAbstractItemView::NoEditTriggers);
    */
}

void SubProjectNameTable::on_linkced(EditPageNum page)
{
    m_page=page;

}

void SubProjectNameTable::on_aiTableview_dbClicked(QModelIndex index)
{

    if(m_page!=AI_Page)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("AI配置信息不能作为其他配置信息"));

        return;
    }

    QAbstractItemModel* m = (QAbstractItemModel *)index.model();
    SubProjectNameBean bean;

    int currentRow=index.row();

    bean.m_Filed=m->index(currentRow,0).data().toString();
    bean.m_SeriesNumber=m->index(currentRow,1).data().toInt();
    emit setAI_Edit_Info(bean);

    this->close();

}

void SubProjectNameTable::on_diTableview_dbClicked(QModelIndex index)
{
    if(m_page!=DI_Page)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("DI配置信息不能作为其他配置信息"));

        return;
    }

    QAbstractItemModel* m = (QAbstractItemModel *)index.model();
    SubProjectNameBean bean;
    int currentRow=index.row();
    bean.m_Filed=m->index(currentRow,0).data().toString();
    bean.m_SeriesNumber=m->index(currentRow,1).data().toInt();
    emit setDI_Edit_Info(bean);

    this->close();


}

void SubProjectNameTable::on_doTableview_dbClicked(QModelIndex index)
{
    if(m_page!=DO_Page)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("DI配置信息不能作为其他配置信息"));

        return;
    }

    QAbstractItemModel* m = (QAbstractItemModel *)index.model();
    SubProjectNameBean bean;

    int currentRow=index.row();
    bean.m_Filed=m->index(currentRow,0).data().toString();
    bean.m_SeriesNumber=m->index(currentRow,1).data().toInt();
    emit setDO_Edit_Info(bean);

    this->close();

}

void SubProjectNameTable::on_spTableview_dbClicked(QModelIndex index)
{
    int pageIndxe= ui->tabWidget->currentIndex();
//    if(m_page!=SerialPortPage_Sub_ProjName)
//    {
//        QMessageBox::warning(this,tr("WARNING"),tr("串口配置信息不能作为其他配置信息"));

//        return;
//    }
//    if(m_page!=SerialPortPage_FT_Manufacture)
//    {
//        QMessageBox::warning(this,tr("WARNING"),tr("流量计厂家配置信息不能作为其他配置信息"));

//        return;
//    }
    bool made=false;
    if(pageIndxe==3&&m_page==SerialPortPage_Sub_ProjName)
    {

        made=true;

    }
    else if(pageIndxe==4&&m_page==SerialPortPage_FT_Manufacture)
    {

        made=true;

    }
    else {
        made=false;
        if(pageIndxe!=3&&m_page==SerialPortPage_Sub_ProjName)
        {
            QMessageBox::warning(this,tr("WARNING"),tr("其他配置信息不能作为串口配置信息的平台ID"));

        }
        else if(pageIndxe!=4&&m_page==SerialPortPage_FT_Manufacture)
        {
            QMessageBox::warning(this,tr("WARNING"),tr("其他配置信息不能作为串口配置信息的流量计厂家ID"));

        }


    }

    if(!made)
    {
        return;
    }
    else {
        QAbstractItemModel* m = (QAbstractItemModel *)index.model();
        SubProjectNameBean bean;

        int currentRow=index.row();
        bean.m_Filed=m->index(currentRow,0).data().toString();
        bean.m_SeriesNumber=m->index(currentRow,1).data().toInt();
        emit setSP_Edit_Info(bean,m_page);

        this->close();

    }



}

void SubProjectNameTable::on_manufTableview_dbClicked(QModelIndex index)
{
    if(m_page!=SerialPortPage_Sub_ProjName)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("串口配置信息不能作为其他配置信息"));

        return;
    }
    if(m_page!=SerialPortPage_FT_Manufacture)
    {
        QMessageBox::warning(this,tr("WARNING"),tr("流量计厂家配置信息不能作为其他配置信息"));

        return;
    }

    QAbstractItemModel* m = (QAbstractItemModel *)index.model();
    SubProjectNameBean bean;

    int currentRow=index.row();
    bean.m_Filed=m->index(currentRow,0).data().toString();
    bean.m_SeriesNumber=m->index(currentRow,1).data().toInt();
    emit setSP_Edit_Info(bean,m_page);

    this->close();

}



void SubProjectNameTable::on_confirmButton_clicked()
{

    this->close();
}
