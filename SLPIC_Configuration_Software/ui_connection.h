/********************************************************************************
** Form generated from reading UI file 'connection.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_CONNECTION_H
#define UI_CONNECTION_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QComboBox>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Connection
{
public:
    QGroupBox *serialGroupBox;
    QWidget *verticalLayoutWidget;
    QVBoxLayout *verticalLayout;
    QComboBox *SerialNumCBX;
    QComboBox *BaudRateCBX;
    QComboBox *DataBitsCBX;
    QComboBox *ParityCBX;
    QComboBox *StopBitCBX;
    QLabel *label_5;
    QLabel *label_6;
    QLabel *label;
    QLabel *label_2;
    QLabel *label_3;
    QLabel *label_4;
    QPushButton *ConfirmButton;
    QPushButton *CancleButton;
    QPushButton *RefreshButton_2;

    void setupUi(QDialog *Connection)
    {
        if (Connection->objectName().isEmpty())
            Connection->setObjectName(QStringLiteral("Connection"));
        Connection->resize(385, 408);
        serialGroupBox = new QGroupBox(Connection);
        serialGroupBox->setObjectName(QStringLiteral("serialGroupBox"));
        serialGroupBox->setGeometry(QRect(10, 20, 361, 351));
        QFont font;
        font.setFamily(QStringLiteral("Microsoft YaHei UI"));
        font.setPointSize(11);
        font.setBold(false);
        font.setWeight(50);
        serialGroupBox->setFont(font);
        verticalLayoutWidget = new QWidget(serialGroupBox);
        verticalLayoutWidget->setObjectName(QStringLiteral("verticalLayoutWidget"));
        verticalLayoutWidget->setGeometry(QRect(79, 30, 111, 271));
        verticalLayout = new QVBoxLayout(verticalLayoutWidget);
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        verticalLayout->setContentsMargins(0, 0, 0, 0);
        SerialNumCBX = new QComboBox(verticalLayoutWidget);
        SerialNumCBX->setObjectName(QStringLiteral("SerialNumCBX"));

        verticalLayout->addWidget(SerialNumCBX);

        BaudRateCBX = new QComboBox(verticalLayoutWidget);
        BaudRateCBX->setObjectName(QStringLiteral("BaudRateCBX"));

        verticalLayout->addWidget(BaudRateCBX);

        DataBitsCBX = new QComboBox(verticalLayoutWidget);
        DataBitsCBX->setObjectName(QStringLiteral("DataBitsCBX"));

        verticalLayout->addWidget(DataBitsCBX);

        ParityCBX = new QComboBox(verticalLayoutWidget);
        ParityCBX->setObjectName(QStringLiteral("ParityCBX"));

        verticalLayout->addWidget(ParityCBX);

        StopBitCBX = new QComboBox(verticalLayoutWidget);
        StopBitCBX->setObjectName(QStringLiteral("StopBitCBX"));

        verticalLayout->addWidget(StopBitCBX);

        label_5 = new QLabel(serialGroupBox);
        label_5->setObjectName(QStringLiteral("label_5"));
        label_5->setGeometry(QRect(10, 158, 45, 19));
        QFont font1;
        font1.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font1.setPointSize(11);
        font1.setBold(false);
        font1.setWeight(50);
        label_5->setFont(font1);
        label_6 = new QLabel(serialGroupBox);
        label_6->setObjectName(QStringLiteral("label_6"));
        label_6->setGeometry(QRect(10, 209, 64, 20));
        QFont font2;
        font2.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font2.setPointSize(12);
        font2.setBold(false);
        font2.setWeight(50);
        label_6->setFont(font2);
        label = new QLabel(serialGroupBox);
        label->setObjectName(QStringLiteral("label"));
        label->setGeometry(QRect(10, 56, 45, 19));
        QFont font3;
        font3.setFamily(QStringLiteral("Microsoft JhengHei UI"));
        font3.setPointSize(11);
        label->setFont(font3);
        label_2 = new QLabel(serialGroupBox);
        label_2->setObjectName(QStringLiteral("label_2"));
        label_2->setGeometry(QRect(10, 107, 45, 19));
        label_2->setFont(font3);
        label_3 = new QLabel(serialGroupBox);
        label_3->setObjectName(QStringLiteral("label_3"));
        label_3->setGeometry(QRect(10, 260, 45, 19));
        label_3->setFont(font3);
        label_4 = new QLabel(Connection);
        label_4->setObjectName(QStringLiteral("label_4"));
        label_4->setGeometry(QRect(430, 330, 109, 259));
        ConfirmButton = new QPushButton(Connection);
        ConfirmButton->setObjectName(QStringLiteral("ConfirmButton"));
        ConfirmButton->setGeometry(QRect(90, 380, 80, 20));
        CancleButton = new QPushButton(Connection);
        CancleButton->setObjectName(QStringLiteral("CancleButton"));
        CancleButton->setGeometry(QRect(190, 380, 80, 20));
        RefreshButton_2 = new QPushButton(Connection);
        RefreshButton_2->setObjectName(QStringLiteral("RefreshButton_2"));
        RefreshButton_2->setGeometry(QRect(290, 380, 80, 20));

        retranslateUi(Connection);

        QMetaObject::connectSlotsByName(Connection);
    } // setupUi

    void retranslateUi(QDialog *Connection)
    {
        Connection->setWindowTitle(QApplication::translate("Connection", "Dialog", Q_NULLPTR));
        serialGroupBox->setTitle(QApplication::translate("Connection", "\344\270\262\345\217\243\350\256\276\347\275\256", Q_NULLPTR));
        label_5->setText(QApplication::translate("Connection", "\346\225\260\346\215\256\344\275\215", Q_NULLPTR));
        label_6->setText(QApplication::translate("Connection", "\345\245\207\345\201\266\346\240\241\351\252\214", Q_NULLPTR));
        label->setText(QApplication::translate("Connection", "\344\270\262\345\217\243\345\217\267", Q_NULLPTR));
        label_2->setText(QApplication::translate("Connection", "\346\263\242\347\211\271\347\216\207", Q_NULLPTR));
        label_3->setText(QApplication::translate("Connection", "\345\201\234\346\255\242\344\275\215", Q_NULLPTR));
        label_4->setText(QApplication::translate("Connection", "TextLabel", Q_NULLPTR));
        ConfirmButton->setText(QApplication::translate("Connection", "\347\241\256\345\256\232", Q_NULLPTR));
        CancleButton->setText(QApplication::translate("Connection", "\345\217\226\346\266\210", Q_NULLPTR));
        RefreshButton_2->setText(QApplication::translate("Connection", "\345\210\267\346\226\260", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Connection: public Ui_Connection {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_CONNECTION_H
