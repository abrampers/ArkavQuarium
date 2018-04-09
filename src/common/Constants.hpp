#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

enum Direction {
    left, right
};

/* Game constants */
const int gameFrameRate = 35;
const int gameScreenWidth = 1024;
const int gameScreenHeight = 768;

const int maxLevel = 3;
const double randomMoveInterval = 4; 		/* Ini juga detik ya brok */
const double pi = 3.14159265;

/* Coin constants */
const double COIN_MOVE_SPEED = 100; 			/* TBD */
const double COIN_DELETION_INTERVAL = 10; 	/* TBD */

/* Guppy constants */
const int guppyFoodThres = 20;
const double guppyEatRadius = 1.25;
const double guppyFullInterval = 5; 		/* Ini detik ye bos */
const double guppyHungerInterval = 10;
const double guppyMoveSpeed = 60; 			/* Pixels per second */

const double guppyCoinInterval = 8;
const double guppyCoinMultiplier = 10;

/* Pellet constants */
const double PELLET_SPEED = 1.0; 			/* TBD */

/* Piranha constants */
const int piranhaFoodThres = 50;
const double piranhaEatRadius = 200;
const double piranhaFullInterval = 10; 		/* Ini detik ye bos */
const double piranhaHungerInterval = 15;
const double piranhaMoveSpeed = 82;
const double piranhaCoinInterval = 8;
const int guppyPrice = 100;

/* Snail constants */
const double SNAIL_SPEED = 80;
const double SNAIL_RADIUS = 1.0;

#endif