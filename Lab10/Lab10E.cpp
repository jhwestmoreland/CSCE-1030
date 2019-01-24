/*
	Jared Westmoreland
	11/21/2018
	2d dynamic array
*/
#include <iostream>
using namespace std;

int main()
{
	int number_of_students, number_of_test;
	
	cout<<"How many students? ";
	cin >>number_of_students;
	
	int **arr = new int*[number_of_students];
	float *avg = new float[number_of_students];
	
	for(int i=0; i<number_of_students; i++)
	{
		cout<<"How many tests for this student #"<<i+1<<"? ";
		cin >>number_of_test;
		
		arr[i] = new int[number_of_test];
		
		int sum = 0;
		for(int j=0; j<number_of_test; ++j)
		{
			cout<<"What are the test score #"<<j+1<<": ";
			cin >>arr[i][j];
			sum += *(*(arr + i)+ j);
		}
		
		avg[i] = sum / static_cast<float>(number_of_test); 
		cout<<"Student #"<<i+1<<" average test score is "<< avg[i] <<endl;
	}
	
	avg = NULL;
	delete avg;
	
	for(int i = 0; i < number_of_students; ++i) {
		delete [] arr[i];
	}
	delete [] arr;
}