TEMPLATE = app
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    rubik.cpp \
    scene.cpp \
    cube.cpp \
    sticker.cpp \
    vao.cpp \
    texture.cpp \
    minicube.cpp \
    object.cpp \
    light.cpp

INCLUDEPATH += $$PWD/include
DEPENDPATH += $$PWD/include

LIBS += -L$$PWD/lib/ -lSOIL -lGL -lGLU -lGLEW -lglut

HEADERS += \
    rubik.h \
    scene.h \
    cube.h \
    sticker.h \
	vao.h \
    texture.h \
    minicube.h \
    object.h \
    light.h

DISTFILES += \
    README.md

