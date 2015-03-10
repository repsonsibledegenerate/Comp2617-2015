/*
A0080865_Dayton_Assignment02c
PartC.cpp
Author: Krista Dayton
Date: Feb72015

program that computes the value of ex by using the formula e^x = 1+ (x^1/1!) + (x^2/2!)......
*/

#include <iostream>
#include <iomanip>
#include <cmath>
using namespace std;

//main function
int main()
{
	//initialize data members
	double x;//holds the user input degree of accuracy
	double term = 1.00;//holds each term calculated
	double e_to_x = 1.00;//holds the value of e

	//prompt user for desired degree of accuracy as x
	cout << "Input a value for x between 1 and 709: ";
	cin >> x;

	//loop that tests that the value of x is between 1 and 709,
	//if not, continue looping and prompt for a value until a 
	//valid value is entered
	while (x < 0 || x > 709)
	{
		//prompt user for desired degree of accuracy as x
		cout << "Input a value for x between 1 and 709: ";
		cin >> x;
	}//end test loop

	//calculate the value of e^x
	//loop until a term becomes less than 1.0E-20
	int i;
	for (i = 1; term > 1.0E-20; i++)
	{
		term = term * (x / i);//each term calculation 
		e_to_x += term;//add the term to the total value of e^x	
	}//end calculation loop

	//output the value of e^x
	//output precision is set to 12
	cout << endl;
	cout << "e raised to the " << x << " power is " << setprecision(12) << e_to_x << endl;
	cout << endl;
	cout << "The number of terms computed is " << i << endl;
	cout << endl;
}//end main