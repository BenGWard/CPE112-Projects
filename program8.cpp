//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		11/1/2004
// Title:		Program 08
//
// Description: 
//	This program encrypts and decrypts messages stored
//	in data files using the Caesar cipher.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <sstream>			//Header file for ostringstream
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings
#include <cctype>			//Header file for character operations

using namespace std;			//Global using directive

void PrintMenu(int&, int, string);	//PrintMenu function declaration
void OpenInput(ifstream&,string&);	//OpenInput function declaration
void GetKey(int&);			//GetKey function declaration
void Encode(ifstream&, int);		//Encode function declaration
void Decode(ifstream&, int);		//Decode function declaration

int main()
{
	int choice = 0;			//Variable for menu choice
	int key = 0;			//Variable for cipher key
	string fileName = "0";		//Variable for filename of open file
	ifstream inFile;		//Variable for input stream

	while(choice >=0 && choice <=4)
	{
		PrintMenu(choice, key, fileName);
		if(choice == 1)
			OpenInput(inFile, fileName);
		else if(choice == 2)
			 GetKey(key);
		else if(choice == 3)
			Encode(inFile, key);
		else if(choice == 4)
			Decode(inFile, key);
	}

	return 0;
}

//************************************************************************************

void PrintMenu(int& choice, int key, string fileName)	//This function prints the program menu
{
	const string dash = "----------";

	cout << dash << endl;
	cout << "Crypto Menu" << endl << endl;
	cout << "1. Open File for Input" << endl;
	cout << "2. Enter New Key Value" << endl;
	cout << "3. Encode Message" << endl;
	cout << "4. Decode Message" << endl;
	cout << "5. Exit Program" << endl << endl;
	if (fileName == "0")				//Determines if fileName has been set
		cout << "Current input file = No File Selected" << endl;
	else
		cout << "Current input file = " << fileName << endl;
	cout << "Current key value = " << key << endl << endl;
	cout << "Please select one of the menu options above: ";
	cin >> choice;
}

//************************************************************************************

void OpenInput(ifstream& inFile, string& fileName)					//This function opens the file input stream
{
	cout << endl << endl << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;								//Get fileName from keyboard	
	inFile.open(fileName.c_str());							//Opens file for data input
}

//************************************************************************************

void GetKey(int& key)				//This function prompts the user for the cipher key
{
	cout << endl << endl << endl;
	cout << "Current key value = " << key << endl;
	cout << "Enter key value now: ";
	cin >> key;
	cout << endl << endl << "New key value = " << key << endl << endl;
}

//************************************************************************************

void Encode(ifstream& inFile, int key)		//This function encrypts a message from a text file into the cipher
{
	char ch;
	ostringstream oss;	

	cout << endl << endl;
	oss << endl << endl;
	cout << "*** Unencrypted Message Begins ***" << endl;
	oss << "*** Encrypted Message Begins ***" << endl;
	inFile.get(ch);
	ch = tolower(ch);
	while(inFile)
	{
		if(ch == '\n')
		{
			cout << endl;
			oss << endl;
		}
		else if((ch + key)>= 97 && (ch + key)<= 122)
		{
			cout << ch;
			ch = ch + key;
			oss << ch;
		}
		else if(ch >= 97 && ch <= 122)
		{
			cout << ch;
			ch = (ch + key) - 26;
			oss << ch;
		}
		else
		{
			cout << ch;
			oss << ch;
		}
		inFile.get(ch);
		ch = tolower(ch);
	}
	cout << endl << "*** Unencrypted Message Ends ***";
	oss << endl << "*** Encrypted Message Ends ***";
	cout << oss.str() << endl;
}

//************************************************************************************

void Decode(ifstream& inFile, int key)		//This function decrypts a message from a text file
{
	char ch;
	ostringstream oss;	

	cout << endl << endl;
	oss << endl << endl;
	oss << "*** Unencrypted Message Begins ***" << endl;
	cout << "*** Encrypted Message Begins ***"<< endl;
	inFile.get(ch);
	ch = tolower(ch);
	while(inFile)
	{
		if(ch == '\n')
		{
			cout << endl;
			oss << endl;
		}
		else if((ch - key) >= 97 && (ch - key) <= 122)
		{
			cout << ch;
			ch = ch - key;
			oss << ch;
		}
		else if(ch >= 97 && ch <= 122)
		{
			cout << ch;
			ch = (ch - key) + 26;
			oss << ch;
		}
		else
		{
			cout << ch;
			oss << ch;
		}
		inFile.get(ch);
		ch = tolower(ch);
	}
	oss << endl << "*** Unencrypted Message Ends ***";
	cout << endl << "*** Encrypted Message Ends ***";
	cout << oss.str() << endl;
}