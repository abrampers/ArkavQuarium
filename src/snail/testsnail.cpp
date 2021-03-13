/* Driver file for Snail */
#include <iostream>
#include "Aquarium.hpp"
#include "Snail.hpp"
using namespace std;

int main() {
	int ret;
	double y;
	Aquarium a(0, 0, 480, 640);
	Snail *s = a.getSnailList().get(0);

	cout << "######################" << endl;
	cout << "# RUNNING SNAIL TEST #" << endl;
	cout << "######################" << endl;

	/* Test 1 */
	cout << "Running TEST 1" << endl;
	a.createCoin(s->getX(), s->getY(), 100);
	s->updateState();
	ret = a.getCoinList().getLength() == 0 ? 1 : 0;
	cout << "	TEST 1: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 2 */
	cout << "Running TEST 2" << endl;
	a.setCurrTime(200);
	y = s->getY();
	s->updateState();
	ret = y == s->getY() ? 1 : 0;
	cout << "	TEST 2: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	cout << endl << endl;

}