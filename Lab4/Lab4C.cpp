/*
	Author:	Jared Westmoreland
	Date:	9/27/2018
	Instructor: Dr. Thompson
	Description: String Manipulation
*/
#include <iostream>
#include <string>
using namespace std;

int main()
{
	//variables
	string userinput;
	int size;
	int j=0;
	int loop;

	//user input
	cout<<"Please enter a palindrome: ";
	cin>>userinput;

	//find length of string
	size = userinput.length();
	//divideds by 2 and stores is into loop. ex: loop will equal 2 if size = 5 because it does not store decimals
	loop = size/2;

	//if valid string length
	if(size > 2)
	//loops for size/2
	for(int i=0; i<loop; i++)
	{
		//checks the first and last letter of the string
		if(userinput.at(i) == userinput.at(size-i-1))
		//for every instance add one to j
		j++;
	}
	//if not valid string length
	else
	cout<<userinput<<" needs to be more than 2 letters long.\n";

	//compares j to the size/2. ex: rac e car
	if(j == size/2)
	cout<<userinput<<" is a palindrome.\n";
	//if it does not compare
	else
	cout<<userinput<<" is not a palindrome.\n";
}

