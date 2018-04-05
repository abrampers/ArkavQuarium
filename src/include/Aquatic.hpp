/* A parent class for aquatic entities sans fish */
#ifndef AQUATIC_HPP
#define AQUATIC_HPP

#include "Aquarium.hpp"
#include <pair.h>

using namespace std;

class Aquatic {
    private:
        Aquarium* a;
        double x, y;
        double curr_time;
        pair position;
        const double move_speed; /* Movement Speed */
    public:
        /* Constructor */
    	Aquatic();

        /* User Defined Constructor */
    	Aquatic(int, int);

        /* Destructor */
    	~Aquatic();

        /*Getter - Setter */
        Aquarium *getAquarium();
        double getMoveSpeed() const;
        double getX();
        double getY();
        void setX();
        void setY();
        void setCurrTime(double t);
        void setPosition(pair p);

        /***********/
    	/* Methods */
        /***********/
        /* Whether the position is inside the aquarium or not. */
        bool isInside();                        

        /* All aquatic entities can move. Returns whether the movement is successful or not.*/
        virtual bool move() = 0;                

        /* What action will it take if the time increments*/
        virtual void updateState() = 0;         

};

#endif