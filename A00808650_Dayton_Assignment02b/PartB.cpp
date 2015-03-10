/*
A00808650_Dayton_Assignment02b
PartB.cpp
Author: Krista Dayton
Date: Feb72015

Program that estimates the value of the mathematical constant e

*/

#include <iostream>
#include <iomanip>
using namespace std;

//main function
int main()
{
	//initialize variables
	const double NUMERATOR = 1.00;
	long long factorial = 1;//holds the factorial value
	unsigned int terms;//holds the user input number of terms(loops) to compute
	double e = 0.00;//holds the value of the caculated e

	//prompt user to enter a nonnegative integer between 5 and 13
	cout << "The number of terms to compute is (5 to 13 are valid values): ";
	cin >> terms;

	//loop to test that the value entered is valid, if not, continue to prompt user
	//until a valid value is entered
	while (terms < 5 || terms > 13)
	{
		//prompt user to enter a nonnegative integer between 5 and 13
		cout << "The number of terms to compute is (5 to 13 are valid values): ";
		cin >> terms;
	}//end of test loop

	//calculate the value of e given the terms to compute
	for (unsigned int i = 1; i < terms; ++i)
	{
		factorial *= i;// calculate the factorial for the given terms
		e += NUMERATOR / factorial;// calculate the equation 1/		
	}
	//output the value of e
	cout << "The value of e is: " << fixed << setprecision(12) << e << endl;
	cout << endl;
}//end of main