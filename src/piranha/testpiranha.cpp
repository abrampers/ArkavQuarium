/* Driver file for Piranha */
#include <iostream>
#include "aquarium/Aquarium.hpp"
#include "piranha/Piranha.hpp"
using namespace std;

int main() {
	int ret;
	Aquarium a(0, 0, 480, 640);
	a.createPiranha();
	Piranha *p = a.getPiranhaList().get(0);

	cout << "########################" << endl;
	cout << "# RUNNING PIRANHA TEST #" << endl;
	cout << "########################" << endl;

	/* Test 1 */
	cout << "Running TEST 1" << endl;
	Guppy *g = a.getGuppyList().get(0);
	g->setX(p->getX());
	g->setY(p->getY());
	p->setHungry(true);
	a.setCurrTime(5);
	p->updateState();
	ret = a.getGuppyList().getLength() == 0 ? 1 : 0;
	cout << "	TEST 1: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 2 */
	cout << "Running TEST 2" << endl;
	ret = a.getCoinList().getLength();
	cout << "	TEST 2: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	cout << endl << endl;

}