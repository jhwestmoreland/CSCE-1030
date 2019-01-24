/*
	Jared Westmoreland
	11/21/2018
	1d array	
*/
#include <iostream>
using namespace std;

int main()
{
	int num;
	
	cout<<"How many integers will you enter? ";
	cin >>num;
	
	int *numlist = NULL;
	numlist = new int[num];
	
	for(int i=0; i<num;i++)
	{
		cout<<"Enter value #"<<i+1<<": ";
		cin >>*(numlist+i);
	}
	
	for(int i=num; i>0; i--)
	{
		cout<<"Value #"<<i<<": ";
		cout<<numlist[i-1]<<endl;
	}
	
	delete []numlist;
	numlist = NULL;
}