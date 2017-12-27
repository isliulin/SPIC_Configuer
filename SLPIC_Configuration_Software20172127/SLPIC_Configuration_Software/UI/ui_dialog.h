/********************************************************************************
** Form generated from reading UI file 'dialog.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_DIALOG_H
#define UI_DIALOG_H

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
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_fildesTable
{
public:
    QGridLayout *gridLayout;
    QLabel *label;
    QTabWidget *tabWidget;
    QWidget *aiTab;
    QWidget *diTab;
    QWidget *doTab;
    QWidget *serialTab;
    QWidget *manufactureTab;
    QWidget *com_protoTable;
    QWidget *com_wayTable;
    QHBoxLayout *horizontalLayout;
    QPushButton *confirmButton;
    QPushButton *cancelButton;

    void setupUi(QDialog *fildesTable)
    {
        if (fildesTable->objectName().isEmpty())
            fildesTable->setObjectName(QStringLiteral("fildesTable"));
        fildesTable->resize(732, 590);
        gridLayout = new QGridLayout(fildesTable);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        label = new QLabel(fildesTable);
        label->setObjectName(QStringLiteral("label"));

        gridLayout->addWidget(label, 0, 0, 1, 1);

        tabWidget = new QTabWidget(fildesTable);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        aiTab = new QWidget();
        aiTab->setObjectName(QStringLiteral("aiTab"));
        tabWidget->addTab(aiTab, QString());
        diTab = new QWidget();
        diTab->setObjectName(QStringLiteral("diTab"));
        tabWidget->addTab(diTab, QString());
        doTab = new QWidget();
        doTab->setObjectName(QStringLiteral("doTab"));
        tabWidget->addTab(doTab, QString());
        serialTab = new QWidget();
        serialTab->setObjectName(QStringLiteral("serialTab"));
        tabWidget->addTab(serialTab, QString());
        manufactureTab = new QWidget();
        manufactureTab->setObjectName(QStringLiteral("manufactureTab"));
        tabWidget->addTab(manufactureTab, QString());
        com_protoTable = new QWidget();
        com_protoTable->setObjectName(QStringLiteral("com_protoTable"));
        tabWidget->addTab(com_protoTable, QString());
        com_wayTable = new QWidget();
        com_wayTable->setObjectName(QStringLiteral("com_wayTable"));
        tabWidget->addTab(com_wayTable, QString());

        gridLayout->addWidget(tabWidget, 1, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        confirmButton = new QPushButton(fildesTable);
        confirmButton->setObjectName(QStringLiteral("confirmButton"));

        horizontalLayout->addWidget(confirmButton);

        cancelButton = new QPushButton(fildesTable);
        cancelButton->setObjectName(QStringLiteral("cancelButton"));

        horizontalLayout->addWidget(cancelButton);


        gridLayout->addLayout(horizontalLayout, 2, 0, 1, 1);


        retranslateUi(fildesTable);

        tabWidget->setCurrentIndex(0);


        QMetaObject::connectSlotsByName(fildesTable);
    } // setupUi

    void retranslateUi(QDialog *fildesTable)
    {
        fildesTable->setWindowTitle(QApplication::translate("fildesTable", "Dialog", Q_NULLPTR));
        label->setText(QApplication::translate("fildesTable", "                                                     \345\210\206\351\241\271\345\220\215\345\210\227\350\241\250", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(aiTab), QApplication::translate("fildesTable", "\346\250\241\346\213\237\351\207\217\350\276\223\345\205\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(diTab), QApplication::translate("fildesTable", "\346\225\260\345\255\227\351\207\217\350\276\223\345\205\245", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(doTab), QApplication::translate("fildesTable", "\346\225\260\345\255\227\351\207\217\350\276\223\345\207\272", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(serialTab), QApplication::translate("fildesTable", "\344\270\262\345\217\243", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(manufactureTab), QApplication::translate("fildesTable", "\346\265\201\351\207\217\350\256\241\345\216\202\345\256\266", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(com_protoTable), QApplication::translate("fildesTable", "\344\270\216\344\270\255\345\277\203\351\200\232\344\277\241\345\215\217\350\256\256", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(com_wayTable), QApplication::translate("fildesTable", "\344\270\216\344\270\255\345\277\203\351\200\232\344\277\241\346\226\271\345\274\217", Q_NULLPTR));
        confirmButton->setText(QApplication::translate("fildesTable", "\347\241\256\345\256\232", Q_NULLPTR));
        cancelButton->setText(QApplication::translate("fildesTable", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class fildesTable: public Ui_fildesTable {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_DIALOG_H
