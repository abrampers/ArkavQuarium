#ifndef SNAIL_HPP
#define SNAIL_HPP

#include "Aquatic.hpp"

class Snail : public Aquatic {
	private:
		const double coin_radius;
	public:
		//ctor
		Snail(); //Initialize y-axis location to be always at the bottom of the aquarium

		//methods
        void updateState(); // What action will it take if the time increments
        void move();
};

#endif