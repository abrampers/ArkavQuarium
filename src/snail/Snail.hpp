#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "common/Constants.hpp"
#include "common/Helper.hpp"
#include "aquatic/Aquatic.hpp"
#include "coin/Coin.hpp"
#include <cmath>

class Snail : public Aquatic {
	private:
		const double coin_radius;
		Coin* nearest_coin;
		int hold_coin_value;
		int x_dir;

		/****************************/
        /* Private member functions */
        /****************************/
		double getDistance(Aquatic*, Aquatic*);
		bool isCoinOnTop();
		void pickCoin(Coin*);
		void findNearestCoin();
        bool nearestCoinInRange();
	public:
		/*ctor*/
		Snail(Aquarium*); //Initialize y-axis location to be always at the bottom of the aquarium

		/*getter-setter*/
        Direction getDirection();

		/*methods*/
        void updateState(); // What action will it take if the time increments
        void move();
};

#endif