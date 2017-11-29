/********************************************************************************
** Form generated from reading UI file 'di_edit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DI_EDIT_H
#define UI_DI_EDIT_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_DI_Edit
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *tab;
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
    QWidget *tab_2;
    QGroupBox *groupBox_3;
    QCheckBox *EnableCBX;
    QWidget *tab_5;
    QGroupBox *groupBox_5;
    QWidget *layoutWidget;
    QHBoxLayout *DI_DO_OUT_Layout;
    QCheckBox *DI_DO1_OUT;
    QCheckBox *DI_DO2_OUT;
    QCheckBox *DI_DO3_OUT;
    QCheckBox *DI_DO4_OUT;
    QCheckBox *DI_DO5_OUT;
    QCheckBox *DI_DO6_OUT;
    QCheckBox *DI_DO7_OUT;
    QCheckBox *DI_DO8_OUT;
    QCheckBox *DI_DO9_OUT;
    QCheckBox *DI_DO10_OUT;
    QCheckBox *DI_DO11_OUT;
    QCheckBox *DI_DO12_OUT;
    QCheckBox *DI_DO13_OUT;
    QCheckBox *DI_DO14_OUT;
    QCheckBox *DI_DO15_OUT;
    QCheckBox *DI_DO16_OUT;
    QWidget *layoutWidget_2;
    QHBoxLayout *DI_DO_ENB_Layout;
    QCheckBox *DI_DO1_ENB;
    QCheckBox *DI_DO2_ENB;
    QCheckBox *DI_DO3_ENB;
    QCheckBox *DI_DO4_ENB;
    QCheckBox *DI_DO5_ENB;
    QCheckBox *DI_DO6_ENB;
    QCheckBox *DI_DO7_ENB;
    QCheckBox *DI_DO8_ENB;
    QCheckBox *DI_DO9_ENB;
    QCheckBox *DI_DO10_ENB;
    QCheckBox *DI_DO11_ENB;
    QCheckBox *DI_DO12_ENB;
    QCheckBox *DI_DO13_ENB;
    QCheckBox *DI_DO14_ENB;
    QCheckBox *DI_DO15_ENB;
    QCheckBox *DI_DO16_ENB;
    QLabel *label_10;
    QLabel *label_3;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;

    void setupUi(QDialog *DI_Edit)
    {
        if (DI_Edit->objectName().isEmpty())
            DI_Edit->setObjectName(QStringLiteral("DI_Edit"));
        DI_Edit->resize(801, 455);
        gridLayout = new QGridLayout(DI_Edit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(DI_Edit);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        tab = new QWidget();
        tab->setObjectName(QStringLiteral("tab"));
        groupBox = new QGroupBox(tab);
        groupBox->setObjectName(QStringLiteral("groupBox"));
        groupBox->setGeometry(QRect(10, 20, 727, 161));
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
        tabWidget->addTab(tab, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        groupBox_3 = new QGroupBox(tab_2);
        groupBox_3->setObjectName(QStringLiteral("groupBox_3"));
        groupBox_3->setGeometry(QRect(10, 20, 725, 186));
        EnableCBX = new QCheckBox(groupBox_3);
        EnableCBX->setObjectName(QStringLiteral("EnableCBX"));
        EnableCBX->setGeometry(QRect(10, 20, 71, 16));
        tabWidget->addTab(tab_2, QString());
        tab_5 = new QWidget();
        tab_5->setObjectName(QStringLiteral("tab_5"));
        groupBox_5 = new QGroupBox(tab_5);
        groupBox_5->setObjectName(QStringLiteral("groupBox_5"));
        groupBox_5->setGeometry(QRect(10, 20, 711, 81));
        layoutWidget = new QWidget(groupBox_5);
        layoutWidget->setObjectName(QStringLiteral("layoutWidget"));
        layoutWidget->setGeometry(QRect(100, 44, 598, 18));
        DI_DO_OUT_Layout = new QHBoxLayout(layoutWidget);
        DI_DO_OUT_Layout->setObjectName(QStringLiteral("DI_DO_OUT_Layout"));
        DI_DO_OUT_Layout->setContentsMargins(0, 0, 0, 0);
        DI_DO1_OUT = new QCheckBox(layoutWidget);
        DI_DO1_OUT->setObjectName(QStringLiteral("DI_DO1_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO1_OUT);

        DI_DO2_OUT = new QCheckBox(layoutWidget);
        DI_DO2_OUT->setObjectName(QStringLiteral("DI_DO2_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO2_OUT);

        DI_DO3_OUT = new QCheckBox(layoutWidget);
        DI_DO3_OUT->setObjectName(QStringLiteral("DI_DO3_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO3_OUT);

        DI_DO4_OUT = new QCheckBox(layoutWidget);
        DI_DO4_OUT->setObjectName(QStringLiteral("DI_DO4_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO4_OUT);

        DI_DO5_OUT = new QCheckBox(layoutWidget);
        DI_DO5_OUT->setObjectName(QStringLiteral("DI_DO5_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO5_OUT);

        DI_DO6_OUT = new QCheckBox(layoutWidget);
        DI_DO6_OUT->setObjectName(QStringLiteral("DI_DO6_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO6_OUT);

        DI_DO7_OUT = new QCheckBox(layoutWidget);
        DI_DO7_OUT->setObjectName(QStringLiteral("DI_DO7_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO7_OUT);

        DI_DO8_OUT = new QCheckBox(layoutWidget);
        DI_DO8_OUT->setObjectName(QStringLiteral("DI_DO8_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO8_OUT);

        DI_DO9_OUT = new QCheckBox(layoutWidget);
        DI_DO9_OUT->setObjectName(QStringLiteral("DI_DO9_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO9_OUT);

        DI_DO10_OUT = new QCheckBox(layoutWidget);
        DI_DO10_OUT->setObjectName(QStringLiteral("DI_DO10_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO10_OUT);

        DI_DO11_OUT = new QCheckBox(layoutWidget);
        DI_DO11_OUT->setObjectName(QStringLiteral("DI_DO11_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO11_OUT);

        DI_DO12_OUT = new QCheckBox(layoutWidget);
        DI_DO12_OUT->setObjectName(QStringLiteral("DI_DO12_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO12_OUT);

        DI_DO13_OUT = new QCheckBox(layoutWidget);
        DI_DO13_OUT->setObjectName(QStringLiteral("DI_DO13_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO13_OUT);

        DI_DO14_OUT = new QCheckBox(layoutWidget);
        DI_DO14_OUT->setObjectName(QStringLiteral("DI_DO14_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO14_OUT);

        DI_DO15_OUT = new QCheckBox(layoutWidget);
        DI_DO15_OUT->setObjectName(QStringLiteral("DI_DO15_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO15_OUT);

        DI_DO16_OUT = new QCheckBox(layoutWidget);
        DI_DO16_OUT->setObjectName(QStringLiteral("DI_DO16_OUT"));

        DI_DO_OUT_Layout->addWidget(DI_DO16_OUT);

        layoutWidget_2 = new QWidget(groupBox_5);
        layoutWidget_2->setObjectName(QStringLiteral("layoutWidget_2"));
        layoutWidget_2->setGeometry(QRect(100, 20, 598, 18));
        DI_DO_ENB_Layout = new QHBoxLayout(layoutWidget_2);
        DI_DO_ENB_Layout->setObjectName(QStringLiteral("DI_DO_ENB_Layout"));
        DI_DO_ENB_Layout->setContentsMargins(0, 0, 0, 0);
        DI_DO1_ENB = new QCheckBox(layoutWidget_2);
        DI_DO1_ENB->setObjectName(QStringLiteral("DI_DO1_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO1_ENB);

        DI_DO2_ENB = new QCheckBox(layoutWidget_2);
        DI_DO2_ENB->setObjectName(QStringLiteral("DI_DO2_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO2_ENB);

        DI_DO3_ENB = new QCheckBox(layoutWidget_2);
        DI_DO3_ENB->setObjectName(QStringLiteral("DI_DO3_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO3_ENB);

        DI_DO4_ENB = new QCheckBox(layoutWidget_2);
        DI_DO4_ENB->setObjectName(QStringLiteral("DI_DO4_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO4_ENB);

        DI_DO5_ENB = new QCheckBox(layoutWidget_2);
        DI_DO5_ENB->setObjectName(QStringLiteral("DI_DO5_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO5_ENB);

        DI_DO6_ENB = new QCheckBox(layoutWidget_2);
        DI_DO6_ENB->setObjectName(QStringLiteral("DI_DO6_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO6_ENB);

        DI_DO7_ENB = new QCheckBox(layoutWidget_2);
        DI_DO7_ENB->setObjectName(QStringLiteral("DI_DO7_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO7_ENB);

        DI_DO8_ENB = new QCheckBox(layoutWidget_2);
        DI_DO8_ENB->setObjectName(QStringLiteral("DI_DO8_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO8_ENB);

        DI_DO9_ENB = new QCheckBox(layoutWidget_2);
        DI_DO9_ENB->setObjectName(QStringLiteral("DI_DO9_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO9_ENB);

        DI_DO10_ENB = new QCheckBox(layoutWidget_2);
        DI_DO10_ENB->setObjectName(QStringLiteral("DI_DO10_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO10_ENB);

        DI_DO11_ENB = new QCheckBox(layoutWidget_2);
        DI_DO11_ENB->setObjectName(QStringLiteral("DI_DO11_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO11_ENB);

        DI_DO12_ENB = new QCheckBox(layoutWidget_2);
        DI_DO12_ENB->setObjectName(QStringLiteral("DI_DO12_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO12_ENB);

        DI_DO13_ENB = new QCheckBox(layoutWidget_2);
        DI_DO13_ENB->setObjectName(QStringLiteral("DI_DO13_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO13_ENB);

        DI_DO14_ENB = new QCheckBox(layoutWidget_2);
        DI_DO14_ENB->setObjectName(QStringLiteral("DI_DO14_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO14_ENB);

        DI_DO15_ENB = new QCheckBox(layoutWidget_2);
        DI_DO15_ENB->setObjectName(QStringLiteral("DI_DO15_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO15_ENB);

        DI_DO16_ENB = new QCheckBox(layoutWidget_2);
        DI_DO16_ENB->setObjectName(QStringLiteral("DI_DO16_ENB"));

        DI_DO_ENB_Layout->addWidget(DI_DO16_ENB);

        label_10 = new QLabel(groupBox_5);
        label_10->setObjectName(QStringLiteral("label_10"));
        label_10->setGeometry(QRect(20, 50, 54, 12));
        label_3 = new QLabel(groupBox_5);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(20, 20, 54, 12));
        tabWidget->addTab(tab_5, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ConfirmBtn = new QPushButton(DI_Edit);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));

        horizontalLayout->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(DI_Edit);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(DI_Edit);

        tabWidget->setCurrentIndex(2);


        QMetaObject::connectSlotsByName(DI_Edit);
    } // setupUi

    void retranslateUi(QDialog *DI_Edit)
    {
        DI_Edit->setWindowTitle(QApplication::translate("DI_Edit", "Dialog", Q_NULLPTR));
        groupBox->setTitle(QString());
        label->setText(QApplication::translate("DI_Edit", "\351\200\232\351\201\223", Q_NULLPTR));
        label_2->setText(QApplication::translate("DI_Edit", "\345\271\263\345\217\260ID", Q_NULLPTR));
        label_17->setText(QApplication::translate("DI_Edit", "\347\202\271\344\275\215\345\220\215", Q_NULLPTR));
        label_18->setText(QApplication::translate("DI_Edit", "\345\210\206\351\241\271\347\274\226\345\217\267", Q_NULLPTR));
        Linklable->setText(QApplication::translate("DI_Edit", "\350\216\267\345\217\226\345\271\263\345\217\260\345\217\202\346\225\260", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab), QApplication::translate("DI_Edit", "Tab 1", Q_NULLPTR));
        groupBox_3->setTitle(QApplication::translate("DI_Edit", "\346\212\245\350\255\246\345\274\200\345\205\263", Q_NULLPTR));
        EnableCBX->setText(QApplication::translate("DI_Edit", "ENABLE", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("DI_Edit", "Tab 2", Q_NULLPTR));
        groupBox_5->setTitle(QApplication::translate("DI_Edit", "\346\212\245\350\255\246", Q_NULLPTR));
        DI_DO1_OUT->setText(QApplication::translate("DI_Edit", "1", Q_NULLPTR));
        DI_DO2_OUT->setText(QApplication::translate("DI_Edit", "2", Q_NULLPTR));
        DI_DO3_OUT->setText(QApplication::translate("DI_Edit", "3", Q_NULLPTR));
        DI_DO4_OUT->setText(QApplication::translate("DI_Edit", "4", Q_NULLPTR));
        DI_DO5_OUT->setText(QApplication::translate("DI_Edit", "5", Q_NULLPTR));
        DI_DO6_OUT->setText(QApplication::translate("DI_Edit", "6", Q_NULLPTR));
        DI_DO7_OUT->setText(QApplication::translate("DI_Edit", "7", Q_NULLPTR));
        DI_DO8_OUT->setText(QApplication::translate("DI_Edit", "8", Q_NULLPTR));
        DI_DO9_OUT->setText(QApplication::translate("DI_Edit", "9", Q_NULLPTR));
        DI_DO10_OUT->setText(QApplication::translate("DI_Edit", "10", Q_NULLPTR));
        DI_DO11_OUT->setText(QApplication::translate("DI_Edit", "11", Q_NULLPTR));
        DI_DO12_OUT->setText(QApplication::translate("DI_Edit", "12", Q_NULLPTR));
        DI_DO13_OUT->setText(QApplication::translate("DI_Edit", "13", Q_NULLPTR));
        DI_DO14_OUT->setText(QApplication::translate("DI_Edit", "14", Q_NULLPTR));
        DI_DO15_OUT->setText(QApplication::translate("DI_Edit", "15", Q_NULLPTR));
        DI_DO16_OUT->setText(QApplication::translate("DI_Edit", "16", Q_NULLPTR));
        DI_DO1_ENB->setText(QApplication::translate("DI_Edit", "1", Q_NULLPTR));
        DI_DO2_ENB->setText(QApplication::translate("DI_Edit", "2", Q_NULLPTR));
        DI_DO3_ENB->setText(QApplication::translate("DI_Edit", "3", Q_NULLPTR));
        DI_DO4_ENB->setText(QApplication::translate("DI_Edit", "4", Q_NULLPTR));
        DI_DO5_ENB->setText(QApplication::translate("DI_Edit", "5", Q_NULLPTR));
        DI_DO6_ENB->setText(QApplication::translate("DI_Edit", "6", Q_NULLPTR));
        DI_DO7_ENB->setText(QApplication::translate("DI_Edit", "7", Q_NULLPTR));
        DI_DO8_ENB->setText(QApplication::translate("DI_Edit", "8", Q_NULLPTR));
        DI_DO9_ENB->setText(QApplication::translate("DI_Edit", "9", Q_NULLPTR));
        DI_DO10_ENB->setText(QApplication::translate("DI_Edit", "10", Q_NULLPTR));
        DI_DO11_ENB->setText(QApplication::translate("DI_Edit", "11", Q_NULLPTR));
        DI_DO12_ENB->setText(QApplication::translate("DI_Edit", "12", Q_NULLPTR));
        DI_DO13_ENB->setText(QApplication::translate("DI_Edit", "13", Q_NULLPTR));
        DI_DO14_ENB->setText(QApplication::translate("DI_Edit", "14", Q_NULLPTR));
        DI_DO15_ENB->setText(QApplication::translate("DI_Edit", "15", Q_NULLPTR));
        DI_DO16_ENB->setText(QApplication::translate("DI_Edit", "16", Q_NULLPTR));
        label_10->setText(QApplication::translate("DI_Edit", "\351\253\230\351\231\220\350\276\223\345\207\272", Q_NULLPTR));
        label_3->setText(QApplication::translate("DI_Edit", "\351\253\230\351\231\220\344\275\277\350\203\275", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_5), QApplication::translate("DI_Edit", "\351\241\265", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("DI_Edit", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelBtn->setText(QApplication::translate("DI_Edit", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class DI_Edit: public Ui_DI_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DI_EDIT_H
