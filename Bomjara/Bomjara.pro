QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    mainMenuScene.cpp \
    player.cpp \
    playerScene.cpp \
    scene.cpp \
    sceneManager.cpp \
    main.cpp \
    mainWindow.cpp \
    moneyScene.cpp

HEADERS += \
    mainMenuScene.h \
    player.h \
    playerScene.h \
    sceneManager.h \
    mainWindow.h \
    moneyScene.h \
    scene.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES +=

RESOURCES += \
    ../Images/Images.qrc
