TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    fancybruteforcealgorithm.cpp \
    filewriter.cpp

HEADERS += \
    algorithm.h \
    bruteforcealgorithm.h \
    fancybruteforcealgorithm.h \
    filewriter.h
