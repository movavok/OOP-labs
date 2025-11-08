TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        inventory.cpp \
        main.cpp

HEADERS += \
    History.h \
    Part.h \
    Supply.h \
    comparator.h \
    inventory.h
