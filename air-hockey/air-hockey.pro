TEMPLATE = app
CONFIG += console c++17
CONFIG -= app_bundle
CONFIG -= qt

TARGET = air-hockey

# Configuração dos arquivos fontes
SOURCES += \
        src/ai.cpp \
        src/disco.cpp \
        src/gol.cpp \
        src/jogador.cpp \
        src/jogo.cpp \
        src/mesa.cpp \
        main.cpp

# Concfigurações dos headers
HEADERS += \
    include/ai.h \
    include/disco.h \
    include/gol.h \
    include/jogador.h \
    include/jogo.h \
    include/mesa.h

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
