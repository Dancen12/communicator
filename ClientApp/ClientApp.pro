QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    beginwindow.cpp \
    cryptographer.cpp \
    currentuser.cpp \
    filemanager.cpp \
    ichat.cpp \
    icipher.cpp \
    imessage.cpp \
    main.cpp \
    mainwindow.cpp \
    registerwindow.cpp \
    secretcipher.cpp \
    serverrequester.cpp \
    settings.cpp \
    singlechat.cpp \
    textmessage.cpp \
    user.cpp

HEADERS += \
    beginwindow.h \
    cryptographer.h \
    currentuser.h \
    filemanager.h \
    ichat.h \
    icipher.h \
    imessage.h \
    mainwindow.h \
    registerwindow.h \
    secretcipher.h \
    serverrequester.h \
    settings.h \
    singlechat.h \
    textmessage.h \
    user.h

FORMS += \
    beginwindow.ui \
    mainwindow.ui \
    registerwindow.ui \
    settings.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resourcesFile.qrc

RC_ICONS = logo.ico
