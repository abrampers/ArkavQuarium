#ifndef COIN_HPP
#define COIN_HPP
#include "Aquatic.hpp"

class Coin : public Aquatic {
	private:
		const int value;
	public:
		//ctor
		Coin();
		Coin(int);

		//methods
        void advTimeHandler(); // What action will it take if the time increments
};

#endif