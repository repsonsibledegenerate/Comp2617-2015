// Assignment 4: Fraction.cpp
// Member-function definitions for class Fraction.
// Author:  Krista Dayton	
// Date: Feb 21 2015

#include "Fraction.h"
#include "GCD.h" // template function for calculating greatest common divisor
#include <iostream>
using namespace std;


Fraction::Fraction(void)
{
	numerator = 0;
	denominator = 1;
}
// second ctor, which
// requires at least one long long argument
Fraction::Fraction(long long num, long long denom)
: numerator(num), denominator(denom)
{
	simplify();// will make sure that denominator is positive and
				//   will invoke gcd() function to reduce fraction
				//   as much as possible
}
// will make sure that denominator is positive and
// will invoke gcd() function to reduce fraction
// as much as possible
void Fraction::simplify(void)
{
	long long divisor = gcd(numerator, denominator);//call the gcd template function and find the lowest common denom

	numerator /= divisor;//divide the numerator by the gcd 
	denominator /= divisor;//divide the denominator by the gcd

	if (denominator < 0)
	{
		denominator = -denominator;
		numerator = -numerator;
	}
}

//Adds RHS to the Fraction object invoked with this method
//(thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::plusEq(const Fraction & op)
{
	
	numerator *= op.denominator;//multiply the first numerator by the second denominator
	numerator += op.numerator * denominator; //multiply the second numerator by the first denominator
	//and add
	denominator *= op.denominator; //multiply the denominators to get a common
	simplify();// will make sure that denominator is positive and
				//   will invoke gcd() function to reduce fraction
				//   as much as possible

	return (*this);
}
//Subtracts RHS from the Fraction object invoked with this method
//  (thereby modifying the Fraction object) and returns the result
const Fraction & Fraction::minusEq(const Fraction & op)
{
	numerator *= op.denominator;//multiply the first numerator by the second denominator
	numerator -= op.numerator * denominator; //multiply the second numerator by the first 
	//denominator and subtract from the new first numerator
	denominator *= op.denominator; //multiply the denominators to get a common
	

	simplify();	// will make sure that denominator is positive and
				//   will invoke gcd() function to reduce fraction
				//   as much as possible

	return (*this);// returns the object which invoked the method
}
//Implementation of the timesEq() member function
//Performs similar operation as the *= operator on the built-in types
const Fraction & Fraction::timesEq(const Fraction & op )
{
	numerator *= op.numerator;
	denominator *= op.denominator;

	simplify();  // will make sure that denominator is positive and
	             //   will invoke gcd() function to reduce fraction
	             //   as much as possible

	return (*this); // returns the object which invoked the method
}

const Fraction & Fraction::divideEq (const Fraction & op )
{
    numerator *= op.denominator;
    denominator*=op.numerator;
    
	simplify(); // will make sure that denominator is positive and
				//   will invoke gcd() function to reduce fraction
				//   as much as possible
    
    return (*this);// returns the object which invoked the method
}
//Returns the negation of the Fraction object
//invoked with the method but must NOT
//modify the actual Fraction object invoked
//with the method.
Fraction Fraction::negate(void)const
{
	//create a new Fraction object and negate the numerator and 
	//return the temp object to the calling function
	Fraction fact = Fraction(-numerator, denominator);
	return fact;
}
// Returns numerator
long long Fraction::getNum(void)const
{
	return numerator;
}
// Returns denominator
long long Fraction::getDenom(void)const
{
	return denominator;
}
// Outputs to standard output stream the Fraction object
//   in the format: numerator/denominator
void Fraction::display(void)const
{
	cout << numerator << "/" << denominator << endl;
}