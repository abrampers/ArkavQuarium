/* Driver file for Pellet */
#include <iostream>
#include "aquarium/Aquarium.hpp"
#include "pellet/Pellet.hpp"
using namespace std;

int main() {
	int ret;
	double x, y;
	Aquarium a(0, 0, 480, 640);
	Pellet c(5, 5, &a);

	cout << "#######################" << endl;
	cout << "# RUNNING PELLET TEST #" << endl;
	cout << "#######################" << endl;

	/* Test 1 */
	cout << "Running TEST 1" << endl;
	x = c.getX();
	y = c.getY();
	a.setCurrTime(100);
	c.updateState();
	ret = y <= c.getY() ? 1 : 0;
	cout << "	TEST 1: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 2 */
	cout << "Running TEST 2" << endl;
	x = c.getX();
	y = c.getY();
	a.setCurrTime(200);
	c.updateState();
	ret = y <= c.getY() ? 1 : 0;
	cout << "	TEST 2: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 3 */
	cout << "Running TEST 3" << endl;
	x = c.getX();
	y = c.getY();
	a.setCurrTime(300);
	c.updateState();
	ret = y <= c.getY() ? 1 : 0;
	cout << "	TEST 3: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 4 */
	cout << "Running TEST 4" << endl;
	x = c.getX();
	y = c.getY();
	a.setCurrTime(400);
	c.updateState();
	ret = x == c.getX() ? 1 : 0;
	cout << "	TEST 4: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 5 */
	cout << "Running TEST 5" << endl;
	x = c.getX();
	y = c.getY();
	a.setCurrTime(500);
	c.updateState();
	ret = x == c.getX() ? 1 : 0;
	cout << "	TEST 5: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	cout << endl << endl;

}