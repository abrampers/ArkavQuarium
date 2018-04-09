#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "common/Helper.hpp"
#include "aquatic/Aquatic.hpp"
#include "fish/Fish.hpp"
#include "linkedlist/LinkedList.hpp"
#include "pellet/Pellet.hpp"

class Guppy : public Aquatic, public Fish {
    private:
        Pellet *nearest_pellet;
        double last_drop_coin;

        /****************************/
        /* Private member functions */
        /****************************/
        void findNearestPellet();
        bool nearestPelletInRange();
        /* Euclidean distance from guppy to pellet */
        double distanceToPellet(Pellet *p);
    public:
    	/* Constructor */
        Guppy(Aquarium *aquarium);

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