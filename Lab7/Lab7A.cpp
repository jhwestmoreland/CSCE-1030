#include <iostream>
#include <cmath>
using namespace std;

float calcBaseArea(float r);
float calcSideArea(float r, float h);
void prntSurfArea(float base_area, float side_area);

const double PI = 3.14159;

int main()
{
	float h;
	float r;
	float base_area;
	float side_area;
	
	cout<<"Enter the radius of the right cylinder in feet: ";
	cin >>r;
	
	cout<<"Enter the height of the right cylinder in feet: ";
	cin >>h;
	
	base_area = calcBaseArea(r);
	cout<<"Base surface area of right cylinder is "<<base_area<<" square feet."<<endl;

	side_area=calcSideArea(r, h);
	cout<<"The side area is "<<side_area<<" square feet."<<endl;
	
	prntSurfArea(base_area, side_area);
}

float calcBaseArea(float r)
{
	return(2*PI*pow(r,2));
}

float calcSideArea(float r, float h)
{
	return(2*PI*r*h);
}

void prntSurfArea(float base_area, float side_area)
{
	cout<<"The surface area of the cylinder is "<<base_area*side_area<<endl;
}