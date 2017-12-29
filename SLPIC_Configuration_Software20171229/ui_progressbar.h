/********************************************************************************
** Form generated from reading UI file 'progressbar.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_PROGRESSBAR_H
#define UI_PROGRESSBAR_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QDialog>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QProgressBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QTextEdit>

QT_BEGIN_NAMESPACE

class Ui_ProgressBar
{
public:
    QGridLayout *gridLayout;
    QProgressBar *progressBar;
    QTextEdit *errorTextEdit;
    QHBoxLayout *horizontalLayout;
    QSpacerItem *horizontalSpacer;
    QPushButton *confirmBtn;

    void setupUi(QDialog *ProgressBar)
    {
        if (ProgressBar->objectName().isEmpty())
            ProgressBar->setObjectName(QStringLiteral("ProgressBar"));
        ProgressBar->resize(604, 192);
        gridLayout = new QGridLayout(ProgressBar);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        progressBar = new QProgressBar(ProgressBar);
        progressBar->setObjectName(QStringLiteral("progressBar"));
        progressBar->setValue(24);

        gridLayout->addWidget(progressBar, 0, 0, 1, 1);

        errorTextEdit = new QTextEdit(ProgressBar);
        errorTextEdit->setObjectName(QStringLiteral("errorTextEdit"));

        gridLayout->addWidget(errorTextEdit, 2, 0, 1, 1);

        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        horizontalSpacer = new QSpacerItem(396, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        confirmBtn = new QPushButton(ProgressBar);
        confirmBtn->setObjectName(QStringLiteral("confirmBtn"));

        horizontalLayout->addWidget(confirmBtn);


        gridLayout->addLayout(horizontalLayout, 1, 0, 1, 1);


        retranslateUi(ProgressBar);

        QMetaObject::connectSlotsByName(ProgressBar);
    } // setupUi

    void retranslateUi(QDialog *ProgressBar)
    {
        ProgressBar->setWindowTitle(QApplication::translate("ProgressBar", "Dialog", Q_NULLPTR));
        confirmBtn->setText(QApplication::translate("ProgressBar", "\347\241\256\350\256\244", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class ProgressBar: public Ui_ProgressBar {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_PROGRESSBAR_H
