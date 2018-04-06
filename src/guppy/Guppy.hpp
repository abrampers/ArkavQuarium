#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "../aquatic/Aquatic.hpp"
#include "../fish/Fish.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../pellet/Pellet.hpp"
#include <cmath>

class Guppy : public Fish, public Aquatic {
    private:
        double last_eat_time;
        double last_random_time;
        Pellet *nearest_pellet;

        /****************************/
        /* Private member functions */
        /****************************/
        void findNearestPellet();
        bool nearestPelletInRange();
        /* Euclidean distance from guppy to pellet */
        double distanceToPellet(Pellet *p);
    public:
    	/* Coin Creation Interval */
    	static const double coin_creation_interval; 
    	/* Constructor */
        Guppy(Aquarium *aquarium); // Check is default constructor is necessary?
        Guppy(double created_time, Aquarium *aquarium);

        /***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState(double current_time); 
        void move(double current_time);

        /* Create new coin, value depends on type of fish and its phase, or what it eats */
        void dropCoin(); 

        /* Implements pure virtual method from Fish */
        void eat();
        
};

#endif