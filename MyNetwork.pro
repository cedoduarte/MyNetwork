QT += core
QT += gui
QT += sql
QT += network
QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    myclient.cpp \
    myclients.cpp \
    mydatabasemanager.cpp \
    myserver.cpp \
    myservers.cpp \
    setupclientdialog.cpp \
    setupserverdialog.cpp

HEADERS += \
    mainwindow.h \
    myclient.h \
    myclients.h \
    mydatabasemanager.h \
    myenums.h \
    myserver.h \
    myservers.h \
    setupclientdialog.h \
    setupserverdialog.h

FORMS += \
    mainwindow.ui \
    setupclientdialog.ui \
    setupserverdialog.ui

RESOURCES += \
    res.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
