#ifndef CONSTANTS_HPP
#define CONSTANTS_HPP

enum GameState { win, lose, closed };

enum Direction { left, right };

enum State {
  movingLeft,
  movingRight,
  turningLeft,
  turningRight,
  deadLeft,
  deadRight,
  fading,
  stillRight,
  stillLeft,
  eatingRight,
  eatingLeft
};

/* Graphics UI constants */
const int coinTextSize = 23;
const int coinTextX = 885;
const int coinTextY = 63;
const int coinTextColorR = 166;
const int coinTextColorG = 255;
const int coinTextColorB = 112;

const int priceTextSize = 15;
const int priceTextColorR = 166;
const int priceTextColorG = 255;
const int priceTextColorB = 112;

const int guppyPriceTextX = 46;
const int guppyPriceTextY = 75;

const int pelletPriceTextX = 157;
const int pelletPriceTextY = 75;

const int piranhaPriceTextX = 367;
const int piranhaPriceTextY = 75;

const int snailPriceTextX = 485;
const int snailPriceTextY = 75;

const int eggPriceTextX = 722;
const int eggPriceTextY = 75;

const int eggCountTextSize = 30;
const int eggCountTextX = 739;
const int eggCountTextY = 23;
const int eggCountTextColorR = 80;
const int eggCountTextColorG = 24;
const int eggCountTextColorB = 186;

/* Click targets */
const int buyGuppyButtonXStart = 33;
const int buyGuppyButtonXEnd = 109;
const int buyGuppyButtonYStart = 7;
const int buyGuppyButtonYEnd = 72;

const int buyPiranhaButtonXStart = 354;
const int buyPiranhaButtonXEnd = 430;
const int buyPiranhaButtonYStart = 7;
const int buyPiranhaButtonYEnd = 72;

const int buySnailButtonXStart = 473;
const int buySnailButtonXEnd = 547;
const int buySnailButtonYStart = 7;
const int buySnailButtonYEnd = 72;

const int buyEggButtonXStart = 708;
const int buyEggButtonXEnd = 783;
const int buyEggButtonYStart = 7;
const int buyEggButtonYEnd = 72;

const int mainStartButtonXStart = 560;
const int mainStartButtonXEnd = 900;
const int mainStartButtonYStart = 80;
const int mainStartButtonYEnd = 185;

const int winStartButtonXStart = 406;
const int winStartButtonXEnd = 621;
const int winStartButtonYStart = 598;
const int winStartButtonYEnd = 666;

const int loseStartButtonXStart = 406;
const int loseStartButtonXEnd = 621;
const int loseStartButtonYStart = 598;
const int loseStartButtonYEnd = 666;

/* Game constants */
const int gameInitialCoin = 200;
const int gameFrameRate = 35;
const int gameScreenWidth = 1024;
const int gameScreenHeight = 768;
const int gameScreenLeftPadding = 20;
const int gameScreenRightPadding = 20;
const int gameScreenTopPadding = 170;
const int gameScreenBottomPadding = 65;
const int maxLevel = 3;
const int eggPrice = 2000;
const double randomMoveInterval = 2; /* Ini juga detik ya brok */
const double pi = 3.14159265;

/* Coin's constant */
const double coinMoveSpeed = 100;      /* TBD */
const double coinDeletionInterval = 5; /* TBD */
const int coinClickRadius = 20;

/* Guppy constants */
const int guppyFoodThres = 2;
const int guppyPrice = 100;
const double guppyEatRadius = 20;
const double guppyFullInterval = 15; /* Ini detik ye bos */
const double guppyHungerInterval = 15;
const double guppyMoveSpeed = 60; /* Pixels per second */
const double guppyCoinInterval = 8;
const double guppyCoinMultiplier = 10;

/* Pellet's constant */
const double pelletSpeed = 0.125; /* TBD */
const int pelletPrice = 10;

/* Piranha constants */
const int piranhaFoodThres = 50;
const int piranhaPrice = 400;
const double piranhaEatRadius = 50;
const double piranhaFullInterval = 15; /* Ini detik ye bos */
const double piranhaHungerInterval = 15;
const double piranhaMoveSpeed = 82;
const double piranhaCoinInterval = 8;

/* Snail's constant */
const int snailPrice = 1000;
const double snailSpeed = 80;
const double snailEatRadius = 50;

/* Progress */
const double progressPeriod = 10;
const double guppyTurnProgressIncrementTime = 0.05;
const double guppyMoveProgressIncrementTime = 0.05;
const double guppyDeadProgressIncrementTime = 0.16;
const double guppyEatProgressIncrementTime = 0.05;
const double piranhaTurnProgressIncrementTime = 0.05;
const double piranhaMoveProgressIncrementTime = 0.05;
const double piranhaDeadProgressIncrementTime = 0.16;
const double piranhaEatProgressIncrementTime = 0.05;
const double snailTurnProgressIncrementTime = 0.05;
const double snailMoveProgressIncrementTime = 0.05;
const double pelletProgressIncrementTime = 0.05;
const double coinProgressIncrementTime = 0.05;
const double coinFadeProgressIncrementTime =
    coinDeletionInterval / progressPeriod;

#endif