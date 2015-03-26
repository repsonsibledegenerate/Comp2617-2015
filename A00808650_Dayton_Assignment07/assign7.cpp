/*
A00808650_Dayton_Assignment07:  assign7.cpp
Author: Krista Dayton
Date: March 21 2015

program that simulates the cloassic tortoise and hare race using Random number generation

*/

#include <iostream>
#include <random>
#include <ctime>
#include <array>
#include <string>
#include <iomanip>
using namespace std;

const int FINISH_LINE = 69;
const int arraySize = 70;

//function prototypes

//moves the turle based on the random number generated
void moveTortoise(int, int &);
//moves the hare based on the random number generated
void moveHare(int, int &);
//displays the race progress
void displayRace(const array<int, arraySize> &, int &, int &);



//main function
int main()
{
	//create a random generator for the tortoise and hare to determine 
	//seed the engine with the time() function
	default_random_engine engine(static_cast<unsigned int>(time(0)));
	uniform_int_distribution<unsigned int> turtleRandom(1, 10);
	uniform_int_distribution<unsigned int> bunnyRandom(1, 10);

	//set the starting position of each contestant to 1
	//variables will hold current position of each
	int turtleMoves = 1;
	int hareMoves = 1;

	int timeTick = 0;//holds the seconds or number of loops till the race is over
	
	//announce the start of the race
	cout << "ON YOUR MARK, GET SET\n"
	<< "BANG                   !!!!\n"
	<< "AND THEY'RE OFF        !!!!" << endl;

	//continue the race until one of the contestants reaches the end
	//of the course or goes beyond
	while (turtleMoves != FINISH_LINE && hareMoves != FINISH_LINE)
	{
		//declare an array to hold the spaces the tortoise and hare
		//will travel in the race
		//intialize the elements to 0
		array<int, arraySize>course = {0};

		//move the hare and move the tortoise
		//display the race
		moveHare(bunnyRandom(engine), hareMoves);
		moveTortoise(turtleRandom(engine), turtleMoves);
		displayRace(course, hareMoves, turtleMoves);
		
		cout << endl;
		timeTick++;//increment the timer
	}
	//the race has ended, who won and how long did it take?
	//display the resultls
	cout << endl;
	if (hareMoves > turtleMoves)
	{
		cout << "\nHare wins. Yuck.\n";
	}
	else{
		cout << "TORTOISE WINS !!! YAY!!!\n";
	}
	cout << "\nTIME ELAPSED = " << timeTick << " seconds" << "\n" << endl;
	
}

//function to move the hare 
void moveHare(int random, int &hareMoves)
{

	int bigHop = 9;//holds the number of spaces in a bigHop
	int bigSlip = -12;//holds the number of spaces in a bigSlip
	int smallHop = 1;//holds the number of spaces in a smallHop
	int smallSlip = -1;//holds the number of spaces in a smallSlip
	//switch to determine the move type
	switch (random)
	{
	case 1://sleep, nothing happens
	case 2:
		break;
	case 3://big hop
	case 4:
		hareMoves += bigHop;//moves 9 spaces to the right
		if (hareMoves > FINISH_LINE)
		{
			//ensure we don't go past the finish line
			hareMoves = FINISH_LINE;
		}
		break;
	case 5://big slip
		hareMoves += bigSlip;//moves 12 spaces to the left
		if (hareMoves < 1)
		{
			//ensure we don't go backwards past the startline
			hareMoves = 1;
		}
		break;
	case 6://small hop
	case 7:
	case 8:
		hareMoves += smallHop;//moves 1 space to the right
		if (hareMoves > FINISH_LINE)
		{
			//ensure we don't go past the finish line
			hareMoves = FINISH_LINE;
		}
		break;
	case 9://small slip
	case 10:
		hareMoves += smallSlip;//moves 2 spaces to the left
		if (hareMoves < 1)
		{
			//ensure we don't go backwards past the startline
			hareMoves = 1;
		}
		break;
	default:
		cerr << "Something has gone horribly, horribly wrong" << endl;
	}
}//end of moveHare function

//function to move the tortoise
void moveTortoise(int random, int &turtleMoves)
{

	int fastPlod = 3;//holds the number of spaces in a fast plod
	int slip = -9;//holds the number of spaces in a slip
	int slowPlod = 1;//holds the number of spaces in a slow plod

	//switch to determine move type
	switch (random)
	{
	case 1://fast plod 
	case 2:
	case 3:
	case 4:
	case 5:
		turtleMoves += fastPlod;//moves 3 spaces to the right
		if (turtleMoves > FINISH_LINE)
		{
			//don't go off the course
			turtleMoves = FINISH_LINE;
		}
		break;
	case 6://slip
	case 7:
		turtleMoves += slip;//moves 9 spaces to the left
		if (turtleMoves < 1)
		{
			//don't go off the course
			turtleMoves = 1;
		}
		break;
	case 8://slow plod
	case 9:
	case 10:
		turtleMoves += slowPlod;//moves 1 space to the right
		if (turtleMoves > FINISH_LINE)
		{
			//don't go off the course
			turtleMoves = FINISH_LINE;
		}
		break;
	default:
		cerr << "Try again cause this ain't workin!" << endl;
	}

}//end of moveTortoise function

//display the progress of the race
void displayRace(const array<int, arraySize> &course, int &hare, int &turtle)
{
	array<int, arraySize> mountain = course;

	//set the current position of the hare and turtle on the course array
	//as 1 for hare and 2 for tortoise and 3 if they land on the same
	//space
	if (hare == turtle)
	{
		mountain[hare] = 3;
		mountain[turtle] = 3;
	}
	else{
		mountain[hare] = 1;
		mountain[turtle] = 2;
	}//end of if

	//loop through the array to display the positions
	//of the turtle and hare
	for (int i = 0; i < arraySize; ++i)
	{
		if (mountain[i] == 0)
		{
			cout << " ";
		}
		else if (mountain[i] == 1)
		{
			cout << 'H';
		}
		else if (mountain[i] == 2)
		{
			cout << 'T';
		}
		//if they land on the same space
		//the tortoise bites the hare...haha
		else if (mountain[i] == 3)
		{
			cout << "OUCH!!";
		}
	}
}//end of displayRace() function