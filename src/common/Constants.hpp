#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

enum Direction {
    left, right
};

const int maxLevel = 3;
const double randomMoveInterval = 2; 		/* Ini juga detik ya brok */
const double pi = 3.14159265;

/* Coin's constant */
const double coinMoveSpeed = 10; 			/* TBD */
const double coinDeletionInterval = 10; 	/* TBD */

/* Guppy's constant */
const int guppyFoodThres = 20;
const double guppyEatRadius = 1.25;
const double guppyFullInterval = 5; 		/* Ini detik ye bos */
const double guppyHungerInterval = 100;
const double guppyMoveSpeed = 120; 			/* Pixels per second */
const double guppyCoinInterval = 8;
const double guppyCoinMultiplier = 10;

/* Pellet's constant */
const double pelletSpeed = 1.0; 			/* TBD */

/* Piranha's constant */
const int piranhaFoodThres = 10;
const double piranhaEatRadius = 150;
const double piranhaFullInterval = 10; 		/* Ini detik ye bos */
const double piranhaHungerInterval = 15;
const double piranhaMoveSpeed = 250;
const double piranhaCoinInterval = 8;
const int guppyPrice = 100;

/* Snail's constant */
const double snailSpeed = 80;
const double snailEatRadius = 50;

#endif