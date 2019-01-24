/*
	Jared Westmoreland
	csce 1030.001
	11/15/2018
	Gets average of file input
*/
#include <iostream>
#include <fstream>
#include <cstdlib>
using namespace std;

int main()
{
	//variables
	int x=0;
	int count=0;
	float sum=0;
	float avg=0;

	//allows us to read file
	ifstream in_s;

	//opens file
	in_s.open("act9A.txt");
	
	//if file doesn't exists exit failure 
	if(!in_s.is_open())
	{
		cout<<"Input file opening failed.\n";
		exit(EXIT_FAILURE);
	}

	//the file:///C:/Users/jhw0094/Downloads/csce1030Lab9_FA18.pdf said can use for loop not shall 
	//grab all the numbers in the file and store them as x
	while(in_s>>x)
	{
		//sum x until the file ends
		sum = sum +x;
		//keeps track of the number of lines within the file to avg
		count++;
	}

	//calculate average
	avg = sum/count;

	//display avg
	cout<<"The average of these "<<count<<" numbers is: "<<avg<<endl;

	//close file
	in_s.close();

	return 0;
}
