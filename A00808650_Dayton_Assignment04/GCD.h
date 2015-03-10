/*
A00808650_Dayton_Assignment04
GCD.h
Author: Krista Dayton
Date: Feb 19 2015

Template function that calculates the gcd of 2 denominators

*/

//function template GCD header
template<typename T> 
T gcd(T value1, T value2)
{
	T gcd = 1;

	//if num1 is negative, swap negation
	if (value1 < 0)
	{
		value1 = -value1;
	}
	//if num2 is negative, swap negation
	if (value2 < 0)
	{
		value2 = -value2;
	}
	//calculate the GCD
	for (int i = 1; i <= value1 && i <= value2; ++i)
	{
		if (value1%i == 0 && value2%i == 0)
		{
			gcd = i;
		}
	}
	return gcd;
}