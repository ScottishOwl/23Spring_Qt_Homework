QT       += core gui
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bloodsupply.cpp \
    flyer.cpp \
    main.cpp \
    mainscene.cpp \
    player_hero.cpp \
    map.cpp \
    enemy_remote.cpp \
    bullet.cpp \
    subscene.cpp

HEADERS += \
    bloodsupply.h \
    config.h \
    flyer.h \
    global.h \
    mainscene.h \
    mainscene.h \
    player_hero.h \
    map.h \
    enemy_remote.h \
    bullet.h \
    subscene.h \
    supply.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc