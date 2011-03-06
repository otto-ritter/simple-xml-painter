#-------------------------------------------------
#
# Project created by QtCreator 2011-03-04T18:12:07
#
#-------------------------------------------------

QT       += core gui xml

TARGET = simple-xml-drawer
TEMPLATE = app
DESTDIR = .
INCLUDEPATH += source
SOURCES += source/main.cpp\
           source/mainwindow.cpp \
           source/myxmlhandler.cpp \
           source/mypainter.cpp \
           source/paintframe.cpp

HEADERS += source/mainwindow.h \
           source/myxmlhandler.h \
           source/mypainter.h \
           source/paintframe.h

FORMS    += ui/mainwindow.ui
