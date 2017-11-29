#-------------------------------------------------
#
# Project created by QtCreator 2017-11-02T08:41:23
#
#-------------------------------------------------

QT       += core gui
QT       += sql
QT       += serialport
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = SLPIC_Configuration_Software
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += main.cpp\
        mainwindow.cpp \
    common/convert.cpp \
    ai_edit.cpp \
    database/slpic_database.cpp \
    di_edit.cpp \
    database/di_information_bean.cpp \
    database/ai_information_bean.cpp \
    do_editer.cpp \
    database/do_information_bean.cpp \
    database/serialport_information_bean.cpp \
    serialport_editer.cpp \
    database/other_information_bean.cpp \
    other_editer.cpp \
    common/xconvert.cpp \
    connection.cpp \
    data_packegt/ai_packet.cpp \
    data_packegt/datapacketinferface.cpp \
    data_packegt/datapackettosend.cpp

HEADERS  += mainwindow.h \
    common/commonhead.h \
    common/convert.h \
    ai_edit.h \
    database/slpic_database.h \
    database/ai_information_bean.h \
    di_edit.h \
    database/di_information_bean.h \
    do_editer.h \
    database/do_information_bean.h \
    database/serialport_information_bean.h \
    serialport_editer.h \
    database/other_information_bean.h \
    other_editer.h \
    common/xconvert.h \
    connection.h \
    data_packegt/ai_packet.h \
    data_packegt/datapacketinferface.h \
    data_packegt/datapackettosend.h

FORMS    += mainwindow.ui \
    ai_edit.ui \
    di_edit.ui \
    do_editer.ui \
    serialport_editer.ui \
    other_editer.ui \
    connection.ui

RESOURCES += \
    images.qrc
