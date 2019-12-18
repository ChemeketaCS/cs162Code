TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

CONFIG -= debug_and_release

SOURCES += doctest.h \
    ../CircleProject/Circle.cpp \
    CircleTester.cpp
SOURCES +=

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion



#prevent warning from pragma used to suppress warnings from doctest.h
QMAKE_CXXFLAGS += -Wno-unknown-pragmas

HEADERS += \
    ../CircleProject/Circle.h


INCLUDEPATH += ../CircleProject/
