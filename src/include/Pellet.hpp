#ifndef PELLET_HPP
#define PELLET_HPP
#include "Aquatic.hpp"

class Pellet : public Aquatic {
	public:
		//ctor
		Pellet();

		//methods
        void advTimeHandler(); // What action will it take if the time increments
}
};

#endif