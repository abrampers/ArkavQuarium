#ifndef COIN_HPP
#define COIN_HPP

#include "Aquatic.hpp"

//! Class Coin. Represents all Coin object in Aquarium.
class Coin : public Aquatic {
	private:
		const int value;
		double last_bottom_time;
	public:
		/* Constructor */
		//! A constructor.
        /*! Constructs a new Coin object. 
        	\param double x x-axis position of the Coin.
        	\param double y y-axis position of the Coin.
        	\param int value Value of the Coin.
            \param Aquarium *aquarium The Aquarium that contains the object.
        */
		Coin(double x, double y, int value, Aquarium* aquarium);

		/* Getter - Setter */
		//! Getter for value.
        /*!  
            \return int value.
        */
		int getValue() const;

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
