#ifndef PIRANHA_HPP
#define PIRANHA_HPP

#include "../aquatic/Aquatic.hpp"
#include "../fish/Fish.hpp"

class Piranha : public Fish, public Aquatic {
	private:
		double last_eat_time;
        double last_random_time;
    public:
    	//ctor
        Piranha();

        /* Create new coin, value depends on type of fish and its phase, or what it eats */
        void dropCoin(); 

        //methods
        void updateState(); // What action will it take if the time increments
        void eat();
        void move();
};

#endif