//********************************************************
// Name:		Ben Ward
// Lab Section: 	CPE 112L-04
// Lecture Section: 	CPE 112-02
// Date:		10/31/2004
// Title:		Program 08
//
// Description: 
//	This program performs operations on a store inventory
//	list.
//********************************************************

#include <iostream>			//Header file for cout and endl
#include <fstream>			//Header file for file I/O
#include <string>			//Header file for strings
#include <iomanip>			//Header file for I/O manipulators

using namespace std;			//Global using directive

struct ItemType
{
	long	catalogNumber;		//Catalog number
	float	wholesale;		//Item wholesale price
	float	retail;			//Item retail price
	int	quantity;		//Quantity in stock
	string	description;		//Item description
};

void PrintMenu(int& choice);
void PrintItem(ItemType& item);
void PrintInventory();
void PrintReorderList();
void PrintWholesaleValue();
void PrintRetailValue();
void GetItem(string&, ItemType&, ItemType&, ItemType&);

int main()
{
	int choice = 0;			//Variable for menu choice
	while(choice >=0 && choice <=4)
	{
		PrintMenu(choice);
		if(choice == 1)
			PrintInventory();
		else if(choice == 2)
			PrintReorderList();
		else if(choice == 3)
			PrintWholesaleValue();
		else if(choice == 4)
			PrintRetailValue();
	}

	return 0;
}

//************************************************************************************
void PrintMenu(int& choice)	//This function prints the program menu
{
	const string dash = "----------";

	cout << endl << endl << dash << endl;
	cout << "Main Menu" << endl << endl;
	cout << "1. Print Inventory" << endl;
	cout << "2. Print Reorder List" << endl;
	cout << "3. Print Inventory Wholesale Value" << endl;
	cout << "4. Print Inventory Retail Value" << endl;
	cout << "5. Exit Program" << endl << endl;
	cout << "Please select one of the menu options above: ";
	cin >> choice;
}
//************************************************************************************
void PrintItem(ItemType& item)		//This function prints a single record to standard output
{
	cout << setprecision(2) << fixed << showpoint;
	cout << item.catalogNumber << '\t' << '\t' << item.wholesale 
		<< '\t' << '\t' << item.retail << '\t' << item.quantity << '\t' 
		<< item.description;
}
//************************************************************************************
void PrintInventory()				//This function prints the inventory list
{
	ItemType item1;
	ItemType item2;
	ItemType item3;
	string fileName;
	GetItem(fileName, item1, item2, item3);		//Open the file and read in the data
	cout << endl << "Printing Inventory Now..."
		<< endl << "Inventory file = " << fileName
		<< endl << endl << endl << "Item" << '\t'
		<< "Catalog #" << '\t' << "Wholesale $"
		<< '\t' << "Retail" << '\t' << "Quantity"
		<< '\t' << "Description" << endl;
	cout << 1 << '\t';
	PrintItem(item1);
	cout << endl << 2 << '\t';
	PrintItem(item2);
	cout << endl << 3 << '\t';
	PrintItem(item3);
}
//************************************************************************************
void PrintReorderList()	//This function prints list of items with quantity == 0
{
	ItemType item1;
	ItemType item2;
	ItemType item3;
	string fileName;
	GetItem(fileName, item1, item2, item3);		//Open the file and read in the data
	cout << endl << "Printing Reorder List Now..."
		<< endl << "Inventory file = " << fileName
		<< endl << endl << endl << "Item" << '\t'
		<< "Catalog #" << '\t' << "Wholesale $"
		<< '\t' << "Retail" << '\t' << "Quantity"
		<< '\t' << "Description" << endl;
	if(item1.quantity == 0)
	{
		cout << 1 << '\t';
		PrintItem(item1);
	}
	if(item2.quantity == 0)
	{
		cout << endl << 2 << '\t';
		PrintItem(item2);
	}
	if(item3.quantity == 0)
	{
		cout << endl << 3 << '\t';
		PrintItem(item3);
	}
}
//************************************************************************************
void PrintWholesaleValue()	//This function prints the sum of the wholesale values of the items in the file
{
	ItemType item1;
	ItemType item2;
	ItemType item3;
	string fileName;
	float sum;
	GetItem(fileName, item1, item2, item3);		//Open the file and read in the data
	sum = item1.wholesale * item1.quantity
		 + item2.wholesale * item2.quantity
		 + item3.wholesale * item3.quantity;
	cout << setprecision(2) << fixed << showpoint;
	cout << endl << "Printing Wholesale Value Now..."
		<< endl << "Inventory file = " << fileName
		<< endl << endl;
	cout << "Inventory Total Wholesale Value = $" << sum;
}
//************************************************************************************
void PrintRetailValue()	//This function prints the sum of the retail values of the items in the file
{
	ItemType item1;
	ItemType item2;
	ItemType item3;
	string fileName;
	float sum;
	GetItem(fileName, item1, item2, item3);		//Open the file and read in the data
	sum = item1.retail * item1.quantity
		+ item2.retail * item2.quantity
		+ item3.retail * item3.quantity;
	cout << setprecision(2) << fixed << showpoint;
	cout << endl << "Printing Retail Value Now..."
		<< endl << "Inventory file = " << fileName
		<< endl << endl;
	cout << "Inventory Total Retail Value = $" << sum;
}
//************************************************************************************
void GetItem(string& fileName, ItemType& item1, ItemType& item2, ItemType& item3)		//This function opens the file input stream
{
	ifstream inFile;
	cout << endl << endl << endl << "Enter the name of the input file now: ";	//Prompt user for filename
	cin >> fileName;								//Get fileName from keyboard	
	inFile.open(fileName.c_str());							//Opens file for data input
	cout << endl << endl;
	
	inFile.ignore(500, '\n');							//Ignore the first line of comments
	inFile >> item1.catalogNumber >> item1.wholesale >> item1.retail		//Reads the data from the file and stores
		>> item1.quantity;							//it into the variable ItemType
	getline(inFile, item1.description);
	inFile >> item2.catalogNumber >> item2.wholesale >> item2.retail		//Reads the data from the file and stores
		>> item2.quantity;							//it into the variable ItemType
	getline(inFile, item2.description);
	inFile >> item3.catalogNumber >> item3.wholesale >> item3.retail		//Reads the data from the file and stores
		>> item3.quantity;							//it into the variable ItemType
	getline(inFile, item3.description);
	inFile.close();
}
