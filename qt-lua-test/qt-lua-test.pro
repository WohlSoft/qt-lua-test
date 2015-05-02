#-------------------------------------------------
#
# Project created by QtCreator 2014-11-13T20:05:38
#
#-------------------------------------------------

QT       += core gui widgets

QMAKE_CXXFLAGS += -Wno-unused-local-typedefs -Wno-ignored-qualifiers

TARGET = qt-lua-test
TEMPLATE = app
CONFIG += static
CONFIG += C++11

INCLUDEPATH += $$PWD/luabind $$PWD/luabind/lua
LIBS += -L$$PWD/luabind_lib/ -lluabind
SOURCES += main.cpp\
        luawindow.cpp

HEADERS  += luawindow.h \
    luabind/___unused.h

FORMS    += luawindow.ui
