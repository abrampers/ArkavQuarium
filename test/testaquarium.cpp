/* Driver file for Aquarium */
#include <iostream>
#include "Aquarium.hpp"
using namespace std;

int main() {
	int ret;
	Aquarium a(0, 0, 480, 640);

	cout << "#########################" << endl;
	cout << "# RUNNING AQUARIUM TEST #" << endl;
	cout << "#########################" << endl;

	/* Test 1 */
	cout << "Running TEST 1" << endl;
	a.createPiranha();
	ret = a.getPiranhaList().getLength();
	cout << "	TEST 1: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 2 */
	cout << "Running TEST 2" << endl;
	a.createGuppy();
	ret = a.getGuppyList().getLength();
	cout << "	TEST 2: ";
	if(ret == 2) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 3 */
	cout << "Running TEST 3" << endl;
	a.createSnail();
	ret = a.getSnailList().getLength();
	cout << "	TEST 3: ";
	if(ret == 2) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 4 */
	cout << "Running TEST 4" << endl;
	a.createPellet(5, 5);
	ret = a.getPelletList().getLength();
	cout << "	TEST 4: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 5 */
	cout << "Running TEST 5" << endl;
	a.createCoin(5, 5, 1);
	ret = a.getCoinList().getLength();
	cout << "	TEST 5: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	Piranha *pir = a.getPiranhaList().get(0);
	Guppy *gup = a.getGuppyList().get(0);
	Snail *snail = a.getSnailList().get(0);
	Coin *c = a.getCoinList().get(0);
	Pellet *p = a.getPelletList().get(0);

	/* Test 6 */
	cout << "Running TEST 6" << endl;
	a.deletePiranha(pir);
	ret = a.getPiranhaList().getLength();
	cout << "	TEST 6: ";
	if(ret == 0) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 7 */
	cout << "Running TEST 7" << endl;
	a.deleteGuppy(gup);
	ret = a.getGuppyList().getLength();
	cout << "	TEST 7: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 8 */
	cout << "Running TEST 8" << endl;
	a.deleteSnail(snail);
	ret = a.getSnailList().getLength();
	cout << "	TEST 8: ";
	if(ret == 1) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 9 */
	cout << "Running TEST 9" << endl;
	a.deletePellet(p);
	ret = a.getPelletList().getLength();
	cout << "	TEST 9: ";
	if(ret == 0) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	/* Test 10 */
	cout << "Running TEST 10" << endl;
	a.deleteCoin(c);
	ret = a.getCoinList().getLength();
	cout << "	TEST 10: ";
	if(ret == 0) {
		cout << "SUCCESS" << endl;
	} else {
		cout << "FAIL" << endl;
	}

	cout << endl << endl;

}