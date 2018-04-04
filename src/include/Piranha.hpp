#ifndef PIRANHA_HPP
#define PIRANHA_HPP
#include "Aquatic.hpp"
#include "Fish.hpp"

class Piranha : public Fish, public Aquatic {
    public:
    	//ctor
        Piranha();

        //methods
        void advTimeHandler(); // What action will it take if the time increments
        void eat();
};

#endif