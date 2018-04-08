# Masukkan semua file cpp Anda
OBJS = src/main.cpp \
src/common/Common.cpp \
src/graphics/Graphics.cpp \
src/game/Game.cpp \
src/aquarium/Aquarium.cpp \
src/aquatic/Aquatic.cpp \
src/fish/Fish.cpp \
src/guppy/Guppy.cpp \
src/coin/Coin.cpp \
src/pellet/Pellet.cpp \
src/snail/Snail.cpp 

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = arkavquarium
all : $(OBJS)
	$(CC) $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)
