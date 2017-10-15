//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		09/13/2004
// Title:		Program 02
//
// Description: Prints an inventory of paint.
//********************************************************

#include <iostream>			// Header file for cout and endl
#include <string>			// Header file for string operations

using namespace std;			// Global using directive

/* Declare constants here */
const string FIVE_STARS = "-----";	// Five stars string constant
const char TAB = '\t';			// TAB character constant
const char ONE = '1';			// Character constant ONE
const string PAINT = " Paint";		// Paint string constant
const string PINT = " Pint";		// Pint string constant
const string QUART = " Quart";		// Quart string constant
const string GALLON = " Gallon";	// Gallon string constant
const string RED = "Red";		// Red string constant
const string YELLOW = "Yellow";		// Yellow string constant
const string GREEN = "Green";		// Green string constant

int main()
{
	/* Declare variables here */
	string header;			// Header string variable
	string dashedLine;		// Dashed line string variable
	string line1;			// Six string variables, one per line
	string line2;			// 	for storing each inventory item
	string line3;			// Declare the rest of them here
	string line4;
	string line5;
	string line6;
	
	/* Initialize header variable */
	header = "Description";
	header = header + TAB;
	header = header + TAB;
	header = header + "Quantity";
	
	/* Initialize dashed line variable here */
	dashedLine = FIVE_STARS + FIVE_STARS + FIVE_STARS;
	dashedLine = dashedLine + dashedLine;
	
	/* Use assignment operators and concatenation operators to	*/
	/* initialize the variables line1, line2, line3, line4, line5,	*/
	/* and line6. Insert your initialization statements below	*/
	/* You may have to adjust the number of Tabs to correct alignment*/
	line1 = GREEN + PAINT + TAB + TAB + ONE + GALLON;
	line2 = YELLOW + PAINT + TAB + TAB + ONE + PINT;
	line3 = RED + PAINT + TAB + TAB + ONE + GALLON;
	line4 = RED + PAINT + TAB + TAB + ONE + PINT;
	line5 = GREEN + PAINT + TAB + TAB + ONE + QUART;
	line6 = YELLOW + PAINT + TAB + TAB + ONE + QUART;
	
	// Print header and line to standard output device
	cout << header << endl;
	cout << dashedLine << endl;
	
	// Print each inventory line to the standard output device
	cout << line1 << endl;			// Output line1
	cout << line2 << endl;			// Fill in the remaining output
	cout << line3 << endl;			// 	statements to complete
	cout << line4 << endl;			// 	the assignment
	cout << line5 << endl;
	cout << line6 << endl;
	
	return 0;				// Program successful
	
} // End of main()