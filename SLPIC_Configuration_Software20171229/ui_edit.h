/********************************************************************************
** Form generated from reading UI file 'edit.ui'
**
** Created by: Qt User Interface Compiler version 5.8.0
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_EDIT_H
#define UI_EDIT_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QTabWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_Edit
{
public:
    QGridLayout *gridLayout;
    QTabWidget *tabWidget;
    QWidget *BaseParam;
    QWidget *tab_2;
    QHBoxLayout *horizontalLayout;
    QPushButton *ConfirmBtn;
    QPushButton *CancelBtn;

    void setupUi(QDialog *Edit)
    {
        if (Edit->objectName().isEmpty())
            Edit->setObjectName(QStringLiteral("Edit"));
        Edit->resize(600, 460);
        Edit->setMinimumSize(QSize(0, 0));
        gridLayout = new QGridLayout(Edit);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        tabWidget = new QTabWidget(Edit);
        tabWidget->setObjectName(QStringLiteral("tabWidget"));
        BaseParam = new QWidget();
        BaseParam->setObjectName(QStringLiteral("BaseParam"));
        tabWidget->addTab(BaseParam, QString());
        tab_2 = new QWidget();
        tab_2->setObjectName(QStringLiteral("tab_2"));
        tabWidget->addTab(tab_2, QString());

        gridLayout->addWidget(tabWidget, 0, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        ConfirmBtn = new QPushButton(Edit);
        ConfirmBtn->setObjectName(QStringLiteral("ConfirmBtn"));

        horizontalLayout->addWidget(ConfirmBtn);

        CancelBtn = new QPushButton(Edit);
        CancelBtn->setObjectName(QStringLiteral("CancelBtn"));

        horizontalLayout->addWidget(CancelBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(Edit);

        tabWidget->setCurrentIndex(1);


        QMetaObject::connectSlotsByName(Edit);
    } // setupUi

    void retranslateUi(QDialog *Edit)
    {
        Edit->setWindowTitle(QApplication::translate("Edit", "Dialog", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(BaseParam), QApplication::translate("Edit", "Tab 1", Q_NULLPTR));
        tabWidget->setTabText(tabWidget->indexOf(tab_2), QApplication::translate("Edit", "Tab 2", Q_NULLPTR));
        ConfirmBtn->setText(QApplication::translate("Edit", "\347\241\256\345\256\232", Q_NULLPTR));
        CancelBtn->setText(QApplication::translate("Edit", "\345\217\226\346\266\210", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class Edit: public Ui_Edit {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_EDIT_H
