# Masukkan semua file cpp Anda
OBJS = src/common/Helper.cpp \
src/graphics/Graphics.cpp \
src/game/Game.cpp \
src/aquarium/Aquarium.cpp \
src/aquatic/Aquatic.cpp \
src/fish/Fish.cpp \
src/piranha/Piranha.cpp \
src/guppy/Guppy.cpp \
src/coin/Coin.cpp \
src/pellet/Pellet.cpp \
src/snail/Snail.cpp 

CC = g++
COMPILER_FLAGS = -std=c++11 -Wall -O2 -Isrc/
LINKER_FLAGS = -lSDL2 -lSDL2_image -lSDL2_ttf
OBJ_NAME = arkavquarium
all : src/main.cpp $(OBJS)
	$(CC) src/main.cpp $(OBJS) $(COMPILER_FLAGS) $(LINKER_FLAGS) -o $(OBJ_NAME)

test :
	make testAquarium && make testCoin && make testGuppy && make testPellet && make testPiranha && make testSnail

runTest :
	./testAquarium && ./testCoin && ./testGuppy && ./testPellet && ./testPiranha && ./testSnail

clean : 
	rm testAquarium && rm testCoin && rm testGuppy && rm testPellet && rm testPiranha && rm testSnail

testAquarium : src/aquarium/testaquarium.cpp $(OBJS)
	$(CC) src/aquarium/testaquarium.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testAquarium

testCoin : src/coin/testcoin.cpp $(OBJS)
	$(CC) src/coin/testcoin.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testCoin

testGuppy : src/guppy/testguppy.cpp $(OBJS)
	$(CC) src/guppy/testguppy.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testGuppy

testPellet : src/pellet/testpellet.cpp $(OBJS)
	$(CC) src/pellet/testpellet.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testPellet

testPiranha : src/piranha/testpiranha.cpp $(OBJS)
	$(CC) src/piranha/testpiranha.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testPiranha

testSnail : src/snail/testsnail.cpp $(OBJS)
	$(CC) src/snail/testsnail.cpp  src/common/Helper.cpp src/aquarium/Aquarium.cpp src/aquatic/Aquatic.cpp src/fish/Fish.cpp src/piranha/Piranha.cpp src/guppy/Guppy.cpp src/coin/Coin.cpp src/pellet/Pellet.cpp \src/snail/Snail.cpp $(COMPILER_FLAGS) -o testSnail
