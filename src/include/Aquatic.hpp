// A parent class for aquatic entities sans fish 
#ifndef AQUATIC_HPP
#define AQUATIC_HPP

#include "Aquarium.hpp"

class Aquatic {
    private:
        Aquarium* a;
        int x, y;
        const int move_speed; /* Movement Speed */
    public:
        /* Constructor */
    	Aquatic();

        /* User Defined Constructor */
    	Aquatic(int, int);

        /* Destructor */
    	~Aquatic();

    	/* Methods */
        Aquarium *getAquarium();

        bool isInside(); // Whether the position is inside the aquarium or not.

        virtual bool move() = 0; // All aquatic entities can move. Returns whether the movement is successful or not.

        virtual void advTimeHandler() = 0; // What action will it take if the time increments
};

#endif