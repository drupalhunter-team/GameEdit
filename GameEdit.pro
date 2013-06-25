#-------------------------------------------------
#
# Project created by QtCreator 2013-06-07T12:08:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GameEdit
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    globaldata.cpp \
    gameitem.cpp \
    DLFile.c \
    gameimage.cpp \
    gamebutton.cpp \
    gamepaintwindow.cpp \
    gamesprite.cpp

HEADERS  += mainwindow.h \
    globaldata.h \
    gameitem.h \
    DLFile.h \
    config.h \
    Prefix.h \
    gameimage.h \
    gamebutton.h \
    gamepaintwindow.h \
    gamesprite.h

FORMS    += mainwindow.ui

OTHER_FILES +=

RESOURCES += \
    icon.qrc
