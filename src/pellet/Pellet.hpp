#ifndef PELLET_HPP
#define PELLET_HPP

#include "aquatic/Aquatic.hpp"

class Pellet : public Aquatic {
	public:
		/*ctor*/
		Pellet(double x, Aquarium* a);

		/***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState();
        void move();
};

#endif