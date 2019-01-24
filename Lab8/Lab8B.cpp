#include <iostream>
using namespace std;


void get_grade(int grade[], int size);

int main()
{
	const int SIZE = 5;
	int grades[SIZE];
	
	get_grade(grades, SIZE);
	for(int i = 0; i < SIZE; i++)
	{
		cout<<"grades["<<i<<"] = "<<grades[i]<<endl;
	}
	
	return 0;
}

void get_grade(int grades[], int size)
{
	for(int i = 0; i <size; i++)
	{
		cout<<"Enter grade between 0 and 100: ";
		cin>> grades[i]; 
	}
	return;
}