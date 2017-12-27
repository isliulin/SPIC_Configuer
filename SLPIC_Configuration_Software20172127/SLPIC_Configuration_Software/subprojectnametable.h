#ifndef SUBPROJECTNAMETABLE_H
#define SUBPROJECTNAMETABLE_H

#include <QDialog>
#include <QSqlTableModel>

#include "common/commonhead.h"
#include "subprojectnamebean.h"

#include <QMessageBox>

#include <QMap>
#include <QString>
namespace Ui {
class SubProjectNameTable;
}

class SubProjectNameTable : public QDialog
{
    Q_OBJECT


public :
    enum TableName {AI=0, DI, DO, SerialPort, Manufacture, commProtocol, commWay};
public:
    explicit SubProjectNameTable(QWidget *parent = 0);
    ~SubProjectNameTable();
    void SetModel(QSqlTableModel *model,TableName tableName);

     QMap<int,QString>&  getFtManufactureMap();

private:
    Ui::SubProjectNameTable *ui;
    EditPageNum m_page;
    QMap<int,QString> m_FtManufactureMap;
private:
    void initAiUi();
    void initDiUi();
    void initDoUi();
    void initSpUi();
    void initManufactUi();
    void initComProtocolUi();
    void initComWayUi();
public slots:
    void on_linkced(EditPageNum page);
    //aiTableview被双击后的SLOT
    void on_aiTableview_dbClicked(QModelIndex index);
    void on_diTableview_dbClicked(QModelIndex index);
    void on_doTableview_dbClicked(QModelIndex index);
    void on_spTableview_dbClicked(QModelIndex index);
    void on_manufTableview_dbClicked(QModelIndex index);

    //void on_aiTableview_dbClicked(QModelIndex index);
signals:
    void setAI_Edit_Info(SubProjectNameBean bean);
    void setDI_Edit_Info(SubProjectNameBean bean);
    void setDO_Edit_Info(SubProjectNameBean bean);
    void setSP_Edit_Info(SubProjectNameBean bean,EditPageNum page);


private slots:
    void on_confirmButton_clicked();
};

#endif // SUBPROJECTNAMETABLE_H
