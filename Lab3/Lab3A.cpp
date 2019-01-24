/*
	Jared Westmoreland
	Dr. Mark Thompson
	1030.001
	Area of a trapezoid
*/
#include <iostream>
using namespace std;

int main()
{
	//variable
	int b1 = 0;
	int b2 = 0;
	int h = 0;;
	float area = 0;

	//users input / prompts
	cout<<"Please enter base 1: ";
	cin>>b1;
	cout<<"Please enter base 2: ";
	cin>>b2;
	cout<<"Please enter height: ";
	cin>>h;

	area = h * static_cast<float>(b1 + b2) / 2; //formula

	//displays area
	cout<<"Area of the trapezoid is "<< area<<endl;

	return 0;
}
