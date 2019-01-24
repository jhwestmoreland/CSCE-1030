/*
	Jared Westmoreland
	csce 1030.001
	11/15/2018
	BMI calculator
*/
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//struct to store the variables
struct Record{
	string name;
	int feet, inches;
	float weight;
};

//initializes function
float calculateBMI(Record);

int main()
{
	//calls struct
	Record person;
	float bmi;
	
	//gets user input
	cout<<"Enter the person's name: ";
	cin >>person.name;
	
	cout<<"Enter the person's weight in pounds: ";
	cin >>person.weight;
	
	cout<<"Enter the person's height in feet and inches: ";
	cin >> person.feet >> person.inches;
	
	//equals called function
	bmi = calculateBMI(person);
	
	//output
	cout<<"The BMI for "<<person.name<<" is: "<<bmi<<endl;
	
	return 0;
}

float calculateBMI(Record person)
{
	//gets height in inches
	int totalHeight = person.feet * 12 + person.inches;
	
	//returns bmi
	return(703*person.weight)/pow(totalHeight,2);
}