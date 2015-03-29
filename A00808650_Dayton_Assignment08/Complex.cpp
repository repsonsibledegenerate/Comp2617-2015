/*
A00808650_Dayton_Assignment08:  Complex.cpp
Author: Krista Dayton
Date: March 29 2015

Implementation of class Complex definition Complex.h

*/
#include "Complex.h"
#include <iomanip>
#include <iostream>
using namespace std;


Complex::Complex(double r, double i) :real(r), imaginary(i)
{ }

//add complext numbers
Complex &Complex::plusEq(const Complex &op)
{
	real += op.real;
	imaginary += op.imaginary;

	return (*this);
}

//subtract real and imaginary numbers
Complex &Complex::minusEq(const Complex &op)
{
	real -= op.real;
	imaginary -= op.imaginary;

	return (*this);
}

//display the complex number in the form
// (a,b) a = real, b = img
void Complex::display()
{
	cout << fixed << setprecision(4) << "( " << real << " , " << imaginary << " )";

}