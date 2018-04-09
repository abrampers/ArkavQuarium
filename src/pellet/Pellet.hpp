#ifndef PELLET_HPP
#define PELLET_HPP

#include "aquatic/Aquatic.hpp"

class Pellet : public Aquatic {
	public:
	/* Constructor */
	Pellet(double x, double y, Aquarium* a);

	/***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState();
        void move();
        void updateProgress();
        void dead();
};

#endif