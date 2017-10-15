//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		09/20/2004
// Title:		Program 03
//
// Description: 
//	Given the principal amount, interest rate, and number of years, this
//	program computes savings account balance for simple and compound
//	interest (compounded monthly and continuously).
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <cmath>			//Header file for math operations
#include <iomanip>			//Header file for I/O manipulators

using namespace std;			//Global using directive

const int N = 12;			//Number of periods per year

int main()
{
	double principal;
	double rate;
	double years;
	double simple;
	double monthly;
	double continuously;
	double ratePercent;
	
	//Input from user
	
	cout << endl;
	cout << "Input the starting balance: ";
	cin >> principal;
	cout << endl;
	cout << "Input the interest rate (Ex. 0.05 for 5%): ";
	cin >> rate;
	cout << endl;
	cout << "Input the number of years: ";
	cin >> years;
	cout << endl << endl;
	
	//Interest calculations
	
	simple = principal * (1 + years * rate);
	monthly = principal * pow(( 1 + rate/N), N*years);
	continuously = principal * exp(rate*years);
	
	//Output to user
	cout << fixed << showpoint << setprecision(2);
	ratePercent = rate * 100;
	
	cout << "For a principal of $" << principal << " at an interest rate of ";
	cout << ratePercent << "% for a period of " << endl << years;
	cout << " years, the final account balance would be" << endl << endl;
	cout << "Simple Interest = $" << simple << endl;
	cout << "Compounded Monthly = $" << monthly << endl;
	cout << "Compounded Continuously = $" << continuously << endl << endl ;
	
	return 0;
	
}