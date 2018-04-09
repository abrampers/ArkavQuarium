#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

enum Direction {
    left, right
};

enum State {
	movingLeft, movingRight, turningLeft, turningRight, deadLeft, deadRight, fading
};

/* Game constants */
const int gameFrameRate = 35;
const int gameScreenWidth = 1024;
const int gameScreenHeight = 768;
const int gameScreenLeftPadding = 30;
const int gameScreenRightPadding = 30;
const int gameScreenTopPadding = 30;
const int gameScreenBottomPadding = 70;
const int maxLevel = 3;
const double randomMoveInterval = 2; 		/* Ini juga detik ya brok */
const double pi = 3.14159265;

/* Coin's constant */
const double coinMoveSpeed = 100; 			/* TBD */
const double coinDeletionInterval = 100; 	/* TBD */
const int coinClickRadius = 20;

/* Guppy constants */
const int guppyFoodThres = 20;
const double guppyEatRadius = 20;
const double guppyFullInterval = 5; 		/* Ini detik ye bos */
const double guppyHungerInterval = 10;
const double guppyMoveSpeed = 60; 			/* Pixels per second */
const double guppyCoinInterval = 8;
const double guppyCoinMultiplier = 10;

/* Pellet's constant */
const double pelletSpeed = 0.125; 				/* TBD */

/* Piranha constants */
const int piranhaFoodThres = 50;
const double piranhaEatRadius = 50;
const double piranhaFullInterval = 10; 		/* Ini detik ye bos */
const double piranhaHungerInterval = 15;
const double piranhaMoveSpeed = 82;
const double piranhaCoinInterval = 8;
const int guppyPrice = 100;

/* Snail's constant */
const double snailSpeed = 80;
const double snailEatRadius = 50;

/* Progress */
const double progressPeriod = 10;
const double guppyTurnProgressIncrementTime = 0.05;
const double guppyMoveProgressIncrementTime = 0.05;
const double guppyDeadProgressIncrementTime = 0.1;
const double piranhaTurnProgressIncrementTime = 0.05;
const double piranhaMoveProgressIncrementTime = 0.05;
const double piranhaDeadProgressIncrementTime = 0.1;
const double snailTurnProgressIncrementTime = 0.05;
const double snailMoveProgressIncrementTime = 0.05;
const double pelletProgressIncrementTime = 0.05;
const double coinProgressIncrementTime = 0.05;
const double coinFadeProgressIncrementTime = coinDeletionInterval / progressPeriod;


#endif