/*
TortoiseAndHare.cpp
Zachary Elmore
6/21/16
Time for a race!!! The tortoise vs the hare.
*/

#include <iostream>
#include <string>
#include <iomanip>
#include <ctime>
using namespace std;

const int FINISH_LINE = 70;//Constant for the finish line

void Tortoise(int *);//Prototype for tortoise
void Hare(int *);//Prototype for hare
void Positions(int*, int*);//Prototype for the positions for the tortoise and the hare 

int main()
{
	int T = 1;
	int H = 1;//Both toroise and hare starts at 1
	int timer = 0;//Timer starts at zero

	srand(time(0));

	cout << "On your mark.\nGet set.\nBANG!\nAND THEY'RE OFF!!!!!" << endl;

	while (T != FINISH_LINE && H != FINISH_LINE)
	{
		Tortoise(&T);//Calls for the tortoise
		Hare(&H);//Calls for the hare
		Positions(&T, &H);//Calls for the positions of both tortoise and hare
		++timer;//Timer is being pre-incremented
	}

	if (T > H)//Output if tortoise wins
	{
		cout << "The tortoise wins!" << endl;
	}
	else if (T < H)//Output if hare wins
	{
		cout << "The hare wins!" << endl;
	}
	else if (T == H)//Output if they both win
	{
		cout << "It's a tie!" << endl;
	}

	cout << "TIME ELAPSED: " << timer << " minutes" << endl;//Output for how long the race lasted

	cin.ignore();
	cin.get();
	return 0;
}

void Tortoise(int *turtlePtr)
{
	int x = 1 + rand() % 10;//Gives a random number for the tortoise's moves

	if (x >= 1 && x <= 5)//Fast plod
	{
		*turtlePtr += 3;
	}
	else if (x == 6 || x == 7)//Slip
	{
		*turtlePtr -= 6;
	}
	else //Slow plod
	{
		++(*turtlePtr);
	}

	if (*turtlePtr < 1)//Won't allow tortoise to go below 1
	{
		*turtlePtr = 1;
	}
	else if (*turtlePtr > FINISH_LINE)//Tortoise goes past the finish line, then he's at the finish line
	{
		*turtlePtr = FINISH_LINE;
	}
}

void Hare(int *rabbitPtr)
{
	int y = 1 + rand() % 10;//Gives a random number for the hare's moves

	if (y == 3 || y == 4)//Big hop
	{
		*rabbitPtr += 9;
	}
	else if (y == 5)//Big slip
	{
		*rabbitPtr -= 12;
	}
	else if (y >= 6 && y <= 8)//Sleep
	{
		++(*rabbitPtr);
	}
	else if (y > 8)//Small slip
	{
		*rabbitPtr -= 2;
	}
	else if (y < 1)//Small hop
	{
		*rabbitPtr = 1;
	}
	else if (*rabbitPtr > FINISH_LINE)//If hare goes past the finish line, then he's at the finish line
	{
		*rabbitPtr = FINISH_LINE;
	}
}

void Positions(int *ninjaPtr, int *bunnyPtr)
{
	if (*bunnyPtr == *ninjaPtr)//Out put for the pointer if they run into eachother
	{
		cout << setw(*bunnyPtr) << "OUCH!!!";
	}
	else if (*bunnyPtr < *ninjaPtr)//Output for pointers if hare is behind the tortoise
	{
		cout << setw(*bunnyPtr) << 'H' << setw(*ninjaPtr - *bunnyPtr) << 'T';
	}
	else//Output for pointers if the tortois is behind the hare
	{
		cout << setw(*ninjaPtr) << 'T' << setw(*bunnyPtr - *ninjaPtr) << 'H';
	}

	cout << "\n";
}