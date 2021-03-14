#ifndef PELLET_HPP
#define PELLET_HPP

#include "Aquatic.hpp"

//! Class Pellet. Represents all Pellet object in Aquarium.
class Pellet : public Aquatic {
	public:
	/* Constructor */
        //! A constructor.
        /*! Constructs a new Coin object. 
                \param double x x-axis position of the Coin.
                \param double y y-axis position of the Coin.
                \param int value Value of the Coin.
            \param Aquarium *aquarium The Aquarium that contains the object.
        */
	Pellet(double x, double y, Aquarium* a);

	/***********/
        /* Methods */
        /***********/
        //! Implements pure virtual method from Aquatic.
        void updateState() override;

        //! Implements pure virtual method from Aquatic.
        void move() override;

        //! Implements pure virtual method from Aquatic.
        void updateProgress() override;

        //! Implements pure virtual method from Aquatic.
        void dead() override;
};

#endif
