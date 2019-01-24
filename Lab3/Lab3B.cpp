/*
	Jared Westmoreland
	Dr. Mark Thompson
	1030.001
	Sales Tax
*/
#include <iostream>
using namespace std;

int main()
{
	//Varibles
	float purchase = 0;
	const float TAX = 0.0825;
	float final = 0;

	//Prompt
	cout<<"Enter purchase value:";
	cin>>purchase;

	//equation
	final = purchase + (TAX * purchase);

	cout.setf(ios::fixed);
	cout.setf(ios::showpoint);
	cout.precision(3);

	//display
	cout<<"The final amount is $"<<final<<endl;

	return 0;
}
