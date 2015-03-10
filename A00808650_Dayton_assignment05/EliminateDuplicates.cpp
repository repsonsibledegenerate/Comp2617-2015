/*
a00808650_Dayton_Assignment05:  DuplicatElimination.cpp
Author:  Krista Dayton
Date: 03/07/15

Description: program that takes user integer input and ignores the duplicate values
then outputs only the non-duplicate values entered

*/

#include <iostream>
#include <iomanip>
#include <array>
using namespace std;


int main()
{
	//intialize variables
	const int arraySize = 20;//holds the size of the array
	int userInput;//holds the user's integer input value
	int counter = 1;
	int elementCounter = 0;
	bool duplicate = false;
	//declare an int array of arraySize and initialize the elements to 0
	int answers[arraySize] = { 0 };

	//prompt user for first integer
	cout << "Enter #" << counter << " : ";
	cin >> userInput;
	while (cin.rdstate()) // check if there was a problem on input
	{
		cin.clear(); // if yes, clear the error bit that is set (badbit, failbit or eofbit) 
		cin.ignore(INT_MAX, '\n'); // flush the input buffer

		cout << "Enter #" << counter << " : ";
		cin >> userInput;
	}
	while (counter <= arraySize){
		while (userInput <= 10 || userInput >= 100)
		{
			cerr << "The number entered is not in valid range of 10 to 100" << endl;
			cout << "Enter #" << counter << " : ";
			cin >> userInput;
		}

		int looper = 0;
		while (looper < arraySize)
		{
			if (answers[looper] == userInput)
			{
				duplicate = true;
			}
			looper++;
		}

		if (duplicate == false)
		{
			answers[elementCounter] = userInput;
			cout << "The number: " << userInput << " is unique" << endl;
			cout << '\n';
		}

		counter++;
		elementCounter++;
		//prompt user for another number
		cout << "Enter #" << counter << " : ";
		cin >> userInput;
	}

	//output the unique values in a table



}//end of main