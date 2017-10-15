//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		10/25/2004
// Title:		Program 07
//
// Description: 
//	This program inputs binary number from a file,
//	converts them, and prints them to the primary output device.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <iomanip>			//Header file for I/O manipulators
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings

using namespace std;			//Global using directive

int main()
{
	string binary;			//Variable for binary digit
	int decimal;			//Variable for decimal number
	int count;			//Counter for while statement
	int x;				//Counter for place setting
	string var;			//Variable for binary number
	string fileName;		//Variable for input of file name
	ifstream inFile;		//Variable for input file
	
	cout << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;						//Get fileName from keyboard
	
	inFile.open(fileName.c_str());					//Opens file for data input
		if(!inFile)						//Tests filestream
		{
			cout << endl << endl << "Error opening input file named: " << fileName;
			cout << endl << "Terminating program now..." << endl << endl << endl;
			return 1;
		}
	
	inFile.ignore(500, '\n');		//Ignore first line of comments
	
	cout << endl << endl << setw(15) << "Binary Value" << setw(15) << "Decimal Value" <<endl;

	inFile >> var;				//Priming read

	while(inFile)				//Run till the end of the file
	{	
		count = var.length();		//Set count to length of number
		cout << setw(15) << var;	//Output number to display
		x = 0;				//Set x to 0
		decimal = 0;			//Set decimal to 0
		while(count > 0)		//Run till count equal 0
		{
			count--;
			binary = var.substr(x, 1);
			if(binary == "1")	//If binary equals 1 add to decimal
				decimal = decimal + pow(2, count);
			if(binary !="0" && binary !="1")	//If binary doesn't equal 0 or 1,
			{					//set exit terms for while statement
				decimal = -1;
				count = -1;
			}	
			x++;					
		}		
		if(decimal >= 0)				//If decimal is a nonnegative number
			cout << setw(15) << decimal << endl;	//print it
		else						//If decimal is a negative number it
			cout << setw(15) << "????" << endl;	//had a character that was not a 1 or 0
		inFile >> var;	
	}

	cout << endl << "Binary Conversion Complete..." << endl << endl;
	
	inFile.close();						//Close input file
	
	return 0;
}