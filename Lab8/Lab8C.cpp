/*
	Jared Westmoreland
	Lab 8 
	11/1/2018
	Computing average for last column
*/
#include <iostream>
using namespace std;

const int COLS = 6;
void computeAverage(float grades[][COLS], int size);

int main()
{
	const int ROWS = 3;
	float grades[ROWS][COLS];
	
	for(int row = 0; row < ROWS; row++)
	{
		for(int col = 0; col < COLS-1; col++)
		{
				cout<<"Enter QUIZ #"<<col+1<<" for STUDENT #"<<row+1<<": ";
				cin>>grades[row][col];
		}
	}
	
	//goes to compute average
	computeAverage(grades, ROWS);
	
	for(int row=0; row<ROWS; row++)
	{
		cout<<"STUDENT #"<<row+1<<": ";
		
		for(int col = 0; col < COLS; col++)
		{
			cout<<grades[row][col]<<" ";
		}
		cout<<endl;
	}
	
	return 0;
}

void computeAverage(float grades[][COLS], int size)
{
	//initializes temp as 0
	float temp= 0;
	
	//to edit array
	for(int i=0; i< size; i++)
	{
		for(int j= 0; j< COLS; j++)
		{
			//sum the rows
			temp += grades[i][j];
		}
		//put the average in array's last column
		grades[i][COLS-1] = temp/(COLS-1);
		temp = 0;
	}
}