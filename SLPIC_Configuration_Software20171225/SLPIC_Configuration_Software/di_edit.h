#ifndef DI_EDIT_H
#define DI_EDIT_H


#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include <QMessageBox>
namespace Ui {
class DI_Edit;
}

class DI_Edit : public QDialog
{
    Q_OBJECT

public:
    class AlarmToRelevant
    {
    public:
        AlarmToRelevant(QList<QCheckBox *>pCheckBox){
            setPCheckBox(pCheckBox);


        }
        AlarmToRelevant(){}
        ~AlarmToRelevant(){

            while (!m_pCheckBox.isEmpty()) {
                delete m_pCheckBox.takeFirst();

            }

        }

        dword m_AlarmtRelevantValue;
        QList<QCheckBox *>m_pCheckBox;


        void setPCheckBox(const QList<QCheckBox *> &pCheckBox)
        {
            m_pCheckBox = pCheckBox;
        }


        dword AlarmtRelevantValue()
        {
            //解析 qcheckbox组的checkstate
             m_AlarmtRelevantValue=0;
            for(int i=0;i<m_pCheckBox.length();i++)
            {

                int current=m_pCheckBox[i]->isChecked();
                m_AlarmtRelevantValue|=0x00|(current<<i);
            }
            return m_AlarmtRelevantValue;
        }

    public :
        void setAlarmtRelevantValue(const dword &AlarmtRelevantValue)
        {
            m_AlarmtRelevantValue = AlarmtRelevantValue;
            for(int i=0;i<m_pCheckBox.length();i++)
            {
                m_pCheckBox[i]->setChecked(false);
            }
            for(int i=0;i<m_pCheckBox.length();i++)
            {
                if((m_AlarmtRelevantValue>>i)&0x1)
                {
                    m_pCheckBox[i]->setChecked(true);
                }
            }

        }

    };
    explicit DI_Edit(QWidget *parent = 0);
    ~DI_Edit();
public:
    EditAttribute m_Attribute;//获取窗体自身的属性
private:
    Ui::DI_Edit *ui;
    void InitRelevantValue();
    void InitBaseTab();
    void InitAlarmTab();

    void InitUi();

    AlarmToRelevant m_DI_Relevant;
    SLPIC_DataBase m_DataBase;

signals:
    void Edit_Triggle(EditPageNum pageNum);
private slots:
    void on_ConfirmBtn_clicked();
    void On_DI_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);
};

#endif // DI_EDIT_H
