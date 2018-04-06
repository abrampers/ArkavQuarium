#ifndef COIN_HPP
#define COIN_HPP

#include "../aquatic/Aquatic.hpp"

class Coin : public Aquatic {
	private:
		const int value;
	public:
		/* Constructor */
		Coin(double x, double y, Aquarium* aquarium);
		Coin(double x, double y, int value, double created_time, Aquarium* aquarium);

		/***********/
        /* Methods */
        /***********/
		/* Implements pure virtual method from Aquatic */
        void updateState(double current_time); 
        void move(double current_time);
};

#endif