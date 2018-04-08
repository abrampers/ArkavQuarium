#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "../aquatic/Aquatic.hpp"
#include "../fish/Fish.hpp"

class Piranha : public Fish, public Aquatic {
	private:
		Guppy *nearest_guppy;
    public:
    	/* Constructor */
        Piranha();

        /* Create new coin, value depends on type of fish and its phase, or what it eats */
        void dropCoin(); 

        /***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState(double current_time);
        void move(double t);

        /* Implements pure virtual method from Fish */
        void eat(double current_time);

        void dropCoin();
};

#endif