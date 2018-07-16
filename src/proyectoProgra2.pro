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
    Item.cpp \
    Food.cpp

HEADERS += \
    Game.h \
    Snek.h \
    AnimatedObject.h \
    Control.h \
    Item.h \
    Food.h

RESOURCES += \
    ../assets/resources.qrc
