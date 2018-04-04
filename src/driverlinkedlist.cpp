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

	dll.print();

	dll.remove(3);
	dll.remove(1);
	dll.remove(5);
	dll.remove(1);
	dll.remove(6);
	dll.remove(0);
	dll.remove(8);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	dll.remove(3);
	

	dll.print();

	return 0;
}