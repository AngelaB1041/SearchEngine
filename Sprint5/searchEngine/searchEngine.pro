TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    thanosTree.cpp \
    stopnstem.cpp \
    porter2_stemmer.cpp \
    catchtests.cpp

HEADERS += \
    thanosTree.h \
    json.hpp \
    catch.hpp \
    porter2_stemmer.h \
    stopnstem.h \
    hash.h \
    string_view.h
