/********************************************************************************
** Form generated from reading UI file 'other_editer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_OTHER_EDITER_H
#define UI_OTHER_EDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDateTimeEdit>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Other_Editer
{
public:
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;
    QTabWidget *tabWidget;
    QWidget *BaseTab;
    QGridLayout *gridLayout_2;
    QGridLayout *gridLayout_5;
    QGroupBox *groupBox;
    QLabel *label;
    QComboBox *ChannelCBX;
    QLabel *label_2;
    QLineEdit *SubPrjNameID;
    QLineEdit *SubPrjName;
    QLabel *label_17;
    QLineEdit *SubPrjNum;
    QLabel *label_18;
    QLabel *Linklable;
    QGroupBox *groupBox_2;
    QLabel *label_11;
    QLineEdit *IP_Address;
    QLabel *label_12;
    QLineEdit *ServerPortNum;
    QLineEdit *RetryCount;
    QLabel *label_13;
    QLineEdit *RetryInternal;
    QLabel *label_14;
    QLineEdit *HeartInternal;
    QLabel *label_15;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QLineEdit *StationID;
    QLabel *label_9;
    QWidget *layoutWidget;
    QHBoxLayout *horizontalLayout_2;
    QLineEdit *DeviceID7;
    QLineEdit *DeviceID6;
    QLineEdit *DeviceID5;
    QLineEdit *DeviceID4;
    QLineEdit *DeviceID3;
    QLineEdit *DeviceID2;
    QLineEdit *DeviceID1;
    QWidget *SysTab;
    QGridLayout *gridLayout_3;
    QGridLayout *gridLayout_6;
    QGroupBox *groupBox_5;
    QGridLayout *gridLayout_4;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLabel *label_8;
    QLabel *label_25;
    QLabel *label_26;
    QLabel *label_27;
    QLineEdit *Density;
    QLabel *label_28;
    QPushButton *getPC_TimeBtn;
    QWidget *layoutWidget1;
    QVBoxLayout *verticalLayout;
    QComboBox *CommProtocol;
    QComboBox *CommWay;
    QComboBox *GPRS_Pass_Mode;
    QComboBox *SystemRestart;
    QDateTimeEdit *dateTimeEdit;
    QLineEdit *lastVolumeText;
    QLabel *lastVolumeLbl;

    void setupUi(QDialog *Other_Editer)
    {
        if (Other_Editer->objectName().isEmpty())
            Other_Editer->setObjectName(QStringLiteral("Other_Editer"));
        Other_Editer->resize(806, 571);
        gridLayout = new QGridLayout(Other_Editer);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ConfirmBtn = new QPushButton(Other_Editer);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));

        horizontalLayout->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(Other_Editer);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tabWidget = new QTabWidget(Other_Editer);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        BaseTab = new QWidget();
        BaseTab->setObjectName(QStringLiteral("BaseTab"));
        gridLayout_2 = new QGridLayout(BaseTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        gridLayout_5 = new QGridLayout();
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        groupBox = new QGroupBox(BaseTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 30, 24, 16));
        ChannelCBX = new QComboBox(groupBox);
        ChannelCBX->setObjectName(QStringLiteral("ChannelCBX"));
        ChannelCBX->setGeometry(QRect(102, 21, 69, 20));
        label_2 = new QLabel(groupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(21, 60, 41, 16));
        SubPrjNameID = new QLineEdit(groupBox);
        SubPrjNameID->setObjectName(QStringLiteral("SubPrjNameID"));
        SubPrjNameID->setGeometry(QRect(101, 60, 133, 20));
        SubPrjName = new QLineEdit(groupBox);
        SubPrjName->setObjectName(QStringLiteral("SubPrjName"));
        SubPrjName->setGeometry(QRect(101, 90, 133, 20));
        label_17 = new QLabel(groupBox);
        label_17->setObjectName(QStringLiteral("label_17"));
        label_17->setGeometry(QRect(21, 90, 41, 16));
        SubPrjNum = new QLineEdit(groupBox);
        SubPrjNum->setObjectName(QStringLiteral("SubPrjNum"));
        SubPrjNum->setGeometry(QRect(100, 120, 133, 20));
        label_18 = new QLabel(groupBox);
        label_18->setObjectName(QStringLiteral("label_18"));
        label_18->setGeometry(QRect(20, 120, 51, 16));
        Linklable = new QLabel(groupBox);
        Linklable->setObjectName(QStringLiteral("Linklable"));
        Linklable->setGeometry(QRect(260, 90, 91, 16));

        gridLayout_5->addWidget(groupBox, 0, 0, 1, 1);

        groupBox_2 = new QGroupBox(BaseTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        label_11 = new QLabel(groupBox_2);
        label_11->setObjectName(QStringLiteral("label_11"));
        label_11->setGeometry(QRect(20, 30, 71, 16));
        IP_Address = new QLineEdit(groupBox_2);
        IP_Address->setObjectName(QStringLiteral("IP_Address"));
        IP_Address->setGeometry(QRect(110, 30, 371, 20));
        label_12 = new QLabel(groupBox_2);
        label_12->setObjectName(QStringLiteral("label_12"));
        label_12->setGeometry(QRect(20, 70, 71, 16));
        ServerPortNum = new QLineEdit(groupBox_2);
        ServerPortNum->setObjectName(QStringLiteral("ServerPortNum"));
        ServerPortNum->setGeometry(QRect(20, 90, 51, 20));
        RetryCount = new QLineEdit(groupBox_2);
        RetryCount->setObjectName(QStringLiteral("RetryCount"));
        RetryCount->setGeometry(QRect(140, 90, 51, 20));
        label_13 = new QLabel(groupBox_2);
        label_13->setObjectName(QStringLiteral("label_13"));
        label_13->setGeometry(QRect(140, 70, 71, 16));
        RetryInternal = new QLineEdit(groupBox_2);
        RetryInternal->setObjectName(QStringLiteral("RetryInternal"));
        RetryInternal->setGeometry(QRect(250, 90, 51, 20));
        label_14 = new QLabel(groupBox_2);
        label_14->setObjectName(QStringLiteral("label_14"));
        label_14->setGeometry(QRect(250, 70, 71, 16));
        HeartInternal = new QLineEdit(groupBox_2);
        HeartInternal->setObjectName(QStringLiteral("HeartInternal"));
        HeartInternal->setGeometry(QRect(360, 90, 51, 20));
        label_15 = new QLabel(groupBox_2);
        label_15->setObjectName(QStringLiteral("label_15"));
        label_15->setGeometry(QRect(360, 70, 71, 16));

        gridLayout_5->addWidget(groupBox_2, 1, 0, 1, 1);

        groupBox_4 = new QGroupBox(BaseTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(20, 100, 51, 16));
        StationID = new QLineEdit(groupBox_4);
        StationID->setObjectName(QStringLiteral("StationID"));
        StationID->setGeometry(QRect(110, 100, 90, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 40, 51, 16));
        layoutWidget = new QWidget(groupBox_4);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(110, 36, 351, 24));
        horizontalLayout_2 = new QHBoxLayout(layoutWidget);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        horizontalLayout_2->setContentsMargins(0, 0, 0, 0);
        DeviceID7 = new QLineEdit(layoutWidget);
        DeviceID7->setObjectName(QStringLiteral("DeviceID7"));

        horizontalLayout_2->addWidget(DeviceID7);

        DeviceID6 = new QLineEdit(layoutWidget);
        DeviceID6->setObjectName(QStringLiteral("DeviceID6"));

        horizontalLayout_2->addWidget(DeviceID6);

        DeviceID5 = new QLineEdit(layoutWidget);
        DeviceID5->setObjectName(QStringLiteral("DeviceID5"));

        horizontalLayout_2->addWidget(DeviceID5);

        DeviceID4 = new QLineEdit(layoutWidget);
        DeviceID4->setObjectName(QStringLiteral("DeviceID4"));

        horizontalLayout_2->addWidget(DeviceID4);

        DeviceID3 = new QLineEdit(layoutWidget);
        DeviceID3->setObjectName(QStringLiteral("DeviceID3"));

        horizontalLayout_2->addWidget(DeviceID3);

        DeviceID2 = new QLineEdit(layoutWidget);
        DeviceID2->setObjectName(QStringLiteral("DeviceID2"));

        horizontalLayout_2->addWidget(DeviceID2);

        DeviceID1 = new QLineEdit(layoutWidget);
        DeviceID1->setObjectName(QStringLiteral("DeviceID1"));

        horizontalLayout_2->addWidget(DeviceID1);


        gridLayout_5->addWidget(groupBox_4, 2, 0, 1, 1);


        gridLayout_2->addLayout(gridLayout_5, 0, 0, 1, 1);

        tabWidget->addTab(BaseTab, QString());
        SysTab = new QWidget();
        SysTab->setObjectName(QStringLiteral("SysTab"));
        gridLayout_3 = new QGridLayout(SysTab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        gridLayout_6 = new QGridLayout();
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        groupBox_5 = new QGroupBox(SysTab);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        gridLayout_4 = new QGridLayout(groupBox_5);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        groupBox_3 = new QGroupBox(groupBox_5);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(30, 30, 61, 16));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(30, 60, 61, 16));
        label_25 = new QLabel(groupBox_3);
        label_25->setObjectName(QStringLiteral("label_25"));
        label_25->setGeometry(QRect(30, 190, 51, 16));
        label_26 = new QLabel(groupBox_3);
        label_26->setObjectName(QStringLiteral("label_26"));
        label_26->setGeometry(QRect(30, 90, 81, 16));
        label_27 = new QLabel(groupBox_3);
        label_27->setObjectName(QStringLiteral("label_27"));
        label_27->setGeometry(QRect(30, 150, 81, 16));
        Density = new QLineEdit(groupBox_3);
        Density->setObjectName(QStringLiteral("Density"));
        Density->setGeometry(QRect(120, 150, 90, 20));
        label_28 = new QLabel(groupBox_3);
        label_28->setObjectName(QStringLiteral("label_28"));
        label_28->setGeometry(QRect(30, 120, 81, 16));
        getPC_TimeBtn = new QPushButton(groupBox_3);
        getPC_TimeBtn->setObjectName(QStringLiteral("getPC_TimeBtn"));
        getPC_TimeBtn->setGeometry(QRect(340, 180, 81, 23));
        layoutWidget1 = new QWidget(groupBox_3);
        layoutWidget1->setObjectName(QStringLiteral("layoutWidget1"));
        layoutWidget1->setGeometry(QRect(120, 30, 121, 108));
        verticalLayout = new QVBoxLayout(layoutWidget1);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        CommProtocol = new QComboBox(layoutWidget1);
        CommProtocol->setObjectName(QStringLiteral("CommProtocol"));

        verticalLayout->addWidget(CommProtocol);

        CommWay = new QComboBox(layoutWidget1);
        CommWay->setObjectName(QStringLiteral("CommWay"));

        verticalLayout->addWidget(CommWay);

        GPRS_Pass_Mode = new QComboBox(layoutWidget1);
        GPRS_Pass_Mode->setObjectName(QStringLiteral("GPRS_Pass_Mode"));

        verticalLayout->addWidget(GPRS_Pass_Mode);

        SystemRestart = new QComboBox(layoutWidget1);
        SystemRestart->setObjectName(QStringLiteral("SystemRestart"));

        verticalLayout->addWidget(SystemRestart);

        dateTimeEdit = new QDateTimeEdit(groupBox_3);
        dateTimeEdit->setObjectName(QStringLiteral("dateTimeEdit"));
        dateTimeEdit->setGeometry(QRect(120, 180, 201, 31));
        lastVolumeText = new QLineEdit(groupBox_3);
        lastVolumeText->setObjectName(QStringLiteral("lastVolumeText"));
        lastVolumeText->setGeometry(QRect(120, 230, 90, 20));
        lastVolumeLbl = new QLabel(groupBox_3);
        lastVolumeLbl->setObjectName(QStringLiteral("lastVolumeLbl"));
        lastVolumeLbl->setGeometry(QRect(30, 230, 61, 16));

        gridLayout_4->addWidget(groupBox_3, 0, 0, 1, 1);


        gridLayout_6->addWidget(groupBox_5, 0, 0, 1, 1);


        gridLayout_3->addLayout(gridLayout_6, 0, 0, 1, 1);

        tabWidget->addTab(SysTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        retranslateUi(Other_Editer);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Other_Editer);
    } // setupUi

    void retranslateUi(QDialog *Other_Editer)
    {
        Other_Editer->setWindowTitle(QApplication::translate("Other_Editer", "Dialog", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("Other_Editer", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelBtn->setText(QApplication::translate("Other_Editer", "\345\217\226\346\266\210", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("Other_Editer", "\351\200\232\351\201\223", Q_NULLPTR));
        label_2->setText(QApplication::translate("Other_Editer", "\345\271\263\345\217\260ID", Q_NULLPTR));
        label_17->setText(QApplication::translate("Other_Editer", "\347\202\271\344\275\215\345\220\215", Q_NULLPTR));
        label_18->setText(QApplication::translate("Other_Editer", "\345\210\206\351\241\271\347\274\226\345\217\267", Q_NULLPTR));
        Linklable->setText(QApplication::translate("Other_Editer", "\350\216\267\345\217\226\345\271\263\345\217\260\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("Other_Editer", "\347\275\221\347\273\234\350\256\276\347\275\256", Q_NULLPTR));
        label_11->setText(QApplication::translate("Other_Editer", "IP Address", Q_NULLPTR));
        IP_Address->setText(QApplication::translate("Other_Editer", "127.0.0.1", Q_NULLPTR));
        label_12->setText(QApplication::translate("Other_Editer", "Server Port", Q_NULLPTR));
        ServerPortNum->setText(QApplication::translate("Other_Editer", "502", Q_NULLPTR));
        RetryCount->setText(QApplication::translate("Other_Editer", "2", Q_NULLPTR));
        label_13->setText(QApplication::translate("Other_Editer", "\351\207\215\345\217\221\346\254\241\346\225\260", Q_NULLPTR));
        RetryInternal->setText(QApplication::translate("Other_Editer", "2", Q_NULLPTR));
        label_14->setText(QApplication::translate("Other_Editer", "\351\207\215\345\217\221\351\227\264\351\232\224(s)", Q_NULLPTR));
        HeartInternal->setText(QApplication::translate("Other_Editer", "1", Q_NULLPTR));
        label_15->setText(QApplication::translate("Other_Editer", "\345\277\203\350\267\263\351\227\264\351\232\224(s)", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("Other_Editer", "\350\256\276\345\244\207\344\277\241\346\201\257", Q_NULLPTR));
        label_4->setText(QApplication::translate("Other_Editer", "\347\253\231\347\202\271\347\274\226\345\217\267", Q_NULLPTR));
        label_9->setText(QApplication::translate("Other_Editer", "\350\256\276\345\244\207\347\274\226\345\217\267", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(BaseTab), QApplication::translate("Other_Editer", "Tab 1", Q_NULLPTR));
        groupBox_5->setTitle(QString());
        groupBox_3->setTitle(QApplication::translate("Other_Editer", "\347\263\273\347\273\237", Q_NULLPTR));
        label_7->setText(QApplication::translate("Other_Editer", "\351\200\232\344\277\241\345\215\217\350\256\256", Q_NULLPTR));
        label_8->setText(QApplication::translate("Other_Editer", "\351\200\232\344\277\241\346\226\271\345\274\217", Q_NULLPTR));
        label_25->setText(QApplication::translate("Other_Editer", "RTC\346\227\266\351\222\237", Q_NULLPTR));
        label_26->setText(QApplication::translate("Other_Editer", "GPRS\344\274\240\350\276\223\346\250\241\345\274\217", Q_NULLPTR));
        label_27->setText(QApplication::translate("Other_Editer", "\345\257\206\345\272\246", Q_NULLPTR));
        Density->setText(QApplication::translate("Other_Editer", "426.00", Q_NULLPTR));
        label_28->setText(QApplication::translate("Other_Editer", "\351\207\215\345\220\257", Q_NULLPTR));
        getPC_TimeBtn->setText(QApplication::translate("Other_Editer", "\350\216\267\345\217\226PC\346\227\266\351\227\264", Q_NULLPTR));
        dateTimeEdit->setDisplayFormat(QApplication::translate("Other_Editer", "yyyy/MM/dd HH:mm:ss", Q_NULLPTR));
        lastVolumeText->setText(QApplication::translate("Other_Editer", "426.00", Q_NULLPTR));
        lastVolumeLbl->setText(QApplication::translate("Other_Editer", "\345\215\241\346\216\247\345\211\251\344\275\231\351\207\217", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(SysTab), QApplication::translate("Other_Editer", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Other_Editer: public Ui_Other_Editer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_OTHER_EDITER_H
