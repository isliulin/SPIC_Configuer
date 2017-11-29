#ifndef DO_EDITER_H
#define DO_EDITER_H

#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include <QMessageBox>

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
private:
    void InitUi();

    void InitBaseTab();
    void InitAlarmTab();


private:
    Ui::DO_Editer *ui;
    SLPIC_DataBase m_DataBase;
    EditAttribute m_Attribute;//获取窗体自身的属性

    qulonglong m_DeviceId;
private slots:
     void On_DO_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
     void on_ConfirmBtn_clicked();
};

#endif // DO_EDITER_H
