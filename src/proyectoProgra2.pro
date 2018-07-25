QT += core gui widgets svg multimedia


TARGET = proyectoProgra2
TEMPLATE = app
CONFIG += c++11


SOURCES += \
        main.cpp \
    Game.cpp \
    Snek.cpp \
    AnimatedObject.cpp \
    Control.cpp \
    Food.cpp \
    Score.cpp \
    FallingObject.cpp \
    Gate.cpp

HEADERS += \
    Game.h \
    Snek.h \
    AnimatedObject.h \
    Control.h \
    Food.h \
    Score.h \
    FallingObject.h \
    Gate.h

RESOURCES += \
    ../assets/resources.qrc
