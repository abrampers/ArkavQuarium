#ifndef AQUARIUM_HPP
#define AQUARIUM_HPP

#include "../linkedlist/LinkedList.hpp"
#include "../coin/Coin.hpp"
#include "../guppy/Guppy.hpp"
#include "../pellet/Pellet.hpp"
#include "../piranha/Piranha.hpp"
#include "../snail/Snail.hpp"

class Aquarium {
    private:
        const double xMax, yMax;
        double curr_time;
        LinkedList<Piranha*> content_piranha;
        LinkedList<Guppy*> content_guppy;
        LinkedList<Snail*> content_snail;
        LinkedList<Pellet*> content_pellet;
        LinkedList<Coin*> content_coin;

    public:
        /* Constructor */
        Aquarium();

        /* Destructor */
        ~Aquarium();
        
        /* Operator Overloading */

        /* Setter & Getter */
        double getXMax() const;
        double getYMax() const;
        LinkedList<Piranha*>& getPiranhaList();
        LinkedList<Guppy*>& getGuppyList();
        LinkedList<Snail*>& getSnailList();
        LinkedList<Pellet*>& getPelletList();
        LinkedList<Coin*>& getCoinList();
        
        void setCurrTime(double t);

        /***********/
        /* Methods */
        /***********/
        /* A function that will increment time and processes all content (coin moves down, etc.) */
        void updateState();

        /* Create and Delete Operations for Aquatic */
        void createPiranha();
        void createGuppy();
        void createSnail();
        void createPellet();
        void createCoin();
        void deletePiranha(Piranha* p);
        void deleteGuppy(Guppy* g);
        void deleteSnail(Snail* s);
        void deletePellet(Pellet* p);
        void deleteCoin(Coin* c);
};

#endif