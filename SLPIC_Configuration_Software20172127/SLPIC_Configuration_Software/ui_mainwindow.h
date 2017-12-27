/********************************************************************************
** Form generated from reading UI file 'mainwindow.ui'
**
** Created by: Qt User Interface Compiler version 5.9.3
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QAction>
#include <QtWidgets/QApplication>
#include <QtWidgets/QButtonGroup>
#include <QtWidgets/QGridLayout>
#include <QtWidgets/QHBoxLayout>
#include <QtWidgets/QHeaderView>
#include <QtWidgets/QLabel>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QMenu>
#include <QtWidgets/QMenuBar>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QSpacerItem>
#include <QtWidgets/QSplitter>
#include <QtWidgets/QStackedWidget>
#include <QtWidgets/QStatusBar>
#include <QtWidgets/QTableWidget>
#include <QtWidgets/QTextEdit>
#include <QtWidgets/QToolBar>
#include <QtWidgets/QTreeWidget>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QAction *actionNew;
    QAction *actionOpen;
    QAction *actionDownload;
    QAction *actionUpload;
    QAction *actionConnect;
    QAction *actionDisconnect;
    QAction *actionabout;
    QAction *actionSave;
    QAction *actionClose;
    QAction *actiondebug;
    QAction *actiontest_2;
    QWidget *centralWidget;
    QGridLayout *gridLayout;
    QSplitter *splitter_2;
    QSplitter *splitter;
    QTreeWidget *treeWidget;
    QStackedWidget *stackedWidget;
    QWidget *AI_Page;
    QGridLayout *gridLayout_2;
    QTableWidget *AI_TableWidget;
    QLabel *AI_PageTitle;
    QWidget *DI_Page;
    QGridLayout *gridLayout_4;
    QTableWidget *DI_TableWidget;
    QLabel *DI_PageTitle;
    QWidget *DO_Page;
    QGridLayout *gridLayout_5;
    QLabel *DO_PageTitle;
    QTableWidget *DO_TableWidget;
    QWidget *SerialPort_Page;
    QGridLayout *gridLayout_6;
    QTableWidget *SerialPort_TableWidget;
    QLabel *SerialPort_PageTitle;
    QWidget *Oter_Page;
    QGridLayout *gridLayout_11;
    QTableWidget *Oter_Page_TableWidget;
    QLabel *Oter_PageTitle;
    QWidget *msgWidget;
    QGridLayout *gridLayout_3;
    QHBoxLayout *horizontalLayout;
    QLabel *label;
    QSpacerItem *horizontalSpacer;
    QPushButton *clearButton;
    QTextEdit *outMsgText;
    QToolBar *mainToolBar;
    QStatusBar *statusBar;
    QMenuBar *menuBar;
    QMenu *menuFile;
    QMenu *menuControl;
    QMenu *menu_H;
    QMenu *menu_2;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName(QStringLiteral("MainWindow"));
        MainWindow->resize(1091, 815);
        actionNew = new QAction(MainWindow);
        actionNew->setObjectName(QStringLiteral("actionNew"));
        QIcon icon;
        icon.addFile(QStringLiteral(":/images/images/new.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionNew->setIcon(icon);
        actionOpen = new QAction(MainWindow);
        actionOpen->setObjectName(QStringLiteral("actionOpen"));
        QIcon icon1;
        icon1.addFile(QStringLiteral(":/images/images/openfile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionOpen->setIcon(icon1);
        actionDownload = new QAction(MainWindow);
        actionDownload->setObjectName(QStringLiteral("actionDownload"));
        QIcon icon2;
        icon2.addFile(QStringLiteral(":/images/images/download.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDownload->setIcon(icon2);
        actionUpload = new QAction(MainWindow);
        actionUpload->setObjectName(QStringLiteral("actionUpload"));
        QIcon icon3;
        icon3.addFile(QStringLiteral(":/images/images/upload.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionUpload->setIcon(icon3);
        actionConnect = new QAction(MainWindow);
        actionConnect->setObjectName(QStringLiteral("actionConnect"));
        QIcon icon4;
        icon4.addFile(QStringLiteral(":/images/images/1.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionConnect->setIcon(icon4);
        actionDisconnect = new QAction(MainWindow);
        actionDisconnect->setObjectName(QStringLiteral("actionDisconnect"));
        QIcon icon5;
        icon5.addFile(QStringLiteral(":/images/images/2.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionDisconnect->setIcon(icon5);
        actionabout = new QAction(MainWindow);
        actionabout->setObjectName(QStringLiteral("actionabout"));
        QIcon icon6;
        icon6.addFile(QStringLiteral(":/images/images/about.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionabout->setIcon(icon6);
        actionSave = new QAction(MainWindow);
        actionSave->setObjectName(QStringLiteral("actionSave"));
        QIcon icon7;
        icon7.addFile(QStringLiteral(":/images/images/save.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionSave->setIcon(icon7);
        actionClose = new QAction(MainWindow);
        actionClose->setObjectName(QStringLiteral("actionClose"));
        QIcon icon8;
        icon8.addFile(QStringLiteral(":/images/images/closefile.png"), QSize(), QIcon::Normal, QIcon::Off);
        actionClose->setIcon(icon8);
        actiondebug = new QAction(MainWindow);
        actiondebug->setObjectName(QStringLiteral("actiondebug"));
        actiontest_2 = new QAction(MainWindow);
        actiontest_2->setObjectName(QStringLiteral("actiontest_2"));
        centralWidget = new QWidget(MainWindow);
        centralWidget->setObjectName(QStringLiteral("centralWidget"));
        gridLayout = new QGridLayout(centralWidget);
        gridLayout->setSpacing(6);
        gridLayout->setContentsMargins(11, 11, 11, 11);
        gridLayout->setObjectName(QStringLiteral("gridLayout"));
        splitter_2 = new QSplitter(centralWidget);
        splitter_2->setObjectName(QStringLiteral("splitter_2"));
        splitter_2->setOrientation(Qt::Vertical);
        splitter = new QSplitter(splitter_2);
        splitter->setObjectName(QStringLiteral("splitter"));
        splitter->setOrientation(Qt::Horizontal);
        treeWidget = new QTreeWidget(splitter);
        QTreeWidgetItem *__qtreewidgetitem = new QTreeWidgetItem();
        __qtreewidgetitem->setText(0, QStringLiteral("1"));
        treeWidget->setHeaderItem(__qtreewidgetitem);
        treeWidget->setObjectName(QStringLiteral("treeWidget"));
        splitter->addWidget(treeWidget);
        stackedWidget = new QStackedWidget(splitter);
        stackedWidget->setObjectName(QStringLiteral("stackedWidget"));
        AI_Page = new QWidget();
        AI_Page->setObjectName(QStringLiteral("AI_Page"));
        gridLayout_2 = new QGridLayout(AI_Page);
        gridLayout_2->setSpacing(6);
        gridLayout_2->setContentsMargins(11, 11, 11, 11);
        gridLayout_2->setObjectName(QStringLiteral("gridLayout_2"));
        AI_TableWidget = new QTableWidget(AI_Page);
        AI_TableWidget->setObjectName(QStringLiteral("AI_TableWidget"));

        gridLayout_2->addWidget(AI_TableWidget, 1, 0, 1, 1);

        AI_PageTitle = new QLabel(AI_Page);
        AI_PageTitle->setObjectName(QStringLiteral("AI_PageTitle"));

        gridLayout_2->addWidget(AI_PageTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(AI_Page);
        DI_Page = new QWidget();
        DI_Page->setObjectName(QStringLiteral("DI_Page"));
        gridLayout_4 = new QGridLayout(DI_Page);
        gridLayout_4->setSpacing(6);
        gridLayout_4->setContentsMargins(11, 11, 11, 11);
        gridLayout_4->setObjectName(QStringLiteral("gridLayout_4"));
        DI_TableWidget = new QTableWidget(DI_Page);
        DI_TableWidget->setObjectName(QStringLiteral("DI_TableWidget"));

        gridLayout_4->addWidget(DI_TableWidget, 1, 0, 1, 1);

        DI_PageTitle = new QLabel(DI_Page);
        DI_PageTitle->setObjectName(QStringLiteral("DI_PageTitle"));

        gridLayout_4->addWidget(DI_PageTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(DI_Page);
        DO_Page = new QWidget();
        DO_Page->setObjectName(QStringLiteral("DO_Page"));
        gridLayout_5 = new QGridLayout(DO_Page);
        gridLayout_5->setSpacing(6);
        gridLayout_5->setContentsMargins(11, 11, 11, 11);
        gridLayout_5->setObjectName(QStringLiteral("gridLayout_5"));
        DO_PageTitle = new QLabel(DO_Page);
        DO_PageTitle->setObjectName(QStringLiteral("DO_PageTitle"));

        gridLayout_5->addWidget(DO_PageTitle, 0, 0, 1, 1);

        DO_TableWidget = new QTableWidget(DO_Page);
        DO_TableWidget->setObjectName(QStringLiteral("DO_TableWidget"));

        gridLayout_5->addWidget(DO_TableWidget, 1, 0, 1, 1);

        stackedWidget->addWidget(DO_Page);
        SerialPort_Page = new QWidget();
        SerialPort_Page->setObjectName(QStringLiteral("SerialPort_Page"));
        gridLayout_6 = new QGridLayout(SerialPort_Page);
        gridLayout_6->setSpacing(6);
        gridLayout_6->setContentsMargins(11, 11, 11, 11);
        gridLayout_6->setObjectName(QStringLiteral("gridLayout_6"));
        SerialPort_TableWidget = new QTableWidget(SerialPort_Page);
        SerialPort_TableWidget->setObjectName(QStringLiteral("SerialPort_TableWidget"));

        gridLayout_6->addWidget(SerialPort_TableWidget, 1, 0, 1, 1);

        SerialPort_PageTitle = new QLabel(SerialPort_Page);
        SerialPort_PageTitle->setObjectName(QStringLiteral("SerialPort_PageTitle"));

        gridLayout_6->addWidget(SerialPort_PageTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(SerialPort_Page);
        Oter_Page = new QWidget();
        Oter_Page->setObjectName(QStringLiteral("Oter_Page"));
        gridLayout_11 = new QGridLayout(Oter_Page);
        gridLayout_11->setSpacing(6);
        gridLayout_11->setContentsMargins(11, 11, 11, 11);
        gridLayout_11->setObjectName(QStringLiteral("gridLayout_11"));
        Oter_Page_TableWidget = new QTableWidget(Oter_Page);
        Oter_Page_TableWidget->setObjectName(QStringLiteral("Oter_Page_TableWidget"));

        gridLayout_11->addWidget(Oter_Page_TableWidget, 1, 0, 1, 1);

        Oter_PageTitle = new QLabel(Oter_Page);
        Oter_PageTitle->setObjectName(QStringLiteral("Oter_PageTitle"));

        gridLayout_11->addWidget(Oter_PageTitle, 0, 0, 1, 1);

        stackedWidget->addWidget(Oter_Page);
        splitter->addWidget(stackedWidget);
        splitter_2->addWidget(splitter);
        msgWidget = new QWidget(splitter_2);
        msgWidget->setObjectName(QStringLiteral("msgWidget"));
        gridLayout_3 = new QGridLayout(msgWidget);
        gridLayout_3->setSpacing(6);
        gridLayout_3->setContentsMargins(11, 11, 11, 11);
        gridLayout_3->setObjectName(QStringLiteral("gridLayout_3"));
        horizontalLayout = new QHBoxLayout();
        horizontalLayout->setSpacing(6);
        horizontalLayout->setObjectName(QStringLiteral("horizontalLayout"));
        label = new QLabel(msgWidget);
        label->setObjectName(QStringLiteral("label"));

        horizontalLayout->addWidget(label);

        horizontalSpacer = new QSpacerItem(40, 20, QSizePolicy::Expanding, QSizePolicy::Minimum);

        horizontalLayout->addItem(horizontalSpacer);

        clearButton = new QPushButton(msgWidget);
        clearButton->setObjectName(QStringLiteral("clearButton"));
        QIcon icon9;
        icon9.addFile(QStringLiteral(":/images/images/clear2.png"), QSize(), QIcon::Normal, QIcon::Off);
        clearButton->setIcon(icon9);

        horizontalLayout->addWidget(clearButton);


        gridLayout_3->addLayout(horizontalLayout, 0, 0, 1, 1);

        outMsgText = new QTextEdit(msgWidget);
        outMsgText->setObjectName(QStringLiteral("outMsgText"));

        gridLayout_3->addWidget(outMsgText, 1, 0, 1, 1);

        splitter_2->addWidget(msgWidget);

        gridLayout->addWidget(splitter_2, 0, 0, 1, 1);

        MainWindow->setCentralWidget(centralWidget);
        mainToolBar = new QToolBar(MainWindow);
        mainToolBar->setObjectName(QStringLiteral("mainToolBar"));
        MainWindow->addToolBar(Qt::TopToolBarArea, mainToolBar);
        statusBar = new QStatusBar(MainWindow);
        statusBar->setObjectName(QStringLiteral("statusBar"));
        MainWindow->setStatusBar(statusBar);
        menuBar = new QMenuBar(MainWindow);
        menuBar->setObjectName(QStringLiteral("menuBar"));
        menuBar->setGeometry(QRect(0, 0, 1091, 22));
        menuFile = new QMenu(menuBar);
        menuFile->setObjectName(QStringLiteral("menuFile"));
        menuControl = new QMenu(menuBar);
        menuControl->setObjectName(QStringLiteral("menuControl"));
        menu_H = new QMenu(menuBar);
        menu_H->setObjectName(QStringLiteral("menu_H"));
        menu_2 = new QMenu(menuBar);
        menu_2->setObjectName(QStringLiteral("menu_2"));
        MainWindow->setMenuBar(menuBar);

        mainToolBar->addAction(actionNew);
        mainToolBar->addAction(actionSave);
        mainToolBar->addAction(actionOpen);
        mainToolBar->addSeparator();
        mainToolBar->addAction(actionDownload);
        mainToolBar->addAction(actionUpload);
        mainToolBar->addAction(actionConnect);
        mainToolBar->addAction(actionDisconnect);
        menuBar->addAction(menuFile->menuAction());
        menuBar->addAction(menuControl->menuAction());
        menuBar->addAction(menu_2->menuAction());
        menuBar->addAction(menu_H->menuAction());
        menuFile->addAction(actionNew);
        menuFile->addAction(actionOpen);
        menuFile->addAction(actionSave);
        menuFile->addAction(actionClose);
        menuControl->addAction(actionDownload);
        menuControl->addAction(actionUpload);
        menuControl->addAction(actionConnect);
        menuControl->addAction(actionDisconnect);
        menu_H->addAction(actionabout);
        menu_H->addAction(actiondebug);
        menu_2->addAction(actiontest_2);

        retranslateUi(MainWindow);

        stackedWidget->setCurrentIndex(4);


        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QApplication::translate("MainWindow", "\350\207\252\345\255\246\345\236\213\345\267\245\344\270\232\346\216\247\345\210\266\345\231\250\351\205\215\347\275\256\350\275\257\344\273\266", Q_NULLPTR));
        actionNew->setText(QApplication::translate("MainWindow", "\346\226\260\345\273\272(&N)", Q_NULLPTR));
#ifndef QT_NO_TOOLTIP
        actionNew->setToolTip(QApplication::translate("MainWindow", "\346\226\260\345\273\272\346\226\207\344\273\266", Q_NULLPTR));
#endif // QT_NO_TOOLTIP
#ifndef QT_NO_SHORTCUT
        actionNew->setShortcut(QApplication::translate("MainWindow", "Alt+N", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionOpen->setText(QApplication::translate("MainWindow", "\346\211\223\345\274\200(&O)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionOpen->setShortcut(QApplication::translate("MainWindow", "Alt+O", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actionDownload->setText(QApplication::translate("MainWindow", "\344\270\213\350\275\275", Q_NULLPTR));
        actionUpload->setText(QApplication::translate("MainWindow", "\344\270\212\350\275\275", Q_NULLPTR));
        actionConnect->setText(QApplication::translate("MainWindow", "Connect", Q_NULLPTR));
        actionDisconnect->setText(QApplication::translate("MainWindow", "Disconnect", Q_NULLPTR));
        actionabout->setText(QApplication::translate("MainWindow", "about", Q_NULLPTR));
        actionSave->setText(QApplication::translate("MainWindow", "\344\277\235\345\255\230(&S)", Q_NULLPTR));
        actionClose->setText(QApplication::translate("MainWindow", "\345\205\263\351\227\255(&C)", Q_NULLPTR));
#ifndef QT_NO_SHORTCUT
        actionClose->setShortcut(QApplication::translate("MainWindow", "Alt+C", Q_NULLPTR));
#endif // QT_NO_SHORTCUT
        actiondebug->setText(QApplication::translate("MainWindow", "debug", Q_NULLPTR));
        actiontest_2->setText(QApplication::translate("MainWindow", "test", Q_NULLPTR));
        AI_PageTitle->setText(QApplication::translate("MainWindow", "AI\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        DI_PageTitle->setText(QApplication::translate("MainWindow", "DI\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        DO_PageTitle->setText(QApplication::translate("MainWindow", "DO\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        SerialPort_PageTitle->setText(QApplication::translate("MainWindow", "\344\270\262\345\217\243\351\205\215\347\275\256\344\277\241\346\201\257", Q_NULLPTR));
        Oter_PageTitle->setText(QApplication::translate("MainWindow", "\345\205\266\344\273\226\344\277\241\346\201\257", Q_NULLPTR));
        label->setText(QApplication::translate("MainWindow", "\350\276\223\345\207\272\344\277\241\346\201\257", Q_NULLPTR));
        clearButton->setText(QApplication::translate("MainWindow", "clear", Q_NULLPTR));
        menuFile->setTitle(QApplication::translate("MainWindow", "\346\226\207\344\273\266(&F)", Q_NULLPTR));
        menuControl->setTitle(QApplication::translate("MainWindow", "\345\267\245\344\270\232\346\216\247\345\210\266\345\231\250", Q_NULLPTR));
        menu_H->setTitle(QApplication::translate("MainWindow", "\345\270\256\345\212\251(&H)", Q_NULLPTR));
        menu_2->setTitle(QApplication::translate("MainWindow", "\347\252\227\345\217\243(&W)", Q_NULLPTR));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
