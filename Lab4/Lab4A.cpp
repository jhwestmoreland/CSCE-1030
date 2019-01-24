/*
	Author:	Jared Westmoreland
	Date:	9/27/2018
	Instructor: Dr. Thompson
	Description: Flow of Control
*/
#include <iostream>
#include <time.h>
#include <stdlib.h>
using namespace std;

int main()
{
	// declares random
	srand(time(NULL));
	//varibles
	int x;
	int random;

	//userinput
	cout<<"Enter a value for x: ";
	cin>>x;

	//checks if user input is between 1 and 100
	if(x>0 && x<= 100)
	{
		//assigns random to random varibake
		random = rand()%100+1;
		//if greater than
		if(x > random)
		{
			cout<<"Your value "<<x<<" was greater than "<<random<<".\n";
		}
		//if less than 
		else if(x < random)
                {
                        cout<<"Your value "<<x<<" was less than "<<random<<".\n";
                }
		//if equal to
		else
                {
                        cout<<"Your value "<<x<<" was equal to "<<random<<".\n";
                }
	}
	//if not within the range of 1 and 100
	else
	{
		cout<<"Error: number is outside of the range.\n";
	}
}
