/********************************************************************************
** Form generated from reading UI file 'serialport_editer.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SERIALPORT_EDITER_H
#define UI_SERIALPORT_EDITER_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QCheckBox>
#include <QtWidgets/QComboBox>
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

class Ui_SerialPort_Editer
{
public:
    QHBoxLayout *horizontalLayout_2;
    QGridLayout *gridLayout;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;
    QTabWidget *tabWidget;
    QWidget *BaseTab;
    QGridLayout *gridLayout_2;
    QVBoxLayout *verticalLayout_2;
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
    QComboBox *ParityCBX;
    QLabel *label_6;
    QLabel *label_7;
    QComboBox *BaudRateCBX;
    QComboBox *StopBitCBX;
    QComboBox *DataBitsCBX;
    QLabel *label_8;
    QLabel *label_5;
    QGroupBox *groupBox_4;
    QLabel *label_4;
    QLineEdit *Protocol;
    QLineEdit *Manufacture;
    QLabel *label_20;
    QLineEdit *SlaveID;
    QLabel *label_9;
    QWidget *AlarmTab;
    QGridLayout *gridLayout_4;
    QVBoxLayout *verticalLayout;
    QGroupBox *groupBox_3;
    QCheckBox *EnableCBX;

    void setupUi(QDialog *SerialPort_Editer)
    {
        if (SerialPort_Editer->objectName().isEmpty())
            SerialPort_Editer->setObjectName(QStringLiteral("SerialPort_Editer"));
        SerialPort_Editer->resize(784, 587);
        horizontalLayout_2 = new QHBoxLayout(SerialPort_Editer);
        horizontalLayout_2->setObjectName(QStringLiteral("horizontalLayout_2"));
        gridLayout = new QGridLayout();
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ConfirmBtn = new QPushButton(SerialPort_Editer);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));

        horizontalLayout->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(SerialPort_Editer);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);

        tabWidget = new QTabWidget(SerialPort_Editer);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        BaseTab = new QWidget();
        BaseTab->setObjectName(QStringLiteral("BaseTab"));
        gridLayout_2 = new QGridLayout(BaseTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        verticalLayout_2 = new QVBoxLayout();
        verticalLayout_2->setObjectName(QStringLiteral("verticalLayout_2"));
        groupBox = new QGroupBox(BaseTab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        label = new QLabel(groupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(21, 20, 24, 16));
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

        verticalLayout_2->addWidget(groupBox);

        groupBox_2 = new QGroupBox(BaseTab);
        groupBox_2->setObjectName(QStringLiteral("groupBox_2"));
        ParityCBX = new QComboBox(groupBox_2);
        ParityCBX->setObjectName(QStringLiteral("ParityCBX"));
        ParityCBX->setGeometry(QRect(252, 37, 69, 20));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(198, 37, 48, 16));
        label_7 = new QLabel(groupBox_2);
        label_7->setObjectName(QStringLiteral("label_7"));
        label_7->setGeometry(QRect(21, 67, 36, 16));
        BaudRateCBX = new QComboBox(groupBox_2);
        BaudRateCBX->setObjectName(QStringLiteral("BaudRateCBX"));
        BaudRateCBX->setGeometry(QRect(63, 37, 69, 20));
        StopBitCBX = new QComboBox(groupBox_2);
        StopBitCBX->setObjectName(QStringLiteral("StopBitCBX"));
        StopBitCBX->setGeometry(QRect(250, 67, 69, 20));
        DataBitsCBX = new QComboBox(groupBox_2);
        DataBitsCBX->setObjectName(QStringLiteral("DataBitsCBX"));
        DataBitsCBX->setGeometry(QRect(63, 67, 69, 20));
        label_8 = new QLabel(groupBox_2);
        label_8->setObjectName(QStringLiteral("label_8"));
        label_8->setGeometry(QRect(21, 37, 36, 16));
        label_5 = new QLabel(groupBox_2);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(198, 67, 36, 16));

        verticalLayout_2->addWidget(groupBox_2);

        groupBox_4 = new QGroupBox(BaseTab);
        groupBox_4->setObjectName(QStringLiteral("groupBox_4"));
        label_4 = new QLabel(groupBox_4);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(250, 40, 41, 16));
        Protocol = new QLineEdit(groupBox_4);
        Protocol->setObjectName(QStringLiteral("Protocol"));
        Protocol->setGeometry(QRect(310, 90, 90, 20));
        Manufacture = new QLineEdit(groupBox_4);
        Manufacture->setObjectName(QStringLiteral("Manufacture"));
        Manufacture->setGeometry(QRect(310, 40, 90, 20));
        label_20 = new QLabel(groupBox_4);
        label_20->setObjectName(QStringLiteral("label_20"));
        label_20->setGeometry(QRect(250, 90, 51, 16));
        SlaveID = new QLineEdit(groupBox_4);
        SlaveID->setObjectName(QStringLiteral("SlaveID"));
        SlaveID->setGeometry(QRect(80, 40, 90, 20));
        label_9 = new QLabel(groupBox_4);
        label_9->setObjectName(QStringLiteral("label_9"));
        label_9->setGeometry(QRect(20, 40, 51, 16));

        verticalLayout_2->addWidget(groupBox_4);


        gridLayout_2->addLayout(verticalLayout_2, 0, 0, 1, 1);

        tabWidget->addTab(BaseTab, QString());
        AlarmTab = new QWidget();
        AlarmTab->setObjectName(QStringLiteral("AlarmTab"));
        gridLayout_4 = new QGridLayout(AlarmTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        groupBox_3 = new QGroupBox(AlarmTab);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        EnableCBX = new QCheckBox(groupBox_3);
        EnableCBX->setObjectName(QStringLiteral("EnableCBX"));
        EnableCBX->setGeometry(QRect(10, 50, 59, 16));

        verticalLayout->addWidget(groupBox_3);


        gridLayout_4->addLayout(verticalLayout, 0, 0, 1, 1);

        tabWidget->addTab(AlarmTab, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);


        horizontalLayout_2->addLayout(gridLayout);


        retranslateUi(SerialPort_Editer);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(SerialPort_Editer);
    } // setupUi

    void retranslateUi(QDialog *SerialPort_Editer)
    {
        SerialPort_Editer->setWindowTitle(QApplication::translate("SerialPort_Editer", "Dialog", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("SerialPort_Editer", "\347\241\256\350\256\244", Q_NULLPTR));
        CancelBtn->setText(QApplication::translate("SerialPort_Editer", "\345\217\226\346\266\210", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("SerialPort_Editer", "\351\200\232\351\201\223", Q_NULLPTR));
        label_2->setText(QApplication::translate("SerialPort_Editer", "\345\271\263\345\217\260ID", Q_NULLPTR));
        label_17->setText(QApplication::translate("SerialPort_Editer", "\347\202\271\344\275\215\345\220\215", Q_NULLPTR));
        label_18->setText(QApplication::translate("SerialPort_Editer", "\345\210\206\351\241\271\347\274\226\345\217\267", Q_NULLPTR));
        Linklable->setText(QApplication::translate("SerialPort_Editer", "\350\216\267\345\217\226\345\271\263\345\217\260\345\217\202\346\225\260", Q_NULLPTR));
        groupBox_2->setTitle(QApplication::translate("SerialPort_Editer", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        label_6->setText(QApplication::translate("SerialPort_Editer", "\345\245\207\345\201\266\346\240\241\351\252\214", Q_NULLPTR));
        label_7->setText(QApplication::translate("SerialPort_Editer", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_8->setText(QApplication::translate("SerialPort_Editer", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label_5->setText(QApplication::translate("SerialPort_Editer", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        groupBox_4->setTitle(QApplication::translate("SerialPort_Editer", "\346\265\201\351\207\217\350\256\241", Q_NULLPTR));
        label_4->setText(QApplication::translate("SerialPort_Editer", "\345\216\202\345\256\266", Q_NULLPTR));
        label_20->setText(QApplication::translate("SerialPort_Editer", "\345\215\217\350\256\256\347\261\273\345\236\213", Q_NULLPTR));
        label_9->setText(QApplication::translate("SerialPort_Editer", "\350\212\202\347\202\271\345\234\260\345\235\200", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(BaseTab), QApplication::translate("SerialPort_Editer", "Tab 1", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("SerialPort_Editer", "\346\212\245\350\255\246\345\274\200\345\205\263", Q_NULLPTR));
        EnableCBX->setText(QApplication::translate("SerialPort_Editer", "ENABLE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(AlarmTab), QApplication::translate("SerialPort_Editer", "Tab 2", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SerialPort_Editer: public Ui_SerialPort_Editer {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SERIALPORT_EDITER_H
