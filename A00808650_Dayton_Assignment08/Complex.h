/*
A00808650_Dayton_Assignment08:   Complex.h
Author: Krista Dayton
Date: March 29 2015

Complex class definition, implementation is contained in Complex.cpp file
Program that adds, subtracts and displays complex numbers

*/


class Complex
{
public:
	//default Ctor takes 2 default values
	Complex(double = 1.0, double = 0.0);
	//add complex numbers
	Complex & plusEq(const Complex & );
	//subtract complex numbers
	Complex & minusEq(const Complex & );
	//display results 
	void display();
private:
	double real;
	double imaginary;


};