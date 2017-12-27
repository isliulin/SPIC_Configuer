#ifndef AI_EDIT_H
#define AI_EDIT_H

#include <QDialog>
#include <QCheckBox>
#include "common/commonhead.h"
#include <QString>
#include <QStringList>
#include "database/slpic_database.h"
#include "subprojectnametable.h"

namespace Ui {
class AI_Edit;
}

class AI_Edit : public QDialog
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
    explicit AI_Edit(QWidget *parent = 0);
    ~AI_Edit();
public:
    EditAttribute m_Attribute;//获取窗体自身的属性
public:
    //接收系统配置信息所在窗体的指针。以便用来可视化设置
    void getSubProjectNameTable(SubProjectNameTable *pSubProjectNameTable);
private slots:
    void on_ConfirmBtn_clicked();
    void on_linkActivated(QString s);

    void on_CancelBtn_clicked();
    void on_setAI_Edit_Info(SubProjectNameBean bean);

public slots:
    void On_AI_Table_DoubleClick_trigger(QStringList items,EditAttribute attribute,QString databasePath);

private:
    void InitUi();
    void InitH_ALM();
    void InitHH_ALM();
    void InitL_ALM();
    void InitLL_ALM();
    void InitRelaventTab();
    void InitBaseTab();
    void InitAlarmTab();
    //void ClearText();

    AlarmToRelevant m_H_Relevant;
    AlarmToRelevant m_HH_Relevant;
    AlarmToRelevant m_L_Relevant;
    AlarmToRelevant m_LL_Relevant;
    SLPIC_DataBase m_DataBase;
    SubProjectNameTable *m_pSubProjectNameTable;
private:
    void InitRelevantValue();

private:
    Ui::AI_Edit *ui;

signals:
    void Edit_Triggle(EditPageNum pageNum);
    //通知系统配置信息窗口，此时要获取哪个类型的数据：例如AI配置信息
    void linkSubProjectName(EditPageNum pageNum);


};

#endif // AI_EDIT_H
