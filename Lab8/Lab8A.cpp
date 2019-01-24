#include <iostream>
#include <cmath>
#include <stdlib.h>
#include <time.h>
using namespace std;

void get_input(int& num1, float& num2);
void modify(int& num1, float& num2, int count);

int main()
{
	srand(time(NULL));
	int count = rand()%10 + 20;
	
	int num1;
	float num2;
	
	get_input(num1, num2);
	
	cout<<"original values: num1 = "<<num1<<" num2 = "<<num2<<endl;
	
	modify(num1, num2, count);
	
	cout<<"modified values: num1 = "<<num1<<" num2 = "<<num2<<endl;
	
	return 0;
}

void get_input(int& num1, float& num2)
{
	cout<<"Enter an integer: ";
	cin>> num1; 
	cout<<"Enter a floating-point number: ";
	cin>>num2;
	
	return;
}

void modify(int& num1, float& num2, int count)
{
	num1 = num1 * count;
	num2 = log(num2);
}