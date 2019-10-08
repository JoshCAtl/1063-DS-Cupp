/**
 * File: main.cpp
 * Aurhor: Josh Cupp
 * Course: CMPS 1063 - Fall 2019
 * Date: 10/7/19
 * Description:
 *    Homework/Program 2: Creating new methods(checkResize, Enlarge,
				Reduce) in a stack.
 *    
 */


#include <iostream>
#include <fstream>

using namespace std;

class Stack
{
private:
	int *A;         // container of items (could make it a list)
	int Top;        // keep track of top
	int Size;		// Arrays need a size

public:
	/**
 * Stack constructor
 * Description:
 *    Inits an array of ints and sets our top
 */
	Stack() {
		Size = 10;
		A = new int[Size];
		Top = -1;
	}

	/**
	 * Stack constructor
	 * Description:
	 *    Inits an array of ints to a specified size and sets our top
	 * Params:
	 *    int s : integer size
	 */
	Stack(int s) {
		Size = s;
		A = new int[Size];
		Top = -1;
	}

	/**
	 * Push
	 * Description:
	 *    Adds item to top of Stack
	 * Params:
	 *    int val : integer size
	 * Returns:
	 *     bool : true = success
	 */
	bool Push(int val) {
		if (!Full()) {
			Top++;
			A[Top] = val;
			return true;
		}
		else {
			return false;
		}
	}

	/**
	 * Pop
	 * Description:
	 *    Removes top of Stack and returns it
	 * Params:
	 *    void
	 * Returns:
	 *     int : item on Stack
	 */
	int Pop() {
		if (!Empty()) {
			int temp = 0;
			temp = A[Top];
			Top--;
			return temp;
		}
		else {
			// should return a value that implies failuer, but good enough for now
			cout << "Cannot remove item from empty StackClass" << endl;
		}
		return 0;
	}

	/**
	 * Print
	 * Description:
	 *    Prints to output file
	 * Params:
	 *    int l = largest size, int c = current size
	 * Returns:
	 *     void
	 */
	void Print(int l, int c) {
		ofstream outfile;
		outfile.open("stack_out.dat");

		outfile << "Josh Cupp" << endl;
		outfile << "10/7/2019" << endl;
		outfile << "Homework 2" << endl;
		outfile << endl << endl;

		outfile << "Stack Size: " << c << endl;
		outfile << "Largest Size: " << l << endl;
		outfile << "Values: ";
		for (int i = Top; i >= 0; i--) {
			outfile << A[i] <<  " ";
		}
		outfile.close();
	}

	/**
	 * Empty
	 * Description:
	 *    Is Stack empty
	 * Params:
	 *    void
	 * Returns:
	 *    bool : true = empty
	 */
	bool Empty() {
		return Top < 0;
	}

	/**
	 * Full
	 * Description:
	 *    Is Stack full
	 * Params:
	 *    void
	 * Returns:
	 *    bool : true = full
	 */
	bool Full() {
		return (Top == Size - 1);
	}
	
	/**
	 * checkResize
	 * Description:
	 *   Checks if stack needs to be resized
	 * Params:
	 *    void
	 * Returns:
	 *    double based on whether it needs to be resized
	 */
	double checkResize()
	{
		double temp = Top + 1 / (double)Size;
		if (temp >= .8)
		{
			return temp;
		}
		else if (temp <= .2)
		{
			return temp;
		}
		else
			return 0.0;
	}

	/**
	 * Enlarge
	 * Description:
	 *   Resizes stack by 1.5 times
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
	void Enlarge()
	{
		int new_size = Size * 1.5; // Enlarge stack by 1.5 times
		int *B = new int[new_size]; // Allocate memory for new array
		for (int i = 0; i < Size; i++) // Copy array
		{
			B[i] = A[i];
		}
		int *Temp = A;
		A = B;
		delete[] Temp;

	}

	/**
	 * Reduce
	 * Description:
	 *   Resizes stack by 0.5 times
	 * Params:
	 *    void
	 * Returns:
	 *    void
	 */
	void Reduce()
	{
		int new_size = Size * .5; // Reduce stack by .5 times
		int *B = new int[new_size]; // Allocate memory for new array
		for (int i = 0; i < Size; i++) // Copy Array A
		{
			B[i] = A[i];
		}

		int *Temp = A;
		A = B;
		delete[] Temp; 
	}
};
/**
 * Main Program
 *
 */
int main() {
	
	ifstream fin;
	fin.open("input_data.txt");
	char sign;
	int data;
	
	int largestSize = 0; // Keeps track of largest size
	
	int currentSize = 0; // Keeps track of currnet size
	
	
	Stack S1; // Instance of our stack default constructor
	
	while (!(fin.eof()))
	{
		fin >> sign; // Reading in the sign '+' or '-'
		fin >> data; // Reading in data behind the sign

		if (sign == '+')
		{
			S1.Push(data);
			largestSize++; // increments largest size of stack
			currentSize++;
		}
		else if (sign == '-')
		{
			S1.Pop();
			currentSize--; // decrements current size of stack
		}

	}
	

	if (S1.checkResize() >= .8)
	{
		S1.Enlarge();
	}
	else if (S1.checkResize() <= .2)
	{
		S1.Reduce();
	}

	S1.Print(largestSize, currentSize); // Print function

	
	fin.close();
	return 0;
}
