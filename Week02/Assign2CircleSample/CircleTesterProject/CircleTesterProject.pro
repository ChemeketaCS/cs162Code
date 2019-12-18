CONFIG   += console
CONFIG	 -= debug_and_release 
CONFIG   -= app_bundle

INCLUDEPATH += .. \
    ../CircleProjectFinal/

TEMPLATE = app
SOURCES += catch.hpp \
    ../CircleProjectFinal/Circle.cpp \
    ../CircleProjectFinal/Point.cpp \
    CircleTester.cpp
SOURCES += mainTester.cpp
SOURCES +=


QMAKE_CXXFLAGS += -std=c++11
QMAKE_LFLAGS += -std=c++11

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

# QMAKE_CXXFLAGS += -Werror
# QMAKE_CXXFLAGS += -Wno-error=unused-variable

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

HEADERS += \
    ../CircleProjectFinal/Circle.h \
    ../CircleProjectFinal/Point.h
