#ifndef COIN_HPP
#define COIN_HPP

#include "../aquatic/Aquatic.hpp"

class Coin : public Aquatic {
	private:
		const int value;
	public:
		//ctor
		Coin();
		Coin(int);

		//methods
		void move();

        void update_state(); // What action will it take if the time increments
};

#endif