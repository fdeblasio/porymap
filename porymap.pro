#-------------------------------------------------
#
# Project created by QtCreator 2016-08-31T15:19:13
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = porymap
TEMPLATE = app
RC_ICONS = resources/icons/porymap-icon-1.ico
ICON = resources/icons/porymap-icon-1.ico


SOURCES += core/block.cpp \
    core/blockdata.cpp \
    core/event.cpp \
    core/heallocation.cpp \
    core/historyitem.cpp \
    core/maplayout.cpp \
    core/metatile.cpp \
    core/parseutil.cpp \
    core/tile.cpp \
    core/tileset.cpp \
    ui/eventpropertiesframe.cpp \
    ui/imageproviders.cpp \
    ui/metatileselector.cpp \
    ui/movementpermissionsselector.cpp \
    ui/neweventtoolbutton.cpp \
    ui/noscrollcombobox.cpp \
    ui/noscrollspinbox.cpp \
    ui/selectablepixmapitem.cpp \
    editor.cpp \
    graphicsview.cpp \
    main.cpp \
    mainwindow.cpp \
    map.cpp \
    project.cpp

HEADERS  += core/block.h \
    core/blockdata.h \
    core/event.h \
    core/heallocation.h \
    core/history.h \
    core/historyitem.h \
    core/mapconnection.h \
    core/maplayout.h \
    core/metatile.h \
    core/parseutil.h \
    core/tile.h \
    core/tileset.h \
    ui/eventpropertiesframe.h \
    ui/imageproviders.h \
    ui/metatileselector.h \
    ui/movementpermissionsselector.h \
    ui/neweventtoolbutton.h \
    ui/noscrollcombobox.h \
    ui/noscrollspinbox.h \
    ui/selectablepixmapitem.h \
    editor.h \
    graphicsview.h \
    mainwindow.h \
    map.h \
    project.h

FORMS    += mainwindow.ui \
    eventpropertiesframe.ui

RESOURCES += \
    resources/images.qrc

INCLUDEPATH += core
INCLUDEPATH += ui