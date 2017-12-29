/********************************************************************************
** Form generated from reading UI file 'subprojectnametable.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_SUBPROJECTNAMETABLE_H
#define UI_SUBPROJECTNAMETABLE_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QTableView>
#include <QtWidgets/QVBoxLayout>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_SubProjectNameTable
{
public:
    QGridLayout *gridLayout;
    QVBoxLayout *verticalLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *aiTab;
    QGridLayout *gridLayout_2;
    QTableView *aiTableView;
    QWidget *diTab;
    QGridLayout *gridLayout_3;
    QTableView *diTableView;
    QWidget *doTab;
    QGridLayout *gridLayout_4;
    QTableView *doTableView;
    QWidget *serialTab;
    QGridLayout *gridLayout_8;
    QTableView *serialTableView;
    QWidget *manufactureTab;
    QGridLayout *gridLayout_5;
    QTableView *manufactTableView;
    QWidget *com_protoTable;
    QGridLayout *gridLayout_6;
    QTableView *commprotoTableView;
    QWidget *com_wayTable;
    QGridLayout *gridLayout_7;
    QTableView *commwaytableView;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *SubProjectNameTable)
    {
        if (SubProjectNameTable->objectName().isEmpty())
            SubProjectNameTable->setObjectName(QStringLiteral("SubProjectNameTable"));
        SubProjectNameTable->resize(921, 674);
        gridLayout = new QGridLayout(SubProjectNameTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        verticalLayout = new QVBoxLayout();
        verticalLayout->setObjectName(QStringLiteral("verticalLayout"));
        label = new QLabel(SubProjectNameTable);
        label->setObjectName(QStringLiteral("label"));
        QFont font;
        font.setFamily(QString::fromUtf8("\351\232\266\344\271\246"));
        font.setPointSize(18);
        label->setFont(font);
        label->setLayoutDirection(Qt::LeftToRight);
        label->setAlignment(Qt::AlignCenter);

        verticalLayout->addWidget(label);

        tabWidget = new QTabWidget(SubProjectNameTable);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        aiTab = new QWidget();
        aiTab->setObjectName(QStringLiteral("aiTab"));
        gridLayout_2 = new QGridLayout(aiTab);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        aiTableView = new QTableView(aiTab);
        aiTableView->setObjectName(QStringLiteral("aiTableView"));

        gridLayout_2->addWidget(aiTableView, 0, 0, 1, 1);

        tabWidget->addTab(aiTab, QString());
        diTab = new QWidget();
        diTab->setObjectName(QStringLiteral("diTab"));
        gridLayout_3 = new QGridLayout(diTab);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        diTableView = new QTableView(diTab);
        diTableView->setObjectName(QStringLiteral("diTableView"));

        gridLayout_3->addWidget(diTableView, 0, 0, 1, 1);

        tabWidget->addTab(diTab, QString());
        doTab = new QWidget();
        doTab->setObjectName(QStringLiteral("doTab"));
        gridLayout_4 = new QGridLayout(doTab);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        doTableView = new QTableView(doTab);
        doTableView->setObjectName(QStringLiteral("doTableView"));

        gridLayout_4->addWidget(doTableView, 0, 0, 1, 1);

        tabWidget->addTab(doTab, QString());
        serialTab = new QWidget();
        serialTab->setObjectName(QStringLiteral("serialTab"));
        gridLayout_8 = new QGridLayout(serialTab);
        gridLayout_8->setObjectName(QStringLiteral("gridLayout_8"));
        serialTableView = new QTableView(serialTab);
        serialTableView->setObjectName(QStringLiteral("serialTableView"));

        gridLayout_8->addWidget(serialTableView, 0, 0, 1, 1);

        tabWidget->addTab(serialTab, QString());
        manufactureTab = new QWidget();
        manufactureTab->setObjectName(QStringLiteral("manufactureTab"));
        gridLayout_5 = new QGridLayout(manufactureTab);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        manufactTableView = new QTableView(manufactureTab);
        manufactTableView->setObjectName(QStringLiteral("manufactTableView"));

        gridLayout_5->addWidget(manufactTableView, 0, 0, 1, 1);

        tabWidget->addTab(manufactureTab, QString());
        com_protoTable = new QWidget();
        com_protoTable->setObjectName(QStringLiteral("com_protoTable"));
        gridLayout_6 = new QGridLayout(com_protoTable);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        commprotoTableView = new QTableView(com_protoTable);
        commprotoTableView->setObjectName(QStringLiteral("commprotoTableView"));

        gridLayout_6->addWidget(commprotoTableView, 0, 0, 1, 1);

        tabWidget->addTab(com_protoTable, QString());
        com_wayTable = new QWidget();
        com_wayTable->setObjectName(QStringLiteral("com_wayTable"));
        gridLayout_7 = new QGridLayout(com_wayTable);
        gridLayout_7->setObjectName(QStringLiteral("gridLayout_7"));
        commwaytableView = new QTableView(com_wayTable);
        commwaytableView->setObjectName(QStringLiteral("commwaytableView"));

        gridLayout_7->addWidget(commwaytableView, 0, 0, 1, 1);

        tabWidget->addTab(com_wayTable, QString());

        verticalLayout->addWidget(tabWidget);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        confirmButton = new QPushButton(SubProjectNameTable);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        horizontalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(SubProjectNameTable);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        verticalLayout->addLayout(horizontalLayout);


        gridLayout->addLayout(verticalLayout, 0, 0, 1, 1);


        retranslateUi(SubProjectNameTable);

        tabWidget->setCurrentIndex(5);


        QMetaObject::connectSlotsByName(SubProjectNameTable);
    } // setupUi

    void retranslateUi(QDialog *SubProjectNameTable)
    {
        SubProjectNameTable->setWindowTitle(QApplication::translate("SubProjectNameTable", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("SubProjectNameTable", "<html><head/><body><p>\345\210\206\351\241\271\345\220\215\345\210\227\350\241\250</p></body></html>", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(aiTab), QApplication::translate("SubProjectNameTable", "\346\250\241\346\213\237\351\207\217\350\276\223\345\205\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(diTab), QApplication::translate("SubProjectNameTable", "\346\225\260\345\255\227\351\207\217\350\276\223\345\205\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(doTab), QApplication::translate("SubProjectNameTable", "\346\225\260\345\255\227\351\207\217\350\276\223\345\207\272", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(serialTab), QApplication::translate("SubProjectNameTable", "\344\270\262\345\217\243", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(manufactureTab), QApplication::translate("SubProjectNameTable", "\346\265\201\351\207\217\350\256\241\345\216\202\345\256\266", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(com_protoTable), QApplication::translate("SubProjectNameTable", "\344\270\216\344\270\255\345\277\203\351\200\232\344\277\241\345\215\217\350\256\256", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(com_wayTable), QApplication::translate("SubProjectNameTable", "\344\270\216\344\270\255\345\277\203\351\200\232\344\277\241\346\226\271\345\274\217", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("SubProjectNameTable", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("SubProjectNameTable", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class SubProjectNameTable: public Ui_SubProjectNameTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_SUBPROJECTNAMETABLE_H
