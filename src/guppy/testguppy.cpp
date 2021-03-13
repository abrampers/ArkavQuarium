/* Driver file for Guppy */
#include <iostream>
#include "Aquarium.hpp"
#include "Guppy.hpp"
using namespace std;

int main() {
	int ret;
	Aquarium a(0, 0, 480, 640);
	Guppy *g = a.getGuppyList().get(0);

	cout << "######################" << endl;
	cout << "# RUNNING GUPPY TEST #" << endl;
	cout << "######################" << endl;

	/* Test 1 */
	cout << "Running TEST 1" << endl;
	a.createPellet(g->getX(), g->getY());
	g->setHungry(true);
	a.setCurrTime(5);
	g->updateState();
	ret = a.getPelletList().getLength() == 0 ? 1 : 0;
	cout << "	TEST 1: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 2 */
	cout << "Running TEST 2" << endl;
	a.setCurrTime(200);
	g->dropCoin();
	ret = a.getCoinList().getLength();
	cout << "	TEST 2: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	cout << endl << endl;

}