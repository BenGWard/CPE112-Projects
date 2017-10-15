//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		10/16/2004
// Title:		Program 06
//
// Description: 
//	This program inputs the coefficients of the quadratic formula
//	it then computes the roots of the equation.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <cmath>			//Header file for math operations
#include <iomanip>			//Header file for I/O manipulators
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings

using namespace std;			//Global using directive

int main()
{
	float a;			//Variable for first coefficient
	float b;			//Variable for second coefficient
	float c;			//Variable for third coefficient
	float d;			//Variable for discriminant
	double r1;			//Variable for first root
	double r2;			//Variable for second root
	string fileName;		//Variable for input of file name
	ifstream inFile;		//Variable for input file

	cout << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;						//Get fileName from keyboard
	cout << fixed << showpoint << setprecision(2) << endl;		//Format output

	inFile.open(fileName.c_str());					//Opens file for data input
		if (!inFile)						//Tests filestream
		{
			cout << endl << "Error opening input file named: " << fileName;
			cout << endl << "Terminating program now..." << endl << endl;
			return 1;
		}
		
	inFile.ignore(500,'A');		//Find A		
	inFile >> a;			//Get value for a
	inFile.ignore(500,'B');		//Find B
	inFile >> b;			//Get value for b
	inFile.ignore(500,'C');		//Find C
	inFile >> c;			//Get value for c
			
	d = pow((b*b - 4*a*c), .5 );	//Discriminant for quadratic equation
	r1 = ( -b + d )/2*a;		//Formula for first root
	r2 = ( -b - d )/2*a;		//Formula for second root

	cout << "Computing the roots of (" << a << ")x^2 + (" << b << ")x + (" << c << ") = 0.0" << endl << endl;

		if (r1 !=r2 && d >= 0)		//Check for two postive roots
		{
			cout << "Two positive real roots..." << endl;
			cout << "r1 = " << r1 << endl << "r2 = " << r2 << endl << endl;
		}

		else if (r1==r2 && d >= 0)	//Check for two equal roots
		{
			cout << "One repeated real root..." << endl;
			cout << "r1 = r2 = " << r1 << endl << endl;
		}
	
		else
		{
			cout << "Two complex roots..." << endl;
			cout << "r1 = " << -b << " + i*" << b + pow(labs(b*b - 4*a*c), .5)/(2*a) << endl;
			cout << "r2 = " << -b << " + i*" << b - pow(labs(b*b - 4*a*c), .5)/(2*a) << endl << endl;
		}

	return 0;

}