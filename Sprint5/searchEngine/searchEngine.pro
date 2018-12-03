TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    word.cpp \
    tests.cpp \
    stopnstem.cpp \
    porter2_stemmer.cpp \
    avlhandler.cpp \
    parser.cpp \
    userI.cpp \
    lucky.cpp \
    query.cpp \
    hashtablehandler.cpp \
    indexinterface.cpp

HEADERS += \
    thanosTree.h \
    catch.hpp \
    word.h \
    thanosnode.h\
    porter2_stemmer.h \
    stopnstem.h \
    hash.h \
    string_view.h \
    avlhandler.h \
    parser.h \
    hashtable.h \
    hashentry.h \
    indexinterface.h \
    userI.h \
    lucky.h \
    query.h \
    hashtablehandler.h


