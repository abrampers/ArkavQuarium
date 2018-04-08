#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "../aquatic/Aquatic.hpp"
#include "../fish/Fish.hpp"
#include "../linkedlist/LinkedList.hpp"
#include "../pellet/Pellet.hpp"
#include <cmath>

class Guppy : public Fish, public Aquatic {
    private:
        Pellet *nearest_pellet;
        int x_dir;
        int y_dir;
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
        Guppy(Aquarium *aquarium); // Check is default constructor is necessary?
        Guppy(double created_time, Aquarium *aquarium);

        /* Getter & Setter */
        int getXDir();

        /***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        void updateState(double current_time); 
        void move(double current_time);

        /* Implements pure virtual method from Fish */
        void eat(double current_time);

        void dropCoin(double current_time); 
};

#endif