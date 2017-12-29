#ifndef DO_EDITER_H
#define DO_EDITER_H

#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include <QMessageBox>
#include "subprojectnametable.h"
namespace Ui {
class DO_Editer;
}

class DO_Editer : public QDialog
{
    Q_OBJECT

public:
    explicit DO_Editer(QWidget *parent = 0);
    ~DO_Editer();
signals:
    void Edit_Triggle(EditPageNum pageNum);
    //通知系统配置信息窗口，此时要获取哪个类型的数据：例如AI配置信息
    void linkSubProjectName(EditPageNum pageNum);
private:
    void InitUi();

    void InitBaseTab();
    void InitAlarmTab();
public:
    //获取系统配置信息窗口的指针
    void getSubProjectNameTable(SubProjectNameTable *pSubProjectNameTable);


private:
    Ui::DO_Editer *ui;
    SLPIC_DataBase m_DataBase;
    EditAttribute m_Attribute;//获取窗体自身的属性

    SubProjectNameTable* m_pSubProjectNameTable;

    qulonglong m_DeviceId;
private slots:
     void On_DO_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
     void on_ConfirmBtn_clicked();

     void on_linkActivated(QString s);

     void on_setDO_Edit_Info(SubProjectNameBean bean);
};

#endif // DO_EDITER_H
