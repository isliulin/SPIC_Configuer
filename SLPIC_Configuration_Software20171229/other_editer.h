#ifndef OTHER_EDITER_H
#define OTHER_EDITER_H

#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include <QMessageBox>
#include "database/other_information_bean.h"
#include <QLineEdit>
#include <QList>
#include "common/xconvert.h"
#include <QDateTime>

namespace Ui {
class Other_Editer;
}

class Other_Editer : public QDialog
{
    Q_OBJECT

public:

    class InputLineEditers
    {
    public:
        InputLineEditers() {}
        ~InputLineEditers() {

            while (!m_pLineEditers.isEmpty()) {
                delete m_pLineEditers.takeFirst();

            }
        }

        void setPLineEditers(const QList<QLineEdit *> &pLineEditers)
        {
            m_pLineEditers = pLineEditers;
        }



        qulonglong Value()
        {
            m_Value=0;
            qulonglong temp=0;
            qulonglong bcd=0;
            for(int i=0;i<m_pLineEditers.length();i++)
            {


                bcd=Xconvert::DectoBCD((quint8)(m_pLineEditers.at(i)->text().toUInt()));
                temp=bcd<<(i*8);
                m_Value|=temp;

            }

            return m_Value;
        }




        void setValue(const qulonglong &Value)
        {
            quint8 temp=0;
            quint8 dec=0;
            for(int i=0;i<m_pLineEditers.length();i++)
            {
                temp=(Value>>(i*8))&0xff;
                dec=Xconvert::BCDtoDec(temp);

                //
                m_pLineEditers.at(i)->setText(QString::number(dec,10));

            }

            m_Value = Value;
        }
        void setDecValue(const quint8 *array)
        {
            quint8 temp=0;


            for(int i=0;i<m_pLineEditers.length();i++)
            {
                temp=*(array+i);


                m_pLineEditers.at(i)->setText(QString::number(temp,10));

            }

        }


    private:
        qulonglong m_Value;
        //7个 lineediter
        QList<QLineEdit*> m_pLineEditers;
    };
    explicit Other_Editer(QWidget *parent = 0);
    ~Other_Editer();

    qulonglong DeviceIdValue() ;
    void setDeviceIdValue(const qulonglong &DeviceIdValue);

    qulonglong pRtcTimerValue() const;
    void setPRtcTimerValue(const qulonglong &pRtcTimerValue);

private:
    Ui::Other_Editer *ui;
    SLPIC_DataBase m_DataBase;
    EditAttribute m_Attribute;//获取窗体自身的属性
//    QList<QLineEdit*> m_pDeviceIdLineEditers;
//    QList<QLineEdit*> m_pRtcTimerLineEditers;
//    qulonglong m_DeviceIdValue;
//    qulonglong m_pRtcTimerValue;
    InputLineEditers m_DeviceId;
    InputLineEditers m_RtcTimer;

private:
    void InitUi();
    void InitBaseTab();
    void InitSystemTab();
    void InitDeviceIdLineEditers();
    //void InitRtcTimerLineEditers();
    bool CheckIp(const QString &ip);
    void DateTimeToArray(const QDateTime &dt, quint8 *array);

    //datetimeedit---->database
    qulonglong DtEditToDataBaseValue();

    //datetimeedit<----database
    void DataBaseToDtEditValue(qulonglong value,QDateTimeEdit *dtEdit);


signals:
    void Edit_Triggle(EditPageNum pageNum);
private slots:
    void On_Other_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);

    void on_ConfirmBtn_clicked();
    void on_CancelBtn_clicked();
    void on_getPC_TimeBtn_clicked();
    void on_linkActivated(QString s);
public:
    void getSysInfo(QMap<int,QString> commProtocol,QMap<int,QString> commWay);

private:
    QMap<int, QString> m_mapCommProtocol;
    QMap<int, QString> m_mapcommWay;
};

#endif // OTHER_EDITER_H
