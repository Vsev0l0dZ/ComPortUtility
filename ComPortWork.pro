QT       += core gui
QT += widgets serialport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    convertergps.cpp \
    main.cpp \
    mainwindow.cpp \
    parsergps.cpp \
    settingsdialog.cpp \
    terminalwindow.cpp

HEADERS += \
    convertergps.h \
    mainwindow.h \
    parsergps.h \
    settingsdialog.h \
    terminalwindow.h

FORMS += \
    mainwindow.ui \
    settingsdialog.ui \
    terminalwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    images/application-exit.png \
    images/clear.png \
    images/connect.png \
    images/disconnect.png \
    images/settings.png

RESOURCES += \
    terminal.qrc
