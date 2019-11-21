///////////////////////////////////////////////////////////////////////////////
//
// Author:           Josh Cupp
// Assignment:       Program_3 - Arbitrary percision math
// Date:             14 November 2019
//
// Files:
//		 apm.cpp
//		 output.num
//		 input_data.txt
//
// Description:
//       This program takes two long numbers and stores them in two lists.
//		 It then performs operations on them and stores the result in a new
//		 list.
//       
//
/////////////////////////////////////////////////////////////////////////////////
#include <iostream>
#include<fstream>
#include<string>
using namespace std;

struct Node {
	int data;
	Node *Next;
	Node *Prev;

	Node(int d) {
		data = d;
		Next = NULL;
		Prev = NULL;
	}
};

class DLList {
private:
	Node *Head;               // Head of list pointer
	Node *Tail;               // Tail of list pointer
	int Count;                // Count of items in list
	void _DeleteTail();
public:
	DLList();                   // Constructor
	DLList(const DLList &);     // Copy Constructor
	~DLList();                  // Destructor
	int Size();
	DLList Add(DLList B2);
	DLList Sub(DLList B2);
	DLList Mul(DLList B2);
	int PopTail();
	int PopFront();
	void InsertFront(int);
	void InsertBack(int);
	void Print(ostream &out);
	void RevPrint(ostream &out);
	void Delete();
};

/**
 * Public Default Constructor
 */
DLList::DLList() {
	Head = Tail = NULL;
	Count = 0;
}

/**
 * Public Copy Constructor
 *      constructs a new list with values from another list.
 */
DLList::DLList(const DLList &list) {
	Head = Tail = NULL; // Initialize pointers like always
	Count = 0;

	// Point to "Other" lists head. Even though its private we
	// can access it beacuase we are in a class of the same type.
	Node* Other = list.Head;

	// Travers the other list
	while (Other) {
		// Insert values into new nodes in this list.
		InsertBack(Other->data);
		Other = Other->Next;
	}
}

/**
 * Public Destructor
 */
DLList::~DLList() {
	Node *temp = Head;

	while (temp) {
		temp = temp->Next;
		delete Head;
		Head = temp;
	}
}

/**
 * Public InsertFront
 *
 * Adds item to head of list by calling private method with a node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void DLList::InsertFront(int data) {
	Node *Temp = new Node(data);

	if (!Head) {
		Head = Temp;
		Tail = Temp;
	}
	else {
		Head->Prev = Temp;
		Temp->Next = Head;
		Head = Temp;
	}
	Count++;
}

/**
 * Public InsertBack
 *
 * Adds item to tail of list by calling private method with a node.
 *
 * @Params:
 *
 *     int data : item to be placed in list
 *
 * @Returns:
 *
 *     void
 */
void DLList::InsertBack(int data) {
	Node *Temp = new Node(data);

	if (!Head) {
		Head = Temp;
		Tail = Temp;
	}
	else {
		Tail->Next = Temp;
		Temp->Prev = Tail;
		Tail = Temp;
	}
	Count++;
}
/**
 * PopTail
 *
 * Description:
 *      Pops the Tail of the list off and then updates Tail
 *
 * Params:
 *      none
 *
 * Returns:
 *      int : the integer value at the end of the list
 */
int DLList::PopTail() {

	int value = 0;
	if (Head)
	{
		value = Tail->data;
		Node *temp = Tail->Prev;

		delete Tail;

		Tail = temp;

		if (Tail)
			Tail->Next = NULL;
		else
			Head = NULL;

		this->Count--;
	}
	return value;
}
/**
 * PopFront
 *
 * Description:
 *      Pops the Head of the list off and then updates head
 *
 * Params:
 *      none
 *
 * Returns:
 *      int : the integer value at the front of the list
 */
int DLList::PopFront() {
	int value = 0;
	if (Head)
	{
		value = Head->data;
		Node *temp = Head->Next;
		delete Head;
		Head = temp;
		if (Head)
			Head->Prev = NULL;
		else
			Tail = NULL;
		this->Count--;
	}
	return value;
}

/**
 * Public Print
 *
 * Prints list to stdout from head to tail
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void DLList::Print(ostream &out) {
	Node *Temp = Head;

	while (Temp) {
		out << Temp->data;
		
		Temp = Temp->Next;
	}
	out << endl;
}

/**
 * Private _DeleteTail
 *
 * Deletes last node in list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void DLList::_DeleteTail() {

	if (Tail) {
		Node *Temp = Tail;
		if (Tail == Head) {
			Tail = Head = NULL;
			delete Temp;
		}
		else {

			Tail = Tail->Prev;
			Tail->Next = NULL;
			delete Temp;
		}
		Count--;
	}
}

/**
 * Public Delete
 *
 * Deletes last node in list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void DLList::Delete() {
	_DeleteTail();
}

/**
 * Public Size
 *
 * Returns size of list
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     int
 */
int DLList::Size() {
	return Count;
}


/**
 * Public RevPrint
 *
 *  Prints list to stdout in reverse (tail to head)
 *
 * @Params:
 *
 *     Void
 *
 * @Returns:
 *
 *     void
 */
void DLList::RevPrint(ostream &out) {
	Node *Temp = Tail;

	while (Temp) {
		out << Temp->data;
		if (Temp->Prev) {
			out << "->";
		}
		Temp = Temp->Prev;
	}
	out << endl;
}
/**
 * Add
 *
 * Description:
 *      Adds an "other" doubly linked list to "this" list
 *
 * Params:
 *      DLList B2    : The second list
 *
 * Returns:
 *      DLList : a doubley linked list with addition results
 */
DLList DLList::Add(DLList B2)
{
	DLList finalList;
	// adding the tails of the two lists and storing in a new list
	while (this->Count > 0 || B2.Count > 0)
		finalList.InsertFront(PopTail() + B2.PopTail());

	Node *temp = finalList.Tail;
	while (temp)
	{
		if (temp->data >= 10)
		{
			if (temp->Prev == NULL)
			{
				finalList.InsertFront((temp->data / 10)); 
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
			else
			{
				temp->Prev->data += (temp->data / 10);
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
		}
		else {
			temp = temp->Prev;
		}
	}
	return finalList;
}
/**
 * Sub
 *
 * Description:
 *      Subtracts an "other" doubly linked list to "this" list
 *
 * Params:
 *      DLList B2    : The second list
 *
 * Returns:
 *      DLList : a doubley linked list with subtraction results
 */
DLList DLList::Sub(DLList B2)
{
	DLList finalList;

	while (this->Count > 0 || B2.Count > 0)
		finalList.InsertFront(PopTail() - B2.PopTail());

	Node *temp = finalList.Tail;
	while (temp)
	{
		if (temp->data < 0)
		{
			if (temp->Prev == NULL)
			{
				finalList.InsertFront(0);
				temp = temp->Prev;
			}
			else
			{
				temp->Prev->data -= (1);
				temp->data = temp->data + 10;
				temp = temp->Prev;
			}
		}
		else {
			temp = temp->Prev;
		}
	}
	return finalList;
}

//couldnt figure this one out
DLList DLList::Mul(DLList B2) {
	DLList finalList;
	while (this->Count > 0 || B2.Count > 0)
		finalList.InsertFront(PopTail() * B2.PopTail());

	Node *temp = finalList.Tail;
	while (temp)
	{
		if (temp->data >= 10)
		{
			if (temp->Prev == NULL) 
			{
				finalList.InsertFront((temp->data / 10));
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
			else
			{
				temp->Prev->data += (temp->data / 10);
				temp->data = temp->data % 10;
				temp = temp->Prev;
			}
		}
		else {
			temp = temp->Prev;
		}
	}
	return finalList;
}

int main()
{
	ifstream fin;
	fin.open("input_data.txt");
	ofstream outfile;
	outfile.open("output.num");

	outfile << "Josh Cupp" << endl;
	outfile << "Program 3" << endl;
	outfile << "Arbitrary Percision Math" << endl;
	outfile << endl;

	
	string num1,num2;

	char op;
	int problems;

	fin >> problems;
	for (int i = 1; i <= problems; i++)
	{
		DLList A1,B2;
		fin >> op >> num1 >> num2;
		for (int j = 0; j < num1.size(); j++)
		{
			int temp = num1[j] - 48;
			A1.InsertBack(temp);
		}
		for (int j = 0; j < num2.size(); j++)
		{
			int temp2 = num2[j] - 48;
			B2.InsertBack(temp2);
		}

		outfile << "Operation " << i << ": ";
		switch (op)
		{
		case '+':
			outfile << "Addition" << endl;
			outfile << "Answer:" << endl << endl;
			(A1.Add(B2)).Print(outfile);
			outfile << endl;
			break;
		case '-':
			outfile << "Subtraction" << endl;
			outfile << "Answer:" << endl << endl;
			(A1.Sub(B2)).Print(outfile);
			outfile << endl;
			break;
		case '*':
			outfile << "Multiplication" << endl;
			outfile << "Answer:" << endl << endl;
			(A1.Mul(B2)).Print(outfile);
			outfile << endl;
			break;
		}
	}

	fin.close();
	outfile.close();
	return 0;
}
