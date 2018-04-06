// Driver for DoublyLinkedList class
#include <iostream>
#include "include/LinkedList.hpp"

int main() {
	LinkedList<int> dll;

	dll.add(1);
	dll.add(3);
	dll.add(5);
	dll.add(1);
	dll.add(6);
	dll.add(0);
	dll.add(8);
	dll.add(3);

	LinkedList<int> dll2 = dll;
	dll2.remove(3);
	dll.print();
	dll2.print();

	return 0;
}