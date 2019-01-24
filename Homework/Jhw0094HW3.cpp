/*
	Jared Westmoreland
	Homework 3
	CSCE 1030
	Disease Modelling
*/
#include <iostream>
using namespace std;

const int SIZE = 7;
char create_array(char array[][SIZE], int xCord, int yCord);
char edit_array(char array[][SIZE]);
char infect_array(char array[][SIZE]);

int main()
{
	//variables 
	char array[SIZE][SIZE];
	int xCord = 0;
	int yCord = 0;
	
	
	//Title card
	cout<<"**********************************************\n"
		<<"Computer Science and Engineering\n"
		<<"CSCE 1030 - Computer Science I\n"
		<<"Jared Westmoreland Jhw0094 jaredwestmoreland@my.unt.edu\n"
		<<"**********************************************\n";
	//Directions for the user to enter cords
	cout<<"Please enter a location to infect: ";
	
	//will get the user input until the input is less than 8 for both x and y
	while(true)
	{	
		//stores user input
		cin>>xCord>>yCord;
	
		//if user input is greater than 7 display prompt
		if(xCord > SIZE || yCord > SIZE || yCord < 1 || yCord < 1)
		{
				cout<<"Those coordinates are outside the bounds of this region.\n";
				cout<<"Please enter a new location to infect: ";
		}
		//if user input is less than or equal to 7 break the loop
		else break;
	}

	//update the user input so it is more program friendly
	xCord = xCord - 1;
	yCord = yCord - 1;
	
	//create the matrix and put the user input labeled as i
	create_array(array, xCord, yCord);

	//start the actual process
	edit_array(array);
		
	return 0;
}

char create_array(char array[][SIZE], int xCord, int yCord)
{
	for(int i=0; i<SIZE; i++)
	{
		for(int j=0; j<SIZE; j++)
		{
			array[i][j] = 's';
			if(i == xCord && j == yCord)
			{
				array[i][j] = 'i';
			}
		}
	}
}

char edit_array(char array[][SIZE])
{
	int count = 0;
	
	for(int day=0; day<=SIZE; day++)
	{
		//displays the current day
		cout<<"\nDay "<<day<<endl;
		//display the matrix so the user can view it
		for(int i=0; i<SIZE; i++)
		{	
			for(int j=0; j<SIZE; j++)
			{	
				if(array[i][j] == 'r')
				{
					//counts how many r's there are
					count++;
				}
				//prints the array with a space
				cout<<array[i][j]<<" ";	
				//swaps any i's with r
				if(array[i][j] == 'i')
				array[i][j] = 'r';
				
			}
			
			//if the entire array is r kill the program
			if(count == SIZE*SIZE)
			{
				//end message
				cout<<"\n\nIt took "<<day+1<<" days for the outbreak to end.\n\n";
				return 0;
			}
			//if the loop is done and the if statement before is not used reset count
			if(i == SIZE-1)
			{
				count = 0;
			}
			cout<<endl;
		}
		//change all surrounding i's to i's
		infect_array(array);
	}
}

char infect_array(char array[][SIZE])
{
	for(int x=0; x<SIZE; x++)
	{	
		for(int y=0; y<SIZE; y++)
		{	
			if(array[x][y] == 'r')
			{
					//every if statement basically updates the matrix value around it
					if(array[x+1][y] == 's')
					array[x+1][y] = 'i';
					if(array[x+1][y+1] == 's' && y+1 < SIZE)
					array[x+1][y+1] = 'i';
					if(array[x+1][y-1] == 's' && y > 0)
					array[x+1][y-1] = 'i';
				
					if(array[x-1][y] == 's')
					array[x-1][y] = 'i';
					if(array[x-1][y+1] == 's' && y+1 < SIZE)
					array[x-1][y+1] = 'i';
					if(array[x-1][y-1] == 's' && y > 0)
					array[x-1][y-1] = 'i';
					
					if(array[x][y+1] == 's' && y+1 < SIZE)
					array[x][y+1] = 'i';
					if(array[x][y-1] == 's' && y > 0)
					array[x][y-1] = 'i';
			}
		}
	}	
}