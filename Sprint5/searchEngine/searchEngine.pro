TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    word.cpp \
    tests.cpp \
    stopnstem.cpp \
    porter2_stemmer.cpp \
    catchtests.cpp \
    avlhandler.cpp \
    parser.cpp \
    query.cpp \
    output.cpp

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
    query.h \
    hashtable.h \
    output.h



