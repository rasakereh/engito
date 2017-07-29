#-------------------------------------------------
#
# Project created by QtCreator 2017-07-26T17:25:40
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = EnchantedForest
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
        main.cpp \
    src/BoardCell.cpp \
    src/CellDecision.cpp \
    src/ConsoleUI.cpp \
    src/Decision.cpp \
    src/DecisionCell.cpp \
    src/DecisionTranslator.cpp \
    src/Dice.cpp \
    src/DiceDecision.cpp \
    src/Game.cpp \
    src/GameBoard.cpp \
    src/GameInitializer.cpp \
    src/GameRuler.cpp \
    src/GameStatistics.cpp \
    src/InitialCell.cpp \
    src/MapLoader.cpp \
    src/NetworkPlayer.cpp \
    src/OrdinaryCell.cpp \
    src/Player.cpp \
    src/RealPlayer.cpp \
    src/RobotPlayer.cpp \
    src/TransportCell.cpp \
    src/Treasure.cpp \
    src/TreasureCell.cpp \
    src/UI.cpp \
    mainwindow.cpp \
    GameScreen.cpp \
    src/GraphicalUI.cpp \
    src/BoardToGUI.cpp \
    src/CellContainer.cpp \
    src/PlayerContainer.cpp

HEADERS += \
    headers/BoardCell.h \
    headers/CellDecision.h \
    headers/ConsoleUI.h \
    headers/Decision.h \
    headers/DecisionCell.h \
    headers/DecisionTranslator.h \
    headers/Dice.h \
    headers/DiceDecision.h \
    headers/Game.h \
    headers/GameBoard.h \
    headers/GameInitializer.h \
    headers/GameRuler.h \
    headers/GameStatistics.h \
    headers/InitialCell.h \
    headers/MapLoader.h \
    headers/NetworkPlayer.h \
    headers/OrdinaryCell.h \
    headers/Player.h \
    headers/RealPlayer.h \
    headers/RobotPlayer.h \
    headers/TransportCell.h \
    headers/Treasure.h \
    headers/TreasureCell.h \
    headers/UI.h \
    GameScreen.h \
    headers/GraphicalUI.h \
    headers/BoardToGUI.h \
    MainWindow.h \
    headers/CellContainer.h \
    headers/PlayerContainer.h

FORMS += \
        mainwindow.ui \
    GameScreen.ui

RESOURCES += \
    icons.qrc
#
