/*
	Jared Westmoreland
	Program 1
	Description: Calcues the time required to reach the surface when dropped
	Date: 9/10/2018
*/
#include <iostream>
#include <cmath>
using namespace std;

int main()
{
	float g = 0; //acceleration due to gravity
	//Gravitational Constant 6.673*10^-11
	const float GRAV = 6.673 * pow(10,-11); //pow is raised to the power
	float mass = 0; //mass of planet in kg
	float r = 0; //radius of planet in meters
	float h = 0; //height from which the object was dropped in feet
	float t = 0; //time required to reach the surface of the earth
	float total = 0; //Extra variable for storage
	const float M2F = 3.28; //Converst feet per second squared to meters per second squared

	//Header
	cout<<	"+--------------------------------------------------------------+\n"
	    <<	"| 		Computer Science and Engineering		|\n"
	    <<	"| 	 	 CSCE 1030 - Computer Science I			|\n"
	    <<	"| Jared Westmoreland Jhw0094 jaredwestmoreland@my.unt.edu 	|\n"
	    <<	"+--------------------------------------------------------------+\n";

	//User inputs to store variable data
	cout<<"Enter mass in kg: "; //Prompt
	cin >> mass;	//user input
	cout<<"Enter radius in meters: "; //Prompt
	cin >> r;	//user input

	//Calculations
	g = (GRAV * mass)/ (pow(r,2)); //Grav * Mass/ r^2

	//Output
	cout<<"The acceleration due to gravity is "<< g <<" meters per second squared.\n";

	cout<<"Enter heigh in feet: "; //Prompt
	cin >> h; //user input

	//Calculations
	h = h/M2F; //Converts
	total = (2*h)/g; //storing into varable for readability
	t = sqrt(total); //Stores it into time

	//Final Output
	cout<<"The object will reach the surface in "<< t <<" seconds.\n";
}
