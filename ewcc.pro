#-------------------------------------------------
#
# Project created by QtCreator 2019-01-27T19:14:17
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = ewcc
TEMPLATE = app

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
    IRC.cpp \
    user_info.cpp \
    IRC_context.cpp \
    mutex_list.cpp \
    mutex_data.cpp

HEADERS += \
        mainwindow.h \
    IRC.h \
    user_info.h \
    IRC_context.h \
    mutex_list.h \
    mutex_data.h

FORMS += \
        mainwindow.ui

QMAKE_CXXFLAGS += -std=c++1z
LIBS += -pthread
INCLUDEPATH += /usr/include/boost

RESOURCES += \
    twitch_resource.qrc

DISTFILES += \
    user_info
