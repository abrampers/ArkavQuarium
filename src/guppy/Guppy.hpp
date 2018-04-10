#ifndef GUPPY_HPP
#define GUPPY_HPP

#include "common/Helper.hpp"
#include "aquatic/Aquatic.hpp"
#include "fish/Fish.hpp"
#include "linkedlist/LinkedList.hpp"
#include "pellet/Pellet.hpp"

//! Class Guppy. Represents all Guppy object in Aquarium.
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
        //! A constructor.
        /*! Constructs a new Guppy object. 
            \param Aquarium *aquarium The Aquarium that contains the Guppy.
        */
        Guppy(Aquarium *aquarium);

        /***********/
        /* Methods */
        /***********/
        /* Implements pure virtual method from Aquatic */
        //! Implements pure virtual method from Aquatic
        void updateState(); 

        //! Implements pure virtual method from Aquatic
        void move();

        //! Implements pure virtual method from Aquatic
        void updateProgress();

        //! Implements pure virtual method from Aquatic
        void dead();

        /* Implements pure virtual method from Fish */
        //! Implements pure virtual method from Fish
        /*! Search for Pellet nearby, if the Pellet is in range, eat */
        void eat();

        //! Implements pure virtual method from Fish
        /*! Drop coin every constant time interval */
        void dropCoin(); 
};

#endif