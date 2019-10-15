/**

* Homework 3
*
* List based Stack that holds an animal type
*
* Author: Josh Cupp
* Date : Oct 14th 2019
* **/




#include "ListStack.h"    // include our stack definition
#include <fstream>        
#include <iostream>

using namespace std;


int main() {
	ifstream fin("animals.txt");  // input file of animal info                   
	Animal *a;                    // animal pointer used to hold popped animals
	ListStack LS;                 // List based stack object
	
	string name;
	double weight = 0.0;
	double scary = 0.0;

	

	// While still animals in the file
	while (!fin.eof()) {
		fin >> name >> weight >> scary; // grab from input file
		// make the constructor read the parameters that you are sending in
		
		a = new Animal(name, weight, scary); 
		LS.Push(a);                       // push animal onto the stack
	}
	

	LS.Print();             // Print the stack

	cout << endl;		    // ummm
	cout << endl;

	a = LS.Pop();           // get animal off top of stack

	cout << a << endl;      // print animal (cout operator overloaded)
	cout << endl;

	a = LS.Pop();           // get animal off top of stack again

	cout << a << endl;      // print animal (cout operator overloaded)
	cout << endl << endl << endl;

	LS.Print();             // print the stack

	system("pause");
}
