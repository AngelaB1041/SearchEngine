TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    thanosTree.cpp \
    stopnstem.cpp \
    porter2_stemmer.cpp \
    catchtests.cpp \
    cheparser.cpp

HEADERS += \
    thanosTree.h \
    json.hpp \
    catch.hpp \
    porter2_stemmer.h \
    stopnstem.h \
    hash.h \
    string_view.h \
    cheparser.h

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/../../../Desktop/myhtml/lib/release/ -lmyhtml
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/../../../Desktop/myhtml/lib/debug/ -lmyhtml
else:unix: LIBS += -L$$PWD/../../../Desktop/myhtml/lib/ -lmyhtml

INCLUDEPATH += $$PWD/../../../Desktop/myhtml/include
DEPENDPATH += $$PWD/../../../Desktop/myhtml/include
