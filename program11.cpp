//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		11/15/2004
// Title:		Program 10
//
// Description: 
//	This program is the game of life.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings

using namespace std;			//Global using directive

const int ROWMAX = 10;			//Constant for maximum number of rows
const int COLMAX = 10;			//Constand for maximum number of columns
typedef char Array[ROWMAX][COLMAX];	//Typedef statment declaring type Array to equal a character array size ROWMAX by COLMAX
typedef int IntArray[ROWMAX][COLMAX];	//Typedef statment declaring type IntArray to equal a interger array size ROWMAX by COLMAX

void LoadArray(Array, int&, int&, int&, ifstream&);		//Function to input file to character array
void PrintArray(Array, IntArray, int, int, int, ifstream&);	//Function to print out character array
void ZeroArray(Array);						//Function to zero out character array
void ZeroArray2(IntArray);					//Function to zero out interger array
void NeighborCount(Array, IntArray);				//Function to count neighbors in character array and save it into the interger array
void LifeOrDeath(Array, IntArray);				//Function to determine if a cell lives, dies, or is born

int main()
{
	Array life;			//Array declaration
	IntArray count;			//Array for neighbor count
	int iterations = 0;		//Variable for number of iterations
	int columns = 0;		//Variable for the number of columns
	int rows = 0;			//Variable for the number of rows
	string fileName;		//Variable for filename
	ifstream inFile;		//Variable for input stream

	cout << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;						//Get fileName from keyboard
	inFile.open(fileName.c_str());					//Opens file for data input
	if(!inFile)							//Tests file stream, if it fails, prints error message
	{
		cout << "Unable to open input file";
		system("pause");
		return 1;
	}

	ZeroArray(life);					//Zero out the array life
	LoadArray(life, iterations, columns, rows, inFile);	//Load the input file into life and send back the number of iterations, columns and rows
	if(columns > COLMAX || rows > ROWMAX)			//Test to see if columns or rows are too big
	{
		cout << "The number of columns or rows is too large";
		system("pause");
		return 1;
	}
	cout << "Number of iterations = " << iterations << endl << endl;	//Print out number of iterations
	cout << "Grid column dimension = " << columns << endl << endl;		//Print out number of columsns
	cout << "Grid row dimension = " << rows;				//Print out number of rows
	PrintArray(life, count, iterations, columns, rows, inFile);		//Prints out the arrray, runs LifeOrDeath and repeats as necessary

	system("pause");
	return 0;
}
//************************************************************************************
void LoadArray( /*out*/ Array arr, /*out*/ int& iterations, /*out*/ int& columns,		//This function loads the array and sends back to the
		/*out*/ int& rows, /*in*/ ifstream& inFile)				//calling program the number of iterations, columns, and rows.
{
	char a;
	int r = 0;			//Variable for row number
	int c = 0;			//Variable for column number
	cout << endl << "Loading data from file..." << endl << endl;
	inFile >> iterations;		//Readin number of iterations
	inFile >> columns;		//Readin number of columns
	inFile >> rows;			//Readin number of rows
	inFile.ignore(100, '\n');	//Ignore the rest of the first line
	do
	{
		inFile.get(a);		//Get a character
		if (a == '\n')	
		{			//If it is a newline character
			r++;		//increment the row number and set 
			c = 0;		//column to zero
		}
		else			//Otherwise, put 'a' in the array and
		{			//increment the column number
			arr[r][c] = a;
			c++;
		}
	} while (inFile);
}
//************************************************************************************
void PrintArray( /*in*/ Array arr, /*in*/ IntArray k, /*in*/ int iterations,		//This function prints the iteration
		/*in*/ int columns, /*in*/ int rows, /*in*/ ifstream& inFile)	//number and the array as '*' or '-'
{
	const string line = "____________________";
	for(int i = 0;i <= iterations; i++)
	{
		cout << endl << endl << endl;
		cout << line << endl;
		cout << "Iteration = " << i << endl;
		for(int r = 0; r < rows; r++)
		{
			for(int c = 0; c < columns; c++)
			{
				if(arr[r][c] == '1')
					cout << '*';
				if(arr[r][c] == '0')
					cout << '-';
			}
			cout << endl;
		}
		cout << endl << line << endl;
		ZeroArray2(k);
		NeighborCount(arr, k);
		LifeOrDeath(arr, k);
	}
}
//************************************************************************************
void ZeroArray( /*inout*/ Array arr)		//This function zeros out an array
{
	for(int r = 0; r < ROWMAX; r++)
	{
		for(int c = 0; c < COLMAX; c++)
			arr[r][c] = '0';
	}
}
//************************************************************************************
void ZeroArray2( /*inout*/ IntArray arr)		//This function zeros out an array
{
	for(int r = 0; r < ROWMAX; r++)
	{
		for(int c = 0; c < COLMAX; c++)
			arr[r][c] = 0;
	}
}
//************************************************************************************
void LifeOrDeath( /*inout*/ Array arr, /*inout*/ IntArray i)	//This function determines if a cell is born, survives, or dies
{
	for(int r = 0; r < ROWMAX; r++)
	{
		for(int c = 0; c < COLMAX; c++)
		{
			if(arr[r][c] == '0' && i[r][c] == 3)
				arr[r][c] = '1';
			else if(arr[r][c] == '1' && (i[r][c] == 2 || i[r][c] == 3))
				arr[r][c] = '1';
			else if(i[r][c] < 2 || i[r][c] > 3)
				arr[r][c] = '0';
		}
	}
}
//************************************************************************************
void NeighborCount( /*inout*/ Array arr, /*inout*/ IntArray i)	//This function counts the neighbors of each element of the array
{								//and saves that number in the interger array
	for(int r = 0; r < ROWMAX; r++)
	{
		for(int c = 0; c < COLMAX; c++)
		{
		if (arr[r-1][c-1] == '1' && r > 0 && c > 0)
			i[r][c] = i[r][c] + 1;
		if (arr[r-1][c] == '1' && r > 0)
			i[r][c] = i[r][c] + 1;
		if (arr[r-1][c+1] == '1' && r > 0 && c < 9)
			i[r][c] = i[r][c] + 1;
		if (arr[r][c-1] == '1' && c > 0)
			i[r][c] = i[r][c] + 1;
		if (arr[r][c+1] == '1' && c < 9)
			i[r][c] = i[r][c] + 1;
		if (arr[r+1][c-1] == '1' && r < 9 && c > 0)
			i[r][c] = i[r][c] + 1;
		if (arr[r+1][c] == '1' && r < 9)
			i[r][c] = i[r][c] + 1;
		if (arr[r+1][c+1] == '1' && r < 9 && c < 9)
			i[r][c] = i[r][c] + 1;
		}
	}
}