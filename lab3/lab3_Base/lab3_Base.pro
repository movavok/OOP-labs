TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        base.cpp \
        main.cpp \
        privatederived.cpp \
        protectedderived.cpp \
        publicderived.cpp

HEADERS += \
    base.h \
    privatederived.h \
    protectedderived.h \
    publicderived.h
