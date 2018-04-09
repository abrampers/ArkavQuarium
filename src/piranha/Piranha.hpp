#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "aquatic/Aquatic.hpp"
#include "fish/Fish.hpp"
#include "linkedlist/LinkedList.hpp"
#include "guppy/Guppy.hpp"

class Piranha : public Aquatic, public Fish {
	private:
		Guppy *nearest_guppy;

        /****************************/
        /* Private member functions */
        /****************************/
        void findNearestGuppy();
        bool nearestGuppyInRange();
        /* Euclidean distance from guppy to pellet */
        double distanceToGuppy(Guppy *p);
    public:
    	/* Constructor */
        Piranha(Aquarium *aquarium);

        /***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState();
        void move();
        void updateProgress();
        void dead();

        /* Implements pure virtual method from Fish */
        void eat();
        void dropCoin();
};

#endif