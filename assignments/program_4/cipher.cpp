///////////////////////////////////////////////////////////////////////////////
//
// Author:           Josh Cupp
// Assignment:       Program_04
// Date:             25 November 2019
// Title:            Program 4 - Cipher
// Semester:         Fall 2019
// Course:           CMPS 1063 
// 
// Files:            cipher.cpp
//                   encrypted.txt
//                   decrypted.txt
//                   
// Description:
//       Program reads in an encrypted file and then is able to decrypt them
//       and vice versa using a class.
//
/////////////////////////////////////////////////////////////////////////////////



#include <iostream>
#include <string>
#include <fstream>
#include <vector>

using namespace std;

class CaesarCipher
{
private:
	int shift;
	string encryptedS;
	string decryptedS;

public:
	CaesarCipher();
	string Encrypt(string &s); // encrypts a string given a specific shift value
	string Decrypt(string &s); // decrypts a string given a specific shift value
	string UpperCase(string &s); // a method that uppercases a string ( there are built in methods, but we will write our own)
	void SetShift(int n); // sets the shift amount for your class (default should be 13)
	void ReadCipherText(ifstream &fin, ofstream &out); // reads an encrypted file into a string
	void WriteCipherText(ofstream &out, string s); // writes an encrypted message to a file
	void ReadPlainText(ifstream &fin, ofstream &out); // reads a plain text file into a string
	void WritePlainText(ofstream &out,string s); // writes a plain text string to a file

};

CaesarCipher::CaesarCipher() {
	shift = 13;
	encryptedS = " ";
	decryptedS = " ";
}

/**
 * Encrypt
 *
 * Description:
 *      reads in a string and shifts the letters by whatever shift is.
 *
 * Params:
 *      string s: string to be encrypted
 *
 * Returns:
 *      string : encrypted string
 */

string CaesarCipher::Encrypt(string &s) {
	int intVal = 0;
	decryptedS = s;
	for (int i = 0; i < s.length(); i++) {
		if (s[i] >= 65 && s[i] <= 90) {
			
			intVal = (int)s[i] - 65;  // Turn it into an integer number between 0-25
			intVal += shift;		
			intVal = intVal % 26;      // Shift the letter, using mod to wrap back around
			s[i] = intVal + 65;    // Turn integer back into an ascii upper case letter
		}
	}

	encryptedS = s;
	return encryptedS;
}

/**
 * Decrypt
 *
 * Description:
 *      reads in a string and shifts the letters to decrypt the string
 *
 * Params:
 *      string s: string to be decrypted
 *
 * Returns:
 *      string : decrypted string
 */
string CaesarCipher::Decrypt(string &s) {
	int intVal = 0;
	encryptedS = s;

	for (int i = 0; i < s.length(); i++)
	{
		if (s[i] >= 65 && s[i] <= 90)
		{
			intVal = (int)s[i] - 65;
			intVal -= shift;

			if (intVal < 0) {
				intVal += 26;
			}

			intVal = intVal % 26;
			s[i] = intVal + 65;
		}
	}
	decryptedS = s;
	return decryptedS;
}

/**
 * UpperCase
 *
 * Description:
 *      reads in a string and makes all the letters uppercase
 *
 * Params:
 *      string s: string that will be uppercase
 *
 * Returns:
 *      string : all uppercase string
 */
string CaesarCipher::UpperCase(string &s) {
	vector<char> work;
	int ascii = 0;
	
	for (int i = 0; i < s.length() ;i++) {

		work.push_back(s[i]);
		if ((work[i] >= 97) && (work[i] <= 122))// if letters are lowercase;
		{
			ascii = work[(int)i];
			ascii = ascii - 32;
			work[i] = ascii;
			
		}

	}

	for (int i = 0; i < s.length(); i++) {

		s[i] = work[i];

	}
	
	return s;
}

/**
 * SetShift
 *
 * Description:
 *      reads in an integer and sets the shift value
 *
 * Params:
 *      int number : number to set the shift
 *
 * Returns:
 *      none
 */
void CaesarCipher::SetShift(int number) {
	
	shift = number;
}

/**
 * ReadCipherText
 *
 * Description:
 *      reads in text that is encrpted and decyphers it
 *
 * Params:
 *      ifstream : input file
 *		ofstream : output file
 *
 * Returns:
 *      none
 */
void CaesarCipher::ReadCipherText(ifstream &fin, ofstream &out) {
	
	int count = 0;
	fin >> count;

	for (int i = 0; i < count; i++) {
		
		fin >> shift;
		
		SetShift(shift);
		getline(fin, encryptedS);
		getline(fin, encryptedS);
		encryptedS = UpperCase(encryptedS);
		
		decryptedS = Decrypt(encryptedS);
		WritePlainText(out, decryptedS);
	}
}
/**
 * WriteCipherText
 *
 * Description:
 *     writes text that is encrypted to the output file
 *
 * Params:
 *      string s
 *		ofstream : output file
 *
 * Returns:
 *      none
 */
void CaesarCipher::WriteCipherText(ofstream &out, string s) {
	for (int i = 0; i < s.length(); i++) {
		out << s[i];
	}
	out << endl << endl;
}
/**
 * ReadPlainText
 *
 * Description:
 *      reads in plain text and encrypts it 
 *
 * Params:
 *      ifstream : input file
 *		ofstream : output file
 *
 * Returns:
 *      none
 */
void CaesarCipher::ReadPlainText(ifstream &fin, ofstream &out) {
	

	while (getline(fin, decryptedS)) {

		decryptedS = UpperCase(decryptedS);
		encryptedS = Encrypt(decryptedS);
		WriteCipherText(out, encryptedS);
	}
}

/**
 * WritePlainText
 *
 * Description:
 *     writes plain text to the output file
 *
 * Params:
 *      string s
 *		ofstream : output file
 *
 * Returns:
 *      none
 */
void CaesarCipher::WritePlainText(ofstream &out, string s) {
	for (int i = 0; i < s.length(); i++) {
		out << s[i];
	}
	out << endl << endl;
}

int main()
{
	ifstream fin;
	fin.open("encrypted.txt");
	ofstream outfile;
	outfile.open("decrypted.txt");

	outfile << "JOSH CUPP" << endl;
	outfile << "11/25/19" << endl;
	outfile << "Program 4 Output" << endl << endl;


	CaesarCipher text;
	CaesarCipher text2;// for the menu


	int operation;
	int shift = 13;

	string Emsg;
	string Dmsg;

	text.ReadCipherText(fin, outfile);

	//basic menu
	do {

		cout << "++++++++++++++++++++++++++++++++" << endl;
		cout << endl << endl;
		cout << "Pick a choice" << endl;
		cout << "1.Encrpt" << endl;
		cout << "2.Decrypt" << endl;
		cout << "3.Quit" << endl;
		cout << endl << endl;
		cout << "++++++++++++++++++++++++++++++++" << endl;


		cin >> operation;
		

		switch (operation) {
		case 1:
			cout << "Enter a string that you want to encrypt" << endl;
			cin >> Emsg;
			Emsg = text2.UpperCase(Emsg);
			Emsg = text2.Encrypt(Emsg);
			cout << "This is the encrypted string" << " " << Emsg << endl;
			system("pause");
			break;
		case 2:
			cout << "Enter an enrypted string that you want to decrypt" << endl;
			cin >> Dmsg;
			Dmsg = text2.UpperCase(Dmsg);
			Dmsg = text2.Decrypt(Dmsg);
			cout << "This is the decryted string" << " " << Dmsg << endl;
			system("pause");
			break;
		case 3:
			break;
		default:
			cout << "Error: Illegal input" << endl;
			break;
		}
	} while (operation != 3);
	
	
	fin.close();
	outfile.close();
	
	return 0;
}
