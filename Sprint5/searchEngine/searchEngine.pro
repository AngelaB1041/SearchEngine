TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    thanosTree.cpp \
    stopnstem.cpp

HEADERS += \
    thanosTree.h \
    json.hpp \
    catch.hpp \
    porter2_stemmer.h \
    stopnstem.h
