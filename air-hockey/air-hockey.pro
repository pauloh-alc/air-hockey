TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TARGET = air-hockey

# Configuração dos arquivos fontes
SOURCES += \
        src/ai.cpp \
        src/puck.cpp \
        src/goal.cpp \
        src/player.cpp \
        src/table.cpp \
        src/shapes.cpp \
        main.cpp

# Concfigurações dos headers
HEADERS += \
    include/ai.h \
    include/puck.h \
    include/goal.h \
    include/player.h \
    include/sizes.h \
    include/table.h \
    include/shapes.h

# Configuração das bibliotecas
LIBS += \
    -lglut \
    -lGL \
    -lGLU

# Configuração dos diretórios de includes
INCLUDEPATH += \
    /usr/include \
    /usr/include/GL \
    /usr/include/GL/freeglut \
    /usr/include/glm \
    include
