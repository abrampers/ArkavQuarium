#ifndef PELLET_HPP
#define PELLET_HPP

#include "../aquatic/Aquatic.hpp"

class Pellet : public Aquatic {
	public:
		/*ctor*/
		Pellet(double, Aquarium*);

		/***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState();
        void move();
};

#endif