#ifndef GUPPY_HPP
#define GUPPY_HPP
#include "Aquatic.hpp"
#include "Fish.hpp"

class Guppy : public Fish, public Aquatic {
    private:
        const int coin_creation_interval; // Time needed for coin creation

    public:
    	//ctor
        Guppy();

        //methods
        void advTimeHandler(); // What action will it take if the time increments
        void eat();
};

#endif