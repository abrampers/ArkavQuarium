#include "Game.hpp"

using namespace std;

Game::Game(int screen_width, int screen_height):
screenWidth(screen_width), 
screenHeight(screen_height), 
frameRate(120), 
graphics(screen_width, screen_height),
coin(0), 
egg(0) {
    /* Initialize game graphics */
    bool succ = graphics.init();
    if (!succ) {
        cerr << "ERROR: Game initialization failed." << endl;
    }
}

/* Destructor */
Game::~Game() {
    /* Delete objects */
    delete aquarium;

    /* Close game graphics */
    graphics.close();
}

/* Initialize game state */
void Game::initState() {
    aquarium = new Aquarium(screenWidth, screenHeight - 80);
}

/* Load game state from an external file */
void Game::loadState(string filename) {
    /* TODO */
}

/* Save game state to an external file */
void Game::saveState(string filename) {
    /* TODO */
}

/* Start a game */
void Game::startGame() {
    double frame_start_time = graphics.timeSinceStart();
    bool running = true;

    while (running) {
        /* Handle input from OS */
        graphics.handleInput();
        if (graphics.quitPressed()) {
            running = false;
        }

        /* TODO: Update objects state */
        aquarium->updateState(frame_start_time);
        LinkedList<Guppy*>& guppy_list = aquarium->getGuppyList();

        /* Clear objects on screen */
        // graphics.clearScreen();

        /* TODO: Draw objects */
        graphics.drawBackground();
        for (int i = 0; i < guppy_list.getLength(); i++) {
            Guppy *curr_guppy = guppy_list.get(i);
            int curr_guppy_x = curr_guppy->getX();
            int curr_guppy_y = curr_guppy->getY();
            int curr_guppy_level = curr_guppy->getLevel();
            Direction curr_guppy_direction = curr_guppy->getDirection();
            graphics.drawGuppy(curr_guppy_x, curr_guppy_y, curr_guppy_level, curr_guppy_direction);
        }
        
        /* Update objects on screen */
        graphics.updateScreen();

        /* Wait until frame time reaches 1 / frameRate */
        double frame_curr_time = graphics.timeSinceStart();
        while (frame_curr_time - frame_start_time < 1.0 / frameRate) {
            frame_curr_time = graphics.timeSinceStart();
        }
    }
}

/* Run game sequence */
void Game::run() {

    /* TODO: Show main menu */
    
    /* Init game states */
    initState();
    startGame();

}
