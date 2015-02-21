/*
A00808650_Dayton_Assignment04
GCD.h
Author: Krista Dayton
Date: Feb 19 2015

Template function that negates negative values and calculates the gcd of the denominators

*/

//function template GCD header
template<typename T> 
T GCD(T value1, T value2)
{
	//initialize variables
	T firstNumber;
	T secondNumber;
	T gcd = 1;

	//negate any negative values




	//calculate the GCD
	for (unsigned int i = 1; i <= firstNumber && i <= secondNumber; ++i)
	{
		if (firstNumber%i == 0 && secondNumber%i == 0)
		{
			gcd = i;
		}
	}
}