/*
	Author:	Jared Westmoreland
	Date:	9/27/2018
	Instructor: Dr. Thompson
	Description: Switch-Case
*/
#include <iostream>
using namespace std;

//enum
enum Option {addition=1, multiplication=2, subtraction=3, division=4};

int main()
{
	//varibles
	Option user;
	int choose;
	int num1, num2;

	//userinput
	cout<<endl;
	cout<<"Welcome to the 1030 calculator. Please choose an option from the following list.\n";
	cout<<"Addition 1, Multiplication 2, Subtraction 3, Division 4: ";
	cin>> choose;

	//converts
	user= (Option)choose;

	//the switch statement
	switch (user)
	{
		//addition
		case 1:
			cout<<"Please enter two numbers to add: ";
			cin>>num1>>num2;
			cout<<"Your result is "<<num1+num2<<endl;
			break;
		//multiplication
		case 2:
                	cout<<"Please enter two numbers to multiply: ";
                	cin>>num1>>num2;
                	cout<<"Your result is "<<num1*num2<<endl;
			break;
		//subtraction
		case 3:
                	cout<<"Please enter two numbers to subtract: ";
                	cin>>num1>>num2;
                	cout<<"Your result is "<<num1-num2<<endl;
			break;
		//division
		case 4:
                	cout<<"Please enter two numbers to divide: ";
                	cin>>num1>>num2;
			if(num2 == 0)
				cout<<"Error: Your demonimator cannot be 0.\n";
			else
                		cout<<"Your result is "<<num1/num2<<endl;
			break;
		default:
			cout<<user<<" was not between 1 - 4\n";
			break;
	}
}
