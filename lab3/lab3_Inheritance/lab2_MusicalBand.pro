TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
QT += core

SOURCES += \
        bandleader.cpp \
        instrument.cpp \
        main.cpp \
        manager.cpp \
        musicalband.cpp \
        musician.cpp

HEADERS += \
    bandleader.h \
    instrument.h \
    manager.h \
    musicalband.h \
    musician.h
