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
using namespace std;

//function prototypes
void moveTortoise(int, int &);
void moveHare(int, int &);

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
	int timeTick = 0;
	const int FINISH_LINE = 70;

	//announce the start of the race
	cout << "Bang !!!\n"
	<< "And they're off !!!!!" << endl;

	//continue the race until one of the contestants reaches the end
	//of the course or goes beyon
	while (turtleMoves != FINISH_LINE && hareMoves != FINISH_LINE)
	{
		//declare an array to hold the spaces the tortoise and hare
		//will travel in the race
		//intialize the elements to 0
		const int arraySize = 70;
		array<char, arraySize>course = {' '};

		//move the hare and move the tortoise
		moveHare(bunnyRandom(engine), hareMoves);
		moveTortoise(turtleRandom(engine), turtleMoves);

		//set the current position of the hare and turtle on the course array
		//as 1 for hare and 2 for tortoise
		course[hareMoves] = 'H';
		course[turtleMoves] = 'T';
		for (int i = 0; i <= arraySize; ++i)
		{
			cout << course[i];
			if (course[i] == ' ')
			{
				cout << " ";
			}
		}
		cout << endl;
		timeTick++;
	}
	cout << '\n\n';
}

//function to move the hare 
void moveHare(int random, int &hareMoves)
{
	//switch to determine the move type
	switch (random)
	{
	case 1://sleep, nothing happens
	case 2:
		break;
	case 3://big hop
	case 4:
		hareMoves += 9;//moves 9 spaces to the right
		break;
	case 5://big slip
		hareMoves -= 12;//moves 12 spaces to the left
		if (hareMoves < 1)
		{
			hareMoves = 1;
		}
		break;
	case 6://small hop
	case 7:
	case 8:
		hareMoves += 1;//moves 1 space to the right
		break;
	case 9://small slip
	case 10:
		hareMoves -= 2;//moves 2 spaces to the left
		if (hareMoves < 1)
		{
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
	//switch to determine move type
	switch (random)
	{
	case 1://fast plod 
	case 2:
	case 3:
	case 4:
	case 5:
		turtleMoves += 3;//moves 3 spaces to the right
		break;
	case 6://slip
	case 7:
		turtleMoves -= 9;//moves 9 spaces to the left
		if (turtleMoves < 1)
		{
			turtleMoves = 1;
		}
		break;
	case 8://slow plod
	case 9:
	case 10:
		turtleMoves += 1;//moves 1 space to the right
		break;
	default:
		cerr << "Try again cause this ain't workin!" << endl;
	}
}//end of moveTortoise function