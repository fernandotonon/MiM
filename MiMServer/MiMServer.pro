#-------------------------------------------------
#
# Project created by QtCreator 2010-12-09T09:35:02
#
#-------------------------------------------------

QT       += core
QT       -= gui

TARGET = MiMServer
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    TCPServer.cpp \
    Session.cpp \
    Server.cpp \
    Receiver.cpp \
    ../Protocol/Protocol.pb.cc \
    TCPClient.cpp \
    ../Dependencies/base64/base64.cpp

HEADERS += \
    Util.hpp \
    TCPServer.h \
    Session.h \
    Server.h \
    Receiver.h \
    EventListener.h \
    ../Protocol/Protocol.pb.h \
    TCPClientEventListener.h \
    TCPClient.h \
    ../Dependencies/base64/base64.h

INCLUDEPATH += ../Dependencies/boost \
        ../Dependencies/Protobuf \
        ../Dependencies/soci-3.0.0/src/core \
        ../Dependencies/soci-3.0.0/src/backends/postgresql \
        ../Dependencies/libpq-fe/include \
        ../Dependencies/base64 \
        ../Protocol

LIBS += ../Dependencies/Protobuf/lib/libprotobuf.a \
        ../Dependencies/boost/libs/libboost_system-mgw44-mt-1_42.lib \
        ../Dependencies/boost/libs/libboost_thread-mgw44-mt-1_42.lib \
        ../Dependencies/soci-3.0.0/build/msvc80/lib/ReleaseWin32/libsoci-core.a \
        ../Dependencies/soci-3.0.0/build/msvc80/lib/ReleaseWin32/libsoci-postgre.a \
        ../Dependencies/libpq-fe/libpq.lib \
        C:/mingw/lib/libws2_32.a \
        C:/mingw/lib/libwsock32.a
