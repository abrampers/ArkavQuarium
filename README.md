# ARKAVQUARIUM 2.0

ArkavQuarium 2.0 is a simplified version of the most famous **InsaniQuarium** game. The goal of this game is to buy an egg using player's **Coin**. The coin is produced by **Guppy** or **Piranha** and can be taken by the **Snail** or by the player himself. This game is made with the most beautiful animation made by us for our beloved players. We hope this game will change our lives and fate.

[Home](doc/images/home.png)
[Game](doc/images/game.png)

## Getting Started

These instructions will tell you how to compile and play the game.

### Prerequisites

Make sure you have installed these packages:
- SDL2
- SDL2_image
- SDL2_ttf
- CMake

### Testing

To build the test, execute
```sh-session
mkdir build
cd build
cmake ..
make
```

To run the test, execute
```sh-session
# inside build folder
make test
```

### Compiling
To build the game, execute
```sh-session
# inside build folder
make
```

Next, run the game by executing this command
```
# inside build folder
./arkavquarium
```

and enjoy the game.

## Tools

* [CMake](https://gitlab.kitware.com/cmake/cmake) - Build system
* [SDL2](https://www.libsdl.org/download-2.0.php) - GUI Library
* [GoogleTest](https://github.com/google/googletest) - Unit testing library

## Authors

* **Abram Perdanaputra Situmorang** - *Initial work* - [abrampers](https://github.com/abrampers)
* **Faza Fahleraz** - *Initial work* - [ffahleraz](https://github.com/ffahleraz)
* **Senapati Sang Diwangkara** - *Initial work* - [diwangs](https://github.com/diwangs)
* **Yusuf Rahmat Pratama** - *Initial work* - [yusufrahmatp](https://github.com/yusufrahmatp)

## Acknowledgments

* InsaniQuarium game maker - [PopCap](https://www.ea.com/studios/popcap)
