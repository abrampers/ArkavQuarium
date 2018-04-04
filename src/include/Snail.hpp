#ifndef SNAIL_HPP
#define SNAIL_HPP
#include "Aquatic.hpp"

class Snail : public Aquatic {
	private:
		const int coin_radius;
	public:
		//ctor
		Snail(); //Initialize y-axis location to be always at the bottom of the aquarium

		//methods
        void advTimeHandler() = 0; // What action will it take if the time increments
};

#endif