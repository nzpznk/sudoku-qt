#-------------------------------------------------
#
# Project created by QtCreator 2017-08-28T13:20:52
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = sudoku-qt
TEMPLATE = app

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
#    main.cpp\
    loader/loader.cpp \
    loader/fileloader.cpp \
    logic/logiccontroller.cpp \
    solver/dancinglinks.cpp \
    solver/solver.cpp \
    solver/stdsudokunodescontainer.cpp \
    solver/dlnodescontainer.cpp \
    UI/gameboard.cpp \
    UI/sudokugrid.cpp \
    UI/gridbtn.cpp \
    UI/inputboard.cpp \
    test/test.cpp \
    test/logger.cpp \
    test/testsukodugrid.cpp \
    test/testinput.cpp \
    UI/mainwindow.cpp \
    loader/randomgenerator.cpp
    test/testgridbtn.cpp

HEADERS  += \
    loader/loader.h \
    loader/fileloader.h \
    logic/logiccontroller.h \
    solver/dancinglinks.h \
    solver/solver.h \
    solver/listnode.h \
    solver/dlnodescontainer.h \
    solver/stdsudokunodescontainer.h \
    UI/gameboard.h \
    UI/sudokugrid.h \
    UI/gridbtn.h \
    UI/inputboard.h \
    test/logger.h \
    test/testsolver.h \
    test/testsukodugrid.h \
    test/testinput.h \
    test/testgameboard.h \
    test/testlogic.h \
    UI/mainwindow.h \
    loader/randomgenerator.h
    test/testgridbtn.h

INCLUDEPATH += \
    ./test/
    ./loader/
    ./logic/
    ./solver/
    ./UI/

FORMS += \
    UI/gameboard.ui \
    UI/sudokugrid.ui \
    UI/inputboard.ui \
    UI/mainwindow.ui \
    test/testsukodugrid.ui \
    test/testgridbtn.ui \
    test/testinput.ui


RESOURCES += \
    resource.qrc
