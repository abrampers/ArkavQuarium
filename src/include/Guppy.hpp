#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "Aquatic.hpp"
#include "Fish.hpp"

class Guppy : public Fish, public Aquatic {
    private:
        const double coin_creation_interval; // Time needed for coin creation

    public:
    	//ctor
        Guppy();

        //methods
        void updateState(); // What action will it take if the time increments
        void eat();
        void move();
};

#endif