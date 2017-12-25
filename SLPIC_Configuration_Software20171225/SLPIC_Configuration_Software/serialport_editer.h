#ifndef SERIALPORT_EDITER_H
#define SERIALPORT_EDITER_H

#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include <QMessageBox>
#include "database/serialport_information_bean.h"

namespace Ui {
class SerialPort_Editer;
}

class SerialPort_Editer : public QDialog
{
    Q_OBJECT

public:
    enum Parity{
        None=0,
        Odd=1,
        Even=2

    };

    explicit SerialPort_Editer(QWidget *parent = 0);
    ~SerialPort_Editer();

    dword BaudeRateValue() ;
    void setBaudeRateValue(const dword &BaudeRateValue);


    byte DataBitsValue();
    void setDataBitsValue(const byte &DataBitsValue);

    byte ParityValue() ;
    void setParityValue(const byte &ParityValue);

    byte StopBitValue() ;
    void setStopBitValue(const byte &StopBitValue);
signals:
    void Edit_Triggle(EditPageNum pageNum);
private:
    void InitUi();
    void InitBaseTab();
    void InitAlarmTab();

private:
    Ui::SerialPort_Editer *ui;
    SLPIC_DataBase m_DataBase;
    EditAttribute m_Attribute;//获取窗体自身的属性
    dword m_BaudeRateValue;
    byte m_DataBitsValue;
    byte m_ParityValue;
    byte m_StopBitValue;
private slots:
     void On_SerialPort_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
     //void on_ConfirmBtn_clicked();


     void on_ConfirmBtn_clicked();
     void on_CancelBtn_clicked();
};

#endif // SERIALPORT_EDITER_H
