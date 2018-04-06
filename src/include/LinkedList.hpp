/* Doubly linked list */
#ifndef DOUBLL_HPP
#define DOUBLL_HPP

#include <iostream>
using namespace std;

template <typename T> class Node;
template <typename T> class LinkedList;

template <typename T>
class Node {
private:
	T value;
	Node* prev;
	Node* next;
public:
	Node() {
		prev = NULL;
		next = NULL;
	}
	Node(T value) { 
		this->value = value; 
		prev = NULL;
		next = NULL;
	}
	~Node() { 
		Node* n = next;
		Node* p = prev;
		next = NULL;
		prev = NULL;
		delete next;
		delete prev;
		if(n != NULL) n->setPrev(p);
		if(p != NULL) p->setNext(n);
	}

	void setValue(T value) { this->value = value; }
	void setPrev(Node* p) { prev = p; }
	void setNext(Node* n) { next = n; }
	T getValue() { return value; }
	Node *getNext() { return this->next; }
	Node *getPrev() { return this->prev; }
};

template <typename T> 
class LinkedList {
private:
	Node<T> *head;
public:
	LinkedList() {
		head = new Node<T>;
		head->setValue(0);
		head->setNext(NULL);
		head->setPrev(NULL);
	}

	LinkedList(const LinkedList<T>& ll) {
		head = new Node<T>;
		head->setValue(0);
		head->setNext(NULL);
		head->setPrev(NULL);

		Node<T>* currLLNode = ll.head;
		while(currLLNode->getNext() != NULL) {
			currLLNode = currLLNode->getNext();
			this->add(currLLNode->getValue());
		}
	}

	// ~LinkedList() { delete head; }
	// LinkedList(const LinkedList&);
	// void operator=(const LinkedList&) {
	// 	head = new Node<T>;
	// 	head->setValue(0);
	// 	head->setNext(NULL);
	// 	head->setPrev(NULL);

	// 	ll
	// }

	bool isEmpty() { return head->getNext() == NULL; }

	void add(T value) {
		Node<T>* n = new Node<T>(value);
		Node<T>* currNode = head;
		while(currNode->getNext() != NULL) {
			currNode = currNode->getNext();
		}
		currNode->setNext(n);
		n->setPrev(currNode);
	}

	int find(T value) {
		if (!isEmpty()) {
			Node<T>* currNode = head->getNext();
			int idx = 0;
			while(currNode->getValue() != value && currNode != NULL) {
				currNode = currNode->getNext();
				idx++;
			}
			if (currNode == NULL) {
				return -1;
			} else {
				return idx;
			}
		} else {
			return -1;
		}
	}

	void remove(T value) {
		if (!isEmpty()) {
			int idx = find(value);
			if(idx != -1) {
				Node<T>* currNode = head->getNext();
				for (int i = 0; i < idx; ++i) {
					currNode = currNode->getNext(); 
				}
				delete currNode;
			}
		}
	}

	/* Assume the index is always correct */
	T get(int idx) {
		Node<T>* currNode = head->getNext();
		for (int i = 0; i < idx; ++i) {
			currNode = currNode->getNext();
		}
		return currNode->getValue();
	}

	void print() {
		if (isEmpty()) {
			cout << "Linked list empty" << endl;
		} else {
			Node<T>* x = head->getNext();
			while(x!=NULL) {
				cout << x->getValue() << " -> ";
				x = x->getNext();
			}
			cout << "NULL" << endl;
		}
	}
};

#endif