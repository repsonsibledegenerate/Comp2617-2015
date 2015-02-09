/*
A00808650_Dayton_Assignment02a
PartA.cpp
Author: Krista Dayton 
Date: Feb72015

Program that accepts a nonnegative integer from an user and calculates that integer's factorial

*/

#include <iostream>
#include <iomanip>
using namespace std;

//main function
int main()
{
	//intialize variables
	long long factorial = 1;//holds the factorial value
	unsigned int numToCalculate = 0;//holds the input value from the user

	//prompt the user to input a nonnegative integer between 0 and 20
	cout << "Enter a positive integer less than or equal to 20: ";
	cin >> numToCalculate;//holds the input value

	//enter loop that checks that the numToCalculate value is equal to or less than 20 and is positive
	//if the value is invalid, reenter loop and ask for input until a valid value is input
	while (numToCalculate < 0 || numToCalculate > 20)
	{
		//prompt the user to input a nonnegative integer between 0 and 20
		cout << "Enter a positive integer less than or equal to 20: ";
		cin >> numToCalculate;
	}//end loop

	//calculate the factorial for the given value
	for (unsigned int i = 1; i <= numToCalculate; ++i)
	{
		factorial *= i;//each loop takes the previous value and multiplies it by the incremented i value
	}

	//output the factorial value
	cout << numToCalculate << "! is " << factorial << endl;
	cout << endl;

}//end of main function