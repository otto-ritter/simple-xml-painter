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
           source/vectorimage.cpp \
           source/paintframe.cpp \
           source/paintserver.cpp

HEADERS += source/mainwindow.h \
           source/myxmlhandler.h \
           source/vectorimage.h \
           source/paintframe.h \
           source/paintserver.h

FORMS    += ui/mainwindow.ui
