#include <iostream>
using namespace std;

double bb_4ac();
void get_coeff(double& coeff, int pos);

int main()
{
	double result;
	result = bb_4ac();
	
	cout<<"The result of b^2-4ac is "<<result<<endl;
	
	return 0;
}

double bb_4ac()
{
	double a,b,c;
	double coeff;
	int pos;
	
	pos = 2;
	get_coeff(coeff,pos);
	a = coeff;
	pos = 1;
	get_coeff(coeff,pos);
	b = coeff;
	pos = 0;
	get_coeff(coeff,pos);
	c = coeff;
	
	return(b*b-4*a*c);
}

void get_coeff(double& coeff, int pos)
{
	cout<<"Please enter the coefficient for position "<<pos<<": ";
	cin >>coeff;
}