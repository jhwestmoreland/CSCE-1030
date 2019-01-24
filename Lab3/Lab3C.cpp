/*
	Jared Westmoreland
	Dr. Mark Thompson
	1030.001
	Puzzel
*/
#include <iostream>
using namespace std;

int main()
{
	//Variables
	const float OFFSET = 0.32;
	float var1 = 39.4;
	float var2 = 7.5;
	float var3 = '4';
	float var4 = 22;
	float var5;

	//Equation
	var5 = ((var4 - var1) / var2 ) + OFFSET + var3;

	//output
	cout<<var5<<endl;

}
