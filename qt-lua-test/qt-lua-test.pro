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

INCLUDEPATH += $$PWD/luabind $$PWD/luabind/boost $$PWD/luabind/lua
LIBS += -L$$PWD/luabind_lib/ -lluabind
SOURCES += main.cpp\
        luawindow.cpp

HEADERS  += luawindow.h

FORMS    += luawindow.ui
