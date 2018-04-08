#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "../aquatic/Aquatic.hpp"
#include "../fish/Fish.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../guppy/Guppy.hpp"
#include "../common/Common.hpp"
#include <cmath>

class Piranha : public Fish, public Aquatic {
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

        /* Implements pure virtual method from Fish */
        void eat();

        /* Create new coin, value depends on type of fish and its phase, or what it eats */
        void dropCoin();
};

#endif