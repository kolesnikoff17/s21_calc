QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    ../calculating/parsing.c \
    ../calculating/calc_core.c \
    ../calculating/common.c \
    ../bonus/credit_c.c \
    ../qcustomplot-source/qcustomplot.cpp \
    credit.cpp \
    main.cpp \
    calc.cpp \
    plot.cpp

HEADERS += \
    ../qcustomplot-source/qcustomplot.h \
    WindowSwitch.h \
    calc.h \
    credit.h \
    plot.h
#    ../calc_c.h

FORMS += \
    calc.ui \
    credit.ui \
    plot.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
