QT       += core gui
QT       += core gui multimedia
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    clear.cpp \
    main.cpp \
    mainscene.cpp \
    player_hero.cpp \
    map.cpp \
    enemy_remote.cpp \
    bullet.cpp \
    points.cpp \
    shield.cpp \
    subscene.cpp

HEADERS += \
    clear.h \
    config.h \
    mainscene.h \
    player_hero.h \
    map.h \
    enemy_remote.h \
    bullet.h \
    points.h \
    shield.h \
    subscene.h

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    res.qrc
