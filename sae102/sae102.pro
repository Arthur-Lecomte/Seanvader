TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
        entite.cpp \
        gererJeu.cpp \
        main.cpp \
        mouvement.cpp \
        projectile.cpp \
        score.cpp \
        srtuctEnsembleDeCleValide.cpp
include(MinGL/mingl.pri)

HEADERS += \
    entite.h \
    gererJeu.h \
    mouvement.h \
    projectile.h \
    score.h \
    srtuctEnsembleDeCleValide.h
