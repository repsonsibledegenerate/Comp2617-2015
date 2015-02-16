/*
A00808650_Dayton_Assignment03
MathTutorial.cpp
Author: Krista Dayton A00808650
Date: Feb142015

Program that helps students learn multiplication
The program chooses 2 random integers to multiply and prompts the student to answser
Correct answers get a positive congratulatory repsonse and asked another question until the sentinel value is entered
Incorrect answers are given a reponse of encouragement and asked for another answer

*/
#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;


//global function prototypes
void multiplication();
void correctMessage();
void incorrectMessage();


int main()
{
	multiplication();

}//end of main function

void multiplication()
{
	//initialize variables
	const int SENTINEL = -1;//holds the sentinel value that when entered, 
	//exits the main loop of the programm
	unsigned int number1;
	unsigned int number2;
	unsigned int answer = 0;
	unsigned int product;

	//begin the program 
	cout << "Enter -1 to end." << endl;

	//enter response loop, continue until the sentinel value is entered
	while (answer != -1)
	{
		srand(static_cast<unsigned int>(time(0)));//seed rand with the time function
		number1 = rand() % 10;//first random number
		number2 = rand() % 10;//second random number
		product = number1 * number2;//holds the calculation of the multiplied numbers

		//ask the multiplication question and get user answser
		cout << "How much is " << number1 << " times " << number2 << " (-1 to end) ";
		cin >> answer;//input answer from user

		//if the answer is correct, call the correctMessage function
		//if the answer is wrong, call the incorrectMessage function until the correct value is entered
		while (answer != product && answer != -1)
		{
			incorrectMessage();
			cout << "? ";
			cin >> answer;
		}
		if (answer == product)
		{
			correctMessage();
		}
	}
	//exit message
	cout << "\n";
	cout << "That's all for now. Bye " << endl;

}//end multiplication function

//function creates a random number and prints a corresponding response from
//a switch statement
void correctMessage()
{
	//create a random number between 1 and 4
	unsigned int response = 1 + rand() % 4;
	//switch statement to determine the reponse output
	switch (response)
	{
	case 1:
		cout << "Very good!\n" << endl;
		break;
	case 2:
		cout << "Excellent!\n" << endl;
		break;
	case 3:
		cout << "Nice work!\n" << endl;;
		break;
	case 4:
		cout << "Keep up the good work\n" << endl;
		break;
	default:
		cerr << "oh oh, something went wrong\n" << endl;
		break;
	}
}//end of correctMessage function

//function creates a random number and prints a corresponding response from
//a switch statement
void incorrectMessage()
{
	//create a random number between 1 and 4
	unsigned int response = 1 + rand() % 4;
	//switch statement to determine the reponse output
	switch (response)
	{
	case 1:
		cout << "No, Please try again." << endl;
		break;
	case 2:
		cout << "Wrong. Try once more." << endl;
		break;
	case 3:
		cout << "Don't give up!" << endl;
		break;
	case 4:
		cout << "No. Keep trying." << endl;
		break;
	default:
		cerr << "Nope. Double check your random generator" << endl;
		break;
	}
}//end incorrectMessage function
