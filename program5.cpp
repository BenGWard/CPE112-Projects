//******************************************************************
// Name:		Ben Ward
// Lab Section:		CPE 112L-04
// Lecture Section:	CPE 112-02
// Date:		09/27/2004
// Title:		Program 04
//
// Description:
//	This program reads a file containing bank account data. It then
//	prints the data to the standard output device.
//******************************************************************

#include <iostream>			//Header file for I/O
#include <fstream>			//Header file to read data from files
#include <string>			//Header file for string data type
#include <iomanip>			//Header file for I/O manipulators

using namespace std;

int main()
{
	ifstream inData;		//Variable for input file
	string firstLine;		//Variable to hold first line of data file
	string secondLine;		//Variable to hold second line of date file	
	string fileName;		//Variable for name of file to open
	string first;			//Variable for first name
	string middle;			//Variable for middle name
	string last;			//Variable for last name
	string number;			//Variable for account number
	string balance;			//Variable for account balance
	string::size_type begin;	//Variable for beginning of string
	string::size_type end;		//Variable for ending of string
	int pos;			//Variable for beginning position of string
	int len;			//Variable for length of string
		
	cout << endl << "Enter the name of the input file now: ";
	cin >> fileName;
	inData.open(fileName.c_str());	//Opens file for data input
	inData >> firstLine;		//Stores first line of data
	inData >> secondLine;		//Stores second line of data
	begin = firstLine.find('1');		//This section
	end = firstLine.find('2');		//finds the flags
	pos = ++begin;				//placed in the
	len = end - pos;			//input file and
	first = firstLine.substr(pos, len);	//saves the data to first
	
	begin = firstLine.find('2');		//This section
	end = firstLine.find('3');		//finds the flags
	pos = ++begin;				//placed in the
	len = end - pos;			//input file and
	middle = firstLine.substr(pos, len);	//saves the data to middle
	
	begin = firstLine.find('3');		//This section
	end = firstLine.find('\n');		//finds the flags
	pos = ++begin;				//placed in the
	len = end - pos;			//input file and
	last = firstLine.substr(pos, len);	//saves the data to last
	
	begin = secondLine.find('N');		//This section
	end = secondLine.find('B');		//finds the flags
	pos = ++begin;				//placed in the
	len = end - pos;			//input file and
	number = secondLine.substr(pos, len);	//saves the data to number
	
	begin = secondLine.find('B');		//This section
	end = secondLine.find('\n');		//finds the flags
	pos = ++begin;				//placed in the
	len = end - pos;			//input file and
	balance = secondLine.substr(pos, len);	//saves the data to balance
	
	cout << endl;
	cout << setw(19) << "Account Holder Name" <<" = ";
	cout << last << ", " << first << ' ' << middle << endl;
	cout << setw(19) << "Account Number" << " = " << number << endl;
	cout << setw(19) << "Account Balance" << " = $" << balance << endl << endl;
	
	return 0;
	
}
	