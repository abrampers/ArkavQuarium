#ifndef PELLET_HPP
#define PELLET_HPP

#include "../aquatic/Aquatic.hpp"

class Pellet : public Aquatic {
	public:
		//ctor
		Pellet();

		//methods
        void updateState(); // What action will it take if the time increments
        void move();
};

#endif