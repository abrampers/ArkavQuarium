#ifndef GAME_HPP
#define GAME_HPP

// #include "Aquarium.hpp"
// #include "Aquatic.hpp"
// #include "LinkedList.hpp"
// #include "Coin.hpp"
// #include "Guppy.hpp"
// #include "Pellet.hpp"
// #include "Piranha.hpp"
// #include "Snail.hpp"
#include "Graphics.hpp"

#include <iostream>
#include <math.h>
#include <sstream>

class Game {
    private:
        const int SCREEN_WIDTH = 640;
        const int SCREEN_HEIGHT = 480;
        double start_time, curr_time;
        Aquarium *aquarium;

    public:
        /* Constructor */
        Game();

        /* Destructor */
        ~Game();

        /* Start a game */
        void run();
};

#endif