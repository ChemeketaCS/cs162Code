TEMPLATE = app
CONFIG += console
CONFIG += c++11
CONFIG -= debug_and_release  
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    Employee.cpp \
    SalariedEmployee.cpp \
    Salesperson.cpp \
    HourlyEmployee.cpp

QMAKE_CXXFLAGS += -pedantic
QMAKE_CXXFLAGS += -pedantic-errors

QMAKE_CXXFLAGS += -Wmissing-include-dirs
QMAKE_CXXFLAGS += -Wfloat-equal
QMAKE_CXXFLAGS += -Wredundant-decls
QMAKE_CXXFLAGS += -Winit-self
QMAKE_CXXFLAGS += -Wshadow
QMAKE_CXXFLAGS += -Wconversion

HEADERS += \
    Employee.h \
    SalariedEmployee.h \
    Salesperson.h \
    HourlyEmployee.h

