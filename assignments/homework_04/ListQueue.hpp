/**
 * ListQueue.hpp
 *
 * List Based Queue definition and implementation.
 * Also added animal struct and changed class to hold animal.

 * Author: Josh Cupp
 * Date: Oct 2019
 */
#include <iostream>
#include <string>

using namespace std;


struct Animal {
	string name;
	double weight;
	double scary;

	// Default constructor
	Animal() {
		name = "";
		weight = 0.0;
		scary = 99.0;
	}

	// Added an overloaded constructor
	Animal(string n, double w, double s)
	{
		//Made the data from the input file equal the objects' data
		name = n;
		weight = w;
		scary = s;
	}
	
};

// Overload "<<" operator for animals
ostream &operator<<(ostream &os, const Animal *a);


struct Node {          // Typical node setup for a list. 
	Animal *A;          
	Node* Next;


	Node(Animal *a) {      // overloaded constructor
		A = a;
		Next = NULL;
	}
};

/**
 * List Queue
 *
 * List Based Queue
 *
 */
class ListQueue {
private:
	Node* Front;            // front of the queue (where we remove from)
	Node* Rear;             // rear of the queue (where we add to)
public:
	
	/**
 * ListQueue
 * Purpose:
 *     Constructs our queue
 * Params:
 *     void
 * Returns:
 *     void
 */
	ListQueue() {            // construct
		Front = Rear = NULL;
	}

/**
 * Push
 * Purpose:
 *     Adds Animal to rear of queue
 * Params:
 *     Animal A : Animal to be added
 * Returns:
 *     void
 */
	void Push(Animal *A) {         // add integers to rear
		Node* temp = new Node(A);     // allocate new memory

		if (Front == NULL) {              // if list is empty
			Front = Rear = temp;          // point everyone to it
		}
		else {
			Rear->Next = temp;            // otherwise link last node to new one
			Rear = temp;                  // then point Rear to it.
		}

	}

	/**
 * Pop
 * Purpose:
 *     Removes Animal from front of queue
 * Params:
 *     void
 * Returns:
 *     Animal *temp
 */
	Animal* Pop() {              // remove from front
		Animal* temp = Front->A;     // get front data temporarily
		Node* T = Front;            // Point to the front temporarily
		Front = Front->Next;        // Move front to next item 
		delete T;                   // Now we can delete the old front

		if (!Front) {                 // If front is NULL make rear NULL as well
			Rear = NULL;              // because if front is NULL list is empty!  
		}

		return temp;                // return front Animal
	}

	/**
 * Print
 * Purpose:
 *     Prints Animals in queue for debugging
 * Params:
 *     void
 * Returns:
 *     void
 */
	void Print() {           // print for debugging
		Node* temp = Front;

		while (temp) {
			cout << temp->A;
			if (temp->Next) {
				cout << "->";
			}
			temp = temp->Next;
		}
		cout << endl;
	}

	/**
 * Empty
 * Purpose:
 *     Checks for empty queue. Cant remove from empty queue!
 * Params:
 *     void
 * Returns:
 *     bool: true == empty
 */
	bool Empty() {           // is queue empty (can't remove from empty queue)
		return Front == NULL;
	}

	/**
 * PrintPointers
 * Purpose:
 *     Prints front and rear values for lecture purposes
 * Params:
 *     void
 * Returns:
 *     void
 */
	void PrintPointers() {   // added for lecture purposes
		cout << "Front = " << Front << endl;
		cout << "Rear = " << Rear << endl;
	}

	/**
 * GetFront
 * Purpose:
 *     Returns the front node, for lecture purposes
 * Params:
 *     void
 * Returns:
 *     void
 */
	Node* GetFront() {      // added for lecture purposes
		return Front;
	}
};
