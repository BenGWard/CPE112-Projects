//******************************************************************
// Name:		Ben Ward
// Lab Section:		CPE 112L-04
// Lecture Section:	CPE 112-02
// Date:		09/27/2004
// Title:		Program 04
//
// Description:
//	This program computes the area of a triangle with side lengths a, b, c,
//	the radius of the circle circumscribing the triangle, and the area of
//	the circle circumscribing the triangle, and it displays these values on
//	the standard output device.
//******************************************************************

#include <iostream>				// Header file for cout and endl
#include <iomanip>				// Header file for I/O manipulators
#include <cmath>				// Header file for math operations
#include <string>

using namespace std;				// Global using directive

const float PI = 3.1415926;

int main()
{
	float a;				// Variable side a
	float b;				// Variable side b
	float c;				// Variable side c
	float s;				// Variable 1/2(a+b+c)
	double areat;				// Variable area of triangle
	double areac;				// Variable area of circle
	float radius;				// Variable of radius of circle
	string n;				// Line of numbers for output

	cout << endl;
	cout << "Input the length of side A: ";
	cin >> a;
	cout << endl;
	cout << "Input the length of side B: ";
	cin >> b;
	cout << endl;
	cout << "Input the length of side C: ";
	cin >> c;
	cout << endl << endl;

	s = .5 * (a+b+c);
	areat = sqrt((double)s*(s-a)*(s-b)*(s-c));
	radius = (a*b*c)/(4*sqrt((double)s*(s-a)*(s-b)*(s-c)));
	areac = PI * pow(radius, 2);

	n = "1234567890";				// Create line of digits
	n = n + n + n + n + n;			// for output
	cout << fixed << showpoint << setprecision(1);
	cout << "For a triangle with sides of length (" << a << ',' << b << ',' << c << ") :" << endl << endl;
	cout << n << endl;
	cout << setprecision(3);
	cout << setw(39) << "the area of the triangle" << " =" << setw(8) << areat << endl;
	cout << setw(39) << "the radius of the circumscribing circle" << " =" << setw(8) << radius << endl;
	cout << setw(39) << "the area of the circumscribing circle" << " =" << setw(8) << areac << endl;

	return 0;
}
