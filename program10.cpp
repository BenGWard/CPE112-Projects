//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		11/15/2004
// Title:		Program 10
//
// Description: 
//	This program inputs, sorts, and prints an array of
//	integers.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings

using namespace std;			//Global using directive

void PrintArray(const int arr[], int num);
void ZeroArray(int arr[], int num);
void LoadArray(int arr[], int& num, ifstream& inFile);
void Swap(int arr[], int m, int n);
int Minimum(const int arr[], int begin, int end);
void SelectionSortAscending(int arr[], int num);

int main()
{
	int array[10];			//Variable for array
	int num = 10;			//Variable for number of objects in array
	string fileName;		//Variable for filename to open
	
	ifstream inFile;
	cout << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;								//Get fileName from keyboard
	cout << endl;	
	inFile.open(fileName.c_str());							//Opens file for data input

	ZeroArray(array, num);
	cout << "Array initialized to zero..." << endl;
	PrintArray(array, num);
	
	LoadArray(array, num, inFile);
	cout << "Array values as input from file..." << endl;
	PrintArray(array, num);
	
	SelectionSortAscending(array, num);
	cout << "Array values sorted in ascending order..." << endl;
	PrintArray(array, num);

	return 0;
}

//************************************************************************************
void PrintArray(const int arr[], int num)		//This function prints arr[0] through arr[num-1]
{
	for(int n = 0; n < num; n++)
		cout << "A[ " << n << "] = " << arr[n] << endl;
	cout << endl;
}

//************************************************************************************
void ZeroArray(int arr[], int num)		//This function sets arr[0] through arr[num-1] to zero
{
	for(int n = 0; n < num; n++)
		arr[n] = 0;
}

//************************************************************************************
void LoadArray(int arr[], int& num, ifstream& inFile)	//This function opens the input file and loads the data in that file into an array
{

	num = 0;
	do
	{
		inFile >> arr[num];
		if (inFile)
			num++;
	} while(inFile && num < 10);
}

//************************************************************************************
void Swap(int arr[], int m, int n)	//This function swaps the value between two array positions
{
	int k;
	k = arr[m];
	arr[m] = arr[n];
	arr[n] = k;
}

//************************************************************************************
int Minimum(const int arr[], int begin, int end)	//This function returns the index value of the smallest element in a subarray
{
	int n;
	n = begin;	
	int minnum = n;
	int min = arr[begin];	
	for(; n < end; n++)
		if (arr[n] < min)
		{
			min = arr[n];
			minnum = n;
		}
	return minnum;
}

//************************************************************************************
void SelectionSortAscending(int arr[], int num)		//This function sorts the integers in the array
{
	int n = 0;
	int r;

	do
	{	
		r = Minimum(arr, n, num);
		Swap(arr, n, r);
		n++;
	} while( (num - n) > 0);
}