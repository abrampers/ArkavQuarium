#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "LinkedList.hpp"
#include "Coin.hpp"
#include "Guppy.hpp"
#include "Pellet.hpp"
#include "Piranha.hpp"
#include "Snail.hpp"

/* Forward declaration */ 
class Aquatic;

class Aquarium {
    private:
        const double xMax, yMax;
        double curr_time;
        LinkedList<Coin*> content_coin;
        LinkedList<Guppy*> content_guppy;
        LinkedList<Pellet*> content_pellet;
        LinkedList<Piranha*> content_piranha;
        LinkedList<Snail*> content_snail;
    public:
        /* Constructor */
        Aquarium();

        /* Destructor */
        ~Aquarium();
        
        /* Operator Overloading */

        /* Setter & Getter */
        double getXMax() const;
        double getYMax() const;
        LinkedList<Coin*>& getCoinList();
        LinkedList<Guppy*>& getGuppyList();
        LinkedList<Pellet*>& getPelletList();
        LinkedList<Piranha*>& getPiranhaList();
        LinkedList<Snail*>& getSnailList();

        void setCurrTime(double t);

        /***********/
        /* Methods */
        /***********/
        /* A function that will increment time and processes all content (coin moves down, etc.) */
        void updateState();

        /* Create and Delete Operations for Aquatic */
        void createPiranha();
        void createPiranha();
        void createPiranha();
        void createPiranha();
        void deleteCoin(Coin* c);
        void deleteGuppy(Guppy* g);
        void deletePellet(Pellet* p);
        void deletePiranha(Piranha* p);
        void deleteSnail(Snail* s);
};

#endif