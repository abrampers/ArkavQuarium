/* Doubly linked list */
#ifndef DOUBLL_HPP
#define DOUBLL_HPP

#include <iostream>

template <typename T> class Node;
template <typename T> class LinkedList;

template <typename T>
//! Generic Class Node. Stores <T> value and pointer to next and prev Node.
class Node {
private:
	T value;
	Node* prev;
	Node* next;
public:
	//! A default constructor.
    /*! Constructs a new Node. */
	Node() {
		prev = nullptr;
		next = nullptr;
	}

	//! A user defined constructor.
    /*! Constructs a new Node.
        \param <T> value.
    */
	Node(T value) { 
		this->value = value; 
		prev = nullptr;
		next = nullptr;
	}

	//! A destructor.
    /*! Destructs the Node. */
	~Node() { 
		Node* n = next;
		Node* p = prev;
		if(n != nullptr) n->setPrev(p);
		if(p != nullptr) p->setNext(n);
	}

	//! Setter for value.
    /*! 
        \param <T> value
     */
	void setValue(T value) { this->value = value; }

	//! Setter for prev.
    /*! 
        \param Node<T> *p Previous Node
     */
	void setPrev(Node* p) { prev = p; }

	//! Setter for next.
    /*! 
        \param Node<T> *n Next Node
     */
	void setNext(Node* n) { next = n; }

	//! Getter for value.
    /*!  
        \return <T> value.
    */
	T getValue() { return value; }

	//! Getter for next.
    /*!  
        \return Node<T> *next.
    */
	Node *getNext() { return this->next; }

	//! Getter for prev.
    /*!  
        \return Node<T> *prev.
    */
	Node *getPrev() { return this->prev; }
};

template <typename T> 
//! Generic Class LinkedList. LinkedList like container
class LinkedList {
private:
	Node<T> *head;
	int length;
public:
	//! A constructor.
    /*! Constructs a new LinkedList object. */
	LinkedList() {
		head = new Node<T>;
		head->setValue(0);
		head->setNext(nullptr);
		head->setPrev(nullptr);
		length = 0;
	}

	//! A copy constructor.
    /*! Constructs a new LinkedList object. 
        \param const LinkedList<T>& ll
    */
	LinkedList(const LinkedList<T>& ll) {
		head = new Node<T>;
		head->setValue(0);
		head->setNext(NULL);
		head->setPrev(NULL);
		length = ll.length;

		Node<T>* currLLNode = ll.head;
		while(currLLNode->getNext() != NULL) {
			currLLNode = currLLNode->getNext();
			this->add(currLLNode->getValue());
		}
	}

	//! A destructor.
    /*! Destructs the Linkedlist object. */
	~LinkedList() {
		Node<T>* target;
		Node<T>* next = head->getNext();
		while (next != nullptr) {
			target = next;
			next = target->getNext();
			delete target;
		}
		delete head;
	}

	//! Getter for head.
    /*!  
        \return Node<T> *head;
    */
	Node<T>* getHead() {
		return head->getNext();
	}

	//! Getter for move_speed.
    /*!  
        \return double move_speed
    */
	int getLength() {
		return length;
	}

	//! Check whether the LinkedList is empty
	/*! \return bool is empty */
	bool isEmpty() { return head->getNext() == nullptr; }

	//!	Add a value to the LinkedList
	/*! \param <T> value */
	void add(T value) {
		Node<T>* n = new Node<T>(value);
		Node<T>* currNode = head;
		while(currNode->getNext() != nullptr) {
			currNode = currNode->getNext();
		}
		currNode->setNext(n);
		n->setPrev(currNode);
		length += 1;
	}

	//! Find a value in the LinkedList
	/*! \param <T> value */
	int find(T value) {
		if (!isEmpty()) {
			Node<T>* currNode = head->getNext();
			int idx = 0;
			while(currNode->getValue() != value && currNode != nullptr) {
				currNode = currNode->getNext();
				idx++;
			}
			if (currNode == nullptr) {
				return -1;
			} else {
				return idx;
			}
		} else {
			return -1;
		}
	}

	//! Remove a value in the LinkedList
	/*! \param <T> value */
	void remove(T value) {
		if (!isEmpty()) {
			int idx = find(value);
			if(idx != -1) {
				Node<T>* currNode = head->getNext();
				for (int i = 0; i < idx; ++i) {
					currNode = currNode->getNext(); 
				}
				delete currNode;
				length -= 1;
			}
		}
	}

	/* Assume the index is always correct */
	//! Get value by index
	/*! 
		\param int index
		\return <T> value
	*/
	T get(int idx) {
		Node<T>* currNode = head->getNext();
		for (int i = 0; i < idx; ++i) {
			currNode = currNode->getNext();
		}
		return currNode->getValue();
	}

	//! Prints the LinkedList
	void print() {
		if (isEmpty()) {
			std::cout << "Linked list empty" << std::endl;
		} else {
			Node<T>* x = head->getNext();
			while(x!=NULL) {
				std::cout << x->getValue() << " -> ";
				x = x->getNext();
			}
			std::cout << "NULL" << std::endl;
		}
	}
};

#endif