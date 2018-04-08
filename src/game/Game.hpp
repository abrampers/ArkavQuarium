#ifndef GAME_HPP
#define GAME_HPP

#include "../common/Constants.hpp"
#include "../graphics/Graphics.hpp"
// #include "../aquarium/Aquarium.hpp"

#include <iostream>
#include <math.h>
#include <sstream>

using namespace std;

class Game {
    private:
        /* Graphics */
        const int screenWidth;
        const int screenHeight;
        const double frameRate;
        Graphics graphics;

        /* Game objects */
        Aquarium *aquarium;

        /* Player state */
        int coin;
        int egg;

    public:
        /* Constructor */
        Game(int screen_width, int screen_height);

        /* Destructor */
        ~Game();

        /* Initialize game state */
        void initState();

        /* Load game state from an external file */
        void loadState(string filename);

        /* Save game state to an external file */
        void saveState(string filename);

        /* Start a game */
        void startGame();

        /* Run game sequence */
        void run();
};

#endif