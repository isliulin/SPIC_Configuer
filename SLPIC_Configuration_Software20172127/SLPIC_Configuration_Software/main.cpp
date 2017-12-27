#include "mainwindow.h"
#include <QApplication>

#include "data_packegt/ai_packet.h"
#include "subprojectnametable.h"



int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    qApp->setStyleSheet("QLineEdit { background-color: yellow }");
    MainWindow w;
    w.show();

    return a.exec();
}
