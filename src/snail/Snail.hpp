#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "../aquatic/Aquatic.hpp"
#include "../coin/Coin.hpp"

class Snail : public Aquatic {
	private:
		const double coin_radius;
		Coin* nearest_coin;

		double getDistance(Aquatic*, Aquatic*);
	public:
		//ctor
		Snail(Aquarium*); //Initialize y-axis location to be always at the bottom of the aquarium

		//methods
        void updateState(double); // What action will it take if the time increments
        void move(double);
		void pickCoin(Coin*);
};

#endif