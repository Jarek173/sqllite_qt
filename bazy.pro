#-------------------------------------------------
#
# Project created by QtCreator 2021-05-24T14:31:19
#
#-------------------------------------------------

QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = bazy
TEMPLATE = app
CONFIG += c++17
QMAKE_CXXFLAGS += -std=gnu++17

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    dbmenager.cpp \
    user.cpp \
    order.cpp \
    mydbgroupbox.cpp \
    getlastorders.cpp \
    sqlcommand.cpp \
    addnewuser.cpp \
    addneworder.cpp \
    getuserorders.cpp

HEADERS += \
        mainwindow.h \
    dbmenager.h \
    user.h \
    order.h \
    mydbgroupbox.h \
    getlastorders.h \
    sqlcommand.h \
    addnewuser.h \
    addneworder.h \
    getuserorders.h

FORMS += \
        mainwindow.ui \
    addnewuser.ui \
    addneworder.ui
