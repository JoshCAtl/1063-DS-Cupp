/**
 * ListStack.h
 *
 * List stack definition file. This stack hold animal types. Why? Cause integers
 * get a little boring after a while.
 *
 * Author: Josh Cupp
 * Date: Oct 14th 2019
 */


#pragma once
#include <iostream>
#include <fstream>
#include <string>


using namespace std;

/**
 * Animal Type
 */
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
	Animal(string n, double w, double s);
};

// Overload "<<" operator for animals
ostream &operator<<(ostream &os, const Animal *);

/**
 * Node type.
 *
 * We seperate Animal from Node so we can return an "Animal"
 * when we pop the stack, and don't have to return a "node"
 */
struct Node {
	Animal *A;
	Node *Next;

	// Needs a default constructor

	Node(Animal *a) {
		A = a;
		Next = NULL;
	}
};

/**
 * ListStack
 *
 * List based stack implementation
 *
 */
class ListStack {
private:
	Node *Top;

public:
	ListStack();          // constructor
	void Push(Animal *a);  // stack gets Animals
	Animal *Pop();        // Pop returns top animal
	void Print();
	// print stack for debugging

};

