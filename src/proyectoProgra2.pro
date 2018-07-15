QT += core gui widgets svg multimedia


TARGET = proyectoProgra2
TEMPLATE = app
CONFIG += c++11


SOURCES += \
        main.cpp \
    Game.cpp \
    Snek.cpp \
    AnimatedObject.cpp \
    Obstacle.cpp

HEADERS += \
    Game.h \
    Snek.h \
    AnimatedObject.h \
    Obstacle.h

RESOURCES += \
    ../assets/resources.qrc
